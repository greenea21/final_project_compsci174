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
		return INVALID_INPUT;
	}
}

bool menu::get_confirmation() const {
	cout << "Are you sure? (Y/N): ";

	std::string input;
	getline(std::cin, input);

	if (input == "Y" || input == "y") {
		return true;
	}
	else {
		return false;
	}
}

void menu::start() {
	store.initialize_items();
	welcome();

	while (true) {
		int choice = get_user_choice(
			"\nPlease enter your choice (digit):"
			"\n0. Add item to cart"
			"\n1. Remove item from cart"
			"\n2. View my cart"
			"\n3. View store items"
			"\n4. Checkout"
			"\n5. EXIT"
		);

		switch (choice) {
		case ADD_ITEM:
			cout << "\nYou selected: Add item" << endl;
			break;
		case REMOVE_ITEM:
			cout << "\nYou selected: Remove item" << endl;
			break;
		case VIEW_CART:
			cout << "\nYou selected: View cart" << endl;
			break;
		case VIEW_STORE_ITEMS:
			cout << "\nYou selected: Show store items" << endl;
			print_store_items();
			break;
		case CHECK_OUT:
			cout << "\nYou selected: Checkout" << endl;
			break;
		case EXIT:
			quit();
			break;
		default:
			cout << "Invalid input!" << endl;
			break;
		}
	}
}

void menu::quit() const {
	cout << "\nYou selected: Exit" << endl;

	if (get_confirmation()) {
		cout << "Goodbye!" << endl;
		exit(0);
	}
	else {
		cout << "Exit cancelled!" << endl;
	}
}

void menu::print_store_items() const {
	store.print_items();
}