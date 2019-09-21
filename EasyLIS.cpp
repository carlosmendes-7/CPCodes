//LIS
//https://www.spoj.com/problems/ELIS/
#include <bits/stdc++.h>
using namespace std;
 
int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    vector<int> dp;
    int n, x;
    cin >> n >> x;
    dp.push_back(x);
    for(int i = 1; i < n; ++i){
        cin >> x;
        if(x > dp.back())
            dp.push_back(x);
        else
            *lower_bound(dp.begin(), dp.end(), x) = x;
    }
    cout << dp.size() << '\n';
} 
