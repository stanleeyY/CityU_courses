//disjoint set

#include <cstring>
#define N 105
int root[N];
int rnk[N]; //level
int node[N];
int findroot(int x) {
	if (root[x] != -1)
		return root[x] = findroot(root[x]); //path compression!
	else
		return x;
}
void combine(int a, int b) {
	int s1 = findroot(a);
	int s2 = findroot(b);
	if (s1 == s2) return;

	if (rnk[s1] < rnk[s2]) {
		root[s1] = s2;
		node[s2] += node[s1];
	}
	else if (rnk[s1] > rnk[s2]) {
		root[s2] = s1;
		node[s1] += node[s2];
	}
	else {//break tie
		root[s1] = s2;
		rnk[s2] ++;
		node[s2] += node[s1];
	}

}
void initialize() {
	memset(root, -1, sizeof(root));
	memset(rnk, 0, sizeof(rnk));
	for (int i = 0;i < N;i++)
		node[i] = 1;
}
