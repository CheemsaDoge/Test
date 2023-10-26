#include<bits/stdc++.h>
template <typename type1> inline void read(type1 &_x) {
	_x=0;
	type1 _w=1,_ch=getchar();
	while(!isdigit(_ch)&&_ch!='-')_ch=getchar();
	if(_ch=='-')_w=-1,_ch=getchar();
	while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();
	_x=_x*_w;
}
template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {
	read(_x), read(args...);
}
template <typename type1> inline void write(type1 _x) {
	static char _q[65];
	int _cnt=0;
	if(_x<0) putchar('-'),_x=-_x;
	_q[++_cnt]=char(_x%10),_x/=10;
	while(_x) _q[++_cnt]=char(_x%10),_x/=10;
	while(_cnt) putchar(_q[_cnt--]+'0');
}
template <typename types,typename ... Args> inline void write(types _x, Args ... args) {
	write(_x),putchar(' '),write(args...);
}
int main() {
    int a,b;read(a,b);write(a+b);
}
