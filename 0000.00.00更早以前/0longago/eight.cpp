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
ll n,sum[200010],q,ans;
short f[200010];
bool num[9];
int main()
{
	freopen("eight.in","r",stdin);
	freopen("eight.out","w",stdout);
	n=read();
	int c;
	for(int i=1;i<=n;i++)
	{
		c=read();
		f[i]=(f[i-1]^(1<<(c-1)));
	}
	for(int i=1;i<=n;i++)
	{
		sum[f[i-1]]++;
		for(int j=1;j<=8;j++)
			ans+=sum[(f[i]^(1<<(j-1)))];
		ans+=sum[f[i]];
	}
	printf("%lld",ans);
}
