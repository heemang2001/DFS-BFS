#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int arrMap[25][25];
int nCount;

bool arrVisited[25][25];

vector<int> vecCount;

void dfs(int x, int y)
{	
	if (x < 0 || x >= N || y < 0 || y >= N)
	{
		return;
	}

	if (arrMap[x][y] == 1 && arrVisited[x][y] == false)
	{
		arrVisited[x][y] = true;
		nCount++;

		dfs(x - 1, y);
		dfs(x, y - 1);
		dfs(x + 1, y);
		dfs(x, y + 1);
	}

	return;
}

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string sTemp;
		cin >> sTemp;

		for (int j = 0; j < N; j++)
		{
			arrMap[i][j] = sTemp[j] - '0';
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arrMap[i][j] == 1 && arrVisited[i][j] == false)
			{			
				nCount = 0;
				dfs(i, j);
				vecCount.push_back(nCount);
			}
		}
	}

	sort(vecCount.begin(), vecCount.end());

	cout << vecCount.size() << '\n';

	for (int i = 0; i < vecCount.size(); i++)
	{
		cout << vecCount[i] << '\n';
	}

	return 0;
}
