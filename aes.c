#include <stdio.h>
#include <stdint.h>

extern uint64_t clock_counter();
extern void aes_encrypt(uint8_t* block, uint8_t* key, uint8_t* result);

int main() {
    uint8_t result[16] = {0};
    uint8_t block[16] = "Two One Nine Two";
    uint8_t key[16] = "Thats my Kung Fu";
    
    uint64_t start = clock_counter();

    aes_encrypt(block, key, result);

    uint64_t end = clock_counter();

    for(int i = 0; i < 16; ++i) {
        if(i != 0) {
            printf(", ");
        }
        printf("0x%x", (uint8_t)result[i]);
    }
    printf("\n");
    printf("processed 128 bits in %lu cycles\n", end - start);
}