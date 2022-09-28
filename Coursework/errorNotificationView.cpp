#include "errorNotificationView.h"
#include "Windows.h"
#include "ErrorStore.h"
#include "flux_cpp.h"
#include "ActionTypes.h"
#include <iostream>

void printErrorNotification() {
	std::cout << "Error:\n";
	std::cout << "------\n";
	std::cout << "Message: " << ErrorStore::instance()->getErrorMessage();
	std::cout << "\n------\n";
	std::cout << "Print any key to resume program...\n";

	std::cout << std::flush;
	char ch[10];
	std::cin.getline(ch, 10);

	flux_cpp::Dispatcher::instance().dispatch(new flux_cpp::Action(ErrorActionTypes::ErrorResolved));
}