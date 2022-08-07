把线转化为格子，对一个矩形 $(a_x,a_y),(b_x,b_y)$，其 $[a_x,b_x),[a_y,b_y)$ 的矩形范围格子都被涂色。

记二进制状态 $b$ 表示当前多少个矩形被染色了，则所有能覆盖 $[0,w),[0,h)$ 的状态都是终态。设 $dp_i$ 表示状态 $i$ 期望要涂色多少次才能填满。则所有上述状态满足 $dp_i=0$。对其他状态，递推方程为：
$$
dp_i=1+\dfrac1n\sum_{j=0}^{n-1} dp_{i|2^j}
$$
设 $i$ 有 $cnt$ 个 $1$，则 $\sum$ 里有 $cnt$ 个或后不变，则上述表达式可以化简为：
$$
\begin{align}
dp_i&=1+\dfrac{cnt}ndp_i+\dfrac1n\sum_{j=0,i|2^j\neq i}^{n-1}dp_{i|2^j}\\
dp_i&=\dfrac{n-cnt}n(1+\dfrac1n\sum_{j=0,i|2^j\neq i}^{n-1}dp_{i|2^j})
\end{align}
$$
若从 $2^n-1$ 逆序枚举所有状态，可以知道，能够每次枚举时其 $dp_{i|2^j}$ 全部已知，故可以逆推。最终所求即 $dp_0$，DP 的复杂度为 $O(n2^n)$

固然可以离散化，然后用二维前缀和差分来处理每个状态是否覆盖 $[0,w),[0,h)$，但对每个状态，都需要进行 $O(n)$ 次差分和 $1$ 次 $O((2n)^2)$ 的前缀和，复杂度是 $O(4n^22^n)$，且有 $t$ 次询问，常数高达 $2\times10^8$，很危险

> 其他方法：用二维线段树维护矩阵加法，然后用 DFS 在枚举状态时不断增删矩形，复杂度为 $O(2^n\log^2(2n))$，但码量很恐怖

不妨用 bitset 优化，对每个状态，用一个 $(2n)^2$ 位的 bitset 维护其染色的格子，设一行为 $2^{b_y-a_y}-1$ 的高位移动，那么每列再高位移动即可。预处理复杂度是 $O(\dfrac {n^4}{w})$ 的，而 DFS 时直接 bitset 运算，其复杂度是 $O(\dfrac{n^2}w2^n)$ 的，事实上因为 $n$ 小比二维线段树常数更优

```c++
#include <bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%lld", &x)
typedef long long ll;
const ll mn = 11, mb = 1030, mm = 503, mod = 998244353;
ll t, n, w, h, xs, ys, x[mn][2], y[mn][2], xh[mn * 2], yh[mn * 2], s;
bitset<mm> cv[mn], stt;
ll dp[mb], inv[mn * 2];//注意2^n不是1e3时是1024,开1e3会wa
signed main()
{
    auto qpow = [&](ll a, ll b)
    {
        ll r = 1;
        for (; b; b >>= 1)
        {
            if (b & 1)
            {
                r = r * a % mod;
            }
            a = a * a % mod;
        }
        return r;
    };
    inv[0] = 1;
    for (ll i = 1; i < mn * 2; ++i)
    {
        inv[i] = qpow(i, mod - 2);
    }
    for (sc(t); t; --t)
    {
        sc(n), sc(w), sc(h);
        xs = ys = 0;
        for (ll i = 0, ax, ay, bx, by; i < n; ++i)
        {
            sc(ax), sc(ay), sc(bx), sc(by);
            ax = min(ax, w), bx = min(bx, w);
            ay = min(ay, h), by = min(by, h);
            xh[++xs] = ax, xh[++xs] = bx;
            yh[++ys] = ay, yh[++ys] = by;
            x[i][0] = ax, x[i][1] = bx, y[i][0] = ay, y[i][1] = by;
        }
        // xh[++xs]=w,yh[++ys]=h;
        sort(xh + 1, xh + xs + 1), sort(yh + 1, yh + ys + 1);
        xs = unique(xh + 1, xh + xs + 1) - (xh + 1); // xs个不同x
        ys = unique(yh + 1, yh + ys + 1) - (yh + 1);
        s = (xs - 1) * (ys - 1); //线数目-1=格子数目
        for (ll i = 0; i < n; ++i)
        {
            x[i][0] = lower_bound(xh + 1, xh + xs + 1, x[i][0]) - xh;
            x[i][1] = lower_bound(xh + 1, xh + xs + 1, x[i][1]) - xh;
            y[i][0] = lower_bound(yh + 1, yh + ys + 1, y[i][0]) - yh;
            y[i][1] = lower_bound(yh + 1, yh + ys + 1, y[i][1]) - yh;
            cv[i].reset();
            // ln表示第[ay,by)个格子都标记为1
            bitset<mm> ln = ((1 << (y[i][1] - y[i][0])) - 1) << (y[i][0] - 1);
            for (ll j = x[i][0] - 1; j < x[i][1] - 1; ++j)
            {
                cv[i] |= (ln << (j * (ys - 1))); //每行涂色,一行ys-1格
            }
        }
        //当前第i个矩形,已选矩形二进制状态为b,矩形覆盖为stt
        auto dfs = [&](auto self, ll i, ll b) -> void
        {
            if (i == n)
            {
                dp[b] = stt.count() == s ? 0 : -1;
                // printf("%lld %lld\n", b, dp[b]);
                return;
            }
            bitset<mm> tmp = stt;
            self(self, i + 1, b);
            stt = tmp | cv[i];
            self(self, i + 1, b | (1 << i));
            stt = tmp;
        };
        dfs(dfs, 0, 0);
        if (dp[(1 << n) - 1] == -1)
        {
            printf("-1\n");
            continue;
        }
        //可以知道逆序遍历顺序是对的，不会引起递归循环引用
        for (ll i = (1 << n) - 1; i >= 0; --i)
        {
            if (dp[i] != -1)
            {
                continue;
            }
            ll cnt = 0, res = 0;
            for (ll j = 0; j < n; ++j)
            {
                if (i >> j & 1)
                {
                    ++cnt;
                }
                else
                {
                    res = (res + inv[n] * dp[i | (1 << j)]) % mod;
                }
                dp[i] = (1 + res) * n % mod * inv[n - cnt] % mod;
            }
        }
        printf("%lld\n", dp[0]);
    }
    return 0;
}
```



