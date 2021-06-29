#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int answer = 123123123;
char Map[10][10];

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

// 빨강 파랑구슬 위치
pair<int, int> Red, Blue;

// 역방향
int Inverse_Direction(int Cur_D)
{
	if (Cur_D == 0)
	{
		return 1;
	}

	else if (Cur_D == 1)
	{
		return 0;
	}

	else if (Cur_D == 2)
	{
		return 3;
	}

	else if (Cur_D == 3)
	{
		return 2;
	}
}

// 구슬이 이동한 절댓값 크기
int Move_Dist(int x, int y, int xx, int yy)
{
	return abs(x - xx) + abs(y - yy);
}

void Move(int Rx, int Ry, int Bx, int By, int Cnt, int dir)
{
	if (Cnt >= answer || Cnt > 10)
	{
		return;
	}

	bool Red_Flag = false;
	bool Blue_Flag = false;

	// 빨강 구슬 이동
	int nRx = Rx + dx[dir];
	int nRy = Ry + dy[dir];
	while (1)
	{
		if (Map[nRx][nRy] == '#')
		{
			break;
		}

		if (Map[nRx][nRy] == 'O')
		{
			Red_Flag = true;
			break;
		}

		nRx = nRx + dx[dir];
		nRy = nRy + dy[dir];
	}

	// 파랑 구슬 이동
	int nBx = Bx + dx[dir];
	int nBy = By + dy[dir];
	while (1)
	{
		if (Map[nBx][nBy] == '#')
		{
			break;
		}

		if (Map[nBx][nBy] == 'O')
		{
			Blue_Flag = true;
			break;
		}

		nBx = nBx + dx[dir];
		nBy = nBy + dy[dir];
	}
	nBx = nBx - dx[dir];
	nBy = nBy - dy[dir];

	// 파랑구슬이 빠지면 그냥 끝냄
	if (Blue_Flag == true)
	{
		return;
	}

	// 빨강 구슬만 빠졋으면 완료
	else if (Red_Flag == true)
	{
		answer = min(answer, Cnt);
		return;
	}

	// 빨강 구슬 파랑 구슬이 겹쳤다면
	if (nRx == nBx && nRy == nBy)
	{
		// 구슬 이동거리
		int Red_Dist = Move_Dist(Rx, Ry, nRx, nRy);
		int Blue_Dist = Move_Dist(Bx, By, nBx, nBy);

		// 빨강 구슬 이동거리가 더 크면
		if (Red_Dist > Blue_Dist)
		{
			// 반대쪽으로 한칸 이동시켜줌
			nRx = nRx - dx[dir];
			nRy = nRy - dy[dir];
		}

		// 파랑 구슬 이동거리가 더 크면
		else
		{
			// 반대쪽으로 한칸 이동시켜줌
			nBx = nBx - dx[dir];
			nBy = nBy - dy[dir];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		// 이동할 방향이 현재 방향과 같다면 continue
		if (i == dir)
		{
			continue;
		}

		// 이동할 방향이 역방향이면 continue
		if (i == Inverse_Direction(dir))
		{
			continue;
		}

		Move(nRx, nRy, nBx, nBy, Cnt + 1, i);
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Map[i][j];

			if (Map[i][j] == 'R')
			{
				Red.first = i;
				Red.second = j;
				Map[i][j] = '.';
			}

			else if (Map[i][j] == 'B')
			{
				Blue.first = i;
				Blue.second = j;
				Map[i][j] = '.';
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		int x = Red.first;
		int y = Red.second;
		int xx = Blue.first;
		int yy = Blue.second;

		Move(x, y, xx, yy, 1, i);
	}

	if (answer > 10 || answer == 123123123)
	{
		answer = -1;
	}

	cout << answer << '\n';

	return 0;
}