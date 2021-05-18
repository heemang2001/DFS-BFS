#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool dfs(int n, vector<vector<int>>& computers)
{
	// �̹� ��ȸ�� ����� ����
	if (computers[n][n] == 0)
	{
		return false;
	}

	// ��ȸ �ߴٰ� �����ϱ�
	computers[n][n] = 0;

	// ��� ����ŭ �ݺ�
	for (int i = 0; i < computers.size(); i++)
	{
		// ����� ��尡 �ִٸ� ���
		if (computers[n][i] == 1)
		{
			dfs(i, computers);
		}
	}
}

int solution(int n, vector<vector<int>> computers)
{
	int answer = 0;	

	for (int i = 0; i < n; i++)
	{
		//��ȸ���� ���� ����� dfsŽ���� answer����
		if (computers[i][i] && dfs(i, computers))
		{
			answer++;
		}			
	}

	return answer;
}

int main()
{
	cout << solution(3, { {1,1,0}, {1,1,0}, {0,0,1} }) << '\n'; // 2
	cout << solution(3, { {1,1,0}, {1,1,1}, {0,1,1} }) << '\n'; // 1

	return 0;
}