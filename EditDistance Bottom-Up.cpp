//Edit Distance Bottom-Up
//https://www.spoj.com/problems/EDIST/
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	ios_base::sync_with_stdio(false);
	cin >> n;
	while(n--){
	    string a, b;
	    cin >> a >> b;
	    vector<vector<int> > mat(a.size()+1, vector<int>(b.size()+1));
	    for(int i = 1; i <= a.size(); ++i){
	        mat[i][0] = i;
	    }
	    for(int i = 1; i <= b.size(); ++i){
	        mat[0][i] = i;
	    }
	    for(int i = 1; i <= a.size(); ++i){
	        for(int j = 1; j <= b.size(); ++j){
	            if(a[i-1] == b[j-1]){
	                mat[i][j] = mat[i-1][j-1];
	            }
	            else mat[i][j] = min(mat[i-1][j-1], min(mat[i][j-1], mat[i-1][j])) + 1;
	        }
	    }
	    cout << mat[a.size()][b.size()] << '\n';
	}
} 