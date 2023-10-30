#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rl register long long
#define ri register int
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const ll N = 100;
int main() 
{
	rl a,b,c;
	freopen("5.5.in","r",stdin);
	freopen("5.5.out","w",stdout);
    read(a);
    read(b);
    printf("%lld",(a-1)*(b-1)-1);
}
