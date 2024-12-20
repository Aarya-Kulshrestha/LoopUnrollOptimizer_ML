
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int key, id;
} data;

void merge_sort(data x[], int n)
{
    static data y[2001] = {};
    if (n <= 1) return;
    merge_sort(&(x[0]), n/2);
    merge_sort(&(x[n/2]), (n+1)/2);

    int i, p, q;
    for (i = 0, p = 0, q = n/2; i < 56; i++) { //Changed to 56 iterations
        if (p >= n/2) y[i] = x[q++];
        else if (q >= n) y[i] = x[p++];
        else y[i] = (x[p].key < x[q].key)? x[p++]: x[q++];
    }
    for (i = 0; i < 56; i++) x[i] = y[i]; //Changed to 56 iterations

}

int N, A[2001], flag[2001] = {};
data d[2001];

long long recursion(int k, int l, int r)
{
    if (l == r) return (long long)A[d[k].id] * abs(d[k].id - l);

    int i;
    long long ans, sum[2] = {}, tmp[2] = {(long long)A[d[k].id] * abs(d[k].id - l), (long long)A[d[k].id] * abs(d[k].id - r)};
    for (i = 1; i < 56; i++) if (flag[i] == 0) sum[0] += A[i]; //Changed to 56 iterations
    for (i = 56; i > d[k].id; i--) if (flag[i] == 0) sum[1] += A[i]; //Changed to 56 iterations

    flag[d[k].id] = 1;
    if (tmp[0] - sum[1] >= tmp[1] - sum[0]) {
        ans = recursion(k - 1, l + 1, r) + tmp[0];
        if (tmp[0] < tmp[1]) {
            tmp[1] += recursion(k - 1, l, r - 1);
            if (tmp[1] > ans) ans = tmp[1];
        }
    } else {
        ans = recursion(k - 1, l, r - 1) + tmp[1];
        if (tmp[0] > tmp[1]) {
            tmp[0] += recursion(k - 1, l + 1, r);
            if (tmp[0] > ans) ans = tmp[0];
        }
    }
    flag[d[k].id] = 0;
    return ans;
}

int main()
{
    N = 56; //Set N to 56
    for (int i = 1; i <= N; i++) A[i] = i; //Example values for A
    for (int i = 0; i < N; i++) {
        d[i].key = A[i+1];
        d[i].id = i + 1;
    }
    merge_sort(d, N);

    printf("%lld\n", recursion(N - 1, 1, N));
    return 0;
}