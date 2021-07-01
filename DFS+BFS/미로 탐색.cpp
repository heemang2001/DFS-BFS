#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int answer = 987654321;

// 상하좌우
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void BFS(int x, int y, vector<vector<int>>& vecMap)
{
	int cnt = 0;	

	queue<pair<int, int>> q;
	q.push({ x,y });

	while (!q.empty())
	{
		int q_x = q.front().first;
		int q_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = q_x + dx[i];
			int next_y = q_y + dy[i];

			// 범위 벗어나거나 벽인경우 무시
			if (next_x <= -1 || next_x >= vecMap.size() || next_y <= -1 || next_y >= vecMap[next_x].size() || vecMap[next_x][next_y] == 0 )
			{
				continue;
			}

			if (vecMap[next_x][next_y] == 1)
			{				
				vecMap[next_x][next_y] = vecMap[q_x][q_y] + 1;
				q.push({ next_x, next_y });				
			}
		}
	}

	answer = vecMap[N - 1][M - 1];
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> vecMap(N,vector<int>(M));
	vector<string> vecString;

	for (int i = 0; i < N; i++)
	{
		string sTemp;
		cin >> sTemp;
		vecString.push_back(sTemp);
	}


	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			vecMap[i][j] = vecString[i][j] - '0';
		}
	}
	
	BFS(0, 0, vecMap);

	cout << answer << '\n';	

	return 0;
}