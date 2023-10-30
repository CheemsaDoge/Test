/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-30 10:39:20
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-30 11:08:29
 * @FilePath: \TEST\2023.10.30\Kamp.cpp
 * -----------Have you ever loved Why today?-----------
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
	using std::sort;using std::set;using std::vector;using std::pair;using std::make_pair;
}
namespace OI_File{
	inline void _File() {
		freopen("thisisyouriofilename.in","r",stdin);
		freopen("thisisyouriofilename.out","w",stdout);
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
int n,k;
LL f[MAXN],g[MAXN];
LL len[MAXN],slen[MAXN],olen[MAXN],siz[MAXN];
struct Edge  {
	LL w;
	int u,v,nxt;
}edge[MAXN*2];
int head[MAXN],totr;
inline void add_edge(int u,int v,LL w) {
	edge[++totr].nxt=head[u];
	head[u]=totr;
	edge[totr].w=w;
	edge[totr].u=u;
	edge[totr].v=v;
}
bool isHome[MAXN];
void dfs1(int u,int fath) {
	siz[u]=isHome[u];
	for(int i=head[u];i;i=edge[i].nxt) {
		int v=edge[i].v;if(v==fath) continue;
		dfs1(v,u);siz[u]+=siz[v];
		if(siz[v]) {
			f[u]+=f[v]+2*edge[i].w;
			LL nlen=edge[i].w+len[v];
			if(nlen>len[u]) {
				slen[u]=len[u];
				len[u]=nlen;
			} else if(nlen>slen[u]) slen[u]=nlen;
		}
	} return void ();
}
#define fath edge[pre].u
#define _w edge[pre].w
void dfs2(int u,int pre) {
	if(siz[u]==k) {
		g[u]=f[u];
		olen[u]=0;
	} else if(!siz[u]) {
		g[u]=g[fath]+_w*2;
		olen[u]=max(len[fath],olen[fath])+_w;
	} else {
		g[u]=g[fath];
		if(len[fath]-len[u]==_w) olen[u]=max(olen[fath],slen[fath])+_w;
		else olen[u]=max(olen[fath],len[fath])+_w;
	}
	for(int i=head[u];i;i=edge[i].nxt) {
		int v=edge[i].v;if(v==fath) continue;
		dfs2(v,i);
	} return void();
}
signed main() {
	// _File();
	read(n,k);
	for(int i=1;i<n;i++) {
		int tmp1,tmp2,tmp3;
		read(tmp1,tmp2,tmp3);
		add_edge(tmp1,tmp2,tmp3);
		add_edge(tmp2,tmp1,tmp3);
	}
	for(int i=1;i<=k;i++) {
		int tmp1;read(tmp1);isHome[tmp1]=1;
	}
	dfs1(1,-1);
	dfs2(1,0);
	for(int i=1;i<=n;i++) {
		write(g[i]-max(olen[i],len[i]),'\n');
	}
	return 0;
}
