
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MEMORY_SIZE 1024*1024 // 1 MB
static char memory_pool[MEMORY_SIZE];

typedef struct BlockHeader
{
    size_t size; // Size of the block
    struct BlockHeader* next; // Next block
} BlockHeader;

static BlockHeader* free_list = NULL;

void initialize_memory_pool() {
    free_list = (BlockHeader*) memory_pool;
    free_list->size = MEMORY_SIZE - sizeof(BlockHeader);
    free_list->next = NULL;
}

void* my_malloc(size_t size) {
    size = (size+7) & ~7;

    BlockHeader* current = free_list;
    BlockHeader* previous = NULL;

    while (current != NULL) {
        if  (current->size >= size) {
            if (current->size > size + sizeof(BlockHeader)) {
                BlockHeader* new_block = (BlockHeader*) ((char*)current + sizeof(BlockHeader) + size);
                new_block->size = current->size - sizeof(BlockHeader) - size;
                new_block->next = current->next;
                current->size = size;
                current->next = new_block;
            }
            if (previous) {
                previous->next = current->next;
            } else {
                free_list = current->next;
            }
            return (char*)current + sizeof(BlockHeader);
        }
        previous = current;
        current = current->next;
    }
    return NULL;
}

void my_free(void* ptr) {
    if (ptr == NULL) return;
    BlockHeader* blockHeader = (BlockHeader*)((char*)ptr - sizeof(BlockHeader));
    blockHeader->next = free_list;
    free_list = blockHeader;
}

void* my_realloc(void* ptr, size_t size) {
    if (ptr==NULL) {
        return my_malloc(size);
    }
    if (size == 0) {
        my_free(ptr);
        return NULL;
    }

    BlockHeader* block = (BlockHeader*)((char*)ptr - sizeof(BlockHeader));
    if (block->size >= size) {
        return ptr;
    }
    void* new_ptr = my_malloc(size);
    if (new_ptr != NULL) {
        memcpy(new_ptr, ptr, block->size);
        my_free(ptr);
    }
    return new_ptr;
}

int main() {
    initialize_memory_pool();

    void* ptr1 = my_malloc(100);
    void* ptr2 = my_malloc(200);

    my_free(ptr1);

    ptr2 = my_realloc(ptr2, 300);

    // Additional testing of allocator

    return 0;
}
