/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define MOD 10007
/*---------------------------------pre------------------------------------*/
ll n, a[30010], s[30010], m, f[4][30010], c[60010], ans;
ll val(int x) {return lower_bound(s+1, s+m+1, x) - s;}
ll ask(int x, ll sum = 0) {
	for(; x; x -= (x & (-x))) sum += c[x];
	return sum;
}
void add(int x, ll v) {
	for(;x<=m;x+=(x&(-x))) c[x]+=v;
}
int main() {
	freopen("thair.in","r",stdin);
	freopen("thair.out","w",stdout);
	read(n);
	for(int i = 1; i <= n; i++) read(a[i]),s[i] = a[i];
	sort(s+1, s+n+1);
	m = unique(s+1, s+n+1) - s - 1;
	for(int i = 1; i <= n; i++) f[1][i] = 1, a[i] = val(a[i]);
	for(int i = 2; i <= 3; i++) {
		memset(c, 0, sizeof(c));
		for(int j = 1; j <= n; j++) {
			f[i][j] = ask(a[j]-1);
			add(a[j], f[i-1][j]);
		}
	}
	for(int i = 1; i <= n; i++) ans += f[3][i];
	write(ans);
	return 0;
}
