//https://codeforces.com/problemset/problem/20/c
#include <bits/stdc++.h>

using namespace std;

#define INF 9223372036854775807
#define X first
#define Y second

int n,m;

vector<pair<long long,int>> adj[100005];
long long d[100005];
int pre[100005];


int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;

  while(m--){
    int a,b,w;
    cin >> a >> b >> w;
    adj[a].push_back({w,b});
    adj[b].push_back({w,a});
  }
  fill(d,d+n+1,INF);
  priority_queue<pair<long long,int>,
                  vector<pair<long long,int>>,
                  greater<pair<long long,int>>> pq;
  
  int st = 1 , en = n;
  d[st] = 0;
  pq.push({d[st],st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y] != cur.X) continue;
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
      d[nxt.Y] = d[cur.Y] + nxt.X;
      pq.push({d[nxt.Y],nxt.Y});
      pre[nxt.Y] = cur.Y;
    }
  }

  //path

  if(pre[n] == 0) cout << -1 << "\n";
  else{
      int cur = en;
      vector<int> path;
      path.push_back(cur);
      while(cur != st){
        path.push_back(pre[cur]);
        cur = pre[cur];
      } 
      reverse(path.begin(),path.end());
    for(int& e : path) cout << e << " ";
  }

  return 0;
}