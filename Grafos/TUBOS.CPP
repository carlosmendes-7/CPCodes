//Pontes
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
bool tarjan(int u, int pai, vector<int>& tempo_de_visita, vector<int>& menor_alcancavel, vector<int> adj[], int cont){
    tempo_de_visita[u] = menor_alcancavel[u] = ++cont;
    bool resp = false;
    for(int v : adj[u]){
        if(v == pai)
            continue;
        if(!tempo_de_visita[v])
            resp |= tarjan(v, u, tempo_de_visita, menor_alcancavel, adj, cont);
        menor_alcancavel[u] = min(menor_alcancavel[u], menor_alcancavel[v]);
        if(menor_alcancavel[v] > tempo_de_visita[u])
            resp = true;
    }
    return resp;
}
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m;
    while(cin >> n >> m, n||m){
        vector<int> adj[n+1];
        while(m--){
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int> tempo_de_visita(n+1), menor_alcancavel(n+1);
        cout << (!tarjan(1, 0, tempo_de_visita, menor_alcancavel, adj, 0)?'S':'N') << '\n';
    }
}