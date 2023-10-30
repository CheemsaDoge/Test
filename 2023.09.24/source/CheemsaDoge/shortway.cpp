/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template<typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template<typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=3e6+10;const int MAXN=1e6+10;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
void _File() {
	freopen("shortway.in","r",stdin);
	freopen("shortway.out","w",stdout);
}
struct Edge{
	int u,v,nxt;
	int val;
}e[MAXM],f[MAXM];
int head[MAXN],totr;
int headf[MAXN],ftotr;
inline void add_edge(int u,int v,int val) {
	e[++totr].nxt=head[u];
	e[totr].u=u;
	e[totr].v=v;
	e[totr].val=val;
	head[u]=totr;
}
inline void fadd_edge(int u,int v,int val) {
	f[++ftotr].nxt=headf[u];
	f[ftotr].u=u;
	f[ftotr].v=v;
	f[ftotr].val=val;
	headf[u]=ftotr;
}
int n,m;
std::vector<std::tuple<int, int,std::string>> E;
int nc;
inline void make_graph() {
	for(auto p:E) {
		int u=std::get<0>(p);
		int v=std::get<1>(p);
		std::string w=std::get<2>(p);
		int lst=u;
		for(int i=0;i<(int)w.length();i++) {
			int x=u,y=v;
			if(i!=0) x=lst;
			if(i!=(int)w.length()-1) y=lst=++nc;
			add_edge(x,y,int(w[i]));
			fadd_edge(y,x,int(w[i]));
		}
	}
}
int dis1[MAXN],disn[MAXN];
void solve_dis1(int s) {
	std::queue<int> q;
	std::fill(dis1+1,dis1+1+nc,0x3f3f3f3f);
	dis1[s] = 0;q.push(s);
	while (!q.empty()) {
		int u = q.front();q.pop();
		for (int i=head[u];i;i=e[i].nxt) {
			int v=e[i].v;
			if (dis1[v]>dis1[u]+1) {
				dis1[v]=dis1[u]+1;
				q.push(v);
			}
		}
	}
	return;
}
void solve_disn(int s) {
	std::queue<int> q;
	std::fill(disn+1,disn+1+nc,0x3f3f3f3f);
	disn[s] = 0;q.push(s);
	while (!q.empty()) {
		int u=q.front();q.pop();
		for (int i=headf[u];i;i=f[i].nxt) {
			int v=f[i].v;
			if(disn[v]>disn[u]+1) {
				disn[v]=disn[u]+1;
				q.push(v);
			}
		}
	}
	return;
}
bool vis[MAXN];
std::string bfs(bool min_dis) {
	std::vector<int>now,nxt;
	std::string ans;
	std::fill(vis,vis+MAXN,false);
	now.push_back(1);
	while(true) {
		int mn=255;
		for(auto u : now) 
		{
			for(int i=head[u];i;i=e[i].nxt) {
				int v=e[i].v;
				if(min_dis) if(((int)ans.length()+disn[v])+1>dis1[n]) continue;
				if(!min_dis) if(disn[v]>=0x3f3f3f3f) continue;
				if(e[i].val<mn) {
					for(auto x : nxt) vis[x]=false; nxt.clear();
					mn=e[i].val;vis[v]=true;nxt.emplace_back(v);
				}
				else if(e[i].val==mn) if(!vis[v]) vis[v]=true,nxt.emplace_back(v);
			}
		}
		ans+=mn;
		if(vis[n]) break;
		for(auto x : nxt) vis[x]=false;
		now.swap(nxt);
		nxt.clear();
	}
	return ans;
}
int main()
{
	_File();
	read(n);read(m);
	for(int i=1;i<=m;i++) {
		int u,v;
		std::string tmp;
		read(u);read(v);std::cin>>tmp;
		E.emplace_back(u,v,tmp);
	}
	nc=n;
	make_graph();
	solve_dis1(1);solve_disn(n);
	std::cout<<bfs(true)<<" "<<bfs(false)<<std::endl;
	return 0;
}
/*
4 6
1 2 aa
1 3 b
1 4 c
2 3 d
2 4 dd
3 4 c
*/

