/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=5e5+10;const int MAXN=2e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("NO")
#define py puts("YES")
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr=1;
void add_edge(int u,int v,int val=1) {
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n,m,t,dan;
int rd[MAXN],cd[MAXN];
bool vis[MAXM];
bool in_stack[MAXN];
struct node {
	int x,num;
};
void solve1() {
	std::stack<node>sta;
	sta.push((node){1,0});
	vis[0]=true;
	while(!sta.empty()) {
		int u=sta.top().x;
		int e=sta.top().num;
		if(!vis[e]) {
			vis[e^1]=true;
			vis[e]=true;
			write(e/2*edge[e].val*-1);pk;
		}
		int i=head[u];
		while(i&&in_stack[i]) i=edge[i].nxt;
		if(i) {
			sta.push((node){edge[i].v,i});
			head[u]=edge[i].nxt;
			in_stack[i]=true;
			in_stack[i^1]=true;
		}
		else sta.pop();
	}
}
void solve2() {
	std::stack<node>sta;
	sta.push((node){1,0});
	vis[0]=true;
	while(!sta.empty()) {
		int u=sta.top().x;
		int e=sta.top().num;
		if(!vis[e]) {
			vis[e]=true;
			write(e-1);pk;
		}
		int i=head[u];
		while(i&&in_stack[i]) i=edge[i].nxt;
		if(i) {
			sta.push((node){edge[i].v,i});
			head[u]=edge[i].nxt;
			in_stack[i]=true;
		}
		else sta.pop();
	}
}
int main()
{
	read(t);
	read(n);read(m);
	for(int i=1;i<=m;i++) {
		int u,v;
		read(u);read(v);
		add_edge(u,v);
		rd[v]++;cd[u]++;
		if(t==1) rd[u]++,add_edge(v,u,-1);
	}
	if(t==1) {
		for(int i=1;i<=n;i++) {
			if(rd[i]%2) {
				pn;return 0;
			}
		}
		py;
		solve1();
	}
	else {
		for(int i=1;i<=n;i++) {
			if(rd[i]!=cd[i]) {
				pn;return 0;
			}
		}
		py;
		solve2();
	}
	return 0;
}


