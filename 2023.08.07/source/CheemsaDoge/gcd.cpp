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
const int MAXN=3e5+1145;
ll a[MAXN];
ll n;
bool cmp(int x,int y)
{
	return x<y;
}
inline ll gcd(int x,int y)
{
	if(x<y) return gcd(y,x);
	return y?gcd(y,x%y):x;
}
int main()
{
	freopen("gcd.in","r",stdin);
	freopen("gcd.out","w",stdout);
	ri n,m;
	read(n);read(m);
	rl u;
	rl b;
	for(ri i=1;i<=n;i++)	read(a[i]);
	sort(a+1,a+n+1,cmp);
	for(ri i=1;i<=m;i++)
	{
		read(b);
		u=a[1]+b;
		for(ri j=2;j<=n;j++)
		{
			u=gcd(u,a[j]+b);
			if(u==1)
			{
				printf("1 ");
				break;
			}
			if(j==n)
				printf("%d ",u);
		}
	}
}
