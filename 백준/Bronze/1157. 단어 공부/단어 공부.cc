#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string word = "";
	cin >> word;

	int arr[100] = { 0, };
	for (int i = 0; i < word.size(); i++)
	{
		word[i] = toupper(word[i]);  // 모든 문자 대문자로 변경

		arr[(int)word[i]]++;
	}
	int Max = -1, index = 0;
	for (int i = 0; i < 100; i++)
	{
		if (arr[i] > Max)
		{
			Max = arr[i];
			index = i;
		}
	}
	bool flag = false;  // 가장 많이 사용된 알파벳이 여러 개인 경우
	for (int i = index + 1; i < 100; i++)
	{
		if (arr[i] == Max)
		{
			flag = true;
			break;
		}
	}
	
	if (flag == true)
		cout << '?';
	else
		cout << (char)index;

	return 0;
}