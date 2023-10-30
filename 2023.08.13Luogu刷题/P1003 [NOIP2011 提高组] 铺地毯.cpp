/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXT=1e4+1145;const int MAXN=1e4+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int n,a,b,g,k,x,y;
struct ditan {int l,r,up,down;}dt[MAXN];
bool fu(int p) {return dt[p].l<=x&&dt[p].r>=x&&dt[p].down<=y&&dt[p].up>=y;}
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a),read(b),read(g),read(k);
		dt[i].l=a; dt[i].r=a+g;
		dt[i].down=b; dt[i].up=b+k;
	}
//	2 5
//	1 4
	read(x);read(y);
	while(n--) if(fu(n+1)) {write(n+1);return 0;}
	write(-1);
}
