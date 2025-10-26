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

/*-------------------------Segment Tree starts-------------------------*/
template <typename Node, typename Update>
struct SegTree
{
    vector<Node> tree;
    vector<ll> arr; // type may change
    int n;
    int s;
    SegTree(int a_len, vector<ll> &a)
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
        build(0, n - 1, 1);
    }
    void build(int start, int end, int index) // Never change this
    {
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
    void update(int start, int end, int index, int query_index, Update &u) // Never Change this
    {
        if (start == end)
        {
            u.apply(tree[index]);
            return;
        }
        int mid = (start + end) / 2;
        if (mid >= query_index)
            update(start, mid, 2 * index, query_index, u);
        else
            update(mid + 1, end, 2 * index + 1, query_index, u);
        tree[index].merge(tree[2 * index], tree[2 * index + 1]);
    }
    Node query(int start, int end, int index, int left, int right)
    { // Never change this
        if (start > right || end < left)
            return Node();
        if (start >= left && end <= right)
            return tree[index];
        int mid = (start + end) / 2;
        Node l, r, ans;
        l = query(start, mid, 2 * index, left, right);
        r = query(mid + 1, end, 2 * index + 1, left, right);
        ans.merge(l, r);
        return ans;
    }
    void make_update(int index, ll val)
    {                                    // pass in as many parameters as required
        Update new_update = Update(val); // may change
        update(0, n - 1, 1, index, new_update);
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
        val = l.val ^ r.val; // may change
    }
};

struct Update1
{
    ll val; // may change
    Update1(ll p1)
    {             // Actual Update
        val = p1; // may change
    }
    void apply(Node1 &a)
    {                // apply update to given node
        a.val = val; // may change
    }
};

/*-------------------------Segment Tree ends-------------------------*/

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