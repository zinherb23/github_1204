#include<stdio.h>

#define MAX_NODES 128
#define NULL_IDX -1

typedef struct{
	int key;
	int left;
	int right;
	int used;
}BSTNode;

static BSTNode pool[MAX_NODES];
static int root = NULL_IDX;

static int alloc_node(int key){
	for(int i = 0; i < MAX_NODES; i++){
		if(!pool[i].used){
			pool[i].used = 1;
			pool[i].key = key;
			pool[i].left = NULL_IDX;
			pool[i].right = NULL_IDX;
			return i;
		}
	}
	return NULL_IDX;
}

void bst_insert(int key){
	if(root == NULL_IDX){
		root = alloc_node(key);
		return;
	}
	int cur = root;
	while(1){
		if(key < pool[cur].key){
			if(pool[cur].left == NULL_IDX){
				pool[cur].left = alloc_node(key);
				return;
			}
			cur = pool[cur].left;
		}else{
			if(pool[cur].right == NULL_IDX){
				pool[cur].right = alloc_node(key);
				return;
			}
			cur = pool[cur].right;
		}
	}
}

int bst_search(int key){
	int cur = root;
	while(cur != NULL_IDX){
		if(key == pool[cur].key){
			return cur;
		}
		cur = (key < pool[cur].key) ? 
			pool[cur].left : pool[cur].right;
	}
	return NULL_IDX;
}

void bst_inorder(int idx){
	if(idx == NULL_IDX) return;
	bst_inorder(pool[idx].left);
	printf("%d ", pool[idx].key);
	bst_inorder(pool[idx].right);
}

int main(){
	bst_insert(8);
	bst_insert(3);
	bst_insert(10);
	bst_insert(1);
	bst_insert(6);
	bst_insert(99);
	bst_insert(199);
	
	bst_inorder(root);
	printf("\n");
	int idx	= bst_search(199);
	printf("my number is at %d\n",idx);
	return 0;
}










