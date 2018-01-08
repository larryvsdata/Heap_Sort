#include <string>
#include <iostream>
#include <ctime>
using namespace std;

#include "SelectionAlgorithm.h"
#include "BinaryHeap.h"

class AlgorithmSortHeap :public SelectionAlgorithm
{

public:
	AlgorithmSortHeap(int kk) : SelectionAlgorithm(kk)
	{
		k = kk;
	}

	int select()
	{

		int N;

		

		cout << "Enter N" << endl;
		cin >> N;


		cout << "Enter all numbers" << endl;
		int *numbers;

		numbers = new int[N];

		for (int i = 0; i < N; i++)
		{
			cin>> numbers[i];
		}



		clock_t start = clock();
		
		BinaryHeap *heap1 = new BinaryHeap(k);


		for (int i = 0; i < k; i++)
		{
			heap1->insert(numbers[i]);
		}


		for (int i = k; i < N; i++)
		{
			if (numbers[i] > heap1->getMin())
			{
				heap1->deleteMin();
				heap1->insert(numbers[i]);
			}
			
		}
		clock_t end = clock();
		double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		cout << "The number  " << heap1->getMin() << " is found in  " << cpu_time << "  seconds " << endl;

		return heap1->getMin();
	}

};