#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>

int x;int y;
char c[1000005];

int cur;
int ccur;
using namespace std;

int st[1000005];
int res;

int gcd(int a, int b) {
	if (b ==0)
		return a;
	else
		return gcd(b, a % b);
}

int xa(char x) {
	if (x >= 'a'&&x <= 'z')return int(x);
	else if (x <= 'Z'&&x >= 'A') {
		return int(x - 'A' + 'a');
	}
}

bool pz(int length,int m) {
	int cnt = 1;
	bool same = true;
	char min = 'z';
	int cccur = 0;
	for (int n = 0;n <= length;n++) {
		if (st[n] == -1)continue;
		if (c[st[n] + m] == min) {
			cnt++;
			//cout << m << ": " << min <<" same "<<cnt<< endl;
		}
		else if (xa(c[st[n] + m]) < xa(min)) {
			same = false;
			min = xa(c[st[n]+m]);
			res = st[n];
			//cout << res << endl<<endl;
			cnt = 1;
			//cout << m << ": "<<"" << min << endl;
			if (n > 0) {
				for (int xx = 0;xx < n;xx++)st[xx] = -1;
			}
		}
		else if (xa(c[st[n] + m]) > xa(min)) {
			same = false;
			st[n] = -1;
		}
	}
	if (cnt == 1) { return true; }
	else { return false; }
}

int main() {
	//freopen("input.txt", "r", stdin);
	while (scanf("%s", c) != EOF)
	{
		int l;
		ccur = 0;
		scanf("%d",&l);
		char lc='z';
		cur = 0;
		while (c[cur+l-1] != '\0') {
			if (xa(c[cur]) < xa(lc))
			{
				lc = c[cur];
				memset(st,-1,sizeof(st));
				ccur = 0;
				st[ccur] = cur;
			}
			else if (c[cur] == lc) {
				ccur++;
				st[ccur] = cur;
			}
			cur++;
		}
		int kkk = cur;
		//while (kkk >= 0) { cout << st[kkk] << endl;kkk--; }
		int m = 1;
		while (m <= l) {
			
			if (pz(cur, m)) { break; }
			m++;
		//	while (kkk >= 0) { cout << st[kkk] << endl;kkk--; }
		}

		kkk = cur;
	//	while (kkk >= 0) { cout << st[kkk] << endl;kkk--; }
		for (int j = 0;j <= cur;j++) {
		//	cout << st[j] << endl;
			if (st[j] != -1) {
				for (int h = st[j];h <=st[j]+ l-1;h++)
				{
					cout << c[h];
				}
				cout << endl;
			break;
			}
		}
	}
}
