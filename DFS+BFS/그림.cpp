#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int N, M;
int Painting_cnt;
int Painting_Big;
int curCount;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool bVisited[501][501];

int DFS(vector<vector<int>>& vecMap, int x, int y)
{
	if (!bVisited[x][y] && vecMap[x][y] == 1)
	{
		bVisited[x][y] = true;
		curCount++;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M && vecMap[next_x][next_y] == 1)
			{
				DFS(vecMap, next_x, next_y);
			}			
		}
	}

	return curCount;
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> vecMap(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int nTemp;
			cin >> nTemp;
			vecMap[i].push_back(nTemp);
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{			
			if (!bVisited[i][j] && vecMap[i][j] == 1)
			{
				Painting_cnt++;
				curCount = 0;
				curCount = DFS(vecMap, i, j);
				Painting_Big = max(Painting_Big, curCount);
			}
		}
	}

	cout << Painting_cnt << '\n';
	cout << Painting_Big << '\n';

	return 0;
}