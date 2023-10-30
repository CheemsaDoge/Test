/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=1e6+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n;
unsigned long long ans;
int cnt;
int r[MAXN];
int a[MAXN],b[MAXN];
inline void Datain()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
}
stack<int>p;
inline void Work()
{
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1,x=a[1];x<=a[n]||!p.empty();)
	{
		while(a[i]==x) p.push(i++);
		if(!p.empty())
		{
			if(x!=a[p.top()]) r[++cnt]=x-a[p.top()];
			p.pop(),++x;
		}
		else x=a[i];
	}
	sort(r+1,r+1+cnt,greater<int>());
	for(int i=1;i<=cnt;i++) ans=ans+1ull*r[i]*b[i];
}
int main()
{
	freopen("dlh.in","r",stdin);
	freopen("dlh.out","w",stdout);
	Datain();
	Work();
	write(ans);
	return 0;
}
