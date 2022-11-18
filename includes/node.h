//
// Created by Daniel on 16.11.2022.
//

#ifndef TABLE_NODE_H
#define TABLE_NODE_H

#include "keyAndValue.h"

typedef struct node {
    keyAndValue pair;
    struct node *next;
} node;

keyAndValue getPair_node(node n);

void setPair_node(node *source, keyAndValue pair);

node *getLinkNext_node(node n);

node getNext_node(node n);

void setNext_node(node *source, node *other);

node *allocateMemory_node();

void free_node(node *n);

node create_node(keyAndValue kv, node *nextNode);

#endif //TABLE_NODE_H
