//Elements belonging to any LIS
//https://www.spoj.com/problems/SUPPER/
//https://stackoverflow.com/questions/45067878/how-to-check-whether-each-element-is-in-any-longest-increasing-subsequence-of-an
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int nteste = 10;
    while(nteste--){
        int n; cin >> n;
        vector<int> vet(n), size_lis_ending_in(n), size_lis_starting_at(n), dp;
        for(int &x : vet)
            cin >> x;
        for(int i = 0; i < n; ++i){
            int x = vet[i];
            if(dp.empty() || x > dp.back()){
                dp.push_back(x);
                size_lis_ending_in[i] = dp.size();
            }
            else{
                auto it = lower_bound(dp.begin(), dp.end(), x);
                *it = x;
                size_lis_ending_in[i] = it-dp.begin() + 1;

            }
        }
        dp.clear();
        for(int i = n-1; i >= 0; --i){
            int x = -vet[i];
            if(dp.empty() || x > dp.back()){
                dp.push_back(x);
                size_lis_starting_at[i] = dp.size();
            }
            else{
                auto it = lower_bound(dp.begin(), dp.end(), x);
                *it = x;
                size_lis_starting_at[i] = it-dp.begin() + 1;

            }
        }
        set<int> supper;
        for(int i = 0; i < n; ++i){
            if(size_lis_ending_in[i] + size_lis_starting_at[i] - 1 == dp.size())
                supper.insert(vet[i]);
        }
        cout << supper.size() << '\n';
        for(int x : supper)
            cout << x << ' ';
        cout << '\n';
    }
}
