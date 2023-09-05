#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> Pair;
#define all(a) (a).begin(), (a).end()

const ll N = 1e3+5;
ll n, m, aX, bX, aY, bY;
string s[N];
bool vis[N][N];
ll dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
Pair parent[N][N];

bool isValid(ll i, ll j) {
    return (i >= 0 and i < n and j >= 0 and j < m and s[i][j] != '#' and !vis[i][j]);
}

void bfs() {
    queue<Pair> q;
    q.push({aX, aY});
    vis[aX][aY] = true;
    
    while (!q.empty()) {
        ll x = q.front().first, y = q.front().second;
        q.pop();

        for (ll i = 0; i < 4; i++) {
            ll tempX = x + dir[i][0], tempY = y + dir[i][1];
            if (isValid(tempX, tempY)) {
                q.push({tempX, tempY});
                vis[tempX][tempY] = true;
                parent[tempX][tempY] = {x, y};
            }
        }
    }
}

char directionFind(ll x2, ll y2, ll x1, ll y1) {
    if (y2 == y1 and x1 > x2) return 'U';
    if (y2 == y1 and x1 < x2) return 'D';
    if (x2 == x1 and y2 > y1) return 'R';
    return 'L';
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (ll i = 0; i < n; i++) {
        cin >> s[i];
        for (ll j = 0; j < m; j++) {
            if (s[i][j] == 'A') aX = i, aY = j;
            else if (s[i][j] == 'B') bX = i, bY = j; 
        }
    }

    bfs();

    if (!vis[bX][bY]) {
        cout << "NO" << endl;
        return 0;
    }

    string ans;
    cout<<"end = "<<bX<<" "<<bY<<", start = "<<aX<<" "<<aY<<endl;
    while (bX != aX || bY != aY) {
        ll tempX = parent[bX][bY].first;
        ll tempY = parent[bX][bY].second;

        ans += directionFind(bX, bY, tempX, tempY);
        bX = tempX;
        bY = tempY;
    }

    reverse(all(ans));
    
    cout << "YES" << endl;
    cout << ans.size() << endl;
    cout << ans << endl;
}