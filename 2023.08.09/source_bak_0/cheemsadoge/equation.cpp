/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=119;const int MAXM=1e6+1145;const int MOD=1e9+7;const int INF=2147483647ll;//2^31-1
#define db double
char in[MAXN];
int a[MAXN],n,m,temp,pd,ans;
bool q[MAXM];
int main() {
	freopen("equation.in","r",stdin);
	freopen("equation.out","w",stdout);	
	ios::sync_with_stdio(0);	//
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n+1;i++)
	{
		cin>>in;temp=1;
		for(int j=strlen(in)-1;j>=0;j--)
		{
			if(j==0&&in[j]==45) {a[i]=-a[i];break;}
			a[i]=(a[i]+1ll*(in[j]-48)*temp%MOD)%MOD;
			temp=1ll*temp*10%MOD;
		}
	}
	for(int i=1;i<=m;i++)
	{
		pd=0;temp=1;
		for(int j=1;j<=n+1;j++)
		{
			pd=(long long)(pd+1ll*a[j]*temp%MOD)%MOD;
			temp=1ll*i*temp%MOD;
		}
		if(!pd) ans++,q[i]=1;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=m;i++) if(q[i]) cout<<i<<"\n";
	return 0;
}
/*O(max(nm,nk)*/
