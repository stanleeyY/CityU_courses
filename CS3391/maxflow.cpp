#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 0x3f3f3f3f
using namespace std;
#define N 100
#define M 100
typedef struct {
	int v;     // edge (u->v)
	int w;  // edge weight (w)
	int nxt;  // the next edge connected by node u.
}EDGE;
int head[N]; // the first edge connected by node u.
int totaledge; // the total number of edges
EDGE edge[M];
//============
queue<int> Q;
int d[N];//???
//============
void cleargraph() {
	totaledge = 0;
	memset(head, -1, sizeof(head));
}
void add_edge(int u, int v, int w) {
	edge[totaledge].v = v;
	edge[totaledge].w = w;
	edge[totaledge].nxt = head[u];
	head[u] = totaledge;
	totaledge++;
}
void visit_array(int u) {//node u
	for (int e = head[u]; e != -1; e = edge[e].nxt) {
		printf("%d -> %d : %d", u, edge[e].v, edge[e].w);
	}
}
//===========
const int i = M;//real # of edge
int f[i];//real flow of edge[i]
void build_f(int u,int v,int w) {
	add_edge(u, v, w);
	add_edge(v, u, 0);
	f[i] = 0;//i-index
}
//===========
bool bfs(int S, int T) {
	int u, v;
	memset(d, -1, sizeof(d));
	while (!Q.empty())Q.pop();
	Q.push(S);
	d[S] = 0;
	while (!Q.empty()) {
		u = Q.front();
		Q.pop();
		for (int e = head[u]; e != -1; e = edge[e].nxt) {
			v = edge[e].v;
			// d[v]=-1,then v is not visited yet
			// and the flow did not reach the capacity
			if ((d[v] == -1) && edge[e].w > f[e]) {
				d[v] = d[u] + 1;
				Q.push(v);
			}
		}
	}
	return d[T] >= 0;
}
int dinic(int u, int T, int Sum) {
	if (u == T) return Sum;
	int v, tp = Sum;
	for (int e = head[u]; e != -1 && Sum; e = edge[e].nxt) {
		v = edge[e].v;
		// find augmenting path by d[]
		if (d[v] == d[u] + 1 && edge[e].w>f[e]) {
			int canflow = dinic(v, T, min(Sum, edge[e].w - f[e]));
			f[e] += canflow;
			f[e ^ 1] -= canflow;
			Sum -= canflow;
			// do not break, because may find more than 1 path
		}
	}
	return tp - Sum;
}
int maxFlow(int S, int T) {
	int ans = 0;
	while (bfs(S, T))
		ans += dinic(S, T, INF);
	return ans;
}