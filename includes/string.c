//
// Created by Daniel on 16.11.2022.
//

#include "string.h"

bool empty_string(string s) {
    return s.size == 0;
}

size_t count_string(string s) {
    return s.size;
}

char *at_string(string s, size_t i) {
    return s.data + i;
}

string *allocateMemory_string(size_t n) {
    string *s = (string *) malloc(sizeof(string));
    s->data = (char *) malloc(n * sizeof(char));
    s->size = n;

    return s;
}

string *createStringFromArray_string(char *a, bool existZeroSymbol) {
    string *string = allocateMemory_string(strlen(a) + !existZeroSymbol);

    for (register size_t i = 0; i < string->size; ++i) {
        (*string).data[i] = *a;

        a++;
    }

    return string;
}
