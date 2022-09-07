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
#define ii pair<int,int>
#define vii vector<ii>
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define X first
#define Y second
#define endl "\n"

const int maxn=1e5+5;
const int maxm=1e3+5;
const int mod=1e9+7;
const int INF=1e18+9;


int n,q;
int a[maxn];
int st[4*maxn],t[4*maxn];

void build(int id,int l,int r){
    if (l==r){
        st[id]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=max(st[id*2],st[id*2+1]);
}

void down(int id){
    int tmp=t[id]; t[id]=0;
    st[id*2]+=tmp; t[id*2]+=tmp;
    st[id*2+1]+=tmp; t[id*2+1]+=tmp;
}

void upd(int id,int l,int r,int u,int v,int val){
    if (v<l || u>r)
        return;
    if (u<=l && r<=v){
        st[id]+=val;
        t[id]+=val;
        return;
    }
    down(id);
    int mid=(l+r)>>1;
    upd(id*2,l,mid,u,v,val);
    upd(id*2+1,mid+1,r,u,v,val);    
    st[id]=max(st[id*2],st[id*2+1]);
}

int query(int id,int l,int r,int u,int v){
    if (v<l || u>r)
        return -INF;
    if (u<=l && r<=v) {
        return st[id];
    }
    int mid=(l+r)>>1;
    down(id); 
    return max(query(id*2,l,mid,u,v),query(id*2+1,mid+1,r,u,v));
}  

int32_t main(){

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    /*-------------*/
    int type,x,y,k;
    cin>>n; for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    cin>>q;
    while(q--){
        cin>>type>>x>>y;
        if (type==1){
            cin>>k;
            upd(1,1,n,x,y,k);
        }
        else
            cout<<query(1,1,n,x,y)<<endl;
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
//               |   | \\  -  /// |   |
//               | \_|  ''\---/''  |_/ |
//               \  .-\__  '-'  ___/-. /
//             ___'. .'  /--.--\  `. .'___
//          ."" '<  `.___\_<|>_/___.' >' "".
//         | | :  `- \`.;`\ _ /`;.`/ - ` : | |
//         \  \ `_.   \_ __\ /__ _/   .-` /  /
//     =====`-.____`.___ \_____/___.-`___.-'=====
//                       `=---='
//     ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~