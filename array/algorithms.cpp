#ifndef CLASS_H
#define CLASS_H
#include"class.h"
#endif

// Function (Linear) which returns the index of first instance of an element
TMP
long long Array<Data>::linearSearch(Data key)
{
    for (int i = 0; i < this->size; i++)
    {
        if(this->atIndex(i) == key)
        {
            return i;
        }
    }
    return LONG_LONG_MIN;
}

// Function (Binary,Iterative) returns first instance of an element on a sorted sub array.
TMP
long long Array<Data>::binarySearchI(Data key,long long low,long long high)
{
    // If upper limit is not given --> Search full array
    if(!high)
        high = this->size - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (this->atIndex(mid) == key)
        {
            return mid;
        }
        else if (this->atIndex(mid) > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return LONG_LONG_MIN;
}

// Function (Binary,recursive) returns first instance of an element on a sorted sub array.
TMP
long long Array<Data>::binarySearchR(Data key,long long low,long long high)
{
    // If upper limit is not given --> Search full array
    if(!high)
        high = this->size - 1;

    if (low <= high)
    {
        int mid = (low + high) / 2;

        if (this->atIndex(mid) == key)
        {
            return mid;
        }
        else if (this->atIndex(mid) < key)
        {
            return binarySearchR(key, mid + 1, high);
        }
        return binarySearchR(key, low, mid - 1);
    }
    return LONG_LONG_MIN;
}

// Function to perform either a recursive (recur=true) or an iterative (recur=false) binary search on a sorted subarray
TMP
long long Array<Data>::bSearch(Data key,long long low,long long high,bool recur)
{
    if(recur)
        return this->binarySearchR(key,low,high);
    else
        return this->binarySearchI(key,low,high);

}

// Utility function to swap two numbers in an array
TMP
void Array<Data>::swap(long long num1,long long num2)
{
    Data temp = this->atIndex(num1);
    this->setIndex(num1,this->atIndex(num2));
    this->setIndex(num2,temp);
}

// Function to implement bubble sort algorithm on an array
TMP
void Array<Data>::bubbleSort()
{
    bool swapped = false;

    // After each outer iteration, note that the ith greatest element is at size - i th position
    for (int out = 0; out < this->size - 1; out++)
    {
        for (int in = 0; in < this->size - out - 1; in++)
        {
            if(this->atIndex(in) > this->atIndex(in+1))
            {
                swap(in,in+1);
                swapped = true;
            }
        }
        // If anything is not swapped, then array has no inversions, hence return
        if(!swapped)
        {
            break;
        }
    }
    return;
}

// Function to implement simple insertion sort on an array.
TMP
void Array<Data>::simpleInsertionSort()
{
    // Initialising loop variables and keys
    long long out,in;
    Data buffer;

    // Iterating through each element
    for (out = 1; out < this->size; out++)
    {
        buffer = this->start[out];
        in = out - 1;

        // Compare the current key with its predecessors.
        // Make space for the current key in the sorted array by shifting greater elements to right of it.
        while (in >= 0 && this->start[in] > buffer)
        {
            this->start[in + 1] = this->start[in];
            in = in - 1;
        }
        // Assign this empty space to current key
        this->start[in + 1] = buffer;
    }
    return;
}

// Utility function to search for Index of given element in sorted sub array (binary insertion sort)
TMP
long long Array<Data>::binarySearchUtil(Data key,long long low,long long high)
{
    // If array has single element return an index accordingly
    if (high <= low)
        return (key > this->start[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    // If there is one or more than one key --> there we insert the element next to it
    if (key == this->start[mid])
        return mid + 1;

    // Else if key > array[mid], recur through the right sub array
    if (key > this->start[mid])
        return binarySearchUtil(key, mid + 1, high);

    // Else recur through the left sub array
    return binarySearchUtil(key, low, mid - 1);
}

// Function to implement Binary Insertion Sort (nlogn time)
TMP
void Array<Data>::binaryInsertionSort()
{
    long long out, in;
    Data buffer;

    // Position Index of element to be inserted
    long long position;

    for (out = 1; out < size; ++out)
    {
        in = out - 1;
        buffer = this->start[out];

        // Find a location at which selected element should be inserts (reduces overall complexity)
        // from n*n to n*log(n)
        position = this->binarySearchUtil(buffer, 0, in);

        // Move all elements after that position to create space for selected
        while (in >= position)
        {
            this->start[in + 1] = this->start[in];
            in--;
        }
        // Insert the selected element
        this->start[in + 1] = buffer;
    }
    return;
}

// Function to implement recursive Insertion Sort
TMP
void Array<Data>::recursiveInsertionSort(long long size)
{
    // If array contains single element, return
    if (size <= 1)
        return;

    // Recursively sort the sub arrays (Top-Down Approach)
    recursiveInsertionSort(size - 1);

    // Insert last element at its correct position in sorted (sub) array.
    int last = this->start[size - 1];
    int iter = size - 2;

    // Compare the current key with its predecessors.
    // Make space for the current key in the sorted array by shifting greater elements to right of it.
    while (iter >= 0 && this->start[iter] > last)
    {
        this->start[iter + 1] = this->start[iter];
        iter--;
    }
    this->start[iter + 1] = last;
}

// Function to implement insertion sort (simple/binary) algorithm.
TMP
void  Array<Data>::insertionSort(bool fast,bool recur)
{
    if(fast)
    {
        this->binaryInsertionSort();
    }
    else
    {
        if(recur)
            this->recursiveInsertionSort(this->size);

        else
            this->simpleInsertionSort();
    }
}

// Selection sort algorithm for array
TMP
void Array<Data>::selectionSort()
{
    // Loop variables and index of minimum element
    long long out, in, minIndex;

    // Iterate entire array
    for (out = 0; out < this->size; out++)
    {
        // Initially i is minimum element
        minIndex = out;
        // Find the minimum element in the sub array and swap it with current element
        // To build the array
        for (in = out + 1; in < size; in++)
        {
            if (this->atIndex(in) < this->atIndex(minIndex))
            {
                minIndex = in;
            }
        }
        swap(minIndex,out);
    }
}