//https://www.acmicpc.net/problem/7576
#include <bits/stdc++.h>

using namespace std;

int board[1002][1002];
int dist[1002][1002];

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int,int>> qq;

int main(){

  ios_base::sync_with_stdio(false);
  
  int n , m;
  cin >> m >> n;  

  for(int i = 1; i <= n; i++){ //y
    for(int j = 1; j <= m; j++){ //x
       int c;
       cin >> c;
       board[i][j] = c;
       if(c == 1) qq.push({i,j});
       if(c == 0) dist[i][j] = -1;
    }
  }

  while(!qq.empty()){
      int cy = qq.front().first;
      int cx = qq.front().second;
      qq.pop();
      for(int i=0; i<4; i++){
        int ny = cy + dy[i];
        int nx = cx + dx[i];

        if(ny < 1 || ny > n || nx < 1 || nx > m) continue;
        if(dist[ny][nx] >= 0) continue;
        
        dist[ny][nx] = dist[cy][cx]+1;
        qq.push({ny,nx});
      }
  }
  int ans = 0;

  for(int i = 1; i<=n;i++){
    for(int j = 1 ;j <= m; j++){
      if(dist[i][j] == -1){cout << -1 <<"\n"; return 0;}
      ans = max(ans, dist[i][j]);
    }
  }


  cout << ans;

  return 0;
}
