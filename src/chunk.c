#include "chunk.h"
#include <stdlib.h>
#include "value.h"

void initChunk(Chunk *chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
    chunk->lines = NULL;
    initValueArray(&chunk->constants);
}

void writeChunk(Chunk *chunk, uint8_t byte, int line) {
    if (chunk->capacity == chunk->count) {
        int newSize = chunk->capacity < 8 ? 8 : chunk->capacity * 2;
        chunk->code = realloc(chunk->code, newSize * sizeof(chunk->code));
        chunk->lines = realloc(chunk->lines, newSize * sizeof(chunk->lines));
        if (chunk->code == NULL || chunk->lines == NULL)
            exit(1);
    }
    chunk->lines[chunk->count] = line;
    chunk->code[chunk->count++] = byte;
}

void freeChunk(Chunk *chunk) {
    freeValueArray(&chunk->constants);
    free(chunk->code);
    free(chunk->lines);
    free(chunk);
}

int addConstant(Chunk *chunk, Value value) {
    writeValueArray(&chunk->constants, value);
    return chunk->constants.count - 1;
}