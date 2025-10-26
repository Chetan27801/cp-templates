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

/*-------------------------Lazy Segment Tree start-------------------------*/
template <typename Node, typename Update>
struct LazySGT
{
    vector<Node> tree;
    vector<bool> lazy;
    vector<Update> updates;
    vector<ll> arr; // type may change
    int n;
    int s;
    LazySGT(int a_len, vector<ll> &a)
    { // change if type updated
        arr = a;
        n = a_len;
        s = 1;
        while (s < 2 * n)
        {
            s = s << 1;
        }
        tree.resize(s);
        fill(all(tree), Node());
        lazy.resize(s);
        fill(all(lazy), false);
        updates.resize(s);
        fill(all(updates), Update());
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index)
    { // Never change this
        if (start == end)
        {
            tree[index] = Node(arr[start]);
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * index);
        build(mid + 1, end, 2 * index + 1);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    void pushdown(int index, int start, int end)
    {
        if (lazy[index])
        {
            int mid = (start + end) / 2;
            apply(2 * index, start, mid, updates[index]);
            apply(2 * index + 1, mid + 1, end, updates[index]);
            updates[index] = Update();
            lazy[index] = 0;
        }
    }
    void apply(int index, int start, int end, Update &u)
    {
        if (start != end)
        {
            lazy[index] = 1;
            updates[index].combine(u, start, end);
        }
        u.apply(tree[index], start, end);
    }
    void update(int start, int end, int index, int left, int right, Update &u)
    { // Never Change this
        if (start > right || end < left)
            return;
        if (start >= left && end <= right)
        {
            apply(index, start, end, u);
            return;
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        update(start, mid, 2 * index, left, right, u);
        update(mid + 1, end, 2 * index + 1, left, right, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right)
    { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
        {
            pushdown(index, start, end);
            return tree[index];
        }
        pushdown(index, start, end);
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int left, int right, ll val)
    {                                    // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, left, right, new_update);
    }
    Node make_query(int left, int right)
    {
        return query(0, n - 1, 1, left, right);
    }
};

struct Node1
{
    ll val; // may change
    Node1()
    {            // Identity element
        val = 0; // may change
    }
    Node1(ll p1)
    {             // Actual Node
        val = p1; // may change
    }
    void merge(Node1 &l, Node1 &r)
    {                        // Merge two child nodes
        val = l.val + r.val; // may change
    }
};

struct Update1
{
    ll val; // may change
    Update1()
    { // Identity update
        val = 0;
    }
    Update1(ll val1)
    { // Actual Update
        val = val1;
    }
    void apply(Node1 &a, int start, int end)
    {                                    // apply update to given node
        a.val = val * (end - start + 1); // may change
    }
    void combine(Update1 &new_update, int start, int end)
    {
        val = new_update.val;
    }
};
/*-------------------------Lazy Segment Tree ends-------------------------*/

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