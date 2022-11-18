//
// Created by Daniel on 16.11.2022.
//

#include "node.h"

keyAndValue getPair_node(node n) {
    return n.pair;
}

node *getLinkNext_node(node n) {
    return n.next;
}

void setNext_node(node *source, node *other) {
    source->next = other;
}

node getNext_node(node n) {
    return *n.next;
}

void setPair_node(node *source, keyAndValue pair) {
    setKeyAndValue_keyAndValue(&source->pair, pair);
}

node *allocateMemory_node() {
    return (node *) malloc(sizeof(node));
}

void free_node(node *n) {
    free(n);
}

node create_node(keyAndValue kv, node *nextNode) {
    return (node) {getKey_keyAndValue(kv), getValue_keyAndValue(kv), nextNode};
}
