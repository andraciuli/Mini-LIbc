// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	void *ptr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }
	mem_list_add(ptr, size);

    return ptr;
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	size_t new_size = nmemb * size;

    void *ptr = mmap(NULL, new_size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (ptr == MAP_FAILED) {
        return NULL;
    }

    mem_list_add(ptr, size);

    memset(ptr, 0, size);

    return ptr;
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	struct mem_list *block = mem_list_find(ptr);

    if (block == NULL) {
        return MAP_FAILED;
    }

    if (munmap(block->start, block->len) == -1) {
        return MAP_FAILED;
    }

    mem_list_del(ptr);

    return (void *)0; 
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {
        return malloc(size);
    }
	void *new_ptr = malloc(size);

    if (new_ptr == NULL) {
        return NULL;
    }

	struct mem_list *block = mem_list_find(ptr);
	size_t old_size = block->len;
	size_t copy_size;
	if (size < old_size) {
    	copy_size = size;
	} else {
    	copy_size = old_size;
	}
    memcpy(new_ptr, ptr, copy_size);
    free(ptr);

    return new_ptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */	
	if (nmemb == 0 || size == 0) {
        free(ptr);
        return NULL;
    }
	
    size_t total_size;
    total_size = nmemb * size;

    void *new_ptr = realloc(ptr, total_size);

    return new_ptr;
}

