#ifndef ARRAY_ITERATOR_H
#define ARRAY_ITERATOR_H

#include <cstddef>

template <typename Array>
class ArrayIterator {
public:
	using value_type = typename Array::value_type;
private:
	value_type* ptr;
public:
	ArrayIterator(value_type* ptr) : ptr(ptr) {}

	ArrayIterator& operator++() {
		ptr++;
		return *this;
	}

	ArrayIterator& operator++(int) {
		ArrayIterator iterator = *this;
		++(*this);
		return iterator;
	}

	ArrayIterator& operator--() {
		ptr--;
		return *this;
	}

	ArrayIterator& operator--(int) {
		ArrayIterator iterator = *this;
		--(*this);
		return iterator;
	}

	value_type& operator[](std::size_t index) {
		return ptr[index];
	}

	value_type* operator->() {
		return ptr;
	}

	value_type& operator*() {
		return *ptr;
	}

	bool operator==(const ArrayIterator& other) const = default;
	bool operator!=(const ArrayIterator& other) const = default;
};

#endif
