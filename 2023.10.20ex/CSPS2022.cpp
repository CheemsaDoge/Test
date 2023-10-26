#include <bits/stdc++.h>
using namespace std;
#define int long long int 
const int MAXN=2e6+1145;
int n,m;
int sta[MAXN][26];
int stb[MAXN][26];
inline void inia() {
    int t=(int)log2(n);
    for(int i=1;i<=t;i++) {
        for(int j=1;j+(1<<t)<=n;j++) {
            sta[j][i]=max(sta[j][i-1],sta[j+(1<<(i-1))][i-1]);
        }
    }
}
inline void inib() {
    int t=(int)log2(m);
    for(int i=1;i<=t;i++) {
        for(int j=1;j+(1<<t)<=n;j++) {
            stb[j][i]=min(stb[j][i-1],stb[j+(1<<(i-1))][i-1]);
        }
    }
}
inline int a_query(int l,int r) {
    int t=(int)log2(r-l+1);
    return max(sta[l][t],sta[r-(1<<t)+1][t]);
}
inline int b_query(int l,int r) {
    int t=(int)log2(r-l+1);
    return min(stb[l][t],stb[r-(1<<t)+1][t]);
}
signed main() {
    
}