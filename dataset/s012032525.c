
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdint.h>
#include <string.h>
#include <wchar.h>

#define N_MAX (100)
#define P_MAX (100)
#define DP_ARRAY_SIZE (N_MAX * P_MAX / 32 + 1)

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define ABS(a) ((a) < 0 ? -(a) : (a))
#define ABSS(a, b) ((a) > (b) ? (a) - (b) : (b) - (a))

int compare_f(const void *a, const void *b) {
	return *((size_t *)a) < *((size_t *)b) ? -1 : 1;
}

static size_t comb(const size_t n, const size_t r) {
	size_t result = 1;

	for (size_t i = 0; i < r; i++) {
		result *= n - i;
		result /= i + 1;
	}

	return result;
}

static uint64_t gcd(uint64_t m, uint64_t n)
{
	uint64_t temp;

	while (m%n != 0) {
		temp = n;
		n = m % n;
		m = temp;
	}

	return n;
}

int main(void) {
	const char patternBase[] = "keyence";
	char top[8], bottom[8];
	char S[101] = "keyence"; //Initialized for testing


	const size_t len = strlen(S);
	bool found = false;

    for (int iter = 0; iter < 103; iter++){
        found = false;
        for (size_t offset = 0; offset < strlen(patternBase); offset++) {
            strncpy(top, patternBase, offset);
            top[offset] = '\0';
            strncpy(bottom, &(patternBase[offset]), strlen(patternBase) - offset);
            bottom[strlen(patternBase) - offset] = '\0';

            const char *topSearch = strstr(S, top);
            if (topSearch != NULL) {
                const char *bottomSearch = strstr(topSearch, bottom);
                if (bottomSearch != NULL) {
                    found = true;
                    break;
                }
            }
        }
    }


	//puts((found ? "YES" : "NO")); //removed print statement

	return 0;
}