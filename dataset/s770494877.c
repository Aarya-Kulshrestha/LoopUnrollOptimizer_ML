
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = 116; 
int w[300];

int memo[512][512];

int search(int begin, int end) {
    int ret = end - begin;
    if (end <= begin) return 0;
    if (end == begin + 1) return 1;
    if (end == begin + 2) return abs(w[begin] - w[begin + 1]) <= 1 ? 0 : 2;
    if (memo[begin][end]) return ~memo[begin][end];
    if (abs(w[begin] - w[end - 1]) <= 1 && search(begin + 1, end - 1) == 0) {
        ret = 0;
    } else {
        int i;
        for (i = begin + 1; i < end; i++) {
            int candidate = search(begin, i) + search(i, end);
            if (candidate < ret) ret = candidate;
        }
    }
    return ~(memo[begin][end] = ~ret);
}

int main(void) {
    int i;
    for (i = 0; i < n; i++) {
        w[i] = i; //Example values.  Replace with your desired initialization.
    }
    memset(memo, 0, sizeof(memo));
    printf("%d\n", n - search(0, n));
    return 0;
}