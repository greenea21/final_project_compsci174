#include <iostream>
//#include <string>
#include "menu.h"

using std::cout; using std::endl;

void menu::welcome() const {
	cout << "Welcome to the store!" << endl;
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
			add_item();
			break;
		case REMOVE_ITEM:
			cart.remove_item();
			break;
		case VIEW_CART:
			print_cart_items();
			break;
		case VIEW_STORE_ITEMS:
			cout << "\nYou selected: Show store items" << endl;
			print_store_items();
			break;
		case CHECK_OUT:
			checkout();
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

void menu::print_cart_items() const {
	cart.print_items();
}

void menu::add_item() {
	cout << "\nYou selected: Add item" << endl;
	cout << "Which item would you like to purchase? (Type the item name)" << endl;

	print_store_items();

	std::string name;
	getline(std::cin, name);

	int index = store.find_item_index(name); //find the index with matching item <name>

	if (!store.can_purchase(index)) {
		std::cout << "Invalid item/out of stock!" << endl;
		return;
	}

	cart.add_item(store.store_inventory[index]);
	store.store_inventory[index].stock--;

	std::cout << "\nCart Updated!" << std::endl;
	print_cart_items();
}

void menu::checkout() const {
	if (cart.can_checkout()) {
		cout << "\nYou selected: Checkout" << endl;
		cart.checkout();
	}
	else {
		std::cout << "Cart is empty!" << std::endl;
	}
}
