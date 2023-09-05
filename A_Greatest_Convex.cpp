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

const int mx = 100;
ll factorial[mx];
ll fact(ll n)
{
    if (n == 0)
        return factorial[n] = 1;
    if (n == 1)
        return factorial[n] = 1;
    return factorial[n] = fact(n - 1) * n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tst;
    cin >> tst;
    ll temp = fact(25);
    while (tst--)
    {
        ll n;
        cin >> n;
        ll ans = -1;
        for (ll i = 2; i <= 20 && i <= n; i++)
        {
            if (factorial[i - 1] % n == 0 || (i + 1) % n == 0)
            {
                ans = i;
                break;
            }
        }
        if (n == 2)
            ans = 1;
        cout << ans << endl;
    }

    return 0;
}
