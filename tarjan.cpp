#include <iostream>
#include <vector>

using namespace std;

const int maxn=1e5+5;

#define ii pair<int,int>

int n,m,u,v;
int num[maxn],low[maxn];
vector<int> adj[maxn];


vector<ii> bridge;
bool joint[maxn];

int timeDFS=0;

void dfs(int u,int pre){
    num[u]=low[u]=++timeDFS; int child=0;
    for (int v:adj[u]){
        if (v==pre)
            continue;
        if (!num[v]){
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if (low[v]==num[v])
                bridge.push_back({u,v});
            child++;
            if (u==pre){
                if (child>1)
                    joint[u]=true;
            }
            else{
                if (low[v]>=num[u])
                    joint[u]=true;
            }
        }
        else
            low[u]=min(low[u],num[v]);
    }    
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("test.inp","r",stdin);
    cin>>n>>m;
    while (m--)
        cin>>u>>v,
        adj[u].push_back(v),
        adj[v].push_back(u);
    dfs(1,1);
    cout<<"Cac dinh khop la:"<<endl;
    for (int i=1;i<=n;i++)
        if (joint[i])
            cout<<i<<" ";
    cout<<endl;
    cout<<"Cac canh cau la:"<<endl;
    for (auto x:bridge)
        cout<<x.first<<" "<<x.second<<endl;
    return 0;
}