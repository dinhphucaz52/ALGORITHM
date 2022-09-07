
#include <iostream>
#include <vector>


using namespace std;

#define int long long
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define FORR(i,a,b) for (int i=a;i<b;i++)
#define DOWN(i,a,b) for (int i=a;i>=b;i--)
#define DOWNN(i,a,b) for (int i=a;i>b;i--)
#define fileI(st) freopen(st,"r",stdin)
#define fileO(st) freopen(st,"w",stdout)
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define bit(i,j) ((i>>j)&1)
#define ii pair<int,int>
#define vii vector<ii>
#define X first
#define Y second
#define endl "\n"

const int maxn=1e5+5;
const int maxm=1e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

int n,m,u,v;
int h[maxn];
int up[20][maxn];
vector<int> adj[maxn];

void dfs(int u){
    FOR(i,1,17)
        up[i][u]=up[i-1][up[i-1][u]];
    for(int v:adj[u])
        h[v]=h[u]+1,
        up[0][v]=u,
        dfs(v);
}

void init(int root){
    up[0][root]=root; h[root]=0; dfs(root);
}

int anc(int u,int k){
    for(int i=0;(1<<i)<=k;i++)
        if (bit(k,i))
            u=up[i][u];
    return u;
}

int lca(int u,int v){
    if (h[u]<h[v])
        swap(u,v);
    u=anc(u,h[u]-h[v]);
    if (u==v)
        return u;
    int k=__lg(h[u]);
    DOWN(i,k,0)
        if (up[i][u]!=up[i][v])
            u=up[i][u],
            v=up[i][v];
    return up[0][u];
}

int dis(int u,int v){
    int tmp=lca(u,v);
    return h[u]+h[v]-2*h[tmp];
}

void solve(){
    fileI("lca.inp");
    cin>>n;
    FOR(i,2,n)
        cin>>u>>v,
        adj[u].push_back(v);
    init(1); cout<<lca(12,11);
}


int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/

    testt();
    while(test--){
        solve();
    }


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