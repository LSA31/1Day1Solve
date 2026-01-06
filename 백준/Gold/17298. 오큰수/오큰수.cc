#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> vect(n, 0);
	vector<int> ret(n, -1);
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	stack<int> st;
	st.push(0);

	for (int i = 0; i < n; i++)
	{
		while (!st.empty() && vect[st.top()] < vect[i])
		{
			ret[st.top()] = vect[i];
			st.pop();
		}
		st.push(i);
	}
	for (int i = 0; i < n; i++)
		cout << ret[i] << ' ';
}