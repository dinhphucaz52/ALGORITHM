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

const int maxn=1e6+5;
const int maxm=1e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=31;

int test=1;

void testt(){
    // cin>>test;
}

string a; int k;
int pow[maxn],pre[maxn],suf[maxn];

int getL(int l,int r){
    return (pre[r]-pre[l-1]*pow[r-l+1]+mod*mod)%mod;
}
int getR(int l,int r){
    return (suf[l]-suf[r+1]*pow[r-l+1]+mod*mod)%mod;
}
void xuat(int l,int r){
    FOR(i,l,r)
        cout<<a[i];
    cout<<endl;
}
void solve(){
    fileI("hash.inp");
    cin>>a>>k; pow[0]=1; 
    int n=len(a); a=" "+a; FOR(i,1,n) pow[i]=(pow[i-1]*base)%mod;
    FOR(i,1,n)  pre[i]=(pre[i-1]*base+a[i]-'a'+1)%mod;
    DOWN(i,n,1) suf[i]=(suf[i+1]*base+a[i]-'a'+1)%mod;
    for(int i=1;i+k-1<=n;i++)
        if (getL(i,i+k-1)==getR(i,i+k-1))
            xuat(i,i+k-1);
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