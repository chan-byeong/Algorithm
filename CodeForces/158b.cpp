//https://codeforces.com/problemset/problem/158/B
//Greedy

#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n ,c1=0,c2=0,c3=0,c4=0,cnt = 0;
  cin >> n;

  for(int i = 0;i<n;i++){
    int tmp;
    cin >> tmp;
    if(tmp  == 1) c1++;
    else if(tmp == 2) c2++;
    else if(tmp == 3) c3++;
    else c4++;
  }

  cnt += c4;
  cnt += c3;
  c1 -= min(c3,c1);
  cnt += c2/2;
  c2 -= (c2/2)*2; //짝수면 0 이고 홀수면 1이된다.
  if(c2 == 1){
    cnt++; c1-= min(2,c1);
  }
  cnt += c1/4;
  c1 -= (c1/4)*4;
  if(c1 > 0 ) cnt++;

  cout << cnt <<"\n";

  return 0;
}