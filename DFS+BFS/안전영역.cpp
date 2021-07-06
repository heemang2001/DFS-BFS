#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N; // 2 <= N <= 100
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool IsFlooding[101][101];

bool DFS(int x, int y, vector<vector<int>>& vecMap, bool IsVisit[][101])
{
	if (x <= -1 || x >= N || y <= -1 || y >= N || IsFlooding[x][y])
	{
		return false;
	}

	else if(!IsFlooding[x][y] && !IsVisit[x][y])
	{
		IsVisit[x][y] = true;

		for (int i = 0; i < 4; i++)
		{
			DFS(x + dx[i], y + dy[i], vecMap, IsVisit);			
		}

		return true;
	}

	return false;
}

int main()
{
	cin >> N;

	vector<vector<int>> vecMap(N, vector<int>(N));

	int min_height = 101;
	int max_height = -1;
	int answer = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int nTemp;
			cin >> nTemp;

			min_height = min(min_height, nTemp);
			max_height = max(max_height, nTemp);

			vecMap[i][j] = nTemp;
		}
	}

	for (int k = min_height; k < max_height; k++)
	{
		int nTemp = 0;
		bool IsVisit[101][101] = { false, };

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (vecMap[i][j] <= k)
				{
					IsFlooding[i][j] = true;
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (DFS(i,j, vecMap, IsVisit) == true)
				{
					nTemp++;
				}
			}
		}

		answer = max(answer, nTemp);
	}

	cout << answer << '\n';

	return 0;
}