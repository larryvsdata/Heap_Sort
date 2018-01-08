#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include <ctime>

#include "SelectionAlgorithm.h"


class AlgorithmSortAll :public SelectionAlgorithm
{
public:


	AlgorithmSortAll(int kk) : SelectionAlgorithm(kk)
	{	}

	int select()
	{
		//cout << "Enter N" << endl;
		int N;

		int type, k;

		ifstream read("data.txt");
		read >> type;
	//	cout << type << endl;
		read >> k;
//		cout << k << endl;


		read>> N;
	//	cout << N<<endl;
		int *numbers;

		numbers = new int[N];

		for (int i = 0; i < N ; i++)
		{
			read >> numbers[i];
		}


		
		

/*		cout << "Enter all numbers" << endl;
		for (int i = 0; i < N; i++)
		{
			int num;
			cin >>num  ;
			numbers[i] = num;
		}
*/

//		int min, temp;

		clock_t start = clock();
		for (int index = 1; index < N ; index++)
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
		clock_t end = clock();
		double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
		




	//	cout << N << endl;
	//	cout << k << endl;

		cout << "The number  "<<numbers[k]<<" is found in  " << cpu_time <<"  seconds "<< endl;


		return numbers[k-1];
	};


	
};