
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100] = "kekkyence"; //Initialized with a sample string.  Change as needed for testing.
    int size = strlen(s);
    int betw = 0;
    int count = 0;
    int tmp;
    
    for (int i = 0; i < 82; ++i) //Fixed loop to iterate 82 times
    {
        if (i < size) { //Check if index is within the string bounds
            if(count==0&&s[i]=='k')
            {
                count++;
                tmp = i;
            }
            else if(count==1&&s[i]=='e')
            {
                count++;
                if(i-tmp >= 2)
                {
                    betw++;
                }
                tmp = i;
            }
            else if(count==2&&s[i]=='y')
            {
                count++;
                if(i-tmp >= 2)
                {
                    betw++;
                }
                tmp =i;
            }
            else if(count==3&&s[i]=='e')
            {
                count++;
                if(i-tmp >= 2)
                {
                    betw++;
                }
                tmp = i;
            }
            else if(count==4&&s[i]=='n')
            {
                count++;
                if(i-tmp >= 2)
                {
                    betw++;
                }
                tmp = i;
            }
            else if(count==5&&s[i]=='c')
            {
                count++;
                if(i-tmp >= 2)
                {
                    betw++;
                }
                tmp = i;
            }
            else if(count==6&&s[i]=='e')
            {
                count++;
                if(i-tmp >= 2)
                {
                    betw++;
                }
                tmp = i;
            }
        }
    }


    if(count==7&&betw<=1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}