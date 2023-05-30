//https://www.acmicpc.net/problem/2606
#include <bits/stdc++.h>

using namespace std;

vector<int> edge[101];
int vis[101];
int cnt = 0;

void dfs(int nd){
  vis[nd] = 1;

  for(int i = 0; i<edge[nd].size();i++){
    int nnd = edge[nd][i];
    if(vis[nnd] == 1) continue;
    cnt++;
    dfs(nnd);
  }
}

int main()
{
  ios_base::sync_with_stdio(false);

  int n ,k,t1,t2;
  cin >> n;
  cin >> k;

  for(int i=0;i<k;i++){
    cin >>t1>>t2;
    edge[t1].push_back(t2);
    edge[t2].push_back(t1);
  }

  dfs(1);
  
  cout << cnt <<"\n";

  return 0;  
}