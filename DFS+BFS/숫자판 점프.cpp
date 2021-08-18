#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int answer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
string arrMap[6][6];
vector<string> vecAnswer;

void DFS(int x, int y, string sum, int cnt)
{
	if (cnt == 6)
	{
		vecAnswer.push_back(sum);
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (next_x >= 1 && next_x <= 5 && next_y >= 1 && next_y <= 5)
		{
			DFS(next_x, next_y, sum + arrMap[next_x][next_y], cnt + 1);
		}		
	}
}

int main()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			string sTemp;
			cin >> sTemp;
			arrMap[i][j] = sTemp;
		}
	}

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 5; j++)
		{
			DFS(i, j, "", 0);
		}
	}	

	sort(vecAnswer.begin(), vecAnswer.end());

	vecAnswer.erase(unique(vecAnswer.begin(), vecAnswer.end()), vecAnswer.end());
	
	answer = vecAnswer.size();
	cout << answer << '\n';

	return 0;
}