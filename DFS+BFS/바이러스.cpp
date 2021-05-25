#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M; // 컴퓨터수 , 컴퓨터 쌍의 수
int answer = 0;

int Graph[101][101];
bool visit[101];

void dfs(int n)
{
	answer++;
	visit[n] = true;

	for (int i = 1; i <= N; i++)
	{
		if (Graph[n][i] == 1 && visit[i] == false)
		{
			dfs(i);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int nTemp1, nTemp2;
		cin >> nTemp1 >> nTemp2;
		Graph[nTemp1][nTemp2] = 1;
		Graph[nTemp2][nTemp1] = 1;
	}

	dfs(1);

	cout << answer - 1 << '\n';

	return 0;
}

