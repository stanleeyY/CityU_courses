#include <cstring>
#include <queue>
#define V 100
#define INF 0x3f3f3f3f
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

int disk[V+1][V+1];
void floyd() {
	//initialize
	memset(disk, INF, sizeof(disk));
	FOR(i, 0, V)
		disk[i][i] = 0;
	//input:	disk[u][v]=w(u,v);
	//core
	FOR(k, 1, V)
		FOR(i, 1, V)
		FOR(j, 1, V)
		if (disk[i][j] > disk[i][k] + disk[k][j])
			disk[i][j] = disk[i][k] + disk[k][j];
}

int path[V + 1][V + 1];
void floyd_reconstruction() {
	//initialize
	memset(disk, INF, sizeof(disk));
	memset(disk, -1, sizeof(disk));
	FOR(i, 0, V) {
		disk[i][i] = 0;
		path[i][i] = 0;
	}
	//input:	disk[u][v]=w(u,v);
	//input:	next[u][v]=v;
	//core
	FOR(k, 1, V)
		FOR(i, 1, V)
		FOR(j, 1, V)
		if (disk[i][j] > disk[i][k] + disk[k][j]) {
			disk[i][j] = disk[i][k] + disk[k][j];
			path[i][j] = path[i][k];
		}
}
queue<int> Q;
void floyd_printPath(int from,int to) {
	if (path[from][to] == NULL)
		return;
	int u = from, v = to;
	Q.push(u);
	while (u != v) {
		u = path[u][v];
		Q.push(u);
	}
	return;
}