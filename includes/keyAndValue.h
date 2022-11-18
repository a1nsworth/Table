//
// Created by Daniel on 16.11.2022.
//

#ifndef TABLE_KEYANDVALUE_H
#define TABLE_KEYANDVALUE_H

#include "string.h"

typedef string TKey;
typedef int TValue;

typedef struct keyAndValue {
    TKey key;
    TValue value;
} keyAndValue;

TKey getKey_keyAndValue(keyAndValue source);

TValue getValue_keyAndValue(keyAndValue source);

void setKey_keyAndValue(keyAndValue *source, TKey key);

void setValue_keyAndValue(keyAndValue *source, TValue value);

void setKeyAndValue_keyAndValue(keyAndValue *source, keyAndValue other);

keyAndValue create_keyAndValue(TKey key, TValue value);

#endif //TABLE_KEYANDVALUE_H
