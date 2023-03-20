//https://codeforces.com/problemset/problem/160/a
//Greedy

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , total = 0;
    cin >> n;
    vector<int> a(n);
    for(int i =0; i < n;i++){
        cin >> a[i];
        total += a[i];
    }
    
    sort(a.begin() , a.end(), greater<int>());
    
    int tmp = 0 ;
    int i;
    for(i =0; i < n; i++){
        tmp += a[i];
        total -= a[i];
        if(tmp > total) break;
    }
    
    cout << i+1 <<"\n";
    
    
    return 0;
}