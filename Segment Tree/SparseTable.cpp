// ## Yuji snippet ##//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define ld long double
#define ull unsigned long long
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define pll pair<ll, ll>
#define fr(a, b, i) for (ll i = a; i < b; i++)
#define fre(a, b, i) for (ll i = a; i <= b; i++)
#define srt(a) sort(a.begin(), a.end())
#define rsrt(a) sort(a.rbegin(), a.rend())
#define rv(a) reverse(a.begin(), a.end())
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vl vector<long>
#define vll vector<long long>
#define umi unordered_map<int, int>
#define mi map<int, int>
#define pq priority_queue<int>
#define mpq priority_queue<int, vi, greater<int>>
#define pqll priority_queue<ll>
#define mpqll priority_queue<ll, vll, greater<ll>>
#define vc vector<char>
#define mod 1000000007
#define INF 4e18
#define inf 1e9
#include <bitset>
using namespace std;
using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// find_by_order - give element at xth index
//  order_of_key - find no of elements smaller than x
ll dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
/*-------------------------factorial and modinv-------------------------*/
//(a/b)%mod = ((a%mod)*((b^(mod-2))%mod))%mod

/*-------------------------Sparse Table start-------------------------*/
template <typename Node>
struct SparseTable
{
    vector<vector<Node>> table;
    vector<ll> logValues;
    int n;
    int maxLog;
    vector<ll> a;
    SparseTable(int n1, vector<ll> &arr)
    {
        n = n1;
        a = arr;
        table.resize(n);
        logValues.resize(n + 1);
        maxLog = log2(n);
        logValues[1] = 0;
        for (int i = 2; i <= n; i++)
        {
            logValues[i] = logValues[i / 2] + 1;
        }
        for (int i = 0; i < n; i++)
        {
            table[i].resize(maxLog + 1);
            fill(all(table[i]), Node());
        }
        build();
    }
    void build()
    {
        for (int i = 0; i < n; i++)
        {
            table[i][0] = Node(a[i]);
        }
        for (int i = 1; i <= maxLog; i++)
        {
            for (int j = 0; (j + (1 << i)) <= n; j++)
            {
                table[j][i].merge(table[j][i - 1], table[j + (1 << (i - 1))][i - 1]);
            }
        }
    }
    Node queryNormal(int left, int right)
    {
        Node ans = Node();
        for (int j = logValues[right - left + 1]; j >= 0; j--)
        {
            if ((1 << j) <= right - left + 1)
            {
                ans.merge(ans, table[left][j]);
                left += (1 << j);
            }
        }
        return ans;
    }
    Node queryIdempotent(int left, int right)
    {
        int j = logValues[right - left + 1];
        Node ans = Node();
        ans.merge(table[left][j], table[right - (1 << j) + 1][j]);
        return ans;
    }
};
struct Node1
{
    ll val; // store more info if required
    Node1()
    { // Identity Element
        val = 0;
    }
    Node1(ll v)
    {
        val = v;
    }
    void merge(Node1 &l, Node1 &r)
    {
        val = l.val ^ r.val;
    }
};
/*-------------------------Sparse Table ends-------------------------*/

/*-------------------------SOLUTION-------------------------*/

void solve()
{
    cout << fixed << setprecision(25);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    // precomp();
    while (t--)
    {
        solve();
    }
    return 0;
}