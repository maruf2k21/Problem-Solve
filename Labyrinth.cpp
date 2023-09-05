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

int n, m;
const int mx = 1000 + 123;

// directional array
int fx[] = {1, -1, 0, 0}; // works for up-down===>>>>>> down,up
int fy[] = {0, 0, 1, -1}; // works for left-right==>>>> right,left

bool vis[mx][mx];
int level[mx][mx];
char adjMat[mx][mx];
queue<pair<int, int>> q;
// for finding parent
// vector<vector<pair<int, int>>> par(1000 + 123, vector<pair<int, int>>(1000 + 123, {0, 0}));
bool found;
pair<int, int> pp[mx][mx];
void bfs(int x, int y)
{
    vis[x][y] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = p.first + fx[i];
            int ny = p.second + fy[i];
            if (nx >= 0 and nx < n and ny >= 0 and ny < m and vis[nx][ny] == 0 and adjMat[nx][ny] != '#')
            {
                // par[nx][ny]=p; //parent push
                level[nx][ny] = level[p.first][p.second] + 1;
                q.push({nx, ny});
                vis[nx][ny] = true;
                pp[nx][ny] = p;
            }
        }
    }
}
char directionFind(int x2, int y2, int x1, int y1)
{
    if (x1 > x2)
        return 'U';
    if (x2 > x1)
        return 'D';
    if (y1 > y2)
        return 'L';
    return 'R';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int start_x, start_y, end_x, end_y;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> adjMat[i][j];
            if (adjMat[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
            if (adjMat[i][j] == 'B')
            {
                end_x = i;
                end_y = j;
            }
        }
    }

    level[start_x][start_y] = 0;
    q.push({start_x, start_y});
    bfs(start_x, start_y);

    if (vis[end_x][end_y])
    {
        cout << "YES" << endl;
        int temp_x = end_x, temp_y = end_y;
        cout << level[end_x][end_y] << endl;
        string ans;
        while (end_x != start_x || end_y != start_y)
        {
            int xx = pp[end_x][end_y].first;
            int yy = pp[end_x][end_y].second;
            // cout << "parent = " << end_x << " " << end_y << " , next = " << xx << " " << yy << endl;
            ans += directionFind(end_x, end_y, xx, yy);
            end_x = xx;
            end_y = yy;
        }
        reverse(all(ans));
        cout << ans << endl;
    }
    else
        cout << "NO" << endl;

    return 0;
}
