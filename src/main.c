#include <stdio.h>

#include "hashtable.h"


int main (int argc, char** argv) {
    
    struct hashtable* t = new_hashtable (1);
    
    hashtable_set (t, "hello", "world");
    hashtable_set (t, "Lorem", "Ipsum");
    
    printf ("hello -> %s\n", hashtable_get (t, "hello"));
    printf ("Lorem -> %s\n", hashtable_get (t, "Lorem"));

    hashtable_set (t, "Lorem", "stuff");
    
    printf ("this one stayed the same: hello -> %s\n", hashtable_get (t, "hello"));
    printf ("this one was overwritten: Lorem -> %s\n", hashtable_get (t, "Lorem"));

    hashtable_reset (t, "Lorem");
    
    printf ("this one should not exist: doesn't exist -> %i\n", hashtable_get (t, "doesn't exist"));
    printf ("this one was reset: Lorem -> %i\n", hashtable_get (t, "Lorem"));
    
    return 0;
}
