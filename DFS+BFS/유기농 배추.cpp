#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T; // 테스트 케이스 수
int M, N, K; // 가로 , 세로 , 개수

int arrBaechu[50][50];

vector<int> vecAnswer;

bool dfs(int x, int y)
{
	if (x <= -1 || x >= N || y <= -1 || y >= M)
	{
		return false;
	}

	// x(세로=N) y(가로=M)
	if (arrBaechu[x][y] == 1)
	{
		arrBaechu[x][y] = 9;

		// 상, 하, 좌, 우의 위치들도 모두 재귀적으로 호출
		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);

		return true;
	}

	return false;
}

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{		
		cin >> M >> N >> K;				

		int answer = 0;
		arrBaechu[50][50] = { 0, };

		for (int i = 0; i < K; i++)
		{
			int nTemp1, nTemp2;
			cin >> nTemp1 >> nTemp2;

			arrBaechu[nTemp2][nTemp1] = 1;
		}	

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (dfs(i, j))
				{
					answer++;
				}
			}
		}

		vecAnswer.push_back(answer);
	}

	for (int i = 0; i < T; i++)
	{
		cout << vecAnswer[i] << '\n';
	}	

	return 0;
}

