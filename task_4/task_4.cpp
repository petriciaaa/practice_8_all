#include <iostream>

const int MAXCOLS = 10;
const int MAXROWS = 4;


void convertToDynamicArray(int(*arr)[MAXCOLS],int ** pRes,int rows) {

	for (int i = 0; i < rows; i++)
	{
		const int cols = arr[i][0];
		int* fillingArr = new int[cols];

		for (int j = 0; j < cols; j++)
		{
			fillingArr[j] = 1;
			pRes[i][j] = fillingArr[j];
		}
		delete []fillingArr;
	}

}

void printArray(int** arr, int rows, int* cols) {
	std::cout <<"Dynamic array" << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols[i]; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void printArray(int(*arr)[MAXCOLS], int rows) {
	std::cout <<"Initial array:" << std::endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < MAXCOLS; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main()
{

	int arr[MAXROWS][MAXCOLS] = {
		{5,1,1,1,1,1,0,0,0,0},
		{7,1,1,1,1,1,1,1,0,0},
		{9,1,1,1,1,1,1,1,1,1},
		{3,1,1,1,0,0,0,0,0,0},
	};

	//pointer to 2 dimension arr in all rows MAXCOLS elems int type
	int (*pArr)[MAXCOLS];
	pArr = arr;

	int resCols[MAXROWS];

	int** pRes = new int* [MAXROWS];
	
	for (int i = 0; i < MAXROWS; i++)
	{
		pRes[i] = new int[MAXCOLS];
		resCols[i] = arr[i][0];
	}
	

	convertToDynamicArray(pArr, pRes, MAXROWS);

	printArray(pArr, MAXROWS);

	printArray(pRes, MAXROWS,resCols);

	for (int i = 0; i < MAXROWS; i++)
	{
		delete  pRes[i];

	}
	delete[] pRes;

	return 0;
}

