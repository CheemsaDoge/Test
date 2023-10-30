/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template <typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
template <typename T> inline T abs(const T _a) {return _a<0?-_a:_a;}
const int MAXM=1e5+10;const int MAXN=4e6+10;const int INF=2147483647ll;//2^31-1
const int MAXK=3e4;
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int cntAll[MAXN];
int cntSingle[MAXN],tag[MAXN];
int n,p,k;
int main(){
	read(n);read(k);read(p);
	ll ans=0;
	int now=0;
	for(int i=0;i<n;i++){
		int a,b;
		read(a);read(b);
		ans+=cntAll[a];
		cntAll[a]++;
		if(b<=p) now++;
		else {
			if(tag[a]!=now) tag[a]=now,cntSingle[a]=0;
			ans-=cntSingle[a];
			cntSingle[a]++;
		}
	}
	write(ans);
	return 0;
}
