//
// Created by Daniel on 16.11.2022.
//

#include "list.h"

size_t getSize_list(list l) {
    return l.size;
}

void setSize_list(list *l, size_t newSize) {
    l->size = newSize;
}

bool empty_list(list l) {
    return getSize_list(l) == 0;
}

node getBegin_list(list l) {
    return *l.begin;
}

node getEnd_list(list l) {
    return *l.end;
}

node getCurrent_list(list l) {
    return *l.current;
}

node *getLinkBegin_list(list l) {
    return l.begin;
}

node *getLinkEnd_list(list l) {
    return l.end;
}

node *getLinkCurrent_list(list l) {
    return l.current;
}

void setBegin_list(list *l, node *newBegin) {
    l->begin = newBegin;
}

void setEnd_list(list *l, node *newEnd) {
    l->end = newEnd;
}

void setCurrent_list(list *l, node *newCurrent) {
    l->current = newCurrent;
}

list createEmpty_list() {
    return (list) {NULL, NULL, NULL, 0};
}

void moveCurrentToNext_list(list *l) {
    setCurrent_list(l, l->current->next);
}

node *getLinkNodeByIndex_list(list l, size_t i) {
    if (getSize_list(l) <= i) {
        fprintf(stderr, "bad index, out of list range");
        exit(1);
    }

    while (i-- > 0) {
        moveCurrentToNext_list(&l);
    }

    return getLinkCurrent_list(l);
}

node getNodeByIndex_list(list l, size_t i) {
    return *getLinkNodeByIndex_list(l, i);
}

void pushFront_list(list *l, keyAndValue kv) {
    node *nodeForPush = allocateMemory_node();
    setPair_node(nodeForPush, kv);
    setNext_node(nodeForPush, NULL);

    if (empty_list(*l)) {
        setBegin_list(l, nodeForPush);
        setEnd_list(l, nodeForPush);
    } else {
        setNext_node(nodeForPush, getLinkBegin_list(*l));
        setEnd_list(l, getLinkBegin_list(*l));
        setBegin_list(l, nodeForPush);
    }

    setCurrent_list(l, nodeForPush);
    setSize_list(l, getSize_list(*l) + 1);
}

void pushBack_list(list *l, keyAndValue kv) {
    node *nodeForPush = allocateMemory_node();
    setPair_node(nodeForPush, kv);
    setNext_node(nodeForPush, NULL);

    if (empty_list(*l)) {
        setBegin_list(l, nodeForPush);
        setEnd_list(l, nodeForPush);

        setCurrent_list(l, nodeForPush);
    } else {
        setNext_node(getLinkEnd_list(*l), nodeForPush);
        setEnd_list(l, nodeForPush);
    }

    setSize_list(l, getSize_list(*l) + 1);
}

void insert_list(list *l, keyAndValue kv, size_t index) {
    if (index >= getSize_list(*l)) {
        fprintf(stderr, "index out of range");
        exit(1);
    }

    if (index == 0) {
        pushFront_list(l, kv);
    } else if (index == getSize_list(*l) - 1) {
        pushBack_list(l, kv);
    } else {
        node *nodeForPush = allocateMemory_node();
        setPair_node(nodeForPush, kv);

        node *last = getLinkNodeByIndex_list(*l, index - 1);
        node *next = getLinkNext_node(*last);

        setNext_node(nodeForPush, next);
        setNext_node(last, nodeForPush);

        setSize_list(l, getSize_list(*l) + 1);
    }
}

void free_list(list *l) {
    for (register int i = getSize_list(*l) - 1; i >= 0; --i) {
        free_node(getLinkNodeByIndex_list(*l, i));
    }

    setSize_list(l, 0);
}

void output_list(list l, void (*outputFunc)(keyAndValue)) {
    while (getLinkCurrent_list(l) != NULL) {
        outputFunc(getPair_node(getCurrent_list(l)));
        moveCurrentToNext_list(&l);
    }
}

list *createFromArray_list(keyAndValue *a, size_t n) {
    list *l = (list *) malloc(sizeof(list));
    *l = createEmpty_list();

    for (register size_t i = 0; i < n; i++) {
        pushBack_list(l, a[i]);
    }

    return l;
}
