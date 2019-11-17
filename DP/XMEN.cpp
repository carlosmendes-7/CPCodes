//Reducing LCS to LIS
//https://www.spoj.com/problems/XMEN/
//Leia https://stackoverflow.com/questions/34656050/reducing-longest-common-subsequence-to-longest-increasing-subsequence
#include <bits/stdc++.h>
using namespace std;
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int nteste;
    cin >> nteste;
    while(nteste--){
        int n;
        cin >> n;
        vector<int> s3(n+1), posicao_em_s1(n+1), dp;
        int x;
        for(int i = 1; i <= n; ++i){ //recebe s1
            cin >> x;
            posicao_em_s1[x] = i;
        }
        for(int i = 1; i <= n; ++i){ //recebe s2
            cin >> x;
            s3[i] = posicao_em_s1[x];
        }
        dp.push_back(s3[1]);
        for(int i = 2; i <= n; ++i){
            if(s3[i] > dp.back())
                dp.push_back(s3[i]);
            else
                *lower_bound(dp.begin(), dp.end(), s3[i]) = s3[i];
        }
        cout << dp.size() << '\n';
    }
} 
