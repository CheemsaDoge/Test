#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define p 19260817

char s[200100];
int n,m,Q,a[200100];

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
	freopen("genshin.in","r",stdin);
	freopen("genshin.out","w",stdout);
		read(n),read(m);
		for(ri i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(ri j=m+1;j<=2*m;j++) s[j]=s[j-m];
			int l=1,r=2;
			while(r<=m)
			{
				for(ri k=0;k<m;k++)
				{
					if(s[l+k]<s[r+k])
					{
						r+=k;
						break;
					}
					if(s[l+k]>s[r+k])
					{
						int tmp=l;
						l=r;
						r=max(tmp+k,r);
						break;
					}
				}
				++r;
			}
			a[i]=0;
			for(ri j=0;j<m;j++)
			{
				a[i]=(29ll*a[i]+s[l+j]-'a'+1)%p;
			}
		}
		read(Q);
		int x,y;
		while(Q--)
		{
			read(x),read(y);
			if(a[x]==a[y]) printf("Yes\n");
			else printf("No\n");
		}
	return 0;
}


