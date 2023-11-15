#include<cstdio>
#include<algorithm>
#define lson pos<<1
#define rson pos<<1|1
using namespace std;
const int maxn=2*1e5+10;
const int INF=1e9;
int n,m,opt;
int tot,head[maxn],to[maxn<<1],nxt[maxn<<1],val[maxn<<1];
int cnt,son[maxn],top[maxn],id[maxn],deep[maxn],fa[maxn],size[maxn],a[maxn],w[maxn];
int sum[maxn<<2],mx[maxn<<2],mn[maxn<<2];
int lazy[maxn<<2];
struct edge
{
	int x,y;
}idx[maxn];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<48||ch>57)
		if(ch=='-')
			f=-1,ch=getchar();
	while(ch>=48&&ch<=57)
		x=x*10+ch-48,ch=getchar();
	return x*f;
}
void add(int x,int y,int z)
{
	to[++tot]=y;
	nxt[tot]=head[x];
	val[tot]=z;
	head[x]=tot;
}
void dfs1(int x,int f)
{
	deep[x]=deep[f]+1;
	fa[x]=f;
	size[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==f)
			continue;
		dfs1(y,x);
		a[y]=val[i];
		size[x]+=size[y];
		if(!son[x]||size[y]>size[son[x]])
			son[x]=y;
	}
}
void dfs2(int x,int t)
{
	top[x]=t;
	id[x]=++cnt;
	w[cnt]=a[x];
	if(!son[x])
		return;
	dfs2(son[x],t);
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa[x]||y==son[x])
			continue;
		dfs2(y,y);
	}
}
void pushup(int pos)
{
	sum[pos]=sum[lson]+sum[rson];
	mx[pos]=max(mx[lson],mx[rson]);
	mn[pos]=min(mn[lson],mn[rson]);
}
void build(int pos,int l,int r)
{
	int mid=(l+r)>>1;
	if(l==r)
	{
		sum[pos]=mx[pos]=mn[pos]=w[l];
		return;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	pushup(pos);
}
void mark(int pos,int l,int r)
{
	lazy[pos]^=1;
	int tmp1=-sum[pos],tmp2=-mn[pos],tmp3=-mx[pos];
	sum[pos]=tmp1;
	mx[pos]=tmp2;
	mn[pos]=tmp3;
}
void pushdown(int pos,int l,int r)
{
	int mid=(l+r)>>1;
	if(lazy[pos])
	{
		mark(lson,l,mid);
		mark(rson,mid+1,r);
		lazy[pos]=0;
	}
}
void update(int pos,int l,int r,int x,int k)
{
	int mid=(l+r)>>1;
	if(l==r)
	{
		sum[pos]=mx[pos]=mn[pos]=k;
		return;
	}
	pushdown(pos,l,r);
	if(x<=mid)
		update(lson,l,mid,x,k);
	else
		update(rson,mid+1,r,x,k);
	pushup(pos);
}
void change(int pos,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	if(x<=l && r<=y)
	{
		mark(pos,l,r);
		return;
	}
	pushdown(pos,l,r);
	if(x<=mid)
		change(lson,l,mid,x,y);
	if(y>mid)
		change(rson,mid+1,r,x,y);
	pushup(pos);
}
int query_sum(int pos,int l,int r,int x,int y)
{
	int ret=0;
	int mid=(l+r)>>1;
	if(x<=l && r<=y)
		return sum[pos];
	pushdown(pos,l,r);
	if(x<=mid)
		ret+=query_sum(lson,l,mid,x,y);
	if(y>mid)
		ret+=query_sum(rson,mid+1,r,x,y);
	return ret;
}
int query_max(int pos,int l,int r,int x,int y)
{
	int ret=-INF;
	int mid=(l+r)>>1;
	if(x<=l && r<=y)
		return mx[pos];
	pushdown(pos,l,r);
	if(x<=mid)
		ret=max(ret,query_max(lson,l,mid,x,y));
	if(y>mid)
		ret=max(ret,query_max(rson,mid+1,r,x,y));
	return ret;
}
int query_min(int pos,int l,int r,int x,int y)
{
	int ret=INF;
	int mid=(l+r)>>1;
	if(x<=l && r<=y)
		return mn[pos];
	pushdown(pos,l,r);
	if(x<=mid)
		ret=min(ret,query_min(lson,l,mid,x,y));
	if(y>mid)
		ret=min(ret,query_min(rson,mid+1,r,x,y));
	return ret;
}
void chain_upd(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		change(1,1,n,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(deep[x]<deep[y])
		swap(x,y);
	if(x!=y)
		change(1,1,n,id[y]+1,id[x]);
}
int q_sum(int x,int y)
{
	int ret=0;
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		ret+=query_sum(1,1,n,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(deep[x]<deep[y])
		swap(x,y);
	if(x!=y)
		ret+=query_sum(1,1,n,id[y]+1,id[x]);
	return ret;
}
int q_max(int x,int y)
{
	int ret=-INF;
	while(top[x]!=top[y])
	{
		if(deep[top[x]]<deep[top[y]])
			swap(x,y);
		ret=max(ret,query_max(1,1,n,id[top[x]],id[x]));
		x=fa[top[x]];
	}
	if(deep[x]<deep[y])
		swap(x,y);
	if(x!=y)
		ret=max(ret,query_max(1,1,n,id[y]+1,id[x]));
	return ret;
}
int main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		x=read();y=read();z=read();
		x++,y++;
		idx[i].x=x;
		idx[i].y=y;
		add(x,y,z);
		add(y,x,z);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	m=read();
	for(int i=1;i<=m;i++)
	{
		int a,b;
		opt=read();a=read();b=read();
		if(opt==1)
		{
			int goal=deep[idx[a].x]>deep[idx[a].y]?idx[a].x:idx[a].y;
			update(1,1,n,id[goal],b);
		}
		else if(opt==2)
		{
			a++,b++;
			chain_upd(a,b);
		}
		else if(opt==3)
		{
			a++,b++;
			printf("%d\n",q_sum(a,b));
		}
		else if(opt==4)
		{
			a++,b++;
			printf("%d\n",q_max(a,b));
		}
	}
	return 0;
}