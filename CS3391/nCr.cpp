long long big_ncr(int n, int r)
{
	int up, down, u, d, i, t;
	up = down = 1;
	if ( r > (n >> 1) ) r = n - r;
	for ( i = r; i >= 1; --i )
	{
		u = n-r+i;
		d = i;

		t = gcd(u,d);
		u /= t; d /= t;

		t = gcd(up,d);
		up /= t; d /= t;

		t = gcd(down,u);
		down /= t; u /= t;

		up *= u;
		down *= d;
	}
	return (up / down);
}