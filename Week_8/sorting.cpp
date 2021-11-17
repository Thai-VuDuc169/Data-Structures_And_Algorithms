/*
1) Manually sort the elements 77, 49, 25, 12, 9, 33, 56, 81 
using: insertion sort, bubble sort, selection sort, quick sort, merge sort and heap sort. 
Represent the temporal result for each step of sorting  
2) Write functions to sort an array of integers using one basic sort algorithm 
and one advanced sort algorithm . Test with the above example
*/
#include<iostream>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}


/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1); // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or
		// equal to pivot
		if (arr[j] <= pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
int count_quichsort = 1;
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		at right place */
		int pi = partition(arr, low, high);
      // print the current state
      cout << "step " << count_quichsort++ << ": ";
      printArray(arr, 6); 

		// Separately sort elements before
		// partition and after partition
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void selectionSort(int arr[], int len)
{
   for (int i = 0; i < len - 1; i++)
   {
      for (int j = i + 1; j < len; j++)
      {
         if (arr[j] < arr[i])
            swap(&arr[i], &arr[j]);
      }
      cout << "step " << i << ": ";
      printArray(arr, len);
   }
}

int main()
{
	int arr1[] = {10, 7, 8, 9, 1, 5};
   int arr2[] = {10, 7, 8, 9, 1, 5};
	int len = sizeof(arr1)/sizeof(arr1[0]);
	cout << "Quich Sort Steps: " << endl;
	quickSort(arr1, 0, len - 1);
   cout << "Selection Sort Steps: " << endl;
   selectionSort(arr2, len);
	return 0;
}
