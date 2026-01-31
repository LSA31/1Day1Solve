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

	priority_queue<int> posi;  // 1보다 큰 양수
	priority_queue<int, vector<int>, greater<int>> nega;  // 음수
	int one = 0, zero = 0;  // 1, 0의 개수
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> num;

		if (num > 1)
			posi.push(num);
		else if (num < 0)
			nega.push(num);
		else if (num == 1)
			one++;
		else
			zero++;
	}

	int sum = 0;
	// 양수 처리
	while (posi.size() > 1)
	{
		int first = posi.top();
		posi.pop();
		int second = posi.top();
		posi.pop();

		sum += (first * second);
	}
	if (!posi.empty())
		sum += posi.top();

	// 음수 처리
	while (nega.size() > 1)
	{
		int first = nega.top();
		nega.pop();
		int second = nega.top();
		nega.pop();

		sum += (first * second);
	}
	if ((!nega.empty()) && (zero == 0))
		sum += nega.top();

	sum += one;

	cout << sum;

	return 0;
}