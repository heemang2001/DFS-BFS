#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

#define MAX 100001

using namespace std;

int N, K;
int answer;
bool isVisit[MAX];

void BFS(int num)
{
	queue<pair<int, int>> q;
	q.push({ num, 0 });

	while (!q.empty())
	{
		int location = q.front().first;
		int cnt = q.front().second;
		q.pop();

		if (location == K)
		{
			answer = cnt;
			return;
		}

		int next_location1 = location - 1;
		int next_location2 = location + 1;
		int next_location3 = location * 2;

		if (0 <= next_location1 && !isVisit[next_location1])
		{
			q.push({ next_location1, cnt + 1 });
			isVisit[next_location1] = true;
		}

		if (next_location2 < MAX && !isVisit[next_location2])
		{
			q.push({ next_location2, cnt + 1 });
			isVisit[next_location2] = true;
		}

		if (next_location3 < MAX && !isVisit[next_location3])
		{
			q.push({ next_location3, cnt + 1 });
			isVisit[next_location3] = true;
		}
	}
}

int main()
{
	cin >> N >> K;

	BFS(N);

	cout << answer << '\n';

	return 0;
}