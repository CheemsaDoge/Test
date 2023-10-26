#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const short dx[4] = {0, 1, 0, -1}; // 四个方向
const short dy[4] = {1, 0, -1, 0};
const short N=805;

// 结构体存 男孩/女孩/鬼，（当然鬼也可以用pair）
// (x, y) 表示其坐标位置，s 表示到达该点的距离。
struct Point{short x, y, s;};
short n, m;     // 地图大小
bool g[N][N];   // 存地图。true 表示能走，false 表示不能走
short st[N][N]; // 存每个点的状态。没被到过是 0，被男孩到过是 1，被女孩到过是 2
Point ghost[2]; // 存两个鬼的坐标

// 返回 a - b 的绝对值（当然也可以用 abs 写）
short sub(short a, short b)
{
    return a > b ? a - b : b - a;
}

// 判断 (x, y) 在第 t 秒的时候是否被某个鬼占领
bool check(short x, short y, short t)
{
    // 枚举两个鬼，如果某个鬼到 (x, y) 的曼哈顿距离 < 2t 那么返回 false
    for (short i = 0; i < 2; i ++ )
        if (sub(ghost[i].x, x) + sub(ghost[i].y, y) <= t << 1)
            return false;
    return true; // 否则说明没有鬼占领，放回 true
}

// 扩展队列 q 中所有到初始点距离在 v * t 以下的点
// 其中 t 是时间，v 是速度
bool BFS(queue<Point> &q, short t, short v)
{
    // 只要 q 不空，并且队头元素到初始点的距离小于 v * t，就继续扩展
    while (q.size() && q.front().s < t * v)
    {
        Point u = q.front(); q.pop();      // 先取出队头
        if (!check(u.x, u.y, t)) continue; // 如果队头元素已经被鬼占领（好惨），则跳过
        for (short i = 0; i < 4; i ++ )    // 枚举四个方向进行扩展
        {
            short a = u.x + dx[i], b = u.y + dy[i]; // 求出按该方向移动一格后的坐标
            // 如果该坐标在地图内，且能走，且没被鬼占领
            if (~a && ~b && a < n && b < m && g[a][b] && check(a, b, t))
                if (!st[a][b]) // 如果该位置没被遍历过
                {
                    // 记录该位置被遍历过。
                    // st[u.x][u.y] 是被谁遍历的，则 st[a][b] 就是被谁遍历过的。
                    st[a][b] = st[u.x][u.y];
                    // 将该点加入队列中
                    q.push({a, b, u.s + 1});
                }
                // 如果遍历 (a, b) 的和遍历 (u.x, u.y) 的不是一个人，说明男女会合了，返回 true
                else if (st[a][b] != st[u.x][u.y]) return true;
        }
    }
    return false; // 男女没会合，返回 false
}

// 求出男女会合的最短时间。如果不能会合，返回 -1
short bfs(Point boy, Point girl)
{
    memset(st, 0, sizeof st); // 将 st 初始化为 0
    // q_boy 是男孩的 bfs 队列，q_girl 是女孩的 bfs 队列
    queue<Point> q_boy, q_girl;
    // 分别将男孩和女孩加入队列中
    q_boy.push(boy), q_girl.push(girl);
    // 男孩到的点标记为 1，女孩到的点标记为 2
    st[boy.x][boy.y] = 1, st[girl.x][girl.y] = 2;
    // 按时间从 1 开始枚举。只要有一个队列没空，就继续枚举。
    for (short t = 1; q_boy.size() || q_girl.size(); t ++ )
        if (BFS(q_boy, t, 3) || BFS(q_girl, t, 1)) // 男孩速度为 3，女孩速度为 1
            return t; // 如果在扩展男孩或者扩展女孩时扩展到了对方，那么直接返回 t
    return -1; // 跳出循环说明两个队列都空了，返回 -1
}

int main()
{
    short test;
    scanf("%hd", &test);
    while (test -- )     // 注意多组测试数据qwq
    {
        scanf("%hd%hd\n", &n, &m);
        Point boy, girl;
        // 读入地图。i 和 j 分别枚举行列，cnt 枚举当前读入到了第几个鬼
        for (short i = 0, cnt = 0; i < n; i ++ , getchar())
            for (short j = 0; j < m; j ++ )
            {
                char ch = getchar();
                if (ch == 'M') boy = {i, j, 0};       // 如果该字符为 'M'，说明是男孩，存入 boy
                else if (ch == 'G') girl = {i, j, 0}; // 如果该字符为 'G'，说明是女孩，存入 girl
                else if (ch == 'Z') ghost[cnt ++ ] = {i, j, 0}; // 该字符是 'Z'，说明是鬼，存入 ghost
                g[i][j] = ch != 'X'; // 如果该字符不为 'X'，则该位置能走
            }
        printf("%d\n", bfs(boy, girl)); // 输出 bfs 的结果即可
    }
    return 0;
}
