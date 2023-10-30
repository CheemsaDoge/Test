/*code by 七枪六马五分钟四把三人两倒下一把*/
/*This is a yes pa(对拍) for auto ac chiken*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6;const int MAXN=1e4;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/

int main(){
	srand((int)time(0));
	freopen("keywords.in","w",stdout);
	const int MAXL=50;
	int T=rand()%20+1;
	write(T);pc;
	int n=rand()%MAXN+1;
	while(T--)
	{
		write(n);pc;
		for(int i=1;i<=n;i++)
		{
			int len=rand()%MAXL+1;
			for(int j=1;j<=len;j++)
			{
				int a=(int)rand()%26+97;
				putchar(a);
			}
			pc;
		}
		int len=rand()%MAXM;
		for(int j=1;j<=len;j++)
		{
			int a=(int)rand()%26+97;
			putchar(a);
		}
		pc;
	}
	return 0;
}
