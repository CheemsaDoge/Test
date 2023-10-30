/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=2012;const int INF=2147483647ll;//2^31-1
#define ll long long 
int th[MAXN][MAXN],s[MAXN][MAXN];
int a,b,p,t,k,n,m;
int main() {
	freopen("problem.in","r",stdin);
	freopen("problem.out","w",stdout);	
	th[0][0]=1;
	read(t);read(k);
	for(int i=1;i<=2001;i++)	//slow(2e6) or goto h?
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
	for(int i=2;i<=2000;i++)
	{
    	for(int j=1;j<=2001;j++)
		{
        	s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        	if(!th[i][j]&&j<=i) s[i][j]+=1;
        }
		s[i][i+1]=s[i][i];//!!!!
    }
    //goto h:
	while(t--){
		read(n);read(m);
		printf("%lld\n",s[n][m]);	
	}
	return 0;
}
/*O(max(2e6,n^2))*/
