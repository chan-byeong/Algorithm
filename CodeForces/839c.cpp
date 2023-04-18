//Tree문제
//https://www.notion.so/6-TREE-afd35100204f4bb19a0ff9fe7b87558b
#include <bits/stdc++.h>

using namespace std;

int n;

class Node {
  public:  
    int pt;
    int nchild;
    vector<int> Ad;
};

Node C[100005];

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

double dfs2(int nd){
  int i,s;
  double retv = 0;
  s= C[nd].Ad.size();

  if(C[nd].nchild == 0) return 0.0;

  for(i =0; i < s; i++){
    if(C[nd].Ad[i] != C[nd].pt){
      retv += dfs2(C[nd].Ad[i]) + 1;
    }
  }

  return retv/C[nd].nchild;

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin >> n;
  int x,y;
  double ans;
  for(int i = 1; i<n; i++){
    cin>> x >> y;
    C[x].Ad.push_back(y);
    C[y].Ad.push_back(x);
  }
  dfs1(1,0);
  ans = dfs2(1);
  printf("%f\n",ans);
  return 0;
}