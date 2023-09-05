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

// direction array

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tst;
    cin >> tst;
    while (tst--)
    {
        int n, m;
        cin >> n >> m;
        int mat[n][m];
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
                if (mat[i][j] == 0)
                    vp.pb({i, j});
            }
        }
        int move = 0;
        for (auto u : vp)
        {
            bool ok = true;
            int x = u.fi, y = u.se;
            for (int i = 0; i < m; i++)
            {
                if (mat[x][i] == 1)
                {
                    ok = false;
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (mat[i][y] == 1)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                move++;
                mat[u.fi][u.se] = 1;
            }
        }
        (move % 2 == 0) ? (cout << "Vivek" << endl) : cout << "Ashish" << endl;
    }

    return 0;
}
