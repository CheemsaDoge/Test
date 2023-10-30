/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=4e5+1145;const int MAXN=3e5+1145;const long long int INF=576460752303423488ll;//2^59
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
inline void _File(){
	freopen("Candy.in","r",stdin);
	freopen("Candy.out","w",stdout);
}
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr;
inline void add_edge(int u,int v,int val)
{
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n,k;
int cnt[MAXN],dis[MAXN],vis[MAXN];
int num=0;
#define v edge[i].v
inline void SPFA()
{
	std::queue<int>a;
	for(int i=1;i<=n;i++) {
		vis[i]=dis[i]=1;
		a.push(i);
	}
	while(!a.empty()) {
		int u=a.front();
		a.pop();
		vis[u]=false;
		for(int i=head[u];i;i=edge[i].nxt)
			if(dis[u]+edge[i].val>dis[v]) {
				dis[v]=dis[u]+edge[i].val;
				if(!vis[v]) {
					a.push(v);
					vis[v]=true;
					cnt[v]=cnt[u]+1;
					if(cnt[v]>=n) {
						write(-1);
						exit(0);
					}
				}
			}
	}
}
#undef v

int main() {
	_File();
	read(n);read(k);
	for(int i=1;i<=n;i++) add_edge(0,i,1);
	for(int i=1;i<=k;i++)
	{
		int x,u,v;
		read(x);read(u);read(v);
		if((x==2||x==4)&&u==v) {
			write(-1);
			return 0;
		}
		if(x==1) add_edge(u,v,0),add_edge(v,u,0);
		if(x==2) add_edge(u,v,1);
		if(x==3) add_edge(v,u,0);
		if(x==4) add_edge(v,u,1);
		if(x==5) add_edge(u,v,0);
	}
    for(int i=1;i<=n;i++) dis[i]=1;
	SPFA();
	long long int ans=0;
//	for(int i=1;i<=n;i++) num+=!tis[i];
	for(int i=1;i<=n;i++) ans+=1ll*dis[i];
//	if(minn<=0) ans+=(n-num)*(std::abs(minn)+1)+num;
//	else ans+=num;
	write(ans);
	return 0;
}
