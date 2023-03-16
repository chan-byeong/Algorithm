//https://www.acmicpc.net/problem/11003
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  
  int n,l;
  cin >>n >>l;

  vector<int> a(n+1);
  multiset<int> ms;

  for(int i=1;i<=n;i++){
    cin >> a[i];
  }

  int en = 1;
  int cntl = 1;
  for(int st = 1; st <=n; st++){
    // if(cntl <= l && en <= n){
    //   cntl++;
    //   ms.insert(a[en]);
    //   en++;
    // }
      
    while(cntl <= l && en <= n){
      cntl++;
      ms.insert(a[en]);
      en++;

      cout << *ms.begin() <<" ";
    }

    if(cntl > l){
      ms.erase(ms.find(a[st]));
      cntl--;
    }
  }


  return 0;
}