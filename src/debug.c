#include "debug.h"
#include <stdio.h>

static int constantInstruction(const char *name, Chunk *chunk, int offset);

#define SIMPLE_INSTRUCTION(type)            \
    case type:                              \
        printf("%s\n",#type);               \
        return offset + 1;

#define CONSTANT_INSTRUCTION()                              \
case OP_CONSTANT:                                           \
return constantInstruction("OP_CONSTANT", chunk, offset);


void disassembleChunk(Chunk *chunk, const char *name) {
    printf("== %s ==\n", name);

    for (int offset = 0; offset < chunk->count;) {
        offset = disassembleInstruction(chunk, offset);
    }
}

int disassembleInstruction(Chunk *chunk, int offset) {
    printf("%04d ", offset);

    if (offset > 0 && chunk->lines[offset] == chunk->lines[offset - 1])
        printf("   | ");
    else
        printf("%4d ", chunk->lines[offset]);

    uint8_t instruction = chunk->code[offset];
    switch (instruction) {
        SIMPLE_INSTRUCTION(OP_RETURN)
        CONSTANT_INSTRUCTION()
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

static int constantInstruction(const char *name, Chunk *chunk, int offset) {
    uint8_t constant = chunk->code[offset + 1];
    printf("%-16s %4d '", name, constant);
    printValue(chunk->constants.values[constant]);
    printf("'\n");
    return offset + 2;
}
