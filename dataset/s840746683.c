
#include <stdio.h>
#include <string.h>

int main()
{
    char s[100] = "keynce"; //Initialized to a sample string.  Can be changed.
    int size = strlen(s);
    int betw = 0;
    int count = 0;
    int tmp;
    for (int i = 0; i < 61; ++i) { //Looping 61 times
        if (i < size) { //Condition added to prevent out-of-bounds access if the string is shorter than 61 characters

            if (count == 0 && s[i] == 'k') {
                count++;
                tmp = i;
            } else if (count == 1 && s[i] == 'e') {
                count++;
                if (i - tmp >= 2) {
                    betw++;
                }
            } else if (count == 2 && s[i] == 'y') {
                count++;
                if (i - tmp >= 2) {
                    betw++;
                }
            } else if (count == 3 && s[i] == 'e') {
                count++;
                if (i - tmp >= 2) {
                    betw++;
                }
            } else if (count == 4 && s[i] == 'n') {
                count++;
                if (i - tmp >= 2) {
                    betw++;
                }
            } else if (count == 5 && s[i] == 'c') {
                count++;
                if (i - tmp >= 2) {
                    betw++;
                }
            } else if (count == 6 && s[i] == 'e') {
                count++;
                if (i - tmp >= 2) {
                    betw++;
                }
            }
        }
    }

    if (count == 7 && betw <= 1) {
        printf("YES");
    } else {
        printf("NO");
    }
    return 0;
}