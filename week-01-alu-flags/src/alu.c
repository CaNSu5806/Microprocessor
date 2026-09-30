#include "alu.h"
#include <stdio.h>

uint8_t alu_add_8bit(uint8_t a, uint8_t b, Flags *flags) {
    uint16_t res_full = (uint16_t)a + (uint16_t)b;
    uint8_t res = (uint8_t)(res_full & 0xFF);

    flags->ZF = (res == 0);
    flags->SF = (res & 0x80) != 0;
    flags->CF = (res_full > 0xFF);
    flags->OF = (!((a ^ b) & 0x80) && ((a ^ res) & 0x80));

    int ones = 0;
    for (int i = 0; i < 8; i++) {
        if ((res >> i) & 1) ones++;
    }
    flags->PF = (ones % 2 == 0);
    flags->AF = (((a & 0x0F) + (b & 0x0F)) > 0x0F);

    return res;
}

uint8_t alu_sub_8bit(uint8_t a, uint8_t b, Flags *flags) {
    uint16_t res_full = (uint16_t)a - (uint16_t)b;
    uint8_t res = (uint8_t)(res_full & 0xFF);

    flags->ZF = (res == 0);
    flags->SF = (res & 0x80) != 0;
    flags->CF = (a < b);
    flags->OF = (((a ^ b) & 0x80) && ((a ^ res) & 0x80));

    int ones = 0;
    for (int i = 0; i < 8; i++) {
        if ((res >> i) & 1) ones++;
    }
    flags->PF = (ones % 2 == 0);
    flags->AF = ((a & 0x0F) < (b & 0x0F));

    return res;
}

void print_binary(uint8_t value) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (value >> i) & 1);
        if (i == 4) printf(" ");
    }
}

void print_flags(const Flags *flags) {
    printf("[FLAGS] ZF=%d | SF=%d | CF=%d | OF=%d | PF=%d | AF=%d\n",
           flags->ZF, flags->SF, flags->CF, flags->OF, flags->PF, flags->AF);
}
