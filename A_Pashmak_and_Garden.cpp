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

    int x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
    {
        if (y1 > y2)
        {
            x3 = x1 + y1 - y2;
            y3 = y2;
        }
        else
        {
            x3 = x1 + y2 - y1;
            y3 = y1;
        }
        x4 = x3;
        y4 = max(y1, y2);
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    }
    else if (y1 == y2)
    {
        cout << x1 << " " << y1 + (abs(x2 - x1)) << " " << x2 << " " << y2 + (abs(x2 - x1));
    }
    else if (x1 == x2 && y1 != y2)
        cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
    else if (abs(x1 - x2) == abs(y2 - y1))
        cout
            << x1 << " " << y2 << " " << x2 << " " << y1 << endl;
    else
        cout << -1 << endl;

    return 0;
}
