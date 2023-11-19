#include <stdio.h>
#include "src/common.h"
#include "src/debug.h"
#include "src/chunk.h"

int main() {
    printf("Hello, World!\n");
    Chunk chunk;
    initChunk(&chunk);
    writeChunk(&chunk, OP_RETURN, 1);
    int constant = addConstant(&chunk, 1.2);
    writeChunk(&chunk, OP_CONSTANT, 123);
    writeChunk(&chunk, constant, 123);

    writeChunk(&chunk, OP_RETURN, 123);
    disassembleChunk(&chunk, "Test Chunk");
    freeChunk(&chunk);


    return 0;
}
