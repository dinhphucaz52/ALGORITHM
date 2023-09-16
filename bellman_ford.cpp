#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <cstring>
#include <math.h>

using namespace std;

#define int long long
#define FOR(i, a, b) for (int i = a;i <= b; i++)
#define DOWN(i, a, b) for (int i = a; i >= b; i--)
#define fileI(st) freopen(st, "r", stdin)
#define fileO(st) freopen(st, "w", stdout)
#define fileE(st) freopen(st, "w", stderr)
#define len(st) (int)(st.length())
#define sz(a) (int)(a.size())
#define bit(i,j) ((i>>j)&1)
#define all(a) (a).begin(),(a).end()
#define left_node id<<1,l,mid
#define right_node id<<1|1,mid+1,r
#define ii pair<int, int>
#define vii vector<ii>
#define vi vector<int>
#define elif else if
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
const int maxn = 1e6  + 5;
const int maxm = 5e3  + 5;
const int base = 311;

int test = 1;

void testt() {
	// cin >> test;
}

struct mydata {
	int u, v, w;
};

vector<mydata> edge;

int u, v, w;
vector<int> d(maxn, INF);
vector<int> trace(maxn);
stack<int> s;


void solve() {

	while(cin >> u >> v >> w) 
		edge.push_back({u, v, w});
	int n = 5;

	trace[0] = 0; d[1] = 0;

	FOR(i, 1, n) {
		for (mydata x : edge) {
			u = x.u; v = x.v; w = x.w;
			if (d[u] != INF && d[v] > d[u] + w)
				trace[v] = u,
				d[v] = d[u] + w;
		}
	}

	int target = 5; cout << d[target] << endl;

	while(target != 0)
		s.push(target),
		target = trace[target];
	while(!s.empty()) 
		cout << s.top() << " ",
		s.pop();		
}

signed main(){
 
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	/*-------------*/

	fileE("test.txt");

	clock_t start = clock();

	testt();
	while (test--)
		solve();

	clock_t end = clock();

	cerr << endl << "Time Run: " << endl;
	cerr << end - start;

	/*-------------*/
	return 0;
}
/*
				  _oo0oo_
				 o8888888o
				 88" . "88
				 (| -_- |)
				 0\  =  /0
			   ___/`---'\___
			 .' \|     |// '.
			/ \|||  :  |||// \
		   / _||||| -:- |||||- \
		  |   | \  -  /// |   |
		  | \_|  ''\---/''  |_/ |
		  \  .-\__  '-'  ___/-. /
		___'. .'  /--.--\  `. .'___
	 ."" '<  `.___\_<|>_/___.' >' "".
	| | :  `- \`.;`\ _ /`;.`/ - ` : | |
	\  \ `_.   \_ __\ /__ _/   .-` /  /
=====`-.____`.___ \_____/___.-`___.-'=====
				  `=---='
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
