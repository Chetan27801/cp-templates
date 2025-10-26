// ## Chetan Joshi snippet ##//

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define fr(a, b, i) for (int i = a; i < b; i++)
#define fre(a, b, i) for (int i = a; i <= b; i++)
#define srt(a) sort(a.begin(), a.end())
#define rsrt(a) sort(a.rbegin(), a.rend())
#define vl vector<long>
#define vll vector<long long>
#define mi map<int, int>
#define vc vector<char>
#define mod 1000000007
#include <bitset>
using namespace std;

/*-------------------------IS PRIME OR NOT {START}-------------------------*/
bool isprime(ll n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (ll i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}
/*-------------------------IS PRIME OR NOT {END}-------------------------*/

/*-------------------------SIEVE FOR PRIME CHECK {START}-------------------------*/
bool prime[15000105];
void sieve(int n)
{
    for (ll i = 0; i <= n; i++)
        prime[i] = 1;

    prime[1] = prime[0] = false;
    for (ll p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (ll i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
/*-------------------------SIEVE FOR PRIME CHECK {END}-------------------------*/

/*-------------------------PRIME NUMBERS UPTO N {START}-------------------------*/
vector<ll> primenums;
bool primes_generated = 0;

void gentprimes(int n)
{
    primes_generated = 1;
    sieve(n + 1);
    for (ll i = 2; i <= n; i++)
        if (prime[i])
            primenums.push_back(i);
}
/*-------------------------PRIME NUMBERS UPTO N {END}-------------------------*/

/*-------------------------PRIME FACTORIZATION USING SIEVE {START}-------------------------*/
vector<ll> factors(ll n)
{
    if (!primes_generated)
    {
        cout << "genrprimes ko call karle :)" << endl;
        return {};
    }
    vector<ll> facs;

    for (ll i = 0; primenums[i] * primenums[i] <= n && i < primenums.size(); i++)
    {
        if (n % primenums[i] == 0)
        {
            while (n % primenums[i] == 0)
            {
                n /= primenums[i];
                facs.push_back(primenums[i]);
            }
        }
    }
    if (n > 1)
    {
        facs.push_back(n);
    }
    sort(facs.begin(), facs.end());
    return facs;
}
/*-------------------------PRIME FACTORIZATION USING SIEVE {END}-------------------------*/

/*-------------------------PRIME FACTORIZATION WITHOUT SIEVE {START} -------------------------*/
vll primeFac(ll n)
{
    vll ans;
    while (n % 2 == 0)
    {
        ans.push_back(2);
        n = n / 2;
    }
    for (ll i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            ans.push_back(i);
            n = n / i;
        }
    }
    if (n > 2)
        ans.push_back(n);
    return ans;
}
/*-------------------------PRIME FACTORIZATION WITHOUT SIEVE {END} -------------------------*/

/*-------------------------UNIQUE DIVISORS {START} -------------------------*/
vector<ll> getdivs(ll n)
{
    vector<ll> divs;
    set<ll> tmpdivs;
    for (ll i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            tmpdivs.insert(i);
            tmpdivs.insert(n / i);
        }
    }

    for (auto i : tmpdivs)
    {
        divs.push_back(i);
    }
    return divs;
}
/*-------------------------UNIQUE DIVISORS {END} -------------------------*/

/*-------------------------SOLUTION-------------------------*/
void solve()
{
    // cout << fixed << setprecision(x);
}
int main()
{
    solve();
    return 0;
}