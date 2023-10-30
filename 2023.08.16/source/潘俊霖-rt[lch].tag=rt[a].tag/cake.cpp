/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=9e5+1145;const int MAXN=7e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("no")
/*---------------------------------pre------------------------------------*/
int siz[MAXN],son[MAXN],fa[MAXN],dep[MAXN],top[MAXN],dfn[MAXN],n;
struct EDGE{
	int u,v,val,nxt;
}edge[MAXM];
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
	for(int i=head[now];i;i=edge[i].nxt) if(edge[i].v!=fath) dfs1(edge[i].v,now),siz[now]+=siz[edge[i].v],son[now]=siz[son[now]]>siz[edge[i].v]?son[now]:edge[i].v;
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
		int val;
	}rt[MAXN*3];
	void Initialize(int a,int l,int r)
	{
		rt[a].val=0;
		rt[a].l=l;rt[a].r=r;rt[a].mid=midd;rt[a].length=(rt[a].r-rt[a].l+1);
		if(l==r) {
			return ;
		}
		Initialize(lch,l,midd);
		Initialize(rch,midd+1,r);
//		rt[a].un=rt[lch].un+rt[rch].un;
	}
	inline void push_down(int a)
	{
		#define v rt[a].tag
		rt[lch].tag+=v;rt[rch].tag+=v;
		rt[lch].val+=v*rt[lch].length;
		rt[rch].val+=v*rt[rch].length;
		rt[a].tag=0;
		#undef v
	}
	void add_part(int a,int l,int r,int v)
	{
		if(rt[a].tag!=0) push_down(a);
		if(rt[a].l>=l&&rt[a].r<=r) 
		{
			rt[a].val+=rt[a].length*v;
			rt[a].tag+=v;
			push_down(a);
		}
		else{
			if(rt[a].mid>=l) add_part(lch,l,r,v);
			if(rt[a].mid<r) add_part(rch,l,r,v);
			rt[a].val=rt[lch].val+rt[rch].val;
		}
		return ;
	}
	void pushdown_zhongjiban(int a)
	{
		if(rt[a].l==rt[a].r) return;
		push_down(a);
		pushdown_zhongjiban(lch);
		pushdown_zhongjiban(rch);
	}
	int get_point(int a,int t)
	{
		if(rt[a].l==rt[a].r) return rt[a].val;
		if(rt[a].mid>=t) return get_point(lch,t);
		else return get_point(rch,t);
	}
}sgt;
inline void add(int x,int y)//
{
    while(top[x]!=top[y]){
        if(dep[top[x]]<dep[top[y]])swap(x,y);
        sgt.add_part(1,dfn[top[x]],dfn[x],1);
        x=fa[top[x]];
    }
    if(dep[x]>dep[y])swap(x,y);
    sgt.add_part(1,dfn[x],dfn[y],1);
}
int a[MAXN];
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("cake.in","r",stdin);
	freopen("cake.out","w",stdout);
	int u,v;
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<n;i++) read(u),read(v),add_edge(u,v),add_edge(v,u);
	dfs1(a[1],-1);dfs2(a[1],a[1]);
	sgt.Initialize(1,1,n);
//	for(int i=0;i<=n;i++) printf("%d dfn%d un ask\n",i,dfn[i]);

	for(int i=1;i<n;i++){
		add(a[i],a[i+1]);
	}
	sgt.pushdown_zhongjiban(1);
	for(int i=1;i<=n;i++) 
	{
		if(a[1]==i) write(sgt.get_point(1,dfn[i])),pc;
		else write(sgt.get_point(1,dfn[i])-1),pc;
	}
}
