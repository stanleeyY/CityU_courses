Prime Number O(n)

#define N 0x3f3f3f3f
bool flag[N];
int prime[N/log(N)];/*** LARGE ENOUGH ? ***/
int cnt;
int bs(int cnt, int n)
{
	int mid, p = 0;
	while (p < cnt)
	{
		mid = (p + cnt + 1) / 2;
		prime[mid] >= n ? cnt = mid - 1 : p = mid;
	}
	return p;
}
void getprime()
{
	cnt = 1;
	int n = N;
	memset(flag, false, sizeof(flag));
	for (int i = 2; i <= n; i++)
	{
		if (!flag[i])
			prime[cnt++] = i;
		for (int j = 1; j <= cnt && i*prime[j] <= n; ++j)
		{
			flag[i*prime[j]] = true;			
			if (i%prime[j] == 0)
				break;
		}
	}
}
bool isprime(int x)
{
	if (prime[bs(cnt, x) + 1] == x)
		return true;
	return false;
}