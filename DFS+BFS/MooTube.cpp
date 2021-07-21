#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define MAX_NUM 1000000001

int N, Q;
int K, V;
int answer;

vector<pair<int, int>> vecGraph[5001];
vector<bool> vecVisited(5001);

void DFS(int num)
{
	vecVisited[num] = true;

	for (int i = 0; i < vecGraph[num].size(); i++)
	{
		if (vecVisited[vecGraph[num][i].first])
		{
			continue;
		}

		if (vecGraph[num][i].second >= K)
		{
			answer++;
			DFS(vecGraph[num][i].first);
		}
	}
}

int main()
{
	cin >> N >> Q;

	// 두 동영상 쌍의 USADO가 한 줄에 하나씩 주어진다.
	// USADO가 K 이상인 모든 동영상이 추천되도록 할 것이다.
	for (int i = 0; i < N - 1; i++)
	{
		int nTemp1;
		int nTemp2;
		int nTemp3;

		cin >> nTemp1 >> nTemp2 >> nTemp3;

		vecGraph[nTemp1].push_back({ nTemp2, nTemp3 });
		vecGraph[nTemp2].push_back({ nTemp1, nTemp3 });
	}

	// 질문들
	for (int i = 0; i < Q; i++)
	{
		cin >> K >> V;
		answer = 0;

		vector<bool> vecTempVisited(N + 1);
		vecVisited = vecTempVisited;

		DFS(V);

		cout << answer << '\n';
	}

	return 0;
}