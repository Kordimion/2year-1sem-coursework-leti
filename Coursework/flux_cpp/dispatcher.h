#ifndef FLUX_CPP_DISPATCHER_H
#define FLUX_CPP_DISPATCHER_H

#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <queue>
#include <thread>
#include <type_traits>
#include <utility>
#include <vector>

#include "middleware.h"
#include "store.h"

namespace flux_cpp
{
	class Action;
	/**
	* @brief Manager of this whole process
	* 
	* The dispatcher receives actions as input and sends these actions (and related data) to registered handlers
	*/
	class Dispatcher final {
	public:
		static Dispatcher& instance() {
			static Dispatcher self;
			return self;
		}

		template <class... Args>

		void registerMiddleware(Args&&... args) {
			middlewares_.emplace_back(std::forward<Args>(args)...);
		}

		template <class... Args>

		void registerClosingMiddleware(Args&&... args) {
			closing_middlewares_.emplace_back(std::forward<Args>(args)...);
		}

		template <class... Args>

		void registerStore(Args&&... args) {
			stores_.emplace_back(std::forward<Args>(args)...);
		}

		template <class... Args>
		/**
		* Function launched from the outside
		*/
		void dispatch(Args&&... args){
			std::unique_lock<std::mutex> lock(mutex_);
			actions_.emplace(std::forward<Args>(args)...);

			wake_ = true;
			condition_.notify_one();
		}
	private:
		Dispatcher() {
			thread_ = std::thread([dispatcher = this]() {
				dispatcher->run();
			});
		}
		Dispatcher(const Dispatcher&) = delete;

		Dispatcher(Dispatcher&&) = delete;

		Dispatcher& operator=(const Dispatcher&) = delete;

		Dispatcher& operator=(Dispatcher&&) = delete;

		~Dispatcher(){
			stop();
			thread_.join();
		}
		/**
		* @brief Processing of actions
		*  Run actions through the chain of handlers
		*/
		void run()	{
			std::unique_lock<std::mutex> lock(mutex_);

			while (true) {

				while (!wake_) {
					condition_.wait(lock);
				}

				while (!actions_.empty()) {
					auto action = actions_.front();

					lock.unlock();

					for (const auto& middleware : middlewares_) {
						action = middleware->process(action);
					}

					for (const auto& store : stores_) {
						store->process(action);
					}

					for (const auto& closingMiddleware : closing_middlewares_) {
						action = closingMiddleware->process(action);
					}

					lock.lock();

					actions_.pop();
				}

				wake_ = false;

				if (done_) {
					return;
				}
			}
		}
		/**
		* @brief Stop activity
		*/
		void stop() {
			std::unique_lock<std::mutex> lock(mutex_);

			done_ = true;
			wake_ = true;
			condition_.notify_one();
		}

		std::vector<std::shared_ptr<Middleware> > middlewares_;
		std::vector<std::shared_ptr<Middleware> > closing_middlewares_;

		std::vector<std::shared_ptr<Store> > stores_;

		std::queue<std::shared_ptr<Action> > actions_;

		std::atomic_bool wake_;
		std::atomic_bool done_;
		std::mutex mutex_;
		std::condition_variable condition_;

		std::thread thread_;
	};
}

#endif

