//https://www.acmicpc.net/problem/11003
#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,l;
  cin >>n >>l;

  vector<int> a(n+1);
  //multiset<int> ms;
  deque<int> dq;

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
      //ms.insert(a[en]);
      while(!dq.empty() && dq.back() > a[en]){
        dq.pop_back();
      }
      dq.push_back(a[en]);
      en++;
      cout << dq.front() <<" ";
      //cout << *ms.begin() <<" ";
    }

    if(cntl > l){
      //ms.erase(ms.find(a[st])); //O(logn^2)
      if(dq.front() == a[st]) dq.pop_front();
      cntl--;
    }
  }


  return 0;
}