#include<bits/stdc++.h>
using namespace std;
const long long int N=1e6+1145;
long long int tot,n,m,a[N];
struct INT
{
	long long int l,r;
	long long int rch,lch;
	long long int light,sum;
}rt[N*3];
void cacl(int x)
{
	rt[x].sum=rt[rt[x].lch].sum+rt[rt[x].rch].sum;
}
void build(long long int l,long long int r)
{
	tot++;
	long long int x=tot;
	rt[x].l=l;
	rt[x].r=r;
	if(l==r)
	{
		rt[x].sum=a[l];
		return;
	}
	long long int mid=(l+r)/2;
	rt[x].lch=tot+1;
	build(l,mid);
	rt[x].rch=tot+1;
	build(mid+1,r);
	rt[x].sum=rt[rt[x].lch].sum+rt[rt[x].rch].sum;
}
inline void down(long long int x)
{
	rt[rt[x].lch].light+=rt[x].light;
	rt[rt[x].lch].sum+=(rt[rt[x].lch].r-rt[rt[x].lch].l+1)*rt[x].light;
	rt[rt[x].rch].light+=rt[x].light;
	rt[rt[x].rch].sum+=(rt[rt[x].rch].r-rt[rt[x].rch].l+1)*rt[x].light;
	rt[x].light=0;
}
void update(long long int x,long long int l,long long int r,long long int v)
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
void upgrade(int x)
{
	down(x);
	if(rt[x].lch==0)
		return;
	upgrade(rt[x].lch);
	upgrade(rt[x].rch);
}
long long int query(long long int x,long long int l,long long int r)
{	
	if(rt[x].l>r || rt[x].r<l) return 0;
	if(rt[x].l>=l && rt[x].r<=r) return rt[x].sum;
	return query(rt[x].lch,l,r)+query(rt[x].rch,l,r);
}
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(long long int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n);
	long long int l,r,x;
	for(long long int i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld",&l,&r,&x);
		update(1,l,r,x);
		upgrade(1);
		printf("%lld\n",query(1,l,r));
	}
}
