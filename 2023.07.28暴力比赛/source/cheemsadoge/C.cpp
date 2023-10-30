#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+1145;
template<typename T> inline void read(T &x) {
	x=0;T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;
}
struct part {
	int l,r,val,tag,maxn;
} rt[MAXN*2];
int va[MAXN],n,opt,c;
#define lch a*2
#define rch a*2+1
#define slen (rt[a].r-rt[a].l+1)
#define len (r-l+1)
#define llen (rt[lch].r-rt[lch].l+1)
#define rlen (rt[rch].r-rt[rch].l+1)
#define mid (r+l)/2
#define smid (rt[a].r+rt[a].l)/2
void push_down(int a) {
	if((rt[a].maxn==1||rt[a].tag==0)&&a!=1) return;
	if(rt[a].l==rt[a].r) {
		if(rt[a].tag>=5) {
			rt[a].val=1;rt[a].maxn=1;
			return;
		}
		for(int i=1; i<=rt[a].tag; i++)rt[a].val=sqrt(rt[a].val);
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
int main() {
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	read(n);for(int i=1; i<=n; i++) read(va[i]);build(1,1,n);
	for(int i=1; i<=n; i++) {
		read(opt);read(l);read(r);read(c);
		if(opt==0) change(1,l,r);
		else printf("%lld\n",query(1,l,r));
	}
}
