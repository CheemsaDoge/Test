#include<cstdio>
#include<set>
#include<vector>
#include<utility>
#include<algorithm>
#define IT set<node>::iterator

using std::set;
using std::vector;
using std::pair;

typedef long long LL;
const int MOD7 = 1e9 + 7;
const int MOD9 = 1e9 + 9;
const int imax_n = 1e5 + 7;

LL pow(LL a, LL b, LL mod)
{
	LL res = 1;
	LL ans = a % mod;
	while (b)
	{
		if (b&1) res = res * ans % mod;
		ans = ans * ans % mod;
		b>>=1;
	}
	return res;
}

struct node
{
	int l,r;
	mutable LL v;
	node(int L, int R=-1, LL V=0):l(L), r(R), v(V) {}
	bool operator<(const node& o) const
	{
		return l < o.l;
	}
};

set<node> s;

IT split(int pos)
{
	IT it = s.lower_bound(node(pos));
	if (it != s.end() && it->l == pos) return it;
	--it;
	int L = it->l, R = it->r;
	LL V = it->v;
	s.erase(it);
	s.insert(node(L, pos-1, V));
	return s.insert(node(pos, R, V)).first;
}

void add(int l, int r, LL val=1)
{
	IT itl = split(l),itr = split(r+1);
	for (; itl != itr; ++itl) itl->v += val;
}

void assign_val(int l, int r, LL val=0)
{
	IT itl = split(l),itr = split(r+1);
	s.erase(itl, itr);
	s.insert(node(l, r, val));
}

LL rank(int l, int r, int k)
{
	vector<pair<LL, int> > vp;
	IT itl = split(l),itr = split(r+1);
	vp.clear();
	for (; itl != itr; ++itl)
		vp.push_back(pair<LL,int>(itl->v, itl->r - itl->l + 1));
	std::sort(vp.begin(), vp.end());
	for (vector<pair<LL,int> >::iterator it=vp.begin();it!=vp.end();++it)
	{
		k -= it->second;
		if (k <= 0) return it->first;
	}
	return -1LL;
}

LL sum(int l, int r, int ex, int mod)
{
	IT itl = split(l),itr = split(r+1);
	LL res = 0;
	for (; itl != itr; ++itl)
		res = (res + (LL)(itl->r - itl->l + 1) * pow(itl->v, LL(ex), LL(mod))) % mod;
	return res;
}

int n, m;
LL seed, vmax;

LL rnd()
{
	LL ret = seed;
	seed = (seed * 7 + 13) % MOD7;
	return ret;
}

LL a[imax_n];

int main()
{
	scanf("%d %d %lld %lld",&n,&m,&seed,&vmax);
	for (int i=1; i<=n; ++i)
	{
		a[i] = (rnd() % vmax) + 1;
		s.insert(node(i,i,a[i]));
	}
	s.insert(node(n+1, n+1, 0));
	for (int i =1; i <= m; ++i)
	{
		int op = int(rnd() % 4) + 1;
		int l = int(rnd() % n) + 1;
		int r = int(rnd() % n) + 1;
		if (l > r)
			std::swap(l,r);
		int x, y;
		if (op == 3)
			x = int(rnd() % (r-l+1)) + 1;
		else
			x = int(rnd() % vmax) +1;
		if (op == 4)
			y = int(rnd() % vmax) + 1;
		if (op == 1)
			add(l, r, LL(x));
		else if (op == 2)
			assign_val(l, r, LL(x));
		else if (op == 3)
			printf("%lld\n",rank(l, r, x));
		else
			printf("%lld\n",sum(l, r, x, y));
	}
	return 0;
}
