// https://github.com/dinhphuc17525/ALGORITHM.git
#include <iostream>
#include <math.h>
#include <algorithm>
#include <set> 
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <iomanip>

using namespace std;

#define int long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define bit(i,j) ((i>>j)&1)
#define sz(a) (int)(a.size())
#define all(a) (a).begin(), (a).end()
#define left_node id<<1, l, mid
#define right_node id<<1|1, mid + 1, r
#define FILEI(st) freopen(st, "r", stdin)
#define FILEO(st) freopen(st, "w", stdout)

const int MAXN = 1e5 + 16;
const int MAXM = 1e3 + 16;
const int BASE = 311;
const int MOD = 1e9 + 7;
const int INF = 1e18;

void prefix_function(string parttern, string s)
{
    vector<int> pi(sz(parttern) + sz(s) + 1);
    s = parttern + " " + s;
    for (int i = 1; i < pi.size(); i++)
    {
        
    }
}

void solve()
{
    

}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
