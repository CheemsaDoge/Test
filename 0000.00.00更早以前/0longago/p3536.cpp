#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e7+1145;
inline ll read()
{
    ll io=0;
	char in=getchar();
    while(in<'0'||in>'9')in=getchar();
    while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
    return io;
}
const int N = 1e6 + 5;
int n, m, cnt, buc[N];
ll tot, ans[N], cur[N];
int main(){
	cin >> m;
	for(int i = 1; i <= m; i++) buc[read()] = 1;
	n = read();
	for(int i = 1; i <= n; i++) {
		int k = read();
		if(cur[k] * k >= N) {tot += k; continue;}
		int rest = k;
		while(rest) {
			int p = (++cur[k]) * k;
			if(p >= N) break;
			if(buc[p] == 1) ans[++cnt] = tot + k - rest + 1;
			if(buc[p] >= 0) buc[p] = -1, rest--;
		} tot += k;
	} cout << cnt << endl;
	for(int i = 1; i <= cnt; i++) printf("%d\n",ans[i]);
	return 0;
}
