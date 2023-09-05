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

ll n, m, danger = 1, ans = 1;
const int mx = 1e5;
bool vis[mx];
vector<int> g[mx];
void dfs(int vertex)
{
    vis[vertex] = 1;
    for (auto u : g[vertex])
    {
        if (vis[u] == 0)
        {
            danger = danger * 2;
            dfs(u);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        g[n1].pb(n2);
        g[n2].pb(n1);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            dfs(i);
    }

    cout << danger << endl;
    return 0;
}
