#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int M, N, K;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool isVisited[101][101];

vector<int> vecAnswer;

void BFS(int x, int y, vector<vector<int>>& vecMap)
{
	int nValue = 1;

	if (x <= -1 || x >= M || y <= -1 || y >= N || vecMap[x][y] != 0 || isVisited[x][y])
	{
		return;
	}	
	
	isVisited[x][y] = true;
	queue<pair<int, int>> q;
	q.push({ x, y });

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x <= -1 || next_x >= M || next_y <= -1 || next_y >= N || vecMap[next_x][next_y] != 0)
			{
				continue;
			}

			else if(!isVisited[next_x][next_y])
			{
				nValue++;
				isVisited[next_x][next_y] = true;
				q.push({ next_x, next_y });
			}
		}
	}

	return vecAnswer.push_back(nValue);	
}

void FillMap(vector<vector<int>>& vecMap, int LeftRight_xy[])
{
	int height = LeftRight_xy[3] - LeftRight_xy[1];
	int width = LeftRight_xy[2] - LeftRight_xy[0];

	for (int i = M - LeftRight_xy[3]; i < M - LeftRight_xy[3] + height; i++)
	{
		for (int j = LeftRight_xy[0]; j < LeftRight_xy[0] + width; j++)
		{
			vecMap[i][j]++;
		}
	}

	return;
}

int main()
{
	cin >> M >> N >> K;

	vector<vector<int>> vecMap(M, vector<int>(N));	

	int LeftRight_xy[4];

	for (int i = 0; i < K; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int nTemp;
			cin >> nTemp;
			LeftRight_xy[j] = nTemp;
		}	

		FillMap(vecMap, LeftRight_xy);
	}

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			BFS(i, j, vecMap);
		}
	}

	sort(vecAnswer.begin(), vecAnswer.end());

	cout << vecAnswer.size() << '\n';

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}	

	return 0;
}