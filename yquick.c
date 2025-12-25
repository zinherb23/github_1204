
#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int* arr, int left, int right){
	int low = left - 1;
	int high = right + 1;
	int p = arr[right];
	while(1){
		do{
			low++;
		}while(arr[low] < p);
		do{
			--high;
		}while(p < arr[high]);
		if(low >= high){
			return low;

		}
		swap(&arr[low], &arr[high]);
	}
}


void static_h_quick(int* arr, int n){
	int* stack = calloc(2*n, sizeof(int));
	if(!stack) return;
	int top = -1;
	stack[++top] = 0;
	stack[++top] = n-1;
	while(top >= 0){
		int high = stack[top--];
		int low = stack[top--];
		if(low < high){
			int p = partition(arr,low,high);
			if(low < p-1){
				stack[++top] = low;
				stack[++top] = p-1;
			}
			if(p < high){
				stack[++top] = p;
				stack[++top] = high;
			}
		}
	}
	free(stack);
}
int main(){
	int arr[] = {2,4,5,1,3,6};
	int n = sizeof(arr)/sizeof(arr[1]);
	static_h_quick(arr,n);
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;


}


/*
#include <stdio.h>

// Standard swap helper
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Hoare Partition Scheme
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        // Find leftmost element greater than or equal to pivot
        do {
            i++;
        } while (arr[i] < pivot);

        // Find rightmost element smaller than or equal to pivot
        do {
            j--;
        } while (arr[j] > pivot);

        // If pointers cross, partitioning is complete
        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

// Recursive Quicksort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // p is the split point
        int p = partition(arr, low, high);

        // Note: In Hoare's scheme, the pivot is NOT necessarily
        // at the split point, so we include 'p' in the left side.
        quickSort(arr, low, p);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int arr[] = {2,4,3,5,1,6};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
*/
