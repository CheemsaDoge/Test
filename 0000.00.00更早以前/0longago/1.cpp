#include<cstdio>
using namespace std;
const int N=1e6+1145;
int tot,n,m,a[N];
struct INT
{
	int l,r;
	int rch,lch;
	int light,sum;
}rt[N];
void build(int l,int r)
{
	tot++;
	int x=tot;
	rt[x].l=l;
	rt[x].r=r;
	if(l==r)
	{
		rt[x].sum=a[l];
		return;
	}
	int mid=(l+r)/2;
	rt[x].lch=tot+1;
	build(l,mid);
	rt[x].rch=tot+1;
	build(mid+1,r);
	rt[x].sum=rt[rt[x].lch].sum+rt[rt[x].rch].sum;
}
void down(int x)
{
	rt[rt[x].lch].light+=rt[x].light;
	rt[rt[x].lch].sum+=(rt[rt[x].lch].r-rt[rt[x].lch].l+1)*rt[x].light;
	rt[rt[x].rch].light+=rt[x].light;
	rt[rt[x].rch].sum+=(rt[rt[x].rch].r-rt[rt[x].rch].l+1)*rt[x].light;
	rt[x].light=0;
}
void update(int x,int l,int r,int v)
{
	if(rt[x].l>r || rt[x].r<l) return;
	if(rt[x].l>=l && rt[x].r<=r)
	{
		rt[x].light+=v;
		rt[x].sum+=(rt[x].r-rt[x].l+1)*v;
		return;
	}
	update(rt[x].lch,l,r,v);
	update(rt[x].rch,l,r,v);
	rt[x].sum=rt[rt[x].lch].sum+rt[rt[x].rch].sum;
}
int query(int x,int l,int r)
{
	if(rt[x].l>r || rt[x].r<l) return 0;
	if(rt[x].l>=l && rt[x].r<=r) return rt[x].sum;
	if(rt[x].light>0) down(x);
	return query(rt[x].lch,l,r)+query(rt[x].rch,l,r);
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n);
	int l,r,x;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&x);
		update(1,l,r,x);
		printf("%lld\n",query(1,l,r));
	}
}
