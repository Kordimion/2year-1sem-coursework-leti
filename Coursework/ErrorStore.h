#pragma once

#include "flux_cpp.h"
#include "ActionTypes.h"

class ErrorStore final : public flux_cpp::Store {
private:
	bool hasError_ = false;
	std::string message = "";
	ErrorStore() = default;

public:
	static ErrorStore* instance() {
		static ErrorStore* self = new ErrorStore();
		return self;
	}

	void process(const std::shared_ptr<flux_cpp::Action>& action) override;

	const bool hasError() const { return hasError_; }
	const std::string& getErrorMessage() const 
	{
		if (this->hasError()) return message;
		else throw std::invalid_argument("ErrorStore getErrorMessage(): can't get error if there is no error ");
	}
};