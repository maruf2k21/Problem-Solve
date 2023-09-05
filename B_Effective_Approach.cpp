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

    ll n;
    cin >> n;ll arr[n];
    for (auto &u : arr)
        cin >> u;

    map<ll, ll> vas, pat;
    for (ll i = 0; i < n; i++)
        vas[arr[i]] = i + 1;
    int cnt = 0;
    for (ll i = n - 1; i >= 0; i--)
    {
        cnt++;
        pat[arr[i]] = cnt;
    }

    ll q, vs = 0, ps = 0;
    cin >> q;
    while (q--)
    {
        ll x;
        cin >> x;
        vs += vas[x];
        ps += pat[x];
    }
    cout << vs << " " << ps << endl;

    return 0;
}
