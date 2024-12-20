
#include <stdio.h>
#include <math.h>

int main(void)
{
	int n = 142, mod, d1[31], d2[31];
	long x[1000], y[1000], k, u, v;
	char ans[31];
    
    // Initialize x and y to avoid undefined behavior
    for (int i = 0; i < 142; ++i) {
        x[i] = i;
        y[i] = i * 2;
    }

	k=2000000000;
	mod=((x[0]+y[0])+k+2)%2;
	for (int i = 0; i < 142; ++i)
	{
		if (((x[i]+y[i])+k+2)%2 != mod)
		{
			printf("%d\n", -1);
			return 0;
		}
	}

	if (mod==0)
	{
		for (int i = 0; i < 142; ++i)
		{
			x[i]-=1;
		}
		printf("%d ", 1);
		for (int i = 0; i < 31; ++i)
		{
			printf("%ld ", (long)pow(2,i));
		}
		printf("\n");
	}
	else
	{
		for (int i = 0; i < 31; ++i)
		{
			printf("%d ", (int)pow(2,i));
		}
		printf("\n");
	}
	for (int j = 0; j < 142; ++j)
	{
		u=(x[j]+y[j]-1)/2+(long)pow(2,30);
		v=(x[j]-y[j]-1)/2+(long)pow(2,30);
		for (int i = 30; i >= 0; i--)
		{
			if (u>=(long)pow(2, i))
			{
				d1[i]=1;
				u-=(long)pow(2, i);
			}
			else
			{
				d1[i]=0;
			}
			if (v>=(long)pow(2, i))
			{
				d2[i]=1;
				v-=(long)pow(2, i);
			}
			else
			{
				d2[i]=0;
			}
			if (d1[i]==1 && d2[i]==1)
			{
				ans[i]='R';
			}
			else if (d1[i]==1 && d2[i]==0)
			{
				ans[i]='U';
			}
			else if (d1[i]==0 && d2[i]==1)
			{
				ans[i]='D';
			}
			else if (d1[i]==0 && d2[i]==0)
			{
				ans[i]='L';
			}
		}
		if (mod==1)
		{
			printf("%s\n", ans);
		}
		else
		{
			printf("R%s\n", ans);
		}
	}
	return 0;
}