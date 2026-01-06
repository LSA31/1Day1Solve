#include <iostream>
#include <string>
using namespace std;

int s, p;
string str;
int checkArr[4], myArr[4];
int checkCnt;  // 현재 만족하는 문자의 개수
int ret;

void Add(char c)
{
	switch (c)
	{
	case 'A':
		myArr[0]++;
		if (myArr[0] == checkArr[0])
			checkCnt++;
		break;
	case 'C':
		myArr[1]++;
		if (myArr[1] == checkArr[1])
			checkCnt++;
		break;
	case 'G':
		myArr[2]++;
		if (myArr[2] == checkArr[2])
			checkCnt++;
		break;
	case 'T':
		myArr[3]++;
		if (myArr[3] == checkArr[3])
			checkCnt++;
		break;
	}
}
void Remove(char c)
{
	switch (c)
	{
	case 'A':
		if (myArr[0] == checkArr[0])
			checkCnt--;
		myArr[0]--;
		break;
	case 'C':
		if (myArr[1] == checkArr[1])
			checkCnt--;
		myArr[1]--;
		break;
	case 'G':
		if (myArr[2] == checkArr[2])
			checkCnt--;
		myArr[2]--;
		break;
	case 'T':
		if (myArr[3] == checkArr[3])
			checkCnt--;
		myArr[3]--;
		break;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> s >> p >> str;

	for (int i = 0; i < 4; i++)
	{
		cin >> checkArr[i];

		if (checkArr[i] == 0)
			checkCnt++;
	}
	for (int i = 0; i < p; i++)  // 초기 문자열 추가
		Add(str[i]);

	if (checkCnt == 4)  // A,C,G,T 최소 개수가 모두 0인 경우
		ret++;

	for (int i = p; i < s; i++)
	{
		int j = i - p;

		Add(str[i]);
		Remove(str[j]);

		if (checkCnt == 4)
			ret++;
	}

	cout << ret;
}