#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int R, C, K;
int answer;
vector<int> vecAnswer;
bool isVisited[6][6];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void DFS(int x, int y, int cnt, vector<string>& vecMap)
{
	// 오른쪽 끝까지 이동횟수가 K인 경우만
	if (cnt == K && x == 0 && y == C - 1)
	{
		answer++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		// 방문할 곳이
		// 범위 벗어남
		if (next_x <= -1 || next_x >= R || next_y <= -1 || next_y >= C)
		{
			continue;
		}

		// T면 안됨
		if (vecMap[next_x][next_y] == 'T')
		{
			continue;
		}

		// 이미 방문했었다면 
		if (isVisited[next_x][next_y])
		{
			continue;
		}

		// 해당 지점 방문처리
		isVisited[next_x][next_y] = true;

		// 다음 위치로 이동
		DFS(next_x, next_y, cnt + 1, vecMap);

		// 다음 위치로 이동후엔 해당 위치방문 기록 없앰
		isVisited[next_x][next_y] = false;
	}
}

int main()
{
	cin >> R >> C >> K;

	vector<string> vecMap(R);

	for (int i = 0; i < R; i++)
	{
		string sTemp;
		cin >> sTemp;
		vecMap[i] = sTemp;
	}

	isVisited[R - 1][0] = true;
	DFS(R - 1, 0, 1, vecMap);

	cout << answer << '\n';

	return 0;
}