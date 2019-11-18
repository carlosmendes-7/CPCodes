//TopoSort
#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
 
typedef pair<int, int> ii;
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int cases, ncase = 0;
    cin >> cases;
    while(cases--){
        cout << "Scenario #" << ++ncase << ":\n\n";
	    int v, e;
	    cin >> v >> e;
	    vector<int> adj[v];
	    vector<int> indegree(v);
	    while(e--){
	        int v1, v2;
	        cin >> v2 >> v1;
	        adj[v1].push_back(v2);
	        ++indegree[v2];
	    }
	    int rank = 1;
        queue<int> pq;
        vector<ii> resp;
	    for(int i = 0; i < v; ++i) 
	        if( !indegree[i] ){
	            pq.push(i);
	            pq.push(rank);
	        }
	    while(!pq.empty()){
	        int u = pq.front(); pq.pop();
	        rank = pq.front(); pq.pop();
	        resp.push_back({rank, u});
	        for(int x : adj[u]){
	            indegree[x]--;
	            if(indegree[x] == 0){
	                pq.push(x);
	                pq.push(rank+1);
	            }
	        }
	    }
	    sort(resp.begin(), resp.end());
	    for(ii x : resp) cout << x.ff << ' ' << x.ss << "\n\n";
	} 
}  
