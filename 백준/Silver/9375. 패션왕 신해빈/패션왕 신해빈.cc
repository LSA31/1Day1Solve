#include <iostream>
#include <map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case = 0;
    cin >> test_case;
    for (int t = 0; t < test_case; t++)
    {
        int n = 0;
        cin >> n;

        map<string, int> m;
        for (int i = 0; i < n; i++)
        {
            string name, type;
            cin >> name >> type;

            m[type]++;
        }

        int ret = 1;
        for (auto& p : m)
            ret *= (p.second + 1);

        cout << ret - 1 << '\n';
    }

    return 0;
}