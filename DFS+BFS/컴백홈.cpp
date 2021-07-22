#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int R, C, K;
int answer;
vector<int> vecAnswer;
bool isVisited[6][6];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void DFS(int x, int y, int cnt, vector<string>& vecMap)
{
	// ������ ������ �̵�Ƚ���� K�� ��츸
	if (cnt == K && x == 0 && y == C - 1)
	{
		answer++;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		// �湮�� ����
		// ���� ���
		if (next_x <= -1 || next_x >= R || next_y <= -1 || next_y >= C)
		{
			continue;
		}

		// T�� �ȵ�
		if (vecMap[next_x][next_y] == 'T')
		{
			continue;
		}

		// �̹� �湮�߾��ٸ� 
		if (isVisited[next_x][next_y])
		{
			continue;
		}

		// �ش� ���� �湮ó��
		isVisited[next_x][next_y] = true;

		// ���� ��ġ�� �̵�
		DFS(next_x, next_y, cnt + 1, vecMap);

		// ���� ��ġ�� �̵��Ŀ� �ش� ��ġ�湮 ��� ����
		isVisited[next_x][next_y] = false;
	}
}

int main()
{
	cin >> R >> C >> K;

	vector<string> vecMap(R);

	for (int i = 0; i < R; i++)
	{
		string sTemp;
		cin >> sTemp;
		vecMap[i] = sTemp;
	}

	isVisited[R - 1][0] = true;
	DFS(R - 1, 0, 1, vecMap);

	cout << answer << '\n';

	return 0;
}