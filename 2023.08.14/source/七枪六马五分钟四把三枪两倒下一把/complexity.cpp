/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXL=2e2+5;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int t,l,WA,RA;
string timer;
string code[MAXL];
int get_c(int &x,string c) {//get nums
	int ans=0;
	while(c[x]<'0' || c[x]>'9'&&x<c.size()) {if(c[x]=='n') {++x;return -1;}++x;}
	while(c[x]>='0' && c[x]<='9'&&x<c.size()) {ans*=10;ans+=c[x]-48;++x;}
	return ans;
}
bool vis[26]={0};
int check() {
	memset(vis,0,sizeof(vis));
	int res=0,now=0;
	int a,b,x;
	queue<int>nums;
	int flag=-1;
	bool ef[26]={0};
	for(int i=1; i<=l; i++) {
		if(code[i][0]=='E') {
			if(nums.empty()) return -1;
			int letter=nums.front();nums.pop();
			vis[letter]=false;
			if(flag==letter) flag=-1;
			if(ef[letter]) {ef[letter]=false;now--;}
		}
		else if(code[i][0]=='F') {
			int letter=code[i][2]-'a';
			if(vis[letter]) return -1;
			nums.push(letter);
			vis[letter]=true;
			x=4;
			a=get_c(x,code[i]);
			b=get_c(x,code[i]);
			if(b==-1) {
				if(flag==-1) {
					now++;
					res=max(res,now);
					ef[letter]=true;
				}
			}
			if((a>b&&b!=-1)||(a==-1&&b!=-1)) {
				if(flag==-1) flag=letter;
			}
		}
	}
	if(!nums.empty()) return -1;
	return res;
}
int getWA() {//get 明's 答案 
	int res=0,x=3;
	if(timer[2]=='n') res=get_c(x,timer);
	else res=0;
	return res;
}

int main() {
	freopen("complexity.in","r",stdin);
	freopen("complexity.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		read(l);
		getline(cin,timer);
		WA=getWA();
		for(int i=1; i<=l; i++) getline(cin,code[i]);
		RA=check();
		if(RA==-1) puts("ERR");
		else if(RA==WA) puts("Yes");
		else puts("No");
	}
}
