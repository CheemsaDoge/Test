/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template <typename T> inline void read(T &_x) {
    _x = 0;    //fast input
    T _w = 1, _ch = getchar();
    while (!isdigit(_ch) && _ch != '-')
        _ch = getchar();
    if (_ch == '-')
        _w = -1, _ch = getchar();
    while (isdigit(_ch))
        _x = (_x << 3) + (_x << 1) + (_ch^'0'), _ch = getchar();
    _x = _x * _w;
}
template <> inline void read <char>(char &in) {
    in = getchar();
    while (in == ' ' || in == '\n')
        in = getchar();
}
template <typename T> inline void write(T _x) {
    static char _q[65];
    int _cnt = 0;
    if (_x < 0)
        putchar('-'), _x = -_x;
    _q[++_cnt] = char(_x % 10), _x /= 10;
    while (_x)
        _q[++_cnt] = char(_x % 10), _x /= 10;
    while (_cnt)
        putchar(_q[_cnt--] + '0');
}
template <> inline void write <char> (char _x) {
    putchar(_x);
}
template <> inline void write <char *> (char *_x) {
    int siz = strlen(_x);
    for (int i = 0; i < siz; i++)
        write(_x[i]);
}
template <typename T> inline T min(const T _a, const T _b) {
    return _a > _b ? _b : _a;
}
template <typename T> inline T max(const T _a, const T _b) {
    return _a > _b ? _a : _b;
}
template <typename T> inline T abs(const T _a) {
    return _a < 0 ? -_a : _a;
}
template <typename T> inline void swap(T &_x, T &_y) {
    _x += _y;
    _y = _x - _y;
    _x -= _y;
}
template <typename types, typename ... Args> inline void read(types &x, Args &... args) {
    read(x), read(args...);
}
template <typename types, typename ... Args> inline void write(types x, Args ... args) {
    write(x), putchar(' '), write(args...);
}
const int MAXM = 1e6 + 10;
const int MAXN = 1e6 + 10;
const int INF = 2147483647ll; //2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int main() {
	return 3;
} 
