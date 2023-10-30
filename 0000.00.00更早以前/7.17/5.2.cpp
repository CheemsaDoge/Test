#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define rl register long long 
#define ll long long
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
ll aa[30];
ll ni[30];
ll exgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = exgcd(b, a % b, x, y);
  ll temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
ll gcd(ll a,ll b)
{
	if(b==0)	return a;
	if(a<b)	return gcd(b,a);
	return gcd(b,a%b);
}
int main()
{
//	freopen("5.2.in","r",stdin);
//	freopen("5.2.out","w",stdout);	
	ri n,k,m;
	rl in,ii;
	read(n);
	read(m);
	read(k);
	for(int i=0;i<=n;i++)
	{
		rl sum=1;
		for(int j=1;j<=m;j++)	read(in),sum*=in;
		aa[i]=sum;
	}
	for(int i=0;i<k;i++)
	{
		read(in);
		read(ii);
		rl x,y;
		if(gcd(in,ii)!=1)
		{
			printf("-1\n");
			continue;
		}
		int dd=gcd(aa[0],aa[ii]);
		exgcd(aa[in]/dd,aa[0]/dd,x,y);
		while(x<=0)
    			x+=abs(ii);
		rl ni=x;
		rl C=ni*aa[0];
		printf("%lld\n",C%ii);
	}
}
