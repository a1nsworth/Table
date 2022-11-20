//
// Created by Daniel on 18.11.2022.
//

#include "task.h"

ProgrammingLanguage createEmpty_ProgrammingLanguage() {
    return (ProgrammingLanguage) {createEmpty_list(), createEmpty_list()};
}

void writeToTable_ProgrammingLanguage(table *source, char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        fprintf(stderr, "failed to open file");
        exit(5);
    }

    string **s = (string **) malloc(1000 * sizeof(string *));
    for (register size_t i = 0; !feof(file); ++i) {
        s[i] = allocateMemory_string(10);

        fscanf(file, "%s", s[i]->data);
        add_table(source, create_keyAndValue(*s[i], 0), compareTKeys);
    }

    free(s);
    fclose(file);
}

void writeVariables_ProgrammingLanguage(ProgrammingLanguage programmingLanguage, table *t, char *path) {
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        fprintf(stderr, "failed to open file");
        exit(5);
    }

    string **s = (string **) malloc(3000 * sizeof(string *));
    for (register size_t i = 0; !feof(file);) {
        s[i] = allocateMemory_string(60);

        char symbol;
        size_t j = 0;
        while (true) {
            symbol = fgetc(file);
            if (symbol != EOF && !isDigit(symbol) && symbol != ' ' && symbol != '\n' && symbol != ';' &&
                !containKey_table(programmingLanguage.separators,
                                  *createStringFromArray_string(
                                          (char[]) {symbol},
                                          false),
                                  compareTKeys)) {
                s[i]->data[j++] = symbol;
                s[i]->data[j] = '\0';
            } else {
                break;
            }
        }

        if (j != 0 && !containKey_table(programmingLanguage.reservedWords, *s[i], compareTKeys) &&
            !containKey_table(programmingLanguage.separators, *s[i], compareTKeys)) {
            if (containKey_table(*t, *s[i], compareTKeys)) {
                int indexForChange = getIndexKey_table(*t, *s[i], compareTKeys);
                node *n = getLinkNodeByIndex_list(*t, indexForChange);
                setPair_node(n, (keyAndValue) {getKey_keyAndValue(getPair_node((*n))),
                                               getValue_keyAndValue(getPair_node((*n))) + 1});
            } else {
                add_table(t, create_keyAndValue(*s[i], 1), compareTKeys);
            }
        }
        i++;
    }

    free(s);
    fclose(file);
}

