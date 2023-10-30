/*code by Cheemsadoge*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e9+1145;
const int MOD=10007;
int jc[MOD+11450];
int gcd(int a,int b)
{
	if(b>a) return gcd(b,a);
	if(b==0) return a;
	return gcd(b,a%b);
}
long long fast_pow(int a,int x,int p) //fast_pow
{
	if(a%p==0) return 0;
	long long no=a,ans=1;
	while(x){
		if(x&1) ans=1ll*ans*no%p;
		x>>=1;no=1ll*no*no%p;
	}
	return ans;
}
int C(int n,int m)
{
	return 1ll*jc[n]*fast_pow(jc[m],MOD-2,MOD)%MOD*fast_pow(jc[n-m],MOD-2,MOD);
}
int Lucas(int n,int m)
{
	if(m==0) return 1;
	return 1ll*C(n%MOD,m%MOD)*Lucas(n/MOD,m/MOD)%MOD;
}
int Catalan(int n)
{
	return 1ll*Lucas(2*n,n)/(n+1)%MOD;
}
int t,n;
int main() {
	freopen("runner.in","r",stdin);
	freopen("runner.out","w",stdout);
	jc[0]=1;
	for(int i=1;i<=MOD;i++) jc[i]=1ll*jc[i-1]*i%MOD;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int ans=Catalan(n)%MOD;
		printf("%d\n",ans*2%MOD);
	}
	return 0;
}


//h[n]=C[2n,n]/(n+1)(n=0,1,2,...)
