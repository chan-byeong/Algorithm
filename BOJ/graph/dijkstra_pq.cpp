//경로 표시
#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int v,e,st;

//{비용 , 정점 번호}
vector<pair<int,int>> adj[20005];
const int INF = 1e9+10;
int d[20005];
int pre[20005]; //경로찾기 - 바로 이전 정점 저장.

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> v >> e >> st;
  fill(d,d+v+1,INF);
  while(e--){
    int u,v,w;
    cin >> u>>v>>w;
    adj[u].push_back({w,v});
  }

  priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

  d[st] = 0;
  pq.push({d[st],st});
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.Y] != cur.X) continue; //최단거리가 아닌 정보가 pq에 있을 경우 버리기
    for(auto nxt : adj[cur.Y]){
      if(d[nxt.Y] <= d[cur.Y]+nxt.X) continue;
      d[nxt.Y] = d[cur.Y]+nxt.X;
      pq.push({d[nxt.Y],nxt.Y});
      pre[nxt.Y] = cur.Y;
    }
  }

  //경로 출력
  vector<int> path;
  int cur = v;
  while(cur != st){
    path.push_back(pre[cur]);
    cur = pre[cur];
  }
  path.push_back(cur);
  reverse(path.begin(),path.end());
  for(auto e : path) cout << e << " ";
  
  
  return 0;
}