/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template <>void read <char>(char &in) {in=getchar();while(in==' '||in=='\n') in=getchar();}
template <typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
template <typename T> inline T abs(const T _a) {return _a<0?-_a:_a;}
template <typename T> inline void swap(T &_x,T &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
template <typename types,typename ... Args> inline void read(types &x, Args &... args) {read(x), read(args...);}
const int MAXM=3e5+10;const int MAXN=3e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int siz[MAXN],son[MAXN],fa[MAXN],dep[MAXN],top[MAXN],dfn[MAXN],pre[MAXN];
int add[MAXN];
struct EDGE {
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr;
void add_edge(int u,int v) {
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
void dfs1(int now,int fath) {
	siz[now]=1,fa[now]=fath,son[now]=0,dep[now]=dep[fath]+1;
	for(int i=head[now];i;i=edge[i].nxt)
		if(edge[i].v!=fath) 
			dfs1(edge[i].v,now),siz[now]+=siz[edge[i].v],son[now]=siz[son[now]]>siz[edge[i].v]?son[now]:edge[i].v;
	return;
}
int dfs_num;
void dfs2(int now,int topx) {
	#define u now
	dfn[now]=++dfs_num;
	pre[dfs_num]=now;
	top[now]=topx;
	if(son[u]) dfs2(son[u],topx); else return;
	for(int i=head[u];i;i=edge[i].nxt) {
		if(edge[i].v!=fa[u]&&edge[i].v!=son[u]) {
			dfs2(edge[i].v,edge[i].v);
		}
	}
	#undef u
}
int LCA(int a,int b) {
	while(1) {
		if(top[a]==top[b]) return dep[a]<dep[b]?a:b;
		if(dep[top[a]]<dep[top[b]]) swap(a,b);
		a=fa[top[a]];
	}
}
int W[MAXN],C[MAXN];
char op[3];
int main() {
	int n,q,x,y;
	read(n,q);
	for(int i=1;i<=n;i++) read(W[i]),read(C[i]);
	for(int i=1;i<n;i++) {
		read(x,y);
		add_edge(x,y);add_edge(y,x);
	}
	dfs1(1,0);dfs2(1,1);
	int ans1=0,ans2=0;
	for(int i=1;i<=q;i++) {
		ans1=ans2=0;
		read(op[0],op[1],x,y);
		if(op[0]=='Q') {
			if(op[1]=='S') {
				int z=LCA(x,y);
				int col=C[x];
				while(x!=z) {
					ans1+=C[x]==col?W[x]:0;
					x=fa[x];
				}
				while(y!=z) {
					ans2+=C[y]==col?W[y]:0;
					y=fa[y];
				}
				write(ans1+ans2+W[z]);pc;
			}else {
				ans1=0;
				int z=LCA(x,y);
				int col=C[x];
				while(x!=z) {
					ans1=max(C[x]==col?W[x]:0,ans1);
					x=fa[x];
				}
				while(y!=z) {
					ans1=max(C[y]==col?W[y]:0,ans1);
					y=fa[y];
				}
				ans1=max(ans1,W[z]);
				write(ans1);pc;
			}
		}
		else if(op[0]=='C') {
			if(op[1]=='C') {
				C[x]=y;
			}
			else {
				W[x]=y;
			}
		}
	}
	
	return 0;
}
