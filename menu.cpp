#include <iostream>
#include <string>
#include "menu.h"
#include "item.h"

using std::cout; using std::endl;

void menu::welcome() const {
	cout << welcome_msg << endl;
}

int menu::get_user_choice(std::string prompt) const {
	cout << prompt << endl;

	std::string temp;

	getline(std::cin, temp);

	try {
		return stoi(temp);
	}
	catch (std::exception& e) {
		//handle invalid input here
	}
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