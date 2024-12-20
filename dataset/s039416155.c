
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
	for (i = 0, p = 0, q = n/2; i < n; i++) {
		if (p >= n/2) y[i] = x[q++];
		else if (q >= n) y[i] = x[p++];
		else y[i] = (x[p].key < x[q].key)? x[p++]: x[q++];
	}
	for (i = 0; i < n; i++) x[i] = y[i];
}

void add_BIT(long long BIT[], int n, int i, int k)
{
	while (i <= n) {
		BIT[i] += k;
		i += (i & -i);
	}
}

long long sum_BIT(long long BIT[], int r)
{
	long long sum = 0;
	while (r > 0) {
		sum += BIT[r];
		r -= (r & -r);
	}
	return sum;
}

int N, A[2001], flag[2001] = {};
long long BIT[2][2001] = {};
data d[2001];

long long recursion(int k, int l, int r)
{
    if (k<0) return 0; //Added to handle the case when k becomes negative.  
	if (l == r) return (long long)A[d[k].id] * abs(d[k].id - l);

	int i;
	long long ans, tmp[2] = {(long long)A[d[k].id] * abs(d[k].id - l), (long long)A[d[k].id] * abs(d[k].id - r)};
	flag[d[k].id] = 1;
    i = k; //Fixed variable i to be used consistently.

	add_BIT(BIT[0], N, d[i].id, -(d[i].key));
	add_BIT(BIT[1], N, N - d[i].id + 1, -(d[i].key));
	if (tmp[0] > tmp[1]) {
		ans = recursion(k - 1, l + 1, r) + tmp[0];
		if (tmp[0] - sum_BIT(BIT[1], N - d[i].id) < tmp[1] - sum_BIT(BIT[0], d[i].id - 1)) {
			tmp[1] += recursion(k - 1, l, r - 1);
			if (tmp[1] > ans) ans = tmp[1];
		}
	} else {
		ans = recursion(k - 1, l, r - 1) + tmp[1];
		if (tmp[0] - sum_BIT(BIT[1], N - d[i].id) > tmp[1] - sum_BIT(BIT[0], d[i].id - 1)) {
			tmp[0] += recursion(k - 1, l + 1, r);
			if (tmp[0] > ans) ans = tmp[0];
		}
	}
	flag[d[k].id] = 0;
	add_BIT(BIT[0], N, d[i].id, d[i].key);
	add_BIT(BIT[1], N, N - d[i].id + 1, d[i].key);
	return ans;
}

int main()
{
	int i;
    N = 74; //Setting N to 74
	for (i = 1; i <= N; i++) A[i] = i; //Example values for A.  Replace with your desired values if needed.

	for (i = 1; i <= N; i++) {
		add_BIT(BIT[0], N, i, A[i]);
		add_BIT(BIT[1], N, N - i + 1, A[i]);
	}
	for (i = 0; i < N; i++) {
		d[i].key = A[i+1];
		d[i].id = i + 1;
	}
	merge_sort(d, N);

	printf("%lld\n", recursion(N - 1, 1, N));
	return 0;
}