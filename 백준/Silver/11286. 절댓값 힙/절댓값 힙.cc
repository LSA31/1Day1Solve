#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare
{
	bool operator()(int o1, int o2)
	{
		int first_abs = abs(o1);
		int second_abs = abs(o2);

		if (first_abs == second_abs)
			return o1 > o2;
		else
			return first_abs > second_abs;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, compare> myQ;

	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;

		if (num == 0)
		{
			if (myQ.empty())
				cout << 0 << '\n';
			else
			{
				cout << myQ.top() << '\n';
				myQ.pop();
			}
		}
		else
		{
			myQ.push(num);
		}
	}
}