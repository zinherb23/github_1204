#include <stdio.h>

#define SIZE 128

typedef struct{
	int arr[SIZE];
	int size;
}Maxheap;

static inline void swap(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

void heap_push(Maxheap* h, int val){
	if(h->size >= SIZE){
		printf("heap is full\n");
		return ;
	}

	int i = h->size++;
	h->arr[i] = val;

	while(i > 0){
		int p = (i-1)/2;
		if(h->arr[i] <= h->arr[p]){
			break;
		}
		swap(&h->arr[i],&h->arr[p]);
		i = p;
	}
}

int heap_pop(Maxheap* h){
	if(h->size == 0){
		printf("heap is empty\n");
		return 0;
	}
	int t = h->arr[0];
	h->arr[0] = h->arr[--h->size];
	int i = 0;
	while(1){
		int left = i*2+1;
		int right = i*2+2;
		int largest = i;
		if(left < h->size && h->arr[left] > h->arr[largest]){
			largest = left;
		}
		if(right < h->size && h->arr[right] > h->arr[largest]){
			largest = right;
		}
		if(largest == i){
			break;
		}
		swap(&h->arr[largest], &h->arr[i]);
		i = largest;

	}
	return t;
}
void heap_print(Maxheap* h){
	for(int i = 0; i < h->size; i++){
		printf("%d ", h->arr[i]);
	}
	printf("\n");
}

int main(){
	Maxheap h = {.size = 0};
	heap_push(&h,111);
	heap_push(&h,333);
	heap_push(&h,666);
	heap_push(&h,999);
	heap_print(&h);
	heap_pop(&h);
	heap_print(&h);
	return 0;
}






