#include <bits/stdc++.h>
using namespace std;
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

const int mx = 1e5 + 123;
int arr[mx];
bool vis[mx];
vector<int> node[mx];
int cnt = 0, ans = INT_MIN;
void dfs(int n, int value)
{
    vis[n] = 1;
    for (auto u : node[n])
    {
        if (vis[u] == 0 && arr[u] == 1 && arr[n]==0)
        {
            cnt++;
            vis[u] = 1;
        }
        if (vis[u] == 0 && arr[u] == 0 && arr[n] == 0)
        {
            cnt++;
            dfs(u, arr[u]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        node[n1].pb(n2);
        node[n2].pb(n1);
    }
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    for (int i = 1; i <= n; i++)
    {
        dfs(i, arr[i]);
        ans = max(cnt, ans);
        cnt = 1;
        memz(vis);
    }
    cout << ans << endl;

    return 0;
}
