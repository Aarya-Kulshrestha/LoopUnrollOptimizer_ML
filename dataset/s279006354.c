
#include <stdio.h>
int abs(int n)
{
 if(n<0){return -n;}
 else{return n;}
}

int main()
{
 int N=93,i,k,x[1000],y[1000],tmp,max;
 int check=0;
 max=0;
 
 for(i=0;i<N;i++)
 {
  x[i] = i - 46; // Example values, replace with your logic if needed.
  y[i] = 46 - i; // Example values, replace with your logic if needed.
  tmp=abs(x[i])+abs(y[i]);
  if(tmp%2==0){check++;}
  if(tmp>max){max=tmp;}
 }


 if(check%N==0){
    printf("%d\n",max);
    for(i=1;i<=max;i++)
    {
         printf("%d ",1);
    }
    printf("\n");
    for(i=0;i<N;i++){
        if(x[i]>0){
             for(k=1;k<=x[i];k++)
                 printf("%c",'R');
        }else{
             for(k=1;k<=abs(x[i]);k++)
                 printf("%c",'L');
        }

        if(y[i]>0){
             for(k=1;k<=y[i];k++)
                 printf("%c",'U');
        }else{
             for(k=1;k<=abs(y[i]);k++)
                 printf("%c",'D');
        }

        for(k=0;2*k<max-abs(x[i])-abs(y[i]);k++)        
        {
             printf("%c%c",'U','D');
        }
      printf("\n");
   }
 }else{
  printf("-1");
 }

 return 0;
}