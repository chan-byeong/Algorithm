//https://www.acmicpc.net/problem/17835
//다익스트라

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int n, m ,k;

vector<pair<int,int>> adj[100005];
int d[100005];
vector<int> pnt;

priority_queue<pair<int,int>> pq;

priority_queue<pair<int,int> , vector<pair<int,int>> , less<pair<int,int>>> pq_res;


pair<int,int> dijk(int nd) //시작 노드
{
  fill(d,d+n+1,INF);

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

  return {pp,nd}; 
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> k;


  while(m--){
    int a,b,w;
    cin >> a >> b >> w;
    adj[a].push_back({w,b});
  }
  while(k--){
    int tmp;
    cin >> tmp;
    pnt.push_back(tmp);
  }

  for(int i = 1; i <= n; i++){
    if(find(pnt.begin() , pnt.end() , i) != pnt.end()) continue;
    pq_res.push(dijk(i));
  }

  auto ans = pq_res.top();

  cout << ans.second << "\n" << ans.first <<"\n";

  return 0;
}