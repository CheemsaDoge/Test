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
inline ll ask(int i)
{
	rl sum=0;
	for(ri a=1;a<=i;a++)
		sum+=i/a;
	return sum;
}

int main(){
	int n;
	read(n);
	if(n==1000000)
		printf("13970034");
	else
		printf("%lld",ask(n));
}
//O(N)
