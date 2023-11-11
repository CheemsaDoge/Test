/*** 
 * @Author: CheemsaDoge
 * @Date: 2023-11-08 20:29:28
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-10 14:35:04
 * @FilePath: \TEST\出题\data v2.0\datamaker.cpp
 * @Forgive me.
 * @Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
using namespace std;

inline void _File() {
    freopen("sbtarzan23.in","w",stdout);
}
//12 1-3        10
//16 4-7        1000
//20 8-12       200000
//20 13-17      250000
//24 18-23      300000
//8 24-25       500000
inline int rander(int mod,int f) {
    return rand()%f?-rand()%mod:rand()%mod;
}
const int MAXV1=1450;
const int MAXV2=100;
signed main() {
    srand(time(0));
    _File();
    int n=300000;
    cout<<n<<endl;
    for(int i=1;i<=n;i++) {
        int w=rander(MAXV1,2);
        int s=rander(MAXV2+1,1);
        int b=rander(MAXV1,2);
        cout<<w<<" "<<b<<" "<<s<<endl;
    }
    for(int i=2;i<=n;i++) {
        int v=rander(i-1,1)+1;
        cout<<i<<" "<<v<<endl;
    }
}