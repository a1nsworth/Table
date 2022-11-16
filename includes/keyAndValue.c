//
// Created by Daniel on 16.11.2022.
//

#include "keyAndValue.h"

TKey getKey_keyAndValue(keyAndValue source) {
    return source.key;
}

TValue getValue_keyAndValue(keyAndValue source) {
    return source.value;
}

void setKey_keyAndValue(keyAndValue *source, TKey key) {
    source->key = key;
}

void setValue_keyAndValue(keyAndValue *source, TValue value) {
    source->value = value;
}

void setKeyAndValue_keyAndValue(keyAndValue *source, keyAndValue other) {
    setKey_keyAndValue(source, getKey_keyAndValue(other));
    setValue_keyAndValue(source, getValue_keyAndValue(other));
}
