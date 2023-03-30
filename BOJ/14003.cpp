//https://www.acmicpc.net/problem/14003
//LIS : temp_array(dp)의 마지막 값만 변경

#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n , ans = 0;
  cin >> n;
  
  vector<int> a(n);
  vector<int> dp;

  dp.push_back(-1000000001);

  for(int i= 0; i < n; i++)
    cin >> a[i];
  
  for(int i = 0; i < n; i++){
    if(a[i] > dp.back()){
      ans++;
      dp.push_back(a[i]);
    }
    else{
      auto iter = lower_bound(dp.begin(),dp.end(),a[i]);
      if(iter == prev(dp.end())) { *iter = a[i]; } 
    }
  }

  cout << ans << "\n";
  //실제 배열 출력
  for(int i = 1; i<=ans; i++)
    cout << dp[i] <<" ";
  cout <<"\n";

  return 0;
}