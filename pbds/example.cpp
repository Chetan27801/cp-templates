// ## Yuji snippet ##//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back()
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
#define vc vector<char>
#define vvc vector<vector<char>>
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

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// We use pair<int, int> to store {value, unique_index}
template <typename T>
using ordered_multiset = tree<pair<T, int>, null_type, less<pair<T, int>>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order - give element at xth index
//  order_of_key - find no of elements strictly smaller than x
ll dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
/*-------------------------hash-------------------------*/
struct chsh
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    // 1. Base Hash for single numbers (int, long long)
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }

    // 2. Hash for pair<int, int> (Pack two 32-bit ints into one 64-bit)
    size_t operator()(const pair<int, int> &p) const
    {
        // Pack into one uint64_t and use the base hash
        uint64_t x = ((uint64_t)p.first << 32) | (unsigned int)p.second;
        return (*this)(x);
    }

    size_t operator()(const pair<int, pair<int, int>> &p) const
    {
        // Step A: Hash the first integer
        uint64_t h1 = (*this)(p.first);

        // Step B: Hash the inner pair (this calls overload #2 automatically)
        uint64_t h2 = (*this)(p.second);

        // Step C: Combine the two hashes (Standard bit-mixing logic)
        // This ensures the combination is unique and well-distributed
        return h1 ^ (h2 + 0x9e3779b9 + (h1 << 6) + (h1 >> 2));
    }
};

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

    for (ll i = 2; i < 1000004; i++)
    {
        for (ll j = i * i; j < 1000004; j += i)
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
    bool same(int u, int v)
    {
        return getPar(u) == getPar(v);
    }
};

/*-------------------------DSU ends-------------------------*/

/*-------------------------SOLUTION-------------------------*/

void solve()
{
    cout << fixed << setprecision(25);

    // --- ORDERED SET EXAMPLE ---
    cout << "--- Ordered Set ---" << endl;
    ordered_set<int> os;
    os.insert(5);
    os.insert(1);
    os.insert(10);
    os.insert(5); // Duplicate ignored

    // Elements: {1, 5, 10}

    // find_by_order: What is at index 1?
    cout << "Element at index 1: " << *os.find_by_order(1) << endl; // Output: 5

    // order_of_key: How many elements < 6?
    cout << "No. of elements < 6: " << os.order_of_key(6) << endl; // Output: 2 ({1, 5})

    //-------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------

    // Ordered Multiset
    ordered_multiset<int> oms;
    int t = 0; // "Time" counter to ensure uniqueness

    // --- INSERTION ---
    // Helper lambda to make insertion easier
    auto insert_val = [&](int val)
    {
        oms.insert({val, t++});
    };

    insert_val(5);
    insert_val(1);
    insert_val(5); // Duplicate 5
    insert_val(10);

    // Current State (conceptually): { {1,1}, {5,0}, {5,2}, {10,3} }
    // Note: They are sorted primarily by value, secondarily by time.

    // --- 1. SEARCHING (Rank) ---
    // "How many elements strictly smaller than 5?"
    // We search for {5, -1} because -1 is smaller than any valid time index (0+).
    int strictly_smaller = oms.order_of_key({5, -1});
    cout << "Count < 5: " << strictly_smaller << endl; // Output: 1 (only {1,1})

    // --- 2. SEARCHING (Index) ---
    // "What is the 2nd smallest element?" (0-indexed)
    // The result is a pair, so we take .first
    cout << "Index 2 value: " << oms.find_by_order(2)->first << endl; // Output: 5

    // --- 3. ERASING (Safe!) ---
    // To erase *one* instance of 5:
    // Find the first instance of 5 using lower_bound with a minimal secondary key.
    auto it = oms.lower_bound({5, -1});

    if (it != oms.end() && it->first == 5)
    {
        oms.erase(it); // Safely erases just one "5"
        cout << "Erased one 5." << endl;
    }

    // --- 4. Upper Bound / Lower Bound ---
    // Standard lower_bound behavior (first element >= 5)
    auto lb = oms.lower_bound({5, -1});
    cout << "Lower Bound 5: " << lb->first << endl; // Output: 5

    // Standard upper_bound behavior (first element > 5)
    // We search for something greater than any possible {5, time}, so {5, infinity}
    auto ub = oms.lower_bound({5, 2e9});
    cout << "Upper Bound 5: " << ub->first << endl; // Output: 10
}
signed main()
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