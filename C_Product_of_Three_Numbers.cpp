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

vector<int> primeFactors;
void primeFact(int n) // compelexity O(sqrt(n))
{
    while (n % 2 == 0)
    {
        primeFactors.push_back(2);
        n /= 2;
    }
    for (int i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0)
        {
            primeFactors.push_back(i);
            n /= i;
        }
    }
    if (n > 2)
        primeFactors.push_back(n);
}

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
        primeFact(n);
        int a = primeFactors[0], b = 1, c = 1;
        if (primeFactors.size() >= 3)
        {
            if (primeFactors[1] != a)
            {
                b = primeFactors[1];
                for (int i = 2; i < primeFactors.size(); i++)
                {
                    c = c * primeFactors[i];
                }
            }
            else
            {
                b = primeFactors[1] * primeFactors[2];
                for (int i = 3; i < primeFactors.size(); i++)
                {
                    c = c * primeFactors[i];
                }
            }
            if (b != 1 && c != 1 && a != b && b != c && a != c)
            {
                yes;
                cout << a << " " << b << " " << c << endl;
            }
            else
                no;
        }
        else
            no;
        primeFactors.clear();
    }

    return 0;
}
