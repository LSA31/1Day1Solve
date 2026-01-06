#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> chennel;

void find_up()  // KBS를 찾아서 위로 올리기
{
	int now = 0;  // 현재 화살표 위치
	while (now < n)
	{
		if (chennel[now] == "KBS1")
			break;

		cout << 1;
		now++;
	}
	while (now > 0)
	{
		swap(chennel[now], chennel[now - 1]);

		cout << 4;
		now--;
	}
	while (now < n)
	{
		if (chennel[now] == "KBS2")
			break;

		cout << 1;
		now++;
	}
	while (now > 1)
	{
		swap(chennel[now], chennel[now - 1]);

		cout << 4;
		now--;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	chennel.resize(n, "");
	for (int i = 0; i < n; i++)
		cin >> chennel[i];

	find_up();

	return 0;
}