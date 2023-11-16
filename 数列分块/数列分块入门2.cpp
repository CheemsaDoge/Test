/*** 
 * @Author: CheemsaDoge
 * @Date: 2023-11-08 15:46:09
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-15 21:10:34
 * @FilePath: \TEST\数列分块\数列分块入门2.cpp
 * @Forgive me.
 * @Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
namespace CheemsaDoge {
	typedef long long LL;
	template <typename type1,typename type2> inline type1 min(const type1 _a,const type2 _b) {return _a>_b?_b:_a;}
	template <typename type1,typename type2> inline type1 max(const type1 _a,const type2 _b) {return _a>_b?_a:_b;}
	template <typename types,typename ... args> inline types min(const types _a,const args ... more) {return min(_a,more...);}
	template <typename types,typename ... args> inline types max(const types _a,const args ... more) {return max(_a,more...);}
	template <typename type1,typename type2> inline void __getmin(type1 &_a,const type2 _b) {_a=min(_a,_b);}
	template <typename type1,typename type2> inline void __getmax(type1 &_a,const type2 _b) {_a=max(_a,_b);}
	template <typename types,typename ... args> inline void __getmin(types &_a,const args ... _b) {_a=getmin(_a,_b...);}
	template <typename types,typename ... args> inline void __getmax(types &_a,const args ... _b) {_a=getmax(_a,_b...);}
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	inline int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}return x*f;}
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
/** @brief 计算某数的多次方对mod取模后的答案 
  * @description: 计算某数的多次方对mod取模后的答案
  * @param {type1} _a 底数(返回值类型以此为主)
  * @param {type2} _n 次数
  * @param {type3} __mod 模数(不填则默认为2,305,843,009,213,693,952(2^61))
  * @return {*} _a的_n次方对__mod取模(类型以底数类型为准)
  */
 	template <typename type1,typename type2> type1 pow(type1 _a,type2 _n,LL __mod=2305843009213693952ll) {type1 _ans=1;_a%=__mod;while(_n) {if(_n&1) _ans=_ans*_a%__mod;_n>>=1;_a=_a*_a%__mod;}return _ans;}
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
// typedef __int128_t int128;
const int MAXN=5.1e4+5;const int MAXB=500;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
int bl;
int L[MAXB],R[MAXB],belong[MAXN];
int tag[MAXB],a[MAXN],b[MAXN],maxn[MAXN],minn[MAXN];
int totr=1;
inline void reset(int x) {
    for(int i=L[x];i<=R[x];i++) b[i]=a[i];
    sort(b+L[x],b+R[x]+1);
}
inline void add(int l,int r,int x) {
    int ls=belong[l],rs=belong[r];
    if(ls==rs) {
        for(int i=l;i<=r;i++) a[i]+=x,minn[ls]=min(minn[ls],a[i]),maxn[ls]=max(maxn[ls],a[i]);
        reset(ls);
        return void();
    }
    for(int i=l;i<=R[ls];i++) a[i]+=x,minn[ls]=min(minn[ls],a[i]),maxn[ls]=max(maxn[ls],a[i]);
    for(int i=L[rs];i<=r;i++) a[i]+=x,minn[rs]=min(minn[rs],a[i]),maxn[rs]=max(maxn[rs],a[i]);
    reset(ls);reset(rs);
    for(int i=ls+1;i!=rs;i++) tag[i]+=x;
    return void();
}
inline int query(int l,int r,LL x) {
    int ans=0;
    int ls=belong[l],rs=belong[r];
    if(ls==rs) {
        int c=x-tag[ls];
        if(minn[ls]>=c) return 0;
        if(maxn[ls]<c) {ans+=r-l+1;return ans;}
        for(int i=l;i<=r;i++) ans+=a[i]<x-tag[ls];
        return ans;
    }
    for(int i=l;i<=R[ls];i++) ans+=a[i]<x-tag[ls];
    for(int i=L[rs];i<=r;i++) ans+=a[i]<x-tag[rs];
    for(int i=ls+1;i!=rs;i++) {
        int c=x-tag[i];
        if(minn[i]>=c) continue;
        if(maxn[i]<c) { ans+=R[i]-L[i]+1;continue;}
        ans+=std::lower_bound(b+L[i],b+R[i]+1,c)-b-L[i];
    }
    return ans;
}
signed main() {
	// _File();
    int n;read(n);
    bl=sqrt(n);
    L[1]=1;
    for(int i=1;i<=bl+2;i++) maxn[i]=-2147483647,minn[i]=2147483647;
    for(int i=1;i<=n;i++) {
        read(a[i]);
        belong[i]=totr;
        maxn[totr]=max(maxn[totr],a[i]);
        minn[totr]=min(minn[totr],a[i]);
        if(!(i%bl)) {
            R[totr]=i;
            reset(totr);
            L[++totr]=i+1;
        }
    }
    if(n%bl) R[totr]=n,reset(totr);
    for(int qq=1;qq<=n;qq++) {
        int op,l,r,x;
        read(op,l,r,x);
        if(!op) add(l,r,x);
        else __builtin_printf("%d\n",query(l,r,1ll*x*x));
    }
	return 0;
}