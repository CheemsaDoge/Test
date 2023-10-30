#include<bits/stdc++.h>
using namespace std;
#define ri register int

int T,n;
long long k;
int a[100100];
int p[2];

template< typename T >inline void read(T &x)
{
	char c=getchar();x=0;int f=0;
	for(;!isdigit(c);c=getchar()) f|=(c=='-');
	for(;isdigit(c);c=getchar()) x=((x<<3)+(x<<1)+(c^48));
	x=f?-x:x;
}
template< typename T >inline void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10^48);
}

int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	read(T);
	while(T--)
	{
		p[0]=p[1]=0;
		read(n),read(k);
//		getchar();
		for(ri i=1;i<=n;i++) a[i]=getchar()-'0';
		int pre=0;
		for(ri i=1;i<=n;i++)
		{
			if(pre!=a[i])
			{
				p[a[i]]++;
				pre=a[i];
			}
		}
		if(n==1)
		{
			if(k&1) printf("%d\n",a[1]^1);
			else printf("%d\n",a[1]);
			continue;
		}
		if(p[0]==0 && k==1)
		{
			for(ri i=1;i<n;i++) putchar('1');
			putchar('0');putchar('\n');
			continue;
		}
		if(k<=p[0])
		{
			bool flag=0;
			for(ri i=1;i<=n;i++)
			{
				if(a[i]==0)
				{
					if(a[i-1]==1)
					{
						if(k)
						{
							--k;
							putchar('1');
							flag=1;
						}
						else 
						{
							flag=0;
							putchar('0');
						}
					}
					else if(flag) putchar('1');
					else putchar('0');
				}
				else if(a[i])
				{
					putchar('1');
					flag=0;
				}
			}
			putchar('\n');
		}
		else
		{
			for(ri i=1;i<=n;i++) putchar('1');
			putchar('\n');
		}
	}
	return 0;
}


