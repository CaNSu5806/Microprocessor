#ifndef ALU_H
#define ALU_H

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    bool CF; // Carry Flag
    bool ZF; // Zero Flag
    bool SF; // Sign Flag
    bool OF; // Overflow Flag
    bool PF; // Parity Flag
    bool AF; // Auxiliary Carry Flag
} Flags;

uint8_t alu_add_8bit(uint8_t a, uint8_t b, Flags *flags);
uint8_t alu_sub_8bit(uint8_t a, uint8_t b, Flags *flags);
void print_flags(const Flags *flags);
void print_binary(uint8_t value);

#endif
