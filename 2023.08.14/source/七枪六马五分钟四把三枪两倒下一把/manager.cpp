/*code by CheemsaDoge*/
#include <bits/stdc++.h>
namespace CheemsaDoge{
	template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &in) {in=getchar();while(in==' '||in=='\n') in=getchar();}
	template <typename T> inline void write(T _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
	template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
	template <typename T> inline T abs(const T _a) {return _a<0?-_a:_a;}
	template <typename T> inline void swap(T &_x,T &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename types,typename ... Args> inline void read(types &x, Args &... args) {read(x), read(args...);}
	template <typename types,typename ... Args> inline void write(types x, Args ... args) {write(x),putchar(' '),write(args...);}
	#define vector std::vector
	#define sort std::sort
}
using namespace CheemsaDoge;
const int MAXM=2e5+10;const int MAXN=2e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int siz[MAXN],son[MAXN],fa[MAXN],dep[MAXN],top[MAXN],dfn[MAXN];
struct EDGE{
	int u,v,val,nxt;
}edge[MAXM*2];
int head[MAXN],totr;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
void dfs1(int now,int fath)
{
	siz[now]=1,fa[now]=fath,son[now]=0,dep[now]=dep[fath]+1;
	for(int i=head[now];i;i=edge[i].nxt) 
	if(edge[i].v!=fath) dfs1(edge[i].v,now),siz[now]+=siz[edge[i].v],son[now]=siz[son[now]]>siz[edge[i].v]?son[now]:edge[i].v;
	return;
}
int dfs_num;
void dfs2(int now,int topx)
{
	#define u now
	dfn[now]=++dfs_num;
	top[now]=topx;
	if(son[u]!=0) dfs2(son[u],topx); else return;
	for(int i=head[u];i;i=edge[i].nxt) {
		if(edge[i].v!=fa[u]&&edge[i].v!=son[u]) {
			dfs2(edge[i].v,edge[i].v);
		}
	}
	#undef u
}
struct Segment_Tree{
	#define lch (a*2)
	#define rch (a*2+1)
	#define midd ((l+r)>>1)
	struct PRT{
		int l,r,tag,mid,length;
		int in,un;
	}rt[MAXN*4];
	void Initialize(int a,int l,int r)
	{
		rt[a].l=l;rt[a].r=r;rt[a].mid=midd;rt[a].length=(rt[a].r-rt[a].l+1);
		if(l==r) {
			rt[a].un=1;
			return ;
		}
		Initialize(lch,l,midd);
		Initialize(rch,midd+1,r);
		rt[a].un=rt[lch].un+rt[rch].un;
	}
	inline void push_down(int a)
	{
		#define v rt[a].tag
		rt[lch].tag=v;rt[rch].tag=v;
		if(v>0){
			rt[lch].in=rt[lch].length;
			rt[rch].in=rt[rch].length;
			rt[lch].un=0;rt[rch].un=0;
		}
		else if(v<0)
		{
			rt[lch].un=rt[lch].length;
			rt[rch].un=rt[rch].length;
			rt[lch].in=0;rt[rch].in=0;
		}
		rt[a].tag=0;
		#undef v
	}
	void add_part(int a,int l,int r,int v)
	{
		if(rt[a].tag!=0) push_down(a);
		if(rt[a].l>=l&&rt[a].r<=r) 
		{
			if(v>0) rt[a].tag=1,rt[a].in=rt[a].length,rt[a].un=0;
			else if(v<0) rt[a].tag=-1,rt[a].un=rt[a].length,rt[a].in=0;
			push_down(a);
		}
		else{
			if(rt[a].mid>=l) add_part(lch,l,r,v);
			if(rt[a].mid<r) add_part(rch,l,r,v);
			rt[a].in=rt[lch].in+rt[rch].in;
			rt[a].un=rt[lch].un+rt[rch].un;
		}
		return ;
	}
	int ask_installed(int a,int l,int r)
	{
		if(rt[a].tag!=0) push_down(a);
		int ans=0;
		if(rt[a].l>=l&&rt[a].r<=r) return rt[a].in;
		else{
			if(rt[a].mid>=l) ans+=ask_installed(lch,l,r);
			if(rt[a].mid+1<=r) ans+=ask_installed(rch,l,r);
			return ans;
		}
	}
	int ask_uninstalled(int a,int l,int r)
	{
		if(rt[a].tag!=0) push_down(a);
		int ans=0;
		if(rt[a].l>=l&&rt[a].r<=r) return rt[a].un;
		else{
			if(rt[a].mid>=l) ans+=ask_uninstalled(lch,l,r);
			if(rt[a].mid+1<=r) ans+=ask_uninstalled(rch,l,r);
			return ans;
		}
	}
}sgt;
int res;
inline int __install(int x,int y)//LCA(根节点,x)+change 
{
	int ans=0;
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        ans+=sgt.ask_uninstalled(1,dfn[top[x]],dfn[x]);
        sgt.add_part(1,dfn[top[x]],dfn[x],1);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    ans+=sgt.ask_uninstalled(1,dfn[x],dfn[y]);
    sgt.add_part(1,dfn[x],dfn[y],1);
    return ans;
}
int install(int x) {return __install(x+1,1);}
inline int __uninstall(int x)//子树 
{
	int ans = sgt.ask_installed(1,dfn[x],dfn[x]+siz[x]-1);
	sgt.add_part(1,dfn[x],dfn[x]+siz[x]-1,-1);
	return ans;
}
int uninstall(int x) {return __uninstall(x+1);}
char op[15];
int main() {
//	freopen("manager.in","r",stdin);
//	freopen("manager.out","w",stdout);
	int q,n,x,a;
	read(n);
	for(int i=2;i<=n;i++)
	{
		read(x);
		add_edge(1+x,i);add_edge(i,x+1);
	}
	dfs1(1,0);dfs2(1,1);
	sgt.Initialize(1,1,n);
	read(q);
	for(int i=1;i<=q;i++)
	{
		std::cin>>op;read(a);
		if(op[0]=='i') write(install(a),'\n');
		else write(uninstall(a),'\n');
	}
}
