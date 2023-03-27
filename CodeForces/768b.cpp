//https://codeforces.com/problemset/problem/768/b
#include <bits/stdc++.h>

using namespace std;

long long f(long long n ,long long l,long long r){ //구간 합 return
  long long nn, mid , len;
  nn = n/2; 
  len = 1;
  while (nn > 0)
  {
    len = len*2 +1 ; 
    nn = nn/2;
  }
  mid = (len+1)/2;
  if(l == 1 && r == len) return n;
  if(l > mid) return f(n/2,l-mid,r-mid);
  if(r < mid) return f(n/2,l,r);
  if(l == mid && r == mid) return n%2;
  if(l == mid) return f(n/2, 1 , r-mid) + n%2;
  if(r ==mid) return f(n/2, l, mid-1)+n%2;

  return f(n/2, l , mid-1) + f(n/2,1, r - mid) + n%2;
}

int main()
{
  long long n , l , r;
  cin >> n >> l >> r ;

  cout << f(n,l,r) <<"\n";
  
  return 0;
}