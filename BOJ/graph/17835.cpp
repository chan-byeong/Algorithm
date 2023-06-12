//https://www.acmicpc.net/problem/17835
//다익스트라
//시간초과 -> 수정 : 면접장에서 모든 노드로 다익스트라 수행
#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int n, m ,k;

vector<pair<int,int>> adj[100005];
int d[100005];
vector<int> pnt;

priority_queue<pair<int,int>> pq;

void dijk(int nd) //시작 노드
{
  d[nd] = 0;
  pq.push({d[nd],nd});

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.second] != cur.first ) continue;

    for(auto nxt : adj[cur.second]){
      if(d[nxt.second] <= d[cur.second]+nxt.first) continue;
      d[nxt.second] = d[cur.second] + nxt.first;
      pq.push({d[nxt.second],nxt.second});
    }
  }

  int pp = INF;
  for(int p : pnt){
    pp = min(d[p],pp);
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> k;

  fill(d,d+n+1,INF);
  while(m--){
    int a,b,w;
    cin >> a >> b >> w;
    adj[b].push_back({w,a});
  }
  while(k--){
    int tmp;
    cin >> tmp;
    pnt.push_back(tmp);
  }

  for(int i = 1; i <= n; i++){
    if(find(pnt.begin() , pnt.end() , i) != pnt.end()) {
      dijk(i);      
    }
  }

  pair<int,int> ans = {0,0};

  for(int i = 1; i <= n; i++){
    if(find(pnt.begin() , pnt.end() , i) != pnt.end()) continue;
    if(ans.first < d[i]){
      ans = {d[i],i};
    }
  }

  cout << ans.second << "\n" << ans.first <<"\n";

  return 0;
}