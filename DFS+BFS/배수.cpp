#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

#define MAX_NUM 11111111111111111111

unsigned long long N;
unsigned long long answer = UINT64_MAX;

void DFS(unsigned long long num)
{	
	if (num % N == 0)
	{
		answer = min(answer, num);
	}

	if (num > MAX_NUM / 10)
	{
		return;
	}

	DFS(num * 10 + 1);
	DFS(num * 10);
}

int main()
{
	cin >> N;

	DFS(1);

	if (answer == UINT64_MAX)
	{
		answer = 0;
	}

	cout << answer << '\n';

	return 0;
}