//DP with Bitmask
//https://www.spoj.com/problems/ASSIGN/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
vector<vector<int>> adj(21);
int dp[(1ULL << 20)];

int assign(int s, unsigned int a){
	if(s == n)
		return 1;
	if(dp[a] >= 0)
		return dp[a];
	int resp = 0;
	for(int x : adj[s])
		if(!(a & (1ULL << x))) //if xth bit is not set
			resp += assign(s+1, a | (1ULL << x));
	return dp[a] = resp;
}


int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int nteste;
	cin >> nteste;
	while(nteste--){
		cin >> n;
		for(vector<int> & vet : adj)
			vet.clear();
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				bool x; cin >> x;
				if(x) adj[i].push_back(j);
			}
		}
		int lim = (1ULL << n);
		for(int i = 0; i < lim; ++i)
			dp[i] = -1;
		cout << assign(0, 0) << '\n';
	}


}