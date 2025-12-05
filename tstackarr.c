#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct{
	int* arr;
	int top;
	int cap;
} Dstack;

void stackInit(Dstack* s, int initcap){
	s->arr = malloc(initcap * sizeof(int));
	s->top = -1;
	s->cap = initcap;
}

bool stackIsEmpty(Dstack* s){
	return s->top == -1;
}

void stackGrow(Dstack* s){
	int newcap = s->cap*2;
	s->arr = realloc(s->arr,newcap * sizeof(int));
	s->cap = newcap;
}

bool stackPush(Dstack* s, int value){
	if(s->top == s->cap-1) {
		stackGrow(s);
	}
	s->arr[++s->top] = value;
	return true;
}

bool stackPop(Dstack* s, int* out){
	if(stackIsEmpty(s)) return false;
	*out = s->arr[s->top--];
	return true;
}
bool stackPeek(Dstack* s, int* out){
	if(stackIsEmpty(s)) return false;
	*out = s->arr[s->top];
	return true;
}

void cleanUp(Dstack* s){
	free(s->arr);
}


int main(){
	Dstack s;
	stackInit(&s,2);
	stackPush(&s,11);
	stackPush(&s,22);
	stackPush(&s,33);
	stackPush(&s,44);
	stackPush(&s,55);
	int out = 0;
	stackPeek(&s,&out);
	printf("the value is %d\n", out);
	stackPop(&s,&out);
	printf("the value is %d\n", out);
	cleanUp(&s);
	return 0;
}















