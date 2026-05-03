#include <iostream>
#include "store.h"
#include "item.h"
// added 6 more items to store inventory
void store::initialize_items() {
	item apple;
	apple.name = "Apple";
	apple.price = 0.49;
	apple.stock = 15;

	item orange;
	orange.name = "Orange";
	orange.price = 0.79;
	orange.stock = 10;

	item banana;
	banana.name = "Banana";
	banana.price = 0.39;
	banana.stock = 20;

	item bread;
	bread.name = "Bread";
	bread.price = 2.49;
	bread.stock = 8;

	item milk;
	milk.name = "Milk";
	milk.price = 3.29;
	milk.stock = 12;

	item eggs;
	eggs.name = "Eggs";
	eggs.price = 2.99;
	eggs.stock = 10;

	item cheese;
	cheese.name = "Cheese";
	cheese.price = 4.49;
	cheese.stock = 6;

	item chicken;
	chicken.name = "Chicken";
	chicken.price = 7.99;
	chicken.stock = 5;

	store_inventory.push_back(apple);
	store_inventory.push_back(orange);
	store_inventory.push_back(banana);
	store_inventory.push_back(bread);
	store_inventory.push_back(milk);
	store_inventory.push_back(eggs);
	store_inventory.push_back(cheese);
	store_inventory.push_back(chicken);
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

int store::find_item_index(const std::string& key) const {
	for (int i = 0; i < store_inventory.size(); i++) {
		if (store_inventory[i].name == key) {
			return i;
		}
	}

	return -1;
}
