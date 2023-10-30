#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define maxn 100010
template< typename T >inline void read(T &x)
{
	char c=getchar();x=0;int f=0;
	for(;!isdigit(c);c=getchar()) f|=(c=='-');
	for(;isdigit(c);c=getchar()) x=((x<<3)+(x<<1)+(c^48));
	x=f?-x:x;
}
template< typename T >inline void write(T x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10^48);
}
const int N = 1e4 + 5;
int a[N];
int vis[N];
std::vector<int> v;
int n, m;
int f[N];
int solve()
{
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] >= 2)
		{
			int flag = 1;
			vis[i] -= 2;
			for (int j = 1; j <= n + 2; j ++) f[j] = vis[j];
			for (int j = 1; j <= n + 2; j++)
			{
				if (f[j] < 0) {flag = 0; break;}
				f[j] %= 3;
				f[j + 1] -= f[j];
				f[j + 2] -= f[j];
			}
			vis[i] += 2;
			if (flag)
				return 1;
		}
	}
	return 0;
}
int main ()
{
	freopen("ma.in", "r", stdin);
	freopen("ma.out", "w", stdout);
	read(n);
	read(m);
	for (int i = 1; i <= 3 * m + 1; i++)
		read(a[i]);
	for (int i = 1; i <= 3 * m + 1; i++)
		vis[a[i]] ++;
	for (int i = 1; i <= n; i++)
	{
		vis[i]++;
		if (solve())
		{
			v.push_back(i);
		}
		vis[i]--;
	}
	if (v.size() == 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
	return 0 ;
}
