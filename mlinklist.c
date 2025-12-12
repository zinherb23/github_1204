#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

static Node* list_head = NULL;

void insert_list(int value){
	Node* temp = malloc(1*sizeof(Node));
	temp->data = value;
	temp->next = list_head;
	list_head = temp;
	return;
}
void free_node(Node* node){
	free(node);
	return;
}


void delete_list(int value){
	Node* curr = list_head;
	Node* prev = NULL;
	while(curr!=NULL){
		if(curr->data == value){
			if(prev == NULL){
				list_head = curr->next;
			}else{
				prev->next = curr->next;
			}
			free_node(curr);
			return;
		}
		prev = curr;
		curr = curr->next;
	}
	return;

}

void print_list(){
	Node* temp = list_head;
	while(temp!=NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}
int main(){
	insert_list(11);
	insert_list(22);
	insert_list(33);
	print_list();
	delete_list(22);
	print_list();
	while(list_head){
		Node* temp = list_head;
		list_head = temp->next;
		free(temp);
	}
	return 0;
}










