#pragma once
#include "number.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Array
{
private:
	int size;
	int capacity;
	number* array;

public:
	Array(int initCapacity = 2) {
		size = 0;
		capacity = initCapacity;
		array = new number[capacity];
	}

	~Array() {
		delete[] array;
	};
	
	void resize(int newCapacity) 
	{
		if (newCapacity < 0) return;

		size = min(size, newCapacity);
		number* temp = new number[newCapacity];
		for (int i = 0; i < size; i++) {
			temp[i] = array[i];
		}
		delete[] array;
		array = temp;
		capacity = newCapacity;
	}

	void add(number value)
	{
		if (size >= capacity) {
			resize(capacity * 2);
		}
		array[size] = value;
		size++;
	}

	void remove()
	{
		if (size > 0) {
			size--;
			if (size <= capacity / 4 && capacity > 2) {
				resize(capacity / 2);
			}
		}
	}

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
			cout << array[i] << ' ';
		}
	}

};