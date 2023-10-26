using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
constexpr int N = 1e6 + 1;
i64 tree[N][2];
inline i64 query(int n) {
    i64 sumA{}, sumB{};
    for (int k = n; k > 0; k -= k & -k)
        sumA += tree[k][0], sumB += tree[k][1];
    return sumA * (n + 1) - sumB;
}
inline void add(int n, i64 x) {
    for (int k = n; k < N; k += k & -k)
        tree[k][0] += x, tree[k][1] += x * n;
}
int main() {
    int n = ii();
    int m = ii();
    for (int i = 1; i <= n; ++i) {
        tree[i][0] = ii();
        tree[i][1] = tree[i - 1][1] + (tree[i][0] - tree[i - 1][0]) * i;
    }
    for (int i = n; i >= 1; --i) {
        tree[i][0] -= tree[(i - 1) & i][0];
        tree[i][1] -= tree[(i - 1) & i][1];
    }
    for (int i = 1; i <= m; ++i) {
        int o = ii();
        int l = ii();
        int r = ii();
        if (o == 1) {
            int x = ii();
            add(l + 0, +x);
            add(r + 1, -x);
        } else {
            oo(query(r) - query(l - 1), '\n');
        }
    }
    flush();
}
//#ifdef LOCAL
//    auto flush = [&]() {};
//    auto ii = [&]() {
//        int x;
//        std::cin >> x;
//        return x;
//    };
//    auto oo = [&](auto x, char c = ' ') {
//        std::cout << x << c << std::flush;
//    };
//#else
//    char bufI[1 << 19], *ptrI = bufI, *endI = bufI + sizeof(bufI);
//    char bufO[1 << 19], *ptrO = bufO, *endO = bufO + sizeof(bufO);
//    fread(bufI, 1, sizeof(bufI), stdin);
//    auto load = [&]() {
//        memcpy(bufI, ptrI, endI - ptrI);
//        fread(endI - ptrI + bufI, 1, ptrI - bufI, stdin);
//        ptrI = bufI;
//    };
//    auto flush = [&]() {
//        fwrite(bufO, 1, ptrO - bufO, stdout);
//        ptrO = bufO;
//    };
//    auto ii = [&]() {
//        if (endI - ptrI < 32) load();
//        int x{};
//        int n{};
//        for (; *ptrI < 48; ++ptrI) n = *ptrI == 45;
//        for (; *ptrI > 47; ++ptrI) x = x * 10 + *ptrI - 48;
//        return n ? -x : +x;
//    };
//    auto oo = [&](auto x, char c = ' ') {
//        if (endO - ptrO < 32) flush();
//        if (x < 0) x = -x, *ptrO++ = '-';
//        char buf[20];
//        char *end = buf + 20;
//        char *ptr = buf + 20;
//        *--ptr = c;
//        for (; x >= 10; x /= 10)
//            *--ptr = char(48 + x % 10);
//        *--ptr = char(48 + x);
//        memcpy(ptrO, ptr, end - ptr);
//        ptrO += end - ptr;
//    };
//#endif
