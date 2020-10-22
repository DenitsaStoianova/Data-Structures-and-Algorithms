#include "pch.h"
#include <iostream>

void bubbleSort(int* arr, int size)
{
	bool areSwapped;
	int temp;
	for (int i = 0; i < size - 1; i++)
	{
		areSwapped = false;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;

				areSwapped = true;
			}
		}

		if (!areSwapped) 
		{
			break;
		}
	}
}

void selectionSort(int* arr, int size)
{
	int minIndex, temp;
	for (int i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex]) 
			{
				minIndex = j;
			}
		}

		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

void insertionSort(int* arr, int size)
{
	int key, j;
	for (int i = 1; i < size; i++)
	{
		key = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > key) 
		{  
			arr[j + 1] = arr[j];       
			j--;					  
		}							 
		arr[j + 1] = key; 
	}
}

int partition(int* arr, int startIndex, int endIndex)
{
	int pivot = arr[endIndex];
	int pIndex = startIndex;
	int temp;
	for (int i = startIndex; i < endIndex; i++)
	{
		if (arr[i] < pivot) 
		{					
			temp = arr[i];
			arr[i] = arr[pIndex];
			arr[pIndex] = temp;
			pIndex++; 
		}
	}

	temp = arr[pIndex]; 
	arr[pIndex] = arr[endIndex];
	arr[endIndex] = temp;

	return pIndex;
}

void quickSort(int* arr, int startIndex, int endIndex) 
{	
	if (startIndex < endIndex)
	{
		int pIndex = partition(arr, startIndex, endIndex);
		quickSort(arr, startIndex, pIndex - 1); 
		quickSort(arr, pIndex + 1, endIndex);
	}
}

void printArr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	int arr[] = { 12, 8, 5, 4, 2, 10, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	return 0;
}
