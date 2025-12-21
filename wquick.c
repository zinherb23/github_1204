#include<stdio.h>

void insert_sort(int* arr, int len){
	for(int i = 1; i < len; i++){
		int value = arr[i];
		int j = i;
		while(j>0 && value > arr[j-1]){
			arr[j] = arr[j-1];
			j--;
		}
		arr[j] = value;
	}
}


int main(){
	int arr[] = {2,5,4,6,3,1};
	int len = sizeof(arr)/4;
	insert_sort(arr,len);
	for(int i = 0; i < len; ++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
