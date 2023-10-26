/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-22 16:53:05
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-26 16:46:39
 * @FilePath: \TEST\2023.10.26\handbook.cpp
 * Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
namespace CheemsaDoge {
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 __mod) {long long _ans=1;_a%=__mod;while(_n) {if(_n&1) _ans=_ans*_a%__mod;_n>>=1;_a=_a*_a%__mod;}return _ans;}
	template <typename type1> inline type1 __gcd(type1 _a,type1 _b) {if(!_a||!_b) return _a==0?_b:_a;type1 az=__builtin_ctz(_a),bz=__builtin_ctz(_b);type1 z=min(az,bz),dif;_b>>=bz;while(_a) {_a>>=az;dif=_b-_a;az=__builtin_ctz(dif);if(_a<_b) _b=_a;_a=dif<0?-dif:dif;}return _b<<z;}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	using std::sort;using std::set;using std::vector;using std::pair;
}
namespace OI_File{
	inline void _File() {
		freopen("handbook.in","r",stdin);
		freopen("handbook.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
#undef std
using namespace OI_File;
typedef long long LL;
// typedef __int128_t int128;
const int MAXN=6e5;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
int n,k,q;
int a[MAXN];
struct EDGE{
	int u,v,w,nxt;
}edge[MAXN*3];
int head[MAXN],totr;
void add_edge(int u,int v,int w) {
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	edge[totr].w=w;
	head[u]=totr;
}
namespace tree {
	int siz[MAXN],son[MAXN],fa[MAXN],dep[MAXN],top[MAXN],dfn[MAXN],pre[MAXN];
	int add[MAXN];
	void dfs1(int now,int fath) {
		siz[now]=1,fa[now]=fath,son[now]=0,dep[now]=dep[fath]+1;
		for(int i=head[now];i;i=edge[i].nxt) if(edge[i].v!=fath) dfs1(edge[i].v,now),siz[now]+=siz[edge[i].v],son[now]=siz[son[now]]>siz[edge[i].v]?son[now]:edge[i].v;
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
	int LCA(int _a,int _b) {
		while(1) {
			if(top[_a]==top[_b]) return dep[_a]<dep[_b]?_a:_b;
			if(dep[top[_a]]<dep[top[_b]]) swap(_a,_b);
			_a=fa[top[_a]];
		}
	}
}
namespace subtask3 {
	int dp[MAXN][10];int dep[MAXN];
	int pos[MAXN][10];
	void dynamic_houmianwangle (int u,int fath) {
		for(int i=1;i<=k;i++) dp[u][i]=0x3f3f3f3f;
		dp[u][a[u]]=0;pos[u][a[u]]=u;
		// write('s',u,a[u],'s','\n');
		for(int i=head[u];i;i=edge[i].nxt) {
			int v=edge[i].v;if(v==fath) continue;
			dynamic_houmianwangle(v,u);
			for(int j=1;j<=k;j++) if(dp[u][j]>dp[v][j]+edge[i].w) dp[u][j]=min(dp[u][j],dp[v][j]+edge[i].w),pos[u][j]=pos[v][j];
		} return void();
	}
	void qianmianwangle(int u,int fath,int val,int deep) {
		if(fath!=-1) for(int j=1;j<=k;j++) if(dp[u][j]>dp[fath][j]+val) dp[u][j]=min(dp[u][j],dp[fath][j]+val),pos[u][j]=pos[fath][j];
		for(int i=head[u];i;i=edge[i].nxt) {
			int v=edge[i].v;if(v==fath) continue;
			qianmianwangle(v,u,edge[i].w,deep+edge[i].w);
		} return dep[u]=deep,void();
	}
	signed main() {
		dynamic_houmianwangle(1,0);
		qianmianwangle(1,-1,0,0);
		for(int __qwq_=1;__qwq_<=q;__qwq_++) {
			int tmp1,tmp2;read(tmp1,tmp2);
			int lca=tree::LCA(tmp1,tmp2);
			// write('s',lca,'s','\n');
			int minn[10];memset(minn,0x3f,sizeof(minn));
			#define why 0
			LL ans=why+dep[tmp1]+dep[tmp2]-2*dep[lca];
			while(tmp1!=lca) {
				for(int i=1;i<=k;i++) if(minn[i]>=dp[tmp1][i]) {
					// int t=pos[tmp1][i];
					minn[i]=min(minn[i],dp[tmp1][i]);
					// for(int q=1;q<=k;q++) minn[q]=min(minn[q],dp[t][q]);
				}
				tmp1=tree::fa[tmp1];
			}
			while(tmp2!=lca) {
				for(int i=1;i<=k;i++) if(minn[i]>=dp[tmp2][i]) {
					// int t=pos[tmp2][i];
					minn[i]=min(minn[i],dp[tmp2][i]);
					// for(int q=1;q<=k;q++) minn[q]=min(minn[q],dp[t][q]);
				}
				tmp2=tree::fa[tmp2];
			}
			for(int i=1;i<=k;i++) minn[i]=min(minn[i],dp[lca][i]);
			for(int i=1;i<=k;i++) ans+=minn[i]*2;
			write(ans,'\n');
		}
		return 0;
	}
}
signed main() {
	_File();
	read(n,k,q);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<n;i++) {
		int tmp1,tmp2,tmp3;read(tmp1,tmp2,tmp3);
		add_edge(tmp1,tmp2,tmp3);add_edge(tmp2,tmp1,tmp3);
	}
	tree::dfs1(1,0);tree::dfs2(1,1);
	return subtask3::main();
	return 0;
}

/*
5 3 3
1 2 3 2 3
1 2 3
2 3 1
2 4 5
4 5 6
1 3
1 4
2 4
*/