/*** 
 * @Author: CheemsaDoge
 * @Date: 2023-10-26 07:57:50
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-11 12:00:39
 * @FilePath: \TEST\2023.11.11ex\序列终结者.cpp
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
	#define sqrt __builtin_sqrt
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
const int MAXN=6e5;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
struct Part {
    int l1,l2,r2,re,tag,maxn;
}s[600];
int a[MAXN],b[MAXN];
int cnt,n,q;
inline void get(int x) {
    s[x].maxn=-0x3f3f3f3f;
    for(int i=s[i].l1;i<=s[i].l1+s[i].r2-s[i].l2;i++) s[x].maxn=max(s[x].maxn,a[i]);
}
inline void rev(int l,int r) {
    for(int i=1;i<=cnt;i++) {
        if(s[i].l2>r||s[i].r2<l) continue;
        if(s[i].l2>=l&&s[i].r2<=r) {
            int l2=s[i].l2,r2=s[i].r2;
            s[i]={s[i].l1,l+r-r2,r+l-l2,s[i].re^1,s[i].tag,s[i].maxn};
            continue;
        }
        if(s[i].r2<=r) {
            s[++cnt]={s[i].l1,s[i].l2,l,s[i].re,s[i].tag,0};
            // get(cnt);
            s[i].l1+=l-s[i].l2;
            s[i].l2=l;
            // get(i);
            int l2=s[i].l2,r2=s[i].r2;
            s[i]={s[i].l1,l+r-r2,r+l-l2,s[i].re^1,s[i].tag,s[i].maxn};
            
        } if(s[i].l2>=l) {
            s[++cnt]={s[i].l1+r-s[i].l2+1,r+1,s[i].r2,s[i].re,s[i].tag,0};
            // get(cnt);
            s[i].r2=r;
            // get(i);
            int l2=s[i].l2,r2=s[i].r2;
            s[i]={s[i].l1,l+r-r2,r+l-l2,s[i].re^1,s[i].tag,s[i].maxn};
        }
    }
}
inline void build() {
    for(int i=1;i<=cnt;i++) {
		if(s[i].re) for(int j=s[i].r2;j>=s[i].l2;j--) b[j]=a[s[i].l1++]+s[i].tag;
		else for(int j=s[i].l2;j<=s[i].r2;j++) b[j]=a[s[i].l1++]+s[i].tag;
	}
	cnt=1,s[cnt]={1,1,n,0,0};/*get(1);*/std::swap(a,b);
}
const int bl=345;
signed main() {
	// _File();
    read(n,q);
	for(int i=1;i<=n;i++) a[i]=i;
	s[++cnt]={1,1,n,0,0,n};cnt=1;
	while(q--) {
    	int l,r;
		read(l,r);
        if(l!=r) rev(l,r);
		if(cnt>bl) build();
	}
	build();
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}
/*
5 2
1 3
1 4

5 2
1 4
1 3
*/