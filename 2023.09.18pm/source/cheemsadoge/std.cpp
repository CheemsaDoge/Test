/*code by CheemsaDoge*/
#include <bits/stdc++.h>
//using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=2e2;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
[[maybe_unused]]inline void _File(){
	freopen("x.in","r",stdin);
	freopen("x.ans","w",stdout);
}
int ans;
int n,k,A,B,C;
int map[MAXN][MAXN];
int dx[5]={0,1,0,-1,0};
int dy[5]={0,0,1,0,-1};
int dd[5]={0,3,4,1,2};
int dis[MAXN][MAXN][13];

inline int min(const int a,const int b) {return a<b?a:b;}
void dfs(int x,int y,int val,int s,int last)
{
	if(x==y&&x==n) ans=min(ans,val);
	if(val>dis[x][y][s]) return;
	dis[x][y][s]=val;
	if(map[x][y]) s=k,val+=A;
	if(s==0) val+=A+C,s=k;
	if(val>=ans) return ;
	int a=int(1.00*(n-x+n-y-s)/k+0.99)*(A);
	if(val+a>=ans) return ;
	int ad;
	for(int i=1;i<=4;i++) 
	{
		ad=0;
		if(i>=3) ad=B;
		if(x==1&&i==3) continue;
		if(y==1&&i==4) continue;
		if(x==n&&i==1) continue;
		if(y==n&&i==2) continue;
		if(i!=dd[last]) dfs(x+dx[i],y+dy[i],val+ad,s-1,i);
	}
}
int main(){
//	_File();
	read(n);read(k);
	read(A);read(B);read(C);
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) 
		{
			for(int z=0;z<=k;z++) dis[i][j][z]=int(1.00*(i+j-2+z)/k+0.99)*(A+C);
			read(map[j][i]);
		}	ans=(n*2-2)/k*(A+C);
	dfs(1,1,0,k,0);
	write(ans);
	return 0;
}


