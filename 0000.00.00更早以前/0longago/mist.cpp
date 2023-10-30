#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
#define MAX_V 1919810
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int INF=1e9+1145;
int l,r;
int n,val[MAX_V];
int maxn[MAX_V];
bool allow[MAX_V];
void Initialize(int n)
{
	for(int i=0;i<=n+1;i++)
		maxn[i]=-1;
}
int tui(int x)
{
	int maxx=0;
	for(int i=l;i<=r&&x-i>=0;i++)
		if(!allow[x-i])
		{
			if(maxn[x-i]==-1)
				tui(x-i);
			maxx=max(maxx,maxn[x-i]);
		}
	return maxn[x]=maxx+val[x];
}
int main()
{
	freopen("mist.in","r",stdin);
	freopen("mist.out","w",stdout);
	read(n);
	read(l);
	read(r);
	Initialize(n);
	for(int i=0;i<=n;i++)
		read(val[i]);
	for(int i=1;i<l;i++)
		allow[i]=1;
	tui(n);
	printf("%d",maxn[n]);
}
