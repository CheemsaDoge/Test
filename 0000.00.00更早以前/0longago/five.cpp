#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;
inline ll read()
{
    ll io=0;
	char in=getchar();
    while(in<'0'||in>'9')in=getchar();
    while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
    return io;
}
struct Matrix
{
	int n,m;     //n-h m-l
	ll a[10][10];	//[6][6]
};
ll n,sum;
Matrix operator*(Matrix x,Matrix y) 	//f-t
{
	Matrix ret;
	for(int i=1;i<=x.n;i++)
		for(int j=1;j<=y.m;j++)
		{
			ret.a[i][j]=0;
			for(int k=1;k<=x.m;k++)
			{
				ret.a[i][j]+=(x.a[i][k]*y.a[k][j])%mod;
				ret.a[i][j]%=mod;
			}
		}
	ret.n=x.n;
	ret.m=y.m;
	return ret;
}
Matrix qmul(Matrix x,int b)
{
	Matrix ret;
	ret.n=x.n;
	ret.m=x.m;
	for(int i=1;i<=x.n;i++)
		for(int j=1;j<=x.m;j++)
			ret.a[i][j]=(i==j)?1:0;
	while(b>0)
	{
		if(b&1)
			ret=ret*x;
		x=x*x;
		b>>=1;
	}
	return ret;
}
Matrix a;
Matrix b;
int main()
{
	freopen("five.in","r",stdin);
	freopen("five.out","w",stdout);
	b.m=5;	b.n=1;
	for(int i=1;i<=5;i++)
		b.a[1][6-i]=read();
	n=read();
	if(n<=5)
	{
		printf("%lld",b.a[1][6-n]);
		return 0;
	}
	a.m=5;	a.n=5;
	a.a[1][1]=1;a.a[2][1]=1;a.a[3][1]=1;a.a[4][1]=1;a.a[5][1]=1;
	a.a[1][2]=1;a.a[2][3]=1;a.a[3][4]=1;a.a[4][5]=1;
	Matrix f=b*qmul(a,n-5);
		printf("%lld",f.a[1][1]%mod);
		
}
/*
	 	 __
1 1 0 0 0 |
1 1 1 0 0 |
1 0 1 0 0 |* [ai-1 ai-2 ai-3 ai-4 ai-5] 
1 0 0 1 0 |
1 0 0 0 1_|
		 

*/
