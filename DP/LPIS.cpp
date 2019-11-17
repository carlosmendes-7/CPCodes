//LPIS
//https://www.spoj.com/problems/LPIS/
#include <bits/stdc++.h>
using namespace std;
 
int lpis[1000001];
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, maior = 0;
    cin >> n;
    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        maior = max(lpis[x] = lpis[x-1]+1, maior);
    }
    cout << maior << '\n';
} 