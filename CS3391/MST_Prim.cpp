#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 110
#define FOR(i,a,b) for(int i=a;i<=b;i++)
int dis[MAXN][MAXN], lowcost[MAXN];
bool visit[MAXN];
int nodenum, sum;

void prim()
{
	int temp, k;
	sum = 0; // sum of all edges in MST
	memset(visit, false, sizeof(visit)); //initialize visit[]
	visit[1] = true; 					// start from any vertex, say node 1
	FOR(i, 1, nodenum) //initialize lowcost[i]
		lowcost[i] = dis[1][i];
	FOR(i, 1, nodenum)// n round
	{
		//find the min edge connecting two vertex sets.
		temp = INF;
		for (int j = 1; j <= nodenum; ++j)
			if (!visit[j] && temp > lowcost[j])
				temp = lowcost[k = j];
		if (temp == INF) break;
		//update
		visit[k] = true; //add node k to be visited vertex set
		sum += temp;//temp is an edge in MST
		for (int j = 1; j <= nodenum; ++j) //update lowcost[]
			if (!visit[j] && lowcost[j] > dis[k][j])
				lowcost[j] = dis[k][j];
	}
}

int main()
{
	int a, b, cost, edgenum;
	while (scanf("%d", &nodenum) && nodenum)
	{
		memset(dis, 0x3F, sizeof(dis));
		edgenum = nodenum * (nodenum - 1) / 2;
		for (int i = 1; i <= edgenum; ++i) //input edges
		{
			scanf("%d%d%d", &a, &b, &cost);
			if (cost < dis[a][b])
				dis[a][b] = dis[b][a] = cost;
		}
		prim();
		printf("%d\n", sum); //print sum of edges in MST
	}
	return 0;
}