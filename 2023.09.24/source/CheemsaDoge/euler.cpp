#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template<typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template<typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define pk putchar(' ')
#define int long long 
void _File() {
	freopen("euler.in","r",stdin);
	freopen("euler.out","w",stdout);
}
/*---------------------------------pre------------------------------------*/
bool inp[1000005];
int pri[1000005], pc;
void sieve(int mx) {
	inp[0] = inp[1] = true;
	for (int i = 2; i <= mx; ++i) {
		if (!inp[i]) pri[++pc] = i;
		for (int j = 1; i * pri[j] <= mx && j <= pc; ++j) {
			inp[i * pri[j]] = true;
			if (i % pri[j] == 0) break;
		}
	}
	return;
}
bool is_prime(int x) {
	if (x <= 1) return false;
	for (int i = 1; pri[i] * pri[i] <= x; ++i) if (x % pri[i] == 0) return false;
	return true;
}
int phi(int x) {
	int ans = x;
	for (int i = 1; pri[i] * pri[i] <= x; ++i) {
		if (x % pri[i] == 0) {
			while (x % pri[i] == 0) x /= pri[i];
			ans = ans / pri[i] * (pri[i] - 1);
		}
	}
	if (x > 1) ans = ans / x * (x - 1);
	return ans;
}
int T, B;
int f(int x, int max_phi) {
	max_phi -= B;
	if (max_phi <= 0) return x;
	while (max_phi--) {
		x = phi(x);
		if (x == 1) return 1;
	}
	return x;
}
int p1, p2;
int val[1000005], ps[1000005];
int a(int x) {
	return x * (x + 1) / 2;
}
int b(int x) {
	return ps[x - p1];
}
int c(int x) {
	return x - p2;
}
void pre() {
	for (int i = B; i; --i) {
		if (is_prime(i)) {
			p1 = i;
			break;
		}
	}
	for (int i = B + 60; i <= 1100000000; ++i) {
		if (is_prime(i)) {
			p2 = i;
			break;
		}
	}
	int mx = phi(p1);
	for (int i = p1; i <= p2; ++i) {
		mx = max(mx, phi(i));
		val[i - p1] = f(i, mx);
		if (i != p1) ps[i - p1] = ps[i - p1 - 1] + val[i - p1];
		else ps[i - p1] = val[i - p1];
	}
}
int solve(int x) {
	if (x < p1) return a(x);
	else if (x <= p2) return a(p1 - 1) + b(x);
	else return a(p1 - 1) + b(p2) + c(x);
}
signed main() {
	_File();
	sieve(1000000);
	read(T);read(B);
	pre();
	while (T--) {
		int L, R;
		read(L);read(R);
		write(solve(R)-solve(L-1));putchar('\n');
	}
	return 0;
}

