//MST
#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define ff first
#define ss second
using namespace std;
 
typedef long double ld;
typedef pair<int, int> ii;
typedef pair<ld, ii> ldii;
 
int pai[200001];
int tam[200001];
 
void init(int n){
    for(int i = 0; i <= n; ++i){
        pai[i] = i;
        tam[i] = 1;
    }
}
int find(int u){
    if(pai[u] == u) return u;
    return pai[u] = find(pai[u]);
}
void merge(int u, int v){
    int a = find(u);
    int b = find(v);
    if(tam[a] < tam[b])
        swap(a, b);
    pai[b] = a;
    tam[a] += tam[b];
}
int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n, n){
	    vector<pair<ld, ld>> coord(n);
	    for(int i = 0; i < n; ++i)
		cin >> coord[i].ff >> coord[i].ss;
	    vector<ldii> aresta;
	    for(int i = 0; i < n-1; ++i){
		for(int j = i+1; j < n; ++j){
		    ld dist = sqrt( (coord[i].ff-coord[j].ff)*(coord[i].ff-coord[j].ff) +
					    (coord[i].ss-coord[j].ss)*(coord[i].ss-coord[j].ss));
		    aresta.pb(ldii(dist, ii(i, j)));
		}
	    }
	    sort(aresta.begin(), aresta.end());
	    init(n);
	    ld resp = 0;
	    for(int i = 0, cont = 0; i < aresta.size() && cont < n-1; ++i){
		if(find(aresta[i].ss.ff) != find(aresta[i].ss.ss)){
		    merge(aresta[i].ss.ff, aresta[i].ss.ss);
		    ++cont;
		    resp = max(aresta[i].ff, resp);
		}
	    }
	    cout << fixed << setprecision(4) << resp << '\n';
	}
}
