//https://codeforces.com/problemset/problem/706/C
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);

  ll n , len,ans = 9999;

  cin >> n;

  vector<ll> c(n+1);

  vector<string> a(n+1);
  vector<string> r(n+1);

  vector<ll> co(n+1);
  vector<ll> cr(n+1);

  for(int i = 1; i <= n; i++)
    cin >> c[i];

  for(int i=1; i <= n; i++){
    string str;
    cin >> str;
    a[i] = str;
    r[i] = str;
    reverse(r[i].begin(), r[i].end());

    co[i] = 100000000000001;
    cr[i] = 100000000000001;
  }
  co[0] = 0 ; cr[0] = 0;
  for(int i = 1; i <= n; i++){
    int flag = 0;

    if(strcmp(a[i].c_str(),a[i-1].c_str()) >= 0 ){ flag++; co[i] = co[i-1]; }    //origin - origin
    
    if(strcmp(a[i].c_str(),r[i-1].c_str()) >= 0 ){ flag++; co[i] = min(co[i],cr[i-1]);}

    if(strcmp(r[i].c_str(),a[i-1].c_str()) >= 0 ){ flag++; cr[i] = co[i-1] + c[i];}
     
    if(strcmp(r[i].c_str(),r[i-1].c_str()) >= 0 ){ flag++; cr[i] = min(cr[i],cr[i-1] + c[i]); }

    if(flag <= 0) { cout << -1 <<"\n"; return 0;}
  }
  ans = min(co[n] , cr[n]);
  if(ans == 100000000000001 ) cout << -1 <<"\n";
  else{
    cout << ans << "\n";
  }


  return 0;
}