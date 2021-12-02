#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int R, C;
int cnt_Sheep;
int cnt_Wolf;
int cnt_TempSheep;
int cnt_TempWolf;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool bVisited[251][251];

vector<pair<int, int>> vecAnimal;

void DFS(int x, int y, vector<string>& vecStr)
{
	if (vecStr[x][y] == '#')
	{
		return;
	}

	else if (vecStr[x][y] == 'o')
	{
		cnt_TempSheep++;
	}

	else if (vecStr[x][y] == 'v')
	{
		cnt_TempWolf++;
	}

	bVisited[x][y] = true;

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 0 && next_x < R && next_y >= 0 && next_y < C && !bVisited[next_x][next_y])
		{
			DFS(next_x, next_y, vecStr);
		}
	}
}

int main()
{
	cin >> R >> C;

	vector<string> vecStr;

	for (int i = 0; i < R; i++)
	{
		string sTemp;
		cin >> sTemp;
		vecStr.push_back(sTemp);
	}

	for (int i = 0; i < vecStr.size(); i++)
	{
		for (int j = 0; j < vecStr[i].size(); j++)
		{
			// 양이면
			if (vecStr[i][j] == 'o')
			{
				vecAnimal.push_back({ i,j });
			}

			// 늑대면
			else if(vecStr[i][j] == 'v')
			{
				vecAnimal.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < vecAnimal.size(); i++)
	{
		if (bVisited[vecAnimal[i].first][vecAnimal[i].second] == false)
		{
			cnt_TempSheep = 0;
			cnt_TempWolf = 0;
			DFS(vecAnimal[i].first, vecAnimal[i].second, vecStr);

			if (cnt_TempSheep > cnt_TempWolf)
			{
				cnt_Sheep += cnt_TempSheep;
			}

			else
			{
				cnt_Wolf += cnt_TempWolf;
			}
		}
	}

	cout << cnt_Sheep << " " << cnt_Wolf;

	return 0;
}