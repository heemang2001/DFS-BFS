#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int answer;
int arrMap[7][7];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int nValue;
bool isVisited[7][7];

void DFS(int x, int y, int num)
{
	if (!isVisited[x][y])
	{
		isVisited[x][y] = true;
		nValue++;

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < 7 && next_y >= 0 && next_y < 7 && arrMap[next_x][next_y] == num)
			{
				DFS(next_x, next_y, num);
			}	
		}	
	}	

	return;
}

int main()
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			int nTemp;
			cin >> nTemp;
			arrMap[i][j] = nTemp; 
		}
	}

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			nValue = 0;
			DFS(i, j, arrMap[i][j]);

			if (nValue >= 3)
			{
				answer++;
			}
		}	
	}

	cout << answer << '\n';
	return 0;
}