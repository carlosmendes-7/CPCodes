//https://www.spoj.com/problems/PSYCHO3/
#include <cstdio>
#include <bitset>
#define MAX 1101
#define KMAX 100001
using namespace std;

int gpf[MAX], em[MAX];
int t, n, k;

bitset<KMAX> b;

int main(){
    //find greatest prime factors
    for(int i = 2; i < MAX; ++i){
    	if(gpf[i] != 0) //i is composite, continue
    		continue;
    	for(int j = i; j < MAX; j += i)
    		gpf[j] = i;
    }
    //stores in em[i] the number of even multiplicities minus number of odd 
    //multiplicities in the prime factorization of i
    for (int i = 2; i < MAX; i++) {
        //impar = 0 se maior fator primo de i tem expoente par
        int j = i, impar = 0;
        while( j % gpf[i] == 0 ){
            j /= gpf[i];
            impar ^= 1;
        }
        //j eh agora o numero constituido pela fatoração prima de i
        //sem seu maior fator primo
        em[i] = em[j] + (impar ? -1:1);
    }
    scanf("%d", &t);
    while(t--){
    	scanf("%d %d", &n, &k);
    	b = 1U;
	    while(n--){
	    	int x; scanf("%d", &x);
	    	if(em[x] > 0) b |= b << x;
	    }
	    if(b[k]) puts("Yes");
	    else puts("No");
    }
}
