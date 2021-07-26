#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define MAX_NUM 100001

int N;
int Parent[MAX_NUM];
bool IsVisited[MAX_NUM];
vector<int> vecTree[MAX_NUM];

void DFS(int node)
{
	IsVisited[node] = true;

	for (int i = 0; i < vecTree[node].size(); i++)
	{
		int next_node = vecTree[node][i];

		if (!IsVisited[next_node])
		{
			Parent[next_node] = node;
			DFS(next_node);
		}
	}
}

int main()
{
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int nTemp1;
		int nTemp2;

		cin >> nTemp1 >> nTemp2;

		vecTree[nTemp1].push_back(nTemp2);
		vecTree[nTemp2].push_back(nTemp1);
	}

	DFS(1);

	for (int i = 2; i <= N; i++)
	{
		cout << Parent[i] << '\n';
	}

	return 0;
}

// 메모리 초과문제 (256 MB)
//
//int N;
//int answer;
//int Depth[MAX_NUM];
//bool IsVisited[MAX_NUM];
//
//void DFS(int node, vector<vector<int>>& vecTree)
//{
//	for (int i = 2; i <= N; i++)
//	{
//		if (vecTree[node][i] == 1 && !IsVisited[i])
//		{
//			Depth[i] = Depth[node] + 1;
//			IsVisited[i] = true;
//			DFS(i, vecTree);
//		}
//	}
//}
//
//int FindParent(int node, vector<vector<int>>& vecTree)
//{
//	int ParentDepth = Depth[node] - 1;
//
//	for (int i = 1; i <= N; i++)
//	{
//		if (Depth[i] == ParentDepth && vecTree[node][i] == 1)
//		{
//			return i;
//		}
//	}
//}
//
//int main()
//{
//	cin >> N;
//
//	vector<vector<int>> vecTree(N+1, vector<int>(N+1));
//	vector<int> vecAnswer;
//
//	for (int i = 0; i < N-1; i++)
//	{
//		int nTemp1;
//		int nTemp2;
//
//		cin >> nTemp1 >> nTemp2;
//
//		vecTree[nTemp1][nTemp2] = 1;
//		vecTree[nTemp2][nTemp1] = 1;
//	}
//
//	IsVisited[1] = true;
//	DFS(1, vecTree);
//
//	for (int i = 2; i <= N; i++)
//	{
//		vecAnswer.push_back(FindParent(i, vecTree));
//	}
//
//	for (int i = 0; i < vecAnswer.size(); i++)
//	{
//		cout << vecAnswer[i] << '\n';
//	}
//
//	return 0;
//}