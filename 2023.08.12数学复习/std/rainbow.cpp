#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

const double EPS = 1e-4;
const int max_n = 7;

struct interval
{
	double lp, rp;
	
	
};

bool operator < (interval a, interval b) {
	if (a.rp != b.rp)
		return a.rp < b.rp;
	
	return a.lp < b.lp;
}

interval it[max_n];
double rad[max_n], pos[max_n], hei, ed;

bool check(double added)
{
	double tmp;
	
	for (int i = 0; i < max_n; i++)
	{
		tmp = sqrt((rad[i] + added) * (rad[i] + added) - hei * hei);
		
		it[i].lp = pos[i] - tmp;
		it[i].rp = pos[i] + tmp;
	}
	
	sort(it, it + max_n);
	
	for (int i = max_n - 1; i > 0; i--)
	{
		if (it[i-1].rp < it[i].lp)
		{
			if (it[i].lp <= 0 && it[i].rp >= ed)
				return true;
			
			continue;
		}
		
		if (it[i-1].lp > it[i].lp)
			it[i-1].lp = it[i].lp;
		it[i-1].rp = it[i].rp;
	}
	
	if (it[0].lp <= 0 && it[0].rp >= ed)
		return true;
	else
		return false;
}

int main()
{
	freopen("rainbow.in", "r", stdin);
	freopen("rainbow.out", "w", stdout);
	double lb = 0, ub = 10010, mid, ans = -1;
	
	scanf("%lf%lf", &hei, &ed);
	for (int i = 0; i < max_n; i++)
		scanf("%lf%lf", pos + i, rad + i);
	
	while (ub - lb > EPS)
	{
		mid = (lb + ub) / 2;
		
		if (check(mid))
			ans = mid, ub = mid;
		else
			lb = mid + EPS;
	}
	
	printf("%.2lf\n", ans);
	
	return 0;
}
