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
const int MOD=998244353;
ll th[2200][2050];
ll s[2200][2050];
ll jiecheng(int n)
{
	rl sum=1;
	for(ri i=1;i<=n;i++)
	{
		sum*=i;
		if(sum>MOD)
			sum-=MOD*(sum/MOD);
	}
	return sum;
}


int main()
{
	rl sum=1;
	freopen("y.in","w",stdout);
	cout<<5000<<endl;
	for(int i=1;i<=5000;i++)
	{
		cout<<i<<endl;
	}
}
