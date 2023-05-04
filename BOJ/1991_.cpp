#include <bits/stdc++.h>

using namespace std;

int n;
int lc[30];
int rc[30];

void preorder(int n){
  cout << char(n + 'A' - 1) ;
  if(lc[n] > 0) preorder(lc[n]);
  if(rc[n] > 0) preorder(rc[n]);
}

void inorder(int n){
  if(lc[n] > 0) inorder(lc[n]);
  cout << char(n + 'A' - 1) ;
  if(rc[n] > 0) inorder(rc[n]);
}

void postorder(int n){
  if(lc[n] > 0) postorder(lc[n]);
  if(rc[n] > 0) postorder(rc[n]);
  cout << char(n + 'A' - 1) ;
}

int main(){
  cin >> n;

  for(int i = 1; i<= n; i++){
    char a,b,c;
    cin >> a >> b >> c;
    if(b != '.') lc[a-'A'+1] = b - 'A' + 1;
    if(c != '.') rc[a-'A'+1] = c - 'A' + 1; 
  }

  preorder(1);
  cout << "\n";
  inorder(1);
  cout << "\n";
  postorder(1);

  return 0;
}