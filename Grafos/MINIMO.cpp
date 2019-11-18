//Floyd-Warshall
#include <bits/stdc++.h>
#define int long long
using namespace std;
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int n, m, ninst = 0;
    while(cin >> n >> m){
        cout << "Instancia " << ++ninst << '\n';
        vector<vector<vector<int>>> mat(n+1, vector<vector<int>>(n+1, vector<int>(n+1, LLONG_MAX)));
        while(m--){
            int u, v, p;
            cin >> u >> v >> p;
            mat[0][u][v] = min(p, mat[0][u][v]);
        }
        for(int k = 0; k <= n; ++k)
            for(int j = 1; j <= n; ++j)
                mat[k][j][j] = 0;
        for(int t = 1; t <= n; ++t){
            mat[t] = mat[t-1];
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    if(mat[t][i][t] != LLONG_MAX && mat[t][t][j] != LLONG_MAX)
                        mat[t][i][j] = min(mat[t][i][j], mat[t-1][i][t]+mat[t-1][t][j]);
                }
            }
        }
        int cons;
        cin >> cons;
        while(cons--){
            int u, v, t;
            cin >> u >> v >> t;
            cout << (mat[t][u][v] == LLONG_MAX ? -1 : mat[t][u][v]) << '\n';
        }
        cout << '\n';
    }
}
