/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=1e3+10;const int MAXN=1e6+10;const int INF=2147483647ll;//2^31-1
#define db double
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("no solution")
/*---------------------------------pre------------------------------------*/
int f[50][70];
bool a[50];
int dfs(bool limit,bool lead,int pos,int cha)
{
	if(!pos) return cha>=30;
	if(!limit&&!lead&&f[pos][cha]) return f[pos][cha];
	int res=0,up=limit?a[pos]:1;
	for(int i=0;i<=up;i++) res+=dfs(limit&(i==a[pos]),lead&(i==0),pos-1,cha+(i==0?(lead?0:1):-1));
	if(!limit&&!lead) f[pos][cha]=res;
	return res;
}
int solve(int x)
{
	int tot=0;
	while(x) a[++tot]=x%2,x>>=1;
	return dfs(1,1,tot,30);
}
int main()
{
	freopen("ton.in","r",stdin);
	freopen("ton.out","w",stdout);
	int l,r;
	read(l),read(r);
	write(solve(r)-solve(l-1));
}
