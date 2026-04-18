#include <iostream>
#include "store.h"
#include "item.h"

void store::initialize_items() {
	item apple;
	apple.name = "Apple";
	apple.price = 0.49;
	apple.stock = 15; //Replace hardcoding items with reading from a text file

	store_inventory.push_back(apple);
}

void store::print_items() const {
	for (int i = 0; i < store_inventory.size(); i++) {
		std::cout << store_inventory[i].name << std::endl;
	}
}