/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-25 08:59:09
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-25 20:21:19
 * @FilePath: \TEST\2023.10.25\B.cpp
 * Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
/// @brief 头文件
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
/// @brief 文件输入输出
namespace OI_File{
	/// @brief freopen输入输出
	inline void _File() {
		freopen("flandre.in","r",stdin);
		freopen("flandre.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
typedef long double LD;
const int MAXN=100000;
/*---------------------------------pre------------------------------------*/
int n,block,m;
int L[MAXN],R[MAXN],belong[MAXN];
/// @brief 块最大值
double maxn[MAXN];
/// @brief 块贡献
int contribution[MAXN];
/// @brief 斜率
double a[1500000];
/// @brief 主程序
/// @return 0
signed main() {
	read(n,m);
	block=__builtin_sqrt(n);L[1]=1;
	int now=0;
	for(int i=1;i<=n;i++) {
		belong[i]=now+1;
		if(!(i%block)) {
			R[++now]=i;L[now+1]=i+1;
		}
	}
	if(n%block) R[++now]=n;
	for(int i=1;i<=now;i++) contribution[i]=maxn[i]=0;
	for(int q=1;q<=m;q++) {
		int tmp1,tmp2;read(tmp1,tmp2);
		a[tmp1]=LD(tmp2)/LD(tmp1);double lst=0;int ans=0;
		for(int i=1;i<=belong[tmp1]-1;i++) ans+=contribution[i],lst=max(maxn[i],lst);
		contribution[belong[tmp1]]=0;double Genshit=maxn[belong[tmp1]];maxn[belong[tmp1]]=0;
		for(int i=L[belong[tmp1]];i<=R[belong[tmp1]];i++) {
			maxn[belong[tmp1]]=max(maxn[belong[tmp1]],a[i]);
			if(a[i]>lst) lst=a[i],contribution[belong[tmp1]]++;
		} ans+=contribution[belong[tmp1]];
		if(maxn[belong[tmp1]]==Genshit) for(int i=belong[tmp1]+1;i<=now;i++) ans+=contribution[i];
		else if(maxn[belong[tmp1]]>Genshit) {
			int p=-1;lst=0;for(int i=1;i<=belong[tmp1];i++) lst=max(lst,maxn[i]);
			for(int i=belong[tmp1]+1;i<=now;i++) {
				contribution[i]=0;
				if(maxn[i]>=lst) {
					for(int j=L[i];j<=R[i];j++) if(a[j]>lst) lst=a[j],contribution[i]++;
					p=i;break;
				}
			}
			if(p!=-1) for(int i=p;i<=now;i++) ans+=contribution[i];
		}
		else if(maxn[belong[tmp1]]<Genshit) {
			lst=0;for(int i=1;i<=belong[tmp1];i++) lst=max(lst,maxn[i]);int nxt=belong[tmp1]+1;
			for(;nxt<=now;nxt++) {
				contribution[nxt]=0;
				for(int i=L[nxt];i<=R[nxt];i++) if(lst<a[i]) lst=a[i],contribution[nxt]++;
				ans+=contribution[nxt];	
			}
		}
		done:;
		write(ans,'\n');
	}
	return signed(0);	
}