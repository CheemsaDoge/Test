/*P1286 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rl register unsigned long long
#define ri register int
bool cmp(int x,int y)
{
	return x>y;
}
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
ll a[55];
int main() 
{
	ri n;
	for(ri i=1;i<=n*(n-1)/2+1;i++)
		read(a[i]);
	sort(a+1,a+n*(n-1)/2+2,cmp);
	
}
