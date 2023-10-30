/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=3e3+1145;const int MAXN=5e3+1145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr;
int rd[MAXN],cd[MAXN];
inline void add_edge(int u,int v,int val) {
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
	rd[v]++;cd[u]++;
}
int n;
int T;
char op;
int siz[MAXN];
inline void initialize() {
	memset(edge,0,sizeof(edge));
	memset(head,0,sizeof(head));
	memset(rd,0,sizeof(rd));
	memset(cd,0,sizeof(cd));
	memset(siz,0,sizeof(siz));
	totr=0;
}
inline int super_topo() {
	std::stack<int>sta;
	for(int i=0;i<n;i++) if(rd[i]==0) siz[i]=1,sta.push(i);
	while(!sta.empty()) {
		int u=sta.top();
		for(int i=head[u];i;i=edge[i].nxt) {
			int v=edge[i].v;rd[v]--;
			if(rd[v]==0) sta.push(v);
			
		}
	}
}
int u,v;
int main()
{
	read(T);
	while(T--) {
		initialize();
		read(n);
		for(int i=1;i<n;i++) {
			read(u);cin>>op;read(v);
			if(op=='<') add_edge(u,v,0);
			if(op=='>') add_edge(v,u,0);
		}
		
	}
	return 0;
}


