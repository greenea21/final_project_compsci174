#include <iostream>
#include "cart.h"

void cart::add_item(item item) {
	cart_inventory.push_back(item);
}

void cart::remove_item() {
	std::string item;
	int item_ID;
	print_items();
	std::cout << "What item would you like to remove?" << std::endl;
	std::getline(std::cin, item);
	try {
		item_ID = std::stoi(item);
	}
	catch (const std::exception& e) {
		std::cout << "Must enter the items corresponding integer.";
		return;
	}
	cart_inventory.erase(cart_inventory.begin() + item_ID);
	return;
}

bool cart::can_checkout() const {
	return !is_empty();
}

void cart::checkout() const {
	std::cout << "\n[Receipt]" << std::endl;

	print_items();

	std::cout << "Total: $" << get_total() << std::endl;
}

bool cart::is_empty() const {
	if (cart_inventory.size() <= 0) {
		return true;
	}

	return false;
}

void cart::print_items() const {
	std::cout << "\n[Cart Items]" << std::endl;

	if (is_empty()) {
		std::cout << "Empty!" << std::endl;
		return;
	}

	for (int i = 0; i < cart_inventory.size(); i++) {
	std::cout << i << ". " << cart_inventory[i].name << "\t$" << cart_inventory[i].price << std::endl;
	}
}

double cart::get_total() const {
	double rolling_total = 0;

	for (int i = 0; i < cart_inventory.size(); i++) {
		rolling_total += cart_inventory[i].price;
	}

	return rolling_total;
}
