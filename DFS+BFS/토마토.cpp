#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int answer;

// 상하좌우
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1, };

int BFS(vector<vector<int>>& vecMap)
{
	queue<pair<int, int>> q;

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (vecMap[i][j] == 1)
			{
				q.push({ i,j });
			}
		}
	}

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x <= -1 || next_x >= M || next_y <= -1 || next_y >= N || vecMap[next_x][next_y] == -1)
			{
				continue;
			}

			else if (vecMap[next_x][next_y] == 0)
			{
				q.push({ next_x, next_y });
				vecMap[next_x][next_y] = vecMap[x][y] + 1;
			}
		}
	}

	int maxValue = 0;
	bool bFindZero = false;

	for (int i = 0; i < vecMap.size(); i++)
	{
		// vector<int>::iterator ==> auto 사용가능 
		// 0을 찾아서 있으면 이터레이터 반환, 없으면 end반환
		vector<int>::iterator it = find(vecMap[i].begin(), vecMap[i].end(), 0);

		if (it != vecMap[i].end())
		{
			bFindZero = true;
			break;
		}
	}

	if (!bFindZero)
	{
		for (int i = 0; i < vecMap.size(); i++)
		{
			int nTemp = *max_element(vecMap[i].begin(), vecMap[i].end());
			maxValue = max(maxValue, nTemp);
		}

		answer = maxValue - 1;		
	}

	else
	{
		answer = -1;	
	}

	return answer;
}

int main()
{
	cin >> N >> M;

	vector<vector<int>> vecMap(M, vector<int>(N));

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int nTemp;
			cin >> nTemp;
			vecMap[i][j] = nTemp;
		}
	}

	BFS(vecMap);

	cout << answer << '\n';

	return 0;
}