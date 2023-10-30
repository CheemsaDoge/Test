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
//	freopen("P2822_2.in","r",stdin);
	ri t,k;
	th[0][0]=1;
	read(t);
	read(k);
	for(ri i=1;i<=2001;i++)
	{
		th[i][0]=1;
		for(ri j=0;j<=i;j++)
		{
			th[i][j]=0;
			th[i][j]+=j-1>=0?th[i-1][j-1]:0;
			th[i][j]+=j<=i?th[i-1][j]:0;
			th[i][j]%=k;
		}
	}
	for(ri i=2;i<=2000;i++){
    	for(ri j=1;j<=2001;j++){
        	s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
        	if(!th[i][j]&&j<=i) s[i][j]+=1;
        }
		s[i][i+1]=s[i][i];
    }
	ri n,m;
	while(t--)
	{
		read(n);
		read(m);
		printf("%lld\n",s[n][m]);	
	}
}

//1 1
//1 2 1
//1 3 3 1
//1 4 6 4 1
//4
//
//2

