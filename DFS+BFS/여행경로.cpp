#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int max_cnt = 0;

void DFS(string start, vector<vector<string>>& tickets, vector<bool>& visit, vector<string>& answer, vector<string>& temp, int cnt)
{
	temp.push_back(start);

	if (max_cnt < cnt)
	{
		max_cnt = cnt;
		answer = temp;
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		if (start == tickets[i][0] && !visit[i])
		{
			visit[i] = true;
			DFS(tickets[i][1], tickets, visit, answer, temp, cnt + 1);
			visit[i] = false;
		}
	}

	temp.pop_back();
}

vector<string> solution(vector<vector<string>> tickets)
{
	int cnt = 0;
	vector<string> answer, temp;
	vector<bool> visit(tickets.size(), false);
	sort(tickets.begin(), tickets.end());
	DFS("ICN", tickets, visit, answer, temp, cnt);
	return answer;
}

int main()
{	
	//vector<string> vecAnswer = solution({ {"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"} });
	//vector<string> vecAnswer = solution({ {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} });
	//vector<string> vecAnswer = solution({ {"ICN","A"} ,{"ICN","A"},{"A","ICN"} });
	//vector<string> vecAnswer = solution({ {"ICN", "SFO"},{"SFO", "ICN"},{"ICN", "SFO"},{"SFO", "QRE"} });	
	//vector<string> vecAnswer = solution({ {"ICN", "BOO"},{"ICN", "COO"},{"COO", "DOO"},{"DOO", "COO"},{"BOO", "DOO"},{"DOO", "BOO"},{"BOO", "ICN"},{"COO", "BOO"} });

	vector<string> vecAnswer = solution({ {"ICN","A"} ,{"A","B"},{"A","C"},{"C","A"},{"B","D"} });


	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	// ["ICN", "JFK", "HND", "IAD"]
	// ["ICN", "ATL", "ICN", "SFO", "ATL", "SFO"]

	// ["ICN", "SFO", "ICN", "SFO", "QRE"]
	// ["ICN", "BOO", "DOO", "BOO", "ICN", "COO", "DOO", "COO", "BOO"]

	return 0;
}