//https://www.acmicpc.net/problem/1753
//최단거리 구하기 - 다익스트라 알고리즘
#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define ww first
#define vv second

vector<pair<int,int>> adj[20005];
int d[20005];

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int  v , e , k;
  cin >> v >> e;
  cin >> k;

  fill(d,d+v+1,INF);

  while(e--){
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({w,v});
  }

  priority_queue<pair<int,int>,
                  vector<pair<int,int>>,
                  greater<pair<int,int>>> pq;
  
  int st = k;
  d[st] = 0;
  pq.push({d[st],st});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.vv] != cur.ww) continue;
    for(auto nxt : adj[cur.vv]){
      if(d[nxt.vv] <= d[cur.vv]+nxt.ww) continue;
      d[nxt.vv] = d[cur.vv]+nxt.ww;
      pq.push({d[nxt.vv] , nxt.vv});
    }
  } 

  for(int i=1; i<=v ;i++){
    if(d[i] == INF) cout << "INF" << "\n";
    else cout <<d[i]<<"\n";
  }


  return 0;
}