static bool __fastcall spfa_dfs (Re int fr, Re double mid)
{
	vis[fr] = true;
	register int to;
	for (Re int i = head[fr]; i; i = nxt[i])
	{
		to = too[i];
		if (dis[fr] + wei[i] - mid > dis[to])
		{
			dis[to] = dis[fr] + wei[i] - mid;
			if (vis[to] || spfa_dfs(to, mid))
				{vis[fr] = false; return true;}
		}
	}
	vis[fr] = false; return false;
}
inline bool judge (register double mid)
{
	memset (dis, 0, sizeof dis);
	for (Re int i = 1; i <= hhsh; ++ i)
		if (spfa_dfs (i, mid)) return true;
	return false;
}
while (true)
	{
		n = read (); if (!n) return 0;
		memset (head, 0, sizeof head);
		memset (hash, 0, sizeof hash);
		ecnt = hhsh = 0;
		while (n --)
		{
			c = gc(), len = 0;
			while (c == '\n' || c == '\r') c = gc ();
			while ((c != '\n') && (c != '\r')) s[++ len] = c, c = gc();
			fr = calc(s[1], s[2]), to = calc(s[len-1], s[len]);
			if (!hash[fr]) hash[fr] = ++ hhsh;
			if (!hash[to]) hash[to] = ++ hhsh;
			addedge (hash[fr], hash[to], len);
		}
		l = 0.0, r = 1000.0;
		while (r - l >= eps)
		{
			mid = (l + r) / 2;
			if (judge(mid)) l = mid;
			else r = mid;
		}
		if (l == 0) puts ("No solution.");
		else printf ("%.2lf\n", l);
	}
