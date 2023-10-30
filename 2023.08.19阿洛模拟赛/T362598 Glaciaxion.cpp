/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=2e6+1145;const int INF=2147483647ll;//2^31-1
#define db double
#define re register
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("No solution")
/*---------------------------------pre------------------------------------*/
//f... ccf 
//luogu写暴戾语言会禁赛吗（吓 
int a[MAXN];
int now;
char in;
int main() {
	int n,m;
	read(n);read(m);
	in=char(getchar());
	if(in=='Y') {
		pn;return 0;
	}
	else for(int i=1;i<=m;i++)
	{
		if(in=='N') a[i]=++now;
		else a[i]=1;
		if(now>n) break;
		in=char(getchar());
	}
	if(now>n) {
		pn;return 0;
	}
	else for(int i=1;i<=m;i++) write(a[i]),pk;
}
