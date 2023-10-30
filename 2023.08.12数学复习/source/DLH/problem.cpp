/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXT=1e4+1145;const int MAXN=2e3+2;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int th[MAXN][MAXN],s[MAXN][MAXN];
int maxn,maxm,t,k;
int n[MAXT],m[MAXT];
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);	
	th[0][0]=1;
	read(t);read(k);
    //goto h:
    for(int i=1;i<=t;i++) read(n[i]),read(m[i]),maxn=max(maxn,n[i]),maxm=max(maxm,m[i]);
	for(int i=1;i<=maxn;i++)
	{
		th[i][0]=1;
		for(int j=0;j<=i;j++)
		{
			th[i][j]=0;
			th[i][j]+=j-1>=0?th[i-1][j-1]:0;
			th[i][j]+=j<=i?th[i-1][j]:0;
			th[i][j]%=k;
		}
	}
	for(int i=2;i<=maxn;i++)
	{
    	for(int j=1;j<=maxm;j++)
		{
        	s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        	if(!th[i][j]&&j<=i) s[i][j]+=1;
        }
		s[i][i+1]=s[i][i];//!!!!
    }
    for(int i=1;i<=t;i++) write(s[n[i]][m[i]]),putchar('\n');
	return 0;
}
