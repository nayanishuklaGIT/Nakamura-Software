#include <iostream>
#include <cmath>
#include <string>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include <numeric>
typedef long long int ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))
long long mod = 998244353;
#define pll pair<ll, ll>
using namespace std;

class Node
{ // tree building
public:
    ll data;
    Node *left;
    Node *right;
    Node(ll val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void pyes()
{
    cout << "YES" << endl;
}
void pno()
{
    cout << "NO" << endl;
}
long long multiply(long long a, long long b)
{
    long long res = 0; // Initialize result

    // Update a if it is more than
    // or equal to mod
    a %= mod;

    while (b)
    {
        // If b is odd, add a with result
        if (b & 1)
            res = (res + a) % mod;

        // Here we assume that doing 2*a
        // doesn't cause overflow
        a = (2 * a) % mod;

        b >>= 1; // b = b / 2
    }

    return res;
}

ll lcm(ll num1, ll num2)
{
    ll lcm, gcd, temp;
    ll a = num1;
    ll b = num2;
    // use while loop to define the condition
    while (num2 != 0)
    {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }

    // assign num1 to gcd variable
    gcd = num1;
    lcm = (a * b) / gcd;
    return lcm;
}

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

vector<ll> seg;

// segment tree

void setsize(ll n)
{
    ll temp = 4 * n;
    for (int i = 0; i < temp; i++)
    {
        seg.push_back(-1);
    }
}

void buildtree(ll start, ll end, ll inx, ll arr[])
{
    if (start == end)
    {
        seg[inx] = arr[start];
        return;
    }
    if (start > end)
    {
        return;
    }
    ll mid = (start + end) / 2;
    buildtree(start, mid, 2 * inx + 1, arr);
    buildtree(mid + 1, end, 2 * inx + 2, arr);
    seg[inx] = seg[2 * inx + 1] + seg[2 * inx + 2]; // precomputing the values
    return;
}

ll sum(ll s, ll e, ll qs, ll qe, ll inx)
{
    if (s > e)
    {
        return 0;
    }
    if (s > qe || e < qs)
    {
        return 0;
    }
    if (s >= qs && e <= qe)
    {
        return seg[inx];
    }
    ll mid = (s + e) >> 1;
    return sum(s, mid, qs, qe, 2 * inx + 1) + sum(mid + 1, e, qs, qe, 2 * inx + 2);
}

void update(ll s, ll e, ll qinx, ll inx, ll diff)
{
    if (qinx < s || qinx > e)
    {
        return;
    }
    if (s == e)
    {
        seg[inx] += diff;
        return;
    }
    if (s > e)
    {
        return;
    }
    ll mid = (s + e) >> 1;
    if (mid < qinx)
    {
        update(mid + 1, e, qinx, 2 * inx + 2, diff);
    }
    else
    {
        update(s, mid, qinx, 2 * inx + 1, diff);
    }
    seg[inx] = seg[2 * inx + 1] + seg[2 * inx + 2];
    return;
}

long long power(long long x, long long y)
{
    long long res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}

long long modInverse(ll x)
{
    return power(x, mod - 2);
}
long long modadd(long long a, long long b)
{
    return (a % mod + b % mod + 2 * mod) % mod;
}

long long modmult(long long a, long long b)
{
    return (a % mod * b % mod) % mod;
}

long long moddiv(long long a, long long b)
{
    return (a % mod * modInverse(b)) % mod;
}
long long calc(ll n, ll r)
{
    if (r > n - r)
        r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for (ll i = 1; i <= r; i++)
    {
        ans *= n - r + i;
        ans /= i;
    }

    return ans;
}
void print(ll ans)
{
    cout << ans << endl;
}
// union by rank lagaa dete hai
vector<ll> parent;
vector<ll> ranks;
ll find(ll x)
{
    if (parent[x] == -1)
    {
        return x;
    }
    return find(parent[x]);
}
void uni(ll x, ll y)
{
    ll xpar = find(x);
    ll ypar = find(y);
    if (xpar == ypar)
    {
        return;
    }
    if (ranks[xpar] < ranks[ypar])
    {
        parent[xpar] = ypar;
    }
    if (ranks[xpar] > ranks[ypar])
    {
        parent[ypar] = xpar;
    }
    if (ranks[xpar] == ranks[ypar])
    {
        ranks[ypar]++;
        parent[xpar] = ypar;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    // cout<<setprecision(7);
    while (t--)
    {
        ll n;
        cin >> n;
    }

    return 0;
}