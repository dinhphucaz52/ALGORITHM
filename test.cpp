#include <iostream>
#include <vector>

using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = a;i <= b; i++)
#define DOWN(i, a, b) for (int i = a; i >= b; i--)
#define fileI(st) freopen(st, "r", stdin)
#define fileO(st) freopen(st, "w", stdout)
#define fileE(st) freopen(st, "w", stderr)
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define bit(i,j) ((i>>j)&1)
#define all(a) (a).begin(),(a).end()
#define left_node id<<1,l,mid
#define right_node id<<1|1,mid+1,r
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define fi first
#define se second
#define endl "\n"

template<class P, class Q> 
bool maximize(P &res, const Q &val) { 
    return res < val ? res = val, true : false;
}

template<class P, class Q> 
bool minimize(P &res, const Q &val) { 
    return res > val ? res = val, true : false;
}

const int INF  = 1e18 + 9;
const int mod  = 1e9  + 7;
const int maxn = 1e6  + 5;
const int maxm = 5e2  + 5;
const int base = 311;

int test = 1;

void testt() {
    // cin >> test;
}

struct segment_tree {
    private:
        int n; vi st;
    public:
        segment_tree (int N) {
            n = N; st.resize(n<<2);
        }
        void build(int id, int l, int r, const vi & cost) {
            if (l == r)
                return st[id] = cost[l], void();
            int mid = (l + r) >> 1;
            build(left_node, cost); build(right_node, cost);
            st[id] = st[id<<1] + st[id<<1|1];
        }
        void build(const vi & cost) { build(1, 1, n, cost); }
        void update(int id, int l, int r, int node, int val) {
            if (node > r || node < l)
                return;
            if (l == r)
                return st[id] += val, void();
            int mid = (l + r) >> 1;
            update(left_node, node, val); update(right_node, node, val);
            st[id] = st[id<<1] + st[id<<1|1];
        }
        void update(int node, int val) { update(1, 1, n, node, val); }
        int query(int id, int l, int r, int u, int v) {
            if (u > r || v < l)
                return 0;
            if (u <= l && r <= v)
                return st[id];
            int mid = (l + r) >> 1;
            return query(left_node, u, v) + query(right_node, u, v);
        }
        int query(int u, int v) { return query(1, 1, n, u, v); }
};

int n, u, v, w; vii adj[maxn];
int h[maxn], up[20][maxn];
int nChilds[maxn], posInBase[maxn], head[maxn], headChain[maxn];
segment_tree s; vi cost = {0, 0};

void dfs(int u, int pre = 1) {
    nChilds[u] = 1;
    FOR (i, 1, 17)
        up[i][u] = up[i-1][up[i-1][u]];
    for (ii x : adj[u]) {
        v = x.fi;
        if (v != pre) {
            h[v] = h[u] + 1; up[0][v] = u;
            dfs(v, u); nChilds[u] += nChilds[v];
        }
    }
}

int nChain, nBase;

void hld(int u, int pre = 1) {
    if (headChain[nChain] == 0)
        headChain[nChain] = u;
    head[u] = headChain[nChain]; posInBase[u] = ++nBase;

    int target = -1, dis;

    for (ii x : adj[u]) {
        v = x.fi, w = x.se;
        if (v != pre) 
            if (target == -1 || nChilds[v] > nChilds[target]) 
                target = v, dis = w;
    }

    if (target != -1)
        cost.push_back(dis);
        hld(v, u);
    
    for (ii x : adj[u]) {
        v = x.fi, w = x.se;
        if (v != pre)
            ++nChain, cost.push_back(w), hld(v, u);
    }

}

int LCA(int u, int v) {
    if (u == v)
        return u;
    if (h[u] < h[v])
        swap(u, v);
    int k = h[u] - h[v];
    for (int i = 0; 1 << i <= k; i++)
        if (bit(k, i))
            u = up[i][u];
    if (u == v)
        return u;
    k = __lg(h[u]);
    DOWN (i, k, 0)
        if (up[i][u] != up[i][v])
            u = up[i][u], v = up[i][v];
    return  u == v ? u : up[0][u];
}

int query(int u, int v) {
    int lca = LCA(h[u], h[v]), res = 0;
    while (head[u] != head[lca])
        res += s.query(posInBase[head[u]], posInBase[u]),
        u = up[0][head[u]];
    while (head[v] != head[lca])
        res += s.query(posInBase[head[v]], posInBase[v]),
        v = up[0][head[v]];
    res += s.query(posInBase[lca], posInBase[u]);
    res += s.query(posInBase[lca], posInBase[v]);
    res -= s.query(posInBase[lca], posInBase[lca]) << 1;
    return res;
}

void solve() {
    cin >> n;
    FOR (i, 2, n)
        cin >> u >> v >> w,
        adj[u].push_back({v, w}),
        adj[v].push_back({u, w});
    dfs(1); hld(1); s = segment_tree(n); s.build(cost);     
    
}

int32_t main(){
 
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/

    testt();
    while (test--)
        solve();


    /*-------------*/
    return 0;
}
//                       _oo0oo_
//                      o8888888o
//                      88" . "88
//                      (| -_- |)
//                      0\  =  /0
//                    ___/`---'\___
//                  .' \|     |// '.
//                 / \|||  :  |||// \
//                / _||||| -:- |||||- \
//               |   | \  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~