#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<iostream>
#define MAXN 30010
#define MAXM MAXN*2+1
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
struct Edge{
	int v;
	int nex;
}E[MAXM];
int head[MAXN],tote=0;
void Add_Edge(int u,int v){
	tote++;
	E[tote].v=v;
	E[tote].nex=head[u];
	head[u]=tote;
}
int size[MAXN];//子树点的个数 
int dep[MAXN];//深度 
int fa[MAXN];//父亲节点 
int son[MAXN];//重儿子 
int top[MAXN];//所在重链最浅节点编号 
int a[MAXN];

int val[MAXN];
int dfn[MAXN],dfncnt=0;//dfs序 

int dfs1(int x){
	size[x]=1;
	for(int i=head[x];i;i=E[i].nex)
	{
		int v=E[i].v;
//		if(v!=fa[x])
		{
			fa[v]=x;
			dep[v]=dep[x]+1;
			dfs1(v);
			size[x]+=size[v];
			if(size[son[x]]<size[v])
				son[x]=v;
		}
	}
}
int dfs2(int x)
{
	dfncnt++;
	dfn[x]=dfncnt;
	val[dfn[x]]=a[x];
	if(x==son[fa[x]])
		top[x]=top[fa[x]];
	else
		top[x]=x;
	
	if(son[x]!=0)
		dfs2(son[x]);
	
	
	for(int i=head[x];i;i=E[i].nex)
	{
		int v=E[i].v;
		if(v!=fa[x]&&v!=son[x])
			dfs2(v);
	}
}

struct SGtree{
	struct Node{
		int l,r;
		int lch,rch;
		int val,tag;
	}rt[MAXN*2+1];
	int totr;
	int build(int l,int r,int *a)
	{
		totr++;
		int x=totr;
		rt[x].l=l;
		rt[x].r=r;
		if(l==r){
			rt[x].val=a[l];
			return x;
		}
		int mid=((l+r)>>1);
		rt[x].lch=build(l,mid,a);
		rt[x].rch=build(mid+1,r,a);
		return x;
	}
	int calc(int x)
	{
		return rt[x].val+(rt[x].r-rt[x].l+1)*rt[x].tag;
	}
	void push_up(int x)
	{
		rt[x].val=
			calc(rt[x].lch)+
			calc(rt[x].rch);
	}
	void push_down(int x)
	{
		rt[rt[x].lch].tag+=rt[x].tag;
		rt[rt[x].rch].tag+=rt[x].tag;
		rt[x].tag=0;
	}
	void modify(int x,int l,int r,int v)
	{
		if(rt[x].r<l||rt[x].l>r)
			return ;
		if(l<=rt[x].l&&rt[x].r<=r)
		{
			rt[x].tag+=v;
			rt[x].val=calc(x);
			return ;
		}
		push_down(x);
		modify(rt[x].lch,l,r,v);
		modify(rt[x].rch,l,r,v);
		push_up(x);
	}
	int query(int x,int l,int r)
	{
		if(rt[x].r<l||rt[x].l>r)
			return 0;
		if(l<=rt[x].l&&rt[x].r<=r)
			return calc(x);
		push_down(x);
		push_up(x);
		return query(rt[x].lch,l,r)+query(rt[x].rch,l,r);
	}
	SGtree(){
		totr=0;
	}
}T1;



int main()
{
	memset(newly, -1, sizeof(newly));
	int n; scanf("%d", &n);
	for(int i=1; i<n; i++)
	{
		int x,y; scanf("%d%d", &x, &y);
		add(x, y),add(y, x);
	}
	dfs1(1, 0);
	f[1]=now,now+=((len[1]-1)<<1)+1;
	g[1]=now,now+=((len[1]-1)<<1)+1;
	dfs(1);
	cout << ans << '\n';
	return 0;
}
