#include <iostream>
#include "menu.h"
#include "item.h"

using std::cout; using std::endl;

void menu::welcome() const {
	cout << welcome_msg << endl;
}

void menu::start() {
	store.initialize_items();

	while (true) {
		welcome();

		break; //use this to end the menu loop, like when the user quits or chooses an option
	}
}

void menu::print_store_items() const {
	store.print_items();
}