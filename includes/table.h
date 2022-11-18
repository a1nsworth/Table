//
// Created by Daniel on 16.11.2022.
//

#ifndef TABLE_TABLE_H
#define TABLE_TABLE_H

#include "list.h"

typedef list table;

int getIndexKey_table(table t, TKey key, int(*cmp)(TKey, TKey));

keyAndValue getKeyAndValueByKey_table(table t, TKey key, int(*cmp)(TKey, TKey));

bool containKey_table(table t, TKey key, int(*cmp)(TKey, TKey));

void add_table(table *t, keyAndValue kv, int(*cmp)(TKey, TKey));

void pop_table(table *t, TKey key, int(*cmp)(TKey, TKey));

table *input_table(size_t n, void (*inputTKey)(TKey *), void (*inputTValue)(TValue *), int(*cmp)(TKey, TKey));

table *createFromArray_table(keyAndValue *a, size_t n, int(*cmp)(TKey, TKey));

bool areEqual_table(table t1, table t2, int(*cmp)(keyAndValue, keyAndValue));

#endif //TABLE_TABLE_H
