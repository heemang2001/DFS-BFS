#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int N, M;
int Answer;
string arrMap[1001][1001];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

// [x][y][º®À»ºÎ¼øÈ½¼ö]
bool bVisited[1001][1001][2];

int BFS(int x, int y)
{
	//{ {x, y}, {º® ºÎ¼ø È½¼ö, ÇöÀç Ä­¼ö} }
	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ { x, y }, {0, 1} });	
	bVisited[x][y][0] = true;

	while (!q.empty())
	{
		int cur_x = q.front().first.first;
		int cur_y = q.front().first.second;
		int Broken = q.front().second.first;
		int Cnt = q.front().second.second;
		q.pop();

		if (cur_x == N - 1 && cur_y == M - 1)
		{
			return Cnt;
		}

		for (int i = 0; i < 4; i++)
		{
			int next_x = cur_x + dx[i];
			int next_y = cur_y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M)
			{
				if (arrMap[next_x][next_y] == "1" && Broken == 0)
				{
					bVisited[next_x][next_y][Broken + 1] = true;
					q.push({ {next_x,next_y},{1, Cnt + 1} });
				}

				else if (arrMap[next_x][next_y] == "0" && bVisited[next_x][next_y][Broken] == false)
				{
					bVisited[next_x][next_y][Broken] = true;
					q.push({ {next_x,next_y},{Broken, Cnt + 1} });
				}
			}
		}
	}

	return -1;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		string sTemp;
		cin >> sTemp;

		for (int j = 0; j < M; j++)
		{
			arrMap[i][j] = sTemp[j];
		}
	}

	Answer = BFS(0, 0);

	cout << Answer << '\n';

	return 0;
}