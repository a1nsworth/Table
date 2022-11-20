//
// Created by Daniel on 16.11.2022.
//

#ifndef TABLE_STRING_H
#define TABLE_STRING_H

#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>

typedef struct string {
    char *data;
    size_t size;
} string;

bool empty_string(string s);

size_t count_string(string s);

char *at_string(string s, size_t i);

string *allocateMemory_string(size_t n);

string *createStringFromArray_string(char *a, bool existZeroSymbol);

#endif //TABLE_STRING_H
