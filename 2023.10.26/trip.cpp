/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-22 16:53:05
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-26 19:33:52
 * @FilePath: \TEST\2023.10.26\trip.cpp
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
	using std::sort;using std::set;using std::vector;using std::pair;
}
namespace OI_File{
	inline void _File() {
		freopen("trip.in","r",stdin);
		freopen("trip.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
#undef std
using namespace OI_File;
typedef long long LL;
// typedef __int128_t int128;
const int MAXN=2.5e5;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
int n,m,p,t,tot;
struct ask{
	int x,t,id,dis;
	bool operator <(const ask &b) const {return t==b.t?dis>b.dis:t<b.t;}
}q[MAXN];
int dis[MAXN],ans[MAXN];
signed main(){
	// _File();
	read(n,m,p,t);
    for(int i=1;i<=m;i++){
        int p1,p2,p3,p4,p5,p6;read(p1,p2,p3,p4,p5,p6);
        q[++tot]=(ask){p1,p3,i,0};
        q[++tot]=(ask){p2,p6,i,p5-p4};
    }
    q[++tot]=(ask){n+1,t,0,-0x3f3f3f3f};
    sort(q+1,q+tot+1);
    memset(dis,233,sizeof(dis));
    dis[1]=0;
    for (int i=1;i<=tot;i++) {
        if(q[i].x==n+1) break;
        if(!q[i].dis)ans[q[i].id]=dis[q[i].x];
        else dis[q[i].x]=max(dis[q[i].x],ans[q[i].id]+q[i].dis);
    } write(dis[p]<0?-1:t-dis[p]);
    return 0;
}