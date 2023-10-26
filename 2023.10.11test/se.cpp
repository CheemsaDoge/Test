/*code by CheemsaDoge*/
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-finline")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-fno-stack-protector")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("abm")
#pragma GCC target("avx")
#pragma GCC target("mmx")
#pragma GCC target("popcnt")
#pragma GCC target("sse")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("sse4")
#pragma GCC target("ssse3")
#pragma GCC target("tune=native")
namespace CheemsaDoge {
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 _mod) {long long ans=1;_a%=_mod;while(_n) {if(_n&1) ans=ans*_a%_mod;_n>>=1;_a=_a*_a%_mod;}return ans;}
	using std::sort;
	using std::set;
	using std::vector;
	using std::pair;
}
namespace OI_File{
	inline void _File() {
		freopen("se.in","r",stdin);
		freopen("se.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e5;
/*---------------------------------pre------------------------------------*/
vector<int>e[MAXN];
int siz[MAXN],dep[MAXN],fa[MAXN],son[MAXN],top[MAXN],dfn[MAXN],dfs_num,Lc,Rc;
int col[MAXN],rid[MAXN];
void dfs1(int u,int ft) {
	siz[u]=1;dep[u]=dep[ft]+1;fa[u]=ft;
	for(auto v:e[u]) if(v!=ft) dfs1(v,u),siz[u]+=siz[v],son[u]=siz[v]>siz[son[u]]?v:son[u];
	return void();
}
void dfs2(int u,int topx) {
	dfn[u]=++dfs_num;rid[dfs_num]=u;top[u]=topx;
	if(son[u]!=0) dfs2(son[u],topx); else return ;
	for(auto v:e[u]) if(v!=son[u]&&v!=fa[u]) dfs2(v,v);
	return void();
}
#define lch (a<<1)
#define rch (a<<1|1)
struct PART {int l,r,lc,rc,val,tag;}rt[MAXN*4];
inline void push_up(int a) {
	rt[a].val=rt[lch].val+rt[rch].val;
	if(rt[lch].rc==rt[rch].lc) rt[a].val--;
	rt[a].lc=rt[lch].lc;rt[a].rc=rt[rch].rc;
}
void build(int a,int l,int r) {
	rt[a].l=l;rt[a].r=r;
	rt[a].lc=col[rid[l]];rt[a].rc=col[rid[r]];
	if(l==r) return rt[a].val=1,void();
	int mid=(l+r)>>1;
	build(lch,l,mid);
	build(rch,mid+1,r);
	push_up(a);
	return void();
}
inline void push_down(int a) {
	if(!rt[a].tag) return void();
	rt[lch].tag=rt[rch].tag=rt[a].tag;
	rt[lch].lc=rt[lch].rc=rt[rch].lc=rt[rch].rc=rt[a].tag;
	rt[lch].val=rt[rch].val=1;
	rt[a].tag=0;
	return void();
}
void __change(int a,int l,int r,int c) {
	if(rt[a].tag) push_down(a);
	if(rt[a].l>=l&&rt[a].r<=r) {
		rt[a].val=1;rt[a].lc=rt[a].rc=c;rt[a].tag=c;
		push_down(a);
		return void();	
	}
	int mid=(rt[a].l+rt[a].r)>>1;
	if(mid+1<=r) __change(rch,l,r,c); 
	if(mid>=l) __change(lch,l,r,c);
	push_up(a);
}
inline void change(int l,int r,int c) {
	while(top[l]!=top[r]) {
		if(dep[top[l]]<dep[top[r]]) swap(l,r);
		__change(1,dfn[top[l]],dfn[l],c);
		l=fa[top[l]];
	}
	if(dfn[l]>dfn[r]) swap(l,r);
	__change(1,dfn[l],dfn[r],c);
}
int query(int a,int L,int R) {
    int l=rt[a].l,r=rt[a].r;	
    if(L<=l&&r<=R) {
    	if(l==L) Lc=rt[a].lc;
    	if(r==R) Rc=rt[a].rc;      
    	return rt[a].val;  
    }
    push_down(a);
    int mid=(l+r)>>1;
    if(R<=mid) return query(lch,L,R);
    if(L>mid)  return query(rch,L,R);
    int ret=query(lch,L,R)+query(rch,L,R);
    if(rt[lch].rc==rt[rch].lc) --ret;
    return ret; 
}
inline int ask(int u,int v) {
    int ret=0;
    int pos1=0,pos2=0;
    while(top[u]!=top[v]) {
        if(dep[top[u]]<dep[top[v]]) swap(u,v),swap(pos1,pos2);		
        ret+=query(1,dfn[top[u]],dfn[u]);
        if(Rc==pos1) --ret;
        pos1=Lc,u=fa[top[u]];
    }
    if(dfn[u]>dfn[v]) swap(u,v),swap(pos1,pos2);
    ret+=query(1,dfn[u],dfn[v]);
    if(Lc==pos1) --ret;
    if(Rc==pos2) --ret; 
    return ret;
}
int n,m;
signed main() {
//	_File();
	read(n,m);
    for(int i=1;i<=n;++i) read(col[i]);
    for(int u,v,i=1;i<n;++i) read(u,v),e[u].push_back(v),e[v].push_back(u);
    dfs1(1,0);dfs2(1,1);build(1,1,n);
    for(int a,b,c,i=1;i<=m;++i) {
        int ch=getchar();
        while(ch!='C'&&ch!='Q') ch=getchar();
        if(ch=='C') read(a,b,c),change(a,b,c);
        if(ch=='Q') read(a,b),write(ask(a,b),'\n');
    }
	return 0;
}

