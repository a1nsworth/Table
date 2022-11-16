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
    s->size = 0;

    return s;
}

string *createStringFromArray(char *a) {
    string *string = allocateMemory_string(strlen(a));

    while (*a != '\0') {
        *string->data = *a;

        string->data++;
        a++;
    }

    return string;
}
