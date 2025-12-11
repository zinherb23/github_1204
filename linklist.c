#include <stdio.h>
#include <stdint.h>

#define SIZE 10

typedef struct{
	int data;
	int next;
}Node;

static Node pool[SIZE];

static int free_head = -1;
static int list_head = -1;

void init_pool(void){
	for(int i = 0; i < SIZE; i++){
		pool[i].next = i + 1;
	}
	pool[SIZE-1].next = -1;
	free_head = 0;
}
int alloc_node(void){
	if(free_head == -1) return -1;
	int idx = free_head;
	free_head = pool[idx].next;
	return idx;
}
void free_node(int idx){
	pool[idx].next = free_head;
	free_head = idx;
}
int list_insert(int value){
	int idx = alloc_node();
	if(idx == -1) return -1;

	pool[idx].data = value;
	pool[idx].next = list_head;
	list_head = idx;
	return idx;
}
int list_delete(int value){
	int prev = -1;
	int cur = list_head;
	while(cur != -1){
		if(pool[cur].data == value){
			if(prev == -1){
				list_head = pool[cur].next;
			}
			else{
				pool[prev].next = pool[cur].next;
			}
			free_node(cur);
			return 1;
		}
		prev = cur;
		cur = pool[cur].next;
	}
	return 0;
}
void list_print(void){
	int cur = list_head;
	while(cur != -1){
		printf("%d ",pool[cur].data);
		cur = pool[cur].next;
	}
	printf("\n");
}
int main(void){
	init_pool();
	list_insert(11);
	list_insert(33);
	list_insert(66);
	list_print();
	list_delete(33);
	list_print();
	return 0;
}




