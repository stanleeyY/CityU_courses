//return a^b mod c

unsigned modExp(unsigned a, unsigned b, unsigned c)
{
	if (a == 0)
		return 0;
	a %= c;
	if (b == 1)
		return a;
	if (b == 0)
		return 1;
	unsigned tmp = modExp(a, b >> 1, c);
	tmp = (tmp*tmp) % c;
	if (b & 1)
		tmp = (tmp*a) % c;
	return tmp;
}
