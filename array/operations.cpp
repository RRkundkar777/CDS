#ifndef CLASS_H
#define CLASS_H
#include"class.h"
#endif

#include <new>
#include<iostream>

// Sets size of array, allocates memory for elements and sets the elements INT_MIN by default
TMP
Array<Data>::Array(long long size)
{
    // If allocation exceeds maximum size
    if(size > LIM)
    {
        throw std::bad_alloc();
    }
    else
    {
        this->size = size;
        this->start = new Data[size];
        std::fill_n(this->start,this->size,INT_MIN);
    }
}

// Function to get an element at an Index, if index is invalid it throws exception.
TMP
Data Array<Data>::atIndex(long long index)
{
    Data result;
    // Handling out of bounds error
    if(index < 0 || this->size <= index)
    {
        throw std::out_of_range("Index out of range");
        return result;
    }
    result = this->start[index];
    return result;
}

// Function to get element at end
TMP
Data Array<Data>::atEnd()
{
    return this->atIndex(this->size - 1);
}

// Function to get element at start
TMP
Data Array<Data>::atStart()
{
    return this->atIndex(0);
}

// Function to display complete array as list
TMP 
void Array<Data>::display()
{
    std::cout << "[";
    // If array is empty, show empty brackets
    if (this->size)
    {
        for (int i = 0; i < (this->size); i++)
        {
            std::cout << this->start[i] << ",";
        }
        std::cout << "\b";
    }
    std::cout << "]\n";
    return;
}

// Function to set an element at an index, if index is invalid it throws exception.
TMP
bool Array<Data>::setIndex(long long index,Data key)
{
    // Handling out of bounds error
    if(index < 0 || this->size <= index)
    {
        throw std::out_of_range("Index out of range");
        return false;
    }
    this->start[index] = key;
    return true;
}

// Function which replaces an element at an index and returns the old element.
TMP
Data Array<Data>::replaceAt(long long index,Data key)
{
    Data oldKey = this->atIndex(index);
    this->setIndex(index,key);
    return oldKey;
}

// Function to insert an element into array, by element shifting.
TMP
void Array<Data>::insert(long long index,Data key)
{
    try
    {
        // Index is unfilled
        if(this->atIndex(index) == INT_MIN)
        {
            this->setIndex(index,key);
        }
        // Array has a room for more elements
        else if(this->atEnd() == INT_MIN)
        {
            // Shifting the elements to the right
            for (long long i = this->size - 1; i >= index; i--)
            {
                this->start[i] = this->start[i - 1];
            }
            // Inserting the element
            this->start[index] = key;
        }
        // Array has no room for more elements
        else
        {
            throw std::overflow_error("Array Overflow while insertion");
        }
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Function to remove an element from an array using shifting, returns removed element.
TMP
Data Array<Data>::pop(long long index)
{
    Data removed = this->atIndex(index);
    // Shifting the elements to the  left
    for (long long i = index; i < this->size - 1; i++)
    {
        this->start[i] = this->start[i + 1];
    }
    this->start[this->size-1] = INT_MIN;
    return removed;
}

// Function to erase an element from an array.
TMP
void Array<Data>::erase(long long index)
{
    this->setIndex(index,INT_MIN);
}