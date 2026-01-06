#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string word[20000];

int cmp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	else
		return a.length() < b.length();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> word[i];

	sort(word, word + N, cmp);

	for (int i = 0; i < N; i++)
	{
		if (word[i] == word[i - 1])
			continue;
		else
			cout << word[i] << '\n';
	}
	return 0;
}