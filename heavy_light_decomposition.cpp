#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = a;i <= b; i++)
#define DOWN(i, a, b) for (int i = a; i >= b; i--)
#define fileI(st) freopen(st, "r", stdin)
#define fileO(st) freopen(st, "w", stdout)
#define fileE(st) freopen(st, "w", stderr)
#define bit(i,j) ((i >> j) & 1)
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define all(a) (a).begin(),(a).end()
#define l_node (id << 1)
#define r_node (id << 1 | 1)
#define left_node id << 1, l, mid
#define right_node id << 1 | 1, mid + 1, r
#define ii pair<int, int>
#define vii vector<ii>
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
const int maxn = 1e5  + 5;
const int maxm = 5e2  + 5;
const int base = 311;

int test = 1;

void testt() {
    fileI("hld.inp");
    // cin >> test;
}

// Tree
int n, m, u, v, w;
vector<ii> adj[maxn];

// HLD
int nChain, nBase;
int head[maxn]; 
int chainHead[maxn]; 
int posInBase[maxn]; 
int nChild[maxn];    

// LCA
int h[maxn];         
int up[20][maxn];  

// ST
int st[maxn * 4 + 100]; 
vector<int> cost = {0, 0}; 

void enter() { 
    // fileI("test.inp"); fileO("test.out");
    cin >> n; 
    FOR (i, 2, n)
        cin >> u >> v >> w,
        adj[u].push_back({v, w}),
        adj[v].push_back({u, w});
}


void dfs(int u, int pre) { 
    nChild[u] = 1;
    FOR (i, 1, 17)
        up[i][u] = up[i-1][up[i-1][u]];
    for (auto x : adj[u]) {
        v = x.fi;
        if (v == pre)
            continue;
        up[0][v] = u; h[v] = h[u] + 1; 
        dfs(v, u);
        nChild[u] += nChild[v];
    }
}

// Heavy Light Decomposition
void hld(int u) { 
    if (chainHead[nChain] == 0) 
        chainHead[nChain] = u;
    posInBase[u] = ++nBase; head[u] = chainHead[nChain];
    int mxVtx = -1;
    int dist; 
    for (auto x : adj[u]) {
        v = x.fi, w = x.se;
        if (v != up[0][u]) {
            if (mxVtx == -1 || nChild[v] > nChild[mxVtx]) {
                mxVtx = v; dist = w;
            }
        }
    }
    if (mxVtx > -1)
        cost.push_back(dist),
        hld(mxVtx);

    for (auto x : adj[u]) {
        v = x.fi, w = x.se;
        if (v != up[0][u] && v != mxVtx) {
            nChain++;
            cost.push_back(w);
            hld(v);
        }
    }
}

// Lowest Common Ancestor
int LCA(int u, int v ){ 
    if (u == v)
        return u;
    if (h[u] < h[v])
        swap(u, v);
    int k = h[u] - h[v];
    for (int i = 0; 1 << i <= u; i++)
        if (bit(k, i))
            u = up[i][u];
    if (u == v) 
        return u;
    k = __lg(h[u]);
    DOWN (i, k, 0)
        if (up[i][u] != up[i][v])
            u = up[i][u],
            v = up[i][v];
    return u == v ? u : up[0][u];
}

// Segment Tree

void build(int id, int l, int r,const vector<int> & a){ 
    if (l == r)
        return st[id] = a[l], void();
    int mid = (l + r) >> 1;
    build(left_node, a); build(right_node, a);
    st[id] = st[id<<1] + st[id<<1|1];
}

void update(int id, int l, int r, int node, int val) { 
    if (node < l || node > r || l > r)
        return;
    if (l == r)
        return st[id] = val, void();
    int mid = (l + r) >> 1;
    update(left_node, node, val);
    update(right_node, node, val);
    st[id] = st[id<<1] + st[id<<1|1];
}

void update(int pos, int val) {
    update(1, 1, n, pos, val);
}

int get(int id, int l, int r, int u, int v){ 
    if (v < l || u > r)
        return 0;
    if (u <= l && r <= v) 
        return st[id];
    int mid = (l + r) >> 1;
    return get(left_node, u, v) + get(right_node, u, v);
} 

int get(int u, int v){
    return get(1, 1, n, u, v);
}

// Query on tree

void update_query(int u, int v, int val) { 
    int node = max(posInBase[u], posInBase[v]); 
    update(node, val);
}

int sum_query(int u, int v) {  
    int lca = LCA(u, v), res = 0; 
    while (head[u] != head[lca]) {
        res += get(posInBase[head[u]], posInBase[u]); 
        u = up[0][head[u]]; 
    }
    while (head[v] != head[lca]) {
        res += get(posInBase[head[v]], posInBase[v]);
        v = up[0][head[v]];
    }
    res += get(posInBase[lca], posInBase[u]); 
    res += get(posInBase[lca], posInBase[v]);
    res -= (get(posInBase[lca], posInBase[lca]) << 1);
    return res; 
}


void solve() {
    enter(); h[1] = 0; up[0][1] = 1;
    dfs(1, 1); hld(1); build(1, 1, n, cost);
}

signed main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/

    testt();
    while (test--)
        solve();


    /*-------------*/
    return 0;
}
