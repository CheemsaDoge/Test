/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=1e6+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
[[maybe_unused]]inline void _File(){
//	freopen("x.in","r",stdin);
	freopen("x.in","w",stdout);
}

int main(){
	_File();
	int n=10;
	int k=rand()%10+1;
	int A=rand()%1000;
	int B=rand()%1000;
	int C=rand()%1000;
	write(n);
	pk;
	write(k);
	pk;
	write(A);
	pk;
	write(B);
	pk;
	write(C);
	pc;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			write(rand()%2);pk;
		}
		pc;
	}
	return 0;
}


