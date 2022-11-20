//
// Created by Daniel on 16.11.2022.
//

#ifndef TABLE_TABLE_H
#define TABLE_TABLE_H

#include "list.h"

typedef list table;

bool isDigit(char c);

int compareTKeys(TKey key1, TKey key2);

/// Поиск по ключу
/// \param t таблица
/// \param key ключ для поиска
/// \param cmp компаратор
/// \return возращает индекс найденного ключа или минимальную верхнюю границу
int getIndexKey_table(table t, TKey key, int(*cmp)(TKey, TKey));

/// Поиск по ключу
/// \param t таблица
/// \param key ключ для поиска
/// \param cmp компаратор
/// \return возращает ключ и значение найденного ключа или минимальный верхний ключ и значение
keyAndValue getKeyAndValueByKey_table(table t, TKey key, int(*cmp)(TKey, TKey));

/// Поиск ключа
/// \param t таблица
/// \param key ключ для поиска
/// \param cmp компаратор
/// \return возращает true, если ключ найден, иначе false.
bool containKey_table(table t, TKey key, int(*cmp)(TKey, TKey));

/// Добавление в таблицу
/// \param t таблица
/// \param kv элемент
/// \param cmp компаратор
void add_table(table *t, keyAndValue kv, int(*cmp)(TKey, TKey));

/// Удаление из таблицы по ключу
/// \param t таблица
/// \param key ключ
/// \param cmp компаратор
void pop_table(table *t, TKey key, int(*cmp)(TKey, TKey));

table *input_table(size_t n, void (*inputTKey)(TKey *), void (*inputTValue)(TValue *), int(*cmp)(TKey, TKey));

table *createFromArray_table(keyAndValue *a, size_t n, int(*cmp)(TKey, TKey));

bool areEqual_table(table t1, table t2, int(*cmp)(keyAndValue, keyAndValue));

/// Изменение значения по ключу
/// \param t таблиа
/// \param key ключ
/// \param value значение
/// \param cmp компаратор
void setValueByKey_table(table *t, TKey key, TValue value, int(*cmp)(TKey, TKey));

#endif //TABLE_TABLE_H
