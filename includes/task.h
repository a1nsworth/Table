//
// Created by Daniel on 18.11.2022.
//

#ifndef TABLE_TASK_H
#define TABLE_TASK_H

#include "table.h"

typedef struct ProgrammingLanguage {
    table separators;
    table reservedWords;
} ProgrammingLanguage;

ProgrammingLanguage createEmpty_ProgrammingLanguage();

void writeToTable_ProgrammingLanguage(table *source, char *path);

void writeVariables_ProgrammingLanguage(ProgrammingLanguage programmingLanguage, table *t, char *path);

#endif //TABLE_TASK_H
