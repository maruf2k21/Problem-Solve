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

    int tst;
    cin >> tst;
    while (tst--)
    {
        int n;
        cin >> n;
        int arr[n * 2];
        int odd = 0, eve = 0;
        for (auto &u : arr)
        {
            cin >> u;
            if (u % 2)
                odd++;
            else
                eve++;
        }

        if (n == 2)
            cout << 1 << " " << 2 << endl;
        else
        {
            vector<int> vo, ve;
            if (odd % 2 && eve % 2)
            {
                int fo = 0, fe = 0;
                for (int i = 0; i < 2 * n; i++)
                {
                    if (arr[i] % 2 == 1)
                    {
                        if (fo == 0)
                            fo = 1;
                        else
                            vo.pb(i + 1);
                    }
                    else
                    {
                        if (fe == 0)
                            fe = 1;
                        else
                            ve.pb(i + 1);
                    }
                }
            }
            else if (odd % 2 == 0 && eve % 2 == 0)
            {
                int f = 1;
                if (odd == 2 * n)
                    f = 1;
                else if (eve == 2 * n)
                    f = 0;
                int cnt = 0;
                for (int i = 0; i < 2 * n; i++)
                {
                    if (f == arr[i] % 2 && cnt < 2)
                        cnt++;
                    else
                    {
                        if (arr[i] % 2)
                            vo.pb(i + 1);
                        else
                            ve.pb(i + 1);
                    }
                }
            }

            for (int i = 0; i < vo.size(); i += 2)
                cout << vo[i] << " " << vo[i + 1] << endl;

            for (int i = 0; i < ve.size(); i += 2)
                cout << ve[i] << " " << ve[i + 1] << endl;
        }
    }
    return 0;
}
