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
ll gcd(ll a,ll b)
{
	return b?gcd(b,a%b):a;
}
ll x,y,sum;
ll num=0;
int main()
{
	freopen("gover.in","r",stdin);
	freopen("gover.out","w",stdout);
	int n;
	x=read();
	y=read();
	sum=x*y;
	for(int i=x;i<=sqrt(sum)&&i<=y;i++)
		if(!(sum%i)&&sum/i<=y)
			num+=(gcd(i,sum/i)==x)?2:0;
	num-=gcd(sqrt(sum),sum/sqrt(sum))==x?1:0;
	printf("%lld",num);
}
