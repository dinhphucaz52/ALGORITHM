#include <iostream>
#include <vector>
#include <algorithm>


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

typedef vector<int> big_num;

void operator >> (istream & in, big_num & a) {
    string s; cin >> s;
    for (char x:s)
        a.push_back(x - '0');
}

void operator << (ostream & out, big_num & a) {
    // for (int x : a)
    //     cout << x; cout << endl;
    for (int i = 0; i < sz(a); i++)
        if (i % 10 == 9)
            cout << a[i] << endl;
        else
            cout << a[i];
}

big_num operator * (big_num a,big_num b) {
    int n = a.size(), m = b.size(), carry = 0, tmp;
    reverse(all(a)); reverse(all(b));     
    big_num res (n + m, 0);
    for (int i = 0; i < n; i++) {
        carry = 0;
        for (int j = 0; j < m || carry; j++) {
            res[i+j] += a[i] * (j < m ? b[j] : 0) + carry;
            carry = res[i+j] / 10;
            res[i+j] %= 10;
        }
    }
    while (!res.empty() && !res.back())
        res.pop_back();
    reverse(all(res));
    return res;
}

big_num operator *= (big_num & a, big_num b) {
    a = a * b;
    return a;
}
big_num convert(int n) {
    big_num res;
    while (n)
        res.push_back(n % 10),
        n /= 10;
    reverse(all(res));
    return res;
}
void solve() {
    fileI("test.inp"); fileO("test.out");  
    big_num res = convert(1);
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