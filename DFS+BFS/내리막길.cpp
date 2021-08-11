#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int M, N; // 세로, 가로
int answer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int DP[501][501]; // DP[a][b] = c 의 의미는 "(a, b)에서는 (N - 1, M - 1) 까지 c개의 경로로 도달할 수 있습니다."

int DFS(vector<vector<int>>& vecMap, int x, int y)
{
	if (x == M - 1 && y == N - 1)
	{
		return 1;
	}

	if (DP[x][y] != -1)
	{
		return DP[x][y];
	}

	DP[x][y] = 0;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_y >= 0 && next_x < M && next_y < N)
		{
			if (vecMap[next_x][next_y] < vecMap[x][y])
			{
				DP[x][y] = DP[x][y] + DFS(vecMap, next_x, next_y);
			}
		}
	}	

	return DP[x][y];
}

int main()
{
	cin >> M >> N;
	
	vector<vector<int>> vecMap(M, vector<int>(N));

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int nTemp;
			cin >> nTemp;
			vecMap[i][j] = nTemp;
			DP[i][j] = -1;
		}
	}

	answer = DFS(vecMap, 0, 0);

	cout << answer << '\n';

	return 0;
}