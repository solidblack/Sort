#include "stdio.h"

void insertSort(int *arry, int number)
{
	int temp;
	int j;


	for (int i = 1; i < number; ++i)
	{
		temp = arry[i];
		j = i - 1;
		while(j >= 0 && arry[j] > temp)
		{
			arry[j + 1] = arry[j];
			j--;
		}
		arry[j + 1] = temp;
	}
}

int main(int argc, char const *argv[])
{
	int arry[] = {2,3,8,0,33,11,2,3,4,5,6};
	int length = sizeof(arry) / sizeof(arry[0]);

	printf("The number before sorted:");
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arry[i]);
	}

	insertSort(arry, length);
	printf("The number after sorted:\n");
	for (int i = 0; i < length; ++i)
	{
		printf("%d ", arry[i]);
	}
	return 0;
}