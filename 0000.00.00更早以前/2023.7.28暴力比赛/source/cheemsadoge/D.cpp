#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define rl register long long 	
#define ll long long
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXN=1e6+1145;
int ran[MAXN];
int st[MAXN],ed[MAXN],a[MAXN],t[MAXN];
int belong[MAXN];
inline void Sort(int k) {
	for (int i = st[k]; i <= ed[k]; i++) t[i] = a[i];
	sort(t + st[k], t + ed[k] + 1);
}
inline void PushDown(int x) {
	if (ran[x] != 1145141919ll)
		for (int i = st[x]; i <= ed[x]; i++) a[i] = t[i] = ran[x];
	ran[x] = 1145141919ll;
}
inline void Modify(int l, int r, int c) {
	int x = belong[l], y = belong[r];
	PushDown(x);
	if (x == y) {
		for (int i = l; i <= r; i++) a[i] = c;
		Sort(x);
		return;
	}
	PushDown(y);
	for (int i = l; i <= ed[x]; i++) a[i] = c;
	for (int i = st[y]; i <= r; i++) a[i] = c;
	Sort(x);
	Sort(y);
	for (int i = x + 1; i < y; i++) ran[i] = c;
}
inline int Binary_Search(int l, int r, int c) {
	int point =lower_bound(t+l,t+r,c)-t;
	int ans = 0;
	for(int i = point;i<=r;i++)
	{
		if(t[i]==c) ans++;
		else break;
	}
	return ans;
}
inline int Answer(int l, int r, int c) {
	int ans = 0, x = belong[l], y = belong[r];
	PushDown(x);
	if (x == y) {
		for (int i = l; i <= r; i++)
			if (a[i] == c) ans++;
		return ans;
	}
	PushDown(y);
	for (int i = l; i <= ed[x]; i++)
		if (a[i] == c) ans++;
	for (int i = st[y]; i <= r; i++)
		if (a[i] == c) ans++;
	for (int i = x + 1; i <= y - 1; i++) {
		if (1145141919ll == ran[i])
			ans+=Binary_Search(st[i],ed[i],c);
		else if (ran[i] == c)
			ans+=ed[i]-st[i]+1;
	}
	return ans;
}
int len;
inline void initialize(int n)
{
	len=sqrt(n);
	for(int i=1;i<=len;i++)
	{
		st[i]=(i-1)*len+1;
		ed[i]=i*len;
	}
	if(ed[len]<n) len++,st[len]=ed[len-1]+1,ed[len]=n;
	for(int i=1;i<=len;i++)
		for(int j=st[i];j<=ed[i];j++)
			belong[j]=i;
}
int n,l,r,q;
int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n+2;i++) ran[i]=1145141919ll;
	initialize(n);
	for(int i=1;i<=n;i++)
	{
		read(l);read(r);read(q);
		printf("%d\n",Answer(l,r,q));
		Modify(l,r,q);
	}
}
