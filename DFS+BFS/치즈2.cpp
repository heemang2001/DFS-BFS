#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int N, M;
int Answer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int arrCheeze[101][101];
bool bVisited[101][101];

queue<pair<int, int>> q;

void BFS()
{
	q.push({ 0, 0 });
	bVisited[0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;		

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && arrCheeze[next_x][next_y] == 0 && !bVisited[next_x][next_y])
			{
				q.push({ next_x,next_y });
				bVisited[next_x][next_y] = true;
			}

			if (arrCheeze[next_x][next_y] >= 1)
			{
				arrCheeze[next_x][next_y]++;
			}
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int nTemp;
			cin >> nTemp;
			arrCheeze[i][j] = nTemp;
		}
	}

	while (1)
	{
		bool bZero = true;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arrCheeze[i][j] == 1)
				{					
					bZero = false;					
				}
			}
		}

		if (bZero)
		{
			break;
		}

		memset(bVisited, false, sizeof(bVisited));
		BFS();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arrCheeze[i][j] >= 3)
				{
					arrCheeze[i][j] = 0;
				}

				else if(arrCheeze[i][j] == 2)
				{
					arrCheeze[i][j] = 1;
				}
			}
		}

		Answer++;
	}

	cout << Answer << '\n';

	return 0;
}

// 치즈 내부 공간 고려X
//int main()
//{
//	cin >> N >> M;
//
//	for (int i = 0; i < N; i++)
//	{
//		for (int j = 0; j < M; j++)
//		{
//			int nTemp;
//			cin >> nTemp;
//			arrCheeze[i][j] = nTemp;
//		}
//	}
//
//	while (1)
//	{
//		bool bZero = true;		
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				if (arrCheeze[i][j] == 1)
//				{
//					q.push({ i, j });
//					bZero = false;
//				}
//
//				else if(arrCheeze[i][j] == -1)
//				{
//					arrCheeze[i][j] = 0;
//				}
//			}
//		}
//
//		if (bZero)
//		{
//			break;
//		}
//
//		while (!q.empty())
//		{
//			int x = q.front().first;
//			int y = q.front().second;
//			int ZeroCount = 0;
//
//			q.pop();			
//
//			for (int i = 0; i < 4; i++)
//			{
//				int next_x = x + dx[i];
//				int next_y = y + dy[i];
//
//				if (next_x >= 0 && next_y >= 0 && next_x < N && next_y < M && arrCheeze[next_x][next_y] == 0 && !bVisited[next_x][next_y])
//				{
//					ZeroCount++;
//				}
//			}
//
//			if (ZeroCount >= 2)
//			{
//				arrCheeze[x][y] = -1;
//			}
//		}
//
//		Answer++;
//	}
//
//	cout << Answer << '\n';
//
//	return 0;
//}