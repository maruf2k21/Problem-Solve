#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    for (int i = 0; i, s.size(); i++)
    {
        if (i == 0 && s[i] == '9')
            continue;
        else
        {
            if (s[i] - '0' > '9' - s[i])
            {
                s[i] = (char)('9' - s[i]);
            }
        }
    }
    cout << s << endl;
    return 0;

    return 0;
}