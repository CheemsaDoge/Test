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
#define ll long long
#define ri register int
#define rl register long long
int n,m;
struct node {
	int l,r,s;
	bool operator < (const node &h)const {
		if(l!=h.l)return l>h.l;
		return r>h.r;
	}
} tmp;
priority_queue<node>q;

int main() {
	freopen("trader.in","r",stdin);
	freopen("trader.out","w",stdout);
	ri t;
	read(t);
	while(t--) {
		while (!q.empty()) q.pop();
		read(n);
		read(m);
		if(m==1) {
			printf("true\n");
			continue;
		}
		for(ri i=1; i<=m; i++) {
			read(tmp.l);
			read(tmp.r);
			read(tmp.s);
			q.push(tmp);
		}
		tmp=q.top();
		q.pop();
		while(!q.empty()) {
			node tmp1;
			tmp1=q.top();
			q.pop();
			if(tmp.l==tmp1.l)
				if(tmp.r==tmp1.r) {
					if(tmp.s!=tmp1.s) {
						printf("false\n");
						goto END;
					}
				} else if(tmp.r<tmp1.r)
					q.push((node) {
					tmp.r+1, tmp1.r, tmp1.s - tmp.s
				});
			tmp = tmp1;
		}
		printf("true\n");
END:
		;
	}
	return 0;
	//À¬»øDLH(
}
