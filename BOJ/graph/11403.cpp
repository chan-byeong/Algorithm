//https://www.acmicpc.net/problem/11403
#include <bits/stdc++.h>

using namespace std;

int n;

int graph[101][101];
int vis[101];

int dfs(int i, int j){
  int res = 0;
  vis[i] = 1;
  for(int p = 0; p < n; p++){
    if(graph[i][p] == 0) continue;
    if(p == j){res = 1; break;}
    if(vis[p] == 1) continue;
    res = dfs(p,j);
    if(res == 1) break;
  }
  vis[i] = 0;
  return res;
}


int main(){
  ios_base::sync_with_stdio(false);
   int i , j;
   cin >> n;

   for(i = 0; i< n;i++){
    for(j=0;j<n;j++){
      cin >>graph[i][j];
    }
   }

   for(i = 0; i< n;i++){
    for(j=0;j<n;j++){
      cout <<dfs(i,j) <<" ";
    }
    cout << "\n";
   }

  return 0;
}