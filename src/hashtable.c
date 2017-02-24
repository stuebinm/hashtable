#include "hashtable.h"

#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdio.h>

struct hashtable* new_hashtable (int size) {
    struct hashtable* ret = malloc (sizeof (struct hashtable));
    
    ret->size = size;
    ret->table = calloc (ret->size, sizeof (struct entry*));
    
}


int hash (char* key, int size) {
    unsigned long int ret = 0;
    
    int i = 0;
    int l = strlen (key);
    while (ret < ULONG_MAX && i<l) {
        ret = ret << 8;
        ret += key[i];
        i++;
    }
    return ret % size;
}


void* hashtable_set (struct hashtable* table, char* keyword, void* data) {
    int key = hash (keyword, table->size);
    
    
    struct entry* stack = table->table[key];
    if (stack) {
        while (strcmp (stack->key, keyword)) {
            if (stack->next == 0) {
                struct entry* new = malloc (sizeof (struct entry));
                new->key = keyword;
                new->data = data;
                new->next = 0;
                stack->next = new;
                return 0;
            }
            stack = stack->next;
        }
        void* old = stack->data;
        stack->data = data;
        return old;
    } else {
        struct entry* new = malloc (sizeof (struct entry));
        new->key = keyword;
        new->data = data;
        new->next = 0;
        table->table[key] = new;
        return 0;
    }
}

void* hashtable_reset (struct hashtable* table, char* keyword) {
    int key = hash (keyword, table->size);
    
    struct entry* stack = table->table[key];
    if (stack->next) {
        if (!strcmp (stack->key, keyword)) {
            table->table[key] = stack->next;
            void* ret = stack->data;
            free (stack);
            return ret;
        }
        while (1) {
            if (stack->next == 0) return 0;
            if (!strcmp (stack->next->key, keyword)) break;
            stack = stack->next;
        }
        struct entry* doomed = stack->next;
        stack->next = stack->next->next;
        void* ret = doomed->data;
        free (doomed);
        return ret;
        
    } else {
        void* ret = table->table [key]->data;
        table->table [key] = 0;
        return ret;
    }
}

void* hashtable_get (struct hashtable* table, char* keyword) {
    int key = hash (keyword, table->size);
    
    struct entry* ret = table->table [key];
    if (ret == 0) return ret;
    while (strcmp (ret->key, keyword)) {
        ret = ret->next;
        if (ret == 0) return ret;
    }
    
    return ret->data;
}
