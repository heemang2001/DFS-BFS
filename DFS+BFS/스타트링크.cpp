#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

#define MAX_NUM 1000001

int F, S, G, U, D;
int answer = -1;
bool isVisited[MAX_NUM];

void BFS(int cur)
{
	queue<pair<int, int>> q;
	q.push({cur, 0});
	isVisited[cur] = true;

	while (!q.empty())
	{
		int cur_Floor = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (cur_Floor == G)
		{
			answer = cnt;
			return;
		}

		if (cur_Floor + U <= F && isVisited[cur_Floor + U] == false)
		{
			q.push({ cur_Floor + U, cnt + 1 });	
			isVisited[cur_Floor + U] = true;
		}

		if (cur_Floor - D > 0 && isVisited[cur_Floor - D] == false)
		{
			q.push({ cur_Floor - D, cnt + 1 });
			isVisited[cur_Floor - D] = true;
		}
	}

	return;
}

int main()
{
	cin >> F >> S >> G >> U >> D;

	BFS(S);

	if (answer == -1)
	{
		cout << "use the stairs" << '\n';
	}

	else
	{
		cout << answer << '\n';
	}

	return 0;
}