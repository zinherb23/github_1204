#include<stdio.h>

void merge(int* arr, int* temp, int left, int mid, int right){
	int n = left;
	int m = mid+1;
	int o = left;
	while(n <= mid && m <= right){
		if(arr[n] > arr[m]){
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
void merge_sort(int* arr, int n){
	int temp[n];
	for(int curr = 1; curr < n; curr*=2){
		for(int left = 0; left < n -1; left += curr*2){
			int mid = left + curr - 1;
			int right = left + curr*2 - 1;
			if(mid >= n){
				continue;
			}
			if(right >= n){
				right = n - 1;
			}
			merge(arr,temp,left, mid, right);
		}
	}	
}
int main(){
	int arr[] = {5,2,4,1,6,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	merge_sort(arr,n);
	for(int i = 0; i < n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
