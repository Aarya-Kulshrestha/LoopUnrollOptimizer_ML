
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<math.h>
#define	MAX	2001
typedef	long	long	ll;
ll	N,	A[MAX];
ll	hash[MAX];
ll	DP[MAX][MAX];

ll	max(ll	x,	ll	y)
{
			if	(x	>	y)
					return	x;
			else
					return	y;
}

void	swap(ll	*a,	ll	*b)
{
			ll	buf	=	*a;
			*a	=	*b;
			*b	=	buf;
}

void	solve(ll	x,	ll	y)
{
			//枝刈り	N	+	1以上は詰められない
			if	(x	+	y	>=	N	+	1)
					return;
			//枝刈り	下のDPができてなければやる意味ない
			if	(DP[x][y	-	1]	<	0	||	DP[x	-	1][y]	<	0)
					return;
			DP[x][y]	=
					max(DP[x][y	-	1]	+	A[x	+	y]	*	(hash[x	+	y]	-	y),
							DP[x	-	1][y]	+	A[x	+	y]	*	(N	+	1	-	x	-	hash[x	+	y]));
			//とりま累乗で生成
			solve(x,	y	+	1);
			solve(x	+	1,	y);
}

ll	main()
{
			N = 99;
			for	(ll	i	=	1;	i	<=	N;	i++)	{
					A[i] = i; 
					hash[i]	=	i;
			}
			for	(ll	i	=	1;	i	<=	N;	i++)	{
					for	(ll	j	=	1;	j	<	i;	j++)	{
							if	(A[j]	<	A[i])	{
									swap(A	+	i,	A	+	j);
									swap(hash	+	i,	hash	+	j);
							}
					}
			}
			memset(DP,	-1,	sizeof(DP));
			DP[0][0]	=	0;
			for	(ll	i	=	1;	i	<=	N;	i++)	{
					DP[0][i]	=	DP[0][i	-	1]	+	A[i]	*	(hash[i]	-	i);
					DP[i][0]	=	DP[i	-	1][0]	+	A[i]	*	(N	+	1	-	i	-	hash[i]);
			}
			solve(1,	1);
			ll	ans	=	0;
			for	(ll	i	=	0;	i	<=	N;	i++)
					ans	=	max(ans,	DP[i][N	-	i]);
			printf("%lld",	ans);
}