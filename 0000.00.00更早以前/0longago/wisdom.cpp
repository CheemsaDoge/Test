//O(mlog2n)
#include<bits/stdc++.h>
using namespace std;
#define INF 1000000001
const int N=1e6+1145;
int n,m,a[N],totr,opt;
struct INT
{
	int l,r;
	int lch,rch;
	int tag;
}rt[N];
void calc(int x)
{
	rt[x].tag=min(rt[rt[x].lch].tag,rt[rt[x].rch].tag);
}
void build(int l,int r)
{
	totr++;
	int x=totr;
	rt[x].l=l;
	rt[x].r=r;
	if(l==r)
	{
		rt[x].tag=a[r];
		return;
	}
	int mid=(l+r)/2;
	rt[x].lch=totr+1;
	build(l,mid);
	rt[x].rch=totr+1;
	build(mid+1,r);
	calc(x);
	return;
}
int query(int x,int l,int r)
{
	if(l<=rt[x].l&&rt[x].r<=r){///
		return rt[x].tag;
	}
	if(l>rt[x].r||r<rt[x].l)
		return INF;
	return min(query(rt[x].lch,l,r),query(rt[x].rch,l,r));
}
void modify(int x,int y,int v)
{
	if(rt[x].l==rt[x].r)
	{
		rt[x].tag=v;
		return ;
	}
	int mid=(rt[x].l+rt[x].r)/2;
	if(y<=mid)modify(rt[x].lch,y,v);
	if(y>mid)modify(rt[x].rch,y,v);
	calc(x);
}
int main()
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n);
	int x,y;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&opt);
		scanf("%d%d",&x,&y);
		if(opt==1)
			modify(1,x,y);
		else
		{
			int c=query(1,x,y);
			printf("%d\n",c);
		}
	}
}
