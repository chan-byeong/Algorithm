//https://www.acmicpc.net/problem/14003
//LIS : temp_array(dp)의 마지막 값만 변경

#include <bits/stdc++.h>

using namespace std;


int main()
{
  int n , ans = 0;
  cin >> n;
  
  vector<int> a(n);
  vector<int> id;
  vector<int> dp;

  dp.push_back(-1000000001);

  for(int i= 0; i < n; i++)
    cin >> a[i];
  
  for(int i = 0; i < n; i++){
      // auto iter = lower_bound(dp.begin(),dp.end(),a[i]);
      // *iter = a[i];
      //iterator -> index
      auto idx = lower_bound(dp.begin(),dp.end(),a[i]) - dp.begin();
      if(idx == dp.size()){
        ans++;
        dp.push_back(a[i]);
      }
      dp[idx] = a[i];
      id.push_back(idx);
    }
  

  cout << ans << "\n";

  //실제 배열 출력

  // for(int i=1 ;i<=n;i++){
  //   cout << dp[i] <<" ";
  // }
  // cout << "\n";

  // for(int& e : id)
  //   cout << e <<" ";

  // cout << "\n";
  stack<int> buf;
  for(int i = n - 1; i >= 0; i--){
    if(id[i] == ans){
      buf.push(a[i]);
      //cout << a[i] <<" ";
      ans-=1;
    }
  }

  while(!buf.empty()){
    cout << buf.top() <<" ";
    buf.pop();
  }

  return 0;
}