#ifndef HASHTABLE_H
#define HASHTABLE_H

struct entry {
    char* key;
    void* data;
    struct entry* next;
};

struct hashtable {
    int size;
    struct entry** table;
};

struct hashtable* new_hashtable (int size);

void* hashtable_set (struct hashtable* table, char* keyword, void* data);
void* hashtable_reset (struct hashtable* table, char* key);

void* hashtable_get (struct hashtable* table, char* key);


#endif
