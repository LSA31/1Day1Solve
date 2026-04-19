#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int send[6] = { 0,0,1,1,2,2 };
int recv[6] = { 1,2,0,2,0,1 };
int now[3];
bool visited[201][201];
vector<int> ans;

void BFS()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = true;
	ans.push_back(now[2]);

	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		
		int A = p.first, B = p.second,
			C = now[2] - A - B;

		for (int i = 0; i < 6; i++)
		{
			int next[3] = { A,B,C };
			next[recv[i]] += next[send[i]];
			next[send[i]] = 0;

			// 받은 물통의 양이 용량을 넘길 때
			if (next[recv[i]] > now[recv[i]])
			{
				next[send[i]] = next[recv[i]] - now[recv[i]];
				next[recv[i]] = now[recv[i]];
			}
			// A와 B의 물의 양을 통해 방문 배열 체크
			if (!visited[next[0]][next[1]])
			{
				visited[next[0]][next[1]] = true;
				q.push(make_pair(next[0], next[1]));

				if (next[0] == 0)
					ans.push_back(next[2]);
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> now[0] >> now[1] >> now[2];

	BFS();
	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
}