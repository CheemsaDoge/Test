#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define rl register long long
#define ll long long
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
const int MAXN=1e6+1145;
ll a[MAXN],add_[MAXN];
int pos[MAXN],L[MAXN],R[MAXN];int len;
#define p pos[l]
#define q pos[r]
inline void add(int l,int r,int v) {
	if(p==q) {
		for(int i=l; i<=r; i++) a[i]+=v;
		return ;
	}
	for(int i=p+1; i<=q-1; i++) add_[i]+=v;
	for(int i=l; i<=R[p]; i++) a[i]+=v;
	for(int i=L[q]; i<=r; i++) a[i]+=v;
}
inline ll ask(int l,int r,ll v) {
	ll ans=-1;
	for(int i=l; i<=r; i++) 
		if(a[i]+add_[pos[i]]<v&&ans<a[i]+add_[pos[i]]) {
			ans=a[i]+add_[pos[i]];
			if(ans==v-1) break;
		}
	return ans;
}
inline void initialize(int n) {
	len=sqrt(n);
	for(int i=1; i<=len; i++) L[i]=(i-1)*len+1,R[i]=i*len;
	if(R[len]<n) len++,L[len]=R[len-1]+1,R[len]=n;
	for(int i=1; i<=len; i++)for(int j=L[i]; j<=R[i]; j++)pos[j]=i;
}
#undef q 
#undef p
int opt,n,l,r;ll c;
int main() {
	freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	read(n);for(int i=1; i<=n; i++) read(a[i]);initialize(n);
	for(int i=1; i<=n; i++) {
		read(opt);
		read(l);
		read(r);
		read(c);
		if(opt==0) add(l,r,c);
		else printf("%d\n",ask(l,r,c));
	}
}
