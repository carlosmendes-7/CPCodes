//LCS Top-Down
//https://www.spoj.com/problems/EELCS/
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int dp[7][7];
string s1, s2;
 
int lcs(int x, int y){
    if(x == -1 || y == -1)
        return 0;
    if(dp[x][y] != -1)
        return dp[x][y];
    int resp = LLONG_MAX;
    if(s1[x] == s2[y])
        resp = 1 + lcs(x-1, y-1);
    else
        resp = max(lcs(x-1, y), lcs(x, y-1));
    return dp[x][y] = resp;
}
 
int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> s1 >> s2;
	for(int i = 0; i < 7; ++i)
	    for(int j = 0; j < 7; ++j)
	        dp[i][j] = -1;
	cout << lcs((int)s1.size()-1, (int)s2.size()-1) << '\n';
} 