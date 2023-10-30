#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
#define ll long long
#define ri register int
#define rl register long long
ll a,b;
int main() {
//	std::ios::sync_with_stdio(0);
	freopen("jlu.in","r",stdin);
	freopen("jlu.out","w",stdout);
	read(a);read(b);
	printf("%lld",(ll)(a-1)*(b-1)-1);
}
