#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
#define ll long long
#define ri register int
#define rl register long long
const int MAXM=3e5+1145;
const int MAXN=3e5+1145;
int opt,n,m,k,s;
int rd[MAXN];
bool vis[MAXN];bool safe[MAXN];
int head[MAXN],totr;int dis[MAXN];
struct Edge{
	int u,v,val,nxt;
}edge[MAXN];
void add_edge(int u,int v,int val)
{
	rd[u]++;
	edge[++totr].nxt=head[v];edge[totr].u=v;
	edge[totr].v=u;edge[totr].val=val;head[v]=totr;
	return;
}
int st[MAXN];
queue<int>po;
void topu()
{
	#define v edge[i].v
	for(int i=1;i<=n;i++)
		if(!rd[i]) po.push(i);
	while(!po.empty())
	{
		int u=po.front();
		po.pop();
		for(int i=head[u];i;i=edge[i].nxt)
		{
			rd[v]--;
			dis[v]=min(dis[v],dis[u]+edge[i].val);
			if(!rd[v]) po.push(v);
		}
	}
	
	#undef v
}
//
//queue<int>sta;
//void dfs2(int x,int len)
//{
//	sta.push(x),vis[x]=1;
//	#define v edge[i].v
//	for(int i=head[x];i;i=edge[i].nxt)
//		if((dis[v]&&dis[v]>len+edge[i].val)||!dis[v]) dfs_ran(v,len+edge[i].val);
//	#undef v
//}
int main()
{
	memset(dis,0x3f,sizeof(dis));
	ri input,input2,input3;
	freopen("payday.in","r",stdin);
	read(opt);read(n);read(m);
	if(opt==1) return 0;
	freopen("payday.out","w",stdout);
	for(int i=1;i<=m;i++)
	{
		read(input);read(input2);read(input3);
		add_edge(input,input2,input3);
	}
	read(k);
	for(int i=1;i<=k;i++) read(st[i]);read(s);
	for(int i=1;i<=s;i++) read(input),dis[input]=0,rd[input]=0;
	topu();
	for(int i=1;i<=k;i++) if(dis[st[i]]==1061109567)printf(".gg\n");else printf("%d\n",dis[st[i]]);
	return 0;
}
