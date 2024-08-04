/*
Question 2: Implement a Memory Pool
Description:

Implement a memory pool allocator in C. The allocator should manage a 
fixed-size memory block and allow allocations and deallocations of memory chunks within that block.
A memory pool is a block of memory pre-allocated for use by a 
program, and it provides an efficient way to allocate and deallocate 
memory quickly, avoiding the overhead of using malloc and free for small, frequent allocations.
Key Concepts:

Manual memory management.
Pointer manipulation.
Understanding of memory alignment.
*/
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    void *memory;
    size_t block_size;
    size_t total_blocks;
    unsigned char *free_list; // Keeps track of which blocks are free
} MemoryPool;

void initMemoryPool(MemoryPool *pool, size_t block_size, size_t total_blocks) {
    pool->memory = (void*)malloc(block_size*total_blocks);
    pool->block_size = block_size;
    pool->total_blocks = total_blocks;
    pool->free_list = (unsigned char*)calloc(total_blocks, sizeof(unsigned char));
}

void *allocateFromPool(MemoryPool *pool) {
    for (int i=0; i < pool->total_blocks; i++) {
        if (pool->free_list[i] == 0) {
            pool->free_list[i] = 1;
            return (char*)pool->memory + i*pool->block_size;
        }
    }
    return NULL;
}

void deallocateToPool(MemoryPool *pool, void *ptr) {
    int index = ((char*)ptr - (char*)pool->memory) / pool->block_size;
    pool->free_list[index] = 0;
}

void freeMemoryPool(MemoryPool *pool) {
    free(pool->memory);
    free(pool->free_list);
}

int main() {
    MemoryPool pool;
    initMemoryPool(&pool, sizeof(int), 10); // Create a pool with 10 blocks of sizeof(int)

    int *num1 = (int *)allocateFromPool(&pool);
    int *num2 = (int *)allocateFromPool(&pool);

    *num1 = 42;
    *num2 = 84;

    printf("num1: %d, num2: %d\n", *num1, *num2);

    deallocateToPool(&pool, num1);
    deallocateToPool(&pool, num2);

    freeMemoryPool(&pool);

    return 0;
}
