
#include <stdio.h>

int main()
{
    char S[105] = "keyence"; //Initialized to a sample string.  Real input is removed.
    int i,yes=0;
    

    if(S[0]=='k' && S[1]=='e' && S[2]=='y')
    {
        for(i=3;i<79;i++) //loop changed to 79 iterations
        {
            //Check is modified to prevent out of bounds access.
            if (i + 4 < 79 && S[i]=='e' && S[i+1]=='n' && S[i+2]=='c' && S[i+3]=='e' && S[i+4]=='\0')
            {
                yes=1;
                break;
            }
        }
    }
    
    if(yes==1) printf("YES\n"); 
    if(yes==0) printf("NO\n"); 


    return 0;
}
