/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("no solution")
/*---------------------------------pre------------------------------------*/
int jacobi(int p, int q) {
	if (p == 1) return 1;
	if (p % 2 == 0) {
		int r = jacobi(p / 2, q);
		if (q % 8 == 1 || q % 8 == 7) return r;
		else return -r;
	}
	if (p > q) return jacobi(p % q, q);
	else {
		int r = jacobi(q % p, p);
		if (p % 4 == 1 || q % 4 == 1) return r;
		else return -r;
	}
}

inline int getN(int p) {
	srand(int(time(NULL)));
	for (;;) {
		int x = rand() % (p - 1) + 1;
		if (jacobi(x, p) == -1) return x;
	}
	return -1;
}

inline int fastPow(int low, int high, int p) {
	int res = 1;
	while (high) {
		if (high & 1) res = (int) (1LL * res * low % p);
		high>>=1;
		low=(int)(1LL * low * low % p);
	}
	return res;
}

int The_shy(int n, int p, int N, int h, int s) {
	if (h%2==1)
		return (int) (1LL*fastPow(n,(h+1)/2,p)*fastPow(N,s/2,p)%p);
	int x=(int)(1LL*fastPow(n,h/2,p)*fastPow(N,s/2,p)%p);
	if (x==1) return The_shy(n,p,N,h/2,s/2);
	else return The_shy(n,p,N,h/2,s/2+(p-1)/2);
}

int solve(int n, int p) {
	if (n == 0) return 0;
	if (jacobi(n, p) == -1) return -1;
	int N = getN(p);
	return The_shy(n, p, N, (p - 1) / 2, 0);
}

int main() {
	freopen("root.in","r",stdin);
	freopen("root.out","w",stdout);
	int te, n, p;
	read(te);
	for (int t = 1; t <= te; ++t) {
		read(n);read(p);
		int x = solve(n, p);
		if (x == -1) puts("Hola!");
		else if (x == 0) puts("0");
		else {
			int y=p-x;
			if (x > y) write(y),pk,write(x),pc;
			else write(x),pk,write(y),pc;
		}
	}
	return 0;
}
