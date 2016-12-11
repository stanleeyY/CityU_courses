//GCD

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

LCM

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

GCD++//gcd(p,q)=p*x+q*y;

#include <cmath>
int ext_gcd(int p, int q, int *x, int *y)
{
	int x1, y1;
	int g;
	if (q > p)
		return gcd(p, q, y, x);
	if (q == 0)
	{
		*x = 1;
		*y = 0;
		return p;
	}
	g = gcd(q, p%q, &x1, &y1);
	*x = y1;
	*y = (x1 - floor(p / q)*y1);
	return g;
}
