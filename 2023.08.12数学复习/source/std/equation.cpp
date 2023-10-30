#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long LL;
const int maxn = 1e6 + 5;
LL num[maxn];
map<int, int> id;

LL a[3], b[3];
int n = 2;

LL qmod(LL a, LL b, LL mod){		
    LL ans = 0;
    while(b > 0){
        if(b & 1) ans = (ans + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}

LL exgcd(LL a, LL b, LL &x, LL &y){
    if(b == 0){
        x = 1, y = 0;
        return a;
    }else{
        LL gcd = exgcd(b, a % b, x, y);
        LL t = y;
        y = x - (a / b) * y;
        x = t;
        return gcd;
    }
}

LL china(){
    LL m = a[1], ans = b[1], x, y;
    for(int i = 2; i <= n; i++){
        LL c = (b[i] - ans % a[i] + a[i]) % a[i];
        LL gcd = exgcd(m, a[i], x, y);
        if(c % gcd) return -1;		// нч╫Б
        LL ag = a[i] / gcd;
        x = qmod(x, c / gcd, ag);
        ans += x * m;
        m *= ag;
        ans = (ans % m + m) % m;
    }
    return (ans % m + m) % m;
}


int main(){
	freopen("equation.in", "r", stdin);
	freopen("equation.out", "w", stdout);
    IOS;
    int aa, bb, p;
    LL x, pp;
    cin >> aa >> bb >> p >> x;
    a[1] = p;
    a[2] = p - 1;
    pp = (LL)p * (p - 1);
    int limit = min(x, p - 1LL);
    num[1] = 1;
    for(int i = 2; i <= limit; i++)
        num[i] = ((p - p / i) * num[p % i]) % p;
    for(int i = 1; i <= limit; i++)
        id[num[i] * bb % p] = i;
    LL ans = 0, now = aa, minone;
    for(int i = 1; i <= limit; i++){
        if(id.count(now)){
            b[1] = id[now];
            b[2] = i;
            minone = china();
            if(x >= minone) ans += (x - minone) / pp + 1;
        }
        now = now * aa % p;
    }
    cout << ans << endl;
}

