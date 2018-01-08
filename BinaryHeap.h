
#ifndef __BINARYHEAP__
#define __BINARYHEAP__

class BinaryHeap {

public:
	BinaryHeap(int); // constructor that takes the capacity of the structure
	~BinaryHeap(); // destructor
	void insert(int); // inserts a new element to the heap, if array is full do nothing
	void deleteMin(); // removes the minimum element from the heap
	int getMin(); // returns the minimum element int the heap, returns -1 if the heap is empty
	bool isEmpty();

private:
	int *heap; // array to store the elements of the heap
	int size; // keeps the number of elements in the heap
	int capacity; // keeps the total capacity of the heap
	void percolateDown(int);
	void swap(int, int);
};

#endif