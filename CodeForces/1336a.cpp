//https://codeforces.com/problemset/problem/1336/A
#include <bits/stdc++.h>

using namespace std;

int n , k;

class Node {
  public:  
    int pt;
    int nchild;
    int dr;
    int ndesc;
    vector<int> Ad;
};

Node C[200005];
int P[200005];

//parent 빼고 인접한 노드 모두 방문하기
//Rooted Tree로 만들기 : 각 노드 parent 찾음
void dfs1(int nd, int PT){
  int i,s;
  C[nd].pt = PT;
  s= C[nd].Ad.size();
  C[nd].nchild = 0;
  for(i =0; i < s; i++){
    if(C[nd].Ad[i] != C[nd].pt){
      C[nd].nchild++;
      dfs1(C[nd].Ad[i],nd);
    }
  }
}

//Root까지의 거리와 Child 개수를 return 
//dr = root까지의 거리
int dfs2(int nd, int dr){
  int i ,s;
  s= C[nd].Ad.size();
  C[nd].dr = dr;
  C[nd].ndesc = 0;
  for(i =0; i < s; i++){
    if(C[nd].Ad[i] != C[nd].pt){
      C[nd].ndesc += dfs2(C[nd].Ad[i],dr+1);
    }
  }

  return C[nd].ndesc + 1; //자기자신 포함해서 return 
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  int x,y,i;
  long long ans = 0;
  for(i = 1; i<n; i++){
    cin>> x >> y;
    C[x].Ad.push_back(y);
    C[y].Ad.push_back(x);
  }
  dfs1(1,0);
  dfs2(1,0);

  for(i =1; i<=n;i++){
    P[i] = C[i].dr - C[i].ndesc;
  }
  
  sort(P+1,P+n+1);

  for(i = 0 ; i < k; i++){
    ans += P[n-i];
  }

  printf("%lld\n",ans);
  return 0;
}