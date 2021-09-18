#include<iostream>
#include<queue>
#include<vector>

#define endl "\n"
#define MAX 201
using namespace std;

int A, B, C;
bool Visit[MAX][MAX][MAX];

vector<int> V;

void Input()
{
	cin >> A >> B >> C;
}

void Solution()
{
	queue<pair<pair<int, int>, int>> Q;
	Q.push(make_pair(make_pair(0, 0), C));

	while (Q.empty() == 0)
	{
		int a = Q.front().first.first;
		int b = Q.front().first.second;
		int c = Q.front().second;
		Q.pop();

		if (Visit[a][b][c] == true) continue;
		Visit[a][b][c] = true;

		if (a == 0) V.push_back(c);

		// A물통에서 B물통으로 줄 때
		if (a + b > B) Q.push(make_pair(make_pair(a + b - B, B), c));
		else Q.push(make_pair(make_pair(0, a + b), c));

		// A물통에서 C물통으로 줄 때
		if (a + c > C) Q.push(make_pair(make_pair(a + c - C, b), C));
		else Q.push(make_pair(make_pair(0, b), a + c));

		// B물통에서 A물통으로 줄 때
		if (b + a > A) Q.push(make_pair(make_pair(A, b + a - A), c));
		else Q.push(make_pair(make_pair(b + a, 0), c));

		// B물통에서 C물통으로 줄 때
		if (b + c > C) Q.push(make_pair(make_pair(a, b + c - C), C));
		else Q.push(make_pair(make_pair(a, 0), b + c));

		// C물통에서 A물통으로 줄 때
		if (c + a > A) Q.push(make_pair(make_pair(A, b), c + a - A));
		else Q.push(make_pair(make_pair(c + a, b), 0));

		// C물통에서 B물통으로 줄 때
		if (c + b > B) Q.push(make_pair(make_pair(a, B), c + b - B));
		else Q.push(make_pair(make_pair(a, b + c), 0));
	}

	sort(V.begin(), V.end());
	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << " ";
	}
	cout << endl;
}

void Solve()
{
	Input();
	Solution();
}

int main(void)
{
	Solve();

	return 0;
}