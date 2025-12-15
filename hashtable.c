#include<stdio.h>
#include<stdbool.h>
//modified in internet
#define TABLESIZE 128

typedef enum{
	EMPTY,
	OCCUPIED,
	DELETED
}EntryState;

typedef struct{
	int key;
	int value;
	EntryState state;
}HashEntry;

typedef struct{
	HashEntry table[TABLESIZE];
}HashTable;

void init_hash(HashTable* ht){
	for(int i = 0; i < TABLESIZE; i++){
		ht->table[i].state = EMPTY;
	}
}

static int hash(int key){
	return key % TABLESIZE;
}

bool insert_hash(HashTable* ht, int key, int value){
	int idx = hash(key);
	for(int i = 0; i < TABLESIZE; i++){
		int probe = (idx + i) % TABLESIZE;
		if(ht->table[probe].state == EMPTY ||
				ht->table[probe].state == DELETED){
			ht->table[probe].key = key;
			ht->table[probe].value = value;
			ht->table[probe].state = OCCUPIED;
			return true;
		}
		if(ht->table[probe].state == OCCUPIED &&
				ht->table[probe].key == key){
			ht->table[probe].value = value;
			return false;
		}
	}
	return false;
}

bool lookup_hash(HashTable* ht, int key, int* value){
	int idx = hash(key);
	for(int i = 0; i < TABLESIZE; i++){
		int probe = (idx + i) % TABLESIZE;
		if(ht->table[probe].state == EMPTY){
			return false;
		}
		if(ht->table[probe].key == key && 
				ht->table[probe].state == OCCUPIED){
			*value = ht->table[probe].value;
			return true;
		}
	}
	return false;
}
bool delete_hash(HashTable* ht, int key){
	int idx = hash(key);
	for(int i = 0; i < TABLESIZE; i++){
		int probe = (idx + i) % TABLESIZE;
		if(ht->table[probe].state == EMPTY){
			return false;
		}
		if(ht->table[probe].key == key &&
				ht->table[probe].state == OCCUPIED){
			ht->table[probe].state = DELETED;
			return true;
		}
	}
	return false;
}
//aaa:
int main(){
	HashTable ht;
	init_hash(&ht);
	insert_hash(&ht,12,1234);
	insert_hash(&ht,23,2345);
	insert_hash(&ht,56,5678);
	int a = 0;
	if(lookup_hash(&ht,23,&a)){
		printf("%d\n",a);
	}
	delete_hash(&ht,23);
	if(!lookup_hash(&ht,23,&a)){
		printf("deleted\n");
	}
	return 0;



}

















