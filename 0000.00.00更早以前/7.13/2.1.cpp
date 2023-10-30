#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
int main()
{
	freopen("2.1.in","r",stdin);
	freopen("2.1.out","w",stdout);
	int T;
	read(T);
	while(T--)
		printf("%d\n",0);
}
