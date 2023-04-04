//https://codeforces.com/problemset/problem/189/a
#include <bits/stdc++.h>

using namespace std;

int dp[3][4001];
int len[3];

int main(){
  ios_base::sync_with_stdio(false);

  int n ,a,b,c ,ans = -1;
  cin >> n >> len[0] >> len[1] >> len[2] ;

  for(int i = 1; i <= n; i++){
    for(int j = 0; j < 3; j++)
    {
      if(i-len[j] < 0) dp[j][i] = -1;
      else if(i-len[j] == 0) dp[j][i] = 1;
      else{
        int mx = max(max(dp[j][i-len[j]],dp[(j+1)%3][i-len[j]]),dp[(j+2)%3][i-len[j]]);
        if(mx < 0) dp[j][i] = -1;
        else dp[j][i] = mx + 1;
      }
    }
  }
  ans = max(max(dp[0][n],dp[1][n]),dp[2][n]);
  cout << ans <<"\n";

  return 0;
}