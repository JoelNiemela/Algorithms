#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstddef>
#include <algorithm>
#include <memory>

#include "../ArrayIterator/ArrayIterator.h"

template <typename T>
class DynamicArray {
public:
	using value_type = T;
	using iterator = ArrayIterator<DynamicArray<T>>;
private:
	std::size_t used = 0;
	std::size_t capacity = 0;
	T* buffer = nullptr;

	void resize(std::size_t size) {
		T* new_buffer = (T*)::operator new(size * sizeof(T));
		std::move(this->buffer, this->buffer + this->used, new_buffer);
		std::destroy(this->buffer, this->buffer + this->used);

		::operator delete(this->buffer, this->capacity * sizeof(T));
		this->buffer = new_buffer;
		this->capacity = size;
	}
public:
	DynamicArray() : used(0), capacity(1) {
		this->buffer = (T*)::operator new(this->capacity * sizeof(T));
	}

	~DynamicArray() {
		this->clear();
		::operator delete(this->buffer, this->capacity * sizeof(T));
	}

	std::size_t size() const {
		return this->used;
	}

	iterator begin() const {
		return iterator(this->buffer);
	}

	iterator end() const {
		return iterator(this->buffer + this->used);
	}

	void clear() {
		std::destroy(this->buffer, this->buffer + this->used);
		this->used = 0;
	}

	void pop() {
		if (this->used > 0) {
			this->used--;
			this->buffer[this->used].~T();
		}
	}

	void push(const T& value) {
		if (this->used >= this->capacity) {
			resize(this->capacity * 2);
		}

		this->buffer[this->used] = value;
		this->used++;
	}

	void push(T&& value) {
		if (this->used >= this->capacity) {
			resize(this->capacity * 2);
		}

		this->buffer[this->used] = std::move(value);
		this->used++;
	}

	template<typename... Args>
	T& emplace(Args&&... args) {
		if (this->used >= this->capacity) {
			resize(this->capacity * 2);
		}

		new(&this->buffer[this->used]) T(std::forward<Args>(args)...);
		return this->buffer[this->used++];
	}

	T& operator[](std::size_t index) {
		return this->buffer[index];
	}

	const T& operator[](std::size_t index) const {
		return this->buffer[index];
	}
};

#endif
