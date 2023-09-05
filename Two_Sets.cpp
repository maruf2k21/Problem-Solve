#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (sum % 2)
        cout << "NO" << endl;
    else
    {

        map<int, int> m;
        int need = sum / 2;
        if (need % 2)
            cout << "NO" << endl;
        else
        {
            vector<int> v;
            for (int i = n; i >= 1; i--)
            {
                if (m[i] == 0)
                {
                    if (need - i >= 0)
                    {
                        v.push_back(i);
                        need = need - i;
                        m[i]++;
                    }
                }
            }
            if (need == 0)
            {
                cout << "YES" << endl;
                cout << v.size() << endl;
                ;
                map<int, int> mm;
                for (auto u : v)
                {
                    cout << u << " ";
                    mm[u]++;
                }
                cout << endl;
                cout << n - v.size() << endl;
                for (int i = 1; i <= n; i++)
                {
                    if (mm[i] == 0)
                        cout << i << " ";
                }
                cout << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}