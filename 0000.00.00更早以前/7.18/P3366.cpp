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
const int MOD=1e9+7;
priority_queue<int>c;
const int MAXN=1e5+1145;
struct edge{
	int to,val,nxt;
}edge[MAXN*4];
int totr=0,head[MAXN];
bool vis[MAXN];
int dis[MAXN];
void add_edge(int u,int v,int val)
{
	edge[++totr].to=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
	edge[totr].val=val;
}
int minn=2147483647;
int po;
int main()
{
	rl sum=0;
	ri n,m,a,b,c;
	read(n);read(m);
	for(ri i=1;i<=m;i++)
	{
		read(a);read(b);read(c);
		add_edge(a,b,c);
		add_edge(b,a,c);
	}
	vis[1]=1;dis[1]=0;
	for(ri i=1;i<=n;i++)
		dis[i]=2147483647;
	for(ri i=head[1];i;i=edge[i].nxt)
		dis[edge[i].to]=edge[i].val;
	vis[1]=1;po=1;ri i,x;
	while(++po<=n)
	{
		minn=2147483647;
		for(i=1;i<=n;i++)
			if(dis[i]<minn&&!vis[i])
			{
				x=i;
				minn=dis[i];
			}
		if(minn==2147483647)
		{
			printf("orz");
			return 0;
		}
		vis[x]=1;sum+=minn;
		for(i=head[x];i;i=edge[i].nxt)
			if(dis[edge[i].to]>edge[i].val&&!vis[edge[i].to])
				dis[edge[i].to]=edge[i].val;
	}
	printf("%lld",sum);
}
