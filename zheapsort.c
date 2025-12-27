#include<stdio.h>
#define size 16


typedef struct{
	int count;
	int arr[size];
	
}heap;

int heap_delete(heap* myheap){
	int value = myheap->arr[0];
	if(myheap->count == 1){
		return value;
	}
	myheap->arr[0]= myheap->arr[--myheap->count];
	int index = 0;
	while(index < myheap->count){
		int leftchild = index*2 + 1;
		int rightchild  = index*2 + 2;
		int temp_index = index;
		int temp_value = myheap->arr[temp_index];
		if(temp_value > myheap->arr[leftchild] && leftchild < myheap->count){
			temp_value = myheap->arr[leftchild];
			temp_index = leftchild;
		}
		if(temp_value >myheap->arr[rightchild] && rightchild < myheap->count){
			temp_value = myheap->arr[rightchild];
			temp_index = rightchild;
		}
		int swap_value = myheap->arr[temp_index];
		myheap->arr[temp_index] = myheap->arr[index];
		myheap->arr[index] = swap_value;
		index = temp_index;
		break;
		
	}
	return value;
}



void heap_insert(heap* heap, int n){
	if(heap->count == 0){
		heap->arr[heap->count++] = n;
		return;
	}
	heap->arr[heap->count++] = n;
	int index = heap->count-1;
	while(index > 0){
		int parent = (index-1)/2;
		if(heap->arr[index] < heap->arr[parent]){
			int temp = heap->arr[parent];
			heap->arr[parent] = heap->arr[index];
			heap->arr[index] = temp;
		}	
		index = parent;
		
	}
	return;
}

void heap_sort(int* arr, int n){
	if(n <= 1) return;
	heap myheap;
	myheap.count = 0;
	for(int i = 0; i < n; ++i){
		heap_insert(&myheap,arr[i]);
	}
	for(int i = 0; i < n; ++i){
		arr[i] = heap_delete(&myheap);
	}
	return;	
}

int main(){
	int arr[] = {1,5,4,2,3,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	heap_sort(arr,len);
	for(int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
