#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// less = set, greater = set, less_equal = multiset, greater_equal = multiset
/// cout<<*X.find_by_order(1)<<endl; // iterator to the k-th largest element
/// cout<<X.order_of_key(-5)<<endl;  // number of items in a set that are strictly smaller than our item
#define endl '\n'
#define ll long long int
#define all(v) v.begin(), v.end()
#define pb push_back //
#define mp make_pair
#define fi first                         //
#define se second                        //
#define yes cout << "YES" << endl        //
#define no cout << "NO" << endl          //
#define M 1000000007                     // 1e9+7
#define gcd(a, b) __gcd(a, b)            //
#define lcm(a, b) a *b / gcd(a, b)       //
#define memz(a) memset(a, 0, sizeof(a))  //
#define memn(a) memset(a, -1, sizeof(a)) //

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tst;
    cin >> tst;
    while (tst--)
    {
        ll n, x;
        cin >> n >> x;
        vector<ll> v(n);
        ll odd = 0, even = 0;
        for (auto &u : v)
        {
            cin >> u;
            if (u % 2)
                odd++;
            else
                even++;
        }
        if (odd == 0)
            cout << "No" << endl;
        else if (x == 1)
        {
            if (odd >= 1)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else if (x <= odd && x % 2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            ll need_odd=0;
            if (even >= x)
            {
                need_odd = 1;
            }
            else
            {
                if (x % 2)
                {
                    if (even % 2 == 0)
                    {
                        need_odd = x - even;
                    }
                    else
                    {
                        even--;
                        need_odd = x - even;
                    }
                }
                else
                {
                    if (even % 2 == 0)
                    {
                        even--;
                        need_odd = x - even;
                    }
                    else
                    {
                        need_odd = x - even;
                    }
                }
            }
            if (need_odd <= odd && need_odd % 2)
                cout
                    << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}
