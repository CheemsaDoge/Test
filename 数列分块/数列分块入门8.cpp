/*code by CheemsaDoge*/
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
namespace CheemsaDoge{
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &in) {in=getchar();while(in==' '||in=='\n') in=getchar();}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename types,typename ... Args> inline void read(types &x, Args &... args) {read(x), read(args...);}
	template <typename types,typename ... Args> inline void write(types x, Args ... args) {write(x),putchar(' '),write(args...);}
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 _mod) {long long ans=1;_a%=_mod;while(_n) {if(_n&1) ans=ans*_a%_mod;_n>>=1;_a=_a*_a%_mod;}return ans;}
	#define sort std::sort
	using std::set;
	using std::vector;
	using std::pair;
}
using namespace CheemsaDoge;
typedef long long LL;
//namespace CheemsaDoge is necessary for ODT
namespace ODT{
	struct node_odt{
		int l,r;
		mutable int val;
		node_odt(int L,int R =-1,int V=0) : l(L), r(R),val(V) {}
		bool operator <(const node_odt& a) const {return l<a.l;}
	};
	set<node_odt>odt;
	#define Iterator set<node_odt>::iterator
	template <typename type1> inline std::set<node_odt>::iterator split(type1 pos) {
		Iterator it = odt.lower_bound(node_odt(pos));
		if(it!=odt.end()&&it->l==pos) return it;it--;
		if(it->r<pos) return odt.end();
		int l=it->l,r=it->r;
	    long long int v=it->val;
	    odt.erase(it);
		odt.insert(node_odt(l,pos-1,v));
		return odt.insert(node_odt(pos,r,v)).first;
	}
	template <typename type1,typename type2> inline void assign(type1 l,type1 r,type2 v=0) {
		Iterator itr=split(r+1);
		Iterator itl=split(l);
		odt.erase(itl,itr);
		odt.insert(node_odt(l,r,v));
	}
	template <typename type1,typename type2> inline void add(type1 l,type1 r,type2 v)  {
		Iterator itr=split(r+1),itl=split(l);
		for(;itl!=itr;itl++) itl->val+=v;
	}
	template <typename type1,typename type2> inline type1 kth(type2 l,type2 r,type2 k) {
		std::vector<std::pair<long long,int> >vec;
		Iterator itr=split(r+1);
		Iterator itl=split(l);
		for(;itl!=itr;itl++) vec.push_back(std::make_pair(itl->val,itl->r-itl->l+1));
		sort(vec.begin(),vec.end());
		for(int i=0;i<(int)vec.size();i++) {
			k-=vec[i].second;
			if(k<=0) return vec[i].first;
		}
		return -1;
	}
	template <typename type1,typename type2> inline type1 query(type2 l,type2 r,type2 c) {
		Iterator itr=split(r+1);
		Iterator itl=split(l);
		type1 ans=0;
		for(;itl!=itr;itl++) if(itl->val==c) ans+=itl->r-itl->l+1;
		return ans;
	} 
}
using namespace ODT;
/*---------------------------------pre------------------------------------*/
const int MAXN=1e6+5;
int n,m;
int seed,vmax;
int a[MAXN];

signed main() {
	read(n);
	for (int i=1; i<=n; ++i) {
		read(a[i]);
		odt.insert(node_odt(i,i,a[i]));
	}
	odt.insert(node_odt(n+1, n+1, 0));
	for (int i=1;i<=n; ++i) {
		int l,r,c;
        read(l,r,c);
		write(query<int>(l,r,c),'\n');
        assign(l,r,c);
	}
	return 0;
}

