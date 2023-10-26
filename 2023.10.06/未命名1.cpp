#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

const short dx[4] = {0, 1, 0, -1}; // �ĸ�����
const short dy[4] = {1, 0, -1, 0};
const short N=805;

// �ṹ��� �к�/Ů��/������Ȼ��Ҳ������pair��
// (x, y) ��ʾ������λ�ã�s ��ʾ����õ�ľ��롣
struct Point{short x, y, s;};
short n, m;     // ��ͼ��С
bool g[N][N];   // ���ͼ��true ��ʾ���ߣ�false ��ʾ������
short st[N][N]; // ��ÿ�����״̬��û�������� 0�����к������� 1����Ů�������� 2
Point ghost[2]; // �������������

// ���� a - b �ľ���ֵ����ȻҲ������ abs д��
short sub(short a, short b)
{
    return a > b ? a - b : b - a;
}

// �ж� (x, y) �ڵ� t ���ʱ���Ƿ�ĳ����ռ��
bool check(short x, short y, short t)
{
    // ö�����������ĳ���� (x, y) �������پ��� < 2t ��ô���� false
    for (short i = 0; i < 2; i ++ )
        if (sub(ghost[i].x, x) + sub(ghost[i].y, y) <= t << 1)
            return false;
    return true; // ����˵��û�й�ռ�죬�Ż� true
}

// ��չ���� q �����е���ʼ������� v * t ���µĵ�
// ���� t ��ʱ�䣬v ���ٶ�
bool BFS(queue<Point> &q, short t, short v)
{
    // ֻҪ q ���գ����Ҷ�ͷԪ�ص���ʼ��ľ���С�� v * t���ͼ�����չ
    while (q.size() && q.front().s < t * v)
    {
        Point u = q.front(); q.pop();      // ��ȡ����ͷ
        if (!check(u.x, u.y, t)) continue; // �����ͷԪ���Ѿ�����ռ�죨�òң���������
        for (short i = 0; i < 4; i ++ )    // ö���ĸ����������չ
        {
            short a = u.x + dx[i], b = u.y + dy[i]; // ������÷����ƶ�һ��������
            // ����������ڵ�ͼ�ڣ������ߣ���û����ռ��
            if (~a && ~b && a < n && b < m && g[a][b] && check(a, b, t))
                if (!st[a][b]) // �����λ��û��������
                {
                    // ��¼��λ�ñ���������
                    // st[u.x][u.y] �Ǳ�˭�����ģ��� st[a][b] ���Ǳ�˭�������ġ�
                    st[a][b] = st[u.x][u.y];
                    // ���õ���������
                    q.push({a, b, u.s + 1});
                }
                // ������� (a, b) �ĺͱ��� (u.x, u.y) �Ĳ���һ���ˣ�˵����Ů����ˣ����� true
                else if (st[a][b] != st[u.x][u.y]) return true;
        }
    }
    return false; // ��Ůû��ϣ����� false
}

// �����Ů��ϵ����ʱ�䡣������ܻ�ϣ����� -1
short bfs(Point boy, Point girl)
{
    memset(st, 0, sizeof st); // �� st ��ʼ��Ϊ 0
    // q_boy ���к��� bfs ���У�q_girl ��Ů���� bfs ����
    queue<Point> q_boy, q_girl;
    // �ֱ��к���Ů�����������
    q_boy.push(boy), q_girl.push(girl);
    // �к����ĵ���Ϊ 1��Ů�����ĵ���Ϊ 2
    st[boy.x][boy.y] = 1, st[girl.x][girl.y] = 2;
    // ��ʱ��� 1 ��ʼö�١�ֻҪ��һ������û�գ��ͼ���ö�١�
    for (short t = 1; q_boy.size() || q_girl.size(); t ++ )
        if (BFS(q_boy, t, 3) || BFS(q_girl, t, 1)) // �к��ٶ�Ϊ 3��Ů���ٶ�Ϊ 1
            return t; // �������չ�к�������չŮ��ʱ��չ���˶Է�����ôֱ�ӷ��� t
    return -1; // ����ѭ��˵���������ж����ˣ����� -1
}

int main()
{
    short test;
    scanf("%hd", &test);
    while (test -- )     // ע������������qwq
    {
        scanf("%hd%hd\n", &n, &m);
        Point boy, girl;
        // �����ͼ��i �� j �ֱ�ö�����У�cnt ö�ٵ�ǰ���뵽�˵ڼ�����
        for (short i = 0, cnt = 0; i < n; i ++ , getchar())
            for (short j = 0; j < m; j ++ )
            {
                char ch = getchar();
                if (ch == 'M') boy = {i, j, 0};       // ������ַ�Ϊ 'M'��˵�����к������� boy
                else if (ch == 'G') girl = {i, j, 0}; // ������ַ�Ϊ 'G'��˵����Ů�������� girl
                else if (ch == 'Z') ghost[cnt ++ ] = {i, j, 0}; // ���ַ��� 'Z'��˵���ǹ����� ghost
                g[i][j] = ch != 'X'; // ������ַ���Ϊ 'X'�����λ������
            }
        printf("%d\n", bfs(boy, girl)); // ��� bfs �Ľ������
    }
    return 0;
}
