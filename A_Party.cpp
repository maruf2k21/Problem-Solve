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

const int mx = 1e5;
bool vis[mx];
int level[mx];
queue<int> q;
vector<int> g[mx];
int mxx;
void bfs(int n)
{

    // q.push(n);
    // level[n] = 0;
    while (!q.empty())
    {
        int top = q.front();
        // vis[top] = true;
        q.pop();
        for (auto u : g[top])
        {
            if (vis[u])
                continue;

            level[u] = level[top] + 1;
            q.push(u);
            vis[u] = true;
        }
        mxx = max(mxx, level[top]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> root;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a == -1)
        {
            root.pb(i);
        }
        else
        {
            g[i].pb(a);
            g[a].pb(i);
        }
    }
    int ans = 0;
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << i << " = ";
    //     for (auto u : g[i])
    //         cout << u << " ";
    //     cout << endl;
    // }
    // cout << "root size = " << root.size() << endl;
    // for (auto u : root)
    //     cout << u << " ";
    // cout << endl;
    for (auto u : root)
    {
        mxx = 0;
        // cout << "loop = " << u << endl;
        vis[u] = true;
        level[u] = 0;
        q.push(u);
        bfs(u);
        ans = max(ans, mxx);
    }
    cout << ans + 1 << endl;
    // cout << "ans = " << ans << endl;
    // cout << "mx = " << mxx << endl;
    // vector<int> temp;
    // for (int i = 0; i < mx; i++)
    // {
    //     if (level[i] > 0)
    //         temp.pb(level[i]);
    // }
    // cout << "Size = " << temp.size() << endl;
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     cout << temp[i] << endl;
    // }

    return 0;
}
