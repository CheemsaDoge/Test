#include<bits/stdc++.h>
namespace CheemsaDoge {
	typedef long long LL;
	template <typename type1,typename type2> inline type1 min(const type1 _a,const type2 _b) {return _a>_b?_b:_a;}
	template <typename type1,typename type2> inline type1 max(const type1 _a,const type2 _b) {return _a>_b?_a:_b;}
	template <typename types,typename ... args> inline types min(const types _a,const args ... more) {return min(_a,more...);}
	template <typename types,typename ... args> inline types max(const types _a,const args ... more) {return max(_a,more...);}
	template <typename type1,typename type2> inline void __getmin(type1 &_a,const type2 _b) {_a=min(_a,_b);}
	template <typename type1,typename type2> inline void __getmax(type1 &_a,const type2 _b) {_a=max(_a,_b);}
	template <typename types,typename ... args> inline void __getmin(types &_a,const args ... _b) {_a=getmin(_a,_b...);}
	template <typename types,typename ... args> inline void __getmax(types &_a,const args ... _b) {_a=getmax(_a,_b...);}
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
/** @brief 计算某数的多次方对mod取模后的答案 
  * @description: 计算某数的多次方对mod取模后的答案
  * @param {type1} _a 底数(返回值类型以此为主)
  * @param {type2} _n 次数
  * @param {type3} __mod 模数(不填则默认为2,305,843,009,213,693,952(2^61))
  * @return {*} _a的_n次方对__mod取模(类型以底数类型为准)
  */
 	template <typename type1,typename type2> type1 pow(type1 _a,type2 _n,LL __mod=2305843009213693952ll) {type1 _ans=1;_a%=__mod;while(_n) {if(_n&1) _ans=_ans*_a%__mod;_n>>=1;_a=_a*_a%__mod;}return _ans;}
	template <typename type1> inline type1 __gcd(type1 _a,type1 _b) {if(!_a||!_b) return _a==0?_b:_a;type1 az=__builtin_ctz(_a),bz=__builtin_ctz(_b);type1 z=min(az,bz),dif;_b>>=bz;while(_a) {_a>>=az;dif=_b-_a;az=__builtin_ctz(dif);if(_a<_b) _b=_a;_a=dif<0?-dif:dif;}return _b<<z;}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	using std::sort;using std::set;using std::vector;using std::pair;using std::make_pair;
} using namespace CheemsaDoge;
const int MAXN=300;const int MOD=998244353;
namespace Graph {
    struct Edge {
        int u,v,nxt;
        LL w;
    }edge[20000];
    int head[MAXN],totr=1;
    inline void add_edge(int u,int v,LL w) {
        edge[++totr].nxt=head[u];
        head[u]=totr;
        edge[totr].u=u;
        edge[totr].v=v;
        edge[totr].w=w;
    }
} using namespace Graph;
const int INF=2e9+5;
/*EK*/ 
namespace EK {
	LL ans;
	int n,m,s,t,pre[MAXN];
	LL dis[MAXN];
	bool vis[MAXN];
	bool bfs() {
		memset(vis,false,sizeof(vis));
		std::queue<int>que;
		que.push(s);
		dis[s]=INF;vis[s]=true;
		while(!que.empty()) {
			int u=que.front();que.pop();
			for(int i=head[u];i;i=edge[i].nxt) {
				int v=edge[i].v;
				if(vis[v]||!edge[i].w) continue;
				pre[v]=i;
				vis[v]=true;que.push(v);
				dis[v]=min(dis[u],edge[i].w);
				if(v==t) return true;
			}
		}
		return false;
	}
	inline void update() {
		int u=t;
		while(u!=s) {
			int i=pre[u];
			edge[i].w-=dis[t];
			edge[i^1].w+=dis[t];
			u=edge[i].u;
		} return ans+=dis[t],void();
	}
	inline void calc() {while(bfs()) update();}
	LL ve[300][330];
	signed main() {
		// _File();
		read(n,m,s,t);
		for(int i=1;i<=m;i++) {
			int tmp1,tmp2;LL tmp3;read(tmp1,tmp2,tmp3);
			ve[tmp1][tmp2]+=tmp3;
			// ve[tmp2][tmp1]+=tmp3;
			// add_edge(tmp1,tmp2,tmp3);
			// add_edge(tmp2,tmp1,tmp3);
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) 
			if(ve[i][j]) {
				add_edge(i,j,ve[i][j]);
				add_edge(j,i,0);
			}
		calc();
		write(ans);
		return 0;
	}
}
namespace Dinic {
	int s,t,n,m,now[MAXN];
	LL dis[MAXN];
	bool bfs() {
		for(int i=1;i<=n;i++) dis[i]=1145141919810ll;
		std::queue<int>que;
		que.push(s);dis[s]=0;now[s]=head[s];
		while(!que.empty()) {
			int u=que.front();que.pop();
			for(int i=head[u];i;i=edge[i].nxt) {
				int v=edge[i].v;
				if(dis[v]!=1145141919810ll||!edge[i].w) continue;
				dis[v]=dis[u]+1;
				que.push(v);now[v]=head[v];
				if(v==t) return true;
			}
		}
		return false;
	}
	LL dfs(int u,LL lst=2e18+7) {
		if(u==t) return lst;
		LL k,res=0;
		for(int i=now[u];i;i=edge[i].nxt) {
			now[u]=i;
			int v=edge[i].v;
			if(dis[v]!=dis[u]+1||!edge[i].w) continue;
			k=dfs(v,min(lst,edge[i].w));
			if(!k) dis[v]=INF;
			edge[i].w-=k;edge[i^1].w+=k;
			res+=k;lst-=k;
		} return res;
	}
	LL calc() {LL ans=0;while(bfs()) ans+=dfs(s); return ans;}
	LL ve[300][330];
	signed main() {
		// _File();
		read(n,m,s,t);
		for(int i=1;i<=m;i++) {
			int tmp1,tmp2;LL tmp3;read(tmp1,tmp2,tmp3);
			ve[tmp1][tmp2]+=tmp3;
		}
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) 
			if(ve[i][j]) {
				add_edge(i,j,ve[i][j]);
				add_edge(j,i,0);
			}
		write(calc());
		return 0;
	}
}
int main() {
	Dinic::main();
}