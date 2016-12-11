#include <iostream>
#include <queue>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int main()
{
	int map[105][105];
	queue<int> Q;
	int M, N, K;
	while (cin >> M)
	{
		cin >> N >> K;
		if (M > 0 && N > 0)
		{
			FOR(i, 0, M)
			{
				FOR(j, 0, N)
				{
					map[i][j] = 0;
				}
			}
			int max = 0, count = 0;
			FOR(i, 1, K)
			{
				int R, C;
				cin >> R >> C;
				map[R][C] = 1;
			}
			//input finished
			FOR(x, 1, M)
			{
				FOR(y, 1, N)
				{
					if (map[x][y] == 1)
					{
						count++;
						Q.push(x);Q.push(y);
						map[x][y] = 2;
						while (!Q.empty())
						{

							int i = Q.front();Q.pop();
							int j = Q.front();Q.pop();
							if (map[i][j + 1] == 1)
							{
								count++;
								Q.push(i);Q.push(j + 1);
								map[i][j + 1] = 2;
							}
							if (map[i][j - 1] == 1)
							{
								count++;
								Q.push(i);Q.push(j - 1);
								map[i][j - 1] = 2;
							}
							if (map[i - 1][j] == 1)
							{
								count++;
								Q.push(i - 1);Q.push(j);
								map[i - 1][j] = 2;
							}
							if (map[i + 1][j] == 1)
							{
								count++;
								Q.push(i + 1);Q.push(j);
								map[i + 1][j] = 2;
							}
						}
						if (count > max)
						{
							max = count;
						}

						count = 0;
					}
				}
			}
			cout << max << endl;
		}
	}
	return 0;
}