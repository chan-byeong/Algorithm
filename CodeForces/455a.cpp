//https://codeforces.com/problemset/problem/455/A

#include <bits/stdc++.h>

using namespace std;

int a[100005];
long long dp[2][100005];

int main()
{
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for(int i = 0; i<n; i++)
    cin >> a[i];
  sort(a,a+n);
  dp[0][0] = 0; dp[1][0] = a[0];

  for(int i = 1; i < n; i++){
    if(a[i] == a[i-1]) {
      dp[0][i] = dp[0][i-1];
      dp[1][i] = dp[1][i-1]+a[i];
    }
    else if(a[i] == a[i-1]+1) {
      dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
      dp[1][i] = dp[0][i-1]+a[i];
    }
    else {
      dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
      dp[1][i] = max(dp[0][i-1],dp[1][i-1]) + a[i];
    }
  }

  cout << max(dp[0][n-1],dp[1][n-1]) << "\n";

  return 0;
}