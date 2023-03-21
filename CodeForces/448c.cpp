//http://codeforces.com/problemset/problem/448/C
#include <bits/stdc++.h>

using namespace std;

int main(){
  int n ,  minb = 0;
  cin >> n;
  vector<int> a(n+2);

  for(int i =1 ; i<=n;i++){
    cin >> a[i];
  }

while(true)
{
  int cnt = 0;
  for(int i = 1; i <= n+1; i++){
    if(a[i] > 0) cnt++;
    else{
      if(cnt == 1){
        a[i-1] = 0;
        minb++;
      }
      else if(cnt > 1){
        for(int j = 1; j <= cnt; j++){
          a[i-j] -= 1;
        }
        minb++;
      }
      cnt = 0;
    }
  }

  int sum = 0;
  for(int e : a) {
    sum += e;
  }

  if(sum == 0) break; 
}

  cout << minb <<"\n";

  return 0;
}