#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ri register int
#define rl register long long 
#define ll long long 
ll th[2200][2050];
ll s[2200][2050];

int main()
{
	freopen("comb1.in","r",stdin);
	freopen("comb1.out","w",stdout);
	ri t,k;
	read(t);
	read(k);
	th[0][0]=1;
	for(int i=1;i<=2001;i++)
	{
		for(int j=1;j<=i;j++)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			th[i][j]=(th[i-1][j]+th[i-1][j-1])%k;
			if(!th[i][j])	s[i][j]++;
		}
		s[i][i+1]=s[i][i];
	}
	ri x,y;
	while(t--)
	{
		read(x);
		read(y);
		printf("%lld\n",s[x+1][min(y+1,x+1)]);
	}
}
