#pragma once
#include "number.h"

class Array
{
private:
	int size = 0;
	int capacity = 0;
	number* array = nullptr;

public:
	Array(int valueSize = 0)
	{
		size = valueSize;
		capacity = valueSize;
		array = new number[capacity];
	};

	~Array() {
		delete[] array;
	};
	
	

	void resize(bool isExpand)
	{
		number* tmp = array;
		if (isExpand) {
			array = new number[capacity * 2];
			capacity *= 2;
		}
		else {
			array = new number[capacity / 2];
			capacity /= 2;
		}
		for (int i = 0; i < size; i++) {
			*(array + i) = *(tmp + i);
		}
		delete[] tmp;
	}

	void add(int value)
	{
		if (size >= capacity) {
			resize(true);
		}
		*(array + size) = value;
		size++;
	}

	void remove()
	{
		delete (array + size - 1);
		size--;
		if (size <= capacity / 2) {
			resize(false);
		}
	}

};