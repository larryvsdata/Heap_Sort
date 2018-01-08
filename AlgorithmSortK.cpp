#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <ctime>

using namespace std;
#include "SelectionAlgorithm.h"


class AlgorithmSortK :public SelectionAlgorithm
{
public:


	AlgorithmSortK(int kk) : SelectionAlgorithm(kk)
	{	}

	int select()
	{
		int N;

		int type, k;

		ifstream read("data.txt");
		read >> type;
	//	cout << type << endl;
		read >> k;
	//	cout << k << endl;


		read >> N;
	//	cout << N << endl;
		int *numbers;

		numbers = new int[N];

		for (int i = 0; i < N; i++)
		{
			read >> numbers[i];
		}


/*			cout << "**********"<< endl;

		for (int i = 0; i < N; i++)
		{
		cout <<numbers[i]<< endl;
		} */

//		int min, temp;

		clock_t start = clock();

		for (int index = 1; index < k; index++)
		{
			int key = numbers[index];
			int position = index;
			while (position > 0 && key < numbers[position - 1])
			{
				numbers[position] = numbers[position - 1];
				position--;
			}
			numbers[position] = key;

		}

		
	//	int val = numbers[N-1];

		for (int z = k+1; z < N;z++)
		{ 
		for (int i = 0; i < k+1 ; i++)
		{
			if (numbers[z] < numbers[i])
			{
				for (int j = k - 1; j > i-1; j--)
				{
					numbers[j + 1] = numbers[j];
				}
				numbers[i] = numbers[z];
				i = k;
			}

		}
		}


		clock_t end = clock();
		double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;


		cout << N << endl;
		cout << k << endl;


		cout << "The number  " << numbers[k] << " is found in  " << cpu_time << "  seconds " << endl;

	   return numbers[k-1];
	};


	
};