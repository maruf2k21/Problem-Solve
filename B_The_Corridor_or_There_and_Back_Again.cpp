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
        int n;
        cin >> n;
        map<int, int> room, active;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            if (room[a] == 0)
            {
                room[a] = 1;
                active[a] = INT_MAX;
                active[a] = min(active[a], a + b);
            }
            else if (room[a] == 1)
            {
                active[a] = min(active[a], a + b);
            }
        }

        int r = 1, sec = 1;
        while (true)
        {
            if (room[r + 1] != 1)
            {
                r++;
                sec++;
            }
            else if (room[r + 1] && active[r + 1] > r + 1)
            {
                r++;
                sec++;
            }
            int temps = sec, flag = 0;
            for (int i = r - 1; i >= 1; i--)
            {
                temps++;
                if (room[i] == 1 && active[i] <= temps)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                break;
        }
        cout << r - 1 << endl;
    }

    return 0;
}
