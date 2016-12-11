Prime Number O(n*logn)

#define N 0x3f3f3f3f
bool prime[N >> 1];
void getprime()
{
	memset(prime, true, sizeof(prime));
	for (int i = 3; i < N; i += 2)
		if (prime[i >> 1] == true)
			for (int j = i; i*j < N && i*j > 0;j += 2)
				prime[i*j >> 1] = false;
}
bool isPrime(int n)
{
	if (n <= 1)
		return false;
	if (n == 2)
		return true;
	if (!(n & 1))
		return false;
	return prime[n >> 1];
}