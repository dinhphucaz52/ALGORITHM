#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define DOWN(i, a, b) for(int i = a; i >= b; i--)
#define bit(i,j) ((i >> j) & 1)
#define all(a) (a).begin(),(a).end()
#define fileI(st) freopen(st,"r",stdin)
#define fileO(st) freopen(st,"w",stdout)
#define sz(a) (a).size()
#define len(st) (st).length()
#define ii pair<int, int>
#define vii vector<ii>
#define fi first
#define se second
#define endl "\n"

int gcd(int a, int b) { return ( b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return a / gcd(a,b) * b; }

const int INF  = 1e18 + 9;
const int mod  = 1e9  + 7;
const int maxn = 1e5  + 5;
const int maxm = 2e3  + 5;
const int base = 311;

int test = 1;

void testt() {
//    cin >> test;
}

struct my_data {
    int u, v, w;
};

vector<my_data> a;

bool cmp(my_data a, my_data b) {
    return a.w < b.w;
}

int sz[maxn], par[maxn];

void initializer(int n) {
    FOR (i, 1, n)
        sz[i] = 1,
        par[i] = i;
}

int find_set(int u) {
    return u == par[u] ? u : par[u] = find_set(par[u]);
}

bool check_sets(int & u, int & v) {
    u = find_set(u);
    v = find_set(v);
    return u == v;
}

void union_sets(int u, int v) {
    if (check_sets(u, v))
        return;
    if (sz[u] < sz[v])
        swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
}

void solve() {
//    fileI("input.txt"); fileO("output.txt");

    int n, m, u, v, w;
    cin >> n >> m;
    while (m--)
        cin >> u >> v >> w,
        a.push_back({u, v, w});

    sort(all(a), cmp); initializer(n);

    int res = 0, cnt = 1;

    for (auto [u, v, w] : a) {
        if (check_sets(u, v))
            continue;
        union_sets(u, v);
        res += w, cnt++;
        if (cnt == n)
            break;
    }

    cout << res << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    testt();

    while (test--)
        solve();

    return 0;
}















