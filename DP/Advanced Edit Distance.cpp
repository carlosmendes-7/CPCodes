//Damerau–Levenshtein distance
//https://www.spoj.com/problems/ADVEDIST/
#include <bits/stdc++.h>
using namespace std;

string a, b;

int aed(int n, int m){
    
    vector<int> da('z'+1, 1);
    
    int maxdist = n+m;

    vector<vector<int>> d(n+2, vector<int>(m+2, maxdist));

    for(int i = 1; i <= n+1; ++i)
        d[i][1] = i-1;
    for(int i = 1; i <= m+1; ++i)
        d[1][i] = i-1;

    for(int i = 2; i <= n+1; ++i){
        int db = 1;
        for(int j = 2; j <= m+1; ++j){
            int k = da[b[j]];
            int l = db;
            int cost = 1;
            if(a[i] == b[j]){
                cost = 0;
                db = j;
            }
            d[i][j] = min(
                            min( d[i-1][j-1]+cost, d[k-1][l-1] + (i-k-1) + 1 + (j-l-1) ),
                            min( d[i][j-1], d[i-1][j] ) + 1
                        );
        }
        da[a[i]] = i;
    }
    return d[n+1][m+1];
}
    
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> a >> b, a != "*" || b != "*"){
        a = "--" + a;
        b = "--" + b;
        cout << aed(a.size()-2, b.size()-2) << '\n';
    }
}
