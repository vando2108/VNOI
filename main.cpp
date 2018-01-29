//KP

#include <bits/stdc++.h>
using namespace std;

// Loop
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define repd(i,a,b) for (int i = a - 1; i >= b; i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

// Define
#define ms(s, n) memset(s, n, sizeof(s))
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unipq(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define fbit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define _(x) ((x) & (-(x)))
#define cn cout << '\n';
#define text "test"
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

//Const
const int MOD = (int) 1e9 + 7;
const int MOD2 = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;

//Function
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
inline bool isUpcase(char x){ return x < 'a'; }
inline char lowercase(char x){ if (isUpcase(x)) return char(x + 32);   return x; }
inline char upcase(char x){ if (!isUpcase(x)) return char(x - 32);   return x; }
//#define db(x) cerr << #x << " = " << (x) << " ";
//#define endln cerr << "\n";

// Direction
const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {-1, 0, 1, 0, -1, 1, 1, -1};

ull power(int x, int k) {
    if (k == 1) return x;
    ull tmp = power(x, k / 2);
    if (!(k & 1)) return tmp * tmp;
        else return tmp * tmp * x;
}

ull cut(ull a, ull b, int k) {
    ull m = power(2, k), n = m, h = 1, r = 1;
    FOR(i,1,k) {
        if (a >= m / 2) {
            a = m - 1 - a;
            r = 2 * h - r + 1;
        }
        m /= 2;
        h *= 2;
        if (b < n / 2) {
             b = n / 2 - 1 - b;
             r = 2 * h - r + 1;
        } else b = b - n / 2;
        n /= 2;
        h *= 2;
    }
    return 1 << (2 * k - r + 1);
}

int main() {
    //freopen(text".inp", "r", stdin);    freopen(text".out", "w", stdout);

    ull k, p, q, u, v;
    cin >> k >> p >> q >> u >> v;
    cout << cut(p, q, k);

    return 0;
}
