#include<bits/stdc++.h>
using namespace std;

const int oo=1e9+7;
const int maxn=2e5+15;
int n,m,cnt;
int ans[maxn],tree[maxn];
struct NODE {
	int x;
	int y;
	int k;
	int id;
	int type;
} q[maxn<<1],q1[maxn<<1],q2[maxn<<1];
void add(int x,int y) {
	while (x<=n) {
		tree[x]+=y;
		x+=x&(-x);
	}
}
int sum(int x) {
	int ans=0;
	while (x) {
		ans+=tree[x];
		x-=x&(-x);
	}
	return ans;
}
void solve(int ql,int qr,int l,int r) {
	if (ql>qr) return;
	if (l==r) {
		for (int i=ql; i<=qr; i++)
			if (q[i].type==2) ans[q[i].id]=l;
		return;
	}
	int mid=(l+r)>>1;
	int p1=0,p2=0;
	for (int i=ql; i<=qr; i++)
		if (q[i].type==1) {
			if (q[i].x<=mid) {
				add(q[i].id,1);
				q1[++p1]=q[i];
			} else q2[++p2]=q[i];
		} else {
			int res=sum(q[i].y)-sum(q[i].x-1);
			if (res>=q[i].k) q1[++p1]=q[i];
			else {
				q[i].k-=res;
				q2[++p2]=q[i];
			}
		}
	for (int i=1; i<=p1; i++) if (q1[i].type==1) add(q1[i].id,-1);
	for (int i=1; i<=p1; i++)
		q[i+ql-1]=q1[i];
	for (int i=1; i<=p2; i++)
		q[i+ql+p1-1]=q2[i];
	solve(ql,ql+p1-1,l,mid);
	solve(ql+p1,qr,mid+1,r);
}
int main() {
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) {
		int x;
		scanf("%d",&x);
		q[++cnt]=(NODE) {
			x,1,oo,i,1
		};
	}
	for (int i=1; i<=m; i++) {
		int x,y,k;
		scanf("%d%d%d",&x,&y,&k);
		q[++cnt]=(NODE) {
			x,y,k,i,2
		};
	}
	solve(1,cnt,-oo,oo);
	for (int i=1; i<=m; i++)
		printf("%d\n",ans[i]);
	return 0;
}
