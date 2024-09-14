#pragma once
#include "number.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Array
{
private:
	int size = 0;
	int capacity = 0;
	number* array = nullptr;

public:
	Array(int valueSize)
	{
		size = valueSize;
		capacity = valueSize;
		array = new number[capacity];
	};

	~Array() {
		delete[] array;
	};
	
	void fill(string& input) 
	{
		stringstream ss(input);
		number value;
		while (ss >> value) {
			add(value);
		}
	}

	void show() 
	{
		for (int i = 0; i < size; i++) {
			cout << (*(array + i)) << ' ';
		}
	}
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
		size--;
		if (size <= capacity / 2 && capacity > 1) {
			resize(false);
		}
	}

};