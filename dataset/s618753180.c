
#include <stdio.h>

int main()
{
	char s[4] = "191919191919191919191919191919191919191919191919191919191919191919191919191919191919191919191919191919191919191919191919191919";
	int i;
	for (i = 0; i < 68; i++) {
		if (s[i % 4] == '1') {
			printf("9");
		} else if (s[i % 4] == '9') {
			printf("1");
		} else {
			printf("%c", s[i % 4]);
		}
	}
	printf("\n");
	return 0;
}
