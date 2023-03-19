//https://www.acmicpc.net/problem/1725
//입력 하나씩 살핀다.
/* size : h*k
  1. a[i] > a[i+1] : 
    1-1. a[i+1] >= h : h * k+1 vs. a[i+1] * 2
    ***1-2. a[i+1] < h : h*k vs. a[i+1] * 해당되는막대개수(>k)
    *** h*k > a[i+1]*i+1 : Pass
    *** else : 0 ~ i+1 까지 min 새로운 h 구한뒤 h * k 비교.???
  2. a[i] =< a[i+1] : 
    2-1. h == a[i] : a[i+1]*1 vs. h * k+1
    2-1. h < a[i] : h * k+1 vs. a[i]*2 vs. a[i+1]*1
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);

  int n , h=0 , k=0 , size=0;
  cin >> n;
  deque<int> dq;

  for(int i =0 ; i < n;i++){
    int tmp;
    cin >> tmp;
    if(dq.empty()){
      h = tmp;
      k++;
    }else{
      if(dq.back() > tmp){
        if(tmp >= h){
          if(h*(k+1) > tmp*2){ k++;}
          else { h = tmp; k = 2; }
          size = h*k;
        }
        else{
          //1-2
          // for(int j = 0;j<i-k-1;j++){
          //   if(dq[j] <= tmp)
          // }
        }
      }else{ //dq.back() =< tmp
        if(h >= dq.back()){
          if(tmp > h*(k+1)){
            h = tmp;
            k=1;
          }
          else{
            k++;
          }
          size= h*k;
        }
        else if(h < dq.back()){
          if(h*(k+1) < tmp && dq.back()*2 < tmp){
            h = tmp;
            k =1;
          }
          else{
            if(h*(k+1) > dq.back()*2){
              k++;
            }
            else{
              h = dq.back();
              k = 2;
            }
          }
          size = h*k;
        }
      }
    }
    cout << size <<"\n";
    dq.push_back(tmp);
  }

  cout << size <<"\n";

  return 0;
}