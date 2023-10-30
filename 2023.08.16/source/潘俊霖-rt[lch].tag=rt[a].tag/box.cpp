/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("no")
/*---------------------------------pre------------------------------------*/
struct EDGE{
	int u,v,val,nxt;
	bool tr;
}edge[MAXM+1145];
int head[MAXN],totr;
int s;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
EDGE e[MAXM+1145];int head2[MAXN],totr2;
void add_edge2(int u,int v){
	e[++totr2].u=u;
	e[totr2].v=v;
	e[totr2].nxt=head2[u];
	head2[u]=totr2;
}
int low[MAXN],dfn[MAXN],dfs_num,num,scc[MAXN],siz[MAXN],scval[MAXN],val[MAXN];
bool vis[MAXN],in_stack[MAXN];
stack<int>sta;
void Tarjan(int u)
{
	low[u]=dfn[u]=++dfs_num;in_stack[u]=1;
	vis[u]=true;sta.push(u);
	for(int i=head[u];i;i=edge[i].nxt)
	{
		#define v edge[i].v
		if(!dfn[v]){
			Tarjan(v);low[u]=min(low[v],low[u]);
		}
		else if(in_stack[v])low[u]=min(low[u],dfn[v]);
		#undef v
	}
	if(dfn[u]==low[u]){
		++num;
		while(sta.top()!=u)
		{
//			write(sta.top());pk;
			scval[num]+=val[sta.top()];
			scc[sta.top()]=num;
			in_stack[sta.top()]=false;
			siz[num]++;
			sta.pop();
		}
//		write(sta.top());pk;
		scval[num]+=val[sta.top()];
		scc[sta.top()]=num;
		in_stack[sta.top()]=false;
		siz[num]++;
		sta.pop();
//		pc;
	}
	
}
int rd[MAXN];
bool vvis[MAXN];
bool p[MAXN];
bool scp[MAXN];
void dfs(int u)
{
	vvis[u]=1;
	#define v edge[i].v
	for(int i=head[u];i;i=edge[i].nxt)
	{
		scp[scc[u]]|=p[u];
		scp[scc[v]]|=p[v];
		if(scc[u]!=scc[v]) add_edge2(scc[u],scc[v]),rd[scc[v]]++;
		if(!vvis[v]) dfs(v);
	}
	#undef v
}
int dis[MAXN];
int topo()
{
	memset(in_stack,0,sizeof(in_stack));
	stack<int>stac;int ans=0;
	stac.push(s);
	in_stack[s]=1;
	while(!stac.empty())
	{
		int u=stac.top();stac.pop();
		dis[u]+=scval[u];in_stack[u]=false;
		if(scp[u]) ans=max(ans,dis[u]);
		for(int j=head2[u];j;j=e[j].nxt)
		{
			dis[e[j].v]=max(dis[e[j].v],dis[u]);
			rd[e[j].v]--;
//			if(!rd[e[j].v]) 
			if(!rd[e[j].v]) stac.push(e[j].v);
		}
	}
	return ans;
}

int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("box.in","r",stdin);
	freopen("box.out","w",stdout);
	int n,m,u,v;
	read(n);read(m);
	for(int i=1;i<=m;i++)
	{
		read(u);read(v);
		add_edge(u,v);
	}
	for(int i=1;i<=n;i++) read(val[i]);
	read(s);read(u);
	for(int i=1;i<=u;i++) read(v),p[v]=true;
//	for(int i=1;i<=n;i++) if(!dfn[i]) 
	Tarjan(s);
	dfs(s);
	s=scc[s];
    write(topo());
}
