#include<stdio.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int partition(int* arr, int left, int right){
	int pivot = arr[right];
	int i = left - 1;
	for(int j = left; j < right; j++){
		if(arr[j] <= pivot){
			swap(&arr[++i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[right]);
	return i+1;
}

void quick_sort(int* arr,int left, int right){
	if(left >= right) return;
	int p = partition(arr, left, right);
	quick_sort(arr, left, p - 1);
	quick_sort(arr, p + 1, right);	
}

int main(){
	int arr[] = {2,4,3,1,6,5};
	int len = sizeof(arr)/sizeof(arr[0]);
	quick_sort(arr,0,len-1);
	for(int i=0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}

