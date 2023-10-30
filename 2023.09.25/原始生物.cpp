/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template <typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
const int MAXM=1000+10;const int MAXN=1000+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
std::vector<int>a[MAXN];
int cd[MAXN],rd[MAXN],ans;
bool vis[MAXN],flag;
int dfs(int k) {
	vis[k]=1;if(cd[k]!=rd[k]) flag=0;
	for(auto i : a[k]) if(!vis[i]) dfs(i);
	return 1;
}
int main() {
	int n,l,r,maxx=0;read(n);
	for(int i=1;i<=n;++i) read(l),read(r),++cd[r],++rd[l],a[l].push_back(r),a[r].push_back(l),maxx=max(max(maxx,r),l);
	for(int i=1;i<=maxx;++i) if(!vis[i]&&(int)a[i].size()) flag=1,dfs(i),ans+=flag;
	for(int i=1;i<=maxx;++i) if(cd[i]||rd[i]) ans+=max(cd[i],rd[i]);
	write(ans);
	return 0;
}
