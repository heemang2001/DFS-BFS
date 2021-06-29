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

// ���� �Ķ����� ��ġ
pair<int, int> Red, Blue;

// ������
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

// ������ �̵��� ���� ũ��
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

	// ���� ���� �̵�
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

	// �Ķ� ���� �̵�
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

	// �Ķ������� ������ �׳� ����
	if (Blue_Flag == true)
	{
		return;
	}

	// ���� ������ �������� �Ϸ�
	else if (Red_Flag == true)
	{
		answer = min(answer, Cnt);
		return;
	}

	// ���� ���� �Ķ� ������ ���ƴٸ�
	if (nRx == nBx && nRy == nBy)
	{
		// ���� �̵��Ÿ�
		int Red_Dist = Move_Dist(Rx, Ry, nRx, nRy);
		int Blue_Dist = Move_Dist(Bx, By, nBx, nBy);

		// ���� ���� �̵��Ÿ��� �� ũ��
		if (Red_Dist > Blue_Dist)
		{
			// �ݴ������� ��ĭ �̵�������
			nRx = nRx - dx[dir];
			nRy = nRy - dy[dir];
		}

		// �Ķ� ���� �̵��Ÿ��� �� ũ��
		else
		{
			// �ݴ������� ��ĭ �̵�������
			nBx = nBx - dx[dir];
			nBy = nBy - dy[dir];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		// �̵��� ������ ���� ����� ���ٸ� continue
		if (i == dir)
		{
			continue;
		}

		// �̵��� ������ �������̸� continue
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