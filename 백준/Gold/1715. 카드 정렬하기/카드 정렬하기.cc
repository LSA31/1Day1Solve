#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;  // 오름차순
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		pq.push(t);
	}
	int sum = 0;
	while (pq.size() > 1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();

		sum += (first + second);
		pq.push(first + second);
	}
	cout << sum;

	return 0;
}