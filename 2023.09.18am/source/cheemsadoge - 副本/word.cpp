/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))x=(x<<3)+(x<<1)+(_ch^'0'),_ch=getchar();x=x*_w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int _cnt=0;if(x<0)putchar('-'),x=-x;_q[++_cnt]=char(x%10),x/=10;while(x)_q[++_cnt]=char(x%10),x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=1e6+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
//[[maybe_unused]]
inline void _File()
{
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
}
int n,cnt,last;
int a[MAXN],h[MAXN],fail[MAXN];
int tr[MAXN][28],sz[MAXN];
char s[MAXN];
inline void insert(char *_s,int x){
	int u=0,len=strlen(_s+1);
	for(int i=1;i<=len;i++){
		if(!tr[u][_s[i]-'a']) tr[u][_s[i]-'a']=++cnt;
		u=tr[u][_s[i]-'a'];
		sz[u]++;
	}
	a[x]=u;
}
inline void build(){
	int i,head=0,tail=0;
	for(i=0;i<26;i++) if(tr[0][i]) h[++tail]=tr[0][i];
	while(head<tail){
		int x=h[++head];
		for(i=0;i<26;i++) 
			if(tr[x][i]){
				h[++tail]=tr[x][i];
				fail[tr[x][i]]=tr[fail[x]][i];
			}
			else tr[x][i]=tr[fail[x]][i];
	}
}
int main(){
//	_File();
	read(n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		insert(s,i);
	}
	build();
	for(int i=cnt;i>=0;i--) sz[fail[h[i]]]+=sz[h[i]];
	for(int i=1;i<=n;i++) write(sz[a[i]]),pc;
	return 0;
}

