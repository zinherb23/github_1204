#include<stdio.h>
#include<stdlib.h>

#define SIZE 16
typedef struct{
	int* arr;
	int capacity;
	int size;
}heapmin;

void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

heapmin* createheap(){
	heapmin* heap = malloc(sizeof(heapmin));
	if(!heap) return NULL;
	heap->arr = malloc(SIZE * sizeof(int));
	if(!heap->arr){
		free(heap);
		return NULL;
	}
	heap->capacity = SIZE;
	heap->size = 0;
	return heap;
}
void push_heap(heapmin* h, int value){
	if(h->size >= h->capacity){
		return;
	}
	h->arr[h->size] = value;
	int i = h->size;
	while(1){
		int p = (i - 1)/ 2;
		if(h->arr[p] <= h->arr[i]) break;
		swap(&h->arr[p],&h->arr[i]);
		i = p;
	}
	h->size++;
}
void pop_heap(heapmin* h,int* out){
	if(h->size == 0) return;
	*out = h->arr[0];
	h->arr[0] = h->arr[--h->size];
	int i = 0;
	while(1){
		int l = i*2 + 1;
		int r = i*2 + 2;
		int min_i = i;
		if(l < h->size && h->arr[min_i] > h->arr[l]){
			min_i = l;
		}
		if(r < h->size && h->arr[min_i] > h->arr[r]){
			min_i = r;
		}
		if(min_i == i) break;
		swap(&h->arr[i], &h->arr[min_i]);
		i = min_i;
	}
}
void print_heap(heapmin* h){
	for(int i = 0; i < h->size; i++){
		printf("%d ", h->arr[i]);
	}
	printf("\n");
}

int main(){
	heapmin* h = createheap();
	push_heap(h,11);
	push_heap(h,234);
	push_heap(h,24);
	push_heap(h,3);
	push_heap(h,4444);
	print_heap(h);
	int temp;
	pop_heap(h,&temp);
	print_heap(h);
	if(!h) return 0;
	free(h->arr);
	free(h);
	return 0;
}












