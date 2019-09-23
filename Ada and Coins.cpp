//DP com Bitset
//https://www.spoj.com/problems/ADACOINS/
#include <bits/stdc++.h>
#define int long long
#define MAX 100001
using namespace std;
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    bitset<MAX> dp = 1U;
    int x;
    while(n--){
        cin >> x;
        dp |= dp << x;
    }
    vector<int> soma(MAX);
    for(int i = 1; i < MAX; ++i){
        soma[i] = soma[i-1] + dp[i];
    }
    int l, r;
    while(q--){
        cin >> l >> r;
        cout << soma[r] - soma[l-1] << '\n';
    }
}
