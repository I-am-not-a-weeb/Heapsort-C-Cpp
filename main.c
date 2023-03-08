#pragma warning(disable : 4996)

#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int* recursiveheapify(int* arr, int arrSize, int pos)
{
	int leftChild = 2 * pos + 1;
	int rightChild = 2 * pos + 2;
	int largest;

	if (leftChild < arrSize && arr[leftChild] > arr[pos])
	{
		largest = leftChild;
	}
	else
	{
		largest = pos;
	}
	if (rightChild < arrSize && arr[rightChild] > arr[largest])
	{
		largest = rightChild;
	}
	if (largest != pos)
	{
		swap(&arr[largest], &arr[pos]);
		recursiveheapify(arr, arrSize, largest);
		pos = largest;
	}
	return arr;

}
void heapify(int *arr, int arrSize, int pos)
{
	
	do {
		int leftChild = 2 * pos + 1;
		int rightChild = 2 * pos + 2;
		int largest;

		if (leftChild < arrSize && arr[leftChild] > arr[pos])
		{
			largest = leftChild;
		}
		else
		{
			largest = pos;
		}
		if (rightChild < arrSize && arr[rightChild] > arr[largest])
		{
			largest = rightChild;
		}
		if (largest != pos)
		{
			swap(&arr[largest], &arr[pos]);

			pos = largest;
		}
		else {
			break;
		}
	} while (1);
}
void buildHeap(int *arr,int arrSize)
{
	int k = (arrSize - 2) / 2;
	for (int i = k; i >= 0; i--)
	{
		heapify(arr, arrSize, i);
	}
}
void HeapSort(int*arr,int arrSize)
{
	buildHeap(arr,arrSize);
	for (int i = arrSize - 1; i > 0; i--)
	{
		swap(&arr[0], &arr[arrSize-- - 1]);
		heapify(arr, arrSize, 0);
	}
}

int* readSortWriteFile(FILE* infile,FILE*outfile)
{
	int lines = 1;
	char ch;
	while (!feof(infile))
	{
		ch = fgetc(infile);
		if (ch == '\n')
		{
			lines++;
		}
	}

	fclose(infile);
	infile = fopen("wejscie.txt", "r");

	int* arr = malloc((lines) * sizeof(int));

	for (int i = 0; i < lines; i++)
	{
		fscanf(infile, "%d",&arr[i]);
	}
	HeapSort(arr,lines);
	for (int i = 0; i < lines; i++)
	{
		fprintf(outfile, "%d\n", arr[i]);
	}
	return arr;

}

void main()
{
	int s_arr[10] = { 1,2,10,9,8,3,4,5,7,6 };
	int* arr = malloc(10 * sizeof(int));

	FILE* wejscie = fopen("wejscie.txt","r");
	FILE* wyjscie = fopen("wyjscie.txt", "w");

	arr = readSortWriteFile(wejscie,wyjscie);

	if (arr==NULL) return 0;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = s_arr[i];
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort(arr,10);
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}

} 