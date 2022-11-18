//
// Created by Daniel on 18.11.2022.
//

#include <assert.h>

#include "table.h"

int cmp(TKey key1, TKey key2) {
    return strcmp(key1.data, key2.data);
}

void test_add_oneElement() {
    // Arrange
    keyAndValue expected = create_keyAndValue((string) {(char[]) {"hello"}, 1}, 6);
    table actual = createEmpty_list();

    // Act
    add_table(&actual, expected, cmp);

    // Assert
    assert(getSize_list(actual) == 1);
    assert(cmp(getKey_keyAndValue(getPair_node(getCurrent_list(actual))), getKey_keyAndValue(expected)) == 0);
}

void test_add_twoElements() {
    // Arrange
    keyAndValue expected1 = create_keyAndValue((string) {(char[]) {"b"}, 1}, 6);
    keyAndValue expected2 = create_keyAndValue((string) {(char[]) {"a"}, 1}, 6);
    table actual = createEmpty_list();

    // Act
    add_table(&actual, expected1, cmp);
    add_table(&actual, expected2, cmp);

    // Assert
    assert(getSize_list(actual) == 2);
    assert(cmp(getKey_keyAndValue(getPair_node(getCurrent_list(actual))), getKey_keyAndValue(expected2)) == 0);

    moveCurrentToNext_list(&actual);
    assert(cmp(getKey_keyAndValue(getPair_node(getCurrent_list(actual))), getKey_keyAndValue(expected1)) == 0);
}

void test_add_addEqualElements() {
    // Arrange
    keyAndValue expected1 = create_keyAndValue((string) {(char[]) {"a"}, 1}, 6);
    keyAndValue expected2 = create_keyAndValue((string) {(char[]) {"b"}, 1}, 6);
    keyAndValue expected3 = create_keyAndValue((string) {(char[]) {"c"}, 1}, 6);
    keyAndValue expected4 = create_keyAndValue((string) {(char[]) {"d"}, 1}, 6);
    table *actual = createFromArray_table((keyAndValue[]) {
            create_keyAndValue((string) {(char[]) {"d"}, 1}, 6),
            create_keyAndValue((string) {(char[]) {"c"}, 1}, 6),
            create_keyAndValue((string) {(char[]) {"b"}, 1}, 6),
            create_keyAndValue((string) {(char[]) {"a"}, 1}, 6)}, 4, cmp);

    // Act
    add_table(actual, expected1, cmp);
    add_table(actual, expected2, cmp);
    add_table(actual, expected3, cmp);
    add_table(actual, expected4, cmp);

    // Assert
    assert(getSize_list(*actual) == 4);
    assert(cmp(getKey_keyAndValue(getPair_node(getCurrent_list(*actual))), getKey_keyAndValue(expected1)) == 0);

    moveCurrentToNext_list(actual);
    assert(cmp(getKey_keyAndValue(getPair_node(getCurrent_list(*actual))), getKey_keyAndValue(expected2)) == 0);

    moveCurrentToNext_list(actual);
    assert(cmp(getKey_keyAndValue(getPair_node(getCurrent_list(*actual))), getKey_keyAndValue(expected3)) == 0);

    moveCurrentToNext_list(actual);
    assert(cmp(getKey_keyAndValue(getPair_node(getCurrent_list(*actual))), getKey_keyAndValue(expected4)) == 0);
}

void test_add() {
    test_add_oneElement();
    test_add_twoElements();
    test_add_addEqualElements();
}

void test_pop_oneElement() {
    // Arrange
    keyAndValue expected = create_keyAndValue((string) {(char[]) {"hello"}, 1}, 6);
    table actual = createEmpty_list();
    add_table(&actual, expected, cmp);

    // Act
    pop_table(&actual, getKey_keyAndValue(expected), cmp);

    // Assert
    assert(getSize_list(actual) == 0);
    assert(getLinkBegin_list(actual) == NULL);
    assert(getLinkEnd_list(actual) == NULL);
    assert(getLinkCurrent_list(actual) == NULL);
}

void test_pop_twoElements() {
    // Arrange
    keyAndValue expected1 = create_keyAndValue((string) {(char[]) {"b"}, 1}, 6);
    keyAndValue expected2 = create_keyAndValue((string) {(char[]) {"a"}, 1}, 6);
    table actual = createEmpty_list();
    add_table(&actual, expected1, cmp);
    add_table(&actual, expected2, cmp);

    // Act
    pop_table(&actual, getKey_keyAndValue(expected1), cmp);
    pop_table(&actual, getKey_keyAndValue(expected2), cmp);

    // Assert
    assert(getSize_list(actual) == 0);
    assert(getLinkBegin_list(actual) == NULL);
    assert(getLinkEnd_list(actual) == NULL);
    assert(getLinkCurrent_list(actual) == NULL);
}

void test_pop_allElements() {
    // Arrange
    keyAndValue expected1 = create_keyAndValue((string) {(char[]) {"a"}, 1}, 6);
    keyAndValue expected2 = create_keyAndValue((string) {(char[]) {"b"}, 1}, 6);
    keyAndValue expected3 = create_keyAndValue((string) {(char[]) {"c"}, 1}, 6);
    keyAndValue expected4 = create_keyAndValue((string) {(char[]) {"d"}, 1}, 6);
    table *actual = createFromArray_table((keyAndValue[]) {
            create_keyAndValue((string) {(char[]) {"d"}, 1}, 6),
            create_keyAndValue((string) {(char[]) {"c"}, 1}, 6),
            create_keyAndValue((string) {(char[]) {"b"}, 1}, 6),
            create_keyAndValue((string) {(char[]) {"a"}, 1}, 6)}, 4, cmp);

    // Act
    pop_table(actual, getKey_keyAndValue(expected1), cmp);
    pop_table(actual, getKey_keyAndValue(expected4), cmp);
    pop_table(actual, getKey_keyAndValue(expected3), cmp);
    pop_table(actual, getKey_keyAndValue(expected2), cmp);

    // Assert
    assert(getSize_list(*actual) == 0);
    assert(getLinkBegin_list(*actual) == NULL);
    assert(getLinkEnd_list(*actual) == NULL);
    assert(getLinkCurrent_list(*actual) == NULL);
}

void test_pop() {
    test_pop_oneElement();
    test_pop_twoElements();
    test_pop_allElements();
}

void test_table() {
    test_add();
    test_pop();
}