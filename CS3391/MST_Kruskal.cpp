#include <iostream>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define Nroad 10000
#define Nnode 55
using namespace std;
struct road {
	int p1, p2, len;
};
road rd[Nroad];
int node[Nnode];
int P, R;// #Points, #Roads

bool operator<(const road& a, const road& b) {
	return a.len > b.len;
}
bool finish() {
	FOR(n, 1, P)
	{
		if (node[n] != node[1])
			return false;
	}
	return true;
}
int kruskal(int P, int R) {
	int sum = 0;
	priority_queue<road> Q;
	//input
	FOR(n, 1, R)
	{
		cin >> rd[n].p1 >> rd[n].p2 >> rd[n].len;
		Q.push(rd[n]);
	}
	//core
	FOR(n, 1, R)
	{
		rd[0] = Q.top();
		if (node[rd[0].p1] != node[rd[0].p2])
		{
			sum += rd[0].len;
			int oldint = node[rd[0].p1];
			int newint = node[rd[0].p2];
			FOR(m, 1, P)
				if (node[m] == oldint)
					node[m] = newint;
		}
		if (finish())
			break;
		Q.pop();
	}
	return sum;
}

int main()
{
	cin >> P;
	while (P != 0)
	{
		FOR(n, 0, Nnode - 1)
			node[n] = n;
		cin >> R;
		cout << kruskal(P, R) << endl;
		cin >> P;
	}
	return 0;
}