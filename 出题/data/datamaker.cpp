/*** 
 * @Author: CheemsaDoge
 * @Date: 2023-11-08 20:29:28
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-08 20:34:54
 * @FilePath: \TEST\出题\data\datamaker.cpp
 * @Forgive me.
 * @Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
using namespace std;

inline void _File() {
    freopen("sbtarzan.in","w",stdout);
}
inline int rander(int mod,int f) {
    return rand()%f?-rand()%mod:rand()%mod;
}
signed main() {
    _File();
    int n=5;
    cout<<n<<endl;
    for(int i=1;i<=n;i++) {
        int w=rander(114514,2);
        int s=rander(100,1);
        int b=rander(114513,2);
        cout<<w<<" "<<b<<" "<<s<<endl;
    }
    for(int i=2;i<n;i++) {
        int v=rander(i,1)+1;
        cout<<i<<" "<<v<<endl;
    }
}