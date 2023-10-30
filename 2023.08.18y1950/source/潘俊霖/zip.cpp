/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=1e4+1145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
char a[MAXN];
int n,p;
#define getchar() char(getchar())
struct EDGE{
	int u,v,val,nxt;
	bool tr;
}edge[MAXM*4];
int head[MAXN],totr;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
bool vis[MAXN];
priority_queue<char>nums;

unordered_map<char,int>pm;
unordered_map<char,int>my;
void dfs(char u)
{
	if(vis[my[u]]) return;
	vis[my[u]]=true;
	add_edge(my[u],my[u]);
	dfs(a[pm[u]]);
}
int sum;
void putc(char u)
{
	sum++;
	putchar(a[my[u]]);
	putc(a[edge[head[my[u]]].v]);
	if(sum==n) return ;
}
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("zip.in","r",stdin);
	freopen("zip.out","w",stdout);
	read(n);
//	static char in=getchar();
//	while(!(in>'a'&&in<'z')) in=getchar();
	cin>>a;
	char in;
	for(int i=0;i<n;i++)
	{
		in=a[i];
		nums.push(in);
		my[in]=i;
	}
	read(p);
	while(!nums.empty())
	{
		in=nums.top();
		pm.insert(make_pair(in,nums.size()-1));
		nums.pop();
	}
	dfs(a[p]);
	putc(a[p]);
	
}

//1 /lt n /le 2 /times 10^5
