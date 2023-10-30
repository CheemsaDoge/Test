#include <bits/stdc++.h>
using namespace std;
#define ll long long
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const ll N = 100;
ll n, a[N], b[N];
inline ll mul(ll a, ll b, ll mod) {
    ll ans = 0;
    while (b > 0) {
        if (b & 1)
            ans = (ans + a) % mod;

        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}
inline ll extend_gcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extend_gcd(b, a % b, y, x);
    y = y - a / b * x;
    return d;
}
inline ll excrt() {
    ll x, y, m1 = a[1], a1 = b[1], ans = 0;
    if (n == 1)
        return a1;
    for (ll i = 2; i <= n; i++) {
        ll m2 = a[i], a2 = b[i];
        ll a = m1, b = m2, c = (a2 - a1 % m2 + m2) % m2;
        ll d = extend_gcd(a, b, x, y);
        if (c % d != 0)
            return -1;
        x = mul(x, c / d, b / d);
        ans = a1 + x * m1;
        m1 = m2 / d * m1;
        ans = (ans % m1 + m1) % m1;
        a1 = ans;
    }
    return ans;
}
int main() {
	freopen("5.3.in","r",stdin);
	freopen("5.3.out","w",stdout);
    read(n);
    for (ll i = 1; i <= n; i++)
        read(a[i]),read(b[i]);
    printf("%lld",excrt());
    return 0;
}
