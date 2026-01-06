#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq; // 우선순위 큐
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;

		pq.push(data);
	}
	int sum = 0;
	while (pq.size() != 1)
	{
		int data1 = pq.top();
		pq.pop();

		int data2 = pq.top();
		pq.pop();

		sum += (data1 + data2);
		pq.push(data1 + data2);
	}
	cout << sum;
}