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

	// ������ ����� �� ��ŭ
	for (int i = 0; i < vecGraph[num].size(); i++)
	{
		// first == ���� ����
		if (vecVisited[vecGraph[num][i].first])
		{
			continue;
		}

		// second == USADO ��ġ
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

	// �� ������ ���� USADO�� �� �ٿ� �ϳ��� �־�����.
	// USADO�� K �̻��� ��� �������� ��õ�ǵ��� �� ���̴�.
	for (int i = 0; i < N - 1; i++)
	{
		int nTemp1;
		int nTemp2;
		int nTemp3;

		cin >> nTemp1 >> nTemp2 >> nTemp3;

		vecGraph[nTemp1].push_back({ nTemp2, nTemp3 });
		vecGraph[nTemp2].push_back({ nTemp1, nTemp3 });
	}

	// ������
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