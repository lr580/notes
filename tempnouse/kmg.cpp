把移动拆分为多个耗费 $1$ 的领位交换。若 $i$ 在 $j$ 后，需要交换一次。对每个 $i$，有 $p_i$ 概率会移动它，而对每个 $j$，设 $i$ 在 $j$ 后的概率为 $p$，则因为只需要考虑相对关系，那么总条件概率为 $p_i+p_j$，每次落在 $p_i+p_j$ 区域内时(即移动 $i,j$ 其一时)，有 $p_j$ 概率移动 $j$ 使得 $j$ 在 $i$ 前。那么经过无穷次移动后，$i$ 在 $j$ 后的概率期望是 $p=\dfrac{p_j}{p_i+p_j}$，故所求为 $\sum_{i=1}^n\sum_{j=1,j\neq i}^n\dfrac{p_ip_j}{p_i+p_j}$

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
const ll mn = 110;
db p[mn], ans;
ll n;
signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
    {
        scanf("%Lf", &p[i]);
    }
    for (ll i = 1; i <= n; ++i)
    {
        for (ll j = 1; j <= n; ++j)
        {
            ans += (p[i] * p[j]) / (p[i] + p[j]) * (i != j);
        }
    }
    printf("%.12Lf", ans);
    return 0;
}
```

