#include <bits/stdc++.h>

using namespace std;

int main(){

  int n;
  cin >> n;
  vector<int> a(n+1);

  for(int i =1 ;i<=n;i++){
    cin >> a[i];

    if(a[i]%2 == 0){
      if(i%2 != 0) {cout <<"NO"<<"\n"; return 0;}
    }
    else{
      if(i%2 == 0) {cout <<"NO"<<"\n"; return 0;}
    }
  }

  cout <<"YES"<<"\n";

  return 0;
}