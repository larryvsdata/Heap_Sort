
#include <iostream>
#include <cassert>
#include "BinaryHeap.h"

using namespace std;

int main ()
{
	cout << "Testing your heap implementation..." << endl << endl;

	BinaryHeap heap(10);

	// BASICS
	cout << "Testing insert for a single item..." << endl;
	heap.insert(3);
	assert(heap.getMin() == 3);
	heap.deleteMin();

	// INSERT
	cout << "Testing insert..." << endl;
	heap.insert(5);
	heap.insert(10);
	heap.insert(4);
	heap.insert(2);
	heap.insert(56);
	heap.insert(34);

	// GETMIN
	cout << "Testing getMin..." << endl;
	assert(heap.getMin() == 2);


	



	// DELETEMIN
	cout << "Testing deleteMin..." << endl;
	heap.deleteMin();
	heap.deleteMin();

	// GETMIN AFTER DELETEMIN
	cout << "Testing getMin after deleteMin..." << endl;
	assert(heap.getMin() == 5);

	

	// EXCESSIVE DELETEMIN
	cout << "Testing deleteMin on an empty heap..." << endl;
	heap.deleteMin();
	heap.deleteMin();
	heap.deleteMin();
	heap.deleteMin();
	heap.deleteMin();

	

	// GETMIN AFTER EXCESSIVE DELETEMIN
	cout << "Testing deleteMin on an empty heap..." << endl;
	assert(heap.getMin() == -1);

	/**/

	//IF THERE ARE TWO CHILDREN NODES THAT ARE BOTH SMALLER THAN THE PARENT, SWAP SMALLER
	cout << "Testing percolate down  If there are two children nodes that are both smaller than the parent... " << endl;
	heap.insert(23);
	heap.insert(43);
	heap.insert(234);
	heap.insert(321);
	heap.insert(243);
	cout << "Testing percolate down  If there are two children nodes that are both smaller than the parent..." << endl;
	assert(heap.getMin() == 23);
	heap.deleteMin();
	assert(heap.getMin() == 43);
	heap.deleteMin();
	assert(heap.getMin() == 234);
	heap.deleteMin();
	assert(heap.getMin() == 243);
	heap.deleteMin();
	assert(heap.getMin() == 321);
	heap.deleteMin();
	
	// DUPLICATE ELEMENTS
	cout << "Testing insert with duplicate values..." << endl;
	heap.insert(5);
	heap.insert(10);
	heap.insert(4);
	heap.insert(4);
	heap.insert(2);
	heap.insert(56);
	heap.insert(10);
	heap.insert(34);

	// GETMIN WITH DUPLICATE ELEMENTS
	cout << "Testing getMin..." << endl;
	assert(heap.getMin() == 2);
	
	// EXCESSIVE INSERT
	cout << "Testing insert over capacity..." << endl;
	heap.insert(25);
	heap.insert(100);
	heap.insert(54);
	heap.insert(44);
	heap.insert(26);
	heap.insert(3);
	heap.insert(48);
	heap.insert(9);

	// GETMIN AFTER EXCESSIVE INSERT
	cout << "Testing getMin..." << endl;
	assert(heap.getMin() == 2);

	cout << endl << "Congrats! Your Heap implementation passed all the tests!" << endl;
	cout << "Now you can use your implementation to complete Homework 4;" << endl;
	cout << "copy the files BinaryHeap.h and BinaryHeap.cpp to extend Homework 1..." << endl;



	

	int k;
	cin >> k;

	return 0;
}
