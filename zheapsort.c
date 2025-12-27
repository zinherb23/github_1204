#include<stdio.h>
#define size 16


typedef struct{
	int count;
	int arr[size];
	
}heap;

int heap_delete(heap* myheap){
	int value = myheap->arr[0];
	if(myheap->count == 0){
		return -1;
	}
	myheap->arr[0]= myheap->arr[--myheap->count];
	int index = 0;
	while(index < myheap->count){
		int leftchild = index*2 + 1;
		int rightchild  = index*2 + 2;
		int temp = index;
		if(leftchild < myheap->count && myheap->arr[temp] > myheap->arr[leftchild]){
			temp = leftchild;
		}
		if(rightchild < myheap->count && myheap->arr[temp] > myheap->arr[rightchild]){
			temp = rightchild;
		}
		if(temp == index) break;
		int swap_value = myheap->arr[temp];
		myheap->arr[temp] = myheap->arr[index];
		myheap->arr[index] = swap_value;
		index = temp;
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
	int arr[] = {6,5,4,3,2,1,7,8,9,10,11,12};
	int len = sizeof(arr)/sizeof(arr[0]);
	heap_sort(arr,len);
	for(int i = 0; i < len; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	return 0;
}
