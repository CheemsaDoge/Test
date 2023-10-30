/*code by CheemsaDoge*/
#include <bits/stdc++.h>
//using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=1e6+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define ull unsigned long long
/*---------------------------------pre------------------------------------*/
[[maybe_unused]]inline void _File(){
	freopen("Beads.in","r",stdin);
	freopen("Beads.out","w",stdout);
}

std::set<ull>hash;
const ull sp=13331;
ull s1[MAXN],s2[MAXN],pp[MAXN];
int a[MAXN],n;
ull get1(int l,int r) {return s1[r]-s1[l-1]*pp[r-l+1];}
ull get2(int l,int r) {return s2[l]-s2[r+1]*pp[r-l+1];}
template <typename T> T min(const T _a,const T _b) {return _a<_b?_a:_b;}
int get_ans(int k)
{
	hash.clear();
	for(int i=0;i*k+k<=n;i++) hash.insert(min<ull>(get1(i*k+1,i*k+k),get2(i*k+1,i*k+k)));
	return hash.size();
}
std::vector<int>ans;
int maxn=-1;
int main(){
	_File();
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	pp[0]=1;
	for(int i=1;i<=n;i++) {
		s1[i]=1ull*a[i]+s1[i-1]*sp;
		pp[i]=pp[i-1]*sp;
	}
	for(int i=n;i>=1;i--) s2[i]=a[i]+s2[i+1]*sp;
	for(int i=1;i<=n;i++)
	{
		int ma=get_ans(i);
		if(maxn<ma) {
			ans.clear();
			ans.push_back(i);
			maxn=ma;
		}
		else if(maxn==ma) ans.push_back(i);
	}
	write(maxn);pk;write(ans.size());pc;
	for(auto i : ans) write(i),pk;
	return 0;
}

