
//https://www.spoj.com/problems/EDDIST/
//https://github.com/marioyc/Online-Judge-Solutions/blob/master/SPOJ/Classical/7103%20-%20Edit%20Distance.cpp
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int K,L;
    string s;
    while(true){
        cin >> K;
        if(K == -1) break;
        
        cin >> s;
        L = s.size();
        
        int cont = 0;
        for(int i = 0;i < L;++i)
            if(s[i] != 'a') ++cont;
        
        if(cont <= K){
            K -= cont;
            
            if(K >= L-cont) cout << endl;
            else cout << string(L-cont-K,'a') << endl;
        }else{
            string ans = s;
            
            for(int ins = 0;ins <= K;++ins){
                string aux = s;
                
                for(int i = 0,j = 0;i < L && j < K-ins;++i){
                    if(aux[i] != 'a'){
                        aux[i] = 'a';
                        ++j;
                    }
                }
                
                if(ins > 0) aux = string(ins,'a') + aux;
                ans = min(ans,aux);
            }
            
            cout << ans << endl;
        }
    }
} 
