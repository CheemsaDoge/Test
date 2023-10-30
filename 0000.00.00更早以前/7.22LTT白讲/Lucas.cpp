#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1145;
int jc[MAXN],inv_jc[MAXN];
int totr=0;
long long quick_mi(int a,int b,int p)
{
	long long sum=1;
	while(b)
	{
		if(b&1)
			sum*=a;
		sum%=p;
		a*=a;
		b>>=1;
	}
	return sum;
}
long long ni(int a,int p)
{
	return quick_mi(a,p-2,p);
}
void prepare(int n,int p)
{
	long long sum=1;
	for(int i=1;i<=n;i++)
	{
		sum*=i;
		sum%=p;
		jc[++totr]=sum;
		inv_jc[totr]=ni(sum,p);
	}
}
long long C(int n,int m,int p)
{
	return (long long)jc[n]*inv_jc[n-m]*inv_jc[m]%p;
}

int Lucas(int n,int m,int p)
{
	if(m==0)	return 1;
	else return (C(n%p,m%p,p)*Lucas(n/p,m/p,p))%p;
}
int main()
{
	int n,m,p;
	cin>>p;
	prepare(p,p);
	jc[0]=1;
	inv_jc[0]=1;
	while(1)
	{
		cin>>n>>m;
		printf("%lld\n",Lucas(n,m,p));
	}
	queue<int>a;
	
}
