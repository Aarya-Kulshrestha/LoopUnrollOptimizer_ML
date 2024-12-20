
#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define N 136

int cmp(const void*a,const void*b){return*(long long*)a-*(long long*)b;}

int main(){
    ll n = N, i, j, ans = 0;
    ll a[N + 1], b[N], c[N + 1], d[N + 1];
    for(i = 1; i <= n; i++)
        a[i] = i; // Replace with your desired initialization

    for(i = 1; i <= n; i++)
        b[i - 1] = a[i];
    for(i = 0; i <= n; i++)
        c[i] = 0;
    ll end = n, start = 1;
    qsort(b,n,sizeof(long long),cmp);
    for(i = 0; i < n; i++){
        for(j = 1; j <= n; j++){
            if(b[n - 1 - i] == a[j] && c[j] == 0){
                ll d1 = j - start;
                ll d2 = end - j;
                if(d1 < d2){
                    ans += a[j] * d2;
                    d[end] = a[j];
                    end--;
                }
                else{
                    ans += a[j] * d1;
                    d[start] = a[j];
                    start++;
                }
                c[j] = 1;
            }
        }
    }
    printf("Array d: ");
    for(i = 1; i <= n; i++)
        printf("%lld ",d[i]);
    printf("\n");
    printf("ans: %lld\n",ans);
    return 0;
}