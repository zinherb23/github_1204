#include<stdio.h>
#include<stdlib.h>

void merge(int* arr, int left, int mid, int right){
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int *left_arr = malloc(n1 * sizeof(int));
	int *right_arr = malloc(n2 * sizeof(int));
	if(!left_arr || !right_arr){
		printf("memory failed\n");
		exit(1);
	}
	for(int i = 0; i < n1; i++){
		left_arr[i] = arr[i+left];
	}
	for(int j = 0; j < n2; j++){
		right_arr[j] = arr[j+mid+1];
	}
	int i = 0, j = 0, k = left;
	while(i < n1 && j < n2){
		if(left_arr[i] < right_arr[j]){
			arr[k++] = left_arr[i++];
		}else{
			arr[k++] = right_arr[j++];
		}
	}
	while(i < n1){
		arr[k++] = left_arr[i++];
	}
	while(j< n2){
		arr[k++] = right_arr[j++];
	}
	free(left_arr);
	free(right_arr);
}

void print_arr(int* arr, int len){
	for(int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


void merge_sort(int* arr, int left, int right){
	if(left >= right) return;
	int mid = left + (right - left)/2;
	merge_sort(arr, left, mid);
	merge_sort(arr, mid+1, right);
	merge(arr,left,mid,right);
}

int main(){
	int arr[]={1,6,2,3,5,4};
	int len = sizeof(arr)/sizeof(arr[0]);
	merge_sort(arr, 0, len-1);
	int len2 = sizeof(arr[0]);
	printf("size of arr[0] is %d\n",len2);
	print_arr(arr,len);
	
	return 0;
}
