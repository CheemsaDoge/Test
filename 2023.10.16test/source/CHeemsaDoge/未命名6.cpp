//
// Created by lndff on 2023/10/16.
//
#include <bits/stdc++.h>
using namespace std;

int a, b, tot;
queue<int>q;
bool vis[4000];
int main(){
//    freopen("tree.in","r",stdin);
//    freopen("tree.out","w",stdout);
    scanf("%d%d", &a, &b);
    if (a == 0 && b == 0) return 0 * puts("1");
    if (a < b + 2) return 0 * puts("0");
    if (a + b > 2000) return 0 * puts("0");
    if (a == b + 3) return 0 * puts("0");
    tot = 1;
    int sum = a + b;
    if (a > b + 3) sum++;
    printf("%d\n", sum);
    if (b) {
        a -= b + 2;
        puts("1 2");
        puts("1 3");
        puts("1 4");
        q.push(2);q.push(3);q.push(4);
        tot = 4;--b;
        while (b) {
            int s = q.front();
            q.pop();
            printf("%d %d\n%d %d\n", s, tot + 1, s, tot + 2);
            q.push(++tot);q.push(++tot);
            --b;
        }
    }
    int nn = tot;
    a++;
    while (a--){
        printf("%d %d\n", nn, ++tot);
    }
}
