#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define SIZE 128

typedef struct{
	uint8_t buffer[SIZE];
	uint16_t head;
	uint16_t tail;
	uint16_t count;
}ringbuf_t;

void ringbuf_init(ringbuf_t* rb){
	rb->head = 0;
	rb->tail = 0;
	rb->count = 0;
}

bool ringbufIsEmpty(ringbuf_t* rb){
	return (rb->count == 0);
}

bool ringbufIsFull(ringbuf_t* rb){
	return (rb->count == SIZE);
}

bool ringbufPush(ringbuf_t* rb, uint8_t* value){
	if (ringbufIsFull(rb)) return false;
	rb->buffer[rb->head] = *value;
	rb->head = (rb->head+1)%SIZE;
	rb->count++;
	return true;
}

bool ringbufPop(ringbuf_t* rb, uint8_t* value){
	if(ringbufIsEmpty(rb)) return false;
	*value = rb->buffer[rb->tail];
	rb->tail = (rb->tail + 1)%SIZE;
	rb->count--;
	return true;
}

int main(){
	uint8_t a = 1;
	uint8_t b = 2;
	uint8_t c = 3;
	uint8_t d = 0;
	ringbuf_t ringbuf;
	ringbuf_init(&ringbuf);
	ringbufPush(&ringbuf, &a);
	ringbufPush(&ringbuf, &b);
	ringbufPush(&ringbuf, &c);
	ringbufPop(&ringbuf, &d);
	printf("the value is %d\n",d);
	ringbufPop(&ringbuf, &d);
	printf("the value is %d\n",d);
	ringbufPop(&ringbuf, &d);
	printf("the value is %d\n",d);
	printf("bye\n");
	return 0;
}







