/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-27 14:50:28
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-27 16:37:52
 * @FilePath: \TEST\2023.10.27\糖果.cpp
 * Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
namespace CheemsaDoge {
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 __mod) {long long _ans=1;_a%=__mod;while(_n) {if(_n&1) _ans=_ans*_a%__mod;_n>>=1;_a=_a*_a%__mod;}return _ans;}
	template <typename type1> inline type1 __gcd(type1 _a,type1 _b) {if(!_a||!_b) return _a==0?_b:_a;type1 az=__builtin_ctz(_a),bz=__builtin_ctz(_b);type1 z=min(az,bz),dif;_b>>=bz;while(_a) {_a>>=az;dif=_b-_a;az=__builtin_ctz(dif);if(_a<_b) _b=_a;_a=dif<0?-dif:dif;}return _b<<z;}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	using std::sort;using std::set;using std::vector;using std::pair;using std::make_pair;
}
namespace OI_File{
	inline void _File() {
		freopen("thisisyouriofilename.in","r",stdin);
		freopen("thisisyouriofilename.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
#undef std
using namespace OI_File;
typedef long long LL;
// typedef __int128_t int128;
const int MAXN=6e5;const int MOD=998244353;
const int MAXB=788;
namespace ODT {
	struct node_odt {
		int l,r;
		mutable long long int val;
		node_odt(int L,int R =-1,long long int V=0) : l(L), r(R),val(V) {}
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
		for(;itl!=itr;itl=odt.lower_bound(node_odt(itl->r+1))) itl->val+=v;
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
	template <typename type1,typename type2> inline type1 sum(type2 l,type2 r) {
		Iterator itr=split(r+1);
		Iterator itl=split(l);
		type1 ans=0;
		for(;itl!=itr;itl=odt.lower_bound(node_odt(itl->r+1))) {
			ans=max(ans,itl->val);
		}
		return ans;
	} 
}
using namespace ODT;
/*---------------------------------pre------------------------------------*/
int n,m,a[MAXN];
signed main() {
	// _File();
	read(n,m);int lst=0,st=0;
	for(int i=1;i<=n;i++) {
		read(a[i]);
		if(a[i]!=lst) {
			odt.insert((node_odt){st,i-1,lst});
			st=i;
			lst=a[i];
		}
	}
	odt.insert((node_odt){st,n,lst});
	odt.insert((node_odt){n+1,n+1,1145141919810ll});
	for(int i=1;i<=m;i++) {
		int l,r;read(l,r);
		Iterator itr=split(r+1);
		Iterator itl=split(l);
		LL why=sum<LL>(l,r);
		int ll=itl->l;
		for(;itl!=itr;itl=odt.lower_bound(node_odt(itl->r+1))) {
			if(itl->val==why) {
				itl->val++;
				assign(ll,itl->l-1,why);
				ll=itl->r+1;
			} 
		}
	}
	Iterator it=odt.lower_bound(node_odt(1));
	LL val=it->val;
	for(int i=1;i<=n;i++) {
		write(val);write(' ');
		if(i>=it->r) {
			it=odt.lower_bound(node_odt(it->r+1));
			val=it->val;
		}
	}
	return 0;
}
