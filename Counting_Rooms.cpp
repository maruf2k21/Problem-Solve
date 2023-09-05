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
int n, m;
const int mx = 1000 + 123;
bool vis[mx][mx];
char adjMat[mx][mx];
void dfs(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return;
    if (vis[x][y])
        return;
    if (adjMat[x][y] == '#')
        return;
    vis[x][y] = true;
    dfs(x + 1, y);
    dfs(x - 1, y);
    dfs(x, y + 1);
    dfs(x, y - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<pair<int, int>> v;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> adjMat[i][j];
            if (adjMat[i][j] == '.')
                v.push_back({i, j});
        }
    }
    int rooms = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (vis[v[i].first][v[i].second])
            continue;
        dfs(v[i].first, v[i].second);
        rooms++;
    }

    cout << rooms << endl;
    return 0;
}
