#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<char>> vect(5, vector<char> (5, ' '));
string S, K;
vector<string> D;

void find(char ch, int& y, int& x)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(vect[i][j] == ch)
            {
                y = i;
                x = j;
                return;
            }
        }
    }
    return;
}
void final()
{
    int y = 0, x = 0, dy = 0, dx = 0;
    for(int i=0; i<D.size(); i++)
    {
        find(D[i][0], y, x);
        find(D[i][1], dy, dx);

        if(y == dy)  // 같은 행에 존재하는 경우
        {
            if(x+1 == 5)
                D[i][0] = vect[y][0];
            else
                D[i][0] = vect[y][x+1];
            
            if(dx+1 == 5)
                D[i][1] = vect[dy][0];
            else
                D[i][1] = vect[dy][dx+1];
        }
        else if(x == dx)  // 같은 열에 존재하는 경우
        {
            if(y+1 == 5)
                D[i][0] = vect[0][x];
            else
                D[i][0] = vect[y+1][x];
            
            if(dy+1 == 5)
                D[i][1] = vect[0][dx];
            else
                D[i][1] = vect[dy+1][dx];
        }
        else
        {
            D[i][0] = vect[y][dx];
            D[i][1] = vect[dy][x];
        }
    }
}
void second_step()
{
    string str = "";
    
    for(int i=0; i<S.length(); i++)
    {
        if(str.length() % 2 != 0)
        {
            if(S[i] == str.back())
            {
                if(S[i] == 'X')
                    str.push_back('Q');
                else
                    str.push_back('X');
            }
        }
        str.push_back(S[i]);
    }

    if(str.length() % 2 != 0)
        str.push_back('X');

    for(int i=0; i<str.length(); i+=2)
        D.push_back(str.substr(i, 2));

    final();
}
int main() {
    cin >> S >> K;

    vector<bool> visited(91, false);
    int y = 0, x = 0;
    for(int i=0; i<K.length(); i++)
    {
        if((!visited[(int)K[i]]) && (K[i] != 'J'))
        {
            vect[y][x] = K[i];
            visited[(int)K[i]] = true;

            x++;
            if(x == 5)
            {
                x = 0;
                y++;
            }
        }
    }
    for(int i=65; i<91; i++)
    {
        if((!visited[i]) && i != 74)
        {
            vect[y][x] = (char)i;

            x++;
            if(x == 5)
            {
                x = 0;
                y++;
            }
        }
    }

    second_step();

    for(int i=0; i<D.size(); i++)
        cout << D[i];

    return 0;
}