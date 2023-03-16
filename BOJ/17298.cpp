#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin >> n;
  stack<int> ss;
  stack<int> ans;
  vector<int> a(n+1);
  for(int i =0 ;i<n;i++)
    cin >> a[i];

  for(int i=n-1 ; i>=0;i--){

    while(!ss.empty() && ss.top() <= a[i]){
      ss.pop();
    }
    if(ss.empty()){
      ans.push(-1);
      ss.push(a[i]);
    }
    else{
      // cout << ss.top() <<" ";
      ans.push(ss.top());
      ss.push(a[i]);
    }
  
  }

  while(!ans.empty()){
    cout << ans.top() <<" ";
    ans.pop();
  }
  
  return 0;
}
/*
  어떻게 하면 O(n)에 풀 수 있을까용?
  왼쪽부터가 아닌 오른쪽부터 본다. 이때 뭘 쓰면될까?
  우리는 오큰수가 되는 후보들만 기억하면 된다. 
*/