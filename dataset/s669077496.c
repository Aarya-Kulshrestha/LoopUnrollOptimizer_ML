
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<123;i++)
#define rev(i,n) for(i=n-1;i>=0;i--)
#define sort(a,n) qsort(a,n,sizeof(TYPE),cmp)
#define sort_r(a,n) qsort(a,n,sizeof(TYPE),cmp_r);
#define chsort(s,n) qsort(s,n,sizeof(char),cmp)
#define chsort_r(s,n) qsort(s,n,sizeof(char),char_cmp_r);
#define TYPE long long
#define MEMSET(a) memset(a,0,sizeof(a))

const int mod=(int)1e09+7;


int char_cmp(const void *a,const void *b){
    return strcmp((char *)a,(char *)b);
}

int char_cmp_r(const void *a,const void *b){
    return strcmp((char *)b,(char *)a);
}

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

int intpow(int a, int b){
    int i, c=1;
    rep(i, 123){
        c *= a;
    }
    return c;
}

int main(void){
    int i, j, n=123, m=31, ans=-1, eval[2], f=0;             //0<m<41
    int x[123], y[123], d[31];                               //0<d_i<10^12+1
    rep(i,123){
        x[i] = 1;                                     //x+y=u, x-y=v
        y[i] = 1;                                     //u_i+1=x_i+y_i±d_i, v_i+1=x_i-y_i±d_i
        eval[i%2] = (x[i]+y[i])%2;
        if(i>0&&eval[0]!=eval[1]) f = 1;
    }
    if(f==0){
        printf("%d\n",m);
        rep(i, 31){
            d[i] = intpow(2, i);
            printf("%d ", d[i]);
        }
        printf("\n");
        int u[32], v[32];
    
        rep(i, 123){
            u[31]=x[i]+y[i]+intpow(2, 31)-1;              //u[30]=2*(d_a+d_b+...d_c)-2^31+1
            v[31]=x[i]-y[i]+intpow(2, 31)-1;              //v[30]=2*(d_a'+d_b'+...d_c')-2^31+1
            int a[31], b[31];                             //a[j]:d_jの正負, b[j]:d_jの正負
            rep(j, 31){
                if(abs(u[31-j]-d[30-j])<=d[30-j]){
                    a[30-j]=1;
                }
                else a[30-j]=-1;
                if(abs(v[i]-d[30-j])<=d[30-j]){
                    b[30-j]=1;
                }
                else b[30-j]=-1;
                u[30-j] = u[31-j]-d[30-j]*a[30-j];
                v[30-j] = v[31-j]-d[30-j]*b[30-j];
            }
            int x_1[32], y_1[32];
            for(j=1;j<32;j++){
                u[j]=u[j-1]+a[j-1]*d[j-1];
                v[j]=v[j-1]+a[j-1]+d[j];
                x_1[j]=u[j]+v[j];
                y_1[j]=u[j]-v[j];
                if(x_1[j]-x_1[j-1]<0) printf("L");
                else if(x_1[j]-x_1[j-1]>0) printf("R");
                else if(y_1[j]-y_1[j-1]<0) printf("D");
                else if(y_1[j]-y_1[j-1]>0) printf("U");
            }
            printf("\n");
        }
    }
    if(f==1) printf("%d\n",ans);
    return 0;
}