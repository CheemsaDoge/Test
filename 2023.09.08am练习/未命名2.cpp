#include<bits/stdc++.h>
using namespace std;
const int MAXN=500000;
template <typename T> void read(T &x) {
	x=0;
	T f=1,_ch=getchar();
	while(_ch!='-'&&!isdigit(_ch)) _ch=getchar();
	if(_ch=='-') f=-1,_ch=getchar();
	while(isdigit(_ch)) x=(x<<3)+(x<<1)+(_ch^'0'),_ch=getchar();
	x=x*f;
}
template<typename T> inline void write(T _x) {
	static char _q[65];
	int _cnt=0;
	if(_x<0) putchar('-'),_x=-_x;
	_q[++_cnt]=char(_x%10),_x/=10;
	while(_x)_q[++_cnt]=char(_x%10),_x/=10;
	while(_cnt)putchar(_q[_cnt--]+'0');
}

int main() {
	int n=0;
//	read(n);
	set<int>t;
	t.insert(1);
	t.insert(2);
	t.insert(3);
	for(auto i=t.begin();i!=t.end();i++)
	{
		n++;
		if(n==2) t.erase(i);
		cout<<*i<<endl;
	}
}
