/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=2e5+1145;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
ll a[MAXN],b[MAXN];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	int n,m;
	read(n);read(m);
	ll gcd=0;
	for(int i=1;i<=n;i++) {read(a[i]);if(i!=1) gcd=__gcd(gcd,abs(a[i]-a[i-1]));}
	for(int i=1;i<=m;i++) read(b[i]);
	for(int i=1;i<=m;i++) printf("%lld ",__gcd(b[i]+a[1],gcd));
	return 0;
}
