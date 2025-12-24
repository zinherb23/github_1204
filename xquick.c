#include<stdio.h>
#include<stdlib.h>
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int low, int high){
	int count = low - 1;
	int pivot = arr[high];
	for(int i = low; i < high; i++){
		if(arr[i] <= pivot){
			swap(&arr[++count],&arr[i]);
		}
	}
	swap(&arr[++count],&arr[high]);
	return count;
}

void static_l_quick_sort(int* arr, int left, int right){
	int n = right + 1;
	int* stack = calloc(2*n, sizeof(int));
	if(!stack) return;
	int top = - 1;	
	stack[++top] = left;
	stack[++top] = n - 1;
	while(top >= 0){
		int high = stack[top--];
		int low = stack[top--];
		if(low < high){
			int p = partition(arr, low, high);
			if(p+1 < high){
				stack[++top] = p+1;
				stack[++top] = high;
			}
			if(low < p-1){
				stack[++top]= low;
				stack[++top]=p-1;
			}
		}

	}
	free(stack);

}

int main(){
	int arr[] = {2,4,1,5,6,3};
	int len = sizeof(arr)/sizeof(arr[1]);
	static_l_quick_sort(arr,0,len-1);
	for(int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}	
