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
    // cout << tst << endl;
    while (tst--)
    {
        // cout << "tst" << endl;
        string s = "0", ss;
        cin >> ss;
        s += ss;
        int nine = 0, nineidx;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == '9')
            {
                nine = 1;
                nineidx = i;
                break;
            }
        }
        if (nine == 1)
        {
            nineidx = nineidx - 1;
            while (nineidx >= 2 && s[nineidx] == '8')
            {
                nineidx--;
            }
            s[nineidx]++; // nineindx + 1; last nine
            for (int i = 1; i <= nineidx; i++)
            {
                if (s[i] - '0' >= 5)
                {
                    int fiveidx = i - 1;
                    while (fiveidx >= 1 && s[fiveidx] == '4')
                    {
                        fiveidx--;
                    }
                    s[fiveidx]++;
                    nineidx = fiveidx;
                }
            }

            string ans;
            if (s[0] != '0')
                ans.pb(s[0]);
            for (int i = 1; i <= nineidx; i++)
                ans.pb(s[i]);
            for (int i = nineidx + 1; i < s.size(); i++)
                ans.pb('0');
            cout  << ans << endl;
        }
        else
        {
            int five = 0, fiveidx = -1;
            // cout << s << endl;
            for (int i = 1; i < s.size(); i++)
            {
                char ch = s[i];
                if (ch == '5' || ch == '6' || ch == '7' || ch == '8')
                {
                    fiveidx = i;
                    five = 1;
                    break;
                }
            }

            if (five)
            {
                // cout << "five found" << endl;
                // cout << "five = " << five << ", fiveidx = " << fiveidx << endl;
                // cout << "vai " << s[fiveidx] << endl;
                fiveidx = fiveidx - 1;
                // cout << "next fiveidx = " << fiveidx << endl;
                // cout<<"next "<<s[fiveidx]++<<endl;
                while (fiveidx >= 1 && s[fiveidx] == '4')
                {
                    fiveidx--;
                }
                s[fiveidx]++;
                // cout << "how" << endl;

                string ans;
                if (s[0] != '0')
                    ans += s[0];
                for (int i = 1; i <= fiveidx; i++)
                    ans += s[i];
                for (int i = fiveidx + 1; i < s.size(); i++)
                    ans += '0';
                cout << ans << endl;
            }
            else
            {
                // cout << "Five not found" << endl;
                for (int i = 1; i < s.size(); i++)
                    cout << s[i];
                cout << endl;
            }
        }
    }
    return 0;
}
