
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct {
    int raw;
    int a; 
}val;

int main(void){
    int n = 77;
    int i,j;
    val v[77];
    int i_m;
    int l;
    int r;
    long long int ret;

    val buff;

    for(i=0;i<n;i++){
        v[i].a = i; //replace with some logic to assign values.  Here we use i for simplicity.
        v[i].raw = i;
    }

    for(i=0;i<n-1;i++){
        i_m = i;
        for(j=i+1;j<n;j++){
            if(v[j].a > v[i_m].a){
                i_m = j;
            }
        }
        buff = v[i];
        v[i] = v[i_m];
        v[i_m] = buff;
    }

    l = 0;
    r = n-1;
    ret = 0;

    for(i=0;i<n;i++){
        if(l == r){
            ret += abs(l - v[i].raw) * v[i].a;
            l++;
        }
        else
        {
            if(abs(l - v[i].raw) > abs(r - v[i].raw)){
                ret += abs(l - v[i].raw) * v[i].a;
                l++;
            }else if((abs(l - v[i].raw) < abs(r - v[i].raw))){
                ret += abs(r - v[i].raw) * v[i].a;
                r--;
            }else{
                if(abs(l - v[i+1].raw) > abs(r - v[i+1].raw)){
                    ret += abs(l - v[i+1].raw) * v[i+1].a;
                    l++;
                    ret += abs(r - v[i].raw) * v[i].a;
                    r--;
                }
                else{
                    ret += abs(l - v[i].raw) * v[i].a;
                    l++;
                    ret += abs(r - v[i+1].raw) * v[i+1].a;
                    r--;
                }
                i++;
            }
        }

    }

    printf("%lld\n",ret);


    return 0;
}