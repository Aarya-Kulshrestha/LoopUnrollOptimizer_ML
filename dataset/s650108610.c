#include <stdio.h>

int main(void){
    char s[4];
    scanf("%s",s);
    for (int i=0; i<3; i++){
        if (s[i]=='1'){
            s[i]='9';
        } else {
            s[i]='1';
        }
    }
    printf("%s\n",s);
	return 0 ;
}