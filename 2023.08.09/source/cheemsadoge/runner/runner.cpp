/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=119;const int INF=2147483647ll;//2^31-1
const int MOD=10007;
int jc[MOD+1145];
void initialize()
{
	jc[0]=1;jc[1]=1;
	for(int i=2;i<=MOD;i++) jc[i]=1ll*jc[i-1]*i%MOD;
}
int fast_pow(int a,int x,int p)
{
	int no=a,ans=1;
	while(x)
	{
		if(x&1) ans=1ll*ans*no%MOD;
		no=1ll*no*no%MOD;
		x>>=1;
	}
	return ans;
}
int C(int n,int m)
{
	return 1ll*jc[n]*fast_pow(jc[n-m],MOD-2,MOD)%MOD*fast_pow(jc[m],MOD-2,MOD)%MOD;
}
int Lucas(int n,int m)
{
	if(m==0) return 1;
	return 1ll*C(n%MOD,m%MOD)*Lucas(n/MOD,m/MOD)%MOD;
}
int t,n;
int main() {
	freopen("runner.in","r",stdin);
	freopen("runner.out","w",stdout);	
	initialize();
	read(t);
	while(t--) {
		read(n);
		int ans=2*(Lucas(2*n,n)-Lucas(2*n,n-1));
		printf("%d\n",ans<0?MOD-abs(ans):ans);
	}
	return 0;
}

//·Ç½µÂ·¾¶ 
