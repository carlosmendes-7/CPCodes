#include <bits/stdc++.h>
#define ff first
#define ss second
using namespace std;
 
typedef pair<int, int> ii;

int n, m;
char mat[100][100];
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const map<char, int> b{{'b', 0}, {'y', 1}, {'r', 2}, {'g', 3}, {'B', 0}, {'Y', 1}, {'R', 2}, {'G', 3}};
 
bool valid(int i, int j){
    return (i >= 0 && i < n && j >= 0 && j < m && mat[i][j] != '#');
}

bool enterable(char c, int bm){
    return ( !isupper(c) || (bm & (1 << b.at(c))) );
}

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin >> n >> m, n||m){
        cin.ignore();
        int xo, yo;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cin >> mat[i][j];       
                if(mat[i][j] == '*'){
                    xo = i; yo = j;
                }
            }
        }
        vector<vector<vector<long long>>> dist(n, vector<vector<long long>>(m, vector<long long>(16, LLONG_MAX)));
        dist[xo][yo][0] = 0;
        queue<pair<ii, int>> fila;
        fila.push({{xo, yo}, 0});
        long long resp = 0;
        while(!fila.empty() && !resp){
            auto x = fila.front(); fila.pop();
            for(int k = 0; k < 4; ++k){
                int i = x.ff.ff + dx[k];
                int j = x.ff.ss + dy[k];
                if(valid(i,j)){
                    if( mat[i][j] == 'X' ){
                        resp = dist[x.ff.ff][x.ff.ss][x.ss] + 1;
                    } 
                    else if(enterable(mat[i][j], x.ss)){
                        int bm = x.ss;
                        if(islower(mat[i][j])) bm |= (1 << b.at(mat[i][j]));
                        if(dist[i][j][bm] == LLONG_MAX){
                            dist[i][j][bm] = dist[x.ff.ff][x.ff.ss][x.ss] + 1;
                            fila.push({{i,j},bm}); 
                        }
                    }
                }
            }
        }
        if(!resp) cout << "The poor student is trapped!\n";
        else cout << "Escape possible in " << resp << " steps.\n";
    }
}