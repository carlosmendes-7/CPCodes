//Edit Distance Top-Down
//https://www.spoj.com/problems/EDIST/
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int dp[2001][2001];
string s1, s2;
 
int lcs(int x, int y){
    if(x == -1 || y == -1)
        return abs(y-x);
    if(dp[x][y] != -1)
        return dp[x][y];
    int resp = LLONG_MAX;
    if(s1[x] == s2[y])
        resp = lcs(x-1, y-1);
    else
        resp = 1 + min(lcs(x-1, y), min(lcs(x, y-1), lcs(x-1, y-1)));
    return dp[x][y] = resp;
}
 
int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while(t--){
	    cin >> s1 >> s2;
	    for(int i = 0; i < 2001; ++i)
	        for(int j = 0; j < 2001; ++j)
	            dp[i][j] = -1;
	    cout << lcs((int)s1.size()-1, (int)s2.size()-1) << '\n';
	}
} 