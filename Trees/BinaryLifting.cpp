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

ll fact[1000004];
ll modinv[1000004];

// finding power of something
ll power(ll a, ll b, ll m = mod)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b = b >> 1;
    }
    return res;
    // log(x)
}

void precomp()
{
    modinv[0] = 1;
    fact[0] = 1;
    for (ll i = 1; i <= 1000000; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        modinv[i] = power(fact[i], mod - 2);
    }
}

// nCr calculation
ll ncr(ll n, ll r)
{
    if (n < 0 || r < 0 || r > n)
        return 0;

    return (((fact[n] * modinv[r]) % mod) * modinv[n - r]) % mod;
}

/*-------------------------SIEVE AND PRIME-------------------------*/

// check whether number is prime or not for first 1000004 whole numbers only
vll prime(1);
void sieve()
{
    prime.resize(1000004, 1);
    prime[0] = prime[1] = false;

    for (ll i = 2; i <= 1000004; i++)
    {
        for (ll j = i * i; j <= 1000004; j += i)
        {
            prime[j] = false;
        }
    }
}

// give first n prime numbers
vll primeGenerator(ll n)
{
    ll *arr = new ll[n + 1]();
    vector<ll> vect;
    for (ll i = 2; i <= n; i++)
        if (arr[i] == 0)
        {
            vect.pb(i);
            for (ll j = 2 * i; j <= n; j += i)
                arr[j] = 1;
        }
    return vect;
}

/*-------------------------LCM-------------------------*/

ll lcm(ll a, ll b)
{
    return a / (__gcd(a, b)) * b;
}

// mod stuff starts here
ll invmod(ll a, ll m = mod) { return power(a, m - 2, m); } // For prime mod

ll MOD(ll x)
{
    return ((x % mod + mod) % mod);
}

ll mAdd(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mSub(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mMul(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mDiv(ll a, ll b, ll m = mod)
{
    a = a % m;
    b = b % m;
    return mMul(a, invmod(b, m), m);
}

/*-------------------------DSU begin-------------------------*/

class DSU
{
private:
    vi parent, size, rank;
    int components;

public:
    DSU(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
        components = n;
    }
    int getPar(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = getPar(parent[node]);
    }
    void unite(int u, int v)
    {
        int pu = getPar(u);
        int pv = getPar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        components--;
    }
    void uniteR(int u, int v)
    {
        int pu = getPar(u);
        int pv = getPar(v);

        if (pu == pv)
            return;

        if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else if (rank[pv] > rank[pu])
        {
            parent[pu] = pv;
        }
        else
        {
            parent[pv] = pu;
            rank[pu] += 1;
        }
        components--;
    }

    int component_size(int n)
    {
        int p = getPar(n);
        return size[p];
    }

    int number_of_components()
    {
        return components - 1;
    }
    void del(int x)
    {
        parent[x] = x;
        rank[x] = 0;
    }
};

/*-------------------------DSU ends-------------------------*/

/*-------------------------SOLUTION-------------------------*/

// filling the binary lifting dp/parent table (parent are store in the power of 2)
void dfs(int node, int par, vector<vector<int>> &adj, vector<vector<int>> &dp)
{
    // 0 => 2^0 i.e., first parent
    dp[node][0] = par;

    for (int i = 1; i <= 16; i++)
    { // 16 can be change basically log(N) => N max depth
        dp[node][i] = dp[dp[node][i - 1]][i - 1];
    }

    for (auto it : adj[node])
    {
        if (it != par)
        {
            dfs(it, node, adj, dp);
        }
    }
}

void solve()
{
    cout << fixed << setprecision(25);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(17, 0));
    dfs(1, 0, adj, dp);

    // making n queries to find the kth ancestor/parent
    int q;
    cin >> q;
    while (q--)
    {
        int node, k;
        cin >> node >> k;
        for (int i = 16; i >= 0; i--)
        {
            if ((k >> i) & 1)
            {
                node = dp[node][i];
            }
        }
        cout << node << endl;
    }
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