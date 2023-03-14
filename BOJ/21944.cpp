//문제 추천 시스템 version2
//https://www.acmicpc.net/problem/21944
//set 원소로 pair 넣을 경우 에러 발생 가능성이 높음.

#include <bits/stdc++.h>

using namespace std;

set<int> ss[101][101]; // [g][l]
set<int> sss[101]; // [l]
pair<int,int> ff[100001];

int main(){

  int n , m;
  cin >> n;
  for(int i = 0; i < n; i++){
    int p , l,g;
    cin >> p>>l>>g;
    ff[p] = {l,g};
    ss[g][l].insert(p);
    sss[l].insert(p);
  }
  cin >>m;
  while(m--){
    string cmd;
    int p,l,g;
    cin >> cmd;
    if(cmd == "add"){
      cin >> p >> l >>g;
      ff[p] = {l,g};
      ss[g][l].insert(p);
      sss[l].insert(p);
    }else if(cmd == "solved"){
      cin >> p;
      l = ff[p].first;
      g = ff[p].second;
      ss[g][l].erase(p);
      sss[l].erase(p);
    }else if(cmd == "recommend"){
      cin >> g>>p;
      if(p == 1){
        for(int i =100;i>0;i--){
          if(ss[g][i].empty()) continue;
          else {cout << *(prev(ss[g][i].end())) <<"\n"; break;}
        }
      }else{
        for(int i =1;i<101;i++){
          if(ss[g][i].empty()) continue;
          else {cout << *(ss[g][i].begin()) <<"\n"; break;}
        }
      }
    }else if(cmd == "recommend2"){
      cin >> p;
      if(p == 1){
        for(int i = 100;i>0;i--){
          if(sss[i].empty()) continue;
          else {cout << *(prev(sss[i].end())) <<"\n"; break;}
        }
      }else{
        for(int i =1;i<101;i++){
          if(sss[i].empty()) continue;
          else {cout << *(sss[i].begin()) <<"\n"; break;}
        }
      }
    }else{
      cin >> p >> l;
      bool flag = 0 ;
      if( p == 1){
        for(int i =l; i<=100;i++){
          if(sss[i].empty()) continue;
          else {flag = 1; cout << *(sss[i].begin()) <<"\n"; break;}
        }
        if(!flag) cout << -1 <<"\n";
      }
      else{
        for(int i = l-1 ; i> 0 ; i--){
          if(sss[i].empty()) continue;
          else {
            flag = 1;
            cout << *(prev(sss[i].end())) <<"\n";
            break;
          }
        }
        if(!flag) cout << -1 <<"\n";
      }
    }

  }


  return 0;
}