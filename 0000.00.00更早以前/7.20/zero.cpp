#include <bits/stdc++.h>
using namespace std;

template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

#define ri register int
#define ll long long 
const int MAXN=2e6+1145;
const ll MOD=998244353ll;
int a[MAXN];
ll sum=1;
int main()
{
	
//	freopen("zero.in","r",stdin);
//	freopen("zero.out","w",stdout);
	ri T,n;
	read(T);
	int i=3;
	a[0]=0;a[1]=1;a[2]=2;
	while(T--)
	{
		sum=0;
		read(n);
		for(i=3;i<=n;i++)
		{
			a[i]=(i)*(a[i-1]+a[i-2])%MOD;
		}
		printf("%lld\n",a[n]);
	}
}
