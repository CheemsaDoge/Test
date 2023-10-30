#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int m, p, x, a, tot;
char op;
vector<pair<int, int>> s;

int main() {
    scanf("%d %d\n", &m, &p);
    while (m--) {
        scanf("%c %d\n", &op, &x);
        if (op == 'A') {
            tot++;
            x = (x + a) % p;
            while (s.size() && s.back().second <= x) s.pop_back();
            s.push_back(make_pair(tot, x));
        } else {
            a = upper_bound(s.begin(), s.end(), make_pair(tot - x + 1, -1))->second;
            printf("%d\n", a);
        }
    }
    return 0;
}
