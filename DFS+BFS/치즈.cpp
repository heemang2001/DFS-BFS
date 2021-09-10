#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int Garo;
int Sero;
int LastCheeze;
int Ansewr_Time;
int Answer_Count;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int arrCheeze[101][101];
bool bVisited[101][101];

queue<pair<int, int>> q;

int main()
{
	cin >> Sero >> Garo;

	// 입력
	for (int i = 0; i < Sero; i++)
	{
		for (int j = 0; j < Garo; j++)
		{
			int nTemp;
			cin >> nTemp;
			arrCheeze[i][j] = nTemp;
		}
	}

	while (1)
	{
		// 치즈가 존재하면 치즈갯수 LastCheeze 저장
		for (int i = 0; i < Sero; i++)
		{
			for (int j = 0; j < Garo; j++)
			{
				if (arrCheeze[i][j] == 1)
				{
					LastCheeze++;
				}
			}
		}

		// 치즈가 없으면 탈출
		if (LastCheeze == 0)
		{
			break;
		}

		// 치즈 녹인 시간과 치즈갯수 최신화
		else
		{
			Ansewr_Time++;
			Answer_Count = LastCheeze;
		}

		// 방문기록, 치즈갯수 초기화
		memset(bVisited, false, sizeof(bVisited));
		LastCheeze = 0;

		// 0행 0열부터 시작
		q.push({ 0,0 });
		bVisited[0][0] = true;

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			// 4방향 탐색
			for (int i = 0; i < 4; i++)
			{
				int next_x = x + dx[i];
				int next_y = y + dy[i];

				// 범위를 벗어나지 않고, 방문하지 않은경우만
				if (next_x >= 0 && next_x < Sero && next_y >= 0 && next_y < Garo && !bVisited[next_x][next_y])
				{
					// 치즈가 없는곳이면 넣고 큐에 삽입
					if (arrCheeze[next_x][next_y] == 0)
					{
						q.push({ next_x,next_y });
					}

					// 치즈가 있는곳이면 치즈 지워줌
					else if(arrCheeze[next_x][next_y] == 1)
					{
						arrCheeze[next_x][next_y] = 0;
					}

					// 방문처리
					bVisited[next_x][next_y] = true;
				}
			}
		}
	}

	cout << Ansewr_Time << '\n';
	cout << Answer_Count << '\n';

	return 0;
}