/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-25 10:16:20
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-25 20:26:03
 * @FilePath: \TEST\2023.10.25\D.cpp
 * 大模拟神教万岁
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
typedef long long LL;
const int MAXN=1.5e6;
/*---------------------------------pre------------------------------------*/
int n;
bool f[70][70][70][70];
std::map<int,int>hash;
int a[70];
std::vector<int>vec;
int ans;
signed main() {
	read(n);
	int sum=0;
	for(int i=1;i<=n;i++) {
		read(a[i]);hash[sum+=a[i]]=i;
		vec.push_back(sum);
	}
	if(sum%2) return write(0),1;
	hash[sum]=1;
	for(int st:vec) {
		if(st>=sum/2) break;
		for(int ed:vec) {
			int st1=st+sum/2,ed1=ed+sum/2;
			if(ed<=st) continue;
			if(st1==ed||st==ed1) continue;
			if(ed>sum/2) break;
			if(hash.find(st1)!=hash.end()&&hash.find(ed1)!=hash.end()) {
				if(f[hash[st]][hash[ed]][hash[st1]][hash[ed1]]) continue;
				int tmp[10]={hash[st],hash[ed],hash[st1],hash[ed1]};
				f[tmp[0]][tmp[1]][tmp[2]][tmp[3]]=1;
				while(std::next_permutation(tmp,tmp+4)) {
					f[tmp[0]][tmp[1]][tmp[2]][tmp[3]]=1;
				}
				ans++;
			}
		}
	}
	write(ans);
}