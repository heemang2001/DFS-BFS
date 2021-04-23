#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

int N, M;
int Map[200][200];

// 이동할 네 가지 방향 정의 ( 상, 하, 좌, 우 )
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int BFS(int x, int y)
{
	// 큐(Queue) 구현을 위해 queue 라이브러리 사용
	queue<pair<int, int>> q;
	q.push({ x, y });

	// 큐가 빌 때까지 반복하기
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// 현재 위치에서 4가지 방향으로의 위치 확인
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			// 미로 찾기 공간을 벗어난 경우 무시
			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			{
				continue;
			}

			// 벽인 경우 무시
			if (Map[nx][ny] == 0)
			{
				continue;
			}

			// 해당 노드를 처음 방문하는 경우에만 최단 거리 기록
			if (Map[nx][ny] == 1)
			{
				Map[nx][ny] = Map[x][y] + 1;
				q.push({ nx, ny });
			}
		}
	}

	// 가장 오른쪽 아래까지의 최단 거리 반환
	return Map[N - 1][M - 1];
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &Map[i][j]);			
		}
	}

	cout << BFS(0, 0) << '\n';

	return 0;
}
