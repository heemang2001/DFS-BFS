#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool DFS(int x, int y, vector<vector<int>> vecMap, bool (*isVisited)[51])
{
	if (x <= -1 || x >= vecMap.size() || y <= -1 || y >= vecMap[x].size())
	{
		return false;
	}	

	if (!isVisited[x][y] && vecMap[x][y] == 1)
	{
		isVisited[x][y] = true;

		DFS(x+1, y, vecMap,isVisited);
		DFS(x, y+1, vecMap, isVisited);
		DFS(x-1, y, vecMap, isVisited);
		DFS(x, y-1, vecMap, isVisited);
		DFS(x+1, y-1, vecMap, isVisited);
		DFS(x-1, y+1, vecMap, isVisited);
		DFS(x+1, y+1, vecMap, isVisited);
		DFS(x-1, y-1, vecMap, isVisited);

		return true;
	}

	return false;
}

int main()
{
	vector<int> vecAnswer;

	while (1)
	{
		int w;	// 지도 너비
		int	h;	// 지도 높이	
		int answer = 0;

		cin >> w >> h;

		// 탈출 조건
		if ((w == 0) && (h == 0))
		{
			break;
		}

		vector<vector<int>> vecMap(51);	
		bool isVisited[51][51] = {false,};
		
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				int nTemp;
				cin >> nTemp;
				vecMap[i].push_back(nTemp);
			}
		}

		for (int i = 0; i < vecMap.size(); i++)
		{
			for (int j = 0; j < vecMap[i].size(); j++)
			{
				if (DFS(i,j,vecMap, isVisited))
				{
					answer++;
				}
			}
		}

		vecAnswer.push_back(answer);
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}