//https://www.acmicpc.net/problem/2065
#include <bits/stdc++.h>

using namespace std;

int main(){
  int m,t,n;
  queue<int> q1;
  queue<int> q2;

  int ans[10001];
  
  cin >> m >> t >> n ;

  for(int i=0;i<n;i++){
    int tt;
    string str;
    cin >> tt >>str;
    if(str =="left"){
      q1.push(tt);
    }
    else{
      q2.push(tt);
    }
  }

  int time = 0 , boat = 0; //0 : left , 1 : right

  while(!q1.empty() || !q2.empty()){
    int p = 0;
    int flag = 0;
    if(!q1.empty() && q1.front() <= time){
      flag = 1;
      boat == 0 ? time += 0 : time += t;
      boat = 0;
      while(!q1.empty() && q1.front() <= time && p < m){
        p++;
        cout << time + t <<"\n";
        q1.pop();
      }
      time += t;
      boat = 1;
    }
    p = 0;
    if(!q2.empty() && q2.front() <= time){
      flag = 1;
      boat == 1 ? time += 0 : time += t;
      boat = 1;
      while(!q2.empty() && q2.front() <= time && p < m){
        p++;
        cout << time + t <<"\n";
        q2.pop();
      }
      time += t;
      boat = 0; 
    }

    if(flag == 0) time++;

  }

  return 0;
}
