#include <iostream>
#include <string>
#include "item.h"

using std::cout;
using std::endl;

int main() {
	item apple; //read and parse items from a file for stretch goal 8
	apple.name = "Apple";
	apple.price = 0.49;
	apple.stock = 20;

	return 0;
}