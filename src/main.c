#include <stdio.h>

#include "hashtable.h"


int main (int argc, char** argv) {
    
    struct hashtable* t = new_hashtable (4); // this 'constructor' takes the number of rows in the table
    
    hashtable_set (t, "hello", "world"); // set basic pairs of key -> value
    hashtable_set (t, "Lorem", "Ipsum");
    
    printf ("hello -> %s\n", hashtable_get (t, "hello"));
    printf ("Lorem -> %s\n", hashtable_get (t, "Lorem"));

    hashtable_set (t, "Lorem", "stuff"); // values will be overwritten without asking.
    
    printf ("this one stayed the same: hello -> %s\n", hashtable_get (t, "hello"));
    printf ("this one was overwritten: Lorem -> %s\n", hashtable_get (t, "Lorem"));

    hashtable_reset (t, "Lorem"); // this deletes the entry (this is different from just setting it to 0, as it will also free the corrseponding memory)
    
    printf ("this one should not exist: doesn't exist -> %i\n", hashtable_get (t, "doesn't exist")); // non-existing entires give a null pointer
    printf ("this one was reset: Lorem -> %i\n", hashtable_get (t, "Lorem")); // as do those that have been reset.
    
    return 0;
}
