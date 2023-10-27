/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-27 10:34:40
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-27 16:38:29
 * @FilePath: \TEST\2023.10.27\[ZJOI2010] 数字计数.cpp
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
#define int LL
/*---------------------------------pre------------------------------------*/
int a[20],totr,f[50][3][50][50];
LL l,r;
inline void init(LL n) {
	totr=0;
	if(n==0) return a[1]=0,totr=1,void();
	while(n) {
		a[++totr]=n%10;
		n/=10;
	} return void();
}
int dfs(int pos,bool lead,int limit,int num,int sum) {
	if(!pos) return sum;
	if(!limit&&~f[pos][lead][num][sum]) return f[pos][lead][num][sum];
	int up=limit?a[pos]:9;LL ans=0;
	for(int i=0;i<=up;i++) {
		if(num==0) ans+=dfs(pos-1,lead||i,limit&&(i==up),num,lead?sum+(i==num):0);
		else ans+=dfs(pos-1,lead||i,limit&&(i==up),num,sum+(num==i));
	} return f[pos][lead][num][sum]=ans;
}
inline LL solve(int num) {
	int up=a[totr];LL ans=0;
	for(int i=0;i<=up;i++) {
		if(num==0) ans+=dfs(totr-1,i,(i==up),num,0);
		else ans+=dfs(totr-1,i,(i==up),num,(num==i));
	} return ans;
}
int ans[11];
signed main() {
	// _File();
	read(l,r);init(r);
	memset(f,-1,sizeof(f));
	for(int i=0;i<=9;i++) ans[i]=solve(i);
	init(l-1);memset(f,-1,sizeof(f));
	if(totr==1) {
		for(int i=0;i<a[1];i++) ans[i]--;
	} else for(int i=0;i<=9;i++) ans[i]-=solve(i);
	for(int i=0;i<=9;i++) write(ans[i]),write(' ');
	return 0;
}
