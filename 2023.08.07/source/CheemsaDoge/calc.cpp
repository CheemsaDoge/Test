#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=1e5+1145;
const int INF=2147483647ll;
#define db double
#define ll long long int 
#define ri register int
int a,b,p,n;ll ans;
int main()
{
	char a;
	while(1)
	{
		cin>>a;
		cout<<int(a)<<endl;
	}
}
