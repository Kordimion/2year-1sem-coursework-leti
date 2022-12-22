#include <iostream>
#include "Windows.h"
#include <conio.h>

#include "action_types.h"
#include "error_store.h"
#include "flux_cpp.h"
#include "views.h"

/**
* @brief Prints the error screen
*/
void printErrorNotification() {
	std::cout << "Error:\n";
	std::cout << "------\n";
	std::cout << "Message: " << ErrorStore::instance()->getErrorMessage();
	std::cout << "\n------\n";
	std::cout << "Print any key to resume program...\n";

	std::cout << std::flush;
	char ch = _getch();

	DISPATCH(new ErrorResolvedAction());
}