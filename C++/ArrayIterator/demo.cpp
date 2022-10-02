#include "ArrayIterator.h"

#include <iostream>

template <typename T>
struct Vector3 {
	using value_type = T;
	using iterator = ArrayIterator<Vector3<T>>;
	T data[3];
	Vector3() {}
	Vector3(T x, T y, T z) {
		this->data[0] = x;
		this->data[1] = y;
		this->data[2] = z;
	}
	iterator begin() {
		return iterator(this->data);
	}

	iterator end() {
		return iterator(this->data + 3);
	}
};

int main() {
	Vector3<int> vec3(1, 2, 3);
	for (const int& e : vec3) {
		std::cout << e << std::endl;
	}
}
