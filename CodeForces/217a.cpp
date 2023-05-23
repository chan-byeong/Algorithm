#include <bits/stdc++.h>

using namespace std;

//edges
vector<int> ed[1000];
//visited
int v[1000];

int x[1000] , y[1000];

void dfs(int nd){
  for(int i = 0; i<ed[nd].size();i++){
    if(v[ed[nd][i]] != 0) continue;
    v[ed[nd][i]] = 1;
    dfs(ed[nd][i]);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  
  int n , ans = 0;
  cin >> n;

  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
  }

  for(int i=0; i<n;i++){
    for(int j=0;j<n;j++){
      if(x[i]==x[j] || y[i]==y[j]){
        ed[i].push_back(j);
        ed[j].push_back(i);
        }
    }
  }

  for(int i=0;i<n;i++){
    if(v[i] == 0){
      ans++;
      dfs(i);
    }
  }
  ans--;

  cout << ans <<"\n";
  
  return 0;
}