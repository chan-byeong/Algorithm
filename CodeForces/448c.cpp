//http://codeforces.com/problemset/problem/448/C
#include <bits/stdc++.h>

using namespace std;

int a[5001];
int n ;

int f(int a[] , int n){
  int mn = 1000000005,ans;
  for(int i=0; i <n; i++){
    mn = min(mn,a[i]);
  }
  for(int i=0; i < n; i++){
    a[i] -= mn;
  }
  ans = mn;
  int p = 0,q;
  while(p < n){
    while(p<n && a[p] == 0) p++;
    if(p == n) break;
    q=p;
    while(q+1 < n && a[q+1] > 0) q++;
    ans += f(a+p , q-p+1);
  }

  return min(ans, n);
}

int main(){
  int minb = 0;
  cin >> n;
  for(int i = 0; i< n;i++){
    cin >> a[i];
  }

  cout << f(a,n) <<"\n";

  return 0;
}