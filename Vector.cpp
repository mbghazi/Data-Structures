#include "Vector.h"
#include <iostream>

using namespace std;

// Constructors
template <class DataType>
Vector<DataType>::Vector() // Default constructor
{
	size = 0;
	capacity = 4;
	dataItems = new DataType[capacity]();
}
		  
// Destructor
template <class DataType>
Vector<DataType>::~Vector()
{
	delete[] dataItems;
}

// Vector manipulation operations
template <class DataType>
void Vector<DataType>::append(const DataType item) // Add a new item to the end of the vector
{
	if (isFull())
	{
		cout << "The List is Full, Making Space..." << endl;
		//int *temp = new int[capacity * 2];
		capacity *= 2;
		DataType* temp = new DataType[capacity];

		for (int i = 0; i < size; i++)
		{
			temp[i] = dataItems[i];
			
		}
		delete dataItems;

		dataItems = temp;
	}

	dataItems[size] = item;
	size++;
	//&operator = append(item);
}

template <class DataType>
void Vector<DataType>::insertAt(const int index, const DataType item)  // Insert a new element at the given index
{
	if (index > capacity || index < 0)
	{
		cout << "The index is out of bounds " << endl;
		return;
	}

	if (isFull())
	{
		capacity *= 2;

		DataType *temp = new DataType[capacity * 2];

		for (int i = 0; i < size; i++)
		{
			temp[i] = dataItems[i];

		}
		delete dataItems;
		dataItems = temp;
	}
	dataItems[index] = item;
	size++;
}

template <class DataType>
void Vector<DataType>::removeAt(const int index)        // Remove the data item at the given index
{
	if (index > capacity || index < 0)
	{
		cout << "Given index is out of boundaries... " << endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			dataItems[i] = NULL;
			size--;
		}
	}
	cout << "Element has been removed from Index... " << index << endl;
	return;
}

template <class DataType>
void Vector<DataType>::remove(int item)                   // Remove the given element from the vector
{
	if (isEmpty())
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (dataItems[i] == item)
		{
			dataItems[i] = 700;
		}
	}
	size--;
}

template <class DataType>
void Vector<DataType>::clear()                         // Make the vector empty
{
	size = 0;
	/*
	while (!isEmpty())
	{
		delete[] dataItems;
	}
	*/
	for (int i = 0; i < capacity; i++)
	{
		dataItems[i] = NULL;

	}

	cout << "Capacity is: " << capacity << endl;
}

template <class DataType>
bool Vector<DataType>::isEmpty() const                  // Is the Vector empty?
{
	return (size == 0);
}

template <class DataType>
bool Vector<DataType>::isFull() const                    // Is the Vector full?
{

	return (size >= capacity);
}

template <class DataType>
int Vector<DataType>::contains(const DataType item) const    // Does the vector contain the given item? return the index of the item if found, otherwise, return -1.
{
	if (isEmpty())
	{
		return -1;
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			if (dataItems[i] == item)
			{
				return i;
			}
		 }
	}
	return -1;
}

template <class DataType>
DataType Vector<DataType>::elementAt(const int index) const  // Access the element at the given index
{
	if (isEmpty())
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		if (i == index)
		{
			cout << "The element in index " << index << " is: " << dataItems[i] << endl;
			return dataItems[i];
		}
	}
	//return index;
}

template <class DataType>
int Vector<DataType>::getSize() const                      // Return the number of items in the vector
{

	return size;
}

// overloading subscript []

template <class DataType>
DataType& Vector<DataType>::operator[] (const int index)   // overloading subscript []
{

	return (dataItems[index]);
}



template class Vector<int>;

template class Vector<float>;

template class Vector<char>;
