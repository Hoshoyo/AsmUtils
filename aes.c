#include <stdio.h>
#include <stdint.h>

extern uint64_t clock_counter();
extern void aes_encrypt(uint8_t* block, uint8_t key[16], uint8_t* result, int block_count);
extern void aes_decrypt(uint8_t* block, uint8_t key[16], uint8_t* result, int block_count);

#define BLOCK_SIZE 32
int main() {
    uint8_t key[16] = "Thats my Kung Fu";

    uint8_t result_enc[BLOCK_SIZE] = {0};
    uint8_t result_dec[BLOCK_SIZE] = {0};
    uint8_t block[BLOCK_SIZE] = "Two One Nine Two" "Two One Nine Two";
    
    uint64_t start = clock_counter();

    aes_encrypt(block, key, result_enc, 2);
    aes_decrypt(result_enc, key, result_dec, 2);

    uint64_t end = clock_counter();

    for(int i = 0; i < BLOCK_SIZE; ++i) {
        #if 0
        if(i != 0) {
            printf(", ");
        }
        printf("0x%x", (uint8_t)result_dec[i]);
        #else
        printf("%c", (uint8_t)result_dec[i]);
        #endif
    }

    printf("\n");
    printf("processed %d bits in %lu cycles\n", BLOCK_SIZE * 8, end - start);
}