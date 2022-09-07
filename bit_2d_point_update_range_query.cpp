// BIT 2D point update - range query
#include <iostream>

using namespace std;

int n,q,x,y,u,v,val;
int bit[1001][1001];

void update(int x, int y, int val) {
	for (; x <= n; x += x & -x)
		for (int i = y; i <= n; i += i & -i)
			bit[x][i] += val;
}

int query(int x, int y) {
    int res = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            res += bit[i][j];
    return res;
}

int range_query(int x, int y, int u, int v) {
    return query(u, v) + query(--x, --y)
         - query(x, v) - query(u, y);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("test.inp","r",stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> val,
            update(i,j,val);

    update(2,2,5);
    cout << range_query(1,1,2,2);


	return 0;
}
