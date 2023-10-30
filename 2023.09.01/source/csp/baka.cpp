/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=1e6+10;const int MAXN=1e6+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("no solution")
/*---------------------------------pre------------------------------------*/
struct SEGmentTree{
	struct RT{
		int l,r,maxn;
	}rt[MAXN*2];
	int val[MAXN];
	#define lch (a<<1)
	#define rch ((a<<1)+1)
	#define mid rt[a].l+((rt[a].r-rt[a].l)>>1)
	void build(int a,int l,int r)
	{
		rt[a].l=l;
		rt[a].r=r;
		if(l==r)
		{
			rt[a].maxn=val[l];
			return;
		}
		build(lch,l,mid);
		build(rch,mid+1,r);
		rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
	}
	#undef mid
	void change(int a,int y,int v)
	{
		if(rt[a].l==rt[a].r)
		{
			rt[a].maxn=v;
			return ;
		}
		int mid=(rt[a].l+rt[a].r)/2;
		if(y<=mid) change(lch,y,v);
		if(y>mid) change(rch,y,v);
		rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
	}
	int query(int a,int l,int r)
	{
		if(l<=rt[a].l&&rt[a].r<=r){
			return rt[a].maxn;
		}
		if(l>rt[a].r||r<rt[a].l)
			return 0;
		return max(query(lch,l,r),query(rch,l,r));
	}
}T;
#undef lch
#undef rch
int n,l,r,ans=0;
int a[MAXN];
int main()
{
	freopen("baka.in","r",stdin);
	freopen("baka.out","w",stdout);
	read(n);read(l);read(r);
	for(int i=1;i<=n+1;i++)
		read(a[i]);
	int st=1+l;
	int cha=max(2*l-r-1,0);
	for(int z=0;st-l<=1+n;z++)
	{
		for(int i=0;i<=r-l;i++)
		{
			int cur=st+i;
			T.val[cur]=a[cur];
		}
		st+=r-l+1+cha;
	}
	st=1+l;
	T.build(1,1,n+r+1);
	for(int z=0;st-l<=1+n;z++)
	{
		for(int i=0;i<=r-l;i++)
		{
			int cur=st+i;
			int val=T.val[cur]+T.query(1,cur-r,cur-l);
			T.change(1,cur,val);
			ans=max(ans,val);
		}
		st+=r-l+1+cha;
	}
	write(T.query(1,n,n+r+1));
}
