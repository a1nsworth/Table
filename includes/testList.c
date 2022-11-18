//
// Created by Daniel on 18.11.2022.
//

#include "list.h"

#include <assert.h>

void test_pushBack_emptyList() {
    // Arrange
    list actual = createEmpty_list();
    node *expected = allocateMemory_node();
    setPair_node(expected, create_keyAndValue((string) {(char[]) {"hello world"}}, 12));
    setNext_node(expected, NULL);

    // Act
    pushBack_list(&actual, getPair_node(*expected));

    // Asserts
    assert(strcmp(getKey_keyAndValue(getPair_node(getCurrent_list(actual))).data, getPair_node((*expected)).key.data) ==
           0);
    assert(getValue_keyAndValue(getPair_node(getCurrent_list(actual))) ==
           getValue_keyAndValue(getPair_node((*expected))));
    assert(getLinkNext_node(getBegin_list(actual)) == NULL);
    assert(getSize_list(actual) == 1);
}

void test_pushBack_addTwoElements() {
    // Arrange
    list actual = createEmpty_list();
    node *expected1 = allocateMemory_node();
    node *expected2 = allocateMemory_node();
    setPair_node(expected1, create_keyAndValue((string) {(char[]) {"hello world"}}, 12));
    setNext_node(expected1, expected2);
    setPair_node(expected2, create_keyAndValue((string) {(char[]) {"42"}}, 2));
    setNext_node(expected2, NULL);
    // Act
    pushBack_list(&actual, getPair_node(*expected1));
    pushBack_list(&actual, getPair_node(*expected2));

    // Asserts
    assert(strcmp(getKey_keyAndValue(getPair_node(getCurrent_list(actual))).data,
                  getPair_node((*expected1)).key.data) ==
           0);
    assert(getValue_keyAndValue(getPair_node(getCurrent_list(actual))) ==
           getValue_keyAndValue(getPair_node((*expected1))));

    moveCurrentToNext_list(&actual);

    assert(strcmp(getKey_keyAndValue(getPair_node(getCurrent_list(actual))).data,
                  getPair_node((*expected2)).key.data) ==
           0);
    assert(getValue_keyAndValue(getPair_node(getCurrent_list(actual))) ==
           getValue_keyAndValue(getPair_node((*expected2))));
    assert(getLinkNext_node(*getLinkNext_node(getBegin_list(actual))) == NULL);
    assert(getSize_list(actual) == 2);
}

void test_pushBack() {
    test_pushBack_emptyList();
    test_pushBack_addTwoElements();
}

void test_pushFront_emptyList() {
    // Arrange
    list actual = createEmpty_list();
    node *expected = allocateMemory_node();
    setPair_node(expected, create_keyAndValue((string) {(char[]) {"hello world"}}, 12));
    setNext_node(expected, NULL);

    // Act
    pushFront_list(&actual, getPair_node(*expected));

    // Asserts
    assert(strcmp(getKey_keyAndValue(getPair_node(getCurrent_list(actual))).data, getPair_node((*expected)).key.data) ==
           0);
    assert(getValue_keyAndValue(getPair_node(getCurrent_list(actual))) ==
           getValue_keyAndValue(getPair_node((*expected))));
    assert(getLinkNext_node(getBegin_list(actual)) == NULL);
    assert(getSize_list(actual) == 1);
}

void test_pushFront_addTwoElements() {
    // Arrange
    list actual = createEmpty_list();
    node *expected1 = allocateMemory_node();
    node *expected2 = allocateMemory_node();
    setPair_node(expected1, create_keyAndValue((string) {(char[]) {"hello world"}}, 12));
    setNext_node(expected1, expected2);
    setPair_node(expected2, create_keyAndValue((string) {(char[]) {"42"}}, 2));
    setNext_node(expected2, NULL);
    // Act
    pushFront_list(&actual, getPair_node(*expected1));
    pushFront_list(&actual, getPair_node(*expected2));

    // Asserts
    assert(strcmp(getKey_keyAndValue(getPair_node(getCurrent_list(actual))).data,
                  getPair_node((*expected1)).key.data) ==
           0);
    assert(getValue_keyAndValue(getPair_node(getCurrent_list(actual))) ==
           getValue_keyAndValue(getPair_node((*expected1))));

    moveCurrentToNext_list(&actual);

    assert(strcmp(getKey_keyAndValue(getPair_node(getCurrent_list(actual))).data,
                  getPair_node((*expected2)).key.data) ==
           0);
    assert(getValue_keyAndValue(getPair_node(getCurrent_list(actual))) ==
           getValue_keyAndValue(getPair_node((*expected2))));
    assert(getLinkNext_node(*getLinkNext_node(getBegin_list(actual))) == NULL);
    assert(getSize_list(actual) == 2);
}

void test_pushFront() {
    test_pushFront_emptyList();
    test_pushFront_addTwoElements();
}

void test_insert_middle() {
    // Arrange

    // Act
    // Asserts
}
void test_insert() {

}

void test_list() {
    test_pushBack();
    test_pushFront();
    test_insert();
}