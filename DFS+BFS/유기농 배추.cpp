#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T; // �׽�Ʈ ���̽� ��
int M, N, K; // ���� , ���� , ����

int arrBaechu[50][50];

vector<int> vecAnswer;

bool dfs(int x, int y)
{
	if (x <= -1 || x >= N || y <= -1 || y >= M)
	{
		return false;
	}

	// x(����=N) y(����=M)
	if (arrBaechu[x][y] == 1)
	{
		arrBaechu[x][y] = 9;

		// ��, ��, ��, ���� ��ġ�鵵 ��� ��������� ȣ��
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

