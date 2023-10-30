/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;    //fast input
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
template<typename T> inline void write(T x) {
	static char _q[65];
	int cnt=0;
	if(x<0)putchar('-'),x=-x;
	_q[++cnt]=char(x%10),x/=10;
	while(x)_q[++cnt]=char(x%10),x/=10;
	while(cnt)putchar(_q[cnt--]+'0');
}
const int MAXM=1e5+1145;
const int MAXN=1e7+11145;
const int INF=2147483647ll;//2^31-1
#define ri register int
#define rl register long long
#define ll long long #define pc putchar('\n')
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n,ans,m;
inline int max(const int a,const int b) {
	return a>b?a:b;
}
vector<int> prefix_function(string s) {//小暴力捏
	int _n = (int)s.length();
	vector<int> pi(_n);
	for (int i = 1; i < _n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j]) j = pi[j - 1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}
	return pi;
}
string motherString;
string sonString;
int find_occurrences(string text,string pattern) {
	int maxn=0;
	string cur = pattern + '#' + text;
	int sz1 = (int)text.size(), sz2 = (int)pattern.size();
	vector<int> lps = prefix_function(cur);
	for (int i = sz2 + 1; i <= sz1 + sz2; i++) {
		maxn=max(maxn,lps[i]);
	}
	return maxn;;

}
int main() {
	freopen("symbol.in","r",stdin);
	freopen("symbol.out","w",stdout);
	read(n);
	read(m);
	cin>>motherString;
	for(ri i=1;i<=m;i++)
	{
		cin>>sonString;
		printf("%d\n",find_occurrences(motherString,sonString));
	}
}
