/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int siz[MAXN],son[MAXN],fa[MAXN],dep[MAXN],top[MAXN],dfn[MAXN],pre[MAXN];
int add[MAXN];
struct EDGE{
	int u,v,val,nxt;
}edge[MAXM*3];
int head[MAXN],totr;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
void dfs1(int now,int fath)
{
	siz[now]=1,fa[now]=fath,son[now]=0,dep[now]=dep[fath]+1;
	for(int i=head[now];i;i=edge[i].nxt) if(edge[i].v!=fath) dfs1(edge[i].v,now),siz[now]+=siz[edge[i].v],son[now]=siz[son[now]]>siz[edge[i].v]?son[now]:edge[i].v;
	return;
}
int dfs_num;
void dfs2(int now,int topx)
{
	#define u now
	dfn[now]=++dfs_num;
	pre[dfs_num]=now;
	top[now]=topx;
	if(son[u]) dfs2(son[u],topx); else return;
	for(int i=head[u];i;i=edge[i].nxt) {
		if(edge[i].v!=fa[u]&&edge[i].v!=son[u]) {
			dfs2(edge[i].v,edge[i].v);
		}
	}
	#undef u
}
int LCA(int a,int b)
{
	while(1)
	{
		if(top[a]==top[b]) return dep[a]<dep[b]?a:b;
		if(dep[top[a]]<dep[top[b]]) swap(a,b);
		a=fa[top[a]];
	}
}

int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n,m,s,x,y,a,b;
	read(n);read(m);read(s);
	for(int i=1;i<n;i++)
	{
		read(x);read(y);
		add_edge(x,y);add_edge(y,x);
	}
	dfs1(s,0);dfs2(s,s);
	for(int i=1;i<=m;i++)
	{
		read(a);read(b);
		write(LCA(a,b));
		putchar('\n');
	}
//	for(int i=1;i<=n;i++) printf("%d  top%d son%d fa%d dep%d size%d\n",i,top[i],son[i],fa[i],dep[i],siz[i]);
}
