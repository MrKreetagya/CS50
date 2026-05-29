#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

const unsigned int N = 10000;

node *table[N];

unsigned int word_count = 0;

unsigned int hash(const char *word)
{
    unsigned long hash_value = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash_value = (hash_value * 31) + tolower(word[i]);
    }
    return hash_value % N;
}

bool load(const char *dictionary)
{
    FILE *source_file = fopen(dictionary, "r");
    if (source_file == NULL)
    {
        return false;
    }

    char buffer_word[LENGTH + 1];

    while (fscanf(source_file, "%s", buffer_word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(source_file);
            return false;
        }

        strcpy(new_node->word, buffer_word);

        unsigned int bucket = hash(buffer_word);

        new_node->next = table[bucket];
        table[bucket] = new_node;

        word_count = word_count + 1;
    }

    fclose(source_file);
    return true;
}

unsigned int size(void)
{
    return word_count;
}

bool check(const char *word)
{
    unsigned int bucket = hash(word);

    node *cursor = table[bucket];

    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *temporary_holder = cursor;
            cursor = cursor->next;
            free(temporary_holder);
        }
    }
    return true;
}
