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

node *getNext_node(node n);

void setNext_node(node *source, node *other);

#endif //TABLE_NODE_H
