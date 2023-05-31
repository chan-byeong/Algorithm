//다익스트라 알고리즘 
#include <bits/stdc++.h>
#define first X
#define second Y
using namespace std;

vector<pair<int,int>> adj[20005]; //비용 , 간선번호
const int INF 0x3f3f3f3f;
bool fix[20005];    //확정된 정점인가?
int d[20005];       //최단거리 테이블
int V = 10;         //정점의 개수 

// 시간 복잡도 : O(V^2+E)
void dijkstra_naive(int st){
  fill(d,d+V+1,INF);
  d[st] = 0;
  while(true){
    int idx = -1;
    for(int i =1 ; i <= V;i++){
      if(fix[i]) continue;
      if(idx == -1) idx = i;
      else if(d[i] < d[idx]) idx = i;
    }
    if(idx == -1 || d[idx] == INF)
      break;
    fix[idx] = 1;
    for(auto nxt : adj[idx])
      d[nxt.Y] = min(d[nxt.Y],d[idx] + nxt.X);
  }
}

int main(){

  


  return 0;
}
