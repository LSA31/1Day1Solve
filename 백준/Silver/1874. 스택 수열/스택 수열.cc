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
	vector<char> ret;
	for (int i = 0; i < n; i++)
		cin >> vect[i];

	int num = 1;
	bool flag = true;
	stack<int> st;
	for (int i = 0; i < n; i++)
	{
		if (vect[i] >= num)
		{
			while (vect[i] >= num)
			{
				st.push(num++);
				ret.push_back('+');
			}
			st.pop();
			ret.push_back('-');
		}
		else  // vect[i] < num (현재 수열값 < 자연수)
		{
			if (st.top() > vect[i])
			{
				cout << "NO";
				flag = false;
				break;
			}
			st.pop();
			ret.push_back('-');
		}
	}
	if (flag == true)
	{
		for (int i = 0; i < ret.size(); i++)
			cout << ret[i] << "\n";
	}
}