#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef pair<string, string> pss;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int nteste = 0, m;
	while(cin >> m, m){
		map<pss, int> mapa;
		vector<int> adj[100];
		int indice = 0;
		cin.ignore();
		while(m--){
			string linha, nome, sobrenome;
			getline(cin, linha);
			vector<int> autores;
			bool ehNome = 1;
			for(int i = 0; i < linha.size(); ++i){
				char c = linha[i];
				if(c == ',' || i == linha.size() - 1){
					pss par(sobrenome, nome);
					if(!mapa.count(par))
						mapa[par] = indice++;
					autores.pb(mapa[par]);
					nome.clear();
					sobrenome.clear();
				}
				else if(c == ' ')
					ehNome ^= 1;
				else{
					if(ehNome) nome += c;
					else sobrenome += c;
				}
			}
			for(int i = 0; i < autores.size(); ++i)
				for(int j = 0; j < autores.size(); ++j){
					if(i == j) continue;
					adj[autores[i]].pb(autores[j]);
					adj[autores[j]].pb(autores[i]);
				}
		}
		pss origem("Erdos", "P.");
		queue<int> fila;
		vector<int> dist(indice, INT_MAX);
		if(mapa.count(origem)) {
			fila.push(mapa[origem]);
			dist[mapa[origem]] = 0;
		}
		while(!fila.empty()){
			int x = fila.front(); fila.pop();
			for(int v : adj[x]){
				if(dist[v] == INT_MAX){
					dist[v] = dist[x] + 1;
					fila.push(v);
				}
			}
		}
		cout << "Teste " << ++nteste << '\n';
		for(auto x : mapa){
			if(x.first == origem) continue;
			cout << x.first.second << ' ' << x.first.first << ": ";
			if(dist[x.second] == INT_MAX) cout << "infinito\n";
			else cout << dist[x.second] << '\n';
		}
		cout << '\n';
	}
}