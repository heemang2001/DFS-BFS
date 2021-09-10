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

	// �Է�
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
		// ġ� �����ϸ� ġ��� LastCheeze ����
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

		// ġ� ������ Ż��
		if (LastCheeze == 0)
		{
			break;
		}

		// ġ�� ���� �ð��� ġ��� �ֽ�ȭ
		else
		{
			Ansewr_Time++;
			Answer_Count = LastCheeze;
		}

		// �湮���, ġ��� �ʱ�ȭ
		memset(bVisited, false, sizeof(bVisited));
		LastCheeze = 0;

		// 0�� 0������ ����
		q.push({ 0,0 });
		bVisited[0][0] = true;

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			// 4���� Ž��
			for (int i = 0; i < 4; i++)
			{
				int next_x = x + dx[i];
				int next_y = y + dy[i];

				// ������ ����� �ʰ�, �湮���� ������츸
				if (next_x >= 0 && next_x < Sero && next_y >= 0 && next_y < Garo && !bVisited[next_x][next_y])
				{
					// ġ� ���°��̸� �ְ� ť�� ����
					if (arrCheeze[next_x][next_y] == 0)
					{
						q.push({ next_x,next_y });
					}

					// ġ� �ִ°��̸� ġ�� ������
					else if(arrCheeze[next_x][next_y] == 1)
					{
						arrCheeze[next_x][next_y] = 0;
					}

					// �湮ó��
					bVisited[next_x][next_y] = true;
				}
			}
		}
	}

	cout << Ansewr_Time << '\n';
	cout << Answer_Count << '\n';

	return 0;
}