#include <bits/stdc++.h>
#define pb push_back
using namespace std;
 
void tarjan(int u, int pai, vector<int>& tempo_de_visita, vector<int>& menor_alcancavel, vector<int> adj[], int cont, int& filhosDaRaiz, set<int>& resp){
    tempo_de_visita[u] = menor_alcancavel[u] = ++cont;
    for(int v : adj[u]){
        if(v == pai)
            continue;
        if(!tempo_de_visita[v]){
            if(u == 1)//se u eh a raiz da DFS
                ++filhosDaRaiz;
                
            tarjan(v, u, tempo_de_visita, menor_alcancavel, adj, cont, filhosDaRaiz, resp);   
            
            menor_alcancavel[u] = min(menor_alcancavel[u], menor_alcancavel[v]);
            //menor alcancavel por v nao eh ancestral de u, u eh uma articulacao
            if(menor_alcancavel[v] >= tempo_de_visita[u] && u != 1)
                resp.insert(u);
        }
        else{
            menor_alcancavel[u] = min(menor_alcancavel[u], tempo_de_visita[v]);
        }
    }
}
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, nteste = 0;
    while(cin >> n >> m, n||m){
        cout << "Teste " << ++nteste << '\n';
        vector<int> adj[n+1];
        while(m--){
            int u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<int> tempo_de_visita(n+1), menor_alcancavel(n+1);
        int filhosDaRaiz = 0;
        set<int> resp;
        
        tarjan(1, 0, tempo_de_visita, menor_alcancavel, adj, 0, filhosDaRaiz, resp);
        if(filhosDaRaiz > 1) resp.insert(1);
        
        if(resp.empty()) cout << "nenhum\n\n";
        else{
            for(int x : resp){
                cout << x << ' ';
            }
            cout << "\n\n";
        }
    }
}