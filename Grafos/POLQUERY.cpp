#include <bits/stdc++.h>
#define MAXN 100000
#define pb push_back
using namespace std;

int n, m, cont;
vector<int> adj[MAXN+1], filhos[MAXN+1];
int tempo_de_chegada[MAXN+1], menor_alcancavel[MAXN+1], tempo_de_saida[MAXN+1];

void tarjan(int u, int pai){
    tempo_de_chegada[u] = menor_alcancavel[u] = ++cont;
    for(int v : adj[u]){
        if(v == pai) continue;
        
        if(!tempo_de_chegada[v]){ //se v nao foi visitado ainda
            filhos[u].pb(v);
            tarjan(v, u);   
            menor_alcancavel[u] = min(menor_alcancavel[u], menor_alcancavel[v]);
        } 
        else{
            menor_alcancavel[u] = min(menor_alcancavel[u], tempo_de_chegada[v]);
        }
    }
    tempo_de_saida[u] = ++cont;
}

//true se a eh descendente de b
bool eh_descendente(int a, int b){
	return tempo_de_chegada[b] <= tempo_de_chegada[a] && tempo_de_saida[a] <= tempo_de_saida[b];
}

//acha filho de 'u' do qual 'descendente' descende
int acha_filho_ascendente(int u, int descendente){
   int lo = 0, hi = filhos[u].size() - 1;
   while( lo != hi ) {
      int mid = (lo+hi) / 2;
      if( tempo_de_chegada[descendente] > tempo_de_saida[ filhos[u][mid] ] ) lo = mid+1;
      else if( tempo_de_saida[descendente] < tempo_de_chegada[ filhos[u][mid] ] ) hi = mid-1;
      else lo = hi = mid;
   }
   return filhos[u][lo];
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    while(m--){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    tarjan(1, 0);
    
    int nqueries; cin >> nqueries;
    while(nqueries--){
        int tipo; cin >> tipo;
        if(tipo == 1){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            if(eh_descendente(c, d)) swap(c, d); //d vai ser sempre o descendente
            if(menor_alcancavel[d] <= tempo_de_chegada[c]) //(c,d) nao eh ponte
            	cout << "da\n";
            else if(eh_descendente(a, d) == eh_descendente(b, d)) //'a' e 'b' pertencem aa mesma componente
            	cout << "da\n";
            else cout << "ne\n";
        }
        else{
        	int a, b, c;
        	cin >> a >> b >> c;
        	if(!eh_descendente(a, c) && !eh_descendente(b, c)) //'a' e 'b' pertencem aa mesma componente
        		cout << "da\n";
        	else if(eh_descendente(a, c) && eh_descendente(b, c)){
        		int e = acha_filho_ascendente(c, a);
        		int f = acha_filho_ascendente(c, b);
        		if(e == f) //'a' e 'b' pertencem aa mesma componente
        			cout << "da\n";
        		else if(menor_alcancavel[e] < tempo_de_chegada[c] && menor_alcancavel[f] < tempo_de_chegada[c]) //c nao eh PA
        			cout << "da\n";
        		else
        			cout << "ne\n";
        	}
        	else{
        		if(eh_descendente(a, c)) swap(a, b); //b vai ser sempre o descendente
        		int e = acha_filho_ascendente(c, b);
        		if(menor_alcancavel[e] < tempo_de_chegada[c]) //c nao eh PA
        			cout << "da\n";
        		else
        			cout << "ne\n";
        	}
        }
    }
}
