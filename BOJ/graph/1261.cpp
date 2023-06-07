//https://www.acmicpc.net/problem/1261

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

class tpl {
  public:
    int w;
    int x;
    int y;

    bool operator < (const tpl &rhs) const {
      return w > rhs.w;
    }
};

int n,m;

int board[105][105];
int d[101][101];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int main(){
  ios::sync_with_stdio(false);

  cin >> n >> m;
  memset(d,INF, sizeof(d));

  for(int i=1 ; i<=m; i++){
    string str;
    cin >> str;
    for(int j = 1; j<=n; j++){
      board[i][j] = str[j-1]-'0';
    }
  }

  priority_queue<tpl> pq;

  tpl tmp;
  tmp.w = 0; tmp.x = 1; tmp.y = 1;
  d[1][1] = 0;
  pq.push(tmp);

  while(!pq.empty()){
    auto cur = pq.top(); pq.pop();
    if(d[cur.y][cur.x] != cur.w) continue;

    for(int i = 0; i < 4; i++){
      int ny = cur.y + dy[i];
      int nx = cur.x + dx[i];

      if(ny > m || nx > n || ny < 1 || nx < 1) continue;
      if(d[ny][nx] <= d[cur.y][cur.x]+board[ny][nx]) continue;
      d[ny][nx] = d[cur.y][cur.x]+board[ny][nx];
      
      tpl tmp;
      tmp.w = d[ny][nx];
      tmp.x = nx;
      tmp.y = ny;
      pq.push(tmp);
    }

    //cout << d[cur.y][cur.x] <<"\n";
  }

  cout << d[m][n] <<"\n";

  return 0;
}