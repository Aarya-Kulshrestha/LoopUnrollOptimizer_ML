
#include <stdlib.h>

int max(int a,int b){
  if(a>=b) return a;
  else return b;
}

void _mode(int a, int b, int max, int *A, int *mode, int *count){
  int *num;
  num=(int*)malloc((max+1)*sizeof(int));
  for(int i=0;i<=max;i++) num[i]=0;
  for(int i=a;i<=b;i++){
    num[A[i]]++;
  }
  for(int i=0;i<=max;i++){
    if(*count<num[i]){
      *count=num[i];
      *mode=i;
    }
  }
  free(num);
  return;
}

void _mode2(int a, int b, int max, int *A, int mode, int *count){
  int *num;
  num=(int*)malloc((max+1)*sizeof(int));
  for(int i=0;i<=max;i++) num[i]=0;
  for(int i=a;i<=b;i++){
    num[A[i]]++;
  }
  for(int i=0;i<=max;i++){
    if(i!=mode){
      if(*count<num[i]){
        *count=num[i];
      }
    }
  }
  free(num);
  return;
}

int main(){
  int n = 139; //Fixed n to 139
  int *v;
  v=(int*)malloc(n*sizeof(int));
  //Initialize v with some values for testing.  Replace with your actual initialization if needed.
  for(int i=0; i<n; ++i) v[i] = i % 10;


  int *odd;
  int *even;
  int odd_max=0;
  int even_max=0;
  odd=(int*)malloc((n/2)*sizeof(int));
  even=(int*)malloc((n/2)*sizeof(int));
  for(int i=0;i<(n/2);i++){
    odd[i]=v[2*i];
    if(odd[i]>odd_max) odd_max=odd[i];
    even[i]=v[2*i+1];
    if(even[i]>even_max) even_max=even[i];
  }
  int mode_odd=-1;
  int mode_even=-1;
  int count_odd=0;
  int count_even=0;
  _mode(0,n/2-1,odd_max,odd,&mode_odd,&count_odd);
  _mode(0,n/2-1,even_max,even,&mode_even,&count_even);

  int count_odd2=0;
  int count_even2=0;
  _mode2(0,n/2-1,odd_max,odd,mode_odd,&count_odd2);
  _mode2(0,n/2-1,even_max,even,mode_even,&count_even2);

  int times;
  if(mode_odd!=mode_even){
    times=n-count_odd-count_even;
  }else{
    times=max(n-count_odd-count_even2,n-count_odd2-count_even);
  }

  //printf("%d\n",times); //removed print statement.  You can uncomment for testing.

  free(v);
  free(odd);
  free(even);
  return 0;
}