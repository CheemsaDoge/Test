#include <bits/stdc++.h>
using namespace std;

#define int long long
bool inp[1000005];
int pri[1000005], pc;
void sieve(int mx) {
  inp[0] = inp[1] = true;
  for (int i = 2; i <= mx; ++i) {
    if (!inp[i]) pri[++pc] = i;
    for (int j = 1; i * pri[j] <= mx && j <= pc; ++j) {
      inp[i * pri[j]] = true;
      if (i % pri[j] == 0) break;
    }
  }
  return;
}

bool is_prime(int x) {
  if (x <= 1) return false;
  for (int i = 1; pri[i] * pri[i] <= x; ++i) {
    if (x % pri[i] == 0) return false;
  }
  return true;
}
int phi(int x) {
  int ans = x;
  for (int i = 1; pri[i] * pri[i] <= x; ++i) {
    if (x % pri[i] == 0) {
      while (x % pri[i] == 0) {
        x /= pri[i];
      }
      ans = ans / pri[i] * (pri[i] - 1);
    }
  }
  if (x > 1) ans = ans / x * (x - 1);
  return ans;
}

int T, B;
int f(int x, int max_phi) {
  max_phi -= B;
  if (max_phi <= 0) return x;
  while (max_phi--) {
    x = phi(x);
    if (x == 1) return 1;
  }
  return x;
}

int p1, p2;
int val[1000005], ps[1000005];
int a(int x) {
  return x * (x + 1) / 2; // 1 + 2 + ... + x
}
int b(int x) {
  return ps[x - p1];
}
int c(int x) {
  return x - p2; // p2+1 p2+2 .. x
}
void pre() {
  for (int i = B; i; --i) {
    if (is_prime(i)) {
      p1 = i;
      break;
    }
  }
  for (int i = B + 60; i <= 1100000000; ++i) {
    if (is_prime(i)) {
      p2 = i;
      break;
    }
  }

  int mx = phi(p1);
  for (int i = p1; i <= p2; ++i) {
    mx = max(mx, phi(i));
    val[i - p1] = f(i, mx);
    if (i != p1) ps[i - p1] = ps[i - p1 - 1] + val[i - p1];
    else ps[i - p1] = val[i - p1];
  }
}
int solve(int x) {
  if (x < p1) return a(x);
  else if (x <= p2) return a(p1 - 1) + b(x);
  else return a(p1 - 1) + b(p2) + c(x);
}

signed main() {
  //freopen("phi.in", "r", stdin);
  //freopen("phi.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  sieve(1000000);
  cin >> T >> B;
  pre();
  while (T--) {
    int L, R;
    cin >> L >> R;
    cout << solve(R) - solve(L - 1) << '\n';
  }
  cout.flush();
  return 0;
}