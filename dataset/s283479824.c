
#include<stdio.h>
int main(void){
  char n[3] = "123"; //Initialized to avoid undefined behavior

  for(int i=0;i<99;i++){ 
    for(int j=0; j<3; j++){
      if(n[j]=='1'){
        n[j]='9';
      }else if(n[j]=='9'){
        n[j]='1';
      }
    }
  }
  printf("%s",n); 
  return 0;
}
