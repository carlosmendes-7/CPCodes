#include <bits/stdc++.h>
#define pb push_back
using namespace std;

vector<int> adj[1000001];
bool vis[1000001];
int diam = 0;
int v2 = 1;

void dfs(int n, int dist){
	vis[n] = 1;
	if(dist > diam){
		diam = dist;
		v2 = n;
	}
	for(int u : adj[n]){
		if(!vis[u]){
			dfs(u, dist+1);
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int u, v; cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1, 0);
	memset(vis+1, 0, n*sizeof(bool));
	diam = 0;
	dfs(v2, 0);
	cout << diam << '\n';
}