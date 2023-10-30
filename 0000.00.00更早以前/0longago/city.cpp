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
const int N=1e9+114514;
bool v[N];
int l,r;
int tot=0;
int sum=0;
int  prime[10000];	//N/ln(N)
int z;
void calc_sum(int l,int r)
{
	for(int i=1;i<=tot;i++)
	{
		z=prime[i];
		for(int j=((l/z==1)?2:l/z);z*j<=r;j++)	v[z*j]=1;
		v[prime[i]]=0;
	}
	v[2]=0;
	for(int i=l;i<=r;i++)
		sum+=v[i]?0:1;
}
void calc_primes()
{
	int n=sqrt(r);
	for(int i=2;i<=n;i++)
	{
		if(v[i])continue;
		prime[++tot]=i;
		for(int j=i;j*i<=n;j++)	v[i*j]=1;
	}
	calc_sum(l,r);
}
int main()
{
	freopen("city.in","r",stdin);
	freopen("city.out","w",stdout);
	l=read();
	r=read();
	calc_primes();
	printf("%d",sum);
}
