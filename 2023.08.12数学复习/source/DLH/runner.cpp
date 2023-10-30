/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MOD=10007;const int MAXN=2e3+2;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
//int jc[MOD+1145];
int fast_pow(int a,int n)
{
	if(a==1||a==0) return a;
	int ans=1;
	while(n){
		if(n&1) ans=1ll*ans*a%MOD;
		a=1ll*a*a%MOD;
		n>>=1;
	}
	return ans;
}
//int C(int n,int m)
//{
//	if(m>n) return 0;
//	if(m==n||m==1) return 1;
//	return 1ll*jc[n]*fast_pow(jc[n-m],MOD-2)%MOD*fast_pow(jc[m],MOD-2)%MOD;
//}
ll C(ll n, ll m) {
    if(m>n) return 0;
    ll ans = 1;
    for(int i = 1; i <= m; i++) {
        ll a = (n + i - m) % MOD;ll b = i % MOD;
        ans = ans * (a * fast_pow(b, MOD - 2) % MOD) % MOD;
    }
    return ans;
}
int Lucas(int n,int m)
{
	if(m==0||n==m) return 1;
	return 1ll*Lucas(n/MOD,m/MOD)%MOD*C(n%MOD,m%MOD)%MOD;
}
//void Pre()
//{
//	int zan=1;
//	for(int i=1;i<=MOD;i++){
//		zan=1ll*zan*i%MOD;
//		jc[i]=zan;
//	}
//}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("runner.in","r",stdin);
	freopen("runner.out","w",stdout);	
//	Pre();
	int T,n;
	read(T);while(T--){
		read(n);write((2*(Lucas(2*n,n)-Lucas(2*n,n-1)+MOD))%MOD);putchar('\n');
	}
}
