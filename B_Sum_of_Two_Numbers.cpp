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

    ll tst;
    cin >> tst;
    while (tst--)
    {
        int n;
        cin >> n;
        if (n <= 9)
        {
            cout << n / 2 << " " << (int)ceil(n * 1.00 / 2) << endl;
            continue;
        }
        vector<int> v;
        while (n > 0)
        {
            int rem = n % 10;
            v.pb(rem);
            n = n / 10;
        }
        deque<int> a, b;
        bool active = false, flag = false;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] % 2 == 0)
            {
                a.push_front(v[i] / 2);
                b.push_front(v[i] / 2);
            }
            else if (v[i] == 0)
            {
                if (flag == false)
                {
                    a.push_front(0);
                    flag = true;
                }
                else
                {
                    b.push_front(0);
                    flag = false;
                }
            }
            else
            {
                if (active)
                {
                    a.push_front(v[i] / 2 + 1);
                    b.push_front(v[i] / 2);
                    active = false;
                }
                else
                {
                    a.push_front(v[i] / 2);
                    b.push_front(v[i] / 2 + 1);
                    active = true;
                }
            }
        }
        // ordering output
        int i;
        for (i = 0; i < a.size() - 1; i++)
        {
            if (a[i] == 0 && a[i + 1] == 0)
                continue;
            else
                break;
        }
        if (a[i] != 0)
            cout << a[i];
        int tt = 0;
        for (i = i + 1; i < a.size(); i++)
        {
            cout << a[i];
            tt = 1;
        }
        if (tt == 0)
            cout << a[a.size() - 1];
        cout << " ";
        for (i = 0; i < b.size() - 1; i++)
        {
            if (b[i] == 0 && b[i + 1] == 0)
                continue;
            else
                break;
        }
        if (b[i] != 0)
            cout << b[i];
        for (i = i + 1; i < b.size() - 1; i++)
        {
            cout << b[i];
        }
        cout << b[i];
        cout << endl;
    }

    return 0;
}
