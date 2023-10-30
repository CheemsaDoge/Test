#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(int i = j;i <= k;++i)
#define repp(i,j,k) for(int i = j;i >= k;--i)
int rd()
{
	int num = 0;char c = getchar();bool flag = true;
	while(c < '0'||c > '9') {if(c == '-') flag = false;c = getchar();}
	while(c >= '0' && c <= '9') num = num*10+c-48,c = getchar();
	if(flag) return num;else return -num;
}
const int p = 1e9+9;
int n,k;
int a[2010],b[2010],P[2010],fac[2010];
int dp[2010][2010],f[2010],g[2010],c[2010][2010];
inline int min(int a,int b){return a<b?a:b;}
inline int calc(int a,int b){return (a+=b)>=p?a-=p:a;}
inline int mul(int a,int b){return 1ll*a*b%p;}
inline int del(int a,int b){return (a-=b)<0?a+=p:a;}
int main()
{ 
//	freopen("fear.in", "r", stdin);
//	freopen("fear.out", "w", stdout);
    n = rd();k = rd();
    if((n-k)%2 != 0) {printf("0\n");return 0;}
	rep(i,1,n) a[i] = rd();rep(i,1,n) b[i] = rd();
	sort(a+1,a+n+1);sort(b+1,b+n+1);
	int j = 0;
	rep(i,1,n) {while(j < n && a[i]>b[j+1])j++;P[i] = j;}
	dp[0][0] = 1;
	rep(i,1,n) rep(j,0,min(i,P[i]))
	 	if(j != 0)dp[i][j] = calc(dp[i-1][j],mul(dp[i-1][j-1],P[i]-j+1));
	    else dp[i][j] = dp[i-1][j];
	rep(i,1,n)
	{
		c[i][0] = c[i][i] = 1;
		rep(j,1,i-1) c[i][j] = calc(c[i-1][j],c[i-1][j-1]);
	}
	fac[0] = 1; rep(i,1,n) fac[i] = mul(fac[i-1],i);
	rep(i,1,n) g[i] = f[i] = mul(dp[n][i],fac[n-i]);
	repp(i,n,1) rep(j,i+1,n) f[i] = del(f[i],mul(f[j],c[j][i]));
	printf("%d\n",f[n/2+(k+1)/2]);
	return 0;
}

