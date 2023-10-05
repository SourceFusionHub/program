#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1000
#define HASH_FUNCTIONS 3

typedef struct BloomFilter {
    bool* array;
    int size;
} BloomFilter;

unsigned int hash1(char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 5) + *str++;
    }
    return hash;
}

unsigned int hash2(char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 7) + *str++;
    }
    return hash;
}

unsigned int hash3(char* str) {
    unsigned int hash = 0;
    while (*str) {
        hash = (hash << 11) + *str++;
    }
    return hash;
}

BloomFilter* createBloomFilter() {
    BloomFilter* filter = (BloomFilter*)malloc(sizeof(BloomFilter));
    filter->array = (bool*)calloc(SIZE, sizeof(bool));
    filter->size = SIZE;
    return filter;
}

void insert(BloomFilter* filter, char* str) {
    unsigned int index1 = hash1(str) % SIZE;
    unsigned int index2 = hash2(str) % SIZE;
    unsigned int index3 = hash3(str) % SIZE;

    filter->array[index1] = true;
    filter->array[index2] = true;
    filter->array[index3] = true;
}

bool lookup(BloomFilter* filter, char* str) {
    unsigned int index1 = hash1(str) % SIZE;
    unsigned int index2 = hash2(str) % SIZE;
    unsigned int index3 = hash3(str) % SIZE;

    return filter->array[index1] && filter->array[index2] && filter->array[index3];
}

void freeBloomFilter(BloomFilter* filter) {
    free(filter->array);
    free(filter);
}

int main() {
    BloomFilter* filter = createBloomFilter();

    insert(filter, "hello");
    insert(filter, "world");
    insert(filter, "openai");

    printf("Does 'hello' exist? %d\n", lookup(filter, "hello"));
    printf("Does 'world' exist? %d\n", lookup(filter, "world"));
    printf("Does 'openai' exist? %d\n", lookup(filter, "openai"));
    printf("Does 'ai' exist? %d\n", lookup(filter, "ai"));

    freeBloomFilter(filter);

    return 0;
}
