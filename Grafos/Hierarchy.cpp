#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> adj[n+1];
    vector<int> indegree(n+1);
    for(int i = 1; i <= m; ++i){
        int x; cin >> x;
        for(int j = 0; j < x; ++j){
            int v; cin >> v;
            adj[i].pb(v);
            ++indegree[v];
        }
    }
    queue<int> fila;
    for(int i = 1; i <= n; ++i){
        if(indegree[i] == 0)
            fila.push(i);
    }
    int idx = 1;
    vector<int> pos(n+1), quem_estah_na_pos(n+1);
    while(!fila.empty()){
        int u = fila.front(); fila.pop();
        pos[u] = idx;
        quem_estah_na_pos[idx++] = u;
        for(int v : adj[u]){
            --indegree[v];
            if(indegree[v] == 0)
                fila.push(v);
        }
    }
    for(int i = 1; i <= n; ++i){
        cout << quem_estah_na_pos[pos[i]-1] << '\n';
    }
}