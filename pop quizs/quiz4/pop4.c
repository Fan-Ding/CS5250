#include<stdio.h>
#include<stdint.h>

uint_fast64_t dl_new_hash (const char *s);

int main(){
    int maskwords = 4;
    int shift2 = 7;
    int c = 64;

    char *symbol_name = "printf";

    uint_fast64_t h1 = dl_new_hash(symbol_name);
	printf("H1: %llx\n", h1);

	uint_fast64_t h2 = h1 >> shift2;
	printf("H2: %llx\n", h2);

	uint_fast64_t n = ((h1/c) % maskwords);
	printf("N: %llx\n", n);

	uint_fast64_t BITMASK = (1 << (h1 % c)) | (1 << (h2 % c));
	printf("BITMASK: %llx\n", BITMASK);

	return 0;
}

uint_fast64_t dl_new_hash(const char *s){
	uint_fast64_t h = 5381;
	for (unsigned char c = *s; c!= '\0'; c = *++s)
		h = h * 33 + c;
	return h & 0xffffffff;
}
