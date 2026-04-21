#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> parent;

int find(int x)  // 대표 노드 찾기
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}
void unionfunc(int a, int b)  // 합집합
{
	// 대표 노드 찾기
	a = find(a);  
	b = find(b);

	// 대표 노드끼리 연결
	if (a != b)
		parent[b] = a;
}
bool check(int a, int b)  // 두 노드가 같은 집합인지 확인
{
	a = find(a);
	b = find(b);

	if (a == b)
		return true;

	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	parent.resize(N + 1, 0);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;

		if (a == 0)
			unionfunc(b, c);
		else
		{
			bool ret = check(b, c);

			if (ret)
				cout << "YES" << '\n';
			else
				cout << "NO" << '\n';
		}
	}
}