/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template<typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template<typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
void _File() {
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
}
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr=1;
void add_edge(int u,int v,int val=0) {
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n,m;

int f[MAXN];
int main()
{
//	_File();
int maxx=0;
int B=15;
	for(int i=1;i<=100;i++) {
		write(i);pk;int ans=0;
		for(int j=1;j<=i;j++) {
			if(std::__gcd(i,j)==1)f[i]++;
		}
		write(f[i]);
		pk;
		int q=i;
		for(int j=1;j<=maxx-B;j++) {
			q=f[q];
		}
		if(maxx-B<0) q=i;
		write(q);pc;
		maxx=max(maxx,f[i]);
	}
	return 0;
}

