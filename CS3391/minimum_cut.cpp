/*
 Minimum Cut
 CityU OJ #266
 */
#include<iostream>
#include<cmath>
#include<cstring>
#include<queue>
using namespace std;
#define MIN(a,b) ((a)<(b)?(a):(b))
#define INF 1000000000
#define MAXN 20000
#define CS 1

struct edge {
	int v, w, next;
};
edge E[MAXN];
int f[MAXN];
int head[200];
int D[200];
int total_edge;
void add_edge(int u, int v, int w)
{
	E[total_edge].v = v;
	E[total_edge].w = w;
	E[total_edge].next = head[u];
	head[u] = total_edge++;
}
bool bfs(int s, int t)
{
	int u, v;
	queue<int> q;
	memset(D, -1, sizeof(D));
	D[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		u = q.front();
		q.pop();
		for (int a = head[u]; a != -1; a = E[a].next)
		{
			v = E[a].v;
			if (D[v] == -1 && E[a].w > f[a])
			{
				D[v] = D[u] + 1;
				q.push(v);
			}
		}

	}
	return D[t] >= 0;
}

int dinic(int u, int t, int sum)
{
	int v;
	int temp = sum;
	if (u == t)
		return sum;
	for (int a = head[u]; a != -1 && sum; a = E[a].next)
	{
		v = E[a].v;
		if (D[v] == D[u] + 1)
		{
			int canflow = dinic(v, t, MIN(E[a].w - f[a], sum));
			f[a] += canflow;
			f[a ^ 1] -= canflow;
			sum -= canflow;
		}
	}
	return temp - sum;
}
int maxflow(int s, int t)
{
	int ans = 0;
	while (bfs(s, t))
	{
		ans += dinic(s, t, INF);
	}
	return ans;
}
int main()
{
	int M, W;
	while (cin >> M >> W)
	{
		if (M == 0 && W == 0)
		{
			break;
		}
		memset(f, 0, sizeof(f));
		memset(head, -1, sizeof(head));
		total_edge = 0;
		int m_no, cost;
		for (int i = 1; i <= M - 2; i++)
		{
			cin >> m_no >> cost;
			add_edge(m_no, m_no + 100, cost);
			add_edge(m_no + 100, m_no, 0);
		}
		int u, v, w;
		for (int i = 1; i <= W; i++)
		{

			cin >> u >> v >> w;

			add_edge(u + 100, v, w);
			add_edge(v, u + 100, 0);
			add_edge(v + 100, u, w);
			add_edge(u, v + 100, 0);

		}
		int min_cut = maxflow(101, M);
		cout << min_cut << endl;
	}



	return 0;
}
