//Array Number

#include <cmath>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
int max(int a, int b) {
	return a > b ? a : b;
}

//bit[0] contain # of digits of number n
void numberToArray(int n, int bit[]) {
	while (n != 0) {
		bit[++bit[0]] = n % 10;
		n = n / 10;
	}
}

//addition: c[] = a[] + b[]. 
//Initially, c[]={0}
void add(int a[], int b[], int c[]) {
	//[1] add digits: c = a + b
	FOR(i, 1, a[0]) c[i] += a[i];
	FOR(i, 1, b[0]) c[i] += b[i];
	c[0] = max(a[0], b[0]);
	//[2] handle carry-bit,
	int flag = 0; //carry flag
	FOR(i, 1, c[0]) {
		c[i] += flag;
		flag = c[i] / 10;
		c[i] = c[i] % 10;
	}
	//[3] handle carry-flag, flag <10 
	if (flag) c[++c[0]] = flag;
}

//multiplication: c[] = a[] * b[]
void multiply(int a[], int b[], int c[]) {
	//[1] multiply digits: c = a * b
	FOR(i, 1, a[0])
		FOR(j, 1, b[0])
		c[i + j - 1] += a[i] * b[j];
	c[0] = a[0] + b[0] - 1;
	//[2] handle carry bit
	int flag = 0; //carry flag
	FOR(i, 1, c[0]) {
		c[i] += flag;
		flag = c[i] / 10;
		c[i] = c[i] % 10;
	}
	//[3] handle carry flag
	while (flag) {
		c[++c[0]] = flag % 10;
		flag = flag / 10;
	}
}
