//bz2161
/*
  @Author: YooQ
*/
#include <bits/stdc++.h>
using namespace std;
#define sc scanf
#define pr printf
#define ll long long
#define int long long
#define FILE_OUT freopen("out", "w", stdout);
#define FILE_IN freopen("in", "r", stdin);
#define debug(x) cout << #x << ": " << x << "\n";
#define AC 0
#define WA 1
#define INF 0x3f3f3f3f
const ll MAX_N = 1e6+5;
const ll MOD = 19921228;
int N, M, K;

int arr[MAX_N];
int uniarr[MAX_N];
int unicnt = 0;

int P[MAX_N];
int C[MAX_N];
int L[MAX_N];
int R[MAX_N];

struct Range {
	int l, r, c;
	bool operator < (const Range& B) const {
		return c < B.c;
	}
}range[MAX_N];

struct Qr{
	int id, k, p;
}qr[MAX_N], tmp[MAX_N];

int tr[MAX_N];

inline int lowbit(int x) {
	return x & -x;
}

inline void add(int x, int k) {
	while (x <= unicnt) {
		tr[x] += k;
		x += lowbit(x);
	}
}

inline int ask(int x) {
	int res = 0;
	while (x) {
		res += tr[x];
		x -= lowbit(x);
	}
	return res;
}

int ans[MAX_N];

void div(int l, int r, int x, int y) {
	if (l > r) return;
	int mid = l + ((r-l)>>1);
	
	for (int i = mid; i <= r; ++i) {
		add(range[i].l, 1);
		add(range[i].r+1, -1);
	}
	
	int lx = x;
	int rx = y;
	int cnt = 0;
	for (int i = x; i <= y; ++i) {
		cnt = ask(qr[i].p);
		if (cnt >= qr[i].k) {
			ans[qr[i].id] = range[mid].c;
			tmp[rx--] = qr[i];
		} else {
			qr[i].k -= cnt;
			tmp[lx++] = qr[i];
		}
	}
	
	for (int i = x; i <= y; ++i) {
		qr[i] = tmp[i];
	}
	
	for (int i = mid; i <= r; ++i) {
		add(range[i].l, -1);
		add(range[i].r+1, 1);
	}
	
	div(l, mid-1, x, lx-1);
	div(mid+1, r, lx, y);
}

void solve(){
	unicnt = 0;
	sc("%lld", &N);
	int Padd, Pfirst, Pmod, Pprod, Cadd, Cfirst, Cmod, Cprod, Ladd, Lfirst, Lmod, Lprod, Radd, Rfirst, Rmod, Rprod;
	sc("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &Padd, &Pfirst, &Pmod, &Pprod, &Cadd, &Cfirst, &Cmod, &Cprod, &Ladd, &Lfirst, &Lmod, &Lprod, &Radd, &Rfirst, &Rmod, &Rprod);
    P[1] = Pfirst % Pmod;
    for (int i = 2; i <= N; ++i) P[i] = ((ll)P[i - 1] * Pprod + Padd + i) % Pmod;
    C[1] = Cfirst % Cmod;
    for (int i = 2; i <= N; ++i) C[i] = ((ll)C[i - 1] * Cprod + Cadd + i) % Cmod;
    L[1] = Lfirst % Lmod;
    for (int i = 2; i <= N; ++i) L[i] = ((ll)L[i - 1] * Lprod + Ladd + i) % Lmod;
    R[1] = Rfirst % Rmod;
    for (int i = 2; i <= N; ++i) R[i] = ((ll)R[i - 1] * Rprod + Radd + i) % Rmod;
	for (int i = 1; i <= N; ++i) {
		if (L[i] > R[i]) swap(L[i], R[i]);
		uniarr[++unicnt] = L[i];
		uniarr[++unicnt] = R[i];
		uniarr[++unicnt] = P[i];
	}
	
	sort(uniarr+1, uniarr+1+unicnt);
	unicnt = unique(uniarr+1, uniarr+1+unicnt) - uniarr - 1;

	for (int i = 1; i <= N; ++i) {
		qr[i].k = qr[i].id = i;
		qr[i].p = lower_bound(uniarr+1, uniarr+1+unicnt, P[i]) - uniarr;
		range[i].l = lower_bound(uniarr+1, uniarr+1+unicnt, L[i]) - uniarr;
		range[i].r = lower_bound(uniarr+1, uniarr+1+unicnt, R[i]) - uniarr;
		range[i].c = C[i];
	}
	sort(range+1, range+1+N);

	div(1, N, 1, N);
	
	int res = 0;
	for (int i = 1; i <= N; ++i) {
		res = (res + ans[i]) % MOD;
	}
	pr("%lld", res);
}

signed main()
{
	#ifndef ONLINE_JUDGE
	//FILE_IN
	FILE_OUT
	#endif
	int T = 1;//cin >> T;
	while (T--) solve();

	return AC;
}


