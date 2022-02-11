#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 정수 1은 익은 토마토, 정수 0 은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸을 나타낸다. 
int N, M, H; // M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수
int Answer;
int arrMap[101][101][101];
int noTomato;

typedef struct Direction
{
	int x, y, z;
};

// 상, 하, 좌, 우, 아래, 위
Direction moveDir[6] = { {1,0,0}, {-1,0,0}, {0,1,0}, {0,-1,0}, {0,0,1}, {0,0,-1} };

queue<pair<pair<int, int>, int>> q;

// 토마토 다익었나?
bool IsRipeSucess()
{
	int cnt_ripeTomato = 0;
	int cnt_MaxRipe = M * N * H - noTomato;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				if (arrMap[j][k][i] == 1)
				{
					cnt_ripeTomato++;
				}
			}
		}
	}

	return cnt_ripeTomato == cnt_MaxRipe;
}

void BFS()
{	
	int day = 0;

	if (q.empty())
	{
		Answer = -1;
		return;
	}

	while (!q.empty())
	{
		int cnt_ripeTomato = q.size();

		for (int i = 0; i < cnt_ripeTomato; i++)
		{
			int x = q.front().first.first;
			int y = q.front().first.second;
			int z = q.front().second;
			q.pop();

			for (int i = 0; i < 6; i++)
			{
				int next_x = x + moveDir[i].x;
				int next_y = y + moveDir[i].y;
				int next_z = z + moveDir[i].z;

				// 다음 토마토가 범위안에있고 안익은경우만
				if (0 <= next_x && 0 <= next_y && next_x < N && next_y < M && 0 <= next_z && next_z < H)
				{
					if (arrMap[next_x][next_y][next_z] == 0)
					{
						arrMap[next_x][next_y][next_z] = 1;
						q.push({ {next_x,next_y}, next_z });
					}
				}
			}

			if (q.empty() && IsRipeSucess())
			{
				Answer = day;
				return;
			}

			else if (q.empty() && !IsRipeSucess())
			{
				Answer = -1;
				return;
			}
		}	

		day++;
	}
}

int main()
{
	// M은 상자의 가로 칸의 수, N은 상자의 세로 칸의 수
	cin >> M >> N >> H;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> arrMap[j][k][i];

				// 익은 토마토 칸
				if (arrMap[j][k][i] == 1)
				{
					q.push({ {j,k}, i });
				}

				// 토마토가 없는 칸
				if (arrMap[j][k][i] == -1)
				{
					noTomato++;
				}
			}
		}
	}	

	if (q.size() == M * N * H - noTomato)
	{
		Answer = 0;
	}

	else
	{
		BFS();
	}

	cout << Answer << '\n';

	return 0;
}