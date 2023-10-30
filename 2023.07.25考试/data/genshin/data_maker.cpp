#include<bits/stdc++.h>
using namespace std;
#define ri register int

char s[200100];
int x[200100],y[200100];

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
	freopen("111.in","r",stdin);
	freopen("5.in","w",stdout);
	int T;
	read(T);
	for(ri o=1;o<=T;o++)
	{
		int n,m,Q,flag=0;
		if(o==5) flag=1;
		read(n),read(m);
		if(flag) printf("%d %d\n",n,m);
		for(ri i=1;i<=n;i++) 
		{
			scanf("%s",s);
			if(flag) 
			{
//				cerr<<"111"<<endl;
				printf("%s\n",s);
			}
		}
		read(Q);
		if(flag) printf("1000\n");
		for(ri i=1;i<=Q;i++)
		{
			read(x[i]),read(y[i]);
//			if(flag) printf("%d %d\n",x[i],y[i]);
		}
		if(flag)
		{
			for(ri i=1;i<=1000;i++)printf("%d %d\n",x[i],y[i]);
		}
	}
	return 0;
}


