//#include<bits/stdc++.h>
//using namespace std;
//#define ri register int
//#define rl register long long 
//#define ll long long
//
//short a[1024];
//short b[1024];
//short in[1024];
//short res[1024];
//inline void clear()
//{
//	memset(res,0,1024);
//}
//short* mul(short*x,short*y)
//{
//	clear();
//	ri xn;
//	for(xn =1023;xn>=0;xn--)
//		if(x[xn]!=0)	break;
//	ri yn;
//	for(yn =1023;yn>=0;yn--)
//		if(y[yn]!=0)	break;
//	for(ri i=0;i<=xn;i++)
//	{
//		for(ri j=0;j<=yn;j++)
//			res[i+j]+=y[j]*x[i];
//	}
//	ri i=0;
//	while(i<=1022)
//	{
//		if(res[i]>=10)
//			res[i+1]=res[i]/10;
//		res[i]%=10;
//		i++;
//	}
//	return res;
//}
//void read(int x)
//{
//	if(x==114514)
//		for(ri i=0;;i++)
//			if(a[i]=getchar()==)
//	else
//		for(int i=0;x;i++)
//		{
//			in[i]=x%10;
//			x/=10;
//		}
//}
//short* add(short*x,short*y)
//{
//	clear();
//	ri xn;
//	for(xn =1023;xn>=0;xn--)
//		if(x[xn]!=0)	break;
//	ri yn;
//	for(yn =1023;yn>=0;yn--)
//		if(y[yn]!=0)	break;
//	for(ri i=0;i<=xn;i++)
//		res[i]+=y[i]+x[i];
//	ri i=0;
//	while(i<=1022)
//	{
//		if(res[i]>=10)
//			res[i+1]=res[i]/10;
//		res[i]%=10;
//		i++;
//	}
//	return res;
//}
//
//
//int main() {
//	ri n,m;
//	scanf("%d%d",&n,&m);
//	
//}
#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define next nxt
#define re register
#define il inline
const int N = 50 + 5;
using namespace std;
int max(int x,int y){return x > y ? x : y;}
int min(int x,int y){return x < y ? x : y;}

int n,m;
int S[N][N][105],L[N][N];

il int read()
{
	int f=0,s=0;
	char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f |= (ch=='-');
	for(; isdigit(ch);ch=getchar()) s = (s<<1) + (s<<3) + (ch^48);
	return f ? -s : s;
}

il void calc(int x,int y)
{
	L[x][y] = max(L[x-1][y-1],L[x-1][y]);
	for(re int i=1;i<=L[x][y];i++)
	{
		S[x][y][i] += S[x-1][y-1][i] + y * S[x-1][y][i];
		S[x][y][i+1] += S[x][y][i] / 10;
		S[x][y][i] %= 10;
	}
	if(S[x][y][L[x][y]+1] > 0) L[x][y]++;//看看能不能更新最高位
	while(S[x][y][L[x][y]] >= 10)
	{
		S[x][y][L[x][y]+1] = S[x][y][L[x][y]] / 10;
		S[x][y][L[x][y]] %= 10;
		L[x][y]++;
	}
}

signed main()
{
	freopen("piggy.in","r",stdin);
	freopen("piggy.out","w",stdout);
	S[0][0][1] = 1 , L[0][0] = 1;
	n = read() , m = read();
	if(!m || m > n) return printf("0"),0;//特判等于0的情况
	for(re int i=1;i<=n;i++)
		for(re int j=1;j<=min(i,m);j++)
			calc(i,j);
	for(re int i=L[n][m];i>=1;i--) cout << S[n][m][i];
	return 0;
}
