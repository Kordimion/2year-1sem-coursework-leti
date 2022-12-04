#include <iostream>
#include "Windows.h"

#include "action_types.h"
#include "error_store.h"
#include "flux_cpp.h"
#include "error_notification_view.h"

void printErrorNotification() {
	std::cout << "Error:\n";
	std::cout << "------\n";
	std::cout << "Message: " << ErrorStore::instance()->getErrorMessage();
	std::cout << "\n------\n";
	std::cout << "Print any key to resume program...\n";

	std::cout << std::flush;
	char ch[10];
	std::cin.getline(ch, 10);

//TODO -> to action_creators?
	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::ErrorResolved));
}