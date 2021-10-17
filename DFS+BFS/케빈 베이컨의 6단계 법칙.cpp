#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

#define INF 987654321

int N, M;
int Answer;
int Friends[101][101];

bool cmp(pair<int,int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second)
	{
		return p1.first < p2.first;
	}
		
	return p1.second < p2.second;	
}

int main()
{
	cin >> N >> M;	

	fill(&Friends[0][0], &Friends[100][101], INF);
	vector<pair<int,int>> vecAnswer;

	for (int i = 1; i <= N; i++)
	{
		Friends[i][i] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		int nTemp1;
		int nTemp2;

		cin >> nTemp1 >> nTemp2;

		Friends[nTemp1][nTemp2] = 1;
		Friends[nTemp2][nTemp1] = 1;
	}

	// (플로이드 와샬)
	// 
	// 거쳐가는 노드
	for (int j = 1; j <= N; j++)
	{
		// 출발
		for (int i = 1; i <= N; i++)
		{
			// 도착
			for (int k = 1; k <= N; k++)
			{
				if (Friends[i][j] + Friends[j][k] < Friends[i][k])
				{
					Friends[i][k] = Friends[i][j] + Friends[j][k];
				}
			}
		}
	}

	for (int i = 1; i <= N; i++)
	{
		int nTemp = 0;

		for (int j = 1; j <= N; j++)
		{
			nTemp += Friends[i][j];
		}

		vecAnswer.push_back({i,nTemp});
	}

	sort(vecAnswer.begin(), vecAnswer.end(), cmp);

	cout << vecAnswer.front().first << '\n';

	return 0;
}