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

	priority_queue<int> plusQ;
	priority_queue<int, vector<int>, greater<int>> minusQ;
	int one = 0, zero = 0;
	for (int i = 0; i < n; i++)
	{
		int data;
		cin >> data;

		if (data > 1)
			plusQ.push(data);
		else if (data == 1)
			one++;
		else if (data == 0)
			zero++;
		else
			minusQ.push(data);
	}
	int sum = 0;
	while (plusQ.size() > 1)
	{
		int first = plusQ.top();
		plusQ.pop();
		int second = plusQ.top();
		plusQ.pop();

		sum += (first * second);
	}
	if (!plusQ.empty())
	{
		sum += plusQ.top();
		plusQ.pop();
	}
	while (minusQ.size() > 1)
	{
		int first = minusQ.top();
		minusQ.pop();
		int second = minusQ.top();
		minusQ.pop();

		sum += (first * second);
	}
	if (!minusQ.empty())
	{
		if (zero == 0) // zero가 비어있지 않다면 (음수*0) 은 0이므로 sum 갱신 하지 않음
		{
			sum += minusQ.top();
			minusQ.pop();
		}
	}
	sum += one;

	cout << sum;
}