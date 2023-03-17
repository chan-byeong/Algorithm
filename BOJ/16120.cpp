//https://www.acmicpc.net/problem/16120
//문자열 순회하면서 PPAP 순서대로 있으면 P로 바꾼다.
//스택을 활용해서 스택에 PPAP 순서로 쌓이면 POP 해주고, P를 PUSH 한다.
//만약 PPAP 문자열이면 스택에는 P만 남는다.
#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);

  string str;
  int pcnt = 0;
  bool flag = false;
  cin >> str;

  int l = str.length();
  
  stack<char> ss;
  for(int i=0; i<l; i++) {
    if(str[i] == 'P'){
      if(!ss.empty() && ss.top() == 'A'){
        if(flag){ ss.pop(); ss.pop(); ss.pop(); pcnt-=2;}
        ss.push(str[i]); 
        pcnt++;
      }
      else{
        ss.push(str[i]);
        pcnt++;
      }
    }
    else if(str[i] == 'A'){
      ss.push(str[i]);
      if(pcnt >= 2){ flag = true; }
      else flag = false;
    }
  }
  
  //while(!ss.empty()){ cout << ss.top() <<" ";ss.pop();};

  if(ss.top() == 'P' && ss.size() == 1) cout <<"PPAP"<<"\n";
  else cout <<"NP"<<"\n";

  return 0;
}