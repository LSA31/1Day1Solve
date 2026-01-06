#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int white(const vector<vector<char>>& vect)
{
	int cnt = 0;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (y % 2 == 0)  //짝수 줄
			{
				if (x % 2 == 0)  //짝수 줄의 짝수 칸들
				{
					if (vect[y][x] != 'W')
						cnt++;
				}
				else  //짝수 줄의 홀수 칸들
				{
					if (vect[y][x] != 'B')
						cnt++;
				}
			}
			else  //홀수 줄
			{
				if (x % 2 != 0)  //홀수 줄의 홀수 칸들
				{
					if (vect[y][x] != 'W')
						cnt++;
				}
				else  //홀수 줄의 짝수 칸들
				{
					if (vect[y][x] != 'B')
						cnt++;
				}
			}
		}
	}

	return cnt;
}
int black(const vector<vector<char>>& vect)
{
	int cnt = 0;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (y % 2 == 0)  //짝수 줄
			{
				if (x % 2 == 0)  //짝수 줄의 짝수 칸들
				{
					if (vect[y][x] != 'B')
						cnt++;
				}
				else  //짝수 줄의 홀수 칸들
				{
					if (vect[y][x] != 'W')
						cnt++;
				}
			}
			else  //홀수 줄
			{
				if (x % 2 != 0)  //홀수 줄의 홀수 칸들
				{
					if (vect[y][x] != 'B')
						cnt++;
				}
				else  //홀수 줄의 짝수 칸들
				{
					if (vect[y][x] != 'W')
						cnt++;
				}
			}
		}
	}

	return cnt;
}
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<char>> v(n, vector<char>(m));
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> v[y][x];
		}
	}
	int height = n - 7;  //세로 기준 만들 수 있는 체스판
	int width = m - 7;  //가로 기준 만들 수 있는 체스판

	int Min = 64;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			vector<vector<char>> vect(8, vector<char>(8));  //8x8 체스판
			int h = 0;
			for (int i = y; i < y + 8; i++)  //8x8 체스판 생성
			{
				int w = 0;
				for (int j = x; j < x + 8; j++)
				{
					vect[h][w] = v[i][j];
					w++;
				}
				h++;
			}
			int W_ret = white(vect);
			int B_ret = black(vect);
			int min_ret = min(W_ret, B_ret);
			
			if (min_ret < Min)
				Min = min_ret;
		}
	}
	cout << Min;
}