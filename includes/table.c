//
// Created by Daniel on 16.11.2022.
//

#include "table.h"

int getIndexKey_table(table t, TKey key, int (*cmp)(TKey, TKey)) {
    int left = -1;
    int right = (int) getSize_list(t);
    while (right - left > 1) {
        int middle = left + ((right - left) >> 1);

        cmp(getKey_keyAndValue(getPair_node(getNodeByIndex_list(t, middle))), key) >= 0 ?
        (right = middle) : (left = middle);
    }

    return right;
}

keyAndValue getKeyAndValueByKey_table(table t, TKey key, int (*cmp)(TKey, TKey)) {
    return getPair_node(getNodeByIndex_list(t, getIndexKey_table(t, key, cmp)));
}

bool containKey_table(table t, TKey key, int (*cmp)(TKey, TKey)) {
    return !empty_list(t) && cmp(key, getKey_keyAndValue(getKeyAndValueByKey_table(t, key, cmp))) == 0;
}

void add_table(table *t, keyAndValue kv, int (*cmp)(TKey, TKey)) {
    if (!empty_list(*t) && !containKey_table(*t, getKey_keyAndValue(kv), cmp)) {
        int indexForInsert = getIndexKey_table(*t, getKey_keyAndValue(kv), cmp);

        if (indexForInsert == 0) {
            pushFront_list(t, kv);
            setCurrent_list(t, getLinkBegin_list(*t));
        } else if (indexForInsert == getSize_list(*t)) {
            pushBack_list(t, kv);
        } else {
            node *lastNode = getLinkNodeByIndex_list(*t, indexForInsert);
            node *nextNode = getLinkNext_node(*lastNode);
            node *nodeForInsert = allocateMemory_node();
            setPair_node(nodeForInsert, kv);

            setNext_node(lastNode, nodeForInsert);
            setNext_node(nodeForInsert, nextNode);

            setSize_list(t, getSize_list(*t) + 1);
        }
    } else if (empty_list(*t)) {
        pushBack_list(t, kv);
    }
}

table *input_table(size_t n, void (*inputTKey)(TKey *), void (*inputTValue)(TValue *), int (*cmp)(TKey, TKey)) {
    table *t = (table *) malloc(sizeof(table));
    *t = createEmpty_list();

    TKey key;
    TValue value;
    for (register size_t i = 0; i < n; ++i) {
        inputTKey(&key);
        inputTValue(&value);

        add_table(t, create_keyAndValue(key, value), cmp);
    }

    return t;
}

table *createFromArray_table(keyAndValue *a, size_t n, int (*cmp)(TKey, TKey)) {
    table *t = (table *) malloc(sizeof(table));
    *t = createEmpty_list();

    for (register size_t i = 0; i < n; ++i) {
        add_table(t, a[i], cmp);
    }

    return t;
}

bool areEqual_table(table t1, table t2, int (*cmp)(keyAndValue, keyAndValue)) {
    if (getSize_list(t1) != getSize_list(t2))
        return false;

    while (getLinkCurrent_list(t1) != NULL) {
        if (cmp(getPair_node(getCurrent_list(t1)), getPair_node(getCurrent_list(t2))) != 0)
            return false;

        moveCurrentToNext_list(&t1);
        moveCurrentToNext_list(&t2);
    }

    return true;
}

void pop_table(table *t, TKey key, int (*cmp)(TKey, TKey)) {
    if (!empty_list(*t) && containKey_table(*t, key, cmp)) {
        pop_list(t, getIndexKey_table(*t, key, cmp));
    }
}
