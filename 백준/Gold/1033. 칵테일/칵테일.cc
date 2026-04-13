#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<bool> visited;
vector<tuple<int, int, int>> graph[10];
int n;
long lcm;  // 최소 공배수
long D[10];  // 각 노드값 저장

long GCD(long x, long y)
{
	if (y == 0)
		return x;
	else
		return GCD(y, x % y);
}
void DFS(int node)
{
	visited[node] = true;

	for (tuple<int, int, int> i : graph[node])
	{
		int next = get<0>(i);
		if (!visited[next])
		{
			D[next] = D[node] * get<2>(i) / get<1>(i); 
			DFS(next);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	visited.resize(n, false);

	lcm = 1;
	for (int i = 0; i < n - 1; i++)
	{
		int a = 0, b = 0, p = 0, q = 0;
		cin >> a >> b >> p >> q;

		graph[a].push_back(make_tuple(b, p, q));
		graph[b].push_back(make_tuple(a, q, p));

		lcm *= (p * q / GCD(p, q));  // 최소 공배수 = 두 수의 곱을 최대 공약수로 나눈 것
	}
	D[0] = lcm;  // 시작점
	DFS(0);
	long mgcd = D[0];  // 최대 공약수

	for (int i = 0; i < n; i++)
		mgcd = GCD(mgcd, D[i]);
	for (int i = 0; i < n; i++)
		cout << D[i] / mgcd << ' ';
}