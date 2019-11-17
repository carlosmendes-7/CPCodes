// LCS com Bit-paralelo 
//https://www.spoj.com/problems/LCS0/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define INF INT_MAX

char A[50002], B[50002];

int main(){
	scanf("%s\n%s",A,B);
	register int i, j, k, m, n;
	for ( m = 0; A[m]; ++m) ;
	for ( n = 0; B[n]; ++n) ;
	if ( m == 0 || n == 0) return 0;
	char *X = A, *Y = B;
	if (m < n) {
		char *T;
		T = X ; X = Y ; Y = T ;
		k = m ; m = n ; n = k ;
	}

	int w =( m + 31) >> 5; // ceil [m /32]

	unsigned int S [256][ w ]; // Sigma {all char }
	for ( i = 0; i < 256; ++i)
	for ( j = 0; j < w ; ++j)
	S [ i ][ j ]=0;

	unsigned int set = 1;
	for ( i = 0 , j = 0; i < m ; ++i) {
		S [ X [ i ]][ j ] |= set ;
		set <<= 1;
		if (!set) { ++set; ++j;}
	}

	unsigned int L[w]; // Vetor L(i)
	unsigned int b1 , b2 , c ; // borrows and carries

	for ( i = 0; i < w ; ++i) L[i] = 0;

	register unsigned int U, V;
	for ( i =0; i < n ; ++i) {
		b1 = 1; b2 = 0;
		for ( j = 0; j < w ; ++j) {
			U = L[j] | S [ Y[i] ][j];
			c = L[j] >> 31;
			V = U - ( L[j] << 1 | b1 + b2 ) ;
			b1 = c; b2 = ( V > U ) ;
			L[j] = U & (~V) ;
		}
	}
	for ( k = 0 , i = 0; i < w ; ++i)
		for (; L [ i ]; ++k) L[i] &= L[i] - 1;
	printf("%d\n", k);
 }
