
#include "BinaryHeap.h"
#include <iostream>
using namespace std;


BinaryHeap::BinaryHeap(int capacity) {
    this->capacity = capacity;
	
	// The element at index 0 is not used!
	// The root element will be placed at index 1
	heap = new int[capacity+1];
	size = 0;
}

BinaryHeap::~BinaryHeap() {
	delete [] heap;
}

void BinaryHeap::swap(int i, int j) {
	int t = heap[i];
	heap[i] = heap[j];
	heap[j] = t;
}


void BinaryHeap::insert(int i)
{
	if (size >= capacity)
	{
		cout << "HEAP FULL" << endl;
		return;
	}

	heap[size] = i;

	int place = size;
	int parent = (place - 1) / 2;

	while ((parent >= 0) && (heap[place] < heap[parent]))
	{
		swap(place, parent);
		place = parent;
		parent = (place - 1) / 2;
	}

	size++;
}

bool BinaryHeap::isEmpty()
{
	return(size == 0);
}


int BinaryHeap::getMin()
{
	if (isEmpty())
	{
		cout << "EMPTY" << endl;
		return -1;
	}
	else
	{
		return heap[0];
	}
}


void BinaryHeap::deleteMin()
{
	if (isEmpty())
		cout << "EMPTY" << endl;
	else
	{
		heap[0] = heap[--size];
		percolateDown(0);

	}

}


void BinaryHeap::percolateDown(int root)
{
	int child = 2 * root + 1;

	if (child < size)
	{
		int rightchild = child + 1;

		if ((rightchild < size) && (heap[rightchild] < heap[child]))
		{
			child = rightchild;
		}

		if (heap[root] > heap[child])
		{
			swap(root, child);
			percolateDown(child);

		}

	}

}