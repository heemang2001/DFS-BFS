#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//����, ����Ƚ��, ã�ƾ� �ϴ� ����, �� ����, ������� ��
void dfs(vector<int>& numbers, int& answer, int target, int count = 0, int sum = 0)
{
	//���������� ��ȸ�ߴٸ�
	if (count == numbers.size() - 1)
	{
		//���ݱ��� ���Ѱ��� ������ ���Ҹ� ���Ҷ� Ÿ�ٰ� ���ٸ� ī��Ʈ ����
		if (target == sum + numbers[count])
		{
			answer++;
		}

		//���ݱ��� ���Ѱ��� ������ ���Ҹ� ���� Ÿ�ٰ� ���ٸ� ī��Ʈ ����
		if (target == sum - numbers[count])
		{
			answer++;
		}

		return;
	}

	//�ִ���̱��� �����ʾҴٸ� ���ϰų� �����·� Ž��
	dfs(numbers, answer, target, count + 1, sum + numbers[count]);
	dfs(numbers, answer, target, count + 1, sum - numbers[count]);
}

int solution(vector<int> numbers, int target)
{
	int answer = 0;

	dfs(numbers, answer, target);

	return answer;
}

int main()
{
	cout << solution({ 1,1,1,1,1 }, 3) << '\n';

	return 0;
}