/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template <>void read <char>(char &in) {in=getchar();while(in==' '||in=='\n') in=getchar();}
template <typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
template <typename T> inline T abs(const T _a) {return _a<0?-_a:_a;}
template <typename T> inline void swap(T &_x,T &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
template <typename types,typename ... Args> inline void read(types &x, Args &... args) {read(x), read(args...);}
const int MAXM=3e5+10;const int MAXN=3e5+10;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
long long n,m,f[MAXN],degree[MAXN],flag[MAXN],cut[MAXN],sum,ans,cnt;
long long x,y;
long long find_set(long long x) {return x==f[x]?f[x]:f[x]=find_set(f[x]);}
void merge(long long x,long long y) {if(find_set(x)!=find_set(y)) f[find_set(x)]=find_set(y);}
int main() {
	read(n,m);
	for(long long i=1;i<=2*m+n;i++) f[i]=i;
	for(long long i=1;i<=m;i++) {
		read(x,y);
		if(x==0) n++,x=n;
		if(y==0) n++,y=n;
		degree[x]++;degree[y]++;
		merge(x,y);
	}
	for(long long i=1;i<=n;i++) if(f[i]==i&&degree[i]) cnt++;
	if(cnt==1) {
		for(long long i=1;i<=n;i++)
			if(degree[i]) {if(degree[i]%2) sum++;if(degree[i]>2) ans++;}
	}
	else {
		for(long long i=1;i<=n;i++) 
			if(degree[i]) { 
				if(degree[i]%2) {sum++;cut[find_set(i)]=1;}
			    if(degree[i]>2) {ans++;flag[find_set(i)]=1;}
			} 
		for(long long i=1;i<=n;i++) if(f[i]==i&&degree[i]&&!cut[i]) {ans++;if(!flag[i]) ans++;}
	}
	write(ans+sum/2);
	return 0;
}
