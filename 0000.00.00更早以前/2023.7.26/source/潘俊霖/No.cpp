#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
#define ll long long
#define ri register int
#define rl register long long
int n,m,dp[20][3],p[50];
inline int initialize() {
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (ri i = 1; i <= 10; i++) {
		dp[i][0]=dp[i-1][0]*9-dp[i-1][1];
		dp[i][1]=dp[i-1][0];
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];
	}
}
inline ll cal(ll x) {
	rl cnt=0,ans=0;
	//·ÖÀë
	int a=x;
	while(a) {
		p[++cnt]=a%10;
		a/=10;
	}
	p[cnt+1]=0;
	//
	bool pd=0;
	for(ri i=cnt; i; i--) {
		ans+=p[i]*dp[i-1][2];
		if(pd)
			ans+=p[i]*dp[i-1][0];
		else {
			if(p[i]==4||(p[i]==2&&p[i+1]==6))pd=1;
			if(p[i]>2&&p[i+1]==6)ans+=dp[i][1];
			if(p[i]>4)ans+=dp[i-1][0];
			if(p[i]>6)ans+=dp[i-1][1];
		}
	}
	return (x-ans);
}
int main() {
	freopen("No.in","r",stdin);
	freopen("No.out","w",stdout);
	initialize();
	while(1) {
		read(n);
		read(m);
		if(!n&&!m)break;
		printf("%lld\n",cal(max(n,m)+1)-cal(min(n,m)));
	}
	return 0;
}

