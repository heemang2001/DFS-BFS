#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int N;	// 정점 개수
int M;	// 간선 개수

bool isArrive[1001];
vector<int> vecGraph[1001];

void DFS(int node)
{
	isArrive[node] = true;

	for (int i = 0; i < vecGraph[node].size(); i++)
	{
		int next = vecGraph[node][i];

		if (isArrive[next] == false)
		{
			DFS(next);
		}
	}
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		int nTemp1;
		int nTemp2;

		cin >> nTemp1 >> nTemp2;

		vecGraph[nTemp1].push_back(nTemp2);
		vecGraph[nTemp2].push_back(nTemp1);
	}

	int count = 0;

	for (int i = 1; i <= N; i++)
	{
		if (isArrive[i] == false)
		{
			DFS(i);
			count++;
		}
	}

	cout << count << '\n';

	return 0;
}