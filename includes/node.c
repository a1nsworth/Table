//
// Created by Daniel on 16.11.2022.
//

#include "node.h"

keyAndValue getPair_node(node n) {
    return n.pair;
}

node *getNext_node(node n) {
    return n.next;
}

void setNext_node(node *source, node *other) {
    source->next = other;
}
