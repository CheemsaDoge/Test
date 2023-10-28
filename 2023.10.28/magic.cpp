/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-28 08:32:56
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-28 16:12:41
 * @FilePath: \TEST\2023.10.28\magic.cpp
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
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),write(args...);}
	using std::sort;using std::set;using std::vector;using std::pair;using std::make_pair;
}
namespace OI_File {
	inline void _File() {
		freopen("magic.in","r",stdin);
		freopen("magic.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
#undef std
using namespace OI_File;
typedef long long LL;
// typedef __int128_t int128;
const int MAXN=210;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
typedef pair<int, int>pii;
const int N=80,M=152;
int dp[N][N][M],n,a[N],maxx;
int main() {
    _File();read(n);
    for (int i=1;i<=n;++i) read(a[i]),maxx=max(maxx, a[i]);
    for (int i=1;i<=n;++i) {
        for (int k=0;k<=maxx;++k) dp[i][i][k]=0x3f3f3f3f;
        dp[i][i][a[i]/2]=a[i];
    }
    for (int len=2;len<=n;++len) {
        for (int l=1;l<=n-len+1;++l) {
            int r=l+len-1;
            for(int k=0;k<=maxx;++k) dp[l][r][k]=0x3f3f3f3f;
            for(int mid=l+1;mid<=r;++mid) for(int p=a[r]/2;p<=maxx;++p) for(int k=a[r]/2;k<=p;++k) dp[l][r][p]=min(dp[l][r][p],dp[l][mid-1][p-k]+dp[mid][r][k]);
            for (int p=0;p<=maxx;++p) {
                int nxt=max(p,a[r])/2;
                dp[l][r][nxt]=min(dp[l][r][nxt],dp[l][r-1][p]+max(0,a[r]-p));
            }
        }
    }
    for (int i=1;i<=n;++i) {
        int ret=0x3f3f3f3f;
        for (int k=a[i]/2;k<=maxx;++k) ret=min(ret,dp[1][i][k]);
        write(ret,' ');
    }
    return 0;
}
