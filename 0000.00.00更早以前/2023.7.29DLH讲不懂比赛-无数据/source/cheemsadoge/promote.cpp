#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
#define INF (1 << 30)
int n;
struct treap {
	int l[maxn], r[maxn], val[maxn], rnd[maxn], size[maxn], w[maxn];
	int sz, ans, rt;
	inline void pushup(int x) {size[x] = size[l[x]] + size[r[x]] + w[x];}
	inline int newP(int x){sz++;val[sz]=x;rnd[sz]=rand();size[sz]=1;w[sz]=1;return sz;}
	void lrotate(int &k) {int t = r[k];r[k] = l[t];l[t] = k;size[t] = size[k];pushup(k);k = t;}
	void rrotate(int &k) {int t = l[k];l[k] = r[t];r[t] = k;size[t] = size[k];pushup(k);k = t;}
	void insert(int &k, int x) {
		if (!k) {k=newP(x);return;}
		size[k]++;
		if (val[k] == x) w[k]++;
		else if (val[k] < x) {insert(r[k],x);if(rnd[r[k]] < rnd[k]) lrotate(k);} 
		else {insert(l[k],x);if(rnd[l[k]] < rnd[k]) rrotate(k);}
	}
	bool del(int &k, int x) {
		if (!k) return false;
		if (val[k] == x) {
			if (w[k] > 1) {w[k]--;size[k]--;return true;}
			if (l[k] == 0 || r[k] == 0) {k=l[k]+r[k];return true;} 
			else if (rnd[l[k]]<rnd[r[k]]) {rrotate(k);return del(k,x);} 
			else {lrotate(k);return del(k, x);}
		} 
		else if (val[k]<x) {
			bool succ=del(r[k], x);
			if(succ) size[k]--;
			return succ;
		} 
		else {
			bool succ=del(l[k],x);
			if(succ) size[k]--;
			return succ;
		}
	}
	int queryrank(int k, int x) {
		if (!k) return 0;
		if (val[k] == x) return size[l[k]] + 1;
		else if (x > val[k]) return size[l[k]] + w[k] + queryrank(r[k], x);
		else return queryrank(l[k], x);
	}
	int querynum(int k, int x) {
		if (!k) return 0;
		if (x <= size[l[k]]) return querynum(l[k], x);
		else if (x > size[l[k]] + w[k]) return querynum(r[k], x - size[l[k]] - w[k]);
		else return val[k];
	}
	void querypre(int k,int x) {
		if (!k) return;
		if (val[k]<x) ans=k,querypre(r[k], x);
		else querypre(l[k], x);
	}
	void querysub(int k, int x) {
		if (!k) return;
		if (val[k]>x) ans=k,querysub(l[k], x);
		else querysub(r[k],x);
	}
}T;
int opt, x;
int main() {
	freopen("promote.in","r",stdin);
	freopen("promote.out","w",stdout);	
	srand(time(0));
	scanf("%d", &n);
	int a,b,ans=INF,sum=0;
	for (int i = 1; i <= n; i++) {
		scanf("%d",&x);
		T.ans = 0,T.querypre(T.rt, x),a=T.val[T.ans];
		T.ans = 0,T.querysub(T.rt, x),b=T.val[T.ans];
		ans=abs(a-x);
		ans=min(abs(b-x),ans);
		sum+=ans;
		T.insert(T.rt,x);
	}
	printf("%d",sum);
	return 0;
}

