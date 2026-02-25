#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> vect;
int yy, xx;
bool row[5];
bool col[5];
bool diag[2];

void find(int num)
{
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            if (vect[y][x] == num)
            {
                vect[y][x] = -1;
                yy = y;
                xx = x;
                return;
            }
        }
    }
}
int check()
{
    int cnt = 0;
    int rr = 0, cc = 0, diagL = 0, diagR = 0;
    if (row[xx] == false)
    {
        for (int i = 0; i < 5; i++)
        {
            if (vect[i][xx] == -1)
                rr++;
        }
        if (rr == 5)
        {
            cnt++;
            row[xx] = true;
        }
    }
    if (col[yy] == false)
    {
        for (int i = 0; i < 5; i++)
        {
            if (vect[yy][i] == -1)
                cc++;
        }
        if (cc == 5)
        {
            cnt++;
            col[yy] = true;
        }
    }
    if (diag[0] == false)
    {
        for (int i = 0; i < 5; i++)
        {
            if (vect[i][i] == -1)
                diagL++;
        }
        if (diagL == 5)
        {
            cnt++;
            diag[0] = true;
        }
    }
    if (diag[1] == false)
    {
        for (int i = 0; i < 5; i++)
        {
            if (vect[4 - i][i] == -1)
                diagR++;
        }
        if (diagR == 5)
        {
            cnt++;
            diag[1] = true;
        }
    }
    return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vect.resize(5, vector<int>(5, 0));
	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++)
		{
			cin >> vect[y][x];
		}
	}
    vector<int> call(25, 0);
    for (int i = 0; i < 25; i++)
        cin >> call[i];

    int cnt = 0;
    for (int i = 0; i < 25; i++)
    {
        find(call[i]);

        cnt += check();

        if (cnt >= 3)
        {
            cout << i + 1;
            return 0;
        }
    }
}