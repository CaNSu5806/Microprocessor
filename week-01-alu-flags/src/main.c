#include "alu.h"
#include <stdio.h>

int main(void) {
    Flags flags = {0};

    printf("=========================================\n");
    printf("   x86 8-Bit ALU & Flag Simulator       \n");
    printf("=========================================\n\n");

    // TEST 1: Normal Toplama
    uint8_t a1 = 10, b1 = 20;
    uint8_t r1 = alu_add_8bit(a1, b1, &flags);
    printf("[TEST 1] Add: %d + %d\n", a1, b1);
    printf("Sonuc (Dec): %d | Hex: 0x%02X | Bin: ", r1, r1);
    print_binary(r1);
    printf("\n");
    print_flags(&flags);
    printf("\n");

    // TEST 2: Integer Overflow Zafiyet Senaryosu
    uint8_t a2 = 127, b2 = 1;
    uint8_t r2 = alu_add_8bit(a2, b2, &flags);
    printf("[TEST 2 - PoC] Integer Overflow: 127 + 1\n");
    printf("Hex: 0x%02X | Bin: ", r2);
    print_binary(r2);
    printf("\n");
    printf("Unsigned Yorumu : %u (Beklenen: 128)\n", (uint8_t)r2);
    printf("Signed Yorumu   : %d (Negatife dondu!)\n", (int8_t)r2);
    print_flags(&flags);

    if (flags.OF) {
        printf(">> UYARI: Signed Overflow (OF) tetiklendi!\n");
    }

    return 0;
}
