#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500010],b[500010];
long long prea[500010],preb[500010];
long long suma,sumb;
long long ans;
#define mod 1000000007
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		prea[i]=(prea[i-1]+a[i])%mod;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&b[i]);
		preb[i]=(preb[i-1]+b[i])%mod;
	}
	for(int i=1;i<=n;i++)
	{
		(ans+=(((n+1)*prea[i])%mod)*preb[i])%=mod;
		suma=(suma+prea[i])%mod;
		sumb=(sumb+preb[i])%mod;
	}
	long long tot=(suma*sumb)%mod;
	ans=(ans-tot+mod)%mod;
	printf("%lld",ans);
	return 0;
}
