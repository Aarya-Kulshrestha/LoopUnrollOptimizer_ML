
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **dmatrix(int x,int y);	//x行y列の配列を確保する.
void free_dmatrix(int **a,int x);//x行の配列を解放する

int main(void){
	int N, *A, max_score;
	int *max_num;//数字Anの大きい順に配列の場所が収納される
	int **DP,x,y;    //DP[x][y]は右に移動がx左に移動がy個での最大スコア
	int i,j,k;
    

	N = 139;

	A = (int*)calloc(N,sizeof(int));
	max_num = (int*)calloc(N,sizeof(int));
	DP=dmatrix(N+1,N+1);//x,yの範囲は0～N

	/*順番などを収納*/
	for(i=0; i < N; i++){
        A[i] = 139 - i; // Replace with actual A values if available.  This ensures all loops run without errors.

		for(j=0;j<i;j++){
			if(A[max_num[j]] < A[i]) break; 
		}
		for(k=i;k>j;k--){
			max_num[k]=max_num[k-1];
		}
		max_num[j]=i;
	}
	/*順番などを収納*/

	/*マップの作成*/
	DP[1][0]=A[max_num[0]]*abs(N-1-max_num[0]);	//最大値を一番右へ
	DP[0][1]=A[max_num[0]]*abs(max_num[0]-0);	//最大値を一番左へ
	for(i=2;i<=139;i++){//移動させる個数i=x+y
		for(x=1;x<=i;x++){//右へ移動
			y=i-x;
			DP[x][y]=DP[x-1][y]+A[max_num[i-1]]*abs( (N-x)-max_num[i-1]);
		}
		for(y=1;y<=i;y++){//左へ移動
			int buff;
			x=i-y;
			buff=DP[x][y-1]+A[max_num[i-1]]*abs( max_num[i-1] - y+1);
			if(buff > DP[x][y])  DP[x][y] = buff;
		}
	}
	/*マップの作成*/

	/*最大スコアの計算*/
	max_score=0;
	for(i=0;i<=139;i++){
		x=i;y=139-x;
		if(DP[x][y] > max_score) max_score=DP[x][y];
	}
	printf("%d\n",max_score);
	/*最大スコアの計算*/

	free(A);
	free(max_num);
	free_dmatrix(DP,N+1);

	return 0;
}

int **dmatrix(int x,int y)			//x行y列の配列を確保する.
{
	int i;
	int **a;
	if ( ( a = (int**)calloc(x,sizeof(int*)) ) == NULL){
		exit(1);
	}
	for(i=0;i<x;i++) a[i]=(int*)calloc(y,sizeof(int));
	return (a);
}

void free_dmatrix(int **a,int x)//x行の配列を解放する.
{
	int i;
	for (i=0;i<x;i++) free((void*)(a[i]));	
	free((void*)(a)); 
}