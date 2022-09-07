#include <iostream>
#include <vector>
#include <queue>


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

struct data{int u,v,w;};
int n,m,s,u,v,w;
vii adj[maxn];
bool vst[maxn];
int par[maxn];
vector<int> d(maxn,mod);
vector<data> mst;

void nhap(){
    cin>>n>>m;
    while(m--)
        cin>>u>>v>>w,
        adj[u].push_back({v,w}),
        adj[v].push_back({u,w});
}

void prim(int s){
    priority_queue<ii,vii,greater<ii>> q;
    d[s]=0; q.push({d[s],s});
    while(!q.empty()){
        ii top=q.top(); q.pop();
        int u=top.second,dis=top.first;
        if (d[u] < dis)
            continue;
        if (u!=s)
            mst.push_back({par[u],u,dis});
        vst[u]=true;
        for(auto x:adj[u]){
            int v=x.first,w=x.second;
            if (d[v]>w && !vst[v])
                d[v]=w,
                par[v]=u,
                q.push({w,v});
        }
    }
    for(auto x:mst)
        cout<<x.u<<" "<<x.v<<" "<<x.w<<endl;
}

void solve(){
    fileI("prim.inp");
    nhap(); 
    prim(1);
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