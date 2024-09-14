#pragma once
#include "number.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

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
	
	void clear() 
	{
		resize(2);
		size = 0;
	}

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

	void show(ostream& output)
	{
		output << "Массив: ";
		for (int i = 0; i < size; i++) {
			output << array[i] << ' ';
		}
		output << '\n';
	}
	
	number& operator[](int index) {
		if (index < 0 || index >= size) {
			throw out_of_range("Index out of range");
		}
		return array[index];
	}
	
	number average()
	{
		number res = 0;
		for (int i = 0; i < size; i++) {
			res += array[i];
		}
		res /= size;

		return res;
	}
	
	number MSD() 
	{
		number avg = average();
		number res = 0;
		for (int i = 0; i < size; i++) {
			res += pow((array[i] - avg), 2);
		}
		res = sqrt((1.0 / (size - 1)) * res);

		return res;
	}

	int partition(int low, int high) 
	{
		int pivot = array[high];
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++) {
			if (array[j] <= pivot) {
				i++;
				swap(array[i], array[j]);
			}
		}
		swap(array[i + 1], array[high]);

		return (i + 1);
	}

	void quickSort(int low, int high) 
	{
		if (low < high) {
			int pi = partition(low, high);
			quickSort(low, pi - 1);
			quickSort(pi + 1, high);
		}
	}

	void reverse() 
	{
		for (int i = 0; i < size / 2; i++) {
			swap(array[i], array[size - i - 1]);
		}
	}

	void sort(bool isReversed = false) 
	{
		quickSort(0, size - 1);

		if (isReversed) {
			reverse();
		}
	}
};