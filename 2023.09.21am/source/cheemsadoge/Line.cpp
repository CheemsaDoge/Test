/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=3e5+1145;const int MAXN=2000;const int INF=2147483647;//2^59
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
inline void _File(){
	freopen("Line.in","r",stdin);
	freopen("Line.out","w",stdout);
}
int n,m1,m2,p;
int a,b,c,fst[10100],nex[50010],v[50010],w[50010],cnt,vis[10100],dis[10100],tim[10100];
void add_edge(int _u,int _v,int val)
{
	nex[++cnt]=fst[_u];
    fst[_u]=cnt;
    v[cnt]=_v;
    w[cnt]=val;
    return ;
}
template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
std::queue<int> q;
int SPFA(int k)
{
	memset(dis,0x7f/3,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(tim,0,sizeof(tim));
	q.push(k);dis[k]=0;vis[k]=1;
	while(!q.empty()) {
		int u=q.front();q.pop();
		tim[u]++;vis[u]=0;
		if(tim[u]>n) return -1;
		for(int i=fst[u];i!=-1;i=nex[i])
			if(dis[v[i]]>dis[u]+w[i]) {
				dis[v[i]]=dis[u]+w[i];
				if(!vis[v[i]]) {
					q.push(v[i]);
					vis[v[i]]=1;
				}
			}
	}
	if(dis[n]>1e8) return -2;
	return dis[n];
}
int main()
{
//	_File();
    memset(fst,-1,sizeof(fst));
	read(n);read(m1);read(m2);
	for(int i=1;i<=m1;i++) {
		read(a);read(b);read(c);
		add_edge(min(a,b),max(a,b),c);
	}
	for(int j=1;j<=m2;j++) {
		read(a);read(b);read(c);
		add_edge(max(a,b),min(a,b),-c);
	}
	for(int i=2;i<=n;i++) add_edge(i,i-1,0);
	for(int i=1;i<=n;i++) add_edge(0,i,0);
	int sp=SPFA(0); 
	if(sp<=-1) {
		write(sp);
		return 0;
	}
	else write(SPFA(1));
	return 0;
}
//数组开小De半小时bug，（艹 
