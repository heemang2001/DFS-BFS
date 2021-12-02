#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int R, C;
int cnt_Sheep;
int cnt_Wolf;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
bool bVisited[251][251];

void DFS(int x, int y, vector<string>& vecStr)
{
	if (vecStr[x][y] == '#')
	{
		return;
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

	vector<pair<int, int>> vecSheep;
	vector<pair<int, int>> vecWolf;

	for (int i = 0; i < vecStr.size(); i++)
	{
		for (int j = 0; j < vecStr[i].size(); j++)
		{
			// 양이면
			if (vecStr[i][j] == 'o')
			{
				vecSheep.push_back({ i,j });
			}

			// 늑대면
			else if(vecStr[i][j] == 'v')
			{
				vecWolf.push_back({ i,j });
			}
		}
	}

	cnt_Sheep = vecSheep.size();
	cnt_Wolf = vecWolf.size();



	cout << cnt_Sheep << " " << cnt_Wolf;

	return 0;
}