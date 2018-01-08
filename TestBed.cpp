#include <string>
#include <iostream>

using namespace std;
#include "SelectionAlgorithm.h"
#include "AlgorithmSortAll.cpp";
#include "AlgorithmSortK.cpp";
#include "AlgorithmSortHeap.cpp";

class TestBed
{
public:

	TestBed() {};
	~TestBed() {};

	void setAlgorithm(int type, int kn)
	{
		
		if (type == 1)
		{
			
			algorithm = new AlgorithmSortAll(kn);
			
		}
		else if (type == 2)
		{
			algorithm = new AlgorithmSortK(kn);
			
		}
		else if (type == 3)
		{
			algorithm = new AlgorithmSortHeap(kn);

		}

	}


	void execute()
	{
		
		algorithm->select() ;
		
	};

	SelectionAlgorithm *algorithm;
};