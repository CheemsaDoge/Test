/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-22 16:53:05
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-26 21:20:10
 * @FilePath: \TEST\2023.10.26\fish.cpp
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
		freopen("fish.in","r",stdin);
		freopen("fish.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
#undef std
using namespace OI_File;
typedef long long LL;
// typedef __int128_t int128;
/*---------------------------------pre------------------------------------*/
#define int LL
LL n,m;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
namespace subtask1 {
	struct sub1 {
		int val,x,y;
		bool operator <(const sub1&b) const {return val>b.val;}
	};
	const int MAXN=100;
	int a[MAXN][MAXN];
	bool vis[MAXN][MAXN];
	signed main() {
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++) {
				std::priority_queue<sub1>que;
				std::stack<pair<int,int> >sta;
				for(int k=0;k<=3;k++) {
					int nx=i+dx[k];
					int ny=j+dy[k];
					if(vis[nx][ny]) continue;
					if(nx>n||ny>m||nx<=0||ny<=0) continue;
					que.push((sub1){a[nx][ny],nx,ny});
					vis[nx][ny]=true;
					sta.push(make_pair(nx,ny));
				}
				int tot=a[i][j];
				vis[i][j]=1;sta.push(make_pair(i,j));
				while(!que.empty()) {
					sub1 u=que.top();que.pop();
					if(tot>=u.val) {
						tot+=u.val;
						for(int k=0;k<=3;k++) {
							int nx=u.x+dx[k];
							int ny=u.y+dy[k];
							if(vis[nx][ny]) continue;
							if(nx>n||ny>m||nx<=0||ny<=0) continue;
							que.push((sub1){a[nx][ny],nx,ny});
							vis[nx][ny]=true;
							sta.push(make_pair(nx,ny));
						}
					} else break;
				}
				write(tot);write(' ');
				while(!sta.empty()) {
					vis[sta.top().first][sta.top().second]=false;
					sta.pop();
				} 
			}
			write('\n');
		}
		return 0;
	}
}
namespace subtask2 {
	#define ilovewhy false
	#define ihatewhy true
	const int MAXM=1145;const int MAXN=1919;const LL INF=2e18;
	LL a[MAXN*MAXM],fa[MAXN*MAXM],sum[MAXN*MAXM],id[MAXN*MAXM],tmp;
	vector<int>e[MAXN*MAXM];
	int find(int u) {return u==fa[u]?fa[u]:fa[u]=find(fa[u]);}
 /**
  * @brief 并查集合并
  * @description: 并查集合并,以 u 为父亲,以 v 为儿子
  * @param {int} u 可能的父亲
  * @param {int} v 可能的儿子
  * @return {*} void()
  */
	void merge(int u,int v) {
		if(a[u]<a[v]) return void();
		if((u=find(u))==(v=find(v))) return void();
		fa[v]=u;
		sum[u]+=sum[v];
		return e[u].emplace_back(v),void();
	}
/// @description: 检查是否超出边界 *
/// @return {*} 是否未超出边界     
	inline bool check(int u) {return ((u>=1)&&(u<=n*m));}
	inline bool cmpA(int u,int v) {return a[u]<a[v];}
	void dfs(int u,LL ans,LL maxx) {
		if(sum[u]>=maxx) sum[u]=ans;
		for(int v:e[u]) dfs(v,sum[u],a[u]);
	}
	signed main() {
		for(int i=1;i<=n*m;i++) {
			read(a[i]);sum[i]=a[i];
			fa[i]=id[i]=i;
		}
		sort(id+1,id+1+n*m,cmpA);
		for(int i=1;i<=n*m;i++) {
			if(check(tmp=id[i]+m)) merge(id[i],tmp);
			if(check(tmp=id[i]-m)) merge(id[i],tmp);
			if(id[i]%m!=0&&check(tmp=id[i]+1)) merge(id[i],tmp);
			if(id[i]%m!=1&&check(tmp=id[i]-1)) merge(id[i],tmp);
		}
		for(int i=1;i<=n*m;i++) if(fa[i]==i) dfs(i,0,INF);
		for(int i=1;i<=n*m;i++) {
			write(sum[i]);if(!(i%m)) write('\n'); else write(' ');
		}
	 /**
	  * @brief 返回我是否爱why
	  * @description: 0
	  * @return {*} 假
	  */
		return ilovewhy;
	}
}
signed main() {
	// _File();
	read(n,m);
	// if(n<=50&&m<=50) return subtask1::main();
	// else 
	return subtask2::main();
	return 0;
}
