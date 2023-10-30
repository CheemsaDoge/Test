/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n,m;
int deg[MAXN],cnt[MAXN];
int fa[MAXN];
inline int find(int a) {
	return a==fa[a]?a:fa[a]=find(fa[a]);
}
int main() {
	while(~scanf("%d%d",&n,&m)) {
		int a,b;
		for(int i=0;i<=n;i++) fa[i]=i,deg[i]=cnt[i]=0;
		int sum=0;
		for(int i=1;i<=m;i++) {
			read(a);read(b);
			if(find(a)!=find(b)) fa[find(b)]=find(a);
			deg[a]++;deg[b]++;
		}
		for(int i=1;i<=n;i++) {
            find(i);
            cnt[fa[i]]+=deg[i]&1;
        }
        for (int i=1;i<=n;i++) {
            if (fa[i]==i&&deg[i]) {
                sum+=cnt[i]?cnt[i]>>1:1;
            }
        }
		write(sum);pc;
	}
	return 0;
}
