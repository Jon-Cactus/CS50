// Implements a dictionary's functionality
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node* table[N];

unsigned int SIZE;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int hashkey = hash(word);
    node* cursor = table[hashkey];
    if (!cursor)
    {
        return false;
    }

    while (cursor)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE* source = fopen(dictionary, "r");
    if (!source)
    {
        return false;
    }

    char* word = malloc(LENGTH + 1);
    // read each word
    while (fscanf(source, "%s", word) != EOF)
    {
        // allocate memory for a new node
        node* n = malloc(sizeof(node));
        if (!n)
        {
            return false;
        }

        n->next = NULL;

        // add the word to the node
        strcpy(n->word, word);

        // hash the word to index it
        int hashkey = hash(word);

        // insert the node into the hash table
        if (table[hashkey] == NULL)
        {
            table[hashkey] = n;
        }
        else
        {
            n->next = table[hashkey];
            table[hashkey] = n;
        }

        SIZE++;
    }

    free(word);
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return SIZE;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int bucket = 0; bucket < N; bucket++)
    {
        node* ptr = table[bucket];
        while (ptr)
        {
            node* tmp = ptr;
            ptr = ptr->next;
            free(tmp);
        }
    }
    return true;
}