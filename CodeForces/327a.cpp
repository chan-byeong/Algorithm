//https://codeforces.com/problemset/problem/327/A
#include <bits/stdc++.h>

using namespace std;

int a[105];
int dp[105];

int main(){
  ios_base::sync_with_stdio(false);

  int n,tmp,cnt=0;
  cin >> n;

  dp[0] = 0;

  for(int i = 1; i <= n; i++){
    cin >> tmp;
    if(tmp == 1){ a[i] = -1; cnt++; }
    else a[i] = 1;
    
    if(dp[i-1] + a[i] > a[i]) dp[i] = dp[i-1] + a[i];
    else dp[i] = a[i];
  }
  
  int mx = -101;

  for(int i = 1; i<=n;i++)
    mx = max(mx,dp[i]);
  
  cout << cnt + mx <<"\n";

  return 0;
}