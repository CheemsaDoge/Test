#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
#define ll long long
char a[100100];
bool m;
ll k;
void print(int n,int i)
{
	for(int j=1;j<=i;j++)
		putchar('1');
	if(i<n)
		for(int j=i+1;j<=n;j++)
			putchar(a[j]+'0');
	putchar('\n');
}
int is_zero;
int main() {
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	int T,n;
	read(T);
	while(T--)
	{
		read(n);read(k);
		for(int i=1;i<=n;i++) a[i]=getchar()-'0',is_zero+=a[i]?0:1;
		if(n==1)
		{
			if(k&1) printf("%d\n",int(a[1])^1);
			else printf("%d\n",int(a[1]));
			continue;
		}
		if(k==1&&is_zero==0)
		{
			for(int j=1;j<n;j++)
				putchar('1');
			putchar('0');
			putchar('\n');
			continue;
		}
		if(k>=n)
		{
			print(n,n);
			continue;
		}
		int i;
  		for(i=1;i<=n;i++)
		{
			if(k==0&&a[i]==1)
			{
				i-=1;
				break;
			}
			if(a[i]==1) m=1;
			else
			{
				if(!m) k++;
				k--;
				m=0;
			}
		}
		if(i==n+1) print(n,n);
		else print(n,i);
	}
//	return 1;
}
