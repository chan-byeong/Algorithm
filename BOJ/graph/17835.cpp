//https://www.acmicpc.net/problem/17835
//다익스트라
//시간초과 -> 수정 : pq에 면접장 노드 넣고, 다익스트라 1회 수행
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 0x3f3f3f3f

ll n, m ,k;

vector<pair<ll,ll>> adj[100005];
ll d[100005];

priority_queue<pair<ll,ll>> pq;

void dijk() //시작 노드
{
  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.second] != cur.first ) continue; 
    
    for(auto nxt : adj[cur.second]){
      if(d[nxt.second] <= d[cur.second] + nxt.first) continue;
      d[nxt.second] = d[cur.second] + nxt.first;
      pq.push({d[nxt.second],nxt.second});
    }
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m >> k;

  fill(d,d+n+1,INF);

  while(m--){
    ll a,b,w;
    cin >> a >> b >> w;
    adj[b].push_back({w,a});
  }
  while(k--){
    int tmp;
    cin >> tmp;
    d[tmp] = 0;
    pq.push({d[tmp],tmp});
  }

  dijk();

  ll answ = 0;
  int ansn = 0;

  for(int i = 1; i <= n; i++){
    if(answ < d[i]){
      answ = d[i];
      ansn = i;
    }
  }

  cout << ansn << "\n" << answ <<"\n";

  return 0;
}