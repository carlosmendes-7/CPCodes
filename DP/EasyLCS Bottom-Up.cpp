//LCS Bottom-Up
//https://www.spoj.com/problems/EELCS/
#include <bits/stdc++.h>
using namespace std;
 
int main(){
	string a, b;
	ios_base::sync_with_stdio(false);
	cin >> a >> b;
	vector<vector<int>> mat(a.size()+1, vector<int>(b.size()+1));
	for(int i = 1; i <= a.size(); ++i){
	    for(int j = 1; j <= b.size(); ++j){
	        if(a[i-1] == b[j-1]){
	            mat[i][j] = mat[i-1][j-1] + 1;
	        }
	        else mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
	    }
	}
	cout << mat[a.size()][b.size()] << '\n';
} 