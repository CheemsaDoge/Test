#include <bits/stdc++.h>
using namespace std;

template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
int n,p;
long long f[int(2e6+1145)];
long long sum=0;
int main() {
//	freopen("sequence.in","r",stdin);
//	freopen("sequence.out","w",stdout);
	long long qian=1;
	long long shang=2;
	long long xian=5;
	f[0]=1;
	f[1]=1;
	f[2]=2;
	f[3]=5;
	read(n);
	read(p);
	for (int i=4; i<=n; i++) {
		f[i] = (f[i - 1] * (4 * i - 2) / (i + 1));
	}
	printf("%lld",f[n]);
	return 0;
}


/*
C(n-1,2n-2)-C(n,2n-2)
*/
