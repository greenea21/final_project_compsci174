#include <iostream>
#include "cart.h"
#include <fstream>
#include <string>

void cart::add_item(const item& item) {
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

	std::cout << "What item would you like to remove? (Enter the item number)" << std::endl;
	std::getline(std::cin, temp);

	//Check input is valid integer
	try {
		index = std::stoi(temp);
	}
	catch (const std::exception& e) {
		std::cout << "Must enter a valid item index!" << std::endl;
		return;
	}
	
	//Check input makes sense (valid vector element)
	if (!(index < 0 || index >= cart_inventory.size())) {
		cart_inventory.erase(cart_inventory.begin() + index);
	}
	else {
		std::cout << "Must enter the item's corresponding integer." << std::endl;
		return;
	}
}

bool cart::can_checkout() const {
	return !is_empty();
}

void cart::checkout() const {
	std::cout << "\n[Receipt]" << std::endl;

	print_items();

	double subtotal = get_total();
	double tax_rate = 0.0;
	double tax_amount = 0.0;
	double final_total = 0.0;
	std::string state;

	std::cout << "Enter your state abbreviation (WI, IL, MN, MI, IA): ";
	std::getline(std::cin, state);
	if (state == "WI" || state == "wi" || state == "Wisconsin" || state == "wisconsin") {
		tax_rate = 0.05;
	}
	else if (state == "IL" || state == "il" || state == "Illinois" || state == "illinois") {
		tax_rate = 0.0625;
	}
	else if (state == "MN" || state == "mn" || state == "Minnesota" || state == "minnesota") {
		tax_rate = 0.06875;
	}
	else if (state == "MI" || state == "mi" || state == "Michigan" || state == "michigan") {
		tax_rate = 0.06;
	}
	else if (state == "IA" || state == "ia" || state == "Iowa" || state == "iowa") {
		tax_rate = 0.06;
	}
	else {
		std::cout << "State not found. No sales tax applied." << std::endl;
		tax_rate = 0.0;
	}

	tax_amount = subtotal * tax_rate;
	final_total = subtotal + tax_amount;

	std::cout << "Subtotal: $" << subtotal << std::endl;
	std::cout << "Tax:      $" << tax_amount << std::endl;
	std::cout << "Total:    $" << final_total << std::endl;
	// stretch goal 7
	std::ofstream receipt_file;
	receipt_file.open("receipt.txt");

	if (receipt_file.is_open()) {
		receipt_file << "[Receipt]" << std::endl;

		for (int i = 0; i < cart_inventory.size(); i++) {
			receipt_file << i << ". " << cart_inventory[i].name
				<< "\t$" << cart_inventory[i].price << std::endl;
		}

		receipt_file << "Subtotal: $" << subtotal << std::endl;
		receipt_file << "Tax:      $" << tax_amount << std::endl;
		receipt_file << "Total:    $" << final_total << std::endl;

		receipt_file.close();

		std::cout << "Receipt saved to receipt.txt" << std::endl;
	}
	else {
		std::cout << "Error opening receipt file." << std::endl;
	}
}

bool cart::is_empty() const {
	return (cart_inventory.size() <= 0);
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
