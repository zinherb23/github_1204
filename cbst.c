#include<stdio.h>

#define MAX_NODES 128
#define NULL_IDX (-1)

typedef struct{
	int key;
	int used;
	int left;
	int right;
}BSTNode;

static BSTNode pool[MAX_NODES];
static int root = NULL_IDX;
static int free_head = 0;

void bst_init(void){
	for(int i = 0; i < MAX_NODES - 1; i++){
		pool[i].right = i + 1;
		pool[i].used = 0;
	}
	pool[MAX_NODES-1].right = NULL_IDX;
	pool[MAX_NODES-1].used = 0;
	free_head = 0;
	root = NULL_IDX;
}

int alloc_node(int key){
	if(free_head == NULL_IDX){
		return NULL_IDX;
	}
	int idx = free_head;
	free_head = pool[idx].right;
	pool[idx].key = key;
	pool[idx].used = 1;
	pool[idx].left = NULL_IDX;
	pool[idx].right = NULL_IDX;
	return idx;
}

void free_node(int idx){
	pool[idx].used = 0;
	pool[idx].right = free_head;
	free_head = idx;
}

void bst_insert(int key){
	if(root == NULL_IDX){
		root = alloc_node(key);
		return;
	}
	int curr = root;
	while(1){
		if(pool[curr].key > key){
			if(pool[curr].left == NULL_IDX){
				pool[curr].left = alloc_node(key);
				return;
			}
			curr = pool[curr].left;
		}else{
			if(pool[curr].right == NULL_IDX){
				pool[curr].right = alloc_node(key);
				return;
			}		
			curr = pool[curr].right;
		}
	}
}

int bst_min(int idx){
	while(pool[idx].left != NULL_IDX){
		idx = pool[idx].left;
	}
	return idx;
}

int bst_delete_rec(int curr, int key){
	if(curr == NULL_IDX){
		return NULL_IDX;
	}
	if(key < pool[curr].key){
		pool[curr].left = bst_delete_rec(pool[curr].left,key);
	}else if(key > pool[curr].key){
		pool[curr].right = bst_delete_rec(pool[curr].right,key);
	}else{
		if(pool[curr].left == NULL_IDX){
			int right = pool[curr].right;
			free_node(curr);
			return right;
		}else if(pool[curr].right == NULL_IDX){
			int left = pool[curr].left;
			free_node(curr);
			return left;
		}
		int succ = bst_min(pool[curr].right);
		pool[curr].key = pool[succ].key;
		pool[curr].right = bst_delete_rec(pool[curr].right,pool[succ].key);
	}
	return curr;
}

void bst_delete(int key){
	bst_delete_rec(root, key);
}

void inorder(int idx){
	if(idx == NULL_IDX){
		return;
	}
	inorder(pool[idx].left);
	printf("%d ",pool[idx].key);
	inorder(pool[idx].right);
}

int main(){
	bst_init();
	bst_insert(2);
	bst_insert(5);
	bst_insert(6);
	bst_insert(3);
	bst_insert(7);
	bst_insert(1);
	bst_insert(4);
	bst_insert(8);
	inorder(root);
	printf("\n");
	bst_delete(1);
	inorder(root);
	printf("\n");
	bst_delete(4);
	inorder(root);
	printf("\n");
	return 0;
}








