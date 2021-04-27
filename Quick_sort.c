#include <stdio.h>

// function to swap elements
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

// function to find the partition position
int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot = array[high];
  
  // pointer for greater element
  int i = (low - 1);

  // traverse each element of the array
  // compare them with the pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {      
      
      i++;
      swap(&array[i], &array[j]);
    }
  }

  
  swap(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}



void quickSort(int array[], int low, int high) {
  if (low < high) {
    
    /*find the pivot element such that 
	elements smaller than pivot are on left of pivot
	 elements greater than pivot are on right of pivot*/
    int pi = partition(array, low, high);   
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}


// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


int main() {
	int n,i;
	printf("Enter the number of elements that need to be sorted. ");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
  
  
  
  
  printf("Unsorted Array\n");
  printArray(arr, n);
  
  // perform quicksort on data
  quickSort(arr, 0, n - 1);
  
  printf("Sorted array in ascending order: \n");
  printArray(arr, n);
}

