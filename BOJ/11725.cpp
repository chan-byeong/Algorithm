//tree 연습문제
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n;

  cin >> n;

  vector<int> adj[100001];
  int p[100001];

  queue<int> q;

  for(int i=1; i<n; i++){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  q.push(1);

  while(!q.empty()){
    int cur = q.front();
    q.pop();

    // for(int i = 0; i < adj[cur].size(); i++){
    //   int nxt = adj[cur][i];
    //   if(nxt == p[cur]) {continue;}
    //   q.push(nxt);
    //   p[nxt] = cur;
    // }

    for(int nxt : adj[cur]){
      if(nxt == p[cur]) {continue;}
      q.push(nxt);
      p[nxt] = cur;
    }

  }

  for(int i =2; i <=n; i++)
    cout << p[i] <<"\n";
  

  return 0;
}