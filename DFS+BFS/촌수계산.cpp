#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
int arrPeople[101][101];
int nAnswer1;
int nAnswer2;
bool IsVisited[101];

void DFS(int num, int cnt)
{
	if (num == nAnswer2)
	{
		arrPeople[nAnswer1][nAnswer2] = cnt;
		arrPeople[nAnswer2][nAnswer1] = cnt;

		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (arrPeople[num][i] == 1 && !IsVisited[i])
		{
			IsVisited[i] = true;
			DFS(i, cnt + 1);
		}
	}	
}

int main()
{
	cin >> N;

	cin >> nAnswer1 >> nAnswer2;

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		int nTemp1;
		int nTemp2;

		cin >> nTemp1 >> nTemp2;

		arrPeople[nTemp1][nTemp2] = 1;
		arrPeople[nTemp2][nTemp1] = 1;
	}

	IsVisited[nAnswer1] = true;
	DFS(nAnswer1,0);

	if (arrPeople[nAnswer1][nAnswer2] == 0)
	{
		cout << -1 << '\n';
	}

	else
	{
		cout << arrPeople[nAnswer1][nAnswer2] << '\n';
	}

	return 0;
}