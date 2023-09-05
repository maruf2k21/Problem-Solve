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

vector<string> valid;
void generate(string &s, int open, int close)
{
    if (open == 0 && close == 0)
    {
        valid.push_back(s);
        return;
    }
    if (open > 0)
    {
        s.push_back('(');
        generate(s, open - 1, close);
        s.pop_back();
    }
    if (close > 0)
    {
        if (open < close)
        {
            s.push_back(')');
            generate(s, open, close - 1);
            s.pop_back();
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tst;
    cin >> tst;
    while (tst--)
    {
        string s;
        cin >> s;
        string gen;
        generate(gen, s.size(), s.size());
        int flag = 0;
        string ans;
        for (int i = 0; i < valid.size(); i++)
        {
            if (valid[i].find(s) == string::npos)
            {
                flag = 1;
                ans = valid[i];
                break;
            }
        }
        if (flag)
        {
            yes;
            cout << ans << endl;
        }
        else
            no;
        valid.clear();
    }
    return 0;
}
