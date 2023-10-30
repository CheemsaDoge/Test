/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/

struct Segment_Tree{
	int val[MAXN],tot;
	#define lch (a*2)
	#define rch (a*2+1)
	#define midd ((l+r)>>1)
	struct PRT{
		int l,r,val,maxn,tag,mid,length;
	}rt[MAXN*4];
	void Initialize(int a,int l,int r)
	{
		rt[a].l=l;rt[a].r=r;rt[a].mid=midd;rt[a].length=(rt[a].r-rt[a].l+1);
		if(l==r) {
			rt[a].maxn=rt[a].val=val[l];
			return ;
		}
		Initialize(lch,l,midd);
		Initialize(rch,midd+1,r);
		rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
		rt[a].val=rt[lch].val+rt[rch].val;
	}
	void push_down(int a)
	{
		#define v rt[a].tag
		rt[lch].tag+=v;rt[rch].tag+=v;
		rt[lch].val+=rt[lch].length*v;
		rt[rch].val+=rt[rch].length*v;
		rt[lch].maxn+=v;rt[rch].maxn+=v;
		rt[a].tag=0;
		#undef v
	}
	void add_part(int a,int l,int r,int v)
	{
//		if(!rt[a].l) return ;
		if(rt[a].tag) push_down(a);
		if(rt[a].l>=l&&rt[a].r<=r) rt[a].tag+=v,rt[a].val+=rt[a].length*v,rt[a].maxn+=v;
		else{
			if(rt[a].mid>=l) add_part(lch,l,r,v);
			if(rt[a].mid<r) add_part(rch,l,r,v);
			rt[a].val=rt[lch].val+rt[rch].val;
			rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
		}
		return ;
	}
	int ask_sum(int a,int l,int r)
	{
		if(rt[a].tag) push_down(a);
		int ans=0;
		if(rt[a].l>=l&&rt[a].r<=r) return rt[a].val;
		else{
			if(rt[a].mid>=l) ans+=ask_sum(lch,l,r);
			if(rt[a].mid+1<=r) ans+=ask_sum(rch,l,r);
			return ans;
		}
	}
	int ask_maxn(int a,int l,int r)
	{
		if(rt[a].tag) push_down(a);
		int ans=0;
		if(rt[a].l>=l&&rt[a].r<=r) return rt[a].maxn;
		else{
			if(rt[a].mid>=l) ans=max(ask_maxn(lch,l,r),ans);
			if(rt[a].mid<r) ans=max(ask_maxn(rch,l,r),ans);
			return ans;
		}
	}
	
}sgt;
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n,m,x,y,k,op;
	read(n);read(m);
	for(int i=1;i<=n;i++) read(sgt.val[i]);
	sgt.Initialize(1,1,n);
	for(int i=1;i<=m;i++)
	{
		read(op);
		if(op==1)
		{
			read(x),read(y),read(k);
			sgt.add_part(1,x,y,k);
		}
		else read(x),read(y),write(sgt.ask_sum(1,x,y)),putchar('\n');
	}
//	for(int i=1;i<=n;i++) printf("%d  top%d son%d fa%d dep%d size%d\n",i,top[i],son[i],fa[i],dep[i],siz[i]);
}
