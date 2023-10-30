#include <bits/stdc++.h>
using namespace std;
#define ll long long int
inline ll read()
{
    ll io=0;
	char in=getchar();
    while(in<'0'||in>'9')in=getchar();
    while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
    return io;
}
int f[10][530];
int main()
{
	int maxn=0; 
	int n;
	int sum=1;
	n=read();
	for(int i=0;i<n;i++)
		sum*=2;
	for(int j=1;j<=sum;j++)
		for(int k=1;k<=sum;k++)
			f[1][k]=((!(j&k))&&(!((j<<1)&k))&&(!((j>>1)&k)))?1:0;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=sum;j++)
			for(int k=1;k<=sum;k++)
				f[i][k]=((!(j&k))&&(!((j<<1)&k))&&(!((j>>1)&k)))?1+f[i-1][j]:f[i-1][j];
	for(int i=1;i<=sum;i++)
		maxn+=f[n][i];
	printf("%d %d",maxn,f[n][n]);
}
