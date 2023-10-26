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
		freopen("war.in","r",stdin);
		freopen("war.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e5;
/*---------------------------------pre------------------------------------*/
#define rep(i,a,b) for(register int i=a;i<=b;i++)
#define per(i,b,a) for(register int i=b;i>=a;i--)
typedef long long ll;
int n,tot,m,dfn[250010],t,a[500010],_top,s[250010];
int head[250010],fa[250010],top[250010],d[250010],sz[250010],son[250010],k;
ll mn[250010];
struct node{
	int to,nt,w;
}edge[500010];
inline void add(int u,int v,int w){
	edge[++k].nt=head[u];head[u]=k;
	edge[k].to=v;edge[k].w=w;
}
inline void dfs1(int u,int f){
	fa[u]=f;sz[u]=1;d[u]=d[f]+1;
	for(int i=head[u];i;i=edge[i].nt){
		int v=edge[i].to;
		if(v==f) continue;
		mn[v]=min(mn[u],ll(edge[i].w));
		dfs1(v,u);sz[u]+=sz[v];
		if(!son[u]||sz[v]>sz[son[u]]) son[u]=v;
	}
}
inline void dfs2(int u,int tp){
	top[u]=tp;dfn[u]=++tot;
	if(!son[u]) return ; dfs2(son[u],tp);
	for(register int i=head[u];i;i=edge[i].nt){
		int v=edge[i].to;
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
inline int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(d[top[x]]<d[top[y]]) x^=y^=x^=y;
		x=fa[top[x]];
	}
	return d[x]>d[y]?y:x;
}
vector<int> v[250010];
inline void add(int x,int y) {v[x].push_back(y);}
inline void ins(int x) {
    if(_top == 1) {s[++_top] = x; return ;}
    int lca = LCA(x, s[_top]);
    if(lca == s[_top]) return ;
    while(_top > 1 && dfn[s[_top - 1]] >= dfn[lca]) add(s[_top - 1], s[_top]), _top--;
    if(lca != s[_top]) add(lca, s[_top]), s[_top] = lca;
    s[++_top] = x;
}
inline ll pr(int x){
	ll ans=0;
	if(v[x].size()==0) return mn[x];
	for(register int i=0;i<(int)v[x].size();i++) ans+=pr(v[x][i]);
	v[x].clear();
	return min(ans,mn[x]);
}
inline bool cmp(int _a,int _b){
	return dfn[_a]<dfn[_b];
}
signed main() {
//	_File();
	read(n);
	memset(mn,0x3f,sizeof(mn));
	int _u,_v,w;
	rep(i,1,n-1) read(_u,_v,w),add(_u,_v,w),add(_v,_u,w);
	dfs1(1,0);dfs2(1,1);
	read(m);while(m--) {
        int K=0;read(k);
        for(int i=1;i<=K;i++) read(a[i]);
        sort(a+1,a+K+1,cmp);
        s[_top=1]=1;
        for(int i=1;i<=K;i++) ins(a[i]);
        while(_top>0) add(s[_top-1],s[_top]),_top--;
		write(pr(1),'\n');
    }
    return 0;
}
