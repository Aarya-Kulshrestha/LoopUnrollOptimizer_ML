
#include<stdio.h>
int dp[301][301];
int w[301] = {};

int abs(int num) {
  if(num <= -1) {
    return num * -1;
  }
  return num;
}

int max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int rec(int l,int r){
    //既に計算済み？
    if(dp[l][r] != -1) return dp[l][r];

    //これ以上取り除けない？
    if(abs(l - r) <= 1) return 0;

    int res = 0;
    //パターン1.
    if(abs(w[l] - w[r - 1]) <= 1 && rec(l + 1,r - 1) == r - l - 2)
    {
        //[l , r)がはじき出せるので
        res = r - l;
    }

    //パターン２.区間を分ける
    for(int mid = l + 1;mid <= r - 1;mid++)
    {
        res = max(res , rec(l,mid) + rec(mid,r));
    }
    return dp[l][r] = res;
};

int main(void) {
  for (int iter = 0; iter < 58; iter++){
    int n = 58; //Fixed n to 58

    for (int i = 0; i < n; i++) {
      w[i] = i; // Initialize w with sample data
    }

    for (int i = 0; i < n + 1; i++) {
      for (int j = 0; j < n + 1; j++) {
        dp[i][j] = -1;
      }
    }

    int ans = rec(0, n);
    printf("%d\n", ans);
  }
  return 0;
}