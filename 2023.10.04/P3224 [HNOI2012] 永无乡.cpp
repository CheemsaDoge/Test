/*code by CheemsaDoge*/
#include<bits/stdc++.h>
namespace CheemsaDoge {
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n'||_in=='\r') _in=(char)getchar();}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 _mod) {long long ans=1;_a%=_mod;while(_n) {if(_n&1) ans=ans*_a%_mod;_n>>=1;_a=_a*_a%_mod;}return ans;}
	using std::sort;
	using std::set;
	using std::vector;
	using std::pair;
}
namespace OI_File{
	inline void _File() {
		freopen("x.in","r",stdin);
		freopen("x.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=1e5+5;
/*---------------------------------pre------------------------------------*/
struct part {
	int ls,rs,val;
}pa[MAXN*20];
int root[MAXN],fa[MAXN];
int hash[MAXN];
int n,m,q,cnt;
inline int find(int _x) {return fa[_x]==_x?_x:fa[_x]=find(fa[_x]);}
inline void initialize() {for(int i=1;i<=n;i++) fa[i]=i;}
void insert(int &a,int x,int l,int r) {
	if(!a) a=++cnt;pa[a].val++;
	if(l==r) return void();
	int mid=(l+r)>>1;
	if(x<=mid) insert(pa[a].ls,x,l,mid);
	else insert(pa[a].rs,x,mid+1,r);
}
void merge(int &a,int b) {
	if(!a) return a=b,void();
	if(!b) return void();
	pa[a].val+=pa[b].val;
	merge(pa[a].ls,pa[b].ls);
	merge(pa[a].rs,pa[b].rs);
}
int p;
int query(int a,int l,int r,int k) {
	if(l==r) return l;
	int sls=pa[pa[a].ls].val;
	int mid=(l+r)>>1;
	if(sls>=k) return query(pa[a].ls,l,mid,k);
	return query(pa[a].rs,mid+1,r,k-sls);
}
signed main() {
//	_File();
	read(n,m);
	initialize();
	for(int i=1;i<=n;i++) read(p),hash[p]=i,insert(root[i],p,1,n);
	int u,v;
	char op;
	for(int i=1;i<=m;i++) {
		read(u,v);
		merge(root[find(u)],root[find(v)]);
		fa[find(v)]=fa[find(u)];
	}
	read(q);
	for(int i=1;i<=q;i++) {
		read(op,u,v);
		if(op=='Q')  if(pa[root[find(u)]].val<v) write(-1,'\n'); else write(hash[query(root[find(u)],1,n,v)],'\n');
		else {
			if(find(u)!=find(v)) {
				merge(root[find(u)],root[find(v)]);
				fa[find(v)]=fa[find(u)];
			}
		}
	}
	return 0;
}

