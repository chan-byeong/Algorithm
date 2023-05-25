//https://www.acmicpc.net/problem/11403
#include <bits/stdc++.h>

using namespace std;

int n;

int graph[101][101];
int vis[101];

int dfs(int nd, int tg){
  fill(vis,vis+n+1,0);
  stack<int> st;
  st.push(nd);

  while (!st.empty())
  {
    int cur = st.top();
    st.pop();
    
    if(vis[cur]) continue;
    if(cur != nd) vis[cur] = 1;

    for(int nxt = 0; nxt < n; nxt++){
      if(vis[nxt]) continue;
      if(graph[cur][nxt]){
        if(nxt == tg) return 1;
        st.push(nxt);
      }
    }

  }
  return 0;
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