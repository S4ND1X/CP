#include <bits/stdc++.h>
#include <vector>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define ll long long
#define ld long double
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pll pair<long long, long long>
#define ppll pair<pll, pll>
#define sd(x) scanf("%d", &x)
#define sld(x) scanf("%lld", &x)
#define INF 1e18
#define eps 0.00001
#define le length
#define debug(n1) cout << n1 << endl
#define rep0(i, n) for (i = 0; i < n; ++i)
#define rep(i, j, n) for (ll i = j; i <= n; i++)
#define per(i, j, n) for (ll i = j; i >= n; i--)
const ll N = 3e5 + 5;
const ll MAX = 3e5 + 5;
const ll M = 1e6 + 5;
ll MODULAR_POWER(ll a, ll b, ll MOD)
{
    if (b == 0)
        return 1LL;
    ll d = MODULAR_POWER(a, b / 2, MOD);
    d *= d;
    d %= MOD;
    if (b % 2)
        d *= a;
    d %= MOD;
    return d;
}
ll BINARY_SEARCH(ll dp[], ll n, ll key)
{
    ll s = 1;
    ll e = n;
    while (s <= e)
    {
        ll mid = (s + e) / 2;
        if (dp[mid] == key)
            return mid;
        else if (dp[mid] > key)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}
string CONVERT_TO_BINARY(ll s)
{
    string res = "";
    while (s != 0)
    {
        res += (char)('0' + s % 2);
        s /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
bool PALIN(string s)
{
    ll i = 0;
    ll j = s.le() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        j--, i++;
    }
    return true;
}
ll STOI(string s)
{
    ll num = 0;
    ll po = 1;
    per(i, s.le() - 1, 0)
    {
        num += po * (s[i] - '0');
        po *= 10;
    }
    return num;
}
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c == '-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}

bool comparePairs(pair<int, int> i1, pair<int, int> i2)
{
    return (i1.first < i2.first) ? true : false;
}
string solve()
{
    string s = "";
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v(n);
    for(int i = 0; i < n ; i++)
    {
        cin >> v[i].first >> v[i].second.second;
        v[i].second.first = i;
    }
    sort(v.begin(), v.end());
    bool el = true;
    int endEl = 0;
    bool ella = true;
    int endElla = 0;
    bool possible = true;
    int lastTime = 0;
    vector<char> res(n);
    for(int i = 0; i < v.size() ; i++)
    {
        if (!el)
        { //si está ocupado ver si ya se desocupó
            if (endEl <= v[i].first)
            {
                el = true;
            }
        }
        if (!ella)
        { //si está ocupada ver si ya se desocupó en
            if (endElla <= v[i].first)
            {
                ella = true;
            }
        }
        if (!el && !ella)
        {
            possible = false;
            break;
        }
        if (el)
        {
            el = false;
            endEl = v[i].second.second;
            res[v[i].second.first] = 'C';
        }
        else
        {
            ella = false;
            endElla = v[i].second.second;
            res[v[i].second.first] = 'J';
        }
        lastTime = v[i].second.second;
    }
    if (!possible)
    {
        return  "IMPOSSIBLE";
    }
    else
    {
        for (auto &c : res)
        {
            s+=c;
        }
    }
    return s;
}
int main()
{
    SPEED;

    int t, n = 1;
    cin >> t;
    while(t--){
        cout << "Case #" << n++ <<": " << solve() << "\n";
    }
    return 0;
}