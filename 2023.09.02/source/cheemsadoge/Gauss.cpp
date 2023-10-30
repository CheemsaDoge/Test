/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=1e3+10;const int MAXN=1e3+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("No Solution")
const double eps=1e-9;
/*---------------------------------pre------------------------------------*/
double a[MAXN][MAXN+1];
int n;

void swaph(int x,int y)
{
	for(int i=1;i<=n+1;i++)
		swap(a[x][i],a[y][i]);
}
int ranked;
void work()
{
	int t=0;
	for(int i=1;i<=n;i++)
	{
		t=0;
		for(int j=ranked+1;j<=n;j++)
			if(fabs(a[j][i])>eps) {t=j;break;}
		if(!t) continue;
		ranked++;
		if(ranked!=t) swaph(ranked,t);
		for(int j=1;j<=n;j++)
		{
			if(j==ranked) continue;
			double times=-a[j][i]/a[ranked][i];
			for(int k=i;k<=n+1;k++) a[j][k]+=times*a[ranked][k];
		}
	}
}
double ans[MAXN];
inline bool getnum()
{
	for(int i=ranked+1;i<=n;i++)
	{
		if(fabs(a[i][n+1])>eps)
			return false; //INF
	}
	
	for(int i=1,j=0;i<=n;i++)
	{
		if(fabs(a[i][j+1])>eps)
		{
			j++;
			ans[j]=a[i][n+1]/a[i][j];
		}
		else return false;
	}
	return true;
}
int main()
{
	read(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			scanf("%lf",&a[i][j]);
	work();
	if(getnum()) for(int i=1;i<=n;i++) printf("%.2lf\n",ans[i]);
	else pn;
}
