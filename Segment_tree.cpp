#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

const int inf = 1 << 30, maxN = 100000;

class point{
    public : int x, y, z;
    point(int dx = 0, int dy = 0, int dz = 0) {
        x = dx;
        y = dy;
        z = dz;
    }
};

point a[maxN], b[maxN], r[maxN];
vector <int> g[maxN];
int u, v, n, tmin[2 * maxN], tmax[2 * maxN], mid;

bool f1(point q, point w)
{
    return q.x < w.x;
}

bool f2(point q, point w)
{
    return q.y < w.y;
}

int binS(int dX)
{
    int l = 0, r = n - 1;
    while (l < r) {
        int m = (l + r) / 2;
        if (a[m].x < dX) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l + n;
}

void modifyn(int c, int dX)
{
    tmin[c] = dX;
    c /= 2;
    while (c > 0) {
        tmin[c] = min(tmin[2 * c], tmin[2 * c + 1]);
        c /= 2;
    }
}

void modifyx(int c, int dX)
{
    tmax[c] = dX;
    c /= 2;
    while (c > 0) {
        tmax[c] = max(tmax[2 * c], tmax[2 * c + 1]);
        c /= 2;
    }
}

int rmxq(int l, int r)
{
    int res = -inf;
    while (l <= r) {
        if (l % 2 == 1) {
            res = max(res, tmax[l++]);
        }
        if (r % 2 == 0) {
            res = max(res, tmax[r--]);
        }
        l /= 2; r /= 2;
    }
    return res;
}

int rmnq(int l, int r)
{
    int res = inf;
    while (l <= r) {
        if (l % 2 == 1) {
            res = min(res, tmin[l++]);
        }
        if (r % 2 == 0) {
            res = min(res, tmin[r--]);
        }
        l /= 2; r /= 2;
    }
    return res;
}

int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &u, &v);
        a[i] = b[i] = point(u, v, i);
    }
    for (int i = 0; i < 2 * maxN; i++) {
        tmin[i] = inf;
        tmax[i] = -inf;
    }
    sort(a, a + n, f1);
    sort(b, b + n, f2);
    mid = binS(b[0].x);
    modifyn(mid, mid);
    modifyx(mid, mid);
    for (int i = 1; i < n; i++) {
        int k = binS(b[i].x), f1 = -inf, f2 = inf;
        if (k < mid) {
            f1 = rmxq(n, k - 1);
            f2 = rmnq(k + 1, mid);
        } else {
            f1 = rmxq(mid, k - 1);
            f2 = rmnq(k + 1, 2 * n);
        }
        if (f1 != -inf && r[f1].y == 0) {
            r[k].z = f1;
            r[f1].y = k;
            modifyx(k, k);
            modifyn(k, k);
        } else {
            if (f2 != inf && r[f2].x == 0) {
                r[k].z = f2;
                r[f2].x = k;
                modifyx(k, k);
                modifyn(k, k);
            }
        }
    }
    for (int i = n; i < 2 * n; i++) {
        int to = a[i - n].z;
        if (r[i].z != 0) {
             g[to].push_back(a[r[i].z - n].z + 1);
        } else {
            g[to].push_back(0);
        }
        if (r[i].x != 0) {
            g[to].push_back(a[r[i].x - n].z + 1);
        } else {
            g[to].push_back(0);
        }
        if (r[i].y != 0) {
            g[to].push_back(a[r[i].y - n].z + 1);
        } else {
            g[to].push_back(0);
        }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", g[i][j]);
        }
        printf("\n");
    }
    return 0;
}
