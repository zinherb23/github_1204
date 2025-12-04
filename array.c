#include <stdio.h>
#include <stdbool.h>
#define STACK_CAP 100

typedef struct{
	int arr[STACK_CAP];
	int top;
} Stack;
void stackInit(Stack* s){
	s->top = -1;
}
bool stackIsEmpty(Stack* s){
	return s->top == -1;
}
bool stackIsFull(Stack* s){
	return s->top == STACK_CAP-1;
}
bool stackPush(Stack* s, int n){
	if(stackIsFull(s)) return false;
	s->arr[++s->top] = n;
	return true;
}
bool stackPop(Stack* s, int* out){
	if(stackIsEmpty(s)) return false;
	*out = s->arr[s->top--];
	return true;
}
bool stackPeek(Stack* s, int* out){
	if(stackIsEmpty(s)) return false;
	*out = s->arr[s->top];
	return true;
}

int main(){
	Stack s;
	stackInit(&s);
	int out;
	stackPush(&s,1);
	stackPush(&s,4);
	stackPush(&s,7); 
	stackPeek(&s,&out);
	printf("the value is %d", out);
	stackPop(&s,&out);	
	printf("the value is %d", out);
	stackPop(&s,&out);	
	printf("the value is %d", out);
	return 0;


}
