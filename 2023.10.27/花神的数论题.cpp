/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-27 08:35:07
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-27 09:17:01
 * @FilePath: \TEST\2023.10.27\花神的数论题.cpp
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
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 __mod) {long long _ans=1;_a%=__mod;if(_n==0) return 1;while(_n) {if(_n&1) _ans=_ans*_a%__mod;_n>>=1;_a=_a*_a%__mod;}return _ans;}
	template <typename type1> inline type1 __gcd(type1 _a,type1 _b) {if(!_a||!_b) return _a==0?_b:_a;type1 az=__builtin_ctz(_a),bz=__builtin_ctz(_b);type1 z=min(az,bz),dif;_b>>=bz;while(_a) {_a>>=az;dif=_b-_a;az=__builtin_ctz(dif);if(_a<_b) _b=_a;_a=dif<0?-dif:dif;}return _b<<z;}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	using std::sort;using std::set;using std::vector;using std::pair;
}
namespace OI_File{
	inline void _File() {
		freopen("handbook.in","r",stdin);
		freopen("handbook.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
#undef std
using namespace OI_File;
typedef long long LL;
// typedef __int128_t int128;
const int MAXN=6e5;const LL MOD=10000007;
/*---------------------------------pre------------------------------------*/
// LL inv[100];
#define int LL
int a[MAXN];
LL n;
namespace subtask
{
	int f[60][2][60][60],totr=0;
	int dfs(int pos,int limit,int num,int up) {
		if(!pos) return (num==up);
		if(!limit&&~f[pos][limit][num][up]) return f[pos][limit][num][up];
		int lim=limit?a[pos]:1;LL res=0;
		for(int i=0;i<=lim;i++) res=(res+dfs(pos-1,limit&&(i==lim),num+i,up));
		return f[pos][limit][num][up]=res;
	}
	inline void init() {
		LL tmp=n;memset(f,-1,sizeof(f));
		while(tmp) {
			a[++totr]=tmp%2;
			tmp/=2ll;
		} return void();
	}
	inline LL solve(int num) {
		int lit=a[totr];LL ans=0;
		for(int i=0;i<=lit;i++) ans=(ans+dfs(totr-1,i==lit,i,num));
		return ans;
	}
	signed main() {
		init();LL ans=1;
		for(int i=1;i<=totr;i++) {
			ans=(ans*pow((LL)i,solve(i),MOD))%MOD;
		} return write(ans),0;
	}
} 
signed main() {
	read(n);
	return subtask::main();
}
