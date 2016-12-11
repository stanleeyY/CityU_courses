#include <cstring>
#include <cmath>
#define N 100
#define FOR(i,a,b) for(int i=a;i<=b;i++)
bool A[N+1];
void getprime() {
	memset(A, true, sizeof(A));
	A[0] = false;
	A[1] = false;
	FOR(i, 2, sqrt(N))
		if (A[i])
			for (int j = i*i;j <= N;j += i)
				A[j] = false;
}
bool isprime(int n) {
	return A[n];
}