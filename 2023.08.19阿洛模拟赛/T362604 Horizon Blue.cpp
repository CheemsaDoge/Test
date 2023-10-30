/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=2e6+1145;const int INF=2147483647ll;//2^31-1
#define db double
#define re register
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("No solution")
/*---------------------------------pre------------------------------------*/
//f... ccf 
//luogu写暴戾语言会禁赛吗（吓 
inline int abss(int u){
	return u<0?abs(u)+100000:u;
}
int sum;
unordered_multiset<int>a[MAXN];
queue<int>fk;
bool vis[MAXN];
int main() {
	int n,k,b,op;
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(op);read(k);read(b);
		k=abss(k);
		b=abss(b);
		if(op==1){
			a[k].insert(b);
			sum++;
			if(!vis[k]) fk.push(k),vis[k]=1;
		}
		else if(op==2){
//			write(a[k].size());pc;
			write((sum-a[k].size()));pc;
			//(max(int(a[k].count(b)),1))
		}
		else if(op==3){
			while(!fk.empty()){
				int u=fk.front();
				fk.pop();
				if(u==k){
					sum-=a[k].erase(b);
					if(a[k].empty()) vis[k]=0;
				}else{
					vis[u]=false;
					sum-=a[u].size();
					a[u].clear();
				}
			}
			if(vis[k]) fk.push(k);
		}
	}
}
