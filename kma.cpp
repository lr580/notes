字符串爆搜大模拟，没啥好说的，就是多加注意，语法问题不要犯低级错误

当然有更好的实现，这里只给出我自己的实现

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mn = 13, h20 = 18;
ll n, m, c[mn], a[mn], h[mn], w[mn];
map<string, ll> nam{{"Ala", 0}, {"Asn", 1}, {"Asp", 2}, {"Cys", 3}, {"Gln", 4}, {"Glu", 5}, {"Gly", 6}, {"Met", 7}, {"Ser", 8}, {"Thr", 9}};
ll ma[] = {89, 132, 133, 121, 146, 147, 75, 149, 105, 119};
vector<vector<ll>> ans;
typedef vector<string> amino;
amino str[mn];
void build(ll x, amino v)
{
    h[x] = v.size();
    for (auto ln : v)
    {
        w[x] = max(w[x], ll(ln.size()));
    }
    while (v.size() < 15)
    {
        v.push_back("");
    }
    for (ll i = 0; i < 15; ++i)
    {
        v[i].resize(8, ' ');
        for (ll j = w[i] - (ll)v[i].size(); j > 0; --j)
        {
            v[i] += " ";
        }
    }
    str[x].resize(16);
    for (ll i = 0; i < 15; ++i)
    {
        str[x][i] = v[i];
    }
}
void init()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    amino ala{" H H O", " | | ||", "-N-C-C--", "   |", " H-C-H", "   |", "   H"};
    build(nam["Ala"], ala);

    amino asp{" H H O", " | | ||", "-N-C-C--", "   |", " H-C-H", "   |", " O=C-O-H"};
    build(nam["Asp"], asp);

    amino asn{" H H O", " | | ||", "-N-C-C--", "   |", " H-C-H", "   |", " O=C-N-H", "     |", "     H"};
    build(nam["Asn"], asn);

    amino cys{" H H O", " | | ||", "-N-C-C--", "   |", " H-C-S-H", "   |", "   H"};
    build(nam["Cys"], cys);

    amino gly{" H H O", " | | ||", "-N-C-C--", "   |", "   H"};
    build(nam["Gly"], gly);

    amino ser{" H H O", " | | ||", "-N-C-C--", "   |", " H-C-O-H", "   |", "   H"};
    build(nam["Ser"], ser);

    amino met{" H H O", " | | ||", "-N-C-C--", "   |", " H-C-H", "   |", " H-C-H", "   |", "   S", "   |", " H-C-H", "   |", "   H"};
    build(nam["Met"], met);

    amino thr{" H H O", " | | ||", "-N-C-C--", "   |", " H-C-O-H", "   |", " H-C-H", "   |", "   H"};
    build(nam["Thr"], thr);

    amino gln{" H H O", " | | ||", "-N-C-C--", "   |", " H-C-H", "   |", " H-C-H", "   |", " O=C-N-H", "     |", "     H"};
    build(nam["Gln"], gln);

    amino glu{" H H O", " | | ||", "-N-C-C--", "   |", " H-C-H", "   |", " H-C-H", "   |", " O=C-O-H"};
    build(nam["Glu"], glu);
}
void dfs(ll p, ll s)
{
    if (p >= 2)
    {
        vector<ll> t;
        for (ll i = 0; i < p; ++i)
        {
            t.emplace_back(a[i]);
        }
        ans.push_back(t);
    }
    for (ll i = 0; i < m; ++i)
    {
        ll nw = s + ma[c[i]] - h20;
        if (nw <= n)
        {
            a[p] = i;
            dfs(p + 1, nw);
        }
    }
}
void print(vector<ll> &r)
{
    ll hei = 0;
    for (auto i : r)
    {
        hei = max(hei, h[c[i]]);
    }
    amino t(hei);
    for (ll i = 0; i < hei; ++i)
    {
        t[i] += i == 2 ? "H" : " ";
    }
    for (ll i = 0, ie = r.size(); i < ie; ++i)
    {
        ll id = c[r[i]];
        for (ll j = 0; j < hei; ++j)
        {
            t[j] += str[id][j];
        }
    }
    t[2].back() = 'O';
    string tail = "-H";
    for (ll j = 0; j < 2; ++j)
    {
        for (ll i = 0; i < hei; ++i)
        {
            t[i] += i == 2 ? tail[j] : ' ';
        }
    }
    for (auto &i : t)
    {
        if (i.size())
        {
            cout << i << '\n';
        }
    }
    cout << '\n';
}
signed main()
{
    init();
    cin >> m >> n;
    amino tys;
    for (ll i = 0; i < m; ++i)
    {
        string tmp;
        cin >> tmp;
        tys.push_back(tmp);
    }
    sort(tys.begin(), tys.end());
    for (ll i = 0; i < m; ++i)
    {
        c[i] = nam[tys[i]];
    }
    dfs(0, h20);
    //sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto i : ans)
    {
        print(i);
    }
    return 0;
}
```

