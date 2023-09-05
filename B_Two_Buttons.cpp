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
const int mx = 1e4;
bool vis[mx];
int level[mx];
int n, m;
void bfs(int nn)
{
    queue<int> q;
    q.push(nn);
    level[nn] = 0;
    vis[nn] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u - 1 > 0 && vis[u - 1] == 0)
        {
            level[u - 1] = level[u] + 1;
            q.push(u - 1);
            vis[u - 1] = 1;
        }
        if (u * 2 > 0 && u * 2 <= mx && u * 2 <= m * 2 && vis[u * 2] == 0)
        {
            level[u * 2] = level[u] + 1;
            q.push(u * 2);
            vis[u * 2] = 1;
        }
        if (u - 1 == m || u * 2 == m)
        {
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    bfs(n);
    cout << level[m] << endl;

    return 0;
}
