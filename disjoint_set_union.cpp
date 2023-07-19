//Disjoint Set Union
#include <iostream>
#include <vector>



using namespace std;

#define int long long
#define FOR(i,a,b) for (int i = a;i <= b;i++)
#define DOWN(i,a,b) for (int i = a;i >= b;i--)
#define fileI(st) freopen(st,"r",stdin)
#define fileO(st) freopen(st,"w",stdout)
#define all(a) a.begin(),a.end()
#define len(st) (int)(st.length())
#define sz(st) (int)(st.size())
#define bit(i,j) ((i>>j)&1)
#define ii pair<int,int>
#define vii vector<ii>
#define fi first
#define se second
#define endl "\n"

const int INF  = 1e18+9;
const int mod  = 1e9+7;
const int maxn = 1e6+5;
const int maxm = 2e3+5;
const int base = 311;

int test = 1;

void testt() {
    // cin >> test;
}

int par[maxn],sz[maxn];

void make_set(int u) {
    par[u] = u;
    sz[u] = 1; 
}

int find_set(int u) {
    return u == par[u] ? u : par[u] = find_set(par[u]);
}

void union_sets(int u, int v) {
    u = find_set(u);
    v = find_set(v);
    if (u != v) {
        if (sz[u] < sz[v])
            swap(u,v); 
        par[v] = u;
        sz[u] += sz[v]; 
    } 
}

bool check(int u,int v) {
    u = find_set(u);
    v = find_set(v);
    return u == v;
}

void solve() {
    FOR (i,1,1e4)
        make_set(i);
    int q,u,v,type; cin >> q;
    while (q--) {
        cin >> u >> v >> type;
        if (type == 1) 
            union_sets(u,v);
        else 
            (check(u,v) == true) ? cout << 1 << endl : cout << 0 << endl;
    }
}

int32_t main() {

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
