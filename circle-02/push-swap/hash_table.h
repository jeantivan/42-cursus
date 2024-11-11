#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <stdlib.h>
# include "utils.h"

# define TABLE_SIZE 2048

typedef struct Node {
    char *key;
    int value;
    struct Node *next;   
} Node;

typedef struct HashTable {
    Node **buckets;      
    int size;            
} HashTable;

#endif