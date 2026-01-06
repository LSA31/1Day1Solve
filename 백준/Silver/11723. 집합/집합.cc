#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<bool> S(21, 0);
	int m = 0;
	cin >> m;

	string cal = "";
	int x = 0;
	for (int i = 0; i < m; i++)
	{
		cin >> cal;

		if (cal != "all" && cal != "empty")
			cin >> x;

		if (cal == "add")
			S[x] = true;
		else if (cal == "remove")
			S[x] = false;
		else if (cal == "check")
		{
			if (S[x] == true)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cal == "toggle")
		{
			if (S[x] == false)
				S[x] = true;
			else
				S[x] = false;
		}
		else if (cal == "all")
			fill(S.begin(), S.end(), true);
		else
			fill(S.begin(), S.end(), false);
	}

	return 0;
}