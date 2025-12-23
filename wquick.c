#include<stdio.h>

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}


int partition(int* arr, int left, int right){
	int i = left - 1;
	int j = right + 1;
	int p = arr[left];
	while(1){
		do{
			i++;
		}while(arr[i] < p);

		do{
			j--;
		}while(arr[j] > p);

		if(i >= j){
			return j;
		}
		swap(&arr[i], &arr[j]);
	}
}


void h_quick_sort(int* arr, int left, int right){
	if(left >= right) return;
	int p = partition(arr, left, right);
	h_quick_sort(arr, left, p);
	h_quick_sort(arr, p+1, right);
}

int main(){
	int arr[] = {2,5,4,6,3,1};
	int len = sizeof(arr)/4;
	h_quick_sort(arr,0,len-1);
	for(int i = 0; i < len; ++i){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
