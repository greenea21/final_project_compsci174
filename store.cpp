#include <iostream>
#include "store.h"
#include "item.h"

void store::initialize_items() {
	item apple;
	apple.name = "Apple";
	apple.price = 0.49;
	apple.stock = 15; 

	item orange;
	orange.name = "Orange";
	orange.price = 0.79;
	orange.stock = 10;

	store_inventory.push_back(apple);
	store_inventory.push_back(orange);
}

void store::print_items() const {
	std::cout << "\n[Store Items]" << std::endl;

	for (int i = 0; i < store_inventory.size(); i++) {
		std::cout << store_inventory[i].name << "\t$"
			<< store_inventory[i].price << "\t"
			<< store_inventory[i].stock << " left" << std::endl;
	}
}

bool store::can_purchase(int index) const {
	if (index >= 0 && index < store_inventory.size()) { //check valid index
		if (store_inventory[index].stock > 0) { //check quantity
			return true;
		}
	}

	return false;
}

int store::find_item_index(std::string key) const {
	for (int i = 0; i < store_inventory.size(); i++) {
		if (store_inventory[i].name == key) {
			return i;
		}
	}

	return -1;
}
