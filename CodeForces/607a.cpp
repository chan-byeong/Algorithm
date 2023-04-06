//https://codeforces.com/problemset/problem/607/A
#include <bits/stdc++.h>

#define pp pair<int,int>

using namespace std;


int main(){
  int n , ans;
  cin >> n;

  vector<pair<int,int>> a(n+1);
  int dp[2][100005];

  for(int i = 0; i < n; i++){
    cin >> a[i].first >> a[i].second;
  }

  sort(a.begin(), a.end(),[](pp a , pp b){return a.first > b.first;});

  int cnt1 = 1 , cnt2 = 0;

  //rightest destroyed
  for(int i = 1; i < n; i++){
    int range = a[i].first - a[i].second;
    int tcnt = 0;
    for(int j = i+1; j < n ; j++){
      if(a[j].first >= range){ tcnt++; }
    }
    i+=tcnt;
    cnt1 += tcnt;
  }

  //rightest activated
  for(int i = 0; i < n; i++){
    int range = a[i].first - a[i].second;
    int tcnt = 0;
    for(int j = i+1; j < n ; j++){
      if(a[j].first >= range){ tcnt++; }
    }
    i += tcnt;
    cnt2 += tcnt;
  }

  ans = min(cnt1,cnt2);
  
  cout << ans << "\n";

  return 0;
}

/*
test case
4
1 9
3 1
6 1
7 4

7,4 6,1 3,1 1,9

7-4<= ? <= 7-1
*/