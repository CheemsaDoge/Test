/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=2e5+1145;const int INF=2147483647ll;//2^31-1
#define db double
#define re register
#define ll long long
#define pc putchar('\n')
#define pn puts("Orz, I cannot find x!")
/*---------------------------------pre------------------------------------*/
//f.k ccf
int v,t;
struct point {
	int num,high;
};
bool operator <(point a,point b)
{
	if(a.high==b.high) return a.num>b.num;
	return a.high<b.high;
}
priority_queue<point>a;
int main() {
	int n,T;
	read(n);read(T);
	point s;
	for(int i=1;i<=n;i++)
	{
		s.num=i;
		read(v),read(t);
		int high=(T-t)*v;
		s.high=high;
		a.push(s);
	}
	write(a.top().num);
}
