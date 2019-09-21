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
/*Ada has some coins in her wallet. She is wondering, how many different values is she able to make in a given range?
A value is a sum of some subset of coins.

Input
The first line contains two integer numbers 1 ≤ N ≤ 104, 1 ≤ Q ≤ 5*105, the number of coins and number of queries.

The next line contains N integer numbers 1 ≤ Ai ≤ 105, the values of coins in Ada's wallet.

Afterward, Q lines follow, each containing two integers 1 ≤ B ≤ E ≤ 105, beginning and end of range, for which
 ada wants to know the answer

Output
For each query, output the number of distinct values Ada can generate in given range.*/