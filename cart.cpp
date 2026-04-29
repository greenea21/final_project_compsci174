#include <iostream>
#include "cart.h"

void cart::add_item(item item) {
	cart_inventory.push_back(item);
}

void cart::remove_item() {
	if (is_empty()) {
		std::cout << "Your cart is empty!" << std::endl;
		return;
	}

	std::string temp;
	int index;
	print_items();

	std::cout << "What item would you like to remove?" << std::endl;
	std::getline(std::cin, temp);

	//Check input is valid integer
	try {
		index = std::stoi(temp);
	}
	catch (const std::exception& e) {
		
	}
	
	//Check input makes sense (valid vector element)
	if (!(index < 0 || index >= cart_inventory.size())) {
		cart_inventory.erase(cart_inventory.begin() + index);
	}
	else {
		std::cout << "Must enter the item's corresponding integer.";
		return;
	}

	//return;
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
