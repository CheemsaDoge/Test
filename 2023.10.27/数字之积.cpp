/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-27 09:44:10
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-27 12:02:51
 * @FilePath: \TEST\2023.10.27\数字之积.cpp
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
/*---------------------------------pre------------------------------------*/
int n,a[19];
LL n1[55],n2[37],n3[19],n4[19],f[19][55][37][19][19];
bool wy(int s1,int s2,int s3,int s4) {
    LL ans=n1[s1]*n2[s2]*n3[s3]*n4[s4];
    return ans<=n;
}
long long dfs(int pos,int s1,int s2,int s3,int s4,bool limit,bool lead) {
    if(!pos) return wy(s1,s2,s3,s4);
    if(wy(s1,s2,s3,s4)==false)return 0;
    if(!limit&&!lead&&~f[pos][s1][s2][s3][s4]) return f[pos][s1][s2][s3][s4];
    int up=limit?a[pos]:9;LL ans=0;
    for(int i=0;i<=up;i++) {
        if(!lead&&!i)continue;
        int ss1=s1,ss2=s2,ss3=s3,ss4=s4;
		bool bk1=false,bk2=false;
        if(i==2) ss1++;
        if(i==3) ss2++;
        if(i==4) ss1+=2;
        if(i==5) ss3++;
        if(i==6) ss1++,ss2++;
        if(i==7) ss4++;
        if(i==8) ss1+=3;
        if(i==9) ss2+=2;
        if(limit&&i==a[pos]) bk1=true;
        if(lead&&!i) bk2=true;
        ans+=dfs(pos-1,ss1,ss2,ss3,ss4,bk1,bk2);
    }
    if(!limit&&!lead)f[pos][s1][s2][s3][s4]=ans;
    return ans;
}
LL solve(LL x) {
    int pos=0;
    while(x) {
        a[++pos]=x%10;
        x/=10;
    }
    memset(f,-1,sizeof(f));
    return dfs(pos,0,0,0,0,true,true);
}
signed main() {
    n1[0]=n2[0]=n3[0]=n4[0]=1;
    for(int i=1;i<=54;i++) n1[i]=n1[i-1]*2;
    for(int i=1;i<=36;i++) n2[i]=n2[i-1]*3;
    for(int i=1;i<=18;i++) n3[i]=n3[i-1]*5;
    for(int i=1;i<=18;i++) n4[i]=n4[i-1]*7;
    LL l,r;read(n,l,r);
    write(solve(r-1)-solve(l-1));
    return 0;
}

