#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll read()
{
    ll io=0;
	char in=getchar();
    while(in<'0'||in>'9')in=getchar();
    while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
    return io;
}
ll n,sum,maxn;
const ll mod = 1e9+7;
void mo()
{
	sum%=mod;
}
bool isbad(int x,int y)		//O(n)
{
	int z=x&y;
	while(z>0)
	{
		if((z&1)&&((z>>1)&1))	return true;
		z>>=1;
	}
	return false;
}
ll f[11][520];
int main()
{
	freopen("four.in","r",stdin);
	freopen("four.out","w",stdout);
	n=read();
	maxn=1;
	for(int i=1;i<=n;i++)
		maxn*=2;
	for(int i=1;i<=maxn;i++)
		f[1][i]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=maxn;j++)
			for(int k=1;k<=maxn;k++)
			{
				if(!isbad(j,k))
					f[i][k]+=f[i-1][j];
					f[i][k]%=mod;
			}
	for(int i=1;i<=maxn;i++)
	{
		sum+=f[n][i];
		sum%=mod;
	}
	printf("%lld",sum);
}
