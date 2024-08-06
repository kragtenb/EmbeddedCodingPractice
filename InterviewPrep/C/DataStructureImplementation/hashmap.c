/*
Task 5: Implement a Hash Map in C
Instructions:

Implement a basic hash map (hash table) in C with integer keys and values.
Implement the following operations:
insert(int key, int value): Insert a key-value pair into the hash map.
get(int key): Retrieve the value associated with a given key.
remove(int key): Remove a key-value pair from the hash map.
contains(int key): Check if a key exists in the hash map.
Use a simple hash function to map keys to indices in an array.
Handle collisions using chaining (linked lists).
Implement a function to print all key-value pairs in the hash map.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Entity
{
    int key;
    int value;
    struct Entity* next;
} Entity;


typedef struct Hashmap
{
    int size;
    int count;
    struct Entity* map;
} Hashmap;


Hashmap* initHashmap(int size) {
    Hashmap* hm = (Hashmap*) malloc(sizeof(Hashmap));
    hm->size = size;
    hm->count = 0;
    hm->map = (Entity*) malloc(size * sizeof(Entity));
    return hm;
}

int hash(Hashmap* hm, int key) {
    return key % hm->size;
}

void insert(Hashmap* hm, int key, int value) {
    int hashVal = hash(hm, key);
    Entity entity = hm->map[hashVal];
    if ()
}

int main() {
    return 0;
}