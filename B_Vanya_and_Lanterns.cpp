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

    int n, len;
    cin >> n >> len;
    vector<int> v(n);
    for (auto &u : v)
        cin >> u;
    sort(all(v));

    int first = v[0] - 0, last = len - v.back();
    int mx = max(first, last);
    // cout << first << endl;
    double ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] - v[i - 1] > ans)
            ans = v[i] - v[i - 1];
    }
    ans = ans / 2;
    if (mx > ans)
        ans = mx;
    printf("%0.10lf\n", ans);

    return 0;
}
