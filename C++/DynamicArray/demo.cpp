#include "DynamicArray.h"

#include <iostream>
#include <string>

int main() {
	DynamicArray<int> dyn_arrc;
	for (int i = 0; i < 100; i++) {
		dyn_arrc.push(i);
	}

	for (auto e : dyn_arrc) {
		std::cout << e << std::endl;
	}
	std::cout << dyn_arrc.size() << std::endl;
}
