int bigmod(int m, int e, int n)
{
	long long ans, base; base = m; ans = 1;

	// loop until e = 0 (binary conversion)
	while ( e > 0 )
	{
		// if e is odd, remainder with 2 is 1 (binary conversion)
		if ( e & 1 )
		{
			// if the LSB of e in binary is 1, multiply the answer with current base
			ans *= base;
			if ( ans >= n )
			{
				ans %= n;
			}
		}

		// divide e with 2 (binary conversion)
		e >>= 1;

		// calculate base^2n = base^n * base^n
		base *= base;

		if ( base >= n )
		{
			base %= n;
		}
	}
	return (int)ans;
}