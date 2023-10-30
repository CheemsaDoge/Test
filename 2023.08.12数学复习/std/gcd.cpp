
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
const int inf=0x3f3f3f3f;
const int N=1e6+100;
LL a[N],b[N];

int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out", "w", stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	LL gcd=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		if(i!=1)
			gcd=__gcd(gcd,abs(a[i]-a[i-1]));
	}
	for(int i=1;i<=m;i++)
		scanf("%lld",b+i);
	for(int i=1;i<=m;i++)
		printf("%lld ",__gcd(b[i]+a[1],gcd));
    return 0;
}

