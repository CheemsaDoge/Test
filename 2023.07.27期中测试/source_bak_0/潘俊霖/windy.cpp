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
int f[20][20];
vector<int>num;
int dfs(int x,int st,int op) {
	//op=1==,op=0<
	if (!x) return 1;
	if (!op&&~f[x][st]) return f[x][st];
	int maxx=op?num[x]:9;
	int res=0;
	for (int i=0; i<=maxx; i++) {
		if (abs(st-i)<2) continue;
		if (i==0&&st==11) res+=dfs(x-1,11,op&(i==maxx));
		else res+=dfs(x-1,i,op&(i==maxx));
	}
	if(!op) f[x][st]=res;
	return res;
}
inline int solve(int x) {
	for(int i=0;i<=19;i++)
	 	for(int j=0;j<=19;j++)
	 		f[i][j]=-1;
	num.clear();
	num.push_back(-1);
	while(x) {
		num.push_back(x%10);
		x/=10;
	}
	return dfs(num.size()-1,11,1);
}
int a,b;
int main() {
	freopen("windy.in","r",stdin);
	freopen("windy.out","w",stdout);
	read(a);read(b);
	printf("%d",solve(max(a,b))-solve(min(a,b)-1));
}
