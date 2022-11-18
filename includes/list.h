//
// Created by Daniel on 16.11.2022.
//

#ifndef TABLE_LIST_H
#define TABLE_LIST_H

#include "node.h"

typedef struct list {
    node *begin;
    node *end;
    node *current;
    size_t size;
} list;

size_t getSize_list(list l);

void setSize_list(list *l, size_t newSize);

bool empty_list(list l);

node getBegin_list(list l);

node getEnd_list(list l);

node getCurrent_list(list l);

node *getLinkBegin_list(list l);

node *getLinkEnd_list(list l);

node *getLinkCurrent_list(list l);

void setBegin_list(list *l, node *newBegin);

void setEnd_list(list *l, node *newEnd);

void setCurrent_list(list *l, node *newCurrent);

list createEmpty_list();

void moveCurrentToNext_list(list *l);

node *getLinkNodeByIndex_list(list l, size_t i);

node getNodeByIndex_list(list l, size_t i);

void pushFront_list(list *l, keyAndValue kv);

void pushBack_list(list *l, keyAndValue kv);

void insert_list(list *l, keyAndValue kv, size_t index);

void popFront_list(list *l);

void popBack_list(list *l);

void pop_list(list *l, size_t index);

void free_list(list *l);

void output_list(list l, void(*outputFunc)(keyAndValue kv));

list *createFromArray_list(keyAndValue *a, size_t n);

#endif //TABLE_LIST_H
