//https://www.acmicpc.net/problem/11779
//다익스트라 경로 표시
//https://www.acmicpc.net/problem/1753
//최단거리 구하기 - 다익스트라 알고리즘
#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define ww first
#define vv second

vector<pair<int,int>> adj[1005];
int d[1005];
int pre[1005];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int  n , m , st, en;
  cin >> n >> m;

  fill(d,d+n+1,INF);

  while(m--){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }

  cin >> st >> en;

  priority_queue<pair<int,int>,
                  vector<pair<int,int>>,
                  greater<pair<int,int>>> pq;
  
  d[st] = 0;
  pq.push({d[st],st});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.vv] != cur.ww) continue;
    for(auto nxt : adj[cur.vv]){
      if(d[nxt.vv] <= d[cur.vv]+nxt.ww) continue;
      d[nxt.vv] = d[cur.vv]+nxt.ww;
      pq.push({d[nxt.vv] , nxt.vv});
      pre[nxt.vv] = cur.vv;
    }
  } 

  vector<int> path;
  int cur = en;
  path.push_back(cur);
  while(cur != st){
    path.push_back(pre[cur]);
    cur = pre[cur];
  }

  reverse(path.begin() , path.end());


  cout << d[en] <<"\n";
  cout << path.size() << "\n";
  for(int e : path) cout << e <<" ";

  return 0;
}