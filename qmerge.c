#include<stdio.h>

void merge(int* arr, int* temp, int left, int mid, int right){
	int n = left;
	int m = mid+1;
	int o = left;
	while(n <= mid && m <= right){
		if(arr[n] < arr[m]){
			temp[o++] = arr[n++];
		}else{
			temp[o++] = arr[m++];
		}
	}
	while(n <= mid){
		temp[o++] = arr[n++];
	}
	while(m <=right){
		temp[o++] = arr[m++];
	}
	for(int i = left; i <= right; i++){
		arr[i] = temp[i];
	}
}


void merge_sort(int* arr, int* temp, int left, int right){
	if(left >= right) return;
	int mid = left + (right - left)/2;
	merge_sort(arr, temp, left, mid);
	merge_sort(arr, temp, mid+1, right);
	merge(arr, temp, left, mid, right);
}

void merge_sort_temp(int* arr, int n){
	int temp[n];
	merge_sort(arr, temp, 0, n-1);
}

int main(){
	int arr[] = {5,2,4,1,6,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	merge_sort_temp(arr,n);
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
