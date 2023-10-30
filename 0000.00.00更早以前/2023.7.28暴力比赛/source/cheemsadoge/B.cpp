#include<bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T> inline void read(T &x) {
	x=0;T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;
}
const int MAXN=5e5+1145;int opt,l,r,c;
ll pt[MAXN][2],n,value[MAXN];
inline ll ask(int i) {
	int n=i;ll sum=0,sum2=0;
	while(i) sum+=pt[i][0],sum2+=pt[i][1],i-=i&-i;
	sum*=(n+1);
	return sum-sum2;
}
inline void add(int i,int x) {
	int v=i*x;
	while(i<=n)	pt[i][0]+=x,pt[i][1]+=v,i+=i&-i;
}
inline void Initialize() {
	for(int i=1; i<=n; i++) read(value[i]);
	for(int i=1; i<=n; i++) add(i,value[i]-value[i-1]);
}

int main() {
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	read(n);Initialize();
	for(int i=1; i<=n; i++) {
		read(opt);read(l);read(r);read(c);
		if(opt==0) add(l,c),add(r+1,-c);
		else printf("%lld\n",(ask(r)-ask(l-1))%(c+1));
	}
}
