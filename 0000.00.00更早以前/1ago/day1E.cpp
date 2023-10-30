#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+1145;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ll long long int
#define rl register long long int
#define ri register int
int n,t=0;
int c[MAXN];
int main()
{
	read(n);
    ri x;
    for(ri i=1;i<=n;i++)
	{
        read(x);
		t=max(t,x);
        ri m=sqrt(x);
        for(ri i=1;i<=m;i++)
            if(x%i==0)
			{
                c[i]++;
                if(x!=i*i) c[x/i]++;
            }
    }
    x=t;
    for(ri i=1;i<=n;i++)
	{
        while(c[x]<i) x--;
        printf("%d\n",x);
    }
}
//P1414 
