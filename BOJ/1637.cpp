//https://www.acmicpc.net/problem/1637 
//날카로운 눈
#include <bits/stdc++.h>

using namespace std;
int n;

long long aa[20001] ,bb[20001],cc[20001];

long long f(int m) {

  long long cnt = 0;

  long long mid = m;

  for(int i =0 ; i < n ; i++){
    if(aa[i] > m) continue;
    else{
      cc[i] > m ? mid = m : mid = cc[i];
      cnt += (mid - aa[i])/bb[i] +1;
    }
  }
  return cnt;
}
//y = bx+a (<= c); 
int main(){

  // a c b;

  long long a,c,b,ans = -1;

  cin >> n;

  for(int i =0 ; i < n; i++){
    cin >> a >> c >> b;
    aa[i] = a;
    cc[i] = c;
    bb[i] = b;
  }

  long long l = 1 , r = 2147483647;

  while( l <= r ) {
    
    long long m = (l+r)/2;

    if(f(m) % 2 == 0){
      l = m + 1 ;
    }
    else {
      r = m - 1;
      ans = m;
    }
  }

  if(ans != -1)
      cout << ans <<" " <<f(ans) - f(ans-1)<<"\n";
    else{
      cout <<"NOTHING"<<"\n";
    }

 /*
 1 2 3 4 5 6 7 8 9 10
 4 
 1 2 3 4 5
 6 7 8 9 10
 */

  return 0;
}