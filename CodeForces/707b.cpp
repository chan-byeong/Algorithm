//https://codeforces.com/problemset/problem/707/b
//Bakery
#include <bits/stdc++.h>

using namespace std;

int ed[100001][3];
int f[100001];

int main(){

  ios_base::sync_with_stdio(false);
  int n,m,k,ans;
  cin >> n >> m >> k;
  for(int i=0;i<m;i++){
    cin >> ed[i][0] >> ed[i][1] >> ed[i][2];
  }
  for(int i=0;i<k;i++){
    int t;
    cin >> t;
    f[t] = 1;
  }
  //한쪽은 밀가루 한쪽은 가게 중 최소가 정답
  ans = 2000000000;
  for(int i=0; i<m; i++){
    if(f[ed[i][0]]+ f[ed[i][1]] == 1){
      ans = min(ans,ed[i][2]);
    }
  }
  if(ans == 2000000000) cout << "-1" <<"\n";
  else cout << ans <<"\n";

  return 0;
}