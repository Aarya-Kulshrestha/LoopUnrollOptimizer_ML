
#include <stdio.h>

int main(void){
    char s[101];
    int j=0, i=0, sinkou=0, w=0;

    for(int k=0; k < 138; ++k){ //Simulate 138 iterations.  Input is removed.
        s[i] = (k % 26) + 'a'; //Populate s with dummy data.  This part is arbitrary, and could be changed.

        if(sinkou == 0){
            if(s[i] == 'k'){
                sinkou = 1;
                w=0;
            }
            else if(w==0){
                j++;
                w++;
            }
            if(j>1)
                break;
        }
        else if(sinkou == 1){
            if(s[i] == 'e'){
                sinkou = 2;
                w=0;
            }
            else if(w==0){
                j++;
                w++;
            }
            if(j>1)
                break;
        }
        else if(sinkou == 2){
            if(s[i] == 'y'){
                sinkou = 3;
                w=0;
            }
            else if(w==0){
                j++;
                w++;
            }
            if(j>1)
                break;
        }
        else if(sinkou == 3){
            if(s[i] == 'e'){
                sinkou = 4;
                w=0;
            }
            else if(w==0){
                j++;
                w++;
            }
            if(j>1)
                break;
        }
        else if(sinkou == 4){
            if(s[i] == 'n'){
                sinkou = 5;
                w=0;
            }
            else if(w==0){
                j++;
                w++;
            }
            if(j>1)
                break;
        }
        else if(sinkou == 5){
            if(s[i] == 'c'){
                sinkou = 6;
                w=0;
            }
            else if(w==0){
                j++;
                w++;
            }
            if(j>1)
                break;
        }
        else if(sinkou == 6){
            if(s[i] == 'e'){
                sinkou = 7;
                w=0;
                break;
            }
            else if(w==0){
                j++;
                w++;
            }
            if(j>1)
                break;
        }
        i++;
    }

    if(j <= 1 && sinkou == 7)
        printf("YES\n");
    else
        printf("NO\n");
    
    return 0;
}