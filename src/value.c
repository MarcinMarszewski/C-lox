#include "value.h"
#include <stdlib.h>
#include <stdio.h>

void initValueArray(ValueArray *array) {
    array->capacity = 0;
    array->count = 0;
    array->values = NULL;
}

void writeValueArray(ValueArray *array, Value value) {
    if (array->capacity == array->count) {
        int newSize = array->capacity < 8 ? 8 : array->capacity * 2;
        array->values = realloc(array->values, newSize * sizeof(array->values));
        if (array->values == NULL)
            exit(1);
    }
    array->values[array->count++] = value;
}

void freeValueArray(ValueArray *array) {
    free(array->values);
    free(array);
}

void printValue(Value value) {
    printf("%g", value);
}