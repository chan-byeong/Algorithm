//https://codeforces.com/problemset/problem/602/b
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n ,ans = 0;
  cin >> n;

  vector<int> v(n+1);
  map<int,int> mm;

  for(int i=1 ;i<=n; i++) 
    cin >> v[i];

  int e = 1 , cnt = 1;
  mm[v[1]] = 1;
  
  for(int s = 1; s <= n ; s++)
  {
    while(e+1 <= n && (mm.rbegin()->first - mm.begin()->first) <= 1){
      e++;
      cnt++;
      mm[v[e]]++;
    }
    //마지막일때 조건 확인
    if((mm.rbegin()->first - mm.begin()->first) > 1){ 
      ans = max(ans,cnt-1);
    }
    else
      ans = max(ans,cnt);
    
    mm[v[s]]--;
    if(mm[v[s]] == 0 ) mm.erase(v[s]);
    cnt--;
    if(e == n) break;
  }

  cout << ans <<"\n";

  return 0;
}