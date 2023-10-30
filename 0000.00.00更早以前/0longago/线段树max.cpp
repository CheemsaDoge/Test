#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1145;
int tot,a[N];
struct RT
{
	int l,r;
	int lch,rch;
	int tag;
}rt[N];
void calc(int x)
{
	rt[x].tag=max(rt[rt[x].lch].tag,rt[rt[x].rch].tag);
}
void build(int x,int l,int r)
{
	tot++;
	rt[x].l=l;
	rt[x].r=r;
	if(l==r)
	{
		rt[x].tag=a[l];
		return;
	}
	int mid=(l+r)/2;
	rt[x].lch=tot+1;
	build(tot+1,l,mid);
	rt[x].rch=tot+1;
	build(tot+1,mid+1,r);
	calc(x);
}
int query(int x,int l,int r)
{
	if(rt[x].l>=l&&rt[x].r<=r)
		return rt[x].tag;
	if(rt[x].r<l||rt[x].l>r)
		return -114514;
	return max(query(rt[x].lch,l,r),query(rt[x].rch,l,r));
}
int main()
{
	int n,m,l,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,1,n);
	while(m--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",query(1,l,r));
	}
}
