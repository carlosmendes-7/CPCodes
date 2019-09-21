//Palindrome Partitioning
//https://br.spoj.com/problems/PAL/
//cf. https://www.youtube.com/watch?v=WPr1jDh3bUQ
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int n, nteste = 0;
	while(cin >> n, n){
		cout << "Teste " << ++nteste << '\n';
		string x; cin >> x;
		//dp[i][j] true se substr x(i, j) eh palindrome
		vector<vector<bool>> dp(n, vector<bool>(n));
		//single letter palindromes
		for(int i = 0; i < n; ++i)
			dp[i][i] = 1;
		//two letters palindromes
		for(int i = 0; i < n-1; ++i)
			if(x[i] == x[i+1])
				dp[i][i+1] = 1;
		//palindromes of size 3 to n
		for(int wsize = 3; wsize <= n; ++wsize){
			for(int i = 0; i <= n - wsize; ++i){
				int j = i + wsize - 1;
				if(x[i] == x[j] && dp[i+1][j-1]){
					dp[i][j] = 1;
				}
			}
		}
		//c[i] guarda o menor número de partes em que a substring x(0, i)
		//pode ser dividida de forma que todas as partes sejam palíndromes
		vector<int> c(n, LLONG_MAX);
		for(int i = 0; i < n; ++i){
			if(dp[0][i]){
				c[i] = 1;
			}
			else{
				for(int k = 0; k < i; ++k){
					if(dp[k+1][i] && c[i] > c[k]+1)
						c[i] = c[k]+1;
				}
			}
		}
		cout << c[n-1] << "\n\n";
	}
}