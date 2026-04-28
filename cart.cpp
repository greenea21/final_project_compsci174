#include <iostream>
#include "cart.h"

void cart::add_item(item item) {
	cart_inventory.push_back(item);
}

void cart::remove_item(item item) {
	//will need to find the matching item in the array
	//if found, remove N items
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
