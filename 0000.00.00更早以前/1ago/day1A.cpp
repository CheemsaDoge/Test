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
ll gcd(ll a,ll b)
{
	if(a<b)	swap(a,b);
	if(!b)	return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b)
{
	return a*b/(gcd(a,b));
}
ll a,b,c;

int main(){
	read(a);
	read(b);
	read(c);
	ll d=lcm(a,b);
	printf("%lld",lcm(d,c));
}
