/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template <typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
const int MAXM=6e5+10;const int MAXN=6e5+10;const int INF=2147483647ll;//2^31-1
#define int long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct part {
	int l,r,tag;
	long long maxn;
	long long val;
} rt[MAXN];
long long va[MAXN];
int n,opt,c;
#define lch a*2
#define rch a*2+1
#define slen (rt[a].r-rt[a].l+1)
#define len (r-l+1)
#define llen (rt[lch].r-rt[lch].l+1)
#define rlen (rt[rch].r-rt[rch].l+1)
#define mid (r+l)/2
#define smid (rt[a].r+rt[a].l)/2
void push_down(int a) {
	if((rt[a].maxn<=1||rt[a].tag==0)&&a!=1) return;
	if(rt[a].l==rt[a].r) {
		if(rt[a].tag>=5) {
			rt[a].val=1;rt[a].maxn=1;
			return;
		}
		for(int i=1; i<=rt[a].tag&&rt[a].val!=1; i++)rt[a].val=sqrt(rt[a].val);
		rt[a].maxn=rt[a].val;
		rt[a].tag=0;
		return;
	}
	rt[lch].tag+=rt[a].tag;rt[rch].tag+=rt[a].tag;rt[a].tag=0;
	push_down(lch);push_down(rch);
	rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
	rt[a].val=rt[lch].val+rt[rch].val;
}
void change(int a,int l,int r) {
	if(rt[a].l>=l&&rt[a].r<=r) {
		rt[a].tag+=1;
		push_down(a);
		return ;
	}
	if(smid>=l) change(lch,l,r);
	if(smid<r) change(rch,l,r);
	push_down(a);
	rt[a].val=rt[lch].val+rt[rch].val;
	rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
}
void build(int a,int l,int r) {
	rt[a].l=l,rt[a].r=r;
	if(l==r) {
		rt[a].val=va[l];rt[a].maxn=va[l];
		return ;
	}
	build(lch,l,mid);build(rch,mid+1,r);
	rt[a].val=rt[lch].val+rt[rch].val;
	rt[a].maxn=max(rt[lch].maxn,rt[rch].maxn);
}
long long query(int a,int l,int r) {
	push_down(a);
	long long ans=0;
	if(rt[a].l>=l&&rt[a].r<=r) return rt[a].val;
	if(smid<r) ans+=query(rch,l,r);
	if(smid>=l) ans+=query(lch,l,r);
	return ans;
}
int l,r;
signed main() {
	read(n);
	for(int i=1;i<=n;i++) read(va[i]);
	int m;read(m);
	build(1,1,n);
	for(int i=1;i<=m;i++) {
		read(opt);read(l);read(r);
		if(opt==2) change(1,min(l,r),max(l,r));
		else if(opt==1) write(query(1,min(l,r),max(l,r))),pc;
	}
}
