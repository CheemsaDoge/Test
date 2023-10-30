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
const int MAXN=2e6+1145;
int sum=1,n;
void change(int y[], int len) {
	int rev[MAXN];
	for (int i = 0; i < len; ++i) {
		rev[i] = rev[i >> 1] >> 1;
		if (i & 1) {
			rev[i] |= len >> 1;
		}
	}
	for (int i = 0; i < len; ++i) {
		if (i < rev[i]) {
			swap(y[i], y[rev[i]]);
		}
	}
	return;
}


int y[MAXN];
int main() {
	freopen("ap.in","r",stdin);
	freopen("ap.out","w",stdout);
	read(n);
	for(int i=2; sum<=n; i++)
		sum*=2;
	for(int i=0; i<sum; i++) {
		y[i]=i;
	}
	change(y,sum);
	for(int i=0; i<=sum; i++) {
		if((y[i])<=n&&y[i])printf("%d ",y[i]);
	}
}
