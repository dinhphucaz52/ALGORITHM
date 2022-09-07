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
#define fi first
#define se second
#define endl "\n"

const int maxn=1e6+5;
const int maxm=2e3+5;
const int mod=1e9+7;
const int INF=1e18+9;
const int base=311;

int test=1;

void testt(){
    // cin>>test;
}

#define matrix vector<vector<int>>

matrix a={
    {1,1},
    {1,0}
};

int row(matrix a){return sz(a);}
int col(matrix a){return sz(a[0]);}

matrix mul_matrix(matrix a,matrix b){
    matrix res(row(a),vector<int>(col(b)));
    for(int i=0;i<row(a);i++)
        for(int j=0;j<col(b);j++)
            for(int k=0;k<col(a);k++)
                res[i][j]=(res[i][j]+a[i][k]*b[k][j])%mod;
    return res;
}

matrix pow_matrix(matrix a,int k){
    if (k==1)
        return a;
    matrix tmp=pow_matrix(a,k>>1);
    if (k%2==0)
        return mul_matrix(tmp,tmp);
    else
        return mul_matrix(mul_matrix(tmp,tmp),a);
}

void print_matrix(matrix a){
    for(auto row:a){
        for(auto x:row)
            cout<<x<<" ";
        cout<<endl;
    }
}

void solve(){
    int n; cin>>n;
    if (n==0)
        cout<<0;
    else if (n==1)
        cout<<1;
    else
        cout<<pow_matrix(a,n-1)[0][0]<<endl;
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