/*code by CheemsaDoge*/
#include <bits/stdc++.h>
namespace CheemsaDoge{
	template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &in) {in=getchar();while(in==' '||in=='\n') in=getchar();}
	template <typename T> inline void write(T _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
	template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
	template <typename T> inline T abs(const T _a) {return _a<0?-_a:_a;}
	template <typename T> inline void swap(T &_x,T &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename types,typename ... Args> inline void read(types &x, Args &... args) {read(x), read(args...);}
	template <typename types,typename ... Args> inline void write(types x, Args ... args) {write(x),putchar(' '),write(args...);}
	#define vector std::vector
	#define sort std::sort
}
using namespace CheemsaDoge;
const int MAXM=1e6+10;const int MAXN=1e6+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
using namespace std;
const int N=1e5+7;
ll f[N*4];
ll n,m,p;
struct tt {
	ll sum;
	ll add;
    ll val;
}e[N*4];
void buildtree(int k,int l,int r) {
	e[k].val=1;e[k].add=0;
	if(l==r) {
		e[k].sum=f[l];
		return;
	}
	int mid=(l+r)>>1;
	buildtree(k<<1,l,mid);buildtree(k<<1|1,mid+1,r);
	e[k].sum=e[k<<1].sum+e[k<<1|1].sum;
	return ;
}
void pushdown(int k,int o) {
	int kl=k<<1,kr=k<<1|1;
	e[kl].sum=(e[kl].sum*e[k].val+e[k].add*(o-(o>>1)))%p;
	e[kr].sum=(e[kr].sum*e[k].val+e[k].add*(o>>1))%p;
	e[kl].val=(e[kl].val*e[k].val)%p;
	e[kr].val=(e[kr].val*e[k].val)%p;
	
	e[kl].add=(e[kl].add*e[k].val+e[k].add)%p;
	e[kr].add=(e[kr].add*e[k].val+e[k].add)%p;
	e[k].val=1;
	e[k].add=0;
	return;
}
void add(int k,int l,int r,int x,int y,int w) {
	if(x<=l&&y>=r) {
		e[k].add=(e[k].add+w)%p;
		e[k].sum=(e[k].sum+(r-l+1)*w)%p;
		return ;
	}
	pushdown(k,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)
		add(k<<1,l,mid,x,y,w);
	if(y>mid)
		add(k<<1|1,mid+1,r,x,y,w);
	e[k].sum=(e[k<<1].sum+e[k<<1|1].sum)%p;
	return;
}
void mul(int k,int l,int r,int x,int y,int w) {
	if(x<=l&&y>=r) {
		e[k].val=(e[k].val*w)%p;
		e[k].add=(e[k].add*w)%p;
		e[k].sum=(e[k].sum*w)%p;
		return ;
	}
	pushdown(k,r-l+1);
	int mid=(l+r)>>1;
	if(x<=mid)
		mul(k<<1,l,mid,x,y,w);
	if(y>mid)
		mul(k<<1|1,mid+1,r,x,y,w);
	e[k].sum=(e[k<<1].sum+e[k<<1|1].sum)%p;
	return ;
}

ll query(int k,int l,int r,int x,int y) {
	if(x<=l&&y>=r) return e[k].sum%p;
	int mid=(l+r)>>1;
	pushdown(k,r-l+1);
	ll temp=0;
	if(x<=mid) temp=(temp+query(k<<1,l,mid,x,y));
	if(y>mid) temp=(temp+query(k<<1|1,mid+1,r,x,y));
	e[k].sum=(e[k<<1].sum+e[k<<1|1].sum)%p;
	return temp%p;
}
int main() {
	read(n,p);
	for(int i=1;i<=n;i++) read(f[i]);
	buildtree(1,1,n);
	read(m);
	while(m--) {
		int a,b,c,d;
		read(a,b,c);
		if(a==1) read(d),mul(1,1,n,b,c,d);
		else if(a==2) read(d),add(1,1,n,b,c,d);
		else write(query(1,1,n,b,c),'\n');
	}
	return 0;
 } 
