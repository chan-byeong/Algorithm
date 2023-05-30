//https://www.acmicpc.net/problem/1707
#include <bits/stdc++.h>

using namespace std;

int vis[20001];
int rb[20001];


int main()
{
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while(t--)  
  { 
    vector<int> edge[20001];
    queue<int> q;

    int n ,k ;
    cin >> n >> k;

    fill(vis,vis+n+1,0);
    fill(rb,rb+n+1,0);

    for(int i=0;i<k;i++){
      int t1,t2;
      cin >> t1 >> t2;
      edge[t1].push_back(t2);
      edge[t2].push_back(t1);
    }
    int flag = 0;
    q.push(1);
    rb[1] = 0;

    while(!q.empty()){
      int cur = q.front();
      q.pop();
      vis[cur] = 1;
 
      for(int i=0; i < edge[cur].size(); i++){
        int nxt = edge[cur][i];
        //cout << cur << " : " << rb[cur] <<" , "<<nxt<<" : " <<rb[nxt]<<"\n";
        if(vis[nxt] == 1 && rb[cur] == rb[nxt]){flag = 1; break;}
        if(vis[nxt] == 1) continue;
        rb[nxt] = ( rb[cur] +1 )%2;
        //if(vis[nxt] == 1) {flag = 1; break;}
        //if(vis[nxt] == 1) continue;
        vis[nxt] = 1;
        q.push(nxt);
      }

      if(flag) break;
      else if(q.empty()){
        int i ;
        for(i = 1; i <= n; i++){
          if(vis[i] == 0) break;
        }
        if(i  != n+1) q.push(i);
      }
    }

    if(flag) cout << "NO" <<"\n";
    else cout <<"YES" <<"\n";

  }

  return 0;
}