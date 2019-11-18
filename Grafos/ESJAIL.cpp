//BFS com Bitmask
#include <bits/stdc++.h>
#define pb push_back
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    while(cin >> n >> k >> m, n != -1 || m != -1 || k != -1){
        vector<int> key_needed_by(n+1);
        vector<int> room_opened_by(n+1);
        for(int i = 0; i < k; ++i){
            int u, v; cin >> u >> v;
            room_opened_by[u] = v;
            key_needed_by[v] = u;
        }//Quem nao precisa de chave, precisa da chave 0
        vector<int> adj[n+1];
        while(m--){
            int u, v; cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<bool> is_acquired(n+1), is_reachable(n+1);
        is_acquired[0] = is_acquired[1] = true;
        queue<int> fila;
        fila.push(1);
        while(!fila.empty()){
            int x = fila.front(); fila.pop();
            for(int v : adj[x]){
                if(!is_acquired[v]){
                    if(!is_acquired[key_needed_by[v]])
                        is_reachable[v] = true;
                    else{
                        is_acquired[v] = true;
                        fila.push(v);
                        if(is_reachable[room_opened_by[v]])
                            fila.push(room_opened_by[v]);
                    }               
                }
            }
        }
        cout << (is_acquired[n]?'Y':'N') << '\n';
    }
}
