
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>

#define inf (INT_MAX-1)
#define INF 9223372036854775807
#define sq(n) ((n)*(n))
#define rep(i,n) for(i=0;i<n;i++)
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
    rep(i, b){
        c *= a;
    }
    return c;
}

int main(void){
    int i, j, n, m=31, ans=-1, eval[2], f=0;             //0<m<41
    n = 106; //Fixed n to 106
    int x[106], y[106], d[31];                               //0<d_i<10^12+1
    rep(i,106){ //Changed loop to iterate 106 times.
        x[i] = 1; //Dummy values
        y[i] = 1; //Dummy values
        eval[i%2] = (x[i]+y[i])%2;
        if(i>0&&eval[0]!=eval[1]) f = 1;
    }
    if(f==0){
        if((x[0]+y[0])%2==0) m++;
        //print(m);
        rep(i, 31){
            if((x[0]+y[0])%2!=0||i>0){
                d[i] = intpow(2, i);
                //printf("%d ", d[i]);
            }
            else d[i]=0;
        }
        //printf("\n");
        int u[32], v[32];
    
        rep(i, 106){ //Changed loop to iterate 106 times.
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
                //if(x_1[j]-x_1[j-1]<0) printf("L");
                //else if(x_1[j]-x_1[j-1]>0) printf("R");
                //else if(y_1[j]-y_1[j-1]<0) printf("D");
                //else if(y_1[j]-y_1[j-1]>0) printf("U");
            }
            //printf("\n");
        }
    }
    //if(f==1) print(ans);
    return 0;
}