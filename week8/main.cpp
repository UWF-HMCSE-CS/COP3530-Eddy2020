#include <iostream>


void insertionSort(int *unsortedArray)
{

	for(int i = 0; i < 5; i++)
	{
		int a = i;
		while(unsortedArray[a] < unsortedArray[a - 1])
		{
			int temp = unsortedArray[a];
			unsortedArray[a] = unsortedArray[a - 1];
			unsortedArray[a - 1] = temp;
			a--;
		}
	}
}

int main()
{
	int *unsortedArray = new int[5];

	unsortedArray[0] = 3;
	unsortedArray[1] = 4;
	unsortedArray[2] = 1;
	unsortedArray[3] = 7;
	unsortedArray[4] = 2;

	insertionSort(unsortedArray);
	
	for(int i = 0; i < 5; ++i)
	{
		std::cout << unsortedArray[i] << std::endl;
	}
	return 0;
}





