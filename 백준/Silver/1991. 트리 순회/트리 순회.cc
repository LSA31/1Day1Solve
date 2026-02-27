#include <iostream>
using namespace std;

int n;
pair<char, char> graph[26];

void preorder(char c)
{
	if (c != '.')
	{
		cout << c;
		preorder(graph[c - 'A'].first);
		preorder(graph[c - 'A'].second);
	}
}
void inorder(char c)
{
	if (c != '.')
	{
		inorder(graph[c - 'A'].first);
		cout << c;
		inorder(graph[c - 'A'].second);
	}
}
void postorder(char c)
{
	if (c != '.')
	{
		postorder(graph[c - 'A'].first);
		postorder(graph[c - 'A'].second);
		cout << c;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char parent = 0, left = 0, right = 0;
		cin >> parent >> left >> right;

		graph[(parent - 'A')].first = left;
		graph[(parent - 'A')].second = right;
	}
	preorder('A');
	cout << '\n';
	inorder('A');
	cout << '\n';
	postorder('A');
}