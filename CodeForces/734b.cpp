//https://codeforces.com/problemset/problem/734/B
//Greedy 알고리즘

#include <bits/stdc++.h>

using namespace std;

int main()
{
  long long k2 , k3, k5,k6;
  long long p,q,r,sum=0;

  cin >> k2 >>k3 >>k5>>k6 ;
  
  p = min(k5,k6);
  q = min(p,k2);
  sum = q*256;
  k2 -= q;
  r = min(k2,k3);
  sum += r*32;

  cout <<sum<<"\n";

  return 0;
}