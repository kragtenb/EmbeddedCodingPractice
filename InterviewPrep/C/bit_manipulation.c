#include <stdlib.h>
#include <stdio.h>

unsigned int hammingWeight(unsigned int n) {
    unsigned int count = 0;
    while (n != 0) {
        n = n & (n-1);
        count++;
    }
    return count;
}

__uint32_t reverseBits(__uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
    n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
    n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

int singleNumber(const int* nums, int numsSize) {
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        res = res ^ nums[i];
    }
    return res;
}

int isPowerOfTwo(int n) {
    if (n == 0) {
        return 0;
    }

    unsigned int abs_n = (n < 0) ? -n : n;

    return (abs_n & (abs_n - 1)) == 0;
}

int missingNumber(const int* nums, int numsSize) {
    int res = 0;
    for (int i=0; i < numsSize; i++) {
        res ^= nums[i];
    }

    for (int i=0; i <= numsSize; i++) {
        res ^= i;
    }
    return res;
}


int main() {
    printf("Hamming Weight: %u\n", hammingWeight(11));

    printf("reverseBits: %u\n", reverseBits(43261596));

    int t[5] = {4, 1, 2, 1, 2};
    printf("singleNumber %d\n", singleNumber(t, 5));

    printf("isPowerOfTwo(1) %d\n", isPowerOfTwo(1));
    printf("isPowerOfTwo(16) %d\n", isPowerOfTwo(16));
    printf("isPowerOfTwo(18) %d\n", isPowerOfTwo(18));

    int mn[5] = {0, 3, 1, 2, 5};
    printf("missingNumber: %d\n", missingNumber(mn, 5));

    return 0;
}