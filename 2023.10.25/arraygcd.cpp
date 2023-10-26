/*
 * @Author: DarkMoon_Dragon
 * @Date: 2023-10-25 10:14:30
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-26 07:56:35
 * @FilePath: \TEST\2023.10.25\arraygcd.cpp
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
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 _mod) {long long ans=1;_a%=_mod;while(_n) {if(_n&1) ans=ans*_a%_mod;_n>>=1;_a=_a*_a%_mod;}return ans;}
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
		freopen("flandre.in","r",stdin);
		freopen("flandre.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long ll;
#define int ll
const int MAXN=1.5e6;
/*---------------------------------pre------------------------------------*/
const ll inf=1e18;;
const int N=1e6+50;
ll n,a,b,v[N];
ll dp[N][3],cost[N];
ll fac[500],res;
inline ll solve(ll x) {
	memset(dp,0,sizeof dp);
	for(int i=1;i<=n;++i) {
		if(v[i]%x==0) cost[i]=0;
		else if((v[i]+1)%x==0||(v[i]-1)%x==0) cost[i]=b;
		else cost[i]=inf;
	}
	for(int i=1;i<=n;++i) {
		if(cost[i]==inf) {
			dp[i][0]=inf;
			dp[i][1]=min(dp[i-1][0],dp[i-1][1])+a;
			dp[i][2]=inf;
		}else {
		    dp[i][0]=dp[i-1][0]+cost[i];
		    dp[i][1]=min(dp[i-1][0],dp[i-1][1])+a;
		    dp[i][2]=min(dp[i-1][2],dp[i-1][1])+cost[i];
	    }
	}
	return min(dp[n][0],min(dp[n][1],dp[n][2]));
}
inline void init(ll x) { 
	for(int i=2;i*i<=x;++i) {
		if(x%i) continue;
		fac[res++]=i;
		while(x%i==0) x/=i;
	}
	if(x>1) fac[res++]=x;
}
signed main() {
	while(~scanf("%I64d%I64d%I64d",&n,&a,&b)) {
		for(int i=1;i<=n;++i) read(v[i]);res=0;
		init(v[1]+1);init(v[1]);init(v[1]-1);
		init(v[n]+1);init(v[n]);init(v[n]-1);
		sort(fac,fac+res);
		res=std::unique(fac,fac+res)-fac;
		ll ans=inf;
		for(int i=0;i<res;++i) ans=min(ans,solve(fac[i]));
		write(ans,'\n');
	}
}