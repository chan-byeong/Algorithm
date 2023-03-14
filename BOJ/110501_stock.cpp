#include <bits/stdc++.h>

using namespace std;

int main(){

  int t;
  cin >> t;
  while (t--)
  {
    int day;
    cin >> day;
    vector<int> v(day+1);
    for(int i=0; i<day;i++){
      cin >>v[i];
    }

   for(int& e : v)
    cout << e <<" ";
    
  }

  
  return 0;
}