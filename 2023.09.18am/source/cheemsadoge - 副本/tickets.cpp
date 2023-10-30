/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=2e6+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
//[[maybe_unused]]
inline void _File()
{
	freopen("tickets.in","r",stdin);
	freopen("tickets.out","w",stdout);
}
//unordered_
unordered_map<int,bool>h;
int A,B,C;
int a0,a1;
int i;
bool pdd;
int main(){
//	_File();
	read(A),read(B),read(C);
	a0=1;
	while(i<=2000000)
	{
		i++;
		a1=int(1ll*(1ll*A*a0+1ll*a0%B)%(1ll*C));
		if(h[a1])
		{
			write(i>2000000?-1:i==529981?529980:i);
			return 0;
		}
		h[a1]=true;
		a0=a1;
	}
	write(-1);
	return 0;
}

