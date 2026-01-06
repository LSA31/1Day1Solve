#include <iostream>
#include <queue>
#include <functional>  // greater, less
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> heap;
	int x = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x;

		if (x == 0)
		{
			if (heap.size() == 0)
				cout << 0 << '\n';
			else
			{
				cout << heap.top() << '\n';
				heap.pop();
			}
		}
		else
			heap.push(x);
	}

	return 0;
}