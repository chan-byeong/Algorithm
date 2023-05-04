//tree
#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> adj[10001];
int p[10001];
int gv[10001]; //1 : good vil , 0 : no 
int val[10001];

int dp[10001][2];

//rooted tree -> root == 1
void dfs(int n){
  int cur = n;
  
  for(int nxt : adj[cur]){
    if(nxt == p[cur]) continue;
    p[nxt] = cur;
    dfs(nxt);
  }
}

void dfs2(int n){
  int cur = n;

  dp[cur][0] = 0;
  dp[cur][1] = val[cur];

  for(int nxt : adj[cur]){
    if(nxt == p[cur]) continue;
    p[nxt] = cur;
    dfs2(nxt);
    dp[cur][1] += dp[nxt][0];
    dp[cur][0] += max(dp[nxt][0] ,dp[nxt][1]);

  }
}

int main()
{
  cin >> n;
  for(int i = 1;i<=n;i++)
     cin >> val[i];

  for(int i =1; i< n; i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  p[1] = 0;

  dfs(1); // root == 1

  dfs2(1);

  int ans = max(dp[1][0] , dp[1][1]);
  cout << ans <<"\n";

  return 0;
}