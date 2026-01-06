// 제로
// 스택으로 구현

#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K = 0;
	cin >> K;

	stack<int> st;
	int n = 0;
	for (int i = 0; i < K; i++)
	{
		cin >> n;

		if (n == 0 && !(st.empty()))
			st.pop();
		else
			st.push(n);
	}
	int sum = 0, L = st.size();
	for (int i = 0; i < L; i++)
	{
		sum += st.top();
		st.pop();
	}
	cout << sum;

	return 0;
}