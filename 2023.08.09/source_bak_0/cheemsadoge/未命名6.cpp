/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXsP=40655;const int INF=2147483647ll;//2^31-1
#define db double
int fast_pow(int a,int x,int p)
{
	int no=a,ans=1;
	while(x){
		if(x&1) ans=1ll*ans*no%p;
		x>>=1;no*=no;
	}
	return ans;
}
int a,b,p;
int main() {
	while(1)
	{
		read(a);read(b);
		printf("%d\n",fast_pow(a,b,1000000000));
	}
}
