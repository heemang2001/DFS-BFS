#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int answer = 100;

//���۴ܾ�, ��ǥ�ܾ�, �ܾ��Ʈ, �ܾ��Ʈ��뿩��, ��ǥ���� �� Ƚ��(����)
void dfs(string begin, string target, vector<string> words, vector<bool>& useCheck, int cnt = 0)
{
	//�ܾ��� �����ŭ �ݺ�
	for (int i = 0; i < words.size(); i++)
	{
		//���ĺ����� ��ġ���� �ʱ�ȭ
		int count = 0;

		//�ѱ��ھ� ���ϸ鼭 ���ڰ� �ٸ���� ī��Ʈ ����
		for (int j = 0; j < words[i].length(); j++)
		{
			if (!useCheck[i] && begin[j] != words[i][j])
			{
				count++;
			}
		}
			
		//ī��Ʈ�� 1�̶��(�� ���ڸ� �ٸ����)
		if (count == 1)
		{
			//1���ڸ� �ٸ� �ܾ target�ܾ��̰� answer�� ���ݱ��� ���� ����+1���� ū��� answer����
			if (target == words[i] && answer > cnt + 1)
			{
				answer = cnt + 1;
				return;
			}

			//�ܾ ����ߴ� üũ�ϰ� ���
			useCheck[i] = true;
			dfs(words[i], target, words, useCheck, cnt + 1);

			//�Լ��� ���°�� �ܾ��뿩�� ����
			useCheck[i] = false;
		}
	}
}

int solution(string begin, string target, vector<string> words)
{
	//����� �ܾ� üũ��(words�� ���̸�ŭ �����ϰ� false�� �ʱ�ȭ�Ѵ�.)
	vector<bool> useCheck(words.size(), false);

	dfs(begin, target, words, useCheck);

	//answer�� 100�̸� target���� ���������Ƿ� 0�� �����Ѵ�.
	if (answer == 100)
	{
		return 0;
	}

	//�������� ���õȴٸ� target���� ����ª�� Ƚ���� ����
	return answer;
}

int main()
{
	cout << solution("hit", "cog", { "hot","dot", "dog", "lot", "log", "cog", }) << '\n';	// 4

	answer = 100;
	cout << solution("hit", "cog", { "hot","dot", "dog", "lot", "log"}) << '\n';			// 0

	return 0;
}