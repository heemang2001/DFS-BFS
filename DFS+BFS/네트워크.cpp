#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool dfs(int n, vector<vector<int>>& computers)
{
	// 이미 순회한 노드라면 리턴
	if (computers[n][n] == 0)
	{
		return false;
	}

	// 순회 했다고 변경하기
	computers[n][n] = 0;

	// 노드 수만큼 반복
	for (int i = 0; i < computers.size(); i++)
	{
		// 연결된 노드가 있다면 재귀
		if (computers[n][i])
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
		//순회하지 않은 노드라면 dfs탐색후 answer증가
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