#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define maxn 2023
#define INF (1 << 30)
int n,m;
int a[maxn][maxn];
int b[maxn][maxn];
int gcd(int x,int y)
{
	if(x<y) swap(x,y);
	return y?gcd(y,x%y):x;
}
int nxt(int x,int y)
{
	b[x][y]=gcd(a[x][y],gcd(a[x-1][y],gcd(a[x+1][y],gcd(a[x][y+1],a[x][y-1]))));
}
int gggcd=0,ans=INF;
int x,y;
int main() {
//	freopen("gcd.in","r",stdin);
//	freopen("gcd.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) read(a[i][j]),gggcd=gcd(a[i][j],gggcd);
		a[i][0]=a[i][1],a[i][n+1]=a[i][n];
	}
	if(gggcd!=1){printf("-1\n");return 0;}
	read(x),read(y);
	if(a[x][y]==1) {printf("0\n");return 0;}
	for(int i=1;i<=m;i++) a[0][i]=a[1][i],a[n+1][i]=a[n][i];
	int ss;
	nxt(x,y);
	if(b[x][y]==1) {printf("1");return 0;}
	int st=1,lun=1;
	while(b[x][y]!=1)
	{
		for(int i=max(1,st);i<=min(x+st,n);i++)
		{
			for(int j=max(1,st);j<=min(m,y+st);j++)
			{
				ss=abs(x-i)+abs(y-j);
				if(ss>ans) continue;
				nxt(i,j);
				if(b[i][j]==1) ans=min(ans,ss);
				st=ans;
			}
		}
		lun++;
	}
	printf("%d",ans+lun);
	return 0;
}
