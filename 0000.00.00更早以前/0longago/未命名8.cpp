#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN=550000;
const int INF=2E9+233;
int read()
{
	int x=0, w=0; char ch=0;
	while (!isdigit(ch)) w|=ch=='-', ch=getchar();
	while (isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48), ch=getchar();
	return w?-x:x;
}
struct SegmentTree
{
	struct Node
	{
		int l, r;
		int mx, mx_, se, cnt; ll sum;
		int add1, add1_, add2, add2_;
	} tr[4*MAXN];
	#define lc (o<<1)
	#define rc (o<<1|1)
	void pushup(int o)
	{
		tr[o].sum=tr[lc].sum+tr[rc].sum;
		tr[o].mx_=max(tr[lc].mx_, tr[rc].mx_);
		if (tr[lc].mx==tr[rc].mx)
		{
			tr[o].mx=tr[lc].mx;
			tr[o].se=max(tr[lc].se, tr[rc].se);
			tr[o].cnt=tr[lc].cnt+tr[rc].cnt;
		}
		else if (tr[lc].mx>tr[rc].mx)
		{
			tr[o].mx=tr[lc].mx;
			tr[o].se=max(tr[lc].se, tr[rc].mx);
			tr[o].cnt=tr[lc].cnt;
		}
		else
		{
			tr[o].mx=tr[rc].mx;
			tr[o].se=max(tr[lc].mx, tr[rc].se);
			tr[o].cnt=tr[rc].cnt;
		}
	}
	void update(int o, int k1, int k1_, int k2, int k2_)
	{
		tr[o].sum+=1ll*k1*tr[o].cnt+1ll*k2*(tr[o].r-tr[o].l+1-tr[o].cnt);
		tr[o].mx_=max(tr[o].mx_, tr[o].mx+k1_);
		tr[o].add1_=max(tr[o].add1_, tr[o].add1+k1_);
		tr[o].mx+=k1, tr[o].add1+=k1;
		tr[o].add2_=max(tr[o].add2_, tr[o].add2+k2_);
		if (tr[o].se!=-INF) tr[o].se+=k2;
		tr[o].add2+=k2;
	}
	void pushdown(int o)
	{
		int tmp=max(tr[lc].mx, tr[rc].mx);
		if (tr[lc].mx==tmp)
			update(lc, tr[o].add1, tr[o].add1_, tr[o].add2, tr[o].add2_);
		else update(lc, tr[o].add2, tr[o].add2_, tr[o].add2, tr[o].add2_);
		if (tr[rc].mx==tmp)
			update(rc, tr[o].add1, tr[o].add1_, tr[o].add2, tr[o].add2_);
		else update(rc, tr[o].add2, tr[o].add2_, tr[o].add2, tr[o].add2_);
		tr[o].add1=tr[o].add1_=tr[o].add2=tr[o].add2_=0;
	}
	void build(int o, int l, int r, int* a)
	{
		tr[o].l=l, tr[o].r=r;
		tr[o].add1=tr[o].add1_=tr[o].add2=tr[o].add2_=0;
		if (l==r)
		{
			tr[o].sum=tr[o].mx_=tr[o].mx=a[l];
			tr[o].se=-INF, tr[o].cnt=1;
			return;
		}
		int mid=l+r>>1;
		build(lc, l, mid, a);
		build(rc, mid+1, r, a);
		pushup(o);
	}
	void modify1(int o, int l, int r, int k)
	{
		if (tr[o].l>r||tr[o].r<l) return;
		if (l<=tr[o].l&&tr[o].r<=r)
			{ update(o, k, k, k, k); return; }
		pushdown(o);
		modify1(lc, l, r, k), modify1(rc, l, r, k);
		pushup(o);
	}
	void modify2(int o, int l, int r, int k)
	{
		if (tr[o].l>r||tr[o].r<l||k>=tr[o].mx) return;
		if (l<=tr[o].l&&tr[o].r<=r&&k>tr[o].se)
			{ update(o, k-tr[o].mx, k-tr[o].mx, 0, 0); return; }
		pushdown(o);
		modify2(lc, l, r, k), modify2(rc, l, r, k);
		pushup(o);
	}
	ll query3(int o, int l, int r)
	{
		if (tr[o].l>r||tr[o].r<l) return 0;
		if (l<=tr[o].l&&tr[o].r<=r) return tr[o].sum;
		pushdown(o);
		return query3(lc, l, r)+query3(rc, l, r);
	}
	int query4(int o, int l, int r)
	{
		if (tr[o].l>r||tr[o].r<l) return -INF;
		if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx;
		pushdown(o);
		return max(query4(lc, l, r), query4(rc, l, r));
	}
	int query5(int o, int l, int r)
	{
		if (tr[o].l>r||tr[o].r<l) return -INF;
		if (l<=tr[o].l&&tr[o].r<=r) return tr[o].mx_;
		pushdown(o);
		return max(query5(lc, l, r), query5(rc, l, r));
	}
	#undef lc
	#undef rc
} sgt;
int a[MAXN];
int main()
{
//	freopen("segbeats.in", "r", stdin);
//	freopen("segbeats.out", "w", stdout);
	int n=read(), m=read();
	for (int i=1; i<=n; i++) a[i]=read();
	sgt.build(1, 1, n, a);
	while (m--)
	{
		int op=read(), l, r, k;
		switch (op)
		{
			case 1:
				l=read(), r=read(), k=read();
				sgt.modify1(1, l, r, k);
				break;
			case 2:
				l=read(), r=read(), k=read();
				sgt.modify2(1, l, r, k);
				break;
			case 3:
				l=read(), r=read();
				printf("%lld\n", sgt.query3(1, l, r));
				break;
			case 4:
				l=read(), r=read();
				printf("%d\n", sgt.query4(1, l, r));
				break;
			case 5:
				l=read(), r=read();
				printf("%d\n", sgt.query5(1, l, r));
				break;
		}
	}
	return 0;
}
