#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rint register int
inline ll read()
{
    ll io=0;
	char in=getchar();
    while(in<'0'||in>'9')in=getchar();
    while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
    return io;
}
register int f[11][11][90];
rint k,n;
int main()
{
	n=read();
	k=read();
	
}
