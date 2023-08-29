面试准备笔记。

## 目录

#### 力扣

##### 题单

- 4\. 寻找两个正序数组的中位数

  **分治(二分)**

- 10\. 正则表达式匹配

  **DP 字符串**

- 23\. 合并K个升序链表

  堆

- 25\. K 个一组翻转链表

  模拟

- 30\. 串联所有单词的子串

  滑动窗口 STL

- 32\. 最长有效括号

  **DP / 贪心** / (前缀和 + 二分 + 树状数组)

- 37\. 解数独

  DFS

- 41\. 缺失的第一个正数

  模拟(mex)

- 42\. 接雨水

  前缀和 / <u>单调栈 / 双指针</u>

- 44\. 通配符匹配

  **DP 字符串** / **AC自动机**

- 51\. N皇后

  DFS

- 60\. 排列序列

  模拟(康托展开)

- 65\. 有效数字

  模拟(自动机/regex)

- 68\. 文本左右对齐

  模拟

- 72\.编辑距离

  DP 字符串

- 76\.最小覆盖子串

  滑动窗口

- 84\.柱状图中的最大矩形

  <u>单调栈</u> / ST表

- 85\.最大矩形

  悬线法 / <u>单调栈</u>

- 87\.扰乱字符串

  **记忆化DFS/DP**

- 115\.不同的子序列

  <u>DP</u>

- 123\.买卖股票的最佳时机III

  <u>DP</u> / 前缀和

- 124\.二叉树中的最大路径和

  DFS

- 126\.单词接龙II

  毒瘤卡常爆搜

- 132\.分割回文串II

  <u>DP</u> / DP+字符串哈希

- 140\.单词拆分II

  模拟DFS

- 149\.直线上最多的点数

  <u>枚举+STL</u> / 随机化

- 154\.寻找旋转排序数组中的最小值II

  **二分**

- 164\.最大间距

  基数排序

- 174\.地下城游戏

  **DP**

- 188\.买卖股票的最佳时机IV

  **DP** / **wqs二分**

- 212\.单词搜索II

  模拟DFS

- 214\.最短回文串

  manacher / 字符串哈希 / <u>KMP</u>

- 218\.天际线问题

  小模拟+(对顶堆 / <u>堆</u>)

- 220\.存在重复元素III

  滑动窗口+STL二分 / <u>滑动窗口+STL</u>

- 224\.基本计算器

  模拟(栈)

- 233\.数字1的个数

  思维 / <u>数位DP</u>

- 239\.滑动窗口最大值

  滑动窗口+(对顶堆 / <u>堆</u>)

- 273\.整数转英文表示

  模拟

- 282\.给表达式添加运算符

  模拟+DFS

- 295\.数据流的中位数

  对顶堆

- 297\.二叉树的序列化与反序列化

  DFS

- 301\.删除无效的括号

  DFS / <u>枚举子集</u>

- 312\.戳气球

  区间DP

- 315\.计算右侧小于当前元素的个数

  权值树状数组 / <u>归并排序</u> / <u>平衡树</u>

- 982\.按位与为零的三元组

  **<u>FWT</u> / <u>高维前缀和</u>** / <u>桶枚举</u> / bitset优化枚举

- 321\.拼接最大数

  (**单调栈+反悔贪心**(+后缀数组/后缀自动机)) / **子序列自动机**

- 327\.区间和的个数

  平衡树(pb\_ds) / <u>归并排序</u> / 线段树+离散化

- 329\.矩阵中的最长递增路径

  BFS/DFS/DP

- 330\.按要求补齐数组

  **贪心**

- 332\.重新安排行程

  欧拉图 DFS/Hierholzer

- 335\.路径交叉

  **思维**

- 1617\.统计子树中城市之间最大距离

  树直径+并查集判树+枚举子集 / <u>floyd+记忆化DFS/DP</u>

- 336\.回文对

  字符串哈希 / (trie+manacher)

- 352\.将数据流变为多个不相交区间

  模拟(链表/STL)

- 354\.俄罗斯套娃信封问题

  **单调栈+二分 (LIS)**

- 2488\.统计中位数为k的子数组

  前缀和 桶枚举

- 363\.矩形区域不超过k的最大数值和

  **二分优化枚举**
  
- 381\.O(1)时间插入、删除和获取随机元素-允许重复

  数据结构 STL <u>swap优化</u>
  
- 391\.完美矩阵

  (线段树+离散化+扫描线) / <u>扫描线</u> / <u>思维</u> / <u>格林公式</u>
  
- 407\.接雨水II

  **BFS+堆优化**
  
- 1626\.无矛盾的最佳球队

  DP <u>+树状数组优化</u>
  
- 410\.分割数组的最大值

  二分答案+贪心 / <u>DP</u>

- 1630\.等差子数组

  模拟 / <u>数学优化</u>

- 420\.强密码检测器

  **思维**
  
- 1032\.字符流

  <u>AC自动机</u> / 字符串哈希
  
- 1574\.删除最短的子数组使剩余数组有序

  <u>双指针</u> / 二分 

- 432\.全O(1)的数据结构

  哈希表+链表
  
- 1638\.统计只差一个字符的子串数目

  字符串哈希 / <u>枚举</u> / <u>DP</u>
  
- 1092\.最短公共超序列

  **DP**

- 1641\.统计字典序元音字符串的数目

  高阶前缀和 / DP
  
- 1039\.多边形三角剖分的最低得分

  <u>DP</u>
  
- 1053\.交换一次的先前排列

  <u>贪心</u> / STL二分
  
- 1000\.合并石子的最低成本

  **DP**
  
- 2417\.公因子的数目

  枚举 / <u>gcd优化</u>
  
- 1017\.负二进制转换

  模拟 进制
  
- 1040\.移动石子直到连续II

  思维+STL / 双指针

- 3\.无重复字符的最长子串

  双指针 / <u>前向星</u>
  
- 1125\.最小的必要团队

  BFS 状压
  
- 1147\.段式回文

  字符串哈希 贪心 双指针
  
- 1023\.驼峰式匹配

  小模拟 / <u>正则</u>
  
- 1157\.子数组中占绝大多数的元素

  **随机化+二分** / **摩尔投票+线段树**

- 2409\.统计共同度过的日子数

  日期 模拟 / <u>优化</u>
  
- 1026\.节点与其祖先之间的最大差值

  DFS
  
- 1043\.分隔数组以得到最大和

  **DP**
  
- 1187\.使数组严格递增

  DP+二分 / <u>优化</u>
  
- 1027\.最长等差数列

  DP
  
- 1105\.填充书架

  DP
  
- 1163\.按字典序排在最后的子串

  后缀数组 / <u>双指针</u>
  
- 1031\.两个非重叠子数组的最大和

  前缀和 / <u>DP+滑动窗口</u>
  
- 1048\.最长字符串链

  DP / 拓扑排序 / <u>后缀自动机</u>
  
- 1172\.餐盘栈

  数据结构
  
- 2423\.删除字符使频率相同

  STL
  
- 1003\.检查替换后的词是否有效

  贪心
  
- 2106\.摘水果

  前缀和 / <u>滑动窗口</u>
  
- 1419\.数青蛙

  贪心 小模拟
  
- 1010\.总持续时间可被60整除的歌曲

  枚举
  
- 1263\.推箱子

  BFS套BFS
  
- 1015\.可被k整除的最小整数

  数论
  
- 1016\.子串能表示从1到N的数字的二进制串

  枚举 / <u>滑动窗口+数学</u>
  
- 1330\.翻转子数组得到最大的数组值

  **思维**
  
- 1054\.距离相等的条形码

  STL
  
- 1335\.工作计划的最低难度

  DP / <u>单调栈优化</u>
  
- 2446\.判断两个事件是否存在冲突

  日期
  
- 1073\.负二进制数相加

  模拟
  
- 1079\.活字印刷

  DFS / <u>DP</u>
  
- 2514\.统计同位异构字符串数目

  组合数学
  
- LCP33\.蓄水

  贪心 <u>+优先队列</u>

- 1373\.二叉搜索子树的最大键值和

  DFS
  
- 1080\.根到叶路径上的不足节点

  DFS
  
- 1090\.受标签影响的最大值

  贪心
  
- 1377\.T秒后青蛙的位置

  DFS
  
- 2451\.差值数组不同的字符串

  模拟
  
- 1093\.大样本统计

  模拟
  
- 1439\.有序矩阵中的第k个最小数组和

  STL <u>+归并优化</u> <u>+DP剪枝</u> / <u>二分答案+DFS</u>
  
- 1110\.删点成林

  DFS

- 1130\.叶值的最小代价生成树

  区间DP / <u>单调栈</u>
  
- 2517\.礼盒的最大甜蜜度

  二分答案+STL / <u>二分答案</u>
  
- 2559\.统计范围内的元音字符串数目

  前缀和
  
- 1156\.单字符重复子串的最大长度

  小模拟 / 滑动窗口
  
- 2611\.老鼠和奶酪

  排序 / 优先级队列
  
- 1240.铺瓷砖

  **DFS**
  
- 2699\.修改图中的边权

  **Dijkstra序贪心** / **二分+最短路**
  
- 1170\.比较字符串最小字母出现频次

  前缀和
  
- 1171\.从链表中删去总和值为零的连续节点

  前缀和 STL 链表 / <u>优化</u>
  
- 1483\.树节点的第k个祖先

  树上k级祖先
  
- 2475\.数组中不等三元组的数目

  枚举 / <u>排序+指针</u> / <u>STL</u>
  
- 1375\.二进制字符串前缀一致的次数

  树状数组 / <u>思维</u>
  
- 1177\.构建回文串检测

  前缀和 / <u>前缀异或和</u>
  
- 1494\.并行课程 II

  DFS+BFS / <u>子集枚举</u>
  
- 2481\.分割圆的最少切割次数

  思维

- 1254\.统计封闭岛屿的数目

  BFS / DFS / 并查集
  
- 1262\.可被三整除的最大和

  贪心+二维DP / <u>贪心</u> / <u>DP</u>
  
- 1595\.连通两组点的最小成本

  **网络流** / **状压DP**
  
- LCP41\.黑白翻转棋

  模拟 / <u>BFS</u>
  
- 16\.19\.水域大小

  BFS
  
- 1659\.最大化网格幸福感

  <u>状压DP</u> / <u>轮廓线优化</u>
  
- 1401\.圆和矩形是否有重叠

  计算几何 / <u>思维</u>
  
- 2485\.找出中枢整数

  数学
  
- 1186\.删除一次得到子数组最大和

  **DP**
  
- 1681\.最小不兼容性

  **状压DP+枚举子集**
  
- 1253\.重构2行二进制矩阵

  构造
  
- 2490\.回环句

  小模拟
  
- 443\.两数相加II

  模拟链表
  
- 2178\.拆分成最多数目的正偶数之和

  贪心 构造
  
- 167\.两数之和 II - 输入有序数组

  二分 / <u>双指针</u>
  
- 15\.三数之和

  二分 / <u>双指针</u>
  
- 16\.最接近的三数之和

  二分 / <u>双指针</u>
  
- 1911\. 最大子序列交替和

  贪心 / <u>DP</u>
  
- 979\.在二叉树中分配硬币

  <u>DFS</u> / LCA+网络流
  
- 18\.四数之和

  二分 / 双指针
  
- 834\.树中距离之和

  树上DP
  
- 415\.字符串相加

  高精度
  
- 1851\.包含每个查询的最小区间

  离线 STL
  
- 918\.环形子数组的最大和

  前缀和+可删堆 / <u>前缀和+单调队列</u> / <u>DP</u>
  
- 1499\.满足不等式的最大值

  单调队列 / 堆
  
- 2050\.并行课程 III

  拓扑 / 记忆化DFS
  
- 141\.环形链表

  双指针 / 哈希表
  
- 142\.环形链表II

  <u>双指针</u> / 哈希表
  
- 143\.重排链表

  <u>双指针</u> / 模拟 
  
- 2681\.英雄的力量

  DP / 数学

- 822\.翻转卡片游戏

  小模拟 STL
  
- 21\.合并两个有序链表

  链表
  
- 980\.不同路径III

  BFS / DFS
  
- 1749\.任意子数组和的绝对值的最大值

  前缀和
  
- 1289\.下降路径最小和II

  DP 前缀和
  
- 88\.合并两个有序数组

  双指针
  
- 833\.字符串中的查找与替换

  模拟+双指针
  
- 1444\.切披萨的方案数

  DP+二维前缀和
  
- 1388\.3n 块披萨

  **DP** / **反悔贪心**
  
- 2337\.移动片段得到字符串

  贪心
  
- 849\.到最近的人的最大距离

  枚举 / 链表/前缀和
  
- 1782\.统计点对的数目

  二分 / <u>双指针</u>
  
- 225\.汇总区间

  小模拟
  
- 56\.合并区间

  排序
  
- 57\.插入区间

  小模拟
  
- 440\.字典序的第k小数字

  **DFS+trie**
  
- 823\.带因子的二叉树

  DP (+ <u>双指针优化</u>)

- 446\.等差数列划分 II

  **DP**

- 1654\.到家的最少跳跃次数

  <u>BFS</u>

- 458\.可怜的小猪

  思维+DP / <u>DP+组合数学</u> / <u>数学</u>



## 算法

### 力扣

#### 题单

##### 4. 寻找两个正序数组的中位数

[题目](https://leetcode.cn/problems/median-of-two-sorted-arrays/)

> 究极暴力：sort $O((n+m)\log (n+m))$
>
> 一般暴力：归并排序思想合并/双指针 $O(n+m)$
>
> 不那么暴力的二分套二分做法：对数组 $a$，二分枚举元素 $x$，然后在数组 $b$ 里 upper bound 找有多少个 $\ge x$ 的元素并确定下标，进而确定 $x$ 是第几大元素 (根据两个下标加起来数元素个数)。即本质二分套二分。如果找不出来再反着做一次。理论复杂度 $O(2\log m\log n)$。这是对偶数的概率。奇数的话可能更复杂一些。

题解：首先，$n+m$ 奇数找第 $k=\lfloor\dfrac{n+m}2\rfloor$ 大，否则找两次，分别找 $k,k+1$ 大。所以问题转化为求第 $k$ 大。

判断 $a,b$ 的第 $\lfloor\dfrac k2\rfloor$ 大元素 $x,y$，下标为 $i=\lfloor\dfrac k2\rfloor-1$，前缀共 $2\lfloor\dfrac k2\rfloor\le k$ 个数，有三种情况：

1. $x < y$， 则显然 $a$ 前 $\lfloor\dfrac k2\rfloor$ 都小于 $y$。并不知道 $a$ 的剩余右边元素如何。考虑下面样例：

   ```c++
   1 2 3 4
   5 6 7 8 9
   ```

   则中位数是 $5$。但无论样例如何变化，答案恒不可能取到 $a$ 前 $\lfloor\dfrac k2\rfloor$。因为如果取到了，则必然有 $k-1$ 个元素还要比答案处小，则不管怎么凑都会让 $y$ 选中为 $k-1$ 个的一部分，则 $x > y$ 从而产生矛盾。

   因此，在这种情况下，可以将 $a$ 的前 $\lfloor\dfrac k2\rfloor$ 个排除，缩减掉规模。

2. $x >y$，则同理，将 $b$ 的前 $\lfloor\dfrac k2\rfloor$ 个排除。

3. $x=y$。根据上文分析，可知可以视作任意一种情况，即 $a,b$ 其一可以排掉前 $\lfloor\dfrac k2\rfloor$ 个。

   注意不能两个都排掉前 $\lfloor\dfrac k2\rfloor$ 个。考虑下面样例：

   ```c++
   0 0
   0 0
   ```

   两次匹配 $x=y$，使得 $k-2-2=0$，产生错误(全删完了)。

进行一次判定后，可以减治为子问题，问题规模和 $k$ 都缩减。直到：

1. 任一方删完了，直接取另一方的第 $k$ 个
2. $k=1$，比较 $a,b$ 首元素取最小值
3. 任一方 $i$ 越界，调整 $i$ 指向较短者的最后一个

复杂度分析：考虑分析 $k$，通常而言 $i=\lfloor\dfrac k2\rfloor$ 即每次减半。因此是对数的，即 $O(\log(n+m))$。

```c++
class Solution
{
public:
    int kth(vector<int> &a, vector<int> &b, int k) // k为1是最小值
    {
        int al = 0, ar = a.size(); // n
        int bl = 0, br = b.size(); // m
        while (true)
        {
            //cout << al << ' ' << ar << ' ' << bl << ' ' << br << ' ' << k << '\n';
            if (al == ar)
                return b[bl + k - 1];
            if (bl == br)
                return a[al + k - 1];
            if (k == 1)
                return min(a[al], b[bl]);
            int i = k / 2-1;
            if (al + i >= ar)
                i = ar - al -1;
            if (bl + i >= br)
                i = br - bl -1;
            int x = a[al + i];
            int y = b[bl + i];
            //cout<<i<<' '<<x<<' '<<y<<'\n';
            ++i;
            if (x <= y)
            {
                al += i, k -= i;
            }
            else if (x > y)
            {
                bl += i, k -= i;
            }
        }
    }

    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size(), m = nums2.size();
        int k = (n + m + 1) / 2;
        if ((n + m) & 1)
        {
            return kth(nums1, nums2, k);
        }
        else
        {
            return (kth(nums1, nums2, k) + kth(nums1, nums2, k + 1)) / 2.;
        }
        return 0;
    }
};
```

##### 10. 正则表达式匹配

[题目](https://leetcode.cn/problems/regular-expression-matching/)

设 $dp_{i,j}$ 表示 $s$ 长为 $i$ 的前缀与模式串 $p$ 长为 $j$ 的前缀是否匹配。初始值为 $dp_{0,0}=1$

若 $p_j$ 不是 `*`，当且仅当 $s_i,p_j$ 匹配(要特判 `.`)时可以接上，即结果与 $dp_{i-1,j-1}$ 保持一致，否则恒不匹配。

如果是 `*`，那么可以不断尝试所有长度的连续匹配，即判断 $s_i,p_{j-1}$ 是否一致，如果不一致，舍去 `?*`，即与 $dp_{i,j-2}$ 保持一致，注意不是与 $i-1$，因为可以把整个 `?*` 从模式串删掉，然后让 $i$ 继续往下匹配。

如果一致，有两种选择，一个是进行匹配，一个是不进行匹配。如果进行匹配，消耗掉 $i$，但因为任意多个，所以 $j$ 没有消耗，与 $dp_{i-1,j}$ 一致，否则，与 $dp_{i,j-2}$ 一致。

可以滚动一下优化空间常数。则时间复杂度 $O(|s|\cdot |p|)$，空间复杂度 $O(|p|)$。

```c++
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        auto f = [&](const char &x, const char &y)
        {
            return x == y || y == '.';
        };
        int n = s.size(), m = p.size();
        s = ' ' + s, p = '+' + p;
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (p[j] != '*')
                {
                    if (i && f(s[i], p[j]))
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                }
                else
                {
                    if (j > 1)
                        dp[i][j] = dp[i][j - 2];
                    if (i && f(s[i], p[j - 1]))
                    {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }
                }
            }
        }
        return dp[n][m];
    }
};
```



##### 23. 合并K个升序链表

[题目](https://leetcode.cn/problems/merge-k-sorted-lists/)

> 朴素地不断两两合并时，因为一方不断变长，设每个链表长为 $m$，链表数是 $n$，可以 hack 出 $O(mn^2)$ 的复杂度，所以不可取

直接考虑把链表所有值丢进一个堆里，然后不断拿堆即可。当然直接排序也行。下面是一个 $O(mn\log (mn))$ 的解法。

```java
package lc;

//import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

class ListNode {
    int val;
    ListNode next;

    ListNode() {
    }

    ListNode(int val) {
        this.val = val;
    }

    ListNode(int val, ListNode next) {
        this.val = val;
        this.next = next;
    }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        Queue<Integer> q = new PriorityQueue<>();
        if (lists == null) {
            return null;
        }
        for (int i = 0; i < lists.length; ++i) {
            if (lists[i] == null) {
                continue;
            }
            q.add(lists[i].val);
            ListNode nx = lists[i].next;
            while (nx != null) {
                q.add(nx.val);
                nx = nx.next;
            }
        }
        if (q.isEmpty()) {
            return null;
        }
        ListNode hd = new ListNode(q.peek(), null), pr = hd;
        q.poll();
        while (!q.isEmpty()) {
            ListNode nw = new ListNode(q.peek(), null);
            q.poll();
            pr.next = nw;
            pr = nw;
        }
        return hd;
    }
}

public class lc23 {
    public static void main(String[] args) {
        ListNode sp = new ListNode(5, null);
        ListNode arr[] = { sp };
        Solution s = new Solution();
        s.mergeKLists(arr);
        System.out.println("Done");
    }
}
```

如果进行优化，即一开始只让每个链表头结点入堆，然后出堆的同时让下一个元素进堆，则规模可以缩减为 $n$，即复杂度优化为 $O(mn\log n)$，但是空间复杂度为 $O(n)$。

> 参考：
>
> ```java
> class Solution {
>     class Status implements Comparable<Status> {
>         int val;
>         ListNode ptr;
> 
>         Status(int val, ListNode ptr) {
>             this.val = val;
>             this.ptr = ptr;
>         }
> 
>         public int compareTo(Status status2) {
>             return this.val - status2.val;
>         }
>     }
> 
>     PriorityQueue<Status> queue = new PriorityQueue<Status>();
> 
>     public ListNode mergeKLists(ListNode[] lists) {
>         for (ListNode node: lists) {
>             if (node != null) {
>                 queue.offer(new Status(node.val, node));
>             }
>         }
>         ListNode head = new ListNode(0);
>         ListNode tail = head;
>         while (!queue.isEmpty()) {
>             Status f = queue.poll();
>             tail.next = f.ptr;
>             tail = tail.next;
>             if (f.ptr.next != null) {
>                 queue.offer(new Status(f.ptr.next.val, f.ptr.next));
>             }
>         }
>         return head.next;
>     }
> }
> ```

更优解：分治。减少空间复杂度。考虑若干轮合并，第一轮对 `12`, `34` …… 合并，然后不断使得问题规模折半。可以发现，每一轮合并，会遍历所有链表节点，即每一轮合并的复杂度是 $O(nm)$，共有 $\log n$ 轮，复杂度为 $O(nm\log n)$。空间复杂度为递归深度 $O(\log n)$。



##### 25\. K 个一组翻转链表

[题目](https://leetcode.cn/problems/reverse-nodes-in-k-group/)

无聊的链表模拟题。注意实现翻转的思想是，设右边界是下一个节点，顺序遍历当前区间节点，将当前节点的下一个指向边界，然后把自己更新为边界。手玩可知正是翻转操作。可以做到 $O(1)$。

```java
class Solution {
    private void swap(ListNode lf, ListNode rf) {
        ListNode nx = rf.next;
        while (lf != rf) {
            ListNode tnx = lf.next;
            lf.next = nx;
            nx = lf;
            lf = tnx;
        }
        rf.next = nx;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode hd = new ListNode();
        ListNode st = head;
        hd.next = st;
        ListNode it = hd;
        while (it != null) {
            ListNode jt = it;
            for (int i = 0; i < k; ++i) {
                jt = jt.next;
                if (jt == null) {
                    return hd.next;
                }
            }
            ListNode rf = jt;
            ListNode lf = it.next;
            swap(lf, rf);
            it.next = rf;
            it = lf;
        }
        return hd.next;
    }
}
```



##### 30. 串联所有单词的子串

[题目](https://leetcode.cn/problems/substring-with-concatenation-of-all-words/)

滑动窗口的思想。设原串长 $n$，单词有 $m$ 个长均为 $k$，分别从下标 $[i,k)$ 开始对原串尝试 $k$ 个一次地滑动，哈希优化查找。时间复杂度 $O(nk)$，空间复杂度是哈希存储的复杂度 $O(mk)$。

```java
class Solution {
    private void addFrom(HashMap<String, Integer> h, String w) {
        if (h.containsKey(w)) {
            h.put(w, h.get(w) + 1);
        } else {
            h.put(w, 1);
        }
    }

    private void removeFrom(HashMap<String, Integer> h, String s) {
        Integer t = h.get(s);
        if (t == 1) {
            h.remove(s);
        } else {
            h.put(s, t - 1);
        }
    }

    public List<Integer> findSubstring(String s, String[] words) {
        int n = s.length();
        int m = words.length;
        int k = words[0].length();
        List<Integer> ans = new LinkedList<>();
        for (int i = 0; i < k; ++i) {
            int bg = i, ed = i + m * k;
            if (ed > n) {
                continue;
            }
            HashMap<String, Integer> h = new HashMap<>();
            for (String w : words) {
                addFrom(h, w);
            }
            int suc = 0;
            for (; ed <= n; bg += k, ed += k) {
                for (int j = suc; j < m; ++j) {
                    String t = s.substring(bg + j * k, bg + k + j * k);
                    if (h.containsKey(t)) {
                        suc++;
                        removeFrom(h, t);
                    } else {
                        break;
                    }
                }
                if (suc == m) {
                    ans.add(bg);
                }
                if (suc > 0) {
                    String t = s.substring(bg, bg + k);
                    addFrom(h, t);
                    suc--;
                }
            }
        }
        return ans;
    }
}
```



##### 32. 最长有效括号

[题目](https://leetcode.cn/problems/longest-valid-parentheses/)

仅次于暴力的 acmer 思路：前缀和 + 二分 + 树状数组(/线段树/ST表)

设左括号 $+1$，右括号 $-1$，即求最长区间 $[l,r]$，满足 $\sum_{i=l}^r a_{i}=0$ 且 $\forall l\le i\le r$ 满足 $\sum_{j=l}^ia_j\ge 0$。

叠前缀和，既有 $s_r-s_{l-1}=0$ 且 $\forall l\le i\le r$ 有 $s_i-s_{l-1}\ge 0\Rightarrow s_i\ge s_{l-1}$。

即对每个 $l$，求 $\min s_i \ge s_{l-1}$ 的最大 $i$。

对 $s$ 建树状数组(线段树/ST表也行)，求静态区间最小值。可以证明对固定的 $l$，区间 $[l,i]$ 的最小值单调递减。满足二分，故二分找到最大的符合条件 $i$ 满足 $\forall l\le j\le i, s_i\ge s_{l-1}$，然后得到有效区间 $[l,i]$，用桶有序存每个值 $v$ 的所有下标，再二分桶找到该区间 $[l,i]$ 内满足 $s_j=s_{l-1}$ 的最大 $j$，答案取最大的 $j-l+1$。

复杂度为 $O(n\log^2 n)$。显然比不过官解但是起码能过题，属于是下策。

```java
import java.util.ArrayList;
import java.util.List;

class fenwick {
    int a[], t[], n;// a原数组,t树状数组min

    public fenwick(int n, int a[]) {
        this.n = n;
        this.a = a;
        this.t = new int[n + 1];
        for (int i = 0; i <= n; ++i) {
            t[i] = Integer.MAX_VALUE;
        }
        for (int i = 1; i <= n; ++i) {
            add(i, a[i]);
//            System.out.print(" " + t[i] + " ");
        }
//        System.out.println();
    }

    private void add(int i, int v) {
        for (; i <= n; i += Integer.lowestOneBit(i)) {
            if (v < t[i]) {// a[i]=min(a[i],v)
                t[i] = v;
            } else {
                return;
            }
        }
    }

    public int query(int l, int r) {
        int ans = Integer.MAX_VALUE;
        for (int i = r; i >= l;) {
            if (i - Integer.lowestOneBit(i) > l) {
                ans = Math.min(ans, t[i]);
                i -= Integer.lowestOneBit(i);
            } else {
                ans = Math.min(ans, a[i]);
                --i;
            }
        }
//        System.out.println(String.format("[%d,%d]=%d", l, r, ans));
        return ans;
    }
}

class Solution {
    public int longestValidParentheses(String s) {
        int n = s.length();
        int a[] = new int[n + 1];
        int cnt = 0, cntmi = 0;
        for (int i = 1; i <= n; ++i) {
            a[i] = a[i - 1] + (s.charAt(i - 1) == '(' ? 1 : -1);
            cnt = Math.max(cnt, a[i]);
            cntmi = Math.min(cntmi, a[i]);
        }
        @SuppressWarnings("unchecked")
        List<Integer> lt[] = new ArrayList[cnt - cntmi + 1];
        for (int i = 0; i < lt.length; ++i) {
            lt[i] = new ArrayList<>();
        }
        for (int i = 0; i <= n; ++i) {
//            System.out.println("" + a[i] + " " + cntmi);
            lt[a[i] - cntmi].add(i);// 下标偏移
        }
        int ans = 0;
        fenwick tr = new fenwick(n, a);
        for (int l = 1; l <= n; ++l) {
            int lf = l, rf = n, r = l - 1;
            while (lf <= rf) {
                int cf = (lf + rf) >> 1;
                int min = tr.query(l, cf);
                if (min >= a[l - 1]) {
                    r = Math.max(r, cf);
                    lf = cf + 1;
                } else {
                    rf = cf - 1;
                }
            }
//            System.out.println(String.format("<%d,%d>", l, r));
            int lc = 0, rc = lt[a[l - 1] - cntmi].size() - 1;
            if (rc < 0) {
                continue;
            }
            while (lc <= rc) {// 找到最大的<=r的a[l-1]
                int cc = (lc + rc) >> 1;
                int v = lt[a[l - 1] - cntmi].get(cc);
                if (v > r) {
                    rc = cc - 1;
                } else {
                    lc = cc + 1;
//                    System.out.println(v);
                    ans = Math.max(v - l + 1, ans);
                }
            }
        }
        return ans;
    }
}
```

**官解：**

**DP：**

设 $dp_i$ 表示以 $i$ 结尾的最长有效括号长度。

若 $s_{i-1..i}=$`()`，则 $dp_i=dp_{i-2}+2$。

若 =`))`，则看看左边右括号对应的最左左括号所指位置，则找到这段的最长长度 $dp_{i-1}$，即可定位到右边左括号所在位置，是该最左的前一位即 $i-dp_{i-1}-1$，如果它也是 `(`，这这一段可行，加上它之前是否可行连起来，即：
$$
dp_i=dp_{i-dp_{i-1}+2}+2+dp_{i-1}
$$
答案为 $\max dp$。显然 $O(n)$

```java
class Solution {
    public int longestValidParentheses(String s) {
        int maxans = 0;
        int[] dp = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s.charAt(i - dp[i - 1] - 1) == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = Math.max(maxans, dp[i]);
            }
        }
        return maxans;
    }
}
```

**栈：**

栈存下标，初始设有 $-1$ 在栈(设上一次成功匹配在 $-1$。遇到一个 `(` 就丢进去，遇到一个 `)` 就弹出栈顶，弹完之后，新栈顶是上一个未匹配下标，用当前下标相减得到当前长度。如果栈空了，则当前右括号无解，就将当前右括号下标丢进去作为失配下标。

```java

class Solution {
    public int longestValidParentheses(String s) {
        int maxans = 0;
        Deque<Integer> stack = new LinkedList<Integer>();
        stack.push(-1);
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                stack.pop();
                if (stack.isEmpty()) {
                    stack.push(i);
                } else {
                    maxans = Math.max(maxans, i - stack.peek());
                }
            }
        }
        return maxans;
    }
}
```

**贪心：**

以计数器代替栈。如果左括号与右数目相等，记录答案，如果右比左大，清零所有计数器。会被特殊情况 hack：`()((()))`，则后边的双重括号永远取到等。

因此再逆序处理一次，相等更新，左比右大清零。即正反都来一次。把上述解法的空间复杂度优化成常数。

```java
class Solution {
    public int longestValidParentheses(String s) {
        int left = 0, right = 0, maxlength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * right);
            } else if (right > left) {
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') {
                left++;
            } else {
                right++;
            }
            if (left == right) {
                maxlength = Math.max(maxlength, 2 * left);
            } else if (left > right) {
                left = right = 0;
            }
        }
        return maxlength;
    }
}
```



##### 37. 解数独

[题目](https://leetcode.cn/problems/sudoku-solver/)。签到题没啥好说的，当练语法了。

```java
class Solution {
    private boolean row[][], col[][], blo[][], suc;
    private char b[][];

    private int getBlockId(int i, int j) {
        return (i / 3) * 3 + j / 3;
    }

    private void dfs(int i, int j) {
        if (i == 9) {
            suc = true;
        }
        if (suc) {
            return;
        }
        int nexti = i, nextj = j + 1;
        if (nextj == 9) {
            nexti++;
            nextj = 0;
        }
        if (b[i][j] != '.') {
            dfs(nexti, nextj);
            return;
        }
        int k = getBlockId(i, j);
        for (int x = 1; x <= 9; ++x) {
            if (row[i][x] || col[j][x] || blo[k][x]) {
                continue;
            }
            row[i][x] = col[j][x] = blo[k][x] = true;
            b[i][j] = (char) ('0' + x);
            dfs(nexti, nextj);
            if (suc) {
                break;
            }
            row[i][x] = col[j][x] = blo[k][x] = false;
            b[i][j] = '.';
        }
    }

    public void solveSudoku(char[][] board) {
        row = new boolean[9][10];// 可以二进制压位为int优化
        col = new boolean[9][10];
        blo = new boolean[9][10];
        b = board;
        suc = false;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (b[i][j] == '.') {
                    continue;
                }
                int val = b[i][j] - '0';
                row[i][val] = true;
                col[j][val] = true;
                blo[getBlockId(i, j)][val] = true;
            }
        }
        dfs(0, 0);
    }
}
```

更优雅的官方写法：

```java
class Solution {
    private boolean[][] line = new boolean[9][9];
    private boolean[][] column = new boolean[9][9];
    private boolean[][][] block = new boolean[3][3][9];
    private boolean valid = false;
    private List<int[]> spaces = new ArrayList<int[]>();

    public void solveSudoku(char[][] board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    spaces.add(new int[]{i, j});
                } else {
                    int digit = board[i][j] - '0' - 1;
                    line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                }
            }
        }

        dfs(board, 0);
    }

    public void dfs(char[][] board, int pos) {
        if (pos == spaces.size()) {
            valid = true;
            return;
        }

        int[] space = spaces.get(pos);
        int i = space[0], j = space[1];
        for (int digit = 0; digit < 9 && !valid; ++digit) {
            if (!line[i][digit] && !column[j][digit] && !block[i / 3][j / 3][digit]) {
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = true;
                board[i][j] = (char) (digit + '0' + 1);
                dfs(board, pos + 1);
                line[i][digit] = column[j][digit] = block[i / 3][j / 3][digit] = false;
            }
        }
    }
}
```



##### 41\. 缺失的第一个正数

[题目](https://leetcode.cn/problems/first-missing-positive/) 即 mex 问题。为了节省空间，采用原地哈希的方法，直接修改原始数组。

显然 $> n$ 的以及负数都不贡献答案，不放都设为 $n+1$。那么剩下需要看的就是 $[1,n]$ 内的正数。不放用正负号代表布尔值信息，绝对值代表原信息，由此可以用一个整型变量存储二元信息。遍历一次，对绝对值 $a_i$，在对应位置 $a_i-1$ 下标标上负号，代表这个正数出现过。全部标完后，顺着扫到第一个正数就是没标的，就是缺失的。标记过程不损失原始合理数据。

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            int v = Math.abs(nums[i]) - 1;
            if (v < n) {// v+1<=n
                nums[v] = -Math.abs(nums[v]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
}
```

置换：另 $v=nums_i$，则如果它在 $[1,n]$ 内，它应该位于 $v-1$ 这个下标所在位置。我们把本来这个下标的数与它置换。换完后，$v$ 刷新，不断操作直到 $v$ 不需要换。特别注意相等会死循环，所以如果判断换完后不变，就不换了。每次换会让一个数归位，故复杂度为 $O(n)$

```java
class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
}
```



##### 42\. 接雨水

[题目](https://leetcode.cn/problems/trapping-rain-water/)

显然，对第 $i$ 列，它所能装的深度为左边最大与右边最大的最小值，即：$H_i=\min(\max_{j=0}^ih_j,\max_{j=i}^{n-1}h_j)$

分别用前缀 max，后缀 max 处理即可。

```java
class Solution {
    public int trap(int[] height) {
        int n = height.length;
        int ans = 0;
        int rmax[] = new int[n];// 后缀max
        rmax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            rmax[i] = Math.max(rmax[i + 1], height[i]);
        }
        int lmax = 0;// 前缀max
        for (int i = 0; i < n; ++i) {
            lmax = Math.max(lmax, height[i]);
            // h=min(max[0,i], max[i,n])
            int h = Math.min(lmax, rmax[i]);
            ans += h - height[i];
        }
        return ans;
    }
}
```

解法二：维护单调递减栈。每次遇到一个比栈顶更大的元素时，不断弹栈，弹后看看新栈顶的下标，与当前下标作差得水的宽度，然后取新栈顶与当前的最小高度作水的高度，往原图添加一段矩形的水。空间复杂度不变，没有本质上的优化。

```java
class Solution {
    public int trap(int[] height) {
        int ans = 0;
        Deque<Integer> stack = new LinkedList<Integer>();
        int n = height.length;
        for (int i = 0; i < n; ++i) {
            while (!stack.isEmpty() && height[i] > height[stack.peek()]) {
                int top = stack.pop();
                if (stack.isEmpty()) {
                    break;
                }
                int left = stack.peek();
                int currWidth = i - left - 1;
                int currHeight = Math.min(height[left], height[i]) - height[top];
                ans += currWidth * currHeight;
            }
            stack.push(i);
        }
        return ans;
    }
}
```

解法三：双指针。在前后缀 max 的基础上。初始设左右指针分别是最左右下标。维护指针所在的前后缀 max。

- 若当前前缀高度小于后缀高度，那么实际短板即 min 一定在前缀，不用管左边界往后的后缀究竟是多少就可以凭左边界的前缀求出左边界的答案
- 否则，可以同理求出右边界的答案
- 无论求出哪一方，问题规模都减少。所以缩减边界，继续判断边界值即可。本质上就是把本来每次只算最左边的，换成要么算最左边的要么算最右边的

```java
class Solution {
    public int trap(int[] height) {
        int ans = 0;
        int left = 0, right = height.length - 1;
        int leftMax = 0, rightMax = 0;
        while (left < right) {
            leftMax = Math.max(leftMax, height[left]);
            rightMax = Math.max(rightMax, height[right]);
            if (leftMax < rightMax) {
                ans += leftMax - height[left];
                ++left;
            } else {
                ans += rightMax - height[right];
                --right;
            }
        }
        return ans;
    }
}
```



##### 44\. 通配符匹配

[题目](https://leetcode.cn/problems/wildcard-matching/)，注意这不是正则表达式，`*` 是通杀，不需要看前面的。

```java
class Solution {
    final static char anysg = '?';
    final static char any = '*';

    boolean match(char x, char y) {
        return x == y || y == anysg;
    }

    public boolean isMatch(String s, String p) {
        int n = s.length(), m = p.length();
        boolean dp[][] = new boolean[2][m + 1];
        dp[0][0] = true;
        for (int i = 1; i <= m; ++i) {
            if (p.charAt(i - 1) == any) {
                dp[0][i] = true;
            } else {
                break;
            }
        }
        for (int i = 1, pre = 0, now = 1; i <= n; ++i, pre ^= 1, now ^= 1) {
            char si = s.charAt(i - 1);
            dp[now][0] = false;
            for (int j = 1; j <= m; ++j) {
                dp[now][j] = false;
                char pj = p.charAt(j - 1);
                if (pj == any) {
                    dp[now][j] = dp[now][j - 1] | dp[pre][j];
                } else if (match(si, pj)) {
                    dp[now][j] = dp[pre][j - 1];
                }
            }
        }
        return dp[n & 1][m];
    }
}
```

贪心：设 $u$ 是字符串(可空)，若 $p=* u_1*u_2*\cdots*u_k*$，则只要 $s$ 依次出现了 $u$ 作为子串，即可匹配成功。

如果不以 `*` 结尾，则倒序特判结尾的 $s,p$ 直到可以消解为上式或判无解为止。开头同理。

开头还可以另一种方法：

```java
class Solution {
    public boolean isMatch(String s, String p) {
        int sRight = s.length(), pRight = p.length();
        while (sRight > 0 && pRight > 0 && p.charAt(pRight - 1) != '*') {
            if (charMatch(s.charAt(sRight - 1), p.charAt(pRight - 1))) {
                --sRight;
                --pRight;
            } else {
                return false;
            }
        }

        if (pRight == 0) {
            return sRight == 0;
        }

        int sIndex = 0, pIndex = 0;
        int sRecord = -1, pRecord = -1;
        
        while (sIndex < sRight && pIndex < pRight) {
            if (p.charAt(pIndex) == '*') { //标记可以反悔的节点且不优先使用
                ++pIndex;
                sRecord = sIndex;
                pRecord = pIndex;
            } else if (charMatch(s.charAt(sIndex), p.charAt(pIndex))) {
                //优先尝试匹配非通配符
                ++sIndex;
                ++pIndex;
            } else if (sRecord != -1 && sRecord + 1 < sRight) {
                //如果不能匹配这个p子串，就倒回去匹配上一个通配符
                ++sRecord;
                sIndex = sRecord;
                pIndex = pRecord;
            } else {//开头没有通配符
                return false;
            }
        }

        return allStars(p, pIndex, pRight);//匹配完后p必须只剩下*
    }

    public boolean allStars(String str, int left, int right) {
        for (int i = left; i < right; ++i) {
            if (str.charAt(i) != '*') {
                return false;
            }
        }
        return true;
    }

    public boolean charMatch(char u, char v) {
        return u == v || v == '?';
    }
}
```

还有 AC 自动机解法：[参考](http://t.zoukankan.com/ambition-p-Wildcard.html)



##### 51\. N皇后

[题目](https://leetcode.cn/problems/n-queens/)，没啥好说的签到题。52 是双倍经验题，这里略，稍微改改即可。

```java
class Solution {
    private char[][] c;
    private boolean[] col, dia, dja;
    private int n, cnt;
    private List<List<String>> ans;

    private void dfs(int i) {
        if (cnt == n) {
            List<String> res = new ArrayList<>();
            for (int j = 0; j < n; ++j) {
                res.add(String.copyValueOf(c[j]));
            }
            ans.add(res);
            return;
        }
        for (int j = 0; j < n; ++j) {
            int y = i + j;
            int z = i - j + n;
            if (!col[j] && !dia[y] && !dja[z]) {
                col[j] = dia[y] = dja[z] = true;
                c[i][j] = 'Q';
                ++cnt;
                dfs(i + 1);
                --cnt;
                c[i][j] = '.';
                col[j] = dia[y] = dja[z] = false;
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        c = new char[n][n];
        col = new boolean[n];
        dia = new boolean[n * 2];
        dja = new boolean[n * 2];
        ans = new ArrayList<>();
        cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                c[i][j] = '.';
            }
        }
        dfs(0);
        return ans;
    }
}
```



##### 60\. 排列序列

[题目](https://leetcode.cn/problems/permutation-sequence/)，即逆康托展开裸题。

> 显然可以暴力 DFS 枚举所有排列，然后取第 k 个(++cnt)，但是这样太弱智了，所以考虑优化。

暴力：设一开始每个数都可用。当前位置 $i$ (从 $1$ 开始)如果选择剩下的数里第 $x$ 小的，则贡献 $(x-1)(n-i)!$。

当前第 $k$ 大需要比 $k-1$ 个大。对 $k$，除以当前阶乘 $(n-i)!$ 下取整，得到 $v$ 代表当前这位数需要选择可用里第 $v+1$ 个。暴力遍历可用数即可。复杂度 $O(n^2)$。

```java
class Solution {
    private boolean used[];
    private int n;

    private int findKthUnused(int k) {
//        System.out.println(k);
        for (int j = 1, cnt = 0; j <= n; ++j) {
            if (!used[j]) {
                ++cnt;
            }
            if (cnt == k) {
                used[j] = true;
                return j;
            }
        }
        return 0;// throw new Exception("Not reachable");
    }

    public String getPermutation(int n, int k) {
        this.n = n;
        StringBuilder res = new StringBuilder();
        used = new boolean[n + 1];
        k--;
        int fact = 1;
        for (int i = 2; i < n; ++i) {
            fact *= i;
        }
        for (int i = n - 1; i >= 1 && k > 0; fact /= i, --i) {
            int num = k / fact;
            k -= num * fact;
            res.append(findKthUnused(num + 1));
        }
        while (res.length() < n) {
//            System.out.println("qwq");
            res.append(findKthUnused(1));
        }
        return res.toString();
    }
}
```

线段树优化：(参考题目 [UVA11525](https://www.luogu.com.cn/problem/UVA11525)，考虑 $n\le 10^5$，且 $k$ 很大(如用阶乘多项式精确表示，以可以 $O(1)$ 计算高精度)，这题的模板代码可以参考我的 [算法模板集](https://github.com/lr580/algorithm_template))

上文求 $num$ 在阶乘多项式意义下可以直接由输入获得，也就是只需要把暴力的 `findKthUnused` 进行优化即可。需要支持单点修改和全长查询，考虑线段树分治。

设线段树每个叶子节点表示当前节点是否可用，非叶子节点表示它维护的区间里有多少个节点可用。从根节点出发，看看左子的可用数与当前需求数对比，如果大于等于就走左，否则走右。时空复杂度 $O(n\log n)$。

可以用 zkw 等小常数线段树继续优化，这里直接上普通线段树了。树状数组没能想到实现方法，我认为不可行。

```java
class Solution {
    private boolean used[];
    private int n;
    private int t[];// 线段树节点,1e5的话要开至少short

    private void build(int p, int l, int r) {
        if (l == r) {
            t[p] = 1;
            return;
        }
        int c = (l + r) >> 1;
        build(p << 1, l, c);
        build(p << 1 | 1, c + 1, r);
        t[p] = t[p << 1] + t[p << 1 | 1];
    }

    private int modify(int p, int l, int r, int cnt) {
        if (l == r) {
            t[p] = 0;
            return l;
        }
        int res = 0, c = (l + r) >> 1;
        if (t[p << 1] >= cnt) {
            res = modify(p << 1, l, c, cnt);
        } else {
            res = modify(p << 1 | 1, c + 1, r, cnt - t[p << 1]);
        }
        t[p] = t[p << 1] + t[p << 1 | 1];
        return res;
    }

    private int findKthUnused(int k) {
        return modify(1, 1, n, k);
    }

    public String getPermutation(int n, int k) {
        this.n = n;
        t = new int[n * 4];
        build(1, 1, n);
        StringBuilder res = new StringBuilder();
        k--;
        int fact = 1;
        for (int i = 2; i < n; ++i) {
            fact *= i;
        }
        for (int i = n - 1; i >= 1 && k > 0; fact /= i, --i) {
            int num = k / fact;
            k -= num * fact;
            res.append(findKthUnused(num + 1));
        }
        while (res.length() < n) {
            res.append(findKthUnused(1));
        }
        return res.toString();
    }
}
```



##### 65\. 有效数字

[题目](https://leetcode.cn/problems/valid-number/)

手搓了个正则表达式：

```java
class Solution {
    public boolean isNumber(String s) {
        String regex = "[\\+\\-]?(\\d+|\\d*\\.\\d+|\\d+\\.\\d*)([eE][\\+\\-]?\\d+)?";
        return s.matches(regex);
    }
}
```

> 另一种写法：`"[+-]?(?:\\d+\\.?\\d*|\\.\\d+)(?:[Ee][+-]?\\d+)?"` (也就是说注意 `[]` 里不用转义正负)

手写思路：写一个有限状态自动机。则复杂度是 $O(n)$ 和空间 $O(1)$

![fig1](img/1.png)

```java
class Solution {
    public boolean isNumber(String s) {
        Map<State, Map<CharType, State>> transfer = new HashMap<State, Map<CharType, State>>();
        Map<CharType, State> initialMap = new HashMap<CharType, State>() {{
            put(CharType.CHAR_NUMBER, State.STATE_INTEGER);
            put(CharType.CHAR_POINT, State.STATE_POINT_WITHOUT_INT);
            put(CharType.CHAR_SIGN, State.STATE_INT_SIGN);
        }};
        transfer.put(State.STATE_INITIAL, initialMap);
        Map<CharType, State> intSignMap = new HashMap<CharType, State>() {{
            put(CharType.CHAR_NUMBER, State.STATE_INTEGER);
            put(CharType.CHAR_POINT, State.STATE_POINT_WITHOUT_INT);
        }};
        transfer.put(State.STATE_INT_SIGN, intSignMap);
        Map<CharType, State> integerMap = new HashMap<CharType, State>() {{
            put(CharType.CHAR_NUMBER, State.STATE_INTEGER);
            put(CharType.CHAR_EXP, State.STATE_EXP);
            put(CharType.CHAR_POINT, State.STATE_POINT);
        }};
        transfer.put(State.STATE_INTEGER, integerMap);
        Map<CharType, State> pointMap = new HashMap<CharType, State>() {{
            put(CharType.CHAR_NUMBER, State.STATE_FRACTION);
            put(CharType.CHAR_EXP, State.STATE_EXP);
        }};
        transfer.put(State.STATE_POINT, pointMap);
        Map<CharType, State> pointWithoutIntMap = new HashMap<CharType, State>() {{
            put(CharType.CHAR_NUMBER, State.STATE_FRACTION);
        }};
        transfer.put(State.STATE_POINT_WITHOUT_INT, pointWithoutIntMap);
        Map<CharType, State> fractionMap = new HashMap<CharType, State>() {{
            put(CharType.CHAR_NUMBER, State.STATE_FRACTION);
            put(CharType.CHAR_EXP, State.STATE_EXP);
        }};
        transfer.put(State.STATE_FRACTION, fractionMap);
        Map<CharType, State> expMap = new HashMap<CharType, State>() {{
            put(CharType.CHAR_NUMBER, State.STATE_EXP_NUMBER);
            put(CharType.CHAR_SIGN, State.STATE_EXP_SIGN);
        }};
        transfer.put(State.STATE_EXP, expMap);
        Map<CharType, State> expSignMap = new HashMap<CharType, State>() {{
            put(CharType.CHAR_NUMBER, State.STATE_EXP_NUMBER);
        }};
        transfer.put(State.STATE_EXP_SIGN, expSignMap);
        Map<CharType, State> expNumberMap = new HashMap<CharType, State>() {{
            put(CharType.CHAR_NUMBER, State.STATE_EXP_NUMBER);
        }};
        transfer.put(State.STATE_EXP_NUMBER, expNumberMap);

        int length = s.length();
        State state = State.STATE_INITIAL;

        for (int i = 0; i < length; i++) {
            CharType type = toCharType(s.charAt(i));
            if (!transfer.get(state).containsKey(type)) {
                return false;
            } else {
                state = transfer.get(state).get(type);
            }
        }
        return state == State.STATE_INTEGER || state == State.STATE_POINT || state == State.STATE_FRACTION || state == State.STATE_EXP_NUMBER || state == State.STATE_END;
    }

    public CharType toCharType(char ch) {
        if (ch >= '0' && ch <= '9') {
            return CharType.CHAR_NUMBER;
        } else if (ch == 'e' || ch == 'E') {
            return CharType.CHAR_EXP;
        } else if (ch == '.') {
            return CharType.CHAR_POINT;
        } else if (ch == '+' || ch == '-') {
            return CharType.CHAR_SIGN;
        } else {
            return CharType.CHAR_ILLEGAL;
        }
    }

    enum State {
        STATE_INITIAL,
        STATE_INT_SIGN,
        STATE_INTEGER,
        STATE_POINT,
        STATE_POINT_WITHOUT_INT,
        STATE_FRACTION,
        STATE_EXP,
        STATE_EXP_SIGN,
        STATE_EXP_NUMBER,
        STATE_END
    }

    enum CharType {
        CHAR_NUMBER,
        CHAR_EXP,
        CHAR_POINT,
        CHAR_SIGN,
        CHAR_ILLEGAL
    }
}
```



##### 68\. 文本左右对齐

[题目](https://leetcode.cn/problems/text-justification/)，模拟题

```java
class Solution {
    public List<String> fullJustify(String[] words, int maxWidth) {
        ArrayList<String> ans = new ArrayList<>();
        ArrayList<String> line = new ArrayList<>();
        int n = words.length;
        int cur = 0, raw = 0;
        for (int i = 0; i < n; ++i) {
            int m = words[i].length();
            if (line.size() > 0) {
                ++m;
            }
            if (cur + m > maxWidth) {
                int rem = maxWidth - raw;
                int cnt = line.size() - 1;
                int avg = rem / Math.max(1, cnt);
                int red = rem - avg * cnt;
//                System.out.println(String.format("s=%s rem=%d cnt=%d avg=%d red=%d", words[i], rem,
//                        cnt, avg, red));
                StringBuilder sb = new StringBuilder();
                sb.append(line.get(0));
                String spc0 = "", spc1;
                for (int j = 0; j < avg; ++j) {
                    spc0 += ' ';
                }
                spc1 = spc0 + ' ';
                for (int j = 1, je = line.size(); j < je; ++j) {
                    if (red > 0) {
                        --red;
                        sb.append(spc1);
                    } else {
                        sb.append(spc0);
                    }
                    sb.append(line.get(j));
                }
                raw = cur = 0;
                line.clear();
                while (sb.length() < maxWidth) {
                    sb.append(' ');
                }
                ans.add(sb.toString());
            }
            cur += words[i].length() + (line.size() > 0 ? 1 : 0);
            raw += words[i].length();
            line.add(words[i]);
//            System.out.println(
//                    String.format("%s cur=%d cnt=%d raw=%d", words[i], cur, line.size(), raw));
        }
        if (line.size() > 0) {
            StringBuilder sb = new StringBuilder();
            sb.append(line.get(0));
            for (int j = 1, je = line.size(); j < je; ++j) {
                sb.append(' ');
                sb.append(line.get(j));
            }
            while (sb.length() < maxWidth) {
                sb.append(' ');
            }
            ans.add(sb.toString());
        }
        return ans;
    }
}
```



##### 72\.编辑距离

[题目](https://leetcode.cn/problems/edit-distance/)

DP模板题。设 $dp_{i,j}$ 为 $word1$ 长为 $i$ 的前缀与 $word2$ 变为 $j$ 的前缀的最少操作次数。初始值为：

$dp_{0,0}=0$ 因为空串等于空串。而 $dp_{0,i}=dp_{i,0}=i$ 这意味着从空串到一个串或反过来只能插入那个串。

对一般情况，有：

1. 替换。如果本来尾部就一样就不用换，否则要，即：$dp_{i,j}=dp_{i-1,j-1}+[word1_i=word2_j]$

2. 插入。考虑空位置视为 `\0` 字符，那么跟替换是本质相同的。

   可以把 $word1_i$ 换成 $word2_j$ 或相反，代价加一，即在上述基础上：
   $$
   dp_{i,j}=\min(dp_{i,j},dp_{i-1,j}+1,dp_{i,j-1}+1)
   $$

3. 删除。对一个串删除一个字符等价于对另一个串插入一个字符。那么上文的相反即等于删除操作了。

压一下数组，可以做到 $O(\min(|word1,word2|))$ 的复杂度(把更短的视为 $word2$ 即可，这里懒得这么做了) 

```java
class Solution {
    public int minDistance(String word1, String word2) {
        int n = word1.length(), m = word2.length();
        int dp[][] = new int[2][m + 1];
        for (int i = 1; i <= m; ++i) {
            dp[0][i] = i;
        }
        for (int i = 1, now = 1, prv = 0; i <= n; ++i, now ^= 1, prv ^= 1) {
            dp[now][0] = i;
            for (int j = 1; j <= m; ++j) {
                int res = Math.min(dp[now][j - 1], dp[prv][j]) + 1;
                if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
                    res = Math.min(res, dp[prv][j - 1]);
                } else {
                    res = Math.min(res, dp[prv][j - 1] + 1);
                }
                dp[now][j] = res;
            }
        }
        return dp[n & 1][m];
    }
}
```



##### 76\.最小覆盖子串

[题目](https://leetcode.cn/problems/minimum-window-substring/submissions/)，滑窗简单题。

```java
class Solution {
    private int sat, cnt[], req[], tot;

    private void add(int i) {
        if (req[i] > 0 && cnt[i] < req[i]) {
            ++sat;
        }
        ++cnt[i];
    }

    private void del(int i) {
        if (req[i] > 0 && cnt[i] <= req[i]) {
            --sat;
        }
        --cnt[i];
    }

    public String minWindow(String s, String t) {
        int n = s.length();
        sat = 0;
        cnt = new int[257];
        req = new int[257];
        tot = t.length();
        for (int i = 0; i < tot; ++i) {
            ++req[t.charAt(i)];
        }
        int min = 114514, lf = 0, mlf = 0;
        for (int i = 0; i < n; ++i) {// i=rf
            add(s.charAt(i));
            while (sat == tot) {
                int len = i - lf + 1;
                if (len < min) {
                    min = len;
                    mlf = lf;
                }
                del(s.charAt(lf));
                lf++;
            }
        }
        if (min == 114514) {
            return "";
        }
        return s.substring(mlf, mlf + min);
    }
}
```



##### 84\.柱状图中的最大矩形

[题目](https://leetcode.cn/problems/largest-rectangle-in-histogram/)

> 一时没想出正解，感觉可能是滑窗但不太会滑。所以直接上了个竞赛套路。

对 heights 数组叠 ST 表维护静态区间最小值，然后枚举每个高度 $h=heights_i$，然后以 $i$ 为中心，二分地左右找出最远边界 $l,r$，分别满足 $\min_{j=l}^iheights_j,\min_{j=i}^rheights_j$，然后更新答案即可。时空复杂度都是 $O(n\log n)$。

> 如果用线段树/树状数组代替 ST 表，空间复杂度降为 $O(n)$，但时间复杂度变为 $O(n\log^2 n)$

```java
class SparseTable {
    private int st[][];
    public static int lg2[];

    public SparseTable(int[] a) {
        int n = a.length;
        lg2 = new int[n + 1];
        for (int i = 2; i <= n; ++i) {
            lg2[i] = lg2[i / 2] + 1;
        }
        int top = lg2[n] + 1;
        st = new int[n][top];
        for (int i = 0; i < n; ++i) {
            st[i][0] = a[i];
        }
        for (int j = 1; j < top; ++j) {
            for (int i = 0; i + (1 << j) - 1 < n; ++i) {
                st[i][j] = Math.min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    public int query(int l, int r) {
        int p = lg2[r - l + 1];
        return Math.min(st[l][p], st[r - (1 << p) + 1][p]);
    }
}

class Solution {
    public int largestRectangleArea(int[] heights) {
        SparseTable st = new SparseTable(heights);
        int ans = 0, n = heights.length;
        for (int i = 0; i < n; ++i) {
            int h = heights[i];
            int lf = 0, rf = i, l = i, r = i, cf;
            while (lf <= rf) {
                cf = (lf + rf) >> 1;
                if (st.query(cf, i) >= h) {
                    l = cf;
                    rf = cf - 1;
                } else {
                    lf = cf + 1;
                }
            }
            lf = i;
            rf = n - 1;
            while (lf <= rf) {
                cf = (lf + rf) >> 1;
                if (st.query(i, cf) >= h) {
                    r = cf;
                    lf = cf + 1;
                } else {
                    rf = cf - 1;
                }
            }
            ans = Math.max(ans, (r - l + 1) * h);
        }
        return ans;
    }
}
```

AC 了然后看了一眼答案标题，单调栈，瞬间知道正解怎么做了。

上述要每个 $i$ 对应的最远 $l,r$ 可以用单调栈维护。维护单调递增栈，每个元素被退栈之时得到它的右边界。然后再继续来一遍，得到左边界。之后同理操作即可。

```java
class Solution {
    public int largestRectangleArea(int[] heights) {
        int n = heights.length, ans = 0;
        int l[] = new int[n], r[] = new int[n];
        Arrays.fill(r, n - 1);
        ArrayDeque<Integer> s = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            int h = heights[i];
            while (s.size() > 0 && heights[s.peekFirst()] > h) {
                r[s.peekFirst()] = i - 1;
                s.pop();// popFirst
            }
            s.push(i);// addFirst
        }
        s.clear();
        for (int i = n - 1; i >= 0; --i) {
            int h = heights[i];
            while (s.size() > 0 && heights[s.peekFirst()] > h) {
                l[s.peekFirst()] = i + 1;
                s.pop();
            }
            s.push(i);
        }
        for (int i = 0; i < n; ++i) {
            ans = Math.max(ans, (r[i] - l[i] + 1) * heights[i]);
        }
        return ans;
    }
}
```



##### 85\.最大矩形

[题目](https://leetcode.cn/problems/maximal-rectangle/)

悬线法。其实有点像 DP 的思路。枚举每个 `1` 的位置作为矩形的最高点，然后找到以该点向上最上的前提下，向左向右最远能扩展多远。设 $l_{i,j},r_{i,j},u_{i,j}$ 分别表示点 $(i,j)$ 向左右上的最远距离。

初始值为 $l_{i,j}=r_{i,j}=j$ 对每个 `1` 有 $u_{i,j}=1$。对每一行顺序预处理，若 $(i,j)$ 左边也是 `1`，则 $l_{i,j}=l_{i,j-1}$；同理，逆序预处理 $r$。得到在只有一个高度时，同行的最远扩展。

接下来，如果 $(i,j)$ 上边也是 `1`，则将其与上边拓展，$u_{i,j}=u_{i-1,j}+1$，且这一行的左右要同时满足上面一行需要满足的条件，DP 地转移过来即  $l_{i,j}=\max(l_{i,j},l_{i-1,j}),r_{i,j}=\max(r_{i,j},r_{i-1,j})$

压缩一下 DP，可以做到 $O(nm)$ 时间复杂度和 $O(m)$ 空间复杂度

```java
class Solution {
    static final char req = '1';

    public int maximalRectangle(char[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        // (i,j)能到达的左右最远的点纵坐标l,r
        int l[][] = new int[2][m];
        int r[][] = new int[2][m];
        int u[][] = new int[2][m];// 向上
        int ans = 0;
        for (int i = 0, now = 0, pre = 1; i < n; ++i, now ^= 1, pre ^= 1) {
            for (int j = 0; j < m; ++j) {
                l[now][j] = r[now][j] = j;
                u[now][j] = 1;
            }
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == req && matrix[i][j - 1] == req) {
                    l[now][j] = l[now][j - 1];
                }
            }
            for (int j = m - 2; j > 0; --j) {
                if (matrix[i][j] == req && matrix[i][j + 1] == req) {
                    r[now][j] = r[now][j + 1];
                }
            }
            for (int j = 0; j < m; ++j) {
                if (i > 0 && matrix[i][j] == req && matrix[i - 1][j] == req) {// 同时满足多行
                    r[now][j] = Math.min(r[now][j], r[pre][j]);
                    l[now][j] = Math.max(l[now][j], l[pre][j]);
                    u[now][j] = u[pre][j] + 1;
                }
                if (matrix[i][j] == req) {
                    ans = Math.max(ans, (r[now][j] - l[now][j] + 1) * u[now][j]);
                }
            }
        }
        return ans;
    }
}
```

单调栈解法：类比上一题，可以把只有前 $i$ 行的图看成柱状图，用 $n$ 次单调栈即可求解，复杂度相同。从略。



##### 87\.扰乱字符串

[题目](https://leetcode.cn/problems/scramble-string/)

设 $dp_{i,j,k}$ 表示子串 $s1_{i..i+k},s2_{j..j+k}$ 是否满足扰乱。定义 $f(s1,s2)$ 判断两个字符串是否各字符个数一致。则如果 $(i,j,k)$ 状态本身 $f$ 假，则必假。否则，如果满足下面其一，该状态为真：

1. $(i,j,k)$ 两子串相等(终态)
2. 将 $k$ 拆分为 $l,k-l$， $(i,j,l),(i+l,j+l,k-l)$ 分别为真(选择不交换)
3. 将 $k$ 拆分为 $l,k-l$，$(i,j+k-l,l),(i+l,j,k-l)$ 分别为真(选择交换)

如果都不满足就为假。可以看到对一个状态，需要判断 $O(k)$ 次。所以用记忆化搜索 DFS，可以用 $O(n^4)$ 的时间复杂度和 $O(n^3)$ 的空间复杂度实现。

```java
class Solution {
    private String s1, s2;
    private final static int suc = 1, fail = 2;
    private int dp[][][];
    private static int bin1[] = new int[130];
    private static int bin2[] = new int[130];

    public boolean check(int l1, int l2, int len) {
        boolean same = true;
        for (int i = l1, ie = l1 + len; i < ie; ++i) {
            ++bin1[s1.charAt(i)];
        }
        for (int i = l2, ie = l2 + len; i < ie; ++i) {
            ++bin2[s2.charAt(i)];
        }
        for (int i1 = l1, ie = l1 + len; i1 < ie; ++i1) {
//            System.out.println(String.format("%c %c %d %d",
//                    s1.charAt(i1),s2.charAt(i2),bin1[s1.charAt(i1)],bin2[s2.charAt(i2)]));
            same &= bin1[s1.charAt(i1)] == bin2[s1.charAt(i1)];
        }
        for (int i = l1, ie = l1 + len; i < ie; ++i) {
            --bin1[s1.charAt(i)];
        }
        for (int i = l2, ie = l2 + len; i < ie; ++i) {
            --bin2[s2.charAt(i)];
        }
//        System.out.println(String.format("%s %s %d", s1.substring(l1, l1 + len),
//                s2.substring(l2, l2 + len), same ? 1 : 0));
        return same;
    }

    private boolean dfs(int l1, int l2, int len) {
//        System.out.println(String.format("%d %d %d mhere", l1, l2, len));
        if (dp[l1][l2][len] != 0) {
            return dp[l1][l2][len] == suc;
        }
        if (s1.substring(l1, l1 + len).equals(s2.substring(l2, l2 + len))) {//==判断会死
//            System.out.println(String.format("%d %d %d mtrue", l1, l2, len));
            dp[l1][l2][len] = suc;
            return true;
        }
        if (!check(l1, l2, len)) {
            dp[l1][l2][len] = fail;
            return false;
        }
        for (int i = 1; i < len; ++i) {
            if (dfs(l1, l2, i) && dfs(l1 + i, l2 + i, len - i)) {
                dp[l1][l2][len] = suc;
                return true;
            }
            if (dfs(l1, l2 + len - i, i) && dfs(l1 + i, l2, len - i)) {
                dp[l1][l2][len] = suc;
                return true;
            }
        }
        dp[l1][l2][len] = fail;
        return false;
    }

    public boolean isScramble(String s1, String s2) {
        this.s1 = s1;
        this.s2 = s2;
        assert s1.length() == s2.length();
        int n = s1.length();
        dp = new int[n][n][n + 1];
        return dfs(0, 0, n);
    }
}
```



##### 115\.不同的子序列

[题目](https://leetcode.cn/problems/distinct-subsequences/)

设 $dp_{i,j}$ 表示从下标 $i$ 开始的 $s$ 后缀里下标 $j$ 开始的 $t$ 后缀出现的个数。初始值是 $dp_{i,m}=1$

如果 $s_i=t_j$，当前字符选与不选都可以，即 $dp_{i,j}=dp_{i+1,j+1}+dp_{i+1,j}$。否则只能不选，即 $dp_{i,j}=dp_{i+1,j}$。输出 $dp_{0,0}$ 即可

```java
class Solution {
    public int numDistinct(String s, String t) {
        int n = s.length(), m = t.length();
        int dp[][] = new int[n + 1][m + 1];
        for (int i = 0; i < n; ++i) {
            dp[i][m] = 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            char sc = s.charAt(i);
            for (int j = m - 1; j >= 0; --j) {
                dp[i][j] = dp[i + 1][j];
                if (sc == t.charAt(j)) {
                    dp[i][j] += dp[i + 1][j + 1];
                }
            }
        }
        return dp[0][0];
    }
}
```



##### 123\.买卖股票的最佳时机III

[题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/)

如果只做一笔交易，即求 $\max a_j-a_i,i < j$，直接枚举 $j$ 然后整前缀 min 即可。

做两笔交易，即求 $\max a_j-a_i+a_l-a_k, i < j < k < l$。

跟一笔交易一样，先处理 $i,j$，然后对 $(j,n]$ 部分，反过来，即逆序枚举 $k$，寻找最大的 $a_l$。根据两次枚举 $j,k$ 可以分别求出前缀 max 答案 $lans$ 和后缀答案 $rans$，故答案为：$ans=\max_{i=1}^{n-1}lans_i+rans_{i+1}$。

```java
class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0, n = prices.length;
        int lmin[] = new int[n]; //其实lmin,rmax不用数组也行
        Arrays.fill(lmin, Integer.MAX_VALUE);
        int lans[] = new int[n];
        lmin[0] = prices[0];
        for (int i = 1; i < n; ++i) {
            int v = prices[i] - lmin[i - 1];
            lans[i] = Math.max(v, lans[i - 1]);
            ans = Math.max(v, ans);// 只交易一次
            lmin[i] = Math.min(prices[i], lmin[i - 1]);// min[0,i]
        }
        // 枚举边界[i,n),求这个区间的 max a_j-a_i
        int rmax[] = new int[n];
        rmax[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            int rans = rmax[i + 1] - prices[i];
            int res = (i > 0 ? lans[i - 1] : 0) + rans;
            ans = Math.max(res, ans);
            rmax[i] = Math.max(rmax[i + 1], prices[i]);
        }
        return ans;
    }
}
```

答案解法：DP

```java
 class Solution {
     public int maxProfit(int[] prices) {
         int n = prices.length;
         int buy1 = prices[0], sell1 = 0;
         int buy2 = prices[0], sell2 = 0;
         for (int i = 1; i < n; ++i) {
             buy1 = Math.min(buy1, prices[i]);
             sell1 = Math.max(sell1, prices[i] - buy1);
             buy2 = Math.min(buy2, prices[i] - sell1);
             sell2 = Math.max(sell2, prices[i] - buy2);
         }
         return sell2;
     }
 }
/* buy1是前缀min[0,i]
故sell1=max a_j-a_i,即我解法的lans[i]
buy2是在已经操作一次下，min( a_k - (max a_j-a_i) )
上一次卖的越多,max越大,min越小,所以会取到卖的最多的一次
*/
```



##### 124\.二叉树中的最大路径和

[题目](https://leetcode.cn/problems/binary-tree-maximum-path-sum/)，弱智签到题。

```java
class Solution {
    private int ans;

    // 返回当前子树从根出发的最大路径长
    private int dfs(TreeNode u) {
        if (u == null) {
            return 0;
        }
        int lv = 0, rv = 0;
        if (u.left != null) {
            lv = Math.max(0, dfs(u.left));
        }
        if (u.right != null) {
            rv = Math.max(0, dfs(u.right));
        }
        ans = Math.max(ans, u.val + lv + rv);
        return Math.max(lv, rv) + u.val;
    }

    public int maxPathSum(TreeNode root) {
        ans = Integer.MIN_VALUE;
        dfs(root);
        return ans;
    }
}
```



##### 126\.单词接龙II

[https://leetcode.cn/problems/word-ladder-ii/](https://leetcode.cn/problems/word-ladder-ii/)

垃圾题目，复杂度指数。抽象为在一个图输出所有最短路，非多项式复杂度。

```java
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> res = new ArrayList<>();
        // 因为需要快速判断扩展出的单词是否在 wordList 里，因此需要将 wordList 存入哈希表，这里命名为「字典」
        Set<String> dict = new HashSet<>(wordList);
        // 特殊用例判断
        if (!dict.contains(endWord)) {
            return res;
        }

        dict.remove(beginWord);

        // 第 1 步：广度优先搜索建图
        // 记录扩展出的单词是在第几次扩展的时候得到的，key：单词，value：在广度优先搜索的第几层
        Map<String, Integer> steps = new HashMap<String, Integer>();
        steps.put(beginWord, 0);
        // 记录了单词是从哪些单词扩展而来，key：单词，value：单词列表，这些单词可以变换到 key ，它们是一对多关系
        Map<String, List<String>> from = new HashMap<String, List<String>>();
        int step = 1;
        boolean found = false;
        int wordLen = beginWord.length();
        Queue<String> queue = new ArrayDeque<String>();
        queue.offer(beginWord);
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String currWord = queue.poll();
                char[] charArray = currWord.toCharArray();
                // 将每一位替换成 26 个小写英文字母
                for (int j = 0; j < wordLen; j++) {
                    char origin = charArray[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        charArray[j] = c;
                        String nextWord = String.valueOf(charArray);
                        if (steps.containsKey(nextWord) && step == steps.get(nextWord)) {
                            from.get(nextWord).add(currWord);
                        }
                        if (!dict.contains(nextWord)) {
                            continue;
                        }
                        // 如果从一个单词扩展出来的单词以前遍历过，距离一定更远，为了避免搜索到已经遍历到，且距离更远的单词，需要将它从 dict 中删除
                        dict.remove(nextWord);
                        // 这一层扩展出的单词进入队列
                        queue.offer(nextWord);

                        // 记录 nextWord 从 currWord 而来
                        from.putIfAbsent(nextWord, new ArrayList<>());
                        from.get(nextWord).add(currWord);
                        // 记录 nextWord 的 step
                        steps.put(nextWord, step);
                        if (nextWord.equals(endWord)) {
                            found = true;
                        }
                    }
                    charArray[j] = origin;
                }
            }
            step++;
            if (found) {
                break;
            }
        }

        // 第 2 步：回溯找到所有解，从 endWord 恢复到 beginWord ，所以每次尝试操作 path 列表的头部
        if (found) {
            Deque<String> path = new ArrayDeque<>();
            path.add(endWord);
            backtrack(from, path, beginWord, endWord, res);
        }
        return res;
    }

    public void backtrack(Map<String, List<String>> from, Deque<String> path, String beginWord, String cur, List<List<String>> res) {
        if (cur.equals(beginWord)) {
            res.add(new ArrayList<>(path));
            return;
        }
        for (String precursor : from.get(cur)) {
            path.addFirst(precursor);
            backtrack(from, path, beginWord, precursor, res);
            path.removeFirst();
        }
    }
}
```

> 双向 BFS：(这个不能过题)

> ```java
> public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
>     List<List<String>> ans = new ArrayList<>();
>     if (!wordList.contains(endWord)) {
>         return ans;
>     }
>     // 利用 BFS 得到所有的邻居节点
>     HashMap<String, ArrayList<String>> map = new HashMap<>();
>     bfs(beginWord, endWord, wordList, map);
>     ArrayList<String> temp = new ArrayList<String>();
>     // temp 用来保存当前的路径
>     temp.add(beginWord);
>     findLaddersHelper(beginWord, endWord, map, temp, ans);
>     return ans;
> }
> 
> private void findLaddersHelper(String beginWord, String endWord, HashMap<String, ArrayList<String>> map,
>                                ArrayList<String> temp, List<List<String>> ans) {
>     if (beginWord.equals(endWord)) {
>         ans.add(new ArrayList<String>(temp));
>         return;
>     }
>     // 得到所有的下一个的节点
>     ArrayList<String> neighbors = map.getOrDefault(beginWord, new ArrayList<String>());
>     for (String neighbor : neighbors) {
>         temp.add(neighbor);
>         findLaddersHelper(neighbor, endWord, map, temp, ans);
>         temp.remove(temp.size() - 1);
>     }
> }
> 
> //利用递归实现了双向搜索
> private void bfs(String beginWord, String endWord, List<String> wordList, HashMap<String, ArrayList<String>> map) {
>     Set<String> set1 = new HashSet<String>();
>     set1.add(beginWord);
>     Set<String> set2 = new HashSet<String>();
>     set2.add(endWord);
>     Set<String> wordSet = new HashSet<String>(wordList);
>     bfsHelper(set1, set2, wordSet, true, map);
> }
> 
> // direction 为 true 代表向下扩展，false 代表向上扩展
> private boolean bfsHelper(Set<String> set1, Set<String> set2, Set<String> wordSet, boolean direction,
>                           HashMap<String, ArrayList<String>> map) {
>     //set1 为空了，就直接结束
>     //比如下边的例子就会造成 set1 为空
>     /*	"hot"
> 		"dog"
> 		["hot","dog"]*/
>     if(set1.isEmpty()){
>         return false;
>     }
>     // set1 的数量多，就反向扩展
>     if (set1.size() > set2.size()) {
>         return bfsHelper(set2, set1, wordSet, !direction, map);
>     }
>     // 将已经访问过单词删除
>     wordSet.removeAll(set1);
>     wordSet.removeAll(set2);
> 
>     boolean done = false;
> 
>     // 保存新扩展得到的节点
>     Set<String> set = new HashSet<String>();
> 
>     for (String str : set1) {
>         //遍历每一位
>         for (int i = 0; i < str.length(); i++) {
>             char[] chars = str.toCharArray();
> 
>             // 尝试所有字母
>             for (char ch = 'a'; ch <= 'z'; ch++) {
>                 if(chars[i] == ch){
>                     continue;
>                 }
>                 chars[i] = ch;
> 
>                 String word = new String(chars);
> 
>                 // 根据方向得到 map 的 key 和 val
>                 String key = direction ? str : word;
>                 String val = direction ? word : str;
> 
>                 ArrayList<String> list = map.containsKey(key) ? map.get(key) : new ArrayList<String>();
>                 
>                 //如果相遇了就保存结果
>                 if (set2.contains(word)) {
>                     done = true;
>                     list.add(val);
>                     map.put(key, list);
>                 }
> 
>                 //如果还没有相遇，并且新的单词在 word 中，那么就加到 set 中
>                 if (!done && wordSet.contains(word)) {
>                     set.add(word);
>                     list.add(val);
>                     map.put(key, list);
>                 }
>             }
>         }
>     }
> 
>     //一般情况下新扩展的元素会多一些，所以我们下次反方向扩展  set2
>     return done || bfsHelper(set2, set, wordSet, !direction, map);
> 
> }
> ```



##### 127\.单词接龙

[题目](https://leetcode.cn/problems/word-ladder/)

上题的代码改改就行。

```java
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

class Solution {
    private HashMap<String, Integer> h;
    private ArrayList<Integer> e[];
    private int n, m;

    private int id(String s) {
        if (!h.containsKey(s)) {
            h.put(s, n++);
        }
        return h.get(s);
    }

    @SuppressWarnings("unchecked")
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        h = new HashMap<>();
        n = 0;
        wordList.add(beginWord);
        m = wordList.size();
        e = new ArrayList[m + 2];
        for (int i = 0; i < m; ++i) {
            e[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; ++i) {
            String s = wordList.get(i);
            id(s);
            for (int j = i + 1; j < m; ++j) {
                String t = wordList.get(j);
                int dif = 0;
                for (int k = 0, ke = s.length(); k < ke; ++k) {
                    dif += s.charAt(k) != t.charAt(k) ? 1 : 0;
                }
                if (dif == 1) {
                    e[i].add(j);
                    e[j].add(i);
                }
            }
        }
        if (h.get(endWord) == null) {
            return 0;
        }
        int s = id(beginWord), t = id(endWord);
        int vis[] = new int[m];
        Deque<Integer> q = new LinkedList<>();
        q.push(s);
        vis[s] = 1;
        while (!q.isEmpty()) {
            Integer u = q.poll();
            if (u == t) {
                return vis[t];
            }
            for (int i = 0, ie = e[u].size(); i < ie; ++i) {
                int v = e[u].get(i);
                if (vis[v] == 0) {
                    vis[v] = vis[u] + 1;
                    q.addLast(v);
                }
            }

        }
        return 0;
    }
}
```



##### 132\.分割回文串II

[题目](https://leetcode.cn/problems/palindrome-partitioning-ii/)

设 $isPara_{i,j}$ 表示子串 $s_{l..r}$ 是否是回文串。初始值是 $s_{i..i}=1$。当我们要判断 $s_{l..r}$ 是否为回文串时，令 $k=\lfloor\dfrac{r-l+1}2\rfloor$，只需要判断 $s_{l..l+k}$ 与 $s'_{r-k..r}$ 是否一致即可，其中 $s'$ 是 $s$ 的转置。可以预处理字符串哈希来 $O(1)$ 进行判断。如果一致 $isPara_{l..r}$ 就为真。

设 $dp_i$ 表示长以 $i$ 下标结尾的前缀的最少分割次数。初始设 $dp_i=i$，若 $isPara_{0,i}$ 则 $dp_i=0$，否则 $dp_i=\min_{j=0}^{i-1} dp_{j}+1$ 其中 $j$ 必须满足 $isPara_{j+1..i}$ 为真。

时空复杂度均为 $O(n^2)$，但常数比题解差(多了字符串哈希的 $O(n)$)。

```java
class StringHash {
    private static final int p0 = 131;
    private int h[], n, p[];

    public StringHash(String s) {
        n = s.length();
        p = new int[n + 1];
        h = new int[n + 1];
        p[0] = 1;
        for (int i = 1; i <= n; ++i) {
            p[i] = p[i - 1] * p0;
        }
        for (int i = 1; i <= n; ++i) {
            h[i] = h[i - 1] * p0 + s.charAt(i - 1);
        }
    }

    public int hash(int l, int r) {// 下标从0算
        return h[r + 1] - h[l] * p[r - l + 1];
    }
}

class Solution {
    public int minCut(String s) {
        int n = s.length();
        boolean isPara[][] = new boolean[n][n];
        int dp[] = new int[n];
        StringHash s0 = new StringHash(s);
        StringBuilder sr = new StringBuilder();
        for (int i = n - 1; i >= 0; --i) {
            sr.append(s.charAt(i));
        }
        StringHash s1 = new StringHash(sr.toString());
        for (int i = 0; i < n; ++i) {
            isPara[i][i] = true;
        }
        for (int len = 2; len <= n; ++len) { //其实for i,j 即可
            int k = len / 2;
            for (int l = 0, r = len - 1; r < n; ++l, ++r) {
                if (s0.hash(l, l + k) == s1.hash(n - 1 - r, n - 1 - r + k)) {
                    isPara[l][r] = true;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            dp[i] = isPara[0][i] ? 0 : i;
            for (int j = 0; j < i; ++j) {
                if (isPara[j + 1][i]) {
                    dp[i] = Math.min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n - 1];
    }
}
```

> 没想出是否有 `manacher/回文自动机` 的解法，如果有佬有类似解法欢迎分享。

题解即不需使用字符串哈希，利用 $isPara$ 自身来推导 $isPara$，若 $isPara_{i..j}=1$ 且 $s_{i-1}=s_{j+1}$ 则 $isPara_{i-1..j+1}=1$。

```java
class Solution {
    public int minCut(String s) {
        int n = s.length();
        boolean[][] g = new boolean[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(g[i], true);
        }

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = s.charAt(i) == s.charAt(j) && g[i + 1][j - 1];
            }
        }

        int[] f = new int[n];
        Arrays.fill(f, Integer.MAX_VALUE);
        for (int i = 0; i < n; ++i) {
            if (g[0][i]) {
                f[i] = 0;
            } else {
                for (int j = 0; j < i; ++j) {
                    if (g[j + 1][i]) {
                        f[i] = Math.min(f[i], f[j] + 1);
                    }
                }
            }
        }

        return f[n - 1];
    }
}
```

 

##### 140\.单词拆分II

[题目](https://leetcode.cn/problems/word-break-ii/)

无聊的搜索题，做了不少常数优化(具体而言，字符串哈希+建图缓存)，0ms 100%了：

```java
class Pair { //其实有v就行,p+v.length=nx
    public int nx;
    public String v;

    Pair(int nx, String v) {
        this.nx = nx;
        this.v = v;
    }
}

class Solution {
    private int n;
    private List<Pair> e[];
    private final static int p0 = 131;
    private String log[];
    private List<String> ans;

    private void dfs(int p, int cnt) {
        if (p == n) {
            StringBuilder res = new StringBuilder();
            res.append(log[0]);
            for (int i = 1; i < cnt; ++i) {
                res.append(' ');
                res.append(log[i]);
            }
            ans.add(res.toString());
            return;
        }
        for (int i = 0, ie = e[p].size(); i < ie; ++i) {
            Pair pr = e[p].get(i);
            log[cnt] = pr.v;
            dfs(pr.nx, cnt + 1);
        }
    }

    @SuppressWarnings("unchecked")
    public List<String> wordBreak(String s, List<String> wordDict) {
        n = s.length();
        e = new ArrayList[n + 1];
        for (int i = 0; i <= n; ++i) {
            e[i] = new ArrayList<>();
        }
        int m = wordDict.size();
        int hw[] = new int[m];
        int hl[] = new int[m];
        int pw[] = new int[Math.max(m, n) + 1];
        pw[0] = 1;
        for (int i = 1, ie = pw.length; i < ie; ++i) {
            pw[i] = pw[i - 1] * p0;
        }
        int h[] = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            h[i] = h[i - 1] * p0 + s.charAt(i - 1);
        }
        for (int i = 0; i < m; ++i) {
            int hr = 0;
            String t = wordDict.get(i);
            for (int j = 0, je = t.length(); j < je; ++j) {
                hr = hr * p0 + t.charAt(j);
            }
            hw[i] = hr;
            hl[i] = t.length();
        }
        for (int r = 1; r <= n; ++r) {
            for (int i = 0; i < m; ++i) {
                int l = r - hl[i];
                if (l >= 0) {
                    int hs = h[r] - h[l] * pw[r - l];
                    if (hs == hw[i]) {
                        e[l].add(new Pair(r, wordDict.get(i)));
                    }
                }
            }
        }
        log = new String[n];
        ans = new ArrayList<>();
        dfs(0, 0);
        return ans;
    }
}
```

> 对以下极端样例运行效果良好：
>
> ```java
> "aaaaaaaaaaaaaaaaaaaa"
> ["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]
> ```



##### 149\.直线上最多的点数

[题目](https://leetcode.cn/problems/max-points-on-a-line/)

> 正解是枚举两点组合求所有斜率，统计最大出现频率的斜率即可。

随机化。任意枚举 $m$ 次不同两点 $x,y$，然后枚举所有其他点 $z$，统计有多少个点满足 $\vec{xz}\times\vec{xy}=0$，则有多少个除 $x,y$ 的点与直线 $xy$ 共线。

最差情况是答案为 $3$，即只有 $x,y,z$ 三点共线，其他点均不满足三点共线(显然恒满足任两点共线)。设共有 $n$ 点，则枚举一次能枚举到 $x,y,z$ 其二的概率为 $\dfrac{3}{n}$，枚举一次没能找到答案的概率为 $1-\dfrac3n$。枚举 $m$ 次都没找到答案的概率为 $(1-\dfrac3n)^m$，即如果只枚举 $m$ 次，能求出正解的概率至少是 $p=1-(1-\dfrac3n)^m$。

计算得，对 $n=300$，若 $m=100$ 则 $p\approx 0.63$，若 $m=10^3$ 则 $p\approx0.99995$。考虑到需要同时满足 $t$ 个测试点，不妨设 $t=50$，则 $p^t\approx 0.998$ (实际效果疑似不佳，当 $m=2000$ 时较准)

复杂度为 $O(nm)$。考虑到 $m$ 较大，实际上不如答案优。

```java
class Solution {
    private int[][] p;

    private int[] sub(int a, int b) {
        int[] r = new int[] { p[b][0] - p[a][0], p[b][1] - p[a][1] };
        return r;
    }

    private int cross(int[] i, int[] j) {
        return Math.abs(i[1] * j[0] - i[0] * j[1]);
    }

    public int maxPoints(int[][] points) {
        Random ran = new Random();
        p = points;
        int n = points.length;
        if (n == 1) {
            return 1;
        }
        int ans = 2;
        for (int h = 0; h < 1000; ++h) {
            int x = 0, y = 0;
            while (x == y) {
                x = ran.nextInt(n);
                y = ran.nextInt(n);
            }
            int cnt = 2;
            for (int i = 0; i < n; ++i) {
                int k = cross(sub(x, y), sub(x, i));
                if (i != x && i != y && k == 0) {
                    ++cnt;
                }
            }
            ans = Math.max(ans, cnt);
        }
        return ans;
    }
}
```



##### 154\.寻找旋转排序数组中的最小值II

[题目](https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array-ii/)

```java
class Solution {
    public int findMin(int[] nums) {
        int low = 0;
        int high = nums.length - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            } else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            } else {
                high -= 1;
            }
        }
        return nums[low];
    }
}
```



##### 164\.最大间距

[题目](https://leetcode.cn/problems/maximum-gap/)

使用 $2^8$ 作为基数，方便位运算。然后使用常数较优的内层计数排序写法。期望是 $O(4n)=O(n)$ 的复杂度。

> 以 java 为例，判题时间 2023/2/7 结果为 14ms(超90%) 和 54.5mb(超55%)。

```java
class Solution {
    private int a[], b[], cnt[], n;

    private void radixsort() {
        final int mask = (1 << 8) - 1;
        int x[] = a, y[] = b;// 指针
        for (int i = 0; i < 32; i += 8) {
            for (int j = 0; j < (1 << 8); ++j) {
                cnt[j] = 0;
            }
            for (int j = 0; j < n; ++j) {
                ++cnt[x[j] >> i & mask];
            }
            for (int sum = 0, j = 0; j < (1 << 8); ++j) {
                sum += cnt[j];
                cnt[j] = sum - cnt[j];
            }
            for (int j = 0; j < n; ++j) {
                y[cnt[x[j] >> i & mask]++] = x[j];
            }
            int t[] = x; // swap
            x = y;
            y = t;
        }
    }

    public int maximumGap(int[] nums) {
        n = nums.length;
        a = nums;
        b = new int[n];
        cnt = new int[1 << 8];
        radixsort();
        int ans = 0;
        for (int j = 0, i = 1; i < n; ++i, ++j) {
            ans = Math.max(ans, a[i] - a[j]);
        }
        return ans;
    }
}
```

> 桶排序：
>
> 基本思想：分块，最值一定在相邻块间取得。
>
> ```java
> class Solution {
>     public int maximumGap(int[] nums) {
>         int n = nums.length;
>         if (n < 2) {
>             return 0;
>         }
>         int minVal = Arrays.stream(nums).min().getAsInt();
>         int maxVal = Arrays.stream(nums).max().getAsInt();
>         int d = Math.max(1, (maxVal - minVal) / (n - 1));
>         int bucketSize = (maxVal - minVal) / d + 1;
> 
>         int[][] bucket = new int[bucketSize][2];
>         for (int i = 0; i < bucketSize; ++i) {
>             Arrays.fill(bucket[i], -1); // 存储 (桶内最小值，桶内最大值) 对， (-1, -1) 表示该桶是空的
>         }
>         for (int i = 0; i < n; i++) {
>             int idx = (nums[i] - minVal) / d;
>             if (bucket[idx][0] == -1) {
>                 bucket[idx][0] = bucket[idx][1] = nums[i];
>             } else {
>                 bucket[idx][0] = Math.min(bucket[idx][0], nums[i]);
>                 bucket[idx][1] = Math.max(bucket[idx][1], nums[i]);
>             }
>         }
> 
>         int ret = 0;
>         int prev = -1;
>         for (int i = 0; i < bucketSize; i++) {
>             if (bucket[i][0] == -1) {
>                 continue;
>             }
>             if (prev != -1) {
>                 ret = Math.max(ret, bucket[i][0] - bucket[prev][1]);
>             }
>             prev = i;
>         }
>         return ret;
>     }
> }
> ```



##### 174\.地下城游戏

[题目]()

DP。逆序才没有后效性，考虑样例：

```python
[[ 1,-3, 3],
 [ 0,-2, 0],
 [-3,-3,-3]]
```

```java
class Solution {
    public int calculateMinimumHP(int[][] dungeon) {
        int n = dungeon.length, m = dungeon[0].length;
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 0; i <= n; ++i) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        dp[n][m - 1] = dp[n - 1][m] = 1;
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                int minn = Math.min(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = Math.max(minn - dungeon[i][j], 1);
            }
        }
        return dp[0][0];
    }
}
```



##### 188\.买卖股票的最佳时机IV

[题目](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/)

设 $g_{i,j}$ 是对前 $j$ 天，已经买卖了前 $i-1$ 笔交易且买入了第 $i$ 笔交易下最低的总额，即 $\min a_{buy_k}+\sum_{k=1}^{i-1}a_{sell_k}-a_{buy_k},buy_k,sell_k\le j$

设 $f_{i,j}$ 是对前 $j$ 天，已经买卖了前 $i$ 笔的最高利润。即 $\max\sum_{k=1}^ia_{sell_k}-a_{buy_k},,buy_k,sell_k\le j$

具体推导参见 `123` 题，将其简单推广即可得到本题答案。

```java
class Solution {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        int f[][] = new int[2][n + 1];
        int g[][] = new int[2][n + 1];

        for (int i = 1, pre = 0, now = 1; i <= k; ++i, pre ^= 1, now ^= 1) {
            g[now][0] = 100000000;
            for (int j = 1; j <= n; ++j) {
                int v = prices[j - 1];
                f[now][j] = Math.max(f[now][j - 1], v - g[now][j - 1]);
                g[now][j] = Math.min(g[now][j - 1], v - f[pre][j - 1]);
            }
        }
        return f[k & 1][n];
    }
}
```

[神仙题解 wqs二分](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/solution/yi-chong-ji-yu-wqs-er-fen-de-you-xiu-zuo-x36r/)



##### 212\.单词搜索II

[题目](https://leetcode.cn/problems/word-search-ii/)

复杂度分析：从每个格子开始走，第一次可以走四方向、之后每次不能往回走只能走三个方向，故复杂度是 $O(nm4\cdot 3^{l-1})\approx 10^7$。

```java
class Solution {
    int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public List<String> findWords(char[][] board, String[] words) {
        Trie trie = new Trie();
        for (String word : words) {
            trie.insert(word);
        }

        Set<String> ans = new HashSet<String>();
        for (int i = 0; i < board.length; ++i) {
            for (int j = 0; j < board[0].length; ++j) {
                dfs(board, trie, i, j, ans);
            }
        }

        return new ArrayList<String>(ans);
    }

    public void dfs(char[][] board, Trie now, int i1, int j1, Set<String> ans) {
        if (!now.children.containsKey(board[i1][j1])) {
            return;
        }
        char ch = board[i1][j1];
        Trie nxt = now.children.get(ch);
        if (!"".equals(nxt.word)) {
            ans.add(nxt.word);
            nxt.word = ""; //去重后从630ms优化到了79ms
        }

        if (!nxt.children.isEmpty()) {
            board[i1][j1] = '#';
            for (int[] dir : dirs) {
                int i2 = i1 + dir[0], j2 = j1 + dir[1];
                if (i2 >= 0 && i2 < board.length && j2 >= 0 && j2 < board[0].length) {
                    dfs(board, nxt, i2, j2, ans);
                }
            }
            board[i1][j1] = ch;
        }

        if (nxt.children.isEmpty()) {
            now.children.remove(ch);
        }
    }
}

class Trie {
    String word;
    Map<Character, Trie> children;
    boolean isWord;

    public Trie() {
        this.word = "";
        this.children = new HashMap<Character, Trie>();
    }

    public void insert(String word) {
        Trie cur = this;
        for (int i = 0; i < word.length(); ++i) {
            char c = word.charAt(i);
            if (!cur.children.containsKey(c)) {
                cur.children.put(c, new Trie());
            }
            cur = cur.children.get(c);
        }
        cur.word = word;
    }
}
```



##### 214\.最短回文串

[题目](https://leetcode.cn/problems/shortest-palindrome/)

解法一：用 manacher 求出最长回文子串，然后找出最长回文前缀(即对每个回文中心，若它的左端点是首下标(即第一个分割符))，设回文半径为 $r$，则它的长度是 $2r-1$，显然是奇数，则其原串长度为 $\lfloor\dfrac{2r-1}{2}\rfloor=r-1$。找到最大的即可。

设最长回文前缀为 $s_0$，其余部分为 $s'$ 即 $s=s_0s'$，则答案为 $\overline s's_0s'$，其中 $\overline s'$ 是 $s'$ 的反串。

时空复杂度 $O(n)$。

```java
class Solution {
    public String shortestPalindrome(String s) {
        int n0 = s.length();
        StringBuilder sb = new StringBuilder(2 * n0 + 3);
        sb.append("^#");
        for (int i = 0; i < n0; ++i) {
            sb.append(s.charAt(i));
            sb.append('#');
        }
        sb.append('?');
        String t = sb.toString();
        int n = t.length();
        int p[] = new int[n], r = 0, c = 0, len = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (i <= r) {
                p[i] = Math.min(p[c * 2 - i], r - i + 1);
            }
            while (t.charAt(i + p[i]) == t.charAt(i - p[i])) {
                ++p[i];
            }
            if (i + p[i] > r) {
                r = p[i] + i - 1;
                c = i;
            }
            if (i - p[i] + 1 == 1) {
                len = Math.max(len, (2 * p[i] - 1) / 2);
            }
        }
        StringBuilder ans = new StringBuilder(n0);
        for (int i = n0 - 1; i >= len; --i) {
            ans.append(s.charAt(i));
        }
        ans.append(s);
        return ans.toString();
    }
}
```

解法二：字符串哈希。我们只需要枚举 $O(n)$ 次前缀与其反串的等长后缀是否相等，可以不记忆化哈希数组，达到 $O(1)$ 空间复杂度和 $O(n)$ 时间复杂度。

```java
class Solution {
    public String shortestPalindrome(String s) {
        int n = s.length();
        int base = 131, mod = 1000000007;
        int left = 0, right = 0, mul = 1;
        int best = -1;
        for (int i = 0; i < n; ++i) {
            left = (int) (((long) left * base + s.charAt(i)) % mod);
            right = (int) ((right + (long) mul * s.charAt(i)) % mod);
            if (left == right) {
                best = i;
            }
            mul = (int) ((long) mul * base % mod);
        }
        String add = (best == n - 1 ? "" : s.substring(best + 1));
        StringBuffer ans = new StringBuffer(add).reverse();
        ans.append(s);
        return ans.toString();
    }
}
```

解法三：设 $s$ 为模式串，$s'$ 为原串，用 KMP 在 $s'$ 里匹配出最长的 $s$ 前缀，就是最长的回文串。



##### 218\.天际线问题

[题目](https://leetcode.cn/problems/the-skyline-problem/)

> 截止 2023/2/13，用时10ms(超94%)和内存44.5MB(超71%)。

小模拟，细节有点多。将 $l,r$ 看成是时间轴。

1. 维护可删(对顶)大根堆 $q$。支持对数内插入、取最大元素和删除任意元素。

   对当前 building $(l,r,h)$，拆分为两个操作即在 $l$ 时刻往 $q$ 插入 $h$，然后在 $r$ 时刻删除 $h$。为此维护一个时刻的小根堆 $nx$，代表即将要删除的 $(r,h)$，按 $r$ 排序。

2. 将所有插入删除操作按时间排序。具体而言，可以在每次插入 $h$ 之前，先处理 $nx$ 里所有 $\le l$ 的 $(r,h)$，即不断弹堆。每次处理后，查询 $q$ 的最高元素 $h_\max$，若上一个最高元素不是 $h_\max$，就往答案里插入 $(r,h_{\max})$。

   处理完之后，再对插入 $h$ 后再取 $h_\max$ 再同上操作一次。

3. 特判所有时间相等的情况，考虑 `[[1,2,1],[1,2,2],[1,2,3]]`，需要对同一时间去重。则往答案里插入前，先查看上一个插入的值的时间是否与这个相等，如果相等，直接修改上一个插入的值，而不是插入。或者直接删除上一个答案再插入。

时间复杂度为 $O(n\log n)$，空间复杂度为 $O(n)$。

```java
class node implements Comparable<node> {
    public int i, v;

    public node(int i, int v) {
        this.i = i;
        this.v = v;
    }

    @Override
    public int compareTo(node o) {// i<o.i
        return this.i - o.i;
    }
}

class heap { // 对顶堆(大根堆)
    private PriorityQueue<Integer> a, b;

    public heap() {
        a = new PriorityQueue<>();
        b = new PriorityQueue<>();
    }

    void insert(int x) {
        a.add(-x);
    }

    void erase(int x) {
        b.add(-x);
    }

    int top() {
        while (!b.isEmpty() && a.peek().equals(b.peek())) {
            a.poll();
            b.poll();
        }
        return -a.peek();
    }

    int pop() {
        int t = top();
        a.poll();
        return t;
    }
}

class Solution {
    private int prvh, t;
    private List<List<Integer>> ans;

    private void judge(int h, int now) {
//        System.out.println(String.format("%d %d", now, h));
        if (h != prvh) {
            prvh = h;
            List<Integer> tmp = new ArrayList<>();
            tmp.add(now);
            tmp.add(h);
            if (!ans.isEmpty() && ans.get(ans.size() - 1).get(0) == now) {
                ans.remove(ans.size() - 1);
            }
            ans.add(tmp);
        }
    }

    public List<List<Integer>> getSkyline(int[][] buildings) {
        int n = buildings.length;
        PriorityQueue<node> nx = new PriorityQueue<>();
        heap q = new heap();
        q.insert(0);
        prvh = 0;
        t = -1;
        ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
//            System.out.println("next " + buildings[i][0]);
            t = buildings[i][0];
            nx.add(new node(buildings[i][1], buildings[i][2]));
            while (!nx.isEmpty()) {
                node nd = nx.peek();
                int now = nd.i;
                if (now >= t) {
                    break;
                }
                nx.poll();
                q.erase(nd.v);
                judge(q.top(), now);
            }
            q.insert(buildings[i][2]);
            int h = q.top();
            judge(h, t);
        }
        while (!nx.isEmpty()) {
            node nd = nx.poll();
            q.erase(nd.v);
            judge(q.top(), nd.i);
        }
        return ans;
    }
}
```

题解：

```java
class Solution {
    public List<List<Integer>> getSkyline(int[][] buildings) {
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> b[1] - a[1]);
        List<Integer> boundaries = new ArrayList<Integer>();
        for (int[] building : buildings) {
            boundaries.add(building[0]);
            boundaries.add(building[1]);
        }
        Collections.sort(boundaries);

        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        int n = buildings.length, idx = 0;
        for (int boundary : boundaries) {
            while (idx < n && buildings[idx][0] <= boundary) {
                pq.offer(new int[]{buildings[idx][1], buildings[idx][2]});
                idx++;
            }
            while (!pq.isEmpty() && pq.peek()[0] <= boundary) {
                pq.poll();
            }

            int maxn = pq.isEmpty() ? 0 : pq.peek()[1];
            if (ret.size() == 0 || maxn != ret.get(ret.size() - 1).get(1)) {
                ret.add(Arrays.asList(boundary, maxn));
            }
        }
        return ret;
    }
}
```



##### 220\.存在重复元素III

[题目](https://leetcode.cn/problems/contains-duplicate-iii/)

维护 $\pm t$ 内的滑窗，对中心点，维护 set，然后用 bound 方法找是否存在

```java
class node implements Comparable<node> {
    public int v, i;

    public node(int v, int i) {
        this.v = v;
        this.i = i;
    }

    public int compareTo(node o) {
        if (o.v != this.v) {
            return this.v - o.v;
        }
        return this.i - o.i;
    }

//    @Override 没必要
//    public boolean equals(Object obj) {
//        node o = (node) obj;// 下文程序不会传node外
//        return this.v == o.v && this.i == o.i;
//    }

    @Override
    public String toString() {
        return "(" + this.v + "," + this.i + ")";
    }
}

class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int indexDiff, int valueDiff) {
        TreeSet<node> s = new TreeSet<>();
        int n = nums.length, k = indexDiff, t = valueDiff;
        for (int i = 0, ie = Math.min(k, n); i < ie; ++i) {
            s.add(new node(nums[i], i));
        }
        for (int c = 0, l = c - k, r = c + k; c < n; ++c, ++l, ++r) {
            if (r < n) {
                s.add(new node(nums[r], r));
            }
            if (l > 0) {
                s.remove(new node(nums[l - 1], l - 1));
            }
            int rv = nums[c] + t + 1, lv = nums[c] - t - 1;
            node rlim = new node(rv, 0);
            node llim = new node(lv, n + 1);
            node lf = s.higher(llim);
            node rf = s.lower(rlim);
            if (lf != null && lf.v < rv && lf.i != c && lf.i <= r) {
//                System.out.println("lf suc " + c);
//                System.out.println(lf);
                return true;
            }
            if (rf != null && rf.v > lv && rf.i != c && rf.i >= l) {
//                System.out.println("rf suc" + c);
//                System.out.println(rf);
                return true;
            }
        }
        return false;
    }
}
```

更优雅的做法：其实只需要往左找即可，也不用存下标。

```java
class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        int n = nums.length;
        TreeSet<Long> set = new TreeSet<Long>();
        for (int i = 0; i < n; i++) {
            Long ceiling = set.ceiling((long) nums[i] - (long) t);
            if (ceiling != null && ceiling <= (long) nums[i] + (long) t) {
                return true;
            }
            set.add((long) nums[i]);
            if (i >= k) {
                set.remove((long) nums[i - k]);
            }
        }
        return false;
    }
}
```



##### 224\.基本计算器

[题目](https://leetcode.cn/problems/basic-calculator/)

后缀表达式+递归做法：

```java
class Solution {
    private String s;
    private int now;

    private boolean isInt(int i) {
        if (i >= s.length()) {
            return false;
        }
        char c = s.charAt(i);
        return c >= '0' && c <= '9';
    }

    private void calc(Deque<Integer> num, Deque<Character> cmd) {
        if (!cmd.isEmpty()) {
            int rfs = num.pollLast();
            int lfs = num.pollLast();
            char ope = cmd.pollLast();
            if (ope == '+') {
                num.add(lfs + rfs);
            } else {
                num.add(lfs - rfs);
            }
        }
    }

    private int dfs() {
        Deque<Integer> num = new LinkedList<>();
        Deque<Character> cmd = new LinkedList<>();
        int tmp = 0;
        for (int ie = s.length(); now < ie; ++now) {
            char c = s.charAt(now);
            if (isInt(now)) {
                tmp = tmp * 10 + (c - '0');
                if (!isInt(now + 1)) {
//                    System.out.println("add " + tmp);
                    num.add(tmp);
                    tmp = 0;
                    calc(num, cmd);
                }
            } else if (c == '+') {
                cmd.add('+');
            } else if (c == '-') {
                if (num.isEmpty()) {
                    num.add(0);
                }
                cmd.add('-');
            } else if (c == '(') {
                ++now;
                num.add(dfs());
                calc(num, cmd);
            } else if (c == ')') {
                break;
            }
        }

        return num.pollLast();
    }

    public int calculate(String s) {
        this.s = s;
        now = 0;
        return dfs();
    }
}
```

更优实现：

```java
class Solution {
    public int calculate(String s) {
        Deque<Integer> ops = new LinkedList<Integer>();
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s.charAt(i) == ' ') {
                i++;
            } else if (s.charAt(i) == '+') {
                sign = ops.peek();
                i++;
            } else if (s.charAt(i) == '-') {
                sign = -ops.peek();
                i++;
            } else if (s.charAt(i) == '(') {
                ops.push(sign);
                i++;
            } else if (s.charAt(i) == ')') {
                ops.pop();
                i++;
            } else {
                long num = 0;
                while (i < n && Character.isDigit(s.charAt(i))) {
                    num = num * 10 + s.charAt(i) - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
}
```



##### 233\.数字1的个数

[题目](https://leetcode.cn/problems/number-of-digit-one/)

个人解法：

1. 设 $n=\overline{x0\cdots0}$ 是 $d$ 位数，设 $a=\overline{d0\cdots 0},b=\overline{(d-1)0\cdots 0}$，其中 $a$ 是 $d$ 位数，$b$ 是 $d-1$ 位数，则 $[1,n)$ 内共有 $a-(10-x)b$ 个 $1$。

   具体而言，随着 $x$ 增大，$d$ 位数除了第二次增加($x=2$)外，增量均为 $a$，而总量为 $b$，所以不需要求出第二次增量，减法即可求出。

   证明：设 $[0,\overline{10\cdots 0})$ (其中上界是 $d+1$ 位数)时答案为 $f_{d}$，显然 $f_1=1$。对 $f_2(f_{d})$ 的推导，首先包含 $f_1(f_{d-1})$(最高位为 $0$)，然后当最高位为 $1$ 时，共有 $10^{d-1}$ 个数，最高位贡献 $10^{d-1}$ 次，然后还包含 $f_{d-1}$ 次，之后最高位选 $8$ 次，包含 $f_{d-1}$ 又 $8$ 次，共 $10$ 次，即有：
   $$
   f_1=1,f_{d}=10f_{d-1}+10^{d-1}
   $$
   符合上述提到的规律。

2. 对 $n=\overline{a_d\cdots a_2a_1}$，可以拆分为若干个问题：
   $$
   \overline{a_d0\cdots 0}+\overline{a_{d-1}0\cdots0}+\cdots+\overline{a_300}+\overline{a_20}+\overline{a_1}
   $$
   先按上文规律散着求出每个对应的。

   然后再特判，如果 $a_i$ 是 $1$，那么首先加多一份，然后这个 $1$ 会对接下来剩余的 $\overline{a_{i-1}\cdots a_2,a_1}$ 个数都产生一次贡献，再加多这么多。

   一路推下去即可。

复杂度理论上可达 $O(\log n)$。

```java
class Solution {
    private int pw(int x, int n) {// x0..0, 0num=n-1F
        int res = x;
        for (int i = 1; i < n; ++i) {
            res *= 10;
        }
        return res;
    }

    private int cnt(int len, int x) { // [1,n), n=x00..0, 0num=len-1
        if (x == 0) {
            return 0;
        }
        int epo = pw(len - 1, len - 1);
        if (x == 1) {
            return epo;
        }
        int tot = pw(len, len);
        return tot - (10 - x) * epo;
    }

    public int countDigitOne(int n) {
        int ans = 0, m = 0, num = n;// digit
        int d[] = new int[11];
        for (; n > 0; n /= 10) {
            d[++m] = n % 10;
        }
        int cnt1 = 0;
        for (int i = m; i >= 1; --i) {
            ans += cnt(i, d[i]);
            num -= pw(d[i], i);
            cnt1 += (d[i] == 1 ? 1 : 0);
            ans += cnt1 * pw(d[i - 1], i - 1);
            ans += (d[i] == 1 ? 1 : 0);
        }
        return ans;
    }
}
```

[数位DP参考](https://leetcode.cn/problems/number-of-digit-one/solution/by-endlesscheng-h9ua/)

```java
class Solution {
    char s[];
    int dp[][];

    public int countDigitOne(int n) {
        s = Integer.toString(n).toCharArray();
        var m = s.length;
        dp = new int[m][m];
        for (var i = 0; i < m; i++) Arrays.fill(dp[i], -1);
        return f(0, 0, true);
    }

    int f(int i, int cnt1, boolean isLimit) {
        if (i == s.length) return cnt1;
        if (!isLimit && dp[i][cnt1] >= 0) return dp[i][cnt1];
        var res = 0;
        for (int d = 0, up = isLimit ? s[i] - '0' : 9; d <= up; ++d) // 枚举要填入的数字 d
            res += f(i + 1, cnt1 + (d == 1 ? 1 : 0), isLimit && d == up);
        if (!isLimit) dp[i][cnt1] = res;
        return res;
    }
}
```



##### 239\.滑动窗口最大值

[题目](https://leetcode.cn/problems/sliding-window-maximum/)

对顶堆：

```java
class heap {
    PriorityQueue<Integer> a, b;

    public heap() {
        a = new PriorityQueue<>();
        b = new PriorityQueue<>();
    }

    void insert(int x) {
        a.add(-x);
    }

    void erase(int x) {
        b.add(-x);
    }

    int top() {
        while (!b.isEmpty() && a.peek().equals(b.peek())) {
            a.poll();
            b.poll();
        }
        return -a.peek();
    }

    int pop() {
        int ans = top();
        a.poll();
        return ans;
    }
}

class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        heap q = new heap();
        for (int i = 0; i < k; ++i) {
            q.insert(nums[i]);
        }
        int n = nums.length;
        int ans[] = new int[n - k + 1];
        ans[0] = q.top();
        for (int l = 1, r = k; r < n; ++l, ++r) {
            q.erase(nums[l - 1]);
            q.insert(nums[r]);
            ans[l] = q.top();
        }
        return ans;
    }
}
```

更优解：

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>(new Comparator<int[]>() {
            public int compare(int[] pair1, int[] pair2) {
                return pair1[0] != pair2[0] ? pair2[0] - pair1[0] : pair2[1] - pair1[1];
            }
        });
        for (int i = 0; i < k; ++i) {
            pq.offer(new int[]{nums[i], i});
        }
        int[] ans = new int[n - k + 1];
        ans[0] = pq.peek()[0];
        for (int i = k; i < n; ++i) {
            pq.offer(new int[]{nums[i], i});
            while (pq.peek()[1] <= i - k) {
                pq.poll();
            }
            ans[i - k + 1] = pq.peek()[0];
        }
        return ans;
    }
}
```



##### 273\.整数转英文表示

[题目](https://leetcode.cn/problems/integer-to-english-words/)

愚蠢的模拟题：

```java
class Solution {
    private String[] sg = new String[] { "Zero", "One", "Two", "Three", "Four", "Five", "Six",
            "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
            "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
    private String[] mg = new String[] { "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty",
            "Seventy", "Eighty", "Ninety" };

    private void blank(StringBuilder s) {
        if (s.length() > 0 && s.charAt(s.length() - 1) != ' ') {
            s.append(' ');
        }
    }

    private String three(int n) {
        int h = n / 100;
        int m = n / 10 % 10;
        int s = n % 10;
        int ms = n % 100;
        StringBuilder r = new StringBuilder();
        if (h > 0) {
            r.append(sg[h]);
            r.append(" Hundred");
        }
        if (s == 0 && m > 0) {
            blank(r);
            r.append(mg[m]);
        } else if (ms < 20 && ms > 0) {
            blank(r);
            r.append(sg[ms]);
        } else if (ms >= 20) {
            blank(r);
            r.append(mg[m]);
            r.append(" ");
            r.append(sg[s]);
        }
        return r.toString();
    }

    public String numberToWords(int num) {
        StringBuilder s = new StringBuilder();
        if (num == 0) {
            s.append("Zero");
        }
        int n1 = num % 1000;
        num /= 1000;
        int n2 = num % 1000;
        num /= 1000;
        int n3 = num % 1000;
        num /= 1000;
        int n4 = num % 1000;
//        System.out.println(String.format("%d %d %d %d", n1, n2, n3, n4));
        if (n4 > 0) {
            s.append(three(n4));
            s.append(" Billion");
        }
        if (n3 > 0) {
            blank(s);
            s.append(three(n3));
            s.append(" Million");
        }
        if (n2 > 0) {
            blank(s);
            s.append(three(n2));
            s.append(" Thousand");
        }
        if (n1 > 0) {
            blank(s);
            s.append(three(n1));
        }
        return s.toString();
    }
}
```

更好的实现：

```java
class Solution {
    String[] singles = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    String[] teens = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    String[] tens = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    String[] thousands = {"", "Thousand", "Million", "Billion"};

    public String numberToWords(int num) {
        if (num == 0) {
            return "Zero";
        }
        StringBuffer sb = new StringBuffer();
        for (int i = 3, unit = 1000000000; i >= 0; i--, unit /= 1000) {
            int curNum = num / unit;
            if (curNum != 0) {
                num -= curNum * unit;
                StringBuffer curr = new StringBuffer();
                recursion(curr, curNum);
                curr.append(thousands[i]).append(" ");
                sb.append(curr);
            }
        }
        return sb.toString().trim();
    }

    public void recursion(StringBuffer curr, int num) {
        if (num == 0) {
            return;
        } else if (num < 10) {
            curr.append(singles[num]).append(" ");
        } else if (num < 20) {
            curr.append(teens[num - 10]).append(" ");
        } else if (num < 100) {
            curr.append(tens[num / 10]).append(" ");
            recursion(curr, num % 10);
        } else {
            curr.append(singles[num / 100]).append(" Hundred ");
            recursion(curr, num % 100);
        }
    }
}
```



##### 282\.给表达式添加运算符

[题目](https://leetcode.cn/problems/expression-add-operators/)

自己的屎山，$O(n4^n)$。

```java
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

class Solution {
    private int n, a[], op[], t;
    private List<String> ans;
    final static private int add = 0, sub = 1, mul = 2, nth = 3;
    final static private char so[] = new char[] { '+', '-', '*' };

    private long calc(long lfs, long rfs, int o) {
//        System.out.println(String.format("%d %d %d", lfs, rfs, o));
        if (o == add) {
            lfs += rfs;
        } else if (o == sub) {
            lfs -= rfs;
        } else if (o == mul) {
            lfs *= rfs;
        }
        return lfs;
    }

    private void dfs(int k) {
        if (k == n) {
            long lfs = 0, rfs = a[0];
            Deque<Long> num = new ArrayDeque<>();
//            num.addFirst(0L);
            Deque<Integer> ope = new ArrayDeque<>();
//            ope.addFirst(add);
            StringBuilder sb = new StringBuilder();
            sb.append(rfs);
            for (int i = 1; i < n; ++i) {
                if (op[i] == nth) {
                    rfs = rfs * 10 + a[i];
                } else {
                    num.addLast(rfs);
                    if (!ope.isEmpty() && ope.peekLast() == mul) {
                        Long r = num.pollLast();
                        Long l = num.pollLast();
                        ope.pollLast();
                        num.addLast(l * r);
                    }
                    ope.addLast(op[i]);
//                    lfs = calc(lfs, rfs, o);
                    rfs = a[i];
                    sb.append(so[op[i]]);
                }
                sb.append(a[i]);
            }
            num.addLast(rfs);
            if (!ope.isEmpty() && ope.peekLast() == mul) {
                Long r = num.pollLast();
                Long l = num.pollLast();
                ope.pollLast();
                num.addLast(l * r);
            }
            while (!ope.isEmpty()) {
                Long l = num.pollFirst();
                Long r = num.pollFirst();
                Integer op = ope.pollFirst();
                num.addFirst(calc(l, r, op));
            }
            lfs = num.peekFirst();
//            lfs = calc(lfs, rfs, o);
//            System.out.println(String.format("%s=%d", sb.toString(), lfs));
            if (lfs == t) {
                String f = sb.toString();
                int z = 0; // 0 not begin; 1 leading zero; 2 normal
                for (int i = 0, ie = f.length(); i < ie; ++i) {
                    char c = f.charAt(i);
                    if (c == '+' || c == '-' || c == '*') {
                        z = 0;
                    } else if (c == '0') {
                        if (z == 0) {
                            z = 1;
                        } else if (z == 1) {
                            return;
                        }
                    } else {
                        if (z == 1) {
                            return;
                        }
                        z = 2;
                    }
                }
//                System.out.println(String.format("%s=%d", sb.toString(), lfs));
                ans.add(f);
            }
            return;
        }
        for (int i = 0; i < 4; ++i) {
            op[k] = i;
            dfs(k + 1);
        }
    }

    public List<String> addOperators(String num, int target) {
        n = num.length();
        a = new int[n];
        t = target;
        for (int i = 0; i < n; ++i) {
            a[i] = (int) (num.charAt(i) - '0');
        }
        op = new int[n];
        ans = new ArrayList<>();
        dfs(1);
        return ans;
    }
}
```

答案更优写法：

```java
class Solution {
    int n;
    String num;
    int target;
    List<String> ans;

    public List<String> addOperators(String num, int target) {
        this.n = num.length();
        this.num = num;
        this.target = target;
        this.ans = new ArrayList<String>();
        StringBuffer expr = new StringBuffer();
        backtrack(expr, 0, 0, 0);
        return ans;
    }

    public void backtrack(StringBuffer expr, int i, long res, long mul) {
        if (i == n) {
            if (res == target) {
                ans.add(expr.toString());
            }
            return;
        }
        int signIndex = expr.length();
        if (i > 0) {
            expr.append(0); // 占位，下面填充符号
        }
        long val = 0;
        // 枚举截取的数字长度（取多少位），注意数字可以是单个 0 但不能有前导零
        for (int j = i; j < n && (j == i || num.charAt(i) != '0'); ++j) {
            val = val * 10 + num.charAt(j) - '0';
            expr.append(num.charAt(j));
            if (i == 0) { // 表达式开头不能添加符号
                backtrack(expr, j + 1, val, val);
            } else { // 枚举符号
                expr.setCharAt(signIndex, '+');
                backtrack(expr, j + 1, res + val, val);
                expr.setCharAt(signIndex, '-');
                backtrack(expr, j + 1, res - val, -val);
                expr.setCharAt(signIndex, '*');
                backtrack(expr, j + 1, res - mul + mul * val, mul * val);
            }
        }
        expr.setLength(signIndex);
    }
}
```



##### 295\.数据流的中位数

[题目](https://leetcode.cn/problems/find-median-from-data-stream/)

对顶堆，个人写法：

```java
import java.util.PriorityQueue;

class MedianFinder {
    PriorityQueue<Integer> a, b;

    public MedianFinder() {
        a = new PriorityQueue<>();// 大根堆,前半部分
        b = new PriorityQueue<>();// 小根堆,后半部分
    }

    public void addNum(int num) {
        if (a.isEmpty() || num <= -a.peek()) {
            a.add(-num);
//            System.out.println("a add");
        } else {
            b.add(num);
//            System.out.println("b add");
        }
        while (b.size() > a.size()) {// b->a
            a.add(-b.poll());
//            System.out.println("b to a");
        }
        while (a.size() > b.size() + 1) {// a->b
            b.add(-a.poll());
//            System.out.println("a to b");
        }
    }

    public double findMedian() {
        if (a.size() > b.size()) {
            return -a.peek();
        }
        return (-a.peek() + b.peek()) / 2.0;
    }
}
```

更好的写法：

```java
class MedianFinder {
    PriorityQueue<Integer> queMin;
    PriorityQueue<Integer> queMax;

    public MedianFinder() {
        queMin = new PriorityQueue<Integer>((a, b) -> (b - a));
        queMax = new PriorityQueue<Integer>((a, b) -> (a - b));
    }
    
    public void addNum(int num) {
        if (queMin.isEmpty() || num <= queMin.peek()) {
            queMin.offer(num);
            if (queMax.size() + 1 < queMin.size()) {
                queMax.offer(queMin.poll());
            }
        } else {
            queMax.offer(num);
            if (queMax.size() > queMin.size()) {
                queMin.offer(queMax.poll());
            }
        }
    }
    
    public double findMedian() {
        if (queMin.size() > queMax.size()) {
            return queMin.peek();
        }
        return (queMin.peek() + queMax.peek()) / 2.0;
    }
}
```



##### 297\.二叉树的序列化与反序列化

[题目](https://leetcode.cn/problems/serialize-and-deserialize-binary-tree/)

```java
import java.util.Scanner;
class Codec {
    private StringBuilder sb;

    private void dfs(TreeNode u) {
        if (u == null) {
            sb.append("1024 ");
            return;
        }
        sb.append(u.val);
        sb.append(' ');
        dfs(u.left);
        dfs(u.right);
    }

    private Scanner sc;

    private TreeNode dfs2() {
        int v = sc.nextInt();
        if (v == 1024) {
            return null;
        }
        TreeNode u = new TreeNode(v);
        u.left = dfs2();
        u.right = dfs2();
        return u;
    }

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        sb = new StringBuilder();
        dfs(root);
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        sc = new Scanner(data);
        TreeNode res = dfs2();
        sc.close();
        return res;
    }
}
```



##### 301\.删除无效的括号

[题目]()

无聊的DFS爆搜题。复杂度 $O(m2^m)$ 其中 $m=20$。

```java
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

class Solution {
    private String s;
    private boolean suc;
    private int n, m, p[], lim;
    private boolean del[];
    private List<String> ans;
    private HashSet<String> tmp;

    private void dfs(int prv, int cnt) {
        if (cnt == lim) {
            StringBuilder sb = new StringBuilder();
            int lf = 0;
            for (int i = 0; i < n; ++i) {
                if (del[i]) {
                    continue;
                }
                char c = s.charAt(i);
                if (c == '(') {
                    lf++;
                } else if (c == ')') {
                    if (--lf < 0) {
                        return;
                    }
                }
                sb.append(c);
            }
            if (lf == 0) {
                suc = true;
//                ans.add(sb.toString());
                tmp.add(sb.toString());
            }
            return;
        }
        for (int i = prv + 1; i < m; ++i) {
            del[p[i]] = true;
            dfs(i, cnt + 1);
            del[p[i]] = false;
        }
    }

    public List<String> removeInvalidParentheses(String s) {
        this.s = s;
        suc = false;
        n = s.length();
        p = new int[n];
        m = 0;
        for (int i = 0; i < n; ++i) {
            char c = s.charAt(i);
            if (c == '(' || c == ')') {
                p[m++] = i;
            }
        }
        del = new boolean[n];
        tmp = new HashSet<>();
        ans = new ArrayList<>();
        for (lim = 0; lim <= m && !suc; ++lim) {
            dfs(-1, 0);
        }
        for (String t : tmp) {
            ans.add(t);
        }
        return ans;
    }
}
```

题解解法一：DFS回溯，时间 $O(n2^n)$，空间 $O(n^2)$

```java
class Solution {
    private List<String> res = new ArrayList<String>();

    public List<String> removeInvalidParentheses(String s) {
        int lremove = 0;
        int rremove = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                lremove++;
            } else if (s.charAt(i) == ')') {
                if (lremove == 0) {
                    rremove++;
                } else {
                    lremove--;
                }
            }
        }
        helper(s, 0, lremove, rremove);

        return res;
    }

    private void helper(String str, int start, int lremove, int rremove) {
        if (lremove == 0 && rremove == 0) {
            if (isValid(str)) {
                res.add(str);
            }
            return;
        }

        for (int i = start; i < str.length(); i++) {
            if (i != start && str.charAt(i) == str.charAt(i - 1)) { //去重,因为 (() 来说删哪个左都一样，所以删掉第一个即可
                continue;
            }
            // 如果剩余的字符无法满足去掉的数量要求，直接返回
            if (lremove + rremove > str.length() - i) {
                return;
            }
            // 尝试去掉一个左括号
            if (lremove > 0 && str.charAt(i) == '(') {
                helper(str.substring(0, i) + str.substring(i + 1), i, lremove - 1, rremove);
            }
            // 尝试去掉一个右括号
            if (rremove > 0 && str.charAt(i) == ')') {
                helper(str.substring(0, i) + str.substring(i + 1), i, lremove, rremove - 1);
            }
        }
    }

    private boolean isValid(String str) {
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '(') {
                cnt++;
            } else if (str.charAt(i) == ')') {
                cnt--;
                if (cnt < 0) {
                    return false;
                }
            }
        }

        return cnt == 0;
    }
}
```

解法二：BFS 时间 $O(n2^n)$ 空间 $O(nC_n^{\frac n2})$。

```java
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        List<String> ans = new ArrayList<String>();
        Set<String> currSet = new HashSet<String>();

        currSet.add(s);
        while (true) {
            for (String str : currSet) {
                if (isValid(str)) {
                    ans.add(str);
                }
            }
            if (ans.size() > 0) {
                return ans;
            }
            Set<String> nextSet = new HashSet<String>();
            for (String str : currSet) {
                for (int i = 0; i < str.length(); i ++) {
                    if (i > 0 && str.charAt(i) == str.charAt(i - 1)) {
                        continue;
                    }
                    if (str.charAt(i) == '(' || str.charAt(i) == ')') {
                        nextSet.add(str.substring(0, i) + str.substring(i + 1));
                    }
                }
            }
            currSet = nextSet;
        }
    }

    private boolean isValid(String str) {
        char[] ss = str.toCharArray();
        int count = 0;

        for (char c : ss) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) {
                    return false;
                }
            }
        }

        return count == 0;
    }
}
```

解法三：枚举子集。设非法括号数为 $m$，时间 $O(n2^n)$，空间 $O(nC_n^m)$

```java
class Solution {
    public List<String> removeInvalidParentheses(String s) {
        int lremove = 0;
        int rremove = 0;
        List<Integer> left = new ArrayList<Integer>();
        List<Integer> right = new ArrayList<Integer>();
        List<String> ans = new ArrayList<String>();
        Set<String> cnt = new HashSet<String>();

        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                left.add(i);
                lremove++;
            } else if (s.charAt(i) == ')') {
                right.add(i);
                if (lremove == 0) {
                    rremove++;
                } else {
                    lremove--;
                }
            }
        }

        int m = left.size();
        int n = right.size();
        List<Integer> maskArr1 = new ArrayList<Integer>();
        List<Integer> maskArr2 = new ArrayList<Integer>();
        for (int i = 0; i < (1 << m); i++) {
            if (Integer.bitCount(i) != lremove) {
                continue;
            }
            maskArr1.add(i);
        }
        for (int i = 0; i < (1 << n); i++) {
            if (Integer.bitCount(i) != rremove) {
                continue;
            }
            maskArr2.add(i);
        }
        for (int mask1 : maskArr1) {
            for (int mask2 : maskArr2) {
                if (checkValid(s, mask1, left, mask2, right)) {
                    cnt.add(recoverStr(s, mask1, left, mask2, right));
                }
            }
        }
        for (String v : cnt) {
            ans.add(v);
        }

        return ans;
    }

    private boolean checkValid(String str, int lmask, List<Integer> left, int rmask, List<Integer> right) {
        int pos1 = 0;
        int pos2 = 0;
        int cnt = 0;

        for (int i = 0; i < str.length(); i++) {
            if (pos1 < left.size() && i == left.get(pos1)) {
                if ((lmask & (1 << pos1)) == 0) {
                    cnt++;
                }
                pos1++;
            } else if (pos2 < right.size() && i == right.get(pos2)) {
                if ((rmask & (1 << pos2)) == 0) {
                    cnt--;
                    if (cnt < 0) {
                        return false;
                    }
                }
                pos2++;
            }
        }

        return cnt == 0;
    }

    private String recoverStr(String str, int lmask, List<Integer> left, int rmask, List<Integer> right) {
        StringBuilder sb = new StringBuilder();
        int pos1 = 0;
        int pos2 = 0;

        for (int i = 0; i < str.length(); i++) {
            if (pos1 < left.size() && i == left.get(pos1)) {
                if ((lmask & (1 << pos1)) == 0) {
                    sb.append(str.charAt(i));
                }
                pos1++;
            } else if (pos2 < right.size() && i == right.get(pos2)) {
                if ((rmask & (1 << pos2)) == 0) {
                    sb.append(str.charAt(i));
                }
                pos2++;
            } else {
                sb.append(str.charAt(i));
            }
        }

        return sb.toString();
    }
}
```



##### 312\.戳气球

[题目](https://leetcode.cn/problems/burst-balloons/)

区间 DP。

```java
class Solution {
    public int maxCoins(int[] nums) {
        int n = nums.length;
        int a[] = new int[n + 2];
        int dp[][] = new int[n + 2][n + 2];
        for (int i = 1; i <= n; ++i) {
            a[i] = nums[i - 1];
        }
        a[0] = a[n + 1] = 1;
        for (int len = 1; len <= n; ++len) {
            for (int l = 1, r = l + len - 1; r <= n; ++l, ++r) {
                int bd = a[l - 1] * a[r + 1];
                for (int c = l; c <= r; ++c) {
                    int v = bd * a[c];
                    v += dp[l][c - 1] + dp[c + 1][r];
                    dp[l][r] = Math.max(dp[l][r], v);
                }
            }
        }
        return dp[1][n];
    }
}
```



##### 315\.计算右侧小于当前元素的个数

[题目](https://leetcode.cn/problems/count-of-smaller-numbers-after-self/)

截止 23-03-03 18ms(击败99.85%)和 59.3MB(击败61.57%) 的 Java 代码。

设权值树状数组，逆序遍历原数组，对当前值 $v$，查询树状数组里有多少个 $ < v$ 的值，然后将 $v$ 插入树状数组。

因为有负数，所以对全体数偏移，将 $[-10^4,10^4]$ 偏移到 $[1,2\times 10^4+1]$。

不必离散化。因为离散化的常数较大。

设 $t=2\times 10^4+1$，显然时间复杂度 $O(t\log t)$，空间复杂度 $O(t)$。

> 权值线段树也是可以的，但是常数更大。且四倍空间复杂度。

```java
class fenwick {
    private static final int r = 10000, n = 2 * r + 1;// 值域[-r,r]
    private int t[];

    public fenwick() {
        t = new int[n + 1];
    }

    public void add(int i) {
        for (i += r + 1; i <= n; i += Integer.lowestOneBit(i)) {
            ++t[i];
        }
    }

    public int query(int i) {
        int res = 0;
        for (i += r + 1; i > 0; i -= Integer.lowestOneBit(i)) {
            res += t[i];
        }
        return res;
    }
}

class Solution {
    public List<Integer> countSmaller(int[] nums) {
        int n = nums.length;
        Integer c[] = new Integer[n];
        fenwick t = new fenwick();
        for (int i = n - 1; i >= 0; --i) {
            c[i] = t.query(nums[i] - 1);
            t.add(nums[i]);
        }
        return Arrays.asList(c);
    }
}
```

解法二：归并排序。

```java
class Solution {
    private int[] index;
    private int[] temp;
    private int[] tempIndex;
    private int[] ans;

    public List<Integer> countSmaller(int[] nums) {
        this.index = new int[nums.length];
        this.temp = new int[nums.length];
        this.tempIndex = new int[nums.length];
        this.ans = new int[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            index[i] = i;
        }
        int l = 0, r = nums.length - 1;
        mergeSort(nums, l, r);
        List<Integer> list = new ArrayList<Integer>();
        for (int num : ans) {
            list.add(num);
        }
        return list;
    }

    public void mergeSort(int[] a, int l, int r) {
        if (l >= r) {
            return;
        }
        int mid = (l + r) >> 1;
        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);
        merge(a, l, mid, r);
    }

    public void merge(int[] a, int l, int mid, int r) {
        int i = l, j = mid + 1, p = l;
        while (i <= mid && j <= r) {
            if (a[i] <= a[j]) {
                temp[p] = a[i];
                tempIndex[p] = index[i];
                ans[index[i]] += (j - mid - 1);
                ++i;
                ++p;
            } else {
                temp[p] = a[j];
                tempIndex[p] = index[j];
                ++j;
                ++p;
            }
        }
        while (i <= mid)  {
            temp[p] = a[i];
            tempIndex[p] = index[i];
            ans[index[i]] += (j - mid - 1);
            ++i;
            ++p;
        }
        while (j <= r) {
            temp[p] = a[j];
            tempIndex[p] = index[j];
            ++j;
            ++p;
        }
        for (int k = l; k <= r; ++k) {
            index[k] = tempIndex[k];
            a[k] = temp[k];
        }
    }
}
```

解法三：tree set 二分。用平衡树维护有序数组，逆序遍历原数组并树上查询 rank。略。



##### 982\.按位与为零的三元组

[题目](https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/)

**解法一：bitset 优化的暴力枚举**

bitset：设 $m=16$ 个长为 $n$ 的 bitset $b$，第 $i$ 个 bitset 的第 $j$ 位代表 $a_j$ 的第 $i$ 低位是不是 $0$。 

枚举 $v=a_i \& a_j$，然后枚举 $v$ 的每个为 $1$ 的位，只要这个位为 $0$ 的数就可以。同时满足所有为 $1$ 的位是 $0$，即把这些 $b$ 全部与一下，然后统计与后 $1$ 的个数。

设操作系统位数为 $C=64$，则空间复杂度为 $O(\dfrac{nm}{C})$ ，时间复杂度为 $O(\dfrac{n^3m}{C})\approx 2.5\times 10^8$。

竟然能过题。

```java
import java.util.BitSet;

class Solution {
    private final static int m = 16;

    public int countTriplets(int[] nums) {
        int cnt = 0, n = nums.length;
        BitSet b[] = new BitSet[m];
        for (int i = 0; i < m; ++i) {
            b[i] = new BitSet(n);// b[i][j]表示第nums[j]第i位是不是0
            for (int j = 0; j < n; ++j) {
                if (((nums[j] >> i) & 1) == 0) {
                    b[i].set(j);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int v = nums[i] & nums[j];
                BitSet t = new BitSet(n);
                t.set(0, n);
                for (int k = 0; k < m; ++k) {
                    if (((v >> k) & 1) == 1) {
                        t.and(b[k]);
                    }
                }
                cnt += t.cardinality();
            }
        }
        return cnt;
    }
}
```

**解法二：桶**

枚举 $a_i\&a_j$ 的值，计数存储在桶 $b$ 里。然后枚举 $a_k$，对每个 $a_k$ 枚举桶的所有值，若 $a_k \& i=0$，加上 $b_i$ 计数。

代码略，看官方题解。时间复杂度 $O(n^2+n2^m)\approx 6.6\times 10^7$，空间复杂度 $O(2^m)$。

可以进行常数优化。在枚举 $a_k \& i$ 的满足的 $i$ 时，使用如下方法：

```java
for (int x : nums) {
    x = x ^ 0xffff; // 为1的位是还需要cnt做贡献的
    for (int sub = x; sub != 0; sub = (sub - 1) & x) {
        ans += cnt[sub];
    }
    ans += cnt[0];
}
```

含义是，快速枚举 $x$ 的所有子集，例如 $x=(1011)_2$，能直接枚举出 $(0001)_2,(0010)_2,(0011)_2,(1000)_2,(1001)_2,(1010)_2,(1011)_2$。复杂度不变，但相当于大量剪枝。

**解法三：高维前缀和**

复杂度同上。对桶数组，把解法二的子集用前缀和叠上去，叠 $m$ 维。

> [代码参考](https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/solution/liang-chong-90duo-de-fang-fa-gao-wei-qian-zhui-he-/)

> ```c++
> class Solution {
> public:
> 	int w = 0;
> 	int N, B[1 << 16];
> 
> 	int countTriplets(vector<int>& A) {
> 		N = A.size();
> 		for (auto a : A)
> 		{
> 			B[a]++;
> 			while ((1 << w) <= a)w++;
> 		}
> 
> 		for (int i = 0; i<w; i++) {
> 			for (int j = 0; j<(1 << w); j++) {
> 				if (j&(1 << i)) B[j] += B[j ^ (1 << i)];
> 			}
> 		}
> 
> 		int ans = 0;
> 		int mask = (1 << w) - 1;
> 		for (int i = 0; i < N; i++)
> 			for (int j = 0; j < N; j++)
> 				ans += B[~(A[i] & A[j])&mask];
> 		return ans;
> 	}
> };
> ```

**解法四：FWT**

[快速沃尔什变换(FWT)](https://oi-wiki.org/math/poly/fwt/)。要求
$$
\sum_{i\&j\&k=0}a_ia_ja_k=\sum_{i\&p=0}a_i\sum_{j\&k=p}a_ja_k
$$
也就是求出新数列 $b_p=\sum_{j\&k=p}a_ja_k$，再求新数列 $c_q=\sum_{i\&p=q}a_ib_p$，最后再输出 $c$ 的首项 $c_0$

即求出 $fwt(a)$，并计算 $fwt(b)=fwt(a)^3$，然后对 $fwt(b)$ 逆运算得 $b$，输出 $b_0$。

复杂度 $O(m2^m)$

> [代码参考](https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/solution/liang-chong-90duo-de-fang-fa-gao-wei-qian-zhui-he-/)

> ```java
> // FWT
> class Solution {
> public:
> 	int w;
> 	int B[1 << 16];
> 	void FWTand(int *a, int opt)
> 	{
> 		int N = 1 << w;
> 		for (int mid = 1; mid < N; mid <<= 1)
> 			for (int R = mid << 1, j = 0; j < N; j += R)
> 				for (int k = 0; k < mid; k++)
> 					if (opt == 1) a[j + k] += a[j + k + mid];
> 					else a[j + k] -= a[j + k + mid];
> 	}
> 	int countTriplets(vector<int>& A) {
> 		for (auto a : A)
> 		{
> 			B[a]++;
> 			while ((1 << w) <= a)w++;
> 		}
> 		FWTand(B, 1);
> 		for (int i = 0; i<(1 << w); i++) B[i] *= B[i] * B[i];
> 		FWTand(B, -1);
> 		return B[0];
> 	}
> };
> ```

> ```c++
> void fwt(int* seq, int n) {
>     for (int i = 1;i < n;i *= 2)
>         for (int j = 0;j < n;j += i)
>             for (int k = j + i;j < k;++j)
>                 seq[j] += seq[j + i];
> }
> 
> class Solution {
> public:
>     int countTriplets(const vector<int>& nums) {
>         const int m = *max_element(nums.begin(), nums.end());
>         const int l = m > 0 ? 1 << (32 - __builtin_clz(m)) : 1;
>         int cnt[l];
>         fill_n(cnt, l, 0);
>         for (int e : nums)
>             ++cnt[e];
>         fwt(cnt, l);
>         int ans = 0;
>         for (int i = 0;i <= m;++i)
>             ans += (1 - 2 * __builtin_parity(i)) * cnt[i] * cnt[i] * cnt[i];
>         return ans;
>     }
> };
> ```
>
> ```c++
> #include<immintrin.h>
> 
> __attribute__((target("avx2")))
> void fwt(int* seq, int n) {
>     const auto end = seq + n;
>     for (int i = 1;i < 8 && i < n;i *= 2)
>         for (auto j = seq;j != end;j += i)
>             for (const auto k = j + i;j < k;++j)
>                 *j += j[i];
>     const int m = n / 8;
>     const auto l = reinterpret_cast<__m256i*>(seq);
>     const auto r = reinterpret_cast<__m256i*>(end);
>     for (int i = 1;i < m;i *= 2)
>         for (auto j = l;j != r;j += i)
>             for (const auto k = j + i;j < k;++j)
>                 *j = _mm256_add_epi32(*j, j[i]);
> }
> 
> class Solution {
> public:
>     int countTriplets(const vector<int>& nums) {
>         const int m = *max_element(nums.begin(), nums.end());
>         const int l = m > 0 ? 1 << (32 - __builtin_clz(m)) : 1;
>         alignas(32) int cnt[l];
>         fill_n(cnt, l, 0);
>         for (int e : nums)
>             ++cnt[e];
>         fwt(cnt, l);
>         int ans = 0;
>         for (int i = 0;i <= m;++i)
>             ans += (1 - 2 * __builtin_parity(i)) * cnt[i] * cnt[i] * cnt[i];
>         return ans;
>     }
> };
> ```



##### 321\.拼接最大数

[题目](https://leetcode.cn/problems/create-maximum-number/)

题意：给定长为 $n$ 的整数序列 $a$ 和长为 $m$ 的整数序列 $b$，从 $a,b$ 里分别按顺序选数，共选 $k$ 个数组成 $c$，求出字典序最大的 $c$。具体而言，任意 $c$ 里的两个数 $c_i,c_j(i <j)$ 只要满足是从同一个序列里选出来的 $a_u,a_v$，必须满足 $i,j$ 在原序列 $u < v$。对 $b$ 同理。保证 $a,b$ 的值取值范围是 $[0,9]$。

**解法一：后缀数组/后缀自动机**。本解法在基于官方题解，并进行进一步优化。

枚举所有 $x+y = k,0\le x \le n,0\le y\le m$，然后从前面取 $x$ 个，后面取 $y$ 个，并且取出来后 $O(x+y)$ 归并思想合并。然后对所有 $x,y$ 的答案再取最优答案。对两个串比较字典序最坏 $O(k)$(只要重复较低，数据弱的话平均 $O(1)$)。

具体取 $x$ 个时，顺着扫数组，先能选就选，能反悔 $n-x$ 次，如果当前数比上一个选定的数大，并且能反悔的话，就把上一个选的数删掉，占一次反悔。如果没选满 $x$ 个就把当前数选定，否则把当前数删掉算反悔。也就是说还有反悔次数时就是单调递减栈，不能反悔了就直接有啥选啥。复杂度 $O(n)$，不需要比较字典序。

因此，共需要单调栈 $O(k)$ 次，每次的复杂度是 $O(n+m)$，这里的复杂度是 $O(k(n+m))$。选出来后的长度是 $k$，进行合并的遍历次数 $O(k)$，每次都有可能触发字典序比较，比较的复杂度是 $O(k)$，故一轮合并的复杂度是 $O(k^2)$。对所有 $O(k)$ 个 $x,y$ 结果合并，仍需要字符串比较 $O(k)$ 次，复杂度是 $O(k^2)$。总复杂度是 $O(k^3+kn+km)=O(k^3+k^2)$。空间复杂度 $O(k)$。

考虑将 $O(k^2)$ 的合并用后缀数组优化，可以先 $O(k\log k)$ (倍增法)或 $O(k)$ (SA-IS或DC3)预处理，之后每次比较都是 $O(1)$ 的。设采用 SA-IS 或 DC3，复杂度优化为 $O(k)$，总复杂度优化为 $O(k^2)$。具体而言，将要比较的两个序列 $a,b$ 中间用一个最小数(转化为用 $m=\min(a,b)$ 拼接每个元素增大了 $m$ 的序列 $a+m,b+m$)，求出每个后缀的排名，那么对两个下标，直接比较该下标对应的后缀的排名即可。

> 用后缀自动机也行，但鉴于我不太会，故略。

参考 C++ 代码(基于 SA-IS 的后缀数组)：

```c++
#include <bits/stdc++.h>
using namespace std;
// start leetcode
using ll = long long;
const ll mn = 1e3 + 5;
namespace sa // begin SA-IS
{
    char s[mn];
    ll sa[mn], rk[mn]; //, lcp[mn];
    ll str[mn * 2], ty[mn * 2], p[mn], cnt[mn], cur[mn];
#define pushs(x) sa[cur[str[x]]--] = x
#define pushl(x) sa[cur[str[x]]++] = x
    void sais(ll n, ll m, ll *str, ll *ty, ll *p)
    {
        ll n1 = ty[n - 1] = 0, ch = rk[0] = -1, *s1 = str + n;
        for (ll i = n - 2; ~i; --i)
        {
            ty[i] = str[i] == str[i + 1] ? ty[i + 1] : str[i] > str[i + 1];
        }
        for (ll i = 1; i < n; ++i)
        {
            rk[i] = ty[i - 1] && !ty[i] ? (p[n1] = i, n1++) : -1;
        }

        auto induce_sort = [&](ll *v)
        {
            fill_n(sa, n, -1);
            fill_n(cnt, m, 0);
            for (ll i = 0; i < n; ++i)
            {
                cnt[str[i]]++;
            }
            for (ll i = 1; i < m; ++i)
            {
                cnt[i] += cnt[i - 1];
            }
            for (ll i = 0; i < m; ++i)
            {
                cur[i] = cnt[i] - 1;
            }
            for (ll i = n1 - 1; ~i; --i)
            {
                pushs(v[i]);
            }
            for (ll i = 1; i < m; ++i)
            {
                cur[i] = cnt[i - 1];
            }
            for (ll i = 0; i < n; ++i)
            {
                if (sa[i] > 0 && ty[sa[i] - 1])
                {
                    pushl(sa[i] - 1);
                }
            }
            for (ll i = 0; i < m; ++i)
            {
                cur[i] = cnt[i] - 1;
            }
            for (ll i = n - 1; ~i; --i)
            {
                if (sa[i] > 0 && !ty[sa[i] - 1])
                {
                    pushs(sa[i] - 1);
                }
            }
        };
        induce_sort(p);
        for (ll i = 0, x, y; i < n; ++i)
        {
            if (~(x = rk[sa[i]]))
            {
                if (ch < 1 || p[x + 1] - p[x] != p[y + 1] - p[y])
                {
                    ++ch;
                }
                else
                {
                    for (ll j = p[x], k = p[y]; j <= p[x + 1]; ++j, ++k)
                    {
                        if ((str[j] << 1 | ty[j]) != (str[k] << 1 | ty[k]))
                        {
                            ++ch;
                            break;
                        }
                    }
                }
                s1[y = x] = ch;
            }
        }
        if (ch + 1 < n1)
        {
            sais(n1, ch + 1, s1, ty + n, p + n1);
        }
        else
        {
            for (ll i = 0; i < n1; ++i)
            {
                sa[s1[i]] = i;
            }
        }
        for (ll i = 0; i < n1; ++i)
        {
            s1[i] = p[sa[i]];
        }
        induce_sort(s1);
    }
    ll cti(ll n)
    {
        ll m = *max_element(s, s + n);
        fill_n(rk, m + 1, 0);
        for (ll i = 0; i < n; ++i)
        {
            rk[s[i]] = 1;
        }
        for (ll i = 0; i < m; ++i)
        {
            rk[i + 1] += rk[i];
        }
        for (ll i = 0; i < n; ++i)
        {
            str[i] = rk[s[i]] - 1;
        }
        return rk[m];
    }
    void make_sa(ll n)
    {
        // s[n] 一定要比 s 中所有字符 ascii 值小, s[n+1] 倒无所谓
        s[n] = '!', s[n + 1] = '\0';
        ll m = cti(++n);
        sais(n, m, str, ty, p);
        for (ll i = 0; i < n; ++i)
        {
            rk[sa[i]] = i;
        }
        // for (ll i = 0, h = lcp[0] = 0; i < n - 1; ++i)
        // {
        //     ll j = sa[rk[i] - 1];
        //     while (i + h < n && j + h < n && s[i + h] == s[j + h])
        //     {
        //         ++h;
        //     }
        //     lcp[rk[i] - 1] = h;
        //     if (lcp[rk[i] - 1])
        //     {
        //         --h;
        //     }
        // }
        s[n] = '\0';
    }
} // end SA-IS

char a[mn], b[mn], ans[mn], res[mn], u[mn], v[mn];
int n, m, k, x;

void greedy(char *stk, char *a, int n, int k)
{
    int top = -1, rem = n - k;
    for (int i = 0; i < n; ++i)
    {
        while (top >= 0 && stk[top] < a[i] && rem > 0)
        {
            --top, --rem; // 反悔
        }
        if (top < k - 1)
        {
            stk[++top] = a[i];
        }
        else
        {
            --rem;
        }
    }
    // for (int i = 0; i < k; ++i)
    //     cout << stk[i];
    // cout << '\n';
}
void merge()
{
    int y = k - x;
    // cout<<x<<' '<<y<<'\n';
    if (x == 0)
    {
        memcpy(res, v, k);
        return;
    }
    if (y == 0)
    {
        memcpy(res, u, k);
        return;
    }
    for (int i = 0; i < x; ++i)
    {
        sa::s[i] = u[i];
    }
    sa::s[x] = '0' - 1;
    for (int i = 0, j = x + 1; i < y; ++i, ++j)
    {
        sa::s[j] = v[i];
    }
    sa::make_sa(x + 1 + y); // k+1
    // return if u的后缀i>v的后缀j
    auto cmp = [&](ll i, ll j)
    {
        j += x + 1;
        return sa::rk[i] > sa::rk[j];
    };
    int i = 0, j = 0;
    for (int h = 0; h < k; ++h)
    {
        if (cmp(i, j))
        {
            res[h] = u[i++];
        }
        else
        {
            res[h] = v[j++];
        }
    }
    // cout << "qwq: ";
    // for (int i = 0; i < k; ++i)
    //     cout << res[i];
    // cout << '\n';
}
void solve()
{
    memset(ans, 0, k);
    for (x = 0; x <= k; ++x)
    {
        if (x > n || k - x > m)
        {
            continue;
        }
        greedy(u, a, n, x);
        greedy(v, b, m, k - x);
        merge();
        if (lexicographical_compare(ans, ans + k, res, res + k)) // res>ans
        {
            // cout << "less: " << res << '\n';
            memcpy(ans, res, k);
        }
    }
}

class Solution
{
public:
    vector<int> maxNumber(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        n = nums1.size(), m = nums2.size();
        ::k = k;
        for (int i = 0; i < n; ++i)
        {
            a[i] = nums1[i] + '0';
        }
        for (int i = 0; i < m; ++i)
        {
            b[i] = nums2[i] + '0';
        }
        solve();
        vector<int> ret = vector<int>(k);
        for (int i = 0; i < k; ++i)
        {
            ret[i] = ans[i] - '0';
        }
        return ret;
    }
};
// end leetcode
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    Solution s = Solution();
    vector<int> ans;
    ans = s.maxNumber({3, 4, 6, 5}, {9, 1, 2, 5, 8, 3}, 5);
    auto out = [&](vector<int> a)
    {
        for (auto i : a)
        {
            cout << i << ' ';
        }
        cout << '\n';
    };
    out(ans);
    return 0;
}
```

**解法二：序列自动机**。

创建 $a,b$ 的序列自动机 $sa,sb$。设状态 $(u,v,w)$ 表示当前在字符串 $a,b$ 的第 $u,v$ 个位置($1$ 是第一个有效位置)，还要选 $w$ 个数。则从 $(0,0,k)$ 开始出发。对 $u$ ，从大到小枚举下一个字符 $c$，考虑最坏情况，即这次之后剩下的字符全都要选，看看跳 $c$ 后能不能全填，能的话 $c$ 一定能选。那么贪心要 $c$ 就行。对 $v$ 同理找到它对应的 $c$，然后选择最大的 $c$，进入下一个状态。考虑到 $c$ 可能相等，故每次下一状态里 $u,v$ 的取值较多，最多有 $O(\min(n,m))$ 个状态。一共需要有 $k$ 个状态，每个状态需要遍历 $O(c=10)$ 次，所以枚举的复杂度是 $O(ck(n+m))$。

例如，全是 $1$ 的序列，有状态：$[(0,0)]\to[(0,1),(1,0)]\to[(0,2),(1,1),(2,0)]\to\cdots$，可见状态数不会超过 $w$。且每次状态数增加不会超过 $1$。如图所示：

![image-20230306163930283](img/image-20230306163930283.png)

预处理子序列自动机的空间复杂度是 $O(c(n+m))$ 。总时间复杂度是 $O(ck(n+m))$。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxm = 12, mc = 10, npos = 0x3f, mn = 1e3;
const char s0 = '0';
struct sequenceam
{
    // nxt[i,j]:第i个字符后j首次出现的位置
    int nxt[mn][maxm], n;
    string s;
    void init()
    {
        memset(nxt,0,sizeof nxt);
        n = s.size();
        for (int i = 0; i < mc; ++i)
        {
            nxt[n][i] = 1e9;
        }
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 0; j < mc; ++j)
            {
                nxt[i][j] = nxt[i + 1][j]; // forward
            }
            nxt[i][s[i] - s0] = i; // 0不是首字符
        }
    }
};
char a[mn], b[mn], ans[mn];
int n, m, k;
sequenceam sa, sb;
void solve()
{
    sa.s = a, sb.s = b;
    sa.init(), sb.init();
    using tup = tuple<ll, ll, ll>;
    vector<int> re;
    set<tup> q{{0, 0, k}}; // 起始位置u,v,还要选k个
    while (re.size() < k)
    {
        set<tup> nxt[10];
        for (auto [u, v, w] : q)
        {
            if (u < n)
            {
                for (ll c = 9; c >= 0; --c)
                { // cnt:假设剩下全选
                    ll cnt = n - sa.nxt[u][c] + m - v;
                    if (cnt >= w)
                    {
                        nxt[c].insert({sa.nxt[u][c] + 1, v, w - 1});
                        break;
                    }
                }
            }
            if (v < m)
            {
                for (ll c = 9; c >= 0; --c)
                { // cnt:假设剩下全选
                    ll cnt = m - sb.nxt[v][c] + n - u;
                    if (cnt >= w)
                    {
                        nxt[c].insert({u, sb.nxt[v][c] + 1, w - 1});
                        break;
                    }
                }
            }
        }
        for (ll i = 9; i >= 0; --i)
        {
            if (nxt[i].size())
            {
                q = nxt[i];
                re.push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i < k; ++i)
    {
        ans[i] = re[i] + '0';
    }
}
class Solution
{
public:
    vector<int> maxNumber(const vector<int> &nums1, const vector<int> &nums2, int k)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        memset(ans,0,sizeof ans);
        n = nums1.size(), m = nums2.size();
        ::k = k;
        for (int i = 0; i < n; ++i)
        {
            a[i] = nums1[i] + '0';
        }
        for (int i = 0; i < m; ++i)
        {
            b[i] = nums2[i] + '0';
        }
        solve();
        vector<int> ret = vector<int>(k);
        for (int i = 0; i < k; ++i)
        {
            ret[i] = ans[i] - '0';
        }
        return ret;
    }
};

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    Solution s = Solution();
    vector<int> ans;
    ans = s.maxNumber({6, 7, 5}, {4, 8, 1}, 3);
    auto out = [&](vector<int> a)
    {
        for (auto i : a)
        {
            cout << i << ' ';
        }
        cout << '\n';
    };
    out(ans);
    return 0;
}
```

朴素：

```java
class Solution {
    public int[] maxNumber(int[] nums1, int[] nums2, int k) {
        int m = nums1.length, n = nums2.length;
        int[] maxSubsequence = new int[k];
        int start = Math.max(0, k - n), end = Math.min(k, m);
        for (int i = start; i <= end; i++) {
            int[] subsequence1 = maxSubsequence(nums1, i);
            int[] subsequence2 = maxSubsequence(nums2, k - i);
            int[] curMaxSubsequence = merge(subsequence1, subsequence2);
            if (compare(curMaxSubsequence, 0, maxSubsequence, 0) > 0) {
                System.arraycopy(curMaxSubsequence, 0, maxSubsequence, 0, k);
            }
        }
        return maxSubsequence;
    }

    public int[] maxSubsequence(int[] nums, int k) {
        int length = nums.length;
        int[] stack = new int[k];
        int top = -1;
        int remain = length - k;
        for (int i = 0; i < length; i++) {
            int num = nums[i];
            while (top >= 0 && stack[top] < num && remain > 0) {
                top--;
                remain--;
            }
            if (top < k - 1) {
                stack[++top] = num;
            } else {
                remain--;
            }
        }
        return stack;
    }

    public int[] merge(int[] subsequence1, int[] subsequence2) {
        int x = subsequence1.length, y = subsequence2.length;
        if (x == 0) {
            return subsequence2;
        }
        if (y == 0) {
            return subsequence1;
        }
        int mergeLength = x + y;
        int[] merged = new int[mergeLength];
        int index1 = 0, index2 = 0;
        for (int i = 0; i < mergeLength; i++) {
            if (compare(subsequence1, index1, subsequence2, index2) > 0) {
                merged[i] = subsequence1[index1++];
            } else {
                merged[i] = subsequence2[index2++];
            }
        }
        return merged;
    }

    public int compare(int[] subsequence1, int index1, int[] subsequence2, int index2) {
        int x = subsequence1.length, y = subsequence2.length;
        while (index1 < x && index2 < y) {
            int difference = subsequence1[index1] - subsequence2[index2];
            if (difference != 0) {
                return difference;
            }
            index1++;
            index2++;
        }
        return (x - index1) - (y - index2);
    }
}
```



##### 327\.区间和的个数

[题目](https://leetcode.cn/problems/count-of-range-sum/)

设原数组是 $a$，前缀和为 $s$。一开始先求 $s$ 所有元素即所有 $[0,i]$ 区间里有多少个区间满足，即求 $s_i\in [lower,upper]$ 的数目。之后，不断删掉 $s$ 首元素，并令 $s=s-a_{top}$，即设上一次找的是 $[top,i]$，下一次就找所有 $[top+1,i]$。为了避免对 $s$ 做整体操作，可以只删除，而 $s$ 不变，下一次令 $lower=lower+a_{top},upper=upper+a_{top}$ 即可。

问题转化为对一个会删除元素的序列，多次求该序列里有多少个元素在某个区间内。想到 set / 平衡树。

使用 C++ 扩展库 `pb_ds`，内置可以查询节点排名的 `set`。`order_by_key(x)` 找到第一个 $\ge x$ 的元素的下标(查无返回长度) 。为了防止去重，可以用二元组 $(v,i)$ 代替单纯的 $v$ 传入。查询 $[l,r]$ 内数目时，找到 $(l,-1)$ 的下标，再找到 $(r,n+1)$ 或 $(r+1,-1)$ 的下标，相减就为 $[l,r]$ 内的元素数。

复杂度 $O(n\log n)$。

```c++
using ll = long long;
using pr = pair<ll, int>;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
class Solution
{
public:
    int countRangeSum(const vector<int> &nums, int lower, int upper)
    {
        ll ss = 0, n = nums.size(), ans = 0;
        __gnu_pbds::tree<pr, __gnu_pbds::null_type, less<pr>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> tr; // set
        vector<ll> s(n);
        for (ll i = 0; i < n; ++i)
        {
            ss += nums[i];
            s[i] = ss;
            tr.insert({s[i], i});
        }
        ll lf = lower, rf = upper;
        for (int i = 0; i < n; ++i)
        {
            ll li = tr.order_of_key({lf, -1});
            ll ri = tr.order_of_key({rf, n + 1});
            ans += ri - li;
            tr.erase({s[i], i});
            lf += nums[i], rf += nums[i];
        }
        return ans;
    }
};
```

考虑上述过程逆序，等效于不断插入元素，然后求某个区间内有多少元素。离散化后可以设权值树状数组/线段树来求解。为了在每个差值超过 1 的值之间可设中间值，考虑离散化时添加一些冗余值，如对需要离散化的 $(-10^9,4,5,700)$，可以转化为对 $(-10^9,-10^5,4,5,350,700)$ 离散化。此解法略。



其他解法：

显然原问题是求 $(i,j)$ 数目满足 $s_j-s_i\in[lower,upper]$。

考虑两个升序序列，$a,b$，求 $a_j-b_i\in [lower,upper]$，显然可以归并思路滑窗，遍历 $b$ 在 $a$ 上维护双指针。

![image.png](img/1604740489-tzFzdh-image.png)

根据上图解释，可知排序不会影响答案。所以直接归并即可。

```java
class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        long s = 0;
        long[] sum = new long[nums.length + 1];
        for (int i = 0; i < nums.length; ++i) {
            s += nums[i];
            sum[i + 1] = s;
        }
        return countRangeSumRecursive(sum, lower, upper, 0, sum.length - 1);
    }

    public int countRangeSumRecursive(long[] sum, int lower, int upper, int left, int right) {
        if (left == right) {
            return 0;
        } else {
            int mid = (left + right) / 2;
            int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
            int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
            int ret = n1 + n2;

            // 首先统计下标对的数量
            int i = left;
            int l = mid + 1;
            int r = mid + 1;
            while (i <= mid) {
                while (l <= right && sum[l] - sum[i] < lower) {
                    l++;
                }
                while (r <= right && sum[r] - sum[i] <= upper) {
                    r++;
                }
                ret += r - l;
                i++;
            }

            // 随后合并两个排序数组
            long[] sorted = new long[right - left + 1];
            int p1 = left, p2 = mid + 1;
            int p = 0;
            while (p1 <= mid || p2 <= right) {
                if (p1 > mid) {
                    sorted[p++] = sum[p2++];
                } else if (p2 > right) {
                    sorted[p++] = sum[p1++];
                } else {
                    if (sum[p1] < sum[p2]) {
                        sorted[p++] = sum[p1++];
                    } else {
                        sorted[p++] = sum[p2++];
                    }
                }
            }
            for (int j = 0; j < sorted.length; j++) {
                sum[left + j] = sorted[j];
            }
            return ret;
        }
    }
}
```

一种线段树参考：(顺序枚举，即对每个$j$，枚举可能的 $i$ 满足 $low\le s_j-s_i\le high$)

```java
class Solution {
    public int countRangeSum(int[] nums, int lower, int upper) {
        long sum = 0;
        long[] preSum = new long[nums.length + 1];
        for (int i = 0; i < nums.length; ++i) {
            sum += nums[i];
            preSum[i + 1] = sum;
        }
        
        Set<Long> allNumbers = new TreeSet<Long>();
        for (long x : preSum) {
            allNumbers.add(x);
            allNumbers.add(x - lower);
            allNumbers.add(x - upper);
        }
        // 利用哈希表进行离散化
        Map<Long, Integer> values = new HashMap<Long, Integer>();
        int idx = 0;
        for (long x : allNumbers) {
            values.put(x, idx);
            idx++;
        }

        SegNode root = build(0, values.size() - 1);
        int ret = 0;
        for (long x : preSum) {
            int left = values.get(x - upper), right = values.get(x - lower);
            ret += count(root, left, right);
            insert(root, values.get(x));
        }
        return ret;
    }

    public SegNode build(int left, int right) {
        SegNode node = new SegNode(left, right);
        if (left == right) {
            return node;
        }
        int mid = (left + right) / 2;
        node.lchild = build(left, mid);
        node.rchild = build(mid + 1, right);
        return node;
    }

    public int count(SegNode root, int left, int right) {
        if (left > root.hi || right < root.lo) {
            return 0;
        }
        if (left <= root.lo && root.hi <= right) {
            return root.add;
        }
        return count(root.lchild, left, right) + count(root.rchild, left, right);
    }

    public void insert(SegNode root, int val) {
        root.add++;
        if (root.lo == root.hi) {
            return;
        }
        int mid = (root.lo + root.hi) / 2;
        if (val <= mid) {
            insert(root.lchild, val);
        } else {
            insert(root.rchild, val);
        }
    }
}

class SegNode {
    int lo, hi, add;
    SegNode lchild, rchild;

    public SegNode(int left, int right) {
        lo = left;
        hi = right;
        add = 0;
        lchild = null;
        rchild = null;
    }
}
```

动态加点的线段树，可以不做离散化：

```c++
struct SegNode {
    long long lo, hi;
    int add;
    SegNode* lchild, *rchild;
    SegNode(long long left, long long right): lo(left), hi(right), add(0), lchild(nullptr), rchild(nullptr) {}
};

class Solution {
public:
    void insert(SegNode* root, long long val) {
        root->add++;
        if (root->lo == root->hi) {
            return;
        }
        long long mid = (root->lo + root->hi) >> 1;
        if (val <= mid) {
            if (!root->lchild) {
                root->lchild = new SegNode(root->lo, mid);
            }
            insert(root->lchild, val);
        }
        else {
            if (!root->rchild) {
                root->rchild = new SegNode(mid + 1, root->hi);
            }
            insert(root->rchild, val);
        }
    }

    int count(SegNode* root, long long left, long long right) const {
        if (!root) {
            return 0;
        }
        if (left > root->hi || right < root->lo) {
            return 0;
        }
        if (left <= root->lo && root->hi <= right) {
            return root->add;
        }
        return count(root->lchild, left, right) + count(root->rchild, left, right);
    }

    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0;
        vector<long long> preSum = {0};
        for(int v: nums) {
            sum += v;
            preSum.push_back(sum);
        }
        
        long long lbound = LLONG_MAX, rbound = LLONG_MIN;
        for (long long x: preSum) {
            lbound = min({lbound, x, x - lower, x - upper});
            rbound = max({rbound, x, x - lower, x - upper});
        }
        
        SegNode* root = new SegNode(lbound, rbound);
        int ret = 0;
        for (long long x: preSum) {
            ret += count(root, x - upper, x - lower);
            insert(root, x);
        }
        return ret;
    }
};
```

Treap 平衡树见官方题解，这里略。



##### 329\.矩阵中的最长递增路径

[题目](https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/)

按值降序 DP，每个元素走四方向 max。$O(nm\log(nm))$。

```java
import java.util.Arrays;

class node implements Comparable<node> {
    public int i, j, v;

    public node(int i, int j, int v) {
        this.i = i;
        this.j = j;
        this.v = v;
    }

    @Override
    public int compareTo(node o) {
        return o.v - v;
    }
}

class Solution {
    public int longestIncreasingPath(int[][] matrix) {
        int n = matrix.length, m = matrix[0].length;
        node q[] = new node[n * m];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                q[i * m + j] = new node(i, j, matrix[i][j]);
            }
        }
        Arrays.sort(q);
        final int dx[] = new int[] { -1, 0, 1, 0 };
        final int dy[] = new int[] { 0, -1, 0, 1 };
        int r[][] = new int[n][m], ans = 1;
        for (int i = 0, ie = n * m; i < ie; ++i) {
            node p = q[i];
            int x = p.i, y = p.j, v = p.v;
            for (int j = 0; j < 4; ++j) {
                int nx = x + dx[j], ny = y + dy[j];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || v >= matrix[nx][ny]) {
                    continue;
                }
                r[x][y] = Math.max(r[x][y], r[nx][ny] + 1);
                ans = Math.max(ans, r[x][y] + 1);
            }
        }
        return ans;
    }
}
```

也可以用记忆化 DFS/拓扑序 BFS，复杂度优化为 $O(nm)$：

```java
class Solution {
    public int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public int rows, columns;

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        rows = matrix.length;
        columns = matrix[0].length;
        int[][] memo = new int[rows][columns];
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                ans = Math.max(ans, dfs(matrix, i, j, memo));
            }
        }
        return ans;
    }

    public int dfs(int[][] matrix, int row, int column, int[][] memo) {
        if (memo[row][column] != 0) {
            return memo[row][column];
        }
        ++memo[row][column];
        for (int[] dir : dirs) {
            int newRow = row + dir[0], newColumn = column + dir[1];
            if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[row][column]) {
                memo[row][column] = Math.max(memo[row][column], dfs(matrix, newRow, newColumn, memo) + 1);
            }
        }
        return memo[row][column];
    }
}
```

```java
class Solution {
    public int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    public int rows, columns;

    public int longestIncreasingPath(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) {
            return 0;
        }
        rows = matrix.length;
        columns = matrix[0].length;
        int[][] outdegrees = new int[rows][columns];
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                for (int[] dir : dirs) {
                    int newRow = i + dir[0], newColumn = j + dir[1];
                    if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] > matrix[i][j]) {
                        ++outdegrees[i][j];
                    }
                }
            }
        }
        Queue<int[]> queue = new LinkedList<int[]>();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (outdegrees[i][j] == 0) {
                    queue.offer(new int[]{i, j});
                }
            }
        }
        int ans = 0;
        while (!queue.isEmpty()) {
            ++ans;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                int[] cell = queue.poll();
                int row = cell[0], column = cell[1];
                for (int[] dir : dirs) {
                    int newRow = row + dir[0], newColumn = column + dir[1];
                    if (newRow >= 0 && newRow < rows && newColumn >= 0 && newColumn < columns && matrix[newRow][newColumn] < matrix[row][column]) {
                        --outdegrees[newRow][newColumn];
                        if (outdegrees[newRow][newColumn] == 0) {
                            queue.offer(new int[]{newRow, newColumn});
                        }
                    }
                }
            }
        }
        return ans;
    }
}
```



##### 330\.按要求补齐数组

[题目](https://leetcode.cn/problems/patching-array/)

若 $[1,k)$ 都已经有了，那么填上 $k$，显然可以得到 $[1,2k)$。贪心每次找最小未被覆盖的 $k$，直到能覆盖 $[1,n]$ 为止。

贪心正确性证明：对每个未被覆盖的最小 $k$，$k$ 是一定要被覆盖的，覆盖 $k$ 的所有方案里，直接填 $k$ 能给未来带来最大的覆盖面积。

```java
class Solution {
    public int minPatches(int[] nums, int n) {
        int patches = 0;
        long x = 1;
        int length = nums.length, index = 0;
        while (x <= n) {
            if (index < length && nums[index] <= x) {
                x += nums[index];
                index++;
            } else {
                x *= 2;
                patches++;
            }
        }
        return patches;
    }
}
```



##### 332\.重新安排行程

[题目](https://leetcode.cn/problems/reconstruct-itinerary/)

要么是欧拉路径(起点出度比入度+1，终点入度比出度+1，其他点出入相同)，要么是欧拉回路。但是我们并不需要显式计算出终点是什么，而且已知起点，所以可以不管度。

直接从 `JFK` 作为起点出发，因为保证欧拉路存在，所以在答案里每条边都会被遍历。直接按字典序，遍历当前未访问的最小边(之后在这次遍历里有可能走回这个点)，直到遍历完。按照这个贪心顺序，一定能找到欧拉路径，不然就是无解。显然。

因为要对边排序，故复杂度为 $O(m\log m)$。

```java
class Solution {
    private HashMap<String, ArrayList<String>> g;
    private TreeSet<String> nd;
    private String s = "JFK", t, tops;
    private HashMap<String, Integer> vis;// 当前遍历了它的几条边
    private List<String> ans;

    private void dfs(String u) {
        for (int i = vis.get(u); i < g.get(u).size(); i = vis.get(u)) {
            vis.put(u, i + 1);
            dfs(g.get(u).get(i));
        }
        ans.add(u);
    }

    public List<String> findItinerary(List<List<String>> tickets) {
        g = new HashMap<>();
        nd = new TreeSet<>();
        ans = new ArrayList<>();
        vis = new HashMap<>();
        for (List<String> e : tickets) {
            String u = e.get(0), v = e.get(1);
            if (g.get(u) == null) {
                g.put(u, new ArrayList<>());
            }
            if (g.get(v) == null) {
                g.put(v, new ArrayList<>());
            }
            g.get(u).add(v);
            nd.add(u);
            nd.add(v);
        }
        for (String u : nd) {
            vis.put(u, 0);
            Collections.sort(g.get(u));
        }
        if (t == null) {
            t = tops;
        }
        dfs("JFK");
        Collections.reverse(ans);
        return ans;
    }
}
```

> 一定要后序插入答案。考虑 `J->K,J->N,N->J`，模拟遍历，DFS 序为：
>
> ```
> JFK in
>     KUL in
>     KUL out -> [KUL]
>     NRT in
>         JFK in
>         JFK out -> [JFK, KUL]
>     NRT out -> [NRT, JFK, KUL]
> JFK out -> [JFK, NRT, JFK, KUL]
> ```
>
> 在看一个正常遍历(样例二 `J<->A, S<->A, J->S`)：
>
> ```
> JFK in
> 	ATL in
> 		JFK in
> 			SFO in
> 				ATL in
> 					SFO in
> 					SFO out (S)
> 				ATL out (A,S)
> 			SFO out (S,A,S)
> 		JFK out (J,S,A,S)
> 	ATL out (A,J,S,A,S)
> JFK out (J,A,J,S,A,S)
> ```

为什么后序遍历是可行的，根据上面例子，分析可知，凡是走到底的，都被拖到了最后边，所以如果走到了死路而还没达成欧拉的目标，那么这条思路就会被丢到最后边。证明了可行性。

之所以是最小的，是因为一旦能走到尽头，他就会是首先输出的路，而又是按照升序遍历的，所以综合下来就是贪心最小的。

实际上是 Hierholzer 的思想，vis 的作用是删边。更优实现：

```java
class Solution {
    Map<String, PriorityQueue<String>> map = new HashMap<String, PriorityQueue<String>>();
    List<String> itinerary = new LinkedList<String>();

    public List<String> findItinerary(List<List<String>> tickets) {
        for (List<String> ticket : tickets) {
            String src = ticket.get(0), dst = ticket.get(1);
            if (!map.containsKey(src)) {
                map.put(src, new PriorityQueue<String>());
            }
            map.get(src).offer(dst);
        }
        dfs("JFK");
        Collections.reverse(itinerary);
        return itinerary;
    }

    public void dfs(String curr) {
        while (map.containsKey(curr) && map.get(curr).size() > 0) {
            String tmp = map.get(curr).poll();
            dfs(tmp);
        }
        itinerary.add(curr);
    }
}
```



##### 335\.路径交叉

[题目](https://leetcode.cn/problems/self-crossing/)

官方题解讲得挺好。分类讨论题。

```java
class Solution {
    public boolean isSelfCrossing(int[] distance) {
        int n = distance.length;
        for (int i = 3; i < n; ++i) {
            // 第 1 类路径交叉的情况
            if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) {
                return true;
            }

            // 第 2 类路径交叉的情况
            if (i == 4 && (distance[3] == distance[1]
                && distance[4] >= distance[2] - distance[0])) {
                return true;
            }

            // 第 3 类路径交叉的情况
            if (i >= 5 && (distance[i - 3] - distance[i - 5] <= distance[i - 1]
                && distance[i - 1] <= distance[i - 3]
                && distance[i] >= distance[i - 2] - distance[i - 4]
                && distance[i - 2] > distance[i - 4])) {
                return true;
            }
        }
        return false;
    }
}
```



##### 1617\.统计子树中城市之间最大距离

[题目](https://leetcode.cn/problems/count-subtrees-with-max-distance-between-cities/)

因为 $n=15$，所以枚举边的子集的复杂度是 $O(2^n)$。对每个子集，用并查集 $O(n)$ 判断它是否构成树，方法是判断 $fa_i=i$ 且有度的点有且仅有一个。然后两次 DFS 法 $O(n)$ 求出树的直径。总复杂度为 $O(n2^n)$。板子拼接。

```java
import java.util.ArrayList;
import java.util.Arrays;

class Solution {
    private int ans[], n, m, fa[], e[][];
    private boolean b[][], vis[];
    private ArrayList<Integer> g[];

    private int findfa(int u) {
        while (fa[u] != u) {
            u = fa[u];
        }
        return u;
    }

    private int r, d[];

    private boolean isTree() {
        for (int i = 1; i <= n; ++i) {
            fa[i] = i;
        }
        int du[] = new int[n + 1];
        for (int i = 0; i < m; ++i) {
            int u = e[i][0], v = e[i][1];
            if (b[u][v]) {
                ++du[u];
                ++du[v];
                fa[findfa(u)] = findfa(v);
            }
        }
        int rots = 0;
        for (int i = 1; i <= n; ++i) {
            if (fa[i] == i && du[i] > 0) {
                ++rots;
                r = i;
            }
        }
        return rots == 1;
    }

    private void dfs(int u) {
        vis[u] = true;
        for (Integer v : g[u]) {
            if (b[u][v] && !vis[v]) {
                d[v] = d[u] + 1;
                dfs(v);
            }
        }
    }

    private int getDistance() {
        Arrays.fill(vis, false);
        Arrays.fill(d, 0);
        dfs(r);
        int maxd = 0;
        for (int i = 1; i <= n; ++i) {
            if (d[i] > maxd) {
                maxd = d[i];
                r = i;
            }
        }
        Arrays.fill(vis, false);
        Arrays.fill(d, 0);
        dfs(r);
        maxd = 0;
        for (int i = 1; i <= n; ++i) {
            if (d[i] > maxd) {
                maxd = d[i];
            }
        }
        return maxd;
    }

    @SuppressWarnings("unchecked")
    public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
        this.n = n;
        m = edges.length;
        e = edges;
        b = new boolean[n + 1][n + 1];
        g = new ArrayList[n + 1];
        fa = new int[n + 1];
        d = new int[n + 1];
        vis = new boolean[n + 1];
        for (int i = 0; i <= n; ++i) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; ++i) {
            int u = edges[i][0], v = edges[i][1];
            g[u].add(v);
            g[v].add(u);
        }
        ans = new int[n - 1];
        for (int i = 0, ie = 1 << m; i < ie; ++i) {
            for (int j = 0; j < m; ++j) {
                int u = edges[j][0], v = edges[j][1];
                b[v][u] = b[u][v] = ((i >> j) & 1) == 1;
            }
            if (isTree()) {
                ++ans[getDistance() - 1];
            }
        }
        return ans;
    }
}
```

一种更优解：

先用 floyd 求全源最短路 $dist$。枚举每个 $dist_{x,y}$ 求出其作直径时的子树数目。对每个 $(x,y)$，从 $x$ 开始 DFS $u$，则 $dist_{u,x} > dist_{x,y},dist_{v,y} > dist_{x,y}$ 满足其一的话，$u$ 加进去直径就会改变，所以不能加入。显然在树上 $x,y$ 路径唯一，所以不会出现第二条路径使得 $dist_{u,x}+dist_{u,y} > dist_{x,y}$。只要 $u$ 在 $x,y$ 的路径上，必然满足 $dist_{u,x}+dist_{u,y}=dist_{x,y}$，否则就 $>$，代表 $u$ 在支路，那么在支路上可选可不选，就要作乘法处理。乘上选与不选 $u$ 继续 DFS 的子树里，总可行方案数。所以只要在支路上，这条边就要 +1，也就是它当前继续走的子树有 $ret$ 个，则要么选这条边共有 $ret$ 个方案，要么不选边有一个方案，共 $ret+1$ 个方案。对 $ret$ 的累积，即把每个子树的方案乘起来即可。

现在考虑一个去重问题，以菊花树为例，一个子树可能会有多条最长路径都作为直径。所以我们只能统计其中的一条，其他的都要作废。当发现一条与直径 $dist_{x,y}$ 相等的路径时，必然满足 $dist_{u,x}=dist_{x,y}$ 或 $dist_{u,y}=dist_{x,y}$。当发现取等时，我们考虑剪掉所有 $u < x$(第一个取等)或 $u < y$(第二个取等)。手玩菊花树发现这样能做到不重不漏。

floyd 需要 $O(n^3)$，需要枚举 $O(n^2)$ 次直径，对每条直径进行 $O(n)$ DFS，故总复杂度为 $O(n^3)$。

```java
class Solution {
    public int[] countSubgraphsForEachDiameter(int n, int[][] edges) {
        List<Integer>[] adj = new List[n];
        int[][] dist = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], Integer.MAX_VALUE);
            dist[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for (int[] edge : edges) {
            int x = edge[0] - 1;
            int y = edge[1] - 1;
            adj[x].add(y);
            adj[y].add(x);
            dist[x][y] = dist[y][x] = 1;
        }
        for (int i = 0; i < n; i++) { //floyd
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (dist[j][i] != Integer.MAX_VALUE && dist[i][k] != Integer.MAX_VALUE) {
                        dist[j][k] = Math.min(dist[j][k], dist[j][i] + dist[i][k]);
                    }
                }
            }
        }
        int[] ans = new int[n - 1];
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ans[dist[i][j] - 1] += dfs(adj, dist, i, -1, i, j);
            }
        }
        return ans;
    }

    public int dfs(List<Integer>[] adj, int[][] dist, int u, int parent, int x, int y) {
        if (dist[u][x] > dist[x][y] || dist[u][y] > dist[x][y]) {
            return 1;
        }
        if ((dist[u][y] == dist[x][y] && u < x) || (dist[u][x] == dist[x][y] && u < y)) {
            return 1;
        }
        int ret = 1;
        for (int v : adj[u]) {
            if (v != parent) { //vis
                ret *= dfs(adj, dist, v, u, x, y);
            }
        }
        if (dist[u][x] + dist[u][y] > dist[x][y]) {
            ret++;
        }
        return ret;
    }
}
```



##### 336\.回文对

[题目](https://leetcode.cn/problems/palindrome-pairs/)

计算每个串的字符串哈希 $hp_i$ 及其反串的哈希 $hn_i$，设长度为 $n_i$。对每个 $(i,j)$，拼接起来后的正串的哈希为 $hp_i \cdot n_j+hp_j$，拼接后的反串的哈希为 $hn_j\cdot n_i+hn_i$。若两者相等，即原串=反串，表明是回文串。复杂度为 $O(n^2+nm)$。其中 $m$ 为字符串长度。

注意到这题数据卡哈希，所以 $p=131$ 不行，要换成 $p=233$ 或其他质数。

```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    final static private int p = 233;
    final static private int pw[] = new int[302];
    private int[] hp, hn;

    private List<Integer> wrap(int x, int y) {
        List<Integer> res = new ArrayList<>(2);
        res.add(x);
        res.add(y);
        return res;
    }

    public List<List<Integer>> palindromePairs(String[] words) {
        int n = words.length;
        hp = new int[n];
        hn = new int[n];
        pw[0] = 1;
        for (int i = 1; i <= 301; ++i) {
            pw[i] = pw[i - 1] * p;
        }
        for (int i = 0; i < n; ++i) {
            int h = 0;
            for (int j = 0, je = words[i].length(); j < je; ++j) {
                h = h * p + words[i].charAt(j);
            }
            hp[i] = h;

            h = 0;
            for (int j = words[i].length() - 1; j >= 0; --j) {
                h = h * p + words[i].charAt(j);
            }
            hn[i] = h;
       }
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    continue;
                }
                int ni = words[i].length(), nj = words[j].length();
                int hp0 = hp[i] * pw[nj] + hp[j];
                int hn0 = hn[j] * pw[ni] + hn[i];
                if (hp0 == hn0) {
                    ans.add(wrap(i, j));
                }
            }
        }
        return ans;
    }
}
```

还能 trie + manacher。[参考](https://leetcode.cn/problems/palindrome-pairs/solution/wa-pian-336-hui-wen-dui-java-3333-zi-dia-jca0/)。

具体而言，先用反串建字典树。然后对每个串跑一次 manacher，如果该串是回文，它与空串可以配对。如果该串某个前缀是回文，那么该串剩下的不是回文的后缀，在字典树里找找有没有其反串，有的话可以拼在一起。同理，如果某个后缀是回文，那么其前缀可以找有没有可以拼的。单个 manacher 共遍历 $O(m)$ 次，每次 trie 最坏 $O(m)$，故复杂度 $O(nm^2)$。

```java
class Solution {
	class Node {
		Node[] cs;
		Integer index;

		public Node() {
			cs = new Node[26];
			index = null;
		}

		public void add(String word, int index) {
			Node node = this;
			for (char c : word.toCharArray()) {
				int cur = c - 'a';
				if (node.cs[cur] == null) {
					node.cs[cur] = new Node();
				}
				node = node.cs[cur];
			}
			node.index = index;
		}

		public Integer find(char[] chars, int start, int len) {
			Node node = this;
			for (int i = len - 1; i >= start; i--) {
				char c = chars[i];
				if (c == '#') {
					continue;
				}
				int index = c - 'a';
				if (node.cs[index] == null) {
					return null;
				}
				node = node.cs[index];
			}
			return node.index;
		}
	}

	Node root;
	Integer emptyIndex;

	public List<List<Integer>> palindromePairs(String[] words) {
		emptyIndex = null;
		root = new Node();
		List<List<Integer>> ans = new ArrayList<>();
		for (int i = 0; i < words.length; i++) {
			String word = words[i];
			if (word.length() == 0) {
				emptyIndex = i;
			} else {
				root.add(word, i);
			}
		}
		for (int i = 0; i < words.length; i++) {
			String word = words[i];
			if (word.length() == 0) {
				continue;
			} else {
				this.longestPalindrome(word, i, ans);
			}
		}
		return ans;
	}

	public void longestPalindrome(String s, int index, List<List<Integer>> ans) {
		char[] chars = this.sharp(s);
		int[] radius = new int[chars.length];
		int center = -1;
		int range = -1;
		int start = -1;
		int end = -1;
		int len = chars.length;
		for (int i = 0; i < len; i++) {
			radius[i] = range > i ? Math.min(radius[((center) << 1) - i], range - i) : 1;
			while (i + radius[i] < len && i - radius[i] > -1 && chars[i + radius[i]] == chars[i - radius[i]]) {
				radius[i]++;
			}
			if (i + radius[i] > range) {
				range = i + radius[i];
				center = i;
			}
			start = i - radius[i] + 1;
			end = i + radius[i];// - 1
			boolean pre = start == 0;// 前半段回文
			boolean suf = end == len;// 后半段回文 - 1
			if (pre && suf) {// 整体是回文
				if (emptyIndex != null) {
					ans.add(Arrays.asList(index, this.emptyIndex));
					ans.add(Arrays.asList(this.emptyIndex, index));
				}
			}
			if (pre && end > 1 && end != len) {// 从开头开始的前部分，不能是整体，跳过第一个#
				Integer leftIndex = root.find(chars, end, len);
				if (leftIndex != null) {
					ans.add(Arrays.asList(leftIndex, index));
				}
			}
			if (suf && start < len - 1 && start != 0) {
				Integer rightIndex = root.find(chars, 1, start);
				if (rightIndex != null) {
					ans.add(Arrays.asList(index, rightIndex));
				}
			}

		}
		Integer allIndex = root.find(chars, 1, len);
		if (allIndex != null && allIndex != index) {
			ans.add(Arrays.asList(allIndex, index));
		}
	}

	private char[] sharp(String s) {
		char[] chars = new char[(s.length() << 1) | 1];
		int p = 0;
		for (int i = 0; i < chars.length; i++) {
			if ((i & 1) == 0) {
				chars[i] = '#';
			} else {
				chars[i] = s.charAt(p++);
			}
		}
		return chars;
	}
}
```



##### 352\.将数据流变为多个不相交区间

[题目](https://leetcode.cn/problems/data-stream-as-disjoint-intervals/)

手写静态双向链表。初始设负无穷和正无穷，所有节点失效且指向无穷。负无穷下标设 $0$，故整体往右偏移一位。维护一个 treeset 表示当前所有区间左端点，初始设负无穷加入。对每个插入的 $u$，找到最大小于它的点，然后在链表里找到它的下一个点，这两个点就是新节点的链表前后点。然后连接起来。

之后可能需要合并。设布尔值数组表示每个值是否出现过，如果 $u+1$ 出现过，则一定可以往后合并。如果 $u-1$ 也出现过，那么再往前合并。注意一定要先往后合并，手玩易知。

维护一个整型(或 treeset 的 size)表示当前区间数，然后提前开好数组长度，并遍历链表即可。可以再每个节点维护区间长度，合并时叠加长度。

设值域长度为 $m$，复杂度为 $O(\log m)$，空间复杂度为 $O(m)$。

 ```java
 import java.util.Arrays;
 import java.util.TreeSet;
 
 class SummaryRanges {
     private static final int n = 10005;
     private int pr[] = new int[n];
     private int nx[] = new int[n];
     private int cnt[] = new int[n];
     private boolean vis[] = new boolean[n];
     private TreeSet<Integer> t = new TreeSet<>();
     private int m;
 
     private void merge(int u, int v) {// u<-v
 //        System.out.println("Merge " + u + " " + v);
         m--;
         t.remove(v);
         nx[u] = nx[v];
         pr[nx[v]] = u;
         cnt[u] += cnt[v];
     }
 
     private void insert(int u) {
         if (!vis[u]) {
             vis[u] = true;
             int pu = t.lower(u);
             int nu = nx[pu];
             nx[pu] = pr[nu] = u;
             pr[u] = pu;
             nx[u] = nu;
             cnt[u] = 1;
             ++m;
             t.add(u);
 
             if (vis[u + 1]) { //必须先右
                 merge(u, nu);
             }
             if (vis[u - 1]) {
                 merge(pu, u);
             }
         }
 //        System.out.println(m);
     }
 
     public SummaryRanges() {
         Arrays.fill(nx, n - 1);
         t.add(0);
     }
 
     public void addNum(int value) {
         insert(value + 1);
     }
 
     public int[][] getIntervals() {
         int ans[][] = new int[m][2];
         for (int i = nx[0], j = 0; i != n - 1; i = nx[i], ++j) {
 //            System.out.println((i - 1) + "!");
             ans[j][0] = i - 1;
             ans[j][1] = i + cnt[i] - 1 - 1;
         }
         return ans;
     }
 }
 ```



##### 354\.俄罗斯套娃信封问题

[题目](https://leetcode.cn/problems/russian-doll-envelopes/)

先按 $w$ 升序排序，假设 $w$ 互不相同，则接下来只需要在 $h$ 找最长上升子序列。然而考虑 $(1,1),(1,2),(1,3),(1,4)$，是不可行的。对每个 $w$ 最多选一个信封。

再第二关键字将 $h$ 降序排序，从而避免了相同下存在递增。然后直接跑 LIS 即可。这是一个经典模板，维护严格单调递增的单调栈即可，如果值大于栈顶就入栈，否则，二分单调栈，找到 $\ge$ 值的位置进行替换。

java 可以用 list 实现可任意遍历的单调栈，用 `binarySearch` 函数进行二分。如果查找成功返回对应下标(有多个相等的则返回任意)，如果查找失败，返回一个负数 $i$，其 $-(i+1)$ 代表该值应该插入到的位置。

复杂度是 $O(n\log n)$。参考：

```java
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

class Solution {
    public int maxEnvelopes(int[][] envelopes) {
        int[][] a = envelopes;// 数组名字太长不好写
        Arrays.sort(a, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[0] == o2[0]) {
                    return o2[1] - o1[1];
                } else {
                    return o1[0] - o2[0];
                }
            }
        });
        int n = a.length;
        ArrayList<Integer> s = new ArrayList<>();
        s.add(a[0][1]);
        for (int i = 1; i < n; ++i) {
            if (s.get(s.size() - 1) < a[i][1]) {
                s.add(a[i][1]);
            } else {
                int j = Collections.binarySearch(s, a[i][1]);
                j = j >= 0 ? j : -(j + 1);
                s.set(j, a[i][1]);
            }
        }
        return s.size();
    }
}
```



##### 2488\.统计中位数为k的子数组

[题目](https://leetcode.cn/problems/count-subarrays-with-median-k/)

根据数据范围可知有且仅有一个 $k$。所有有效区间一定包含 $k$，这些有效区间可以拆分为 $k$ 左子区间(含 $k$)与 $k$ 右子区间。设 $> k$ 贡献 $1$，$< k$ 贡献 $-1$，$k$ 贡献 $0$，则一个区间符合题意当且仅当区间贡献和是 $0$ 或 $1$。

从 $k$ 开始(含 $k$)往左叠前缀和，把前缀和计数存桶。然后再往右叠前缀和 $s$，则满足的区间的前缀和是 $s+x=0/1$，解得 $x=-s/(1-s)$，所以每次查桶里有几个 $-s,1-s$，累加上去即可。

时空复杂度 $O(n)$。

```java
class Solution {
    private static int dt(int v, int k) {
        return v > k ? 1 : -1;
    }

    public int countSubarrays(int[] nums, int k) {
        int n = nums.length, j = 0;
        int b[] = new int[2 * n + 3], dt = n + 1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == k) {
                j = i;
                break;
            }
        }
        ++b[0 + dt];
        for (int i = j - 1, s = 0; i >= 0; --i) {
            s += dt(nums[i], k);
            ++b[s + dt];
        }
        int ans = b[dt] + b[1 + dt];
        for (int i = j + 1, s = 0; i < n; ++i) {
            s += dt(nums[i], k);
            ans += b[-s + dt] + b[1 - s + dt];
        }
        return ans;
    }
}
```



##### 363\.矩形区域不超过k的最大数值和

[题目](https://leetcode.cn/problems/max-sum-of-rectangle-no-larger-than-k/)

先考虑对一维问题如何快速求解。即求 $s_r-s_l \le k$ 的最大解。可以枚举 $s_r$，然后约束条件转化为 $s_l\ge k-s_r$，显然满足约束的前提下，$s_l$ 越小越好。所以将已知 $s_l$ 存 set，找到大于等于 $k-s_r$ 的最小 $s_l$。

拓展到二维，枚举矩形左上角和左下角，然后对固定的高，用上述技巧枚举宽。复杂度为 $O(n^2m\log m)$。空间复杂度可以做到 $O(m)$。

```java
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        int n = matrix.length, m = matrix[0].length;
        int s[] = new int[m], ans = Integer.MIN_VALUE;// not ans=0
        TreeSet<Integer> t = new TreeSet<>();
        for (int i = 0; i < n; ++i) {
            Arrays.fill(s, 0);
            for (int j = i; j < n; ++j) {
                for (int l = 0; l < m; ++l) {
                    s[l] += matrix[j][l];
                } // s[l]=sum matrix[i..j][l]
                t.clear();
                t.add(0);// 全选
                for (int l = 0, sr = 0; l < m; ++l) {
                    sr += s[l];
                    Integer sl = t.ceiling(sr - k);
                    if (sl != null) {
                        ans = Math.max(ans, sr - sl);
                    }
                    if (ans == k) {
                        return ans;// 神奇剪枝,不用也行
                    }
                    t.add(sr);
                }
            }
        }
        return ans;
    }
}
```

一种卡常暴力：

```java
class Solution {
    public int maxSumSubmatrix(int[][] matrix, int k) {
        // 先整理出每个点到原点的矩形面积，那么，两个点之间的矩形面积就很好算了
        int m = matrix.length;
        int n = matrix[0].length;

        int max = Integer.MIN_VALUE;
        // 固定一列，另外一列往右移动，计算sum，二维转一维求解
        for (int first = 0; first < n; first++) {
            int[] sum = new int[m];
            for (int second = first; second < n; second++) {
                for (int row = 0; row < m; row++) {
                    sum[row] += matrix[row][second];
                }
                // 求sum中最接近k的连续子数组的和
                max = Math.max(max, nearly(sum, k));
                if (max == k) {
                    return k;
                }
            }
        }

        return max;
    }

    private int nearly(int[] sum, int k) {
        // 1,-3,2,1,-1,-2  4

        // 求连续的正数和的最大值，如果小于等于k可以直接返回
        int max = Integer.MIN_VALUE;
        int currentMax = Integer.MIN_VALUE;
        for (int i = 0; i < sum.length; i++) {
            // 如果之前连续的和小于0，则重新计数
            currentMax = Math.max(currentMax, 0) + sum[i];
            max = Math.max(max, currentMax);
            if (max == k) {
                return k;
            }
        }

        if (max < k) {
            return max;
        }

        // 求[i,j]连续和
        max = Integer.MIN_VALUE;
        for (int i = 0; i < sum.length; i++) {
            int currSum = 0;
            for (int j = i; j < sum.length; j++) {
                currSum += sum[j];
                if (currSum == k) return k;
                if (currSum < k) max = Math.max(max, currSum);
            }
        }

        return max;
    }
}
```



##### 381\.O(1)时间插入、删除和获取随机元素-允许重复

[题目](https://leetcode.cn/problems/insert-delete-getrandom-o1-duplicates-allowed/)

截止23/3/18，时间 27ms(击败97.18%)，空间 88.6M(击败61.70%)

因为要等概率抽取，所以考虑把所有元素存到名为 bin 的 arraylist / 静态数组里。然后 rand 一个下标读取，可以实现等概率。但是需要涉及删除，如果真删的话，又需要 $O(n)$ 的代价。所以考虑做假删除，即另设一个 bool 数组 alive 表示某个位置是否被删除。对每个删除，直接标 alive false 即可。那么要随机取时，就会取空，所以要不断 rand 直到 rand 的位置不为空为止。设当前数组长度是 $n$，alive true 总数是 $m$，那么平均需要抽取 $\dfrac nm$ 次才能抽中。如果 $m$ 极小，会退化为 $O(n)$ 的随机抽取代价。

考虑当 $m$ 小到一定程度时，重新整理数组，把所有 alive false 位置删掉，即强行 resize 剔除全部空位，用双指针实现，需要 $O(n)$ 的复杂度每次，在这之后，$n$ 会降到为 $m$。考虑在 $mk < n$ 时进行整理操作。如果 $k$ 过大，则随机抽取的复杂度为 $O(k)$ 会很大。如果 $k$ 过小， 则可能需要频繁整理。当 $n$ 很大时，整理的代价比较大，不妨设 $k=10$。

> 假设插入、删除操作和取随机操作等概率出现，则期望每次需要抽取 $O(k)$ 次才能抽中，且等效于每次插入就会出现一个空位，那么 $O(k)$ 次之后就会刷新一次，代价是 $O(n)$，即平均复杂度是 $O(k+\dfrac nk)$，所以理论上最好是 $k=\sqrt n$。简便起见，可以设 $k=\sqrt{2\times 10^5}=443$。则理论均摊复杂度为 $O(\sqrt n)$。但是考虑阴间数据，一次性插完后删到 $mk\approx 443$，然后不断随机询问，则复杂度比较大。但是如果 $k$ 比较小，比如 $k=2$，则随机抽取 $O(2)=O(1)$，但最坏可以卡到先插入 $x-1$ 个数据，然后不断插入 $x+1$ 个删除 $x+1$ 个，均摊下来也只是相当于二倍常数而已。所以对阴间数据，$k$ 小比较保险。
>
> 事实上本题数据弱，即便不整理也能过。我们直接设 $k=10$，经验表明，比 $k=2$ 快，但再提高 $k$ 没有显著提升。

现在考虑插入和删除。需要 $O(1)$ 查存在，考虑 hashmap $h$，合并同值的所有 bin 下标，每个元素是 arraylist 或 hashset。因此在维护上述 bin 时，要增加维护 hashset，即每次插入 $v$ 时，先取得 bin 里下标 $i$，对 $h_v$ 插入 $i$。每次删除时，取出 $h_v$ 里任意一个 $i$ 进行删除。整理时重新初始化 $h$。随机访问不变。

具体代码如下：

```java
class RandomizedCollection {
    private int n, m;// 桶长,实际面积
    private ArrayList<Integer> bin;
    private ArrayList<Boolean> alive;
    private HashMap<Integer, ArrayList<Integer>> h;// 套Arraylist即可
    private static Random rand = new Random();

    private int add(int v) {
        bin.add(v);
        alive.add(true);
        ++n;
        ++m;
        return n - 1;
    }

    private void del(int i) {
        alive.set(i, false);
        --m;
//        System.out.println(n + "+" + m);
        if (m *10 < n) {
           shrink();
        }
//        System.out.println(n + "-" + m);
    }

    private void shrink() {
        h.clear();
        for (int i = 0, j = 0; i < n; ++i) {
            if (alive.get(i)) {
                bin.set(j++, bin.get(i));
            }
            alive.set(i, false);
        }
        for (int i = n - 1; i >= m; --i) {
            bin.remove(i);
            alive.remove(i);
        }
        n=m;
        for (int i = 0; i < n; ++i) {
            alive.set(i, true);
            int v = bin.get(i);
            ArrayList<Integer> lt = h.get(v);
            if (lt == null) {
                lt = new ArrayList<>();
                h.put(v, lt);
            }
            lt.add(i);
        }
    }

    public RandomizedCollection() {
        h = new HashMap<>();
        bin = new ArrayList<>();
        alive = new ArrayList<>();
        n = 0;
        m = 0;
    }

    public boolean insert(int val) {
        ArrayList<Integer> lt = h.get(val);
        int lts = 0;
        if (lt == null) {
            lt = new ArrayList<>();
            h.put(val, lt);
        } else {
            lts = lt.size();
        }
        int pos = add(val);
        lt.add(pos);
        return lts == 0;
    }

    public boolean remove(int val) {
        ArrayList<Integer> lt = h.get(val);
        if (lt == null || lt.size() == 0) {
//            System.out.println("Fatal");
            return false;
        }
//        System.out.print(lt.size() + " ");
        int pos = lt.get(lt.size() - 1);
        lt.remove(lt.size() - 1);
        del(pos);
//        System.out.println(h.get(val).size());
        return true;
    }

    public int getRandom() {
        int ret = 0;
//        System.out.println(n + " " + m);
        while (true) {
            int i = rand.nextInt(n);
            if (alive.get(i)) {
                ret = bin.get(i);
//                del(i);
//                h.get(ret).remove(i);
                break;
            }
        }
        return ret;
    }
}
```

题解解法：照常开 map 套 set 和 bin。插入直接维护。对删除，直接原地把 bin 的最后一个元素挪到要删除的位置，然后更新 map。

````java
class RandomizedCollection {
    Map<Integer, Set<Integer>> idx;
    List<Integer> nums;

    /** Initialize your data structure here. */
    public RandomizedCollection() {
        idx = new HashMap<Integer, Set<Integer>>();
        nums = new ArrayList<Integer>();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        nums.add(val);
        Set<Integer> set = idx.getOrDefault(val, new HashSet<Integer>());
        set.add(nums.size() - 1);
        idx.put(val, set);
        return set.size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (!idx.containsKey(val)) {
            return false;
        }
        Iterator<Integer> it = idx.get(val).iterator();  
        int i = it.next();
        int lastNum = nums.get(nums.size() - 1);
        nums.set(i, lastNum);
        idx.get(val).remove(i);
        idx.get(lastNum).remove(nums.size() - 1);
        if (i < nums.size() - 1) {
            idx.get(lastNum).add(i);
        }
        if (idx.get(val).size() == 0) {
            idx.remove(val);
        }
        nums.remove(nums.size() - 1);
        return true;
    }
    
    /** Get a random element from the collection. */
    public int getRandom() {
        return nums.get((int) (Math.random() * nums.size()));
    }
}
````



##### 391\.完美矩阵

[题目](https://leetcode.cn/problems/perfect-rectangle/)

将每个矩形看成是两条竖线，建立扫描线。按照 $x$ 排序。然后每次判断同一个 $x$ 的扫描线是否覆盖全部 $y$，即离散化后所有取值范围，并且每个 $y$ 段覆盖且仅覆盖一次。

考虑快速判断上述要求，不妨建立线段树，维护区间最大最小值。则根节点的最大值和最小值都为 1 即可。不可以维护区间和，因为空段可以被重复段作伪导致看起来和是均 1。然后需要支持区间加法维护，所以加懒标记。

因为需要维护线段树，所以 $y$ 的跨度不建议太大，可以考虑离散化。这题不离散化也行。

离散化后，总复杂度为 $O(n\log n)$，空间复杂度为 $O(4n)$。

```java
import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.TreeSet;

class segtree {// 维护区间加法，求根节点最大最小值
    private int mi[], mx[], n, lazy[];

    public segtree(int n) {
        this.n = n;
        n *= 4;
        mi = new int[n];
        mx = new int[n];
        lazy = new int[n];
    }

    private void pushdown(int p) {
        int lfs = p << 1, rfs = p << 1 | 1;
        lazy[lfs] += lazy[p];
        lazy[rfs] += lazy[p];
        mi[lfs] += lazy[p];
        mx[lfs] += lazy[p];
        mi[rfs] += lazy[p];
        mx[rfs] += lazy[p];
        lazy[p] = 0;
    }

    private void pushup(int p) {
        int lfs = p << 1, rfs = p << 1 | 1;
        mi[p] = Math.min(mi[lfs], mi[rfs]);
        mx[p] = Math.max(mx[lfs], mx[rfs]);
    }

    private void upd(int p, int lf, int rf, int lc, int rc, int v) {
//        System.out.println("upd " + p + " " + lf + " " + rf);
        if (lc <= lf && rc >= rf) {
            lazy[p] += v;
            mi[p] += v;
            mx[p] += v;
            return;
        }
        pushdown(p);
        int cf = (lf + rf) >> 1, lfs = p << 1, rfs = p << 1 | 1;
        if (cf >= lc) {
            upd(lfs, lf, cf, lc, rc, v);
        }
        if (cf + 1 <= rc) {
            upd(rfs, cf + 1, rf, lc, rc, v);
        }
        pushup(p);
//        System.out.println("upd " + lf + " " + rf + " " + mi[p] + " " + mx[p]);
    }

    public void add(int lc, int rc, int v) {
//        System.out.println("add " + lc + " " + rc + " " + v);
        upd(1, 0, n - 1, lc, rc, v);
//        System.out.println("res " + mi[1] + " " + mx[1]);
    }

    public boolean check() {
        return mi[1] == 1 && mx[1] == 1;
    }
}

class Solution {
    public boolean isRectangleCover(int[][] a) {
        int n = a.length;
        // 离散化
        TreeSet<Integer> h = new TreeSet<>();
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < 4; j += 2) {
                h.add(a[i][j]);
            }
        }
        int ha[] = new int[h.size()];
        Iterator<Integer> it = h.iterator();
        for (int i = 0, ie = ha.length; i < ie; ++i) {
            ha[i] = it.next();
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < 4; j += 2) {
                a[i][j] = Arrays.binarySearch(ha, a[i][j]);
            }
        }

        int b[][] = new int[n * 2 + 1][4];// ymin,ymax,x,in/out
        for (int i = 0, j = 0; i < n * 2; i += 2, ++j) {
            b[i][0] = b[i + 1][0] = a[j][1];
            b[i][1] = b[i + 1][1] = a[j][3];
            b[i][2] = a[j][0];
            b[i + 1][2] = a[j][2];
            b[i][3] = 1;
            b[i + 1][3] = -1;
        }
        b[2 * n][2] = Integer.MAX_VALUE;
        Arrays.sort(b, new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return o1[2] - o2[2];
            }
        });

        segtree tr = new segtree(ha.length - 1);
        for (int i = 0; i < 2 * n; ++i) {
            int ymi = b[i][0], ymx = b[i][1], v = b[i][3];
            tr.add(ymi, ymx - 1, v);
            if (i + 1 < 2 * n && b[i][2] != b[i + 1][2]) {
                if (!tr.check()) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

纯扫描线解法：两关键字排序，然后拆为 $x$ 相同的组，对每一组，合并连续线段，得到若干不连续线段。按照出入分类。最开始和最末尾，必须有且仅有一条全长线段。对其他情况，比如出入分别完全重合。即判断出入两个线段组是否完全重合，不是的话不合法。

```java
class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        int n = rectangles.length;
        int[][] rs = new int[n * 2][4];
        for (int i = 0, idx = 0; i < n; i++) {
            int[] re = rectangles[i];
            rs[idx++] = new int[]{re[0], re[1], re[3], 1};
            rs[idx++] = new int[]{re[2], re[1], re[3], -1};
        }
        Arrays.sort(rs, (a,b)->{
            if (a[0] != b[0]) return a[0] - b[0];
            return a[1] - b[1];
        });
        n *= 2;
        // 分别存储相同的横坐标下「左边的线段」和「右边的线段」 (y1, y2)
        List<int[]> l1 = new ArrayList<>(), l2 = new ArrayList<>(); 
        for (int l = 0; l < n; ) {
            int r = l;
            l1.clear(); l2.clear();
            // 找到横坐标相同部分
            while (r < n && rs[r][0] == rs[l][0]) r++;
            for (int i = l; i < r; i++) {
                int[] cur = new int[]{rs[i][1], rs[i][2]};
                List<int[]> list = rs[i][3] == 1 ? l1 : l2;
                if (list.isEmpty()) {
                    list.add(cur);
                } else {
                    int[] prev = list.get(list.size() - 1);
                    if (cur[0] < prev[1]) return false; // 存在重叠
                    else if (cur[0] == prev[1]) prev[1] = cur[1]; // 首尾相连
                    else list.add(cur); 
                }
            }
            if (l > 0 && r < n) {
                // 若不是完美矩形的边缘竖边，检查是否成对出现
                if (l1.size() != l2.size()) return false;
                for (int i = 0; i < l1.size(); i++) {
                    if (l1.get(i)[0] == l2.get(i)[0] && l1.get(i)[1] == l2.get(i)[1]) continue;
                    return false;
                }
            } else {
                // 若是完美矩形的边缘竖边，检查是否形成完整一段
                if (l1.size() + l2.size() != 1) return false;
            }
            l = r;
        }
        return true;
    }
}
```

官解：满足①大矩形面积是各矩形面积之和；②除了大矩形四个顶点外，每个点的重合度仅能是2或4。

```java
class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        long area = 0;
        int minX = rectangles[0][0], minY = rectangles[0][1], maxX = rectangles[0][2], maxY = rectangles[0][3];
        Map<Point, Integer> cnt = new HashMap<Point, Integer>();
        for (int[] rect : rectangles) {
            int x = rect[0], y = rect[1], a = rect[2], b = rect[3];
            area += (long) (a - x) * (b - y);

            minX = Math.min(minX, x);
            minY = Math.min(minY, y);
            maxX = Math.max(maxX, a);
            maxY = Math.max(maxY, b);

            Point point1 = new Point(x, y);
            Point point2 = new Point(x, b);
            Point point3 = new Point(a, y);
            Point point4 = new Point(a, b);

            cnt.put(point1, cnt.getOrDefault(point1, 0) + 1);
            cnt.put(point2, cnt.getOrDefault(point2, 0) + 1);
            cnt.put(point3, cnt.getOrDefault(point3, 0) + 1);
            cnt.put(point4, cnt.getOrDefault(point4, 0) + 1);
        }

        Point pointMinMin = new Point(minX, minY);
        Point pointMinMax = new Point(minX, maxY);
        Point pointMaxMin = new Point(maxX, minY);
        Point pointMaxMax = new Point(maxX, maxY);
        if (area != (long) (maxX - minX) * (maxY - minY) || cnt.getOrDefault(pointMinMin, 0) != 1 || cnt.getOrDefault(pointMinMax, 0) != 1 || cnt.getOrDefault(pointMaxMin, 0) != 1 || cnt.getOrDefault(pointMaxMax, 0) != 1) {
            return false;
        }

        cnt.remove(pointMinMin);
        cnt.remove(pointMinMax);
        cnt.remove(pointMaxMin);
        cnt.remove(pointMaxMax);

        for (Map.Entry<Point, Integer> entry : cnt.entrySet()) {
            int value = entry.getValue();
            if (value != 2 && value != 4) {
                return false;
            }
        }
        return true;
    }
}

class Point {
    int x;
    int y;

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    @Override
    public int hashCode() {
        return x + y;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Point) {
            Point point2 = (Point) obj;
            return this.x == point2.x && this.y == point2.y;
        }
        return false;
    }
}
```

格林公式：[参考](https://leetcode.cn/problems/perfect-rectangle/solution/ge-lin-gong-shi-shuang-chao-100-by-aijk-h7x6/)



##### 403\.青蛙过河

[题目](https://leetcode.cn/problems/frog-jump/)

截止 2023/2/20，时间 98%(11ms)，空间 94%(43.8MB)

记忆化搜索，每个点以 $k$ 记忆化。显然每个点最多有 $k$ 个记忆化状态，所以复杂度最坏为 $O(n^2)$。因为显然有很多状态用不上，考虑用 set 常数优化。

```java
class Solution {
    private int n, s[];
    private HashSet<Integer> vis[];
    private HashMap<Integer, Integer> h;

    private void dfs(int v, int k) {
        Integer i = h.get(v);
        if (i == null) {
            return;
        }
        if (vis[i].contains(k) || vis[n - 1].size() > 0 || k < 0) {
            return;
        }
        vis[i].add(k);
        dfs(v + k, k);
        dfs(v + k - 1, k - 1);
        dfs(v + k + 1, k + 1);
    }

    @SuppressWarnings("unchecked")
    public boolean canCross(int[] stones) {
        n = stones.length;
        s = stones;
        vis = new HashSet[n];
        h = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            vis[i] = new HashSet<>();
            h.put(s[i], i);
        }
        dfs(0, 0);
        return vis[n - 1].size() > 0;
    }
}
```



##### 407\.接雨水II

[题目](https://leetcode.cn/problems/trapping-rain-water-ii/)

BFS：$O(n^2m^2)$。

```java
class Solution {
    public int trapRainWater(int[][] heightMap) {
        int m = heightMap.length;
        int n = heightMap[0].length;
        int[] dirs = {-1, 0, 1, 0, -1}; //[:4]dx [1:]dy
        int maxHeight = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                maxHeight = Math.max(maxHeight, heightMap[i][j]);
            }
        }
        int[][] water = new int[m][n];
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j){
                water[i][j] = maxHeight;      
            }
        }  
        Queue<int[]> qu = new LinkedList<>();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) { //最外围一圈
                    if (water[i][j] > heightMap[i][j]) {
                        water[i][j] = heightMap[i][j];
                        qu.offer(new int[]{i, j});
                    } //这一格可以倒水进去
                }
            }
        } 
        while (!qu.isEmpty()) {
            int[] curr = qu.poll();
            int x = curr[0];
            int y = curr[1];
            for (int i = 0; i < 4; ++i) {
                int nx = x + dirs[i], ny = y + dirs[i + 1]; //非常巧妙的方向枚举
                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }
                //如果不合理(nx,ny的水会往当前地方流失)，就流走
                if (water[x][y] < water[nx][ny] && water[nx][ny] > heightMap[nx][ny]) {
                    water[nx][ny] = Math.max(water[x][y], heightMap[nx][ny]);
                    qu.offer(new int[]{nx, ny});
                }//溯源，当前不合理可能还有其他不合理
            }
        }

        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res += water[i][j] - heightMap[i][j];
            }
        }
        return res;
    }
}
```

更优的实现，小根堆优化：$O(nm\log(nm))$。

```java
class Solution {
    public int trapRainWater(int[][] heightMap) {
        if (heightMap.length <= 2 || heightMap[0].length <= 2) {
            return 0;
        }
        int m = heightMap.length;
        int n = heightMap[0].length;
        boolean[][] visit = new boolean[m][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]); //小根堆

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    pq.offer(new int[]{i * n + j, heightMap[i][j]}); //从这里开始最高能装多少水
                    visit[i][j] = true;
                }
            }
        }
        int res = 0;
        int[] dirs = {-1, 0, 1, 0, -1};
        while (!pq.isEmpty()) {
            int[] curr = pq.poll();
            for (int k = 0; k < 4; ++k) {
                int nx = curr[0] / n + dirs[k];
                int ny = curr[0] % n + dirs[k + 1];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visit[nx][ny]) {
                    if (curr[1] > heightMap[nx][ny]) {
                        res += curr[1] - heightMap[nx][ny];
                    }
                    pq.offer(new int[]{nx * n + ny, Math.max(heightMap[nx][ny], curr[1])}); //如果更高还能继续蓄水
                    visit[nx][ny] = true;
                }
            }
        }
        return res;
    }
}
```



##### 1626\.无矛盾的最佳球队

[题目](https://leetcode.cn/problems/split-array-largest-sum/)

将原数组看成结构体 $(score, age)$，然后按 $age$ 排序。排序后，转化为最大和不下降子序列问题，用 DP。之后设 $dp_i$ 表示只考虑排序后前 $i$ 个队员组队的最大分数， 则答案为 $\max dp$。转移方程是，枚举前面所有人的 $dp$，如果 score 不大于自己，就可以更新为 $dp_i=score_i+dp_j$。

复杂度为 $O(n^2)$。

```rust
impl Solution {
    pub fn best_team_score(scores: Vec<i32>, ages: Vec<i32>) -> i32 {
        let n = scores.len();
        let mut pr: Vec<(i32, i32)> = scores
        .iter()
        .zip(ages.iter())
        .map(|(&a, &b)| (a, b))
        .collect();
        use std::cmp::Ordering;
        pr.sort_by(|a, b| {
            let cmp = a.1.cmp(&b.1);
            if cmp == Ordering::Equal {
                a.0.cmp(&b.0)
            } else {
                cmp
            }
        });
        let mut dp = vec![0; n];
        let mut ans = 0;
        for i in 0..n {
            let mut mx = 0;
            for j in 0..i {
                if pr[j].0 <= pr[i].0 {
                    mx = mx.max(dp[j]);
                }
            }
            dp[i] = mx + pr[i].0;
            ans = ans.max(dp[i]);
        }
        ans
    }
}
```

对区间求 max，可以用树状数组优化，此处略，则 $O(n\log n)$。

> 假算法：所有同 age 合并在桶里，然后类似 DP，不用排序。样例就过不去了。



##### 410\.分割数组的最大值

[题目](https://leetcode.cn/problems/split-array-largest-sum/)

对二分答案的题解进行补充解释。

注意到一个事实，设约定子数组最大值不超过 $cf$，然后贪心地取每个子数组的长度使其尽可能的长，此时能够得到最小的区间数 $m'$。如果 $m' \le m$，那么一定可以拆分其中的若干个子数组，使其满足 $m'=m$，所以只要贪心找 $m'$ 发现 $m' > m$，无论如何不满足，只需 $lf=cf+1$ 调整左边界，以调整最大值大小。否则，一定满足题意，考虑找更小的答案。

注意到显然 $rf=\sum nums$，且最坏情况下每个元素成子数组，有 $lf=\max nums$。在 $m\le n$ 的情况下，一定能在最坏情况更新至少一次 $ans$。

复杂度为 $O(n\log\max a)$。

```rust
impl Solution {
    pub fn split_array(nums: Vec<i32>, k: i32) -> i32 {
        let mut lf = *nums.iter().max().unwrap();
        let mut rf = nums.iter().sum();
        let mut ans = std::i32::MAX;
        while lf <= rf {
            let cf = lf + (rf - lf) / 2;
            let mut cnt = 1;
            let mut sum = 0;
            for i in 0..nums.len() {
                if sum + nums[i] > cf {
                    sum = nums[i];
                    cnt += 1;
                } else {
                    sum += nums[i];
                }
            }
            if cnt > k {
                lf = cf + 1;
            } else {
                ans = ans.min(cf);
                rf = cf - 1;
            }
        }
        ans
    }
}
```

DP 解法：设 $dp_{i,j}$ 表示前 $i$ 个数分成 $j$ 段得到的答案，即求 $dp_{n,m}$。递推方程为：
$$
dp_{i,j}=\min_{k=0}^{i-1}\max(dp_{k,j-1},\sum_{l=k+1}^ia_l)
$$
也就是说将 $[k+1,i]$ 分成一个子数组，然后剩余部分 $[1,k]$ 分成 $j-1$ 个子数组。用前缀和优化，复杂度为 $O(n^2m)=O(n^3)$。

```java
class Solution {
    public int splitArray(int[] nums, int m) {
        int n = nums.length;
        int[][] f = new int[n + 1][m + 1];
        for (int i = 0; i <= n; i++) {
            Arrays.fill(f[i], Integer.MAX_VALUE);
        }
        int[] sub = new int[n + 1];
        for (int i = 0; i < n; i++) {
            sub[i + 1] = sub[i] + nums[i];
        }
        f[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= Math.min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    f[i][j] = Math.min(f[i][j], Math.max(f[k][j - 1], sub[i] - sub[k]));
                }
            }
        }
        return f[n][m];
    }
}
```



##### 1630\.等差子数组

[题目](https://leetcode.cn/problems/arithmetic-subarrays/)

可以暴力 sort 验证：

```rust
impl Solution {
    pub fn check_arithmetic_subarrays(nums: Vec<i32>, l: Vec<i32>, r: Vec<i32>) -> Vec<bool> {
        let n = nums.len();
        let m = l.len();
        let mut ans = vec![false; m]; //not n
        for i in 0..m {
            let li = l[i] as usize; //强转
            let ri = r[i] as usize;
            let mut a = nums[li..=ri].to_vec();//切片返回迭代器转vec
            a.sort();
            let mut ok = true;
            let d = a[1] - a[0];
            for j in 2..a.len() {
                if a[j] - a[j - 1] != d {
                    ok = false;
                    break; //剪
                }
            }
            ans[i] = ok;
        }
        ans
    }
}
```

优化：先找到 $[l,r]$ 内最小值 $mi$、最大值 $mx$(可以 ST 表优化)，如果不能被 $r-l$ 整除，就没有公差。否则，直接求出 $d=\dfrac{mx-mi}{r-l}$，然后对每个数 $v$，判断 $v-mi$ 是否是 $d$ 的倍数，并且快速求出当前 $v$ 是第几项即 $i=\dfrac{v-mi}{d}$，必须保证项不重，例如 `1 2 2 3` 不是等差。可以用桶来实现。复杂度为 $O(r-l)=O(m)$。故总复杂度为 $O(nm)$。

```java
class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int n = l.length;
        List<Boolean> ans = new ArrayList<Boolean>();
        for (int i = 0; i < n; ++i) {
            int left = l[i], right = r[i];
            int minv = nums[left], maxv = nums[left];
            for (int j = left + 1; j <= right; ++j) {
                minv = Math.min(minv, nums[j]);
                maxv = Math.max(maxv, nums[j]);
            }

            if (minv == maxv) {
                ans.add(true);
                continue;
            }
            if ((maxv - minv) % (right - left) != 0) {
                ans.add(false);
                continue;
            }

            int d = (maxv - minv) / (right - left);
            boolean flag = true;
            boolean[] seen = new boolean[right - left + 1];
            for (int j = left; j <= right; ++j) {
                if ((nums[j] - minv) % d != 0) {
                    flag = false;
                    break;
                }
                int t = (nums[j] - minv) / d;
                if (seen[t]) {
                    flag = false;
                    break;
                }
                seen[t] = true;
            }
            ans.add(flag);
        }
        return ans;
    }
}
```



##### 420\.强密码检测器

[题目](https://leetcode.cn/problems/strong-password-checker/)

对小于 $6$ 个字符时，易知只有添加字符有意义，设长为 $n$，种类为 $m$，最多添加 $\max(6-n,3-m)$ 个字符。

对在 $[6,20]$ 个字符时，只有修改一个字符有意义，对连续 $k$ 个相同，替换掉 $\sum\lfloor\dfrac k3\rfloor$ 个。

对大于 $20$ 个字符时，需要修改或删除。考虑全 `a`，显然又要删又要改。

- 若 $k\bmod 3=0$，则删除一个字符后，$\lfloor\dfrac k3\rfloor$ 马上减一
- 若 $k\bmod 3=1$，删除两个字符后才能减一
- 若 $k\bmod 3=2$，删除三个字符后才能减一

因此，要删时，优先从 $k\bmod 3=0$ 删，然后从 $=1$ 删，最后从 $=2$ 删。对 $k=1$ 考虑到删了之后可能会造成新的 $k\ge 3$，如 `aabaa` 的 `b`，所以合法时，优先删除 $k=2$。删到余 $20$ 时，再考虑修改。

一天速成 rust 语言的自己的极其繁琐的实现代码：

```rust
mod lc420s {
    fn insert(str_slice: &str, idx: usize, ch: char) -> String {
        let mut new_str = String::with_capacity(str_slice.len() + 1);
        new_str.push_str(&str_slice[..idx]);
        new_str.push(ch);
        new_str.push_str(&str_slice[idx..]);
        new_str
    }
    fn get_index_ranges(input: &str) -> Vec<[usize; 2]> {
        let mut ranges = vec![];
        let mut start = 0;
        let mut end = 0;
        for (i, c) in input.char_indices() {
            if i > 0 && c != input.chars().nth(i - 1).unwrap() {
                ranges.push([start, end]);
                start = i;
            }
            end = i;
        }
        ranges.push([start, end]);
        ranges
    }
    fn remove(s: &str, index: usize) -> String {
        let mut chars: Vec<char> = s.chars().collect();
        chars.remove(index);
        chars.iter().collect()
    }
    fn get_bin(v: &Vec<[usize; 2]>) -> [Vec<usize>; 6] {
        let mut arr: [Vec<usize>; 6] = Default::default();
        for i in 0..v.len() {
            let len = v[i][1] - v[i][0] + 1;
            if len <= 2 {
                arr[len].push(i);
            } else {
                arr[len % 3 + 3].push(i);
            }
        }
        arr
    }
    fn get_mid(rng: &[usize; 2]) -> usize {
        (rng[0] + rng[1] + 1) / 2
    }
    fn get_len(rng: &[usize; 2]) -> usize {
        rng[1] - rng[0] + 1
    }

    pub struct Solution {
        has_lower: bool,
        has_upper: bool,
        has_digit: bool,
        psw: String,
        n: usize,
        res: i32,
    }
    impl Solution {
        pub fn new(password: &str) -> Self {
            let has_lower = password.chars().any(|c| c.is_ascii_lowercase());
            let has_upper = password.chars().any(|c| c.is_ascii_uppercase());
            let has_digit = password.chars().any(|c| c.is_ascii_digit());
            Solution {
                has_lower,
                has_upper,
                has_digit,
                psw: String::from(password),
                n: password.len(),
                res: 0,
            }
        }
        fn insert_any(&mut self, idx: usize) {
            let mut prv = '_';
            if idx > 0 {
                prv = self.psw.chars().nth(idx - 1).unwrap();
            }
            let mut nxt = '_';
            if idx < self.psw.len() {
                nxt = self.psw.chars().nth(idx).unwrap();
            }
            if !self.has_lower {
                self.has_lower = true;
                if prv != 'a' && nxt != 'a' {
                    self.psw = insert(&self.psw, idx, 'a')
                } else if prv != 'b' && nxt != 'b' {
                    self.psw = insert(&self.psw, idx, 'b')
                } else {
                    self.psw = insert(&self.psw, idx, 'c')
                }
            } else if !self.has_upper {
                self.has_upper = true;
                if prv != 'A' && nxt != 'A' {
                    self.psw = insert(&self.psw, idx, 'A')
                } else if prv != 'B' && nxt != 'B' {
                    self.psw = insert(&self.psw, idx, 'B')
                } else {
                    self.psw = insert(&self.psw, idx, 'C')
                }
            } else {
                self.has_digit = true;
                if prv != '0' && nxt != '0' {
                    self.psw = insert(&self.psw, idx, '0')
                } else if prv != '1' && nxt != '1' {
                    self.psw = insert(&self.psw, idx, '1')
                } else {
                    self.psw = insert(&self.psw, idx, '2')
                }
            }
            self.n += 1;
            self.res += 1;
        }
        fn remove(&mut self, idx: usize) {
            self.psw = remove(&self.psw, idx);
            self.n -= 1;
            self.res += 1;
        }
        fn remove_any(&mut self) {
            let rng = get_index_ranges(&self.psw);
            let bin = get_bin(&rng);
            let order = vec![3, 4, 5, 2, 1];
            for j in 0..order.len() {
                let i = order[j];
                if bin[i].len() > 0 {
                    self.remove(get_mid(&rng[bin[i][0]]));
                    break;
                }
            }
            // if bin[3].len() > 0 {
            //     self.remove(get_mid(&rng[bin[3][0]]));
            // } else if bin[4].len() > 0 {
            //     self.remove(get_mid(&rng[bin[4][0]]));
            // } else if bin[5].len() > 0 {
            //     self.remove(get_mid(&rng[bin[5][0]]));
            // } else if bin[2].len() > 0 {
            //     self.remove(get_mid(&rng[bin[2][0]]));
            // } else {
            //     self.remove(get_mid(&rng[bin[1][0]]));
            // }
        }
        fn update_any(&mut self, idx: usize) {
            self.insert_any(idx);
            self.remove(idx + 1);
            self.res -= 1;
        }
        fn update_cnt(&mut self, rng: &[usize; 2]) {
            let mut l = rng[0] + 2;
            let r = rng[1];
            while l <= r {
                self.update_any(l);
                l += 3;
            }
        }
        pub fn strong_password_checker(password: String) -> i32 {
            let mut sol = Solution::new(&password);
            if sol.n < 6 {
                let rng = get_index_ranges(&sol.psw);
                for i in 0..rng.len() {
                    if get_len(&rng[i]) >= 3 {
                        sol.insert_any(get_mid(&rng[i]));
                    }
                }
                while sol.n < 6 {
                    sol.insert_any(0);
                }
            }
            while sol.n > 20 {
                sol.remove_any();
            }
            loop {
                let rng = get_index_ranges(&sol.psw);
                let bin = get_bin(&rng);
                let order = vec![3, 4, 5];
                let mut fix = false;
                for j in 0..order.len() {
                    let i = order[j];
                    for k in 0..bin[i].len() {
                        sol.update_cnt(&rng[bin[i][k]]);
                        fix = true;
                    }
                    // if bin[i].len() > 0 {
                    // bin[i].sort_by(|&x, &y| rng[x][0].cmp(&rng[y][0]));
                    // println!("mid {}",get_mid(&rng[bin[i][0]]));
                    // sol.update_any(get_mid(&rng[bin[i][0]]));
                    // }
                }
                if !fix {
                    break;
                }
            }
            while !sol.has_digit || !sol.has_lower || !sol.has_upper {
                sol.insert_any(0);
            }
            //println!("psw = {}", sol.psw);
            sol.res
        }
    }
}
impl Solution {
    pub fn strong_password_checker(password: String) -> i32 {
        lc420s::Solution::strong_password_checker(password)
    }
}
```

题解的优雅的实现：(不做真的修改，只统计修改次数)

```java
class Solution {
    public int strongPasswordChecker(String password) {
        int n = password.length();
        int hasLower = 0, hasUpper = 0, hasDigit = 0;
        for (int i = 0; i < n; ++i) {
            char ch = password.charAt(i);
            if (Character.isLowerCase(ch)) {
                hasLower = 1;
            } else if (Character.isUpperCase(ch)) {
                hasUpper = 1;
            } else if (Character.isDigit(ch)) {
                hasDigit = 1;
            }
        }
        int categories = hasLower + hasUpper + hasDigit;

        if (n < 6) {
            return Math.max(6 - n, 3 - categories);
        } else if (n <= 20) {
            int replace = 0;
            int cnt = 0;
            char cur = '#';

            for (int i = 0; i < n; ++i) {
                char ch = password.charAt(i);
                if (ch == cur) {
                    ++cnt;
                } else {
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            replace += cnt / 3;
            return Math.max(replace, 3 - categories);
        } else {
            // 替换次数和删除次数
            int replace = 0, remove = n - 20;
            // k mod 3 = 1 的组数，即删除 2 个字符可以减少 1 次替换操作
            int rm2 = 0;
            int cnt = 0;
            char cur = '#';

            for (int i = 0; i < n; ++i) {
                char ch = password.charAt(i);
                if (ch == cur) {
                    ++cnt;
                } else {
                    if (remove > 0 && cnt >= 3) {
                        if (cnt % 3 == 0) {
                            // 如果是 k % 3 = 0 的组，那么优先删除 1 个字符，减少 1 次替换操作
                            --remove;
                            --replace;
                        } else if (cnt % 3 == 1) {
                            // 如果是 k % 3 = 1 的组，那么存下来备用
                            ++rm2;
                        }
                        // k % 3 = 2 的组无需显式考虑
                    }
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            if (remove > 0 && cnt >= 3) {
                if (cnt % 3 == 0) {
                    --remove;
                    --replace;
                } else if (cnt % 3 == 1) {
                    ++rm2;
                }
            }
            replace += cnt / 3;

            // 使用 k % 3 = 1 的组的数量，由剩余的替换次数、组数和剩余的删除次数共同决定
            int use2 = Math.min(Math.min(replace, rm2), remove / 2);
            replace -= use2;
            remove -= use2 * 2;
            // 由于每有一次替换次数就一定有 3 个连续相同的字符（k / 3 决定），因此这里可以直接计算出使用 k % 3 = 2 的组的数量
            int use3 = Math.min(replace, remove / 3);
            replace -= use3;
            remove -= use3 * 3;
            return (n - 20) + Math.max(replace, 3 - categories);
        }
    }
}
```



##### 1032\.字符流

[题目](https://leetcode.cn/problems/stream-of-characters/)

rust 战绩(截止2023-3-24 15:00) 160ms(击败100%) 20MB(击败100%)

凭借 acm 的经验一眼 ACAM，但是我太蒟蒻了不知道怎么多次匹配。所以直接无脑哈希了：

维护字符串哈希 $h$ 及幂数组 $p_i=37^i$。则可以计算任意子串哈希为 $h_r-h_{l-1}37^{r-l+1}$。枚举全体 words，得到子串是 $[n-|words_i|+1,n]$ 范围，直接计算哈希，并与 $words_i$ 预处理的哈希进行比较。设 $m$ 是 $words$ 个数，理论上每次查询的复杂度是 $O(m)$，有 $q$ 次询问则总复杂度为 $O(mq)=O(200\times 4\times 10^4)=8\times 10^6$。

考虑进行阴湿的剪枝卡常，将 $words$ 按最后一个字符拆分为 $26$ 组，每次只遍历与 $letter$ 相同的那一组，如果数据随机，理论上可以优化提速 $26$ 倍。如果更阴湿一点，可以结合  trie，在 trie 上走一半然后再对 $words$ 里满足这一半后缀的全体进行遍历。这里懒没这么做了。

> 不考虑只使用 trie，因为可以被卡到复杂度为 $O(q\max |words_i|)=8\times 10^7$。

```rust
const P: usize = 37;
const DT: usize = 'a' as usize;
fn hash(s: &str) -> usize {
    let mut h = 0 as usize;
    for i in 0..s.len() {
        h = h.wrapping_mul(P);
        h = h.wrapping_add(s.chars().nth(i).unwrap() as usize - DT);
    }
    h
}

struct StreamChecker {
    s: [Vec<usize>; 26],
    len: [Vec<usize>; 26],
    h: Vec<usize>,
    p: Vec<usize>,
}

impl StreamChecker {
    fn new(words: Vec<String>) -> Self {
        let mut s: [Vec<usize>; 26] = Default::default();
        let mut len: [Vec<usize>; 26] = Default::default();
        for i in 0..words.len() {
            let ch = words[i].chars().nth(words[i].len() - 1).unwrap();
            let lch = ch as usize - DT;
            s[lch].push(hash(&words[i]));
            len[lch].push(words[i].len());
        }
        let h: Vec<usize> = vec![0];
        let p: Vec<usize> = vec![1];
        StreamChecker { s, len, h, p }
    }

    fn hash(&self, l: usize, r: usize) -> usize {
        let n = r - l + 1;
        self.h[r].wrapping_sub(self.h[l - 1].wrapping_mul(self.p[n]))
    }

    fn query(&mut self, letter: char) -> bool {
        let newh = self.h[self.h.len() - 1]
            .wrapping_mul(P)
            .wrapping_add(letter as usize - DT);
        self.h.push(newh);
        let newp = self.p[self.p.len() - 1].wrapping_mul(P);
        self.p.push(newp);
        let j = letter as usize - DT;
        let r = self.p.len() - 1;
        for i in 0..self.len[j].len() {
            if self.len[j][i] > r {
                continue;
            }
            let l = r - self.len[j][i] + 1;
            if self.hash(l, r) == self.s[j][i] {
                return true;
            }
        }
        false
    }
}

fn main() {
    let s = vec![String::from("cd"), String::from("f"), String::from("kl")];
    let mut sol = StreamChecker::new(s);
    println!("{}", sol.query('d'));
    for ch in 'a'..='l' {
        println!("{}", sol.query(ch));
    }
}
```

题解：ACAM。对普通的 ACAM，做如下变动。初始每个 trie 终点节点标记。在处理 BFS 时，每次把当前节点是否是终点与它的失配指针指向的节点是否是终点或起来。然后每次匹配时不跑失配，直接继续往下走。说实话还是不太懂，暂时放弃了。

```c++
typedef struct TrieNode {
    vector<TrieNode *> children;
    bool isEnd;
    TrieNode *fail;
    TrieNode() {
        this->children = vector<TrieNode *>(26, nullptr);
        this->isEnd = false;
        this->fail = nullptr;
    }
};

class StreamChecker {
public:
    TrieNode *root;
    TrieNode *temp;
    StreamChecker(vector<string>& words) {
        root = new TrieNode();
        for (string &word : words) {
            TrieNode *cur = root;
            for (int i = 0; i < word.size(); i++) {
                int index = word[i] - 'a';
                if (cur->children[index] == nullptr) {
                    cur->children[index] = new TrieNode();
                }
                cur = cur->children[index];
            }
            cur->isEnd = true;
        }
        root->fail = root;
        queue<TrieNode *> q;
        for (int i = 0; i < 26; i++) {
            if(root->children[i] != nullptr) {
                root->children[i]->fail = root;
                q.emplace(root->children[i]);
            } else {
                root->children[i] = root;
            }
        }
        while (!q.empty()) {
            TrieNode *node = q.front();
            q.pop();
            node->isEnd = node->isEnd || node->fail->isEnd;//核心
            for (int i = 0; i < 26; i++) {
                if(node->children[i] != nullptr) {
                    node->children[i]->fail = node->fail->children[i];
                    q.emplace(node->children[i]);
                } else {
                    node->children[i] = node->fail->children[i];
                }
            }
        }

        temp = root;
    }
    
    bool query(char letter) {
        temp = temp->children[letter - 'a'];
        return temp->isEnd;
    }
};
```



##### 1574\.删除最短的子数组使剩余数组有序

[题目](https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/)

> 截止 2023-3-25 13:20 rust 12ms(100%击败)，3.7MB(1005击败)

扫一遍求出最长单调前缀下标为 $[0,incf]$ 和最长单调后缀下标 $[incb,n)$。如果 $incb\le incf$，则整体单调，不用删。否则，枚举 $[0,incf]$ 的每个数 $x$，在 $[incb,n)$ 内二分找到最前的 $\ge x$ 的数的下标，将这两段拼起来。复杂度 $O(n\log n)$。

```rust
fn lower_bound(v: &Vec<i32>, x: i32) -> usize {
    v.partition_point(|&y| y < x)
}
impl Solution {
    pub fn find_length_of_shortest_subarray(arr: Vec<i32>) -> i32 {
        let mut incf = 0; //单调前缀[0,inc]
        let mut incb = arr.len() - 1; //单调后缀 [incb,n)
        for i in 1..arr.len() {
            if arr[i] >= arr[i - 1] {
                incf += 1;
            } else {
                break;
            }
        }
        for i in (0..(arr.len() - 1)).rev() {
            if arr[i] <= arr[i + 1] {
                incb -= 1;
            } else {
                break;
            }
        }
        if incb <= incf {
            return 0;
        }
        let a = arr[incb..].to_vec();
        // println!("{} {} {:?}", incf, incb, a);
        let mut ans = arr.len() - 1 - incf;
        ans = ans.min(incb);
        for i in 0..=incf {
            let j = lower_bound(&a, arr[i]);
            // println!("{} {} {}", j, arr[i], incb + j - i - 1);
            ans = ans.min(incb + j - i - 1);
        }
        ans as i32
    }
}
```

双指针：$O(n)$

```java
class Solution {
    public int findLengthOfShortestSubarray(int[] arr) {
        int n = arr.length, j = n - 1;
        while (j > 0 && arr[j - 1] <= arr[j]) {
            j--;
        } //单调递增后缀 [j,n)
        if (j == 0) {
            return 0;
        }
        int res = j;
        for (int i = 0; i < n; i++) { //枚举单调递增前缀
            while (j < n && arr[j] < arr[i]) {
                j++;
            } //满足a[i]<=a[j]
            res = Math.min(res, j - i - 1);
            if (i + 1 < n && arr[i] > arr[i + 1]) {
                break;
            }
        }
        return res;
    }
}
```



##### 432\.全O(1)的数据结构

[题目](https://leetcode.cn/problems/all-oone-data-structure/)

每个字符串用 map 记录出现次数，同出现次数的字符串全部丢到一个 set 里，所有 set 用链表存起来，min max 就是头尾节点

```java
class AllOne {
    Node root;
    Map<String, Node> nodes;

    public AllOne() {
        root = new Node();
        root.prev = root;
        root.next = root;  // 初始化链表哨兵，下面判断节点的 next 若为 root，则表示 next 为空（prev 同理）
        nodes = new HashMap<String, Node>();
    }
    
    public void inc(String key) {
        if (nodes.containsKey(key)) {
            Node cur = nodes.get(key);
            Node nxt = cur.next;
            if (nxt == root || nxt.count > cur.count + 1) {
                nodes.put(key, cur.insert(new Node(key, cur.count + 1)));
            } else {
                nxt.keys.add(key);
                nodes.put(key, nxt);
            }
            cur.keys.remove(key);
            if (cur.keys.isEmpty()) {
                cur.remove();
            }
        } else {  // key 不在链表中
            if (root.next == root || root.next.count > 1) {
                nodes.put(key, root.insert(new Node(key, 1)));
            } else {
                root.next.keys.add(key);
                nodes.put(key, root.next);
            }
        }
    }
    
    public void dec(String key) {
        Node cur = nodes.get(key);
        if (cur.count == 1) {  // key 仅出现一次，将其移出 nodes
            nodes.remove(key);
        } else {
            Node pre = cur.prev;
            if (pre == root || pre.count < cur.count - 1) {
                nodes.put(key, cur.prev.insert(new Node(key, cur.count - 1)));
            } else {
                pre.keys.add(key);
                nodes.put(key, pre);
            }
        }
        cur.keys.remove(key);
        if (cur.keys.isEmpty()) {
            cur.remove();
        }
    }
    
    public String getMaxKey() {
        return root.prev != null ? root.prev.keys.iterator().next() : "";
    }
    
    public String getMinKey() {
        return root.next != null ? root.next.keys.iterator().next() : "";
    }
}

class Node {
    Node prev;
    Node next;
    Set<String> keys;
    int count;

    public Node() {
        this("", 0);
    }

    public Node(String key, int count) {
        this.count = count;
        keys = new HashSet<String>();
        keys.add(key);
    }

    public Node insert(Node node) {  // 在 this 后插入 node
        node.prev = this;
        node.next = this.next;
        node.prev.next = node;
        node.next.prev = node;
        return node;
    }

    public void remove() {
        this.prev.next = this.next;
        this.next.prev = this.prev;
    }
}
```

如果不用链表，用数组，每次发生变动都要 $O(n)$ 才能更新 min, max，容易被卡 $O(n^2)$，反面例子：

> ```rust
> use std::collections::HashMap;
> use std::collections::HashSet;
> struct AllOne {
>     n: usize, //bin的下标是[0,n]
>     mx: usize,
>     mi: usize,
>     bin: Vec<HashSet<String>>,
>     h: HashMap<String, usize>,
> }
> 
> /**
>  * `&self` means the method takes an immutable reference.
>  * If you need a mutable reference, change it to `&mut self` instead.
>  */
> impl AllOne {
>     fn new() -> Self {
>         let mut bin: Vec<HashSet<String>> = vec![];
>         bin.push(HashSet::new());
>         bin[0].insert(String::from(""));
>         let mut h: HashMap<String, usize> = HashMap::new();
>         h.entry(String::from("")).or_insert(0);
>         AllOne {
>             n: 0,
>             mx: 0,
>             mi: 0,
>             bin,
>             h,
>         }
>     }
> 
>     fn update_mi_mx(&mut self, v: usize, t: usize) {
>         if self.bin[v].len() == t {
>             self.mx = 0;
>             self.mi = 0;
>             for i in 1..self.bin.len() {
>                 if self.bin[i].len() > 0 {
>                     self.mx = i;
>                     if self.mi == 0 {
>                         self.mi = i;
>                     }
>                 }
>             }
>         }
>     }
> 
>     fn inc(&mut self, key: String) {
>         let mut cnt = *self.h.entry(key.clone()).or_insert(0);
>         self.bin[cnt].remove(&key); //根据有无返回boolean
>         cnt += 1;
>         self.mx = self.mx.max(cnt);
>         if self.mx > self.n {
>             self.n += 1;
>             self.bin.push(HashSet::new());
>         } // self.bin.resize_with(self.mx + 1, HashSet::new);
>           // if self.mi == 0 {
>           //     self.mi = cnt;
>           // }
>         self.bin[cnt].insert(key.clone());
>         *self.h.get_mut(&key).unwrap() = cnt;
>         // println!("ti {} {}", cnt , self.bin[cnt].len());
>         self.update_mi_mx(cnt - 1, 0);
>         self.update_mi_mx(cnt, 1);
>         // println!("incd {} {}", self.mi, self.mx);
>     }
> 
>     fn dec(&mut self, key: String) {
>         let mut cnt = *self.h.get_mut(&key).unwrap();
>         self.bin[cnt].remove(&key);
>         // println!("td {} {}", cnt , self.bin[cnt].len());
>         if cnt == 1 {
>             self.h.remove(&key);
>             self.update_mi_mx(cnt, 0);
>         } else {
>             cnt -= 1;
>             *self.h.get_mut(&key).unwrap() = cnt;
>             self.bin[cnt].insert(key.clone());
>             self.update_mi_mx(cnt + 1, 0);
>         }
>         // println!("deld {} {}", self.mi, self.mx);
>     }
> 
>     fn get_max_key(&self) -> String {
>         self.bin[self.mx].iter().next().unwrap().clone()
>     }
> 
>     fn get_min_key(&self) -> String {
>         self.bin[self.mi].iter().next().unwrap().clone()
>     }
> }
> ```



##### 1638. 统计只差一个字符的子串数目

[题目](https://leetcode.cn/problems/count-substrings-that-differ-by-one-character/)

穷凶极恶的字符串哈希暴力。设 $n=\max(|s|,|t|)$。

对同长字符串 $a,b$，只有一个字符不同，意味着枚举不同位置，其前缀后缀分别相同。可以用字符串哈希，需要 $O(n)$ 来枚举不同位置。但是直接枚举 $s$ 的所有子串，再直接枚举 $t$ 的所有子串，再判断是否严格只差一个字符相同的复杂度为 $O(n^5)$，不可行，考虑优化掉一次枚举。

考虑枚举 $t$ 的所有子串，对每个子串 $b$，枚举删掉一个字符后得到的前后缀 $(b_p,b_s)$，计算其字符串哈希(考虑空串冲突，字符值转化后不能为 $0$)。将所有二元哈希值 $(h(b_p),h(b_s))$ (注意不能将两个哈希值并成一个哈希值，如 $h(b_p)C+h(b_s)$，这样会极大地提高哈希冲突率)作为键，所有键相等的子串下标范围 $[l,r]$ 构成不重的值(这里因为不超 int，可以用 $Cl+r$ 压缩二元组为一元) 。也就是说，开一个 hashmap，键是二元哈希值，值是 hashset，set 的每个值是下标范围。这里的复杂度是 $O(n^3)$。

因为如果在这个过程还要考虑中间那个字符串相同不相同，比较复杂。考虑转化问题，即：

- 恰有一个不同的子串数=有一个或零个不同的子串数 - 相同子串数

现在统计有一个或零个不同的子串数。对 $s$，枚举每个子串 $a$ 的删掉一个字符后得到的前后缀 $(a_p,a_s)$，得到二元哈希值，用这个值做键找到 hashset。对 $a$ 能找到的所有 set，进行合并。最坏情况(考虑只由一个字符组成)下每个 set 有 $O(n)$ 个元素，则合并的最坏复杂度是 $O(n^2)$。故总复杂度最坏为 $O(n^4)$。如果字符串比较混乱，平均复杂度 $O(n^3)$。

> 不能用 bitset 优化合并，这是因为 $[l,r]$ 的情况数为 $O(n^2)$，则合并复杂度退化成恒为 $O(\dfrac{n^3}C)$

之后再预处理出 $s,t$ 的每个子串的哈希值，用哈希值作键同理得到 hashmap 套 hashset，然后枚举 $s$ 的每个 hashset，查找 $t$ 里同键的 hashset，则元素数分别为 $cnt_1,cnt_2$，则共有 $cnt_1\times cnt_2$ 个元素哈希值相同，答案里减去即可。这里的复杂度是 $O(n^2)$。

综上，总时间复杂度最坏为 $O(n^4)$，数据弱的话平均为 $O(n^3)$。空间复杂度为 $O(n^3)$。

rust 参考代码：

```rust
const P0: i32 = 31;
const P1: i32 = 10007;
fn fill(s: &String, h: &mut Vec<i32>) {
    for i in 0..s.len() {
        h[i + 1] = h[i]
            .wrapping_mul(P0)
            .wrapping_add(s.chars().nth(i).unwrap() as i32 - 'a' as i32 + 1);
    }
}
fn hash(l: usize, r: usize, h: &Vec<i32>, p: &Vec<i32>) -> i32 {
    if l > r || r >= h.len() || l >= h.len() {
        return 0;
    }
    h[r].wrapping_sub(h[l - 1].wrapping_mul(p[r - l + 1]))
}
use std::collections::{HashMap, HashSet};
type Hmap = HashMap<i32, HashSet<i32>>; //hmap 命名会 warning
type Hmap2 = HashMap<(i32, i32), HashSet<i32>>;
fn pre(h: &Vec<i32>, p: &Vec<i32>) -> Hmap2 {
    let mut m: Hmap2 = HashMap::new();
    for l in 1..h.len() {
        for r in l..h.len() {
            for k in l..=r {
                let hl = hash(l, k - 1, &h, &p);
                let hr = hash(k + 1, r, &h, &p);
                let k2 = (l as i32).wrapping_mul(P1).wrapping_add(r as i32);
                m.entry((hl, hr)).or_insert(HashSet::new()).insert(k2);
            }
        }
    }
    m
}
fn pre2(h: &Vec<i32>, p: &Vec<i32>) -> Hmap {
    let mut m: Hmap = HashMap::new();
    for l in 1..h.len() {
        for r in l..h.len() {
            let h = hash(l, r, &h, &p);
            let k = (l as i32).wrapping_mul(P1).wrapping_add(r as i32);
            m.entry(h).or_insert(HashSet::new()).insert(k);
        }
    }
    m
}
//pub struct Solution {}
impl Solution {
    pub fn count_substrings(s: String, t: String) -> i32 {
        let n = s.len();
        let m = t.len();
        let mn = n.max(m);
        let mut p: Vec<i32> = vec![0; mn + 1]; //长度不确定不能用array
                                               //必须声明类型,不然乘不了
        p[0] = 1;
        for i in 1..=mn {
            p[i] = p[i - 1].wrapping_mul(P0);
        }
        let mut hs = vec![0; n + 1];
        let mut ht = vec![0; m + 1];
        fill(&s, &mut hs);
        fill(&t, &mut ht);
        let mt = pre(&ht, &p);
        let mut ans = 0 as i32;
        for l in 1..hs.len() {
            for r in l..hs.len() {
                let mut bin: HashSet<i32> = HashSet::new();
                for k in l..=r {
                    let hl = hash(l, k - 1, &hs, &p);
                    let hr = hash(k + 1, r, &hs, &p);
                    if mt.contains_key(&(hl, hr)) {
                        let vs = mt.get(&(hl, hr)).unwrap();
                        bin.extend(&*vs);
                    }
                }
                ans += bin.len() as i32;
            }
        }
        let ms2 = pre2(&hs, &p);
        let mt2 = pre2(&ht, &p);
        for (k, vs) in ms2.iter() {
            if !mt2.contains_key(&k) {
                continue;
            }
            let vs2 = mt2.get(&k).unwrap();
            let cnt = vs.len() as i32;
            let cnt2 = vs2.len() as i32;
            ans -= cnt * cnt2;
        }
        ans
    }
}
```

枚举：

```java
class Solution {
    public int countSubstrings(String s, String t) {
        int m = s.length(), n = t.length();
        int ans = 0;
        for (int i = 0; i < m; i++) { //s起始位置
            for (int j = 0; j < n; j++) { //t起始位置
                int diff = 0;
                for (int k = 0; i + k < m && j + k < n; k++) { //len
                    diff += s.charAt(i + k) == t.charAt(j + k) ? 0 : 1;
                    if (diff > 1) {
                        break;
                    } else if (diff == 1) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
}
```

DP：

```java
class Solution {
    public int countSubstrings(String s, String t) {
        int m = s.length(), n = t.length();
        int[][] dpl = new int[m + 1][n + 1]; //s i结束, t j结束相等的最长长度
        int[][] dpr = new int[m + 1][n + 1]; //s i开始, t j开始相等的最长长度
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dpl[i + 1][j + 1] = s.charAt(i) == t.charAt(j) ? (dpl[i][j] + 1) : 0;
            }
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                dpr[i][j] = s.charAt(i) == t.charAt(j) ? (dpr[i + 1][j + 1] + 1) : 0;
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (s.charAt(i) != t.charAt(j)) {
                    ans += (dpl[i][j] + 1) * (dpr[i + 1][j + 1] + 1);
                }
            }
        }
        return ans;
    }
}
```



##### 1092\.最短公共超序列

[题目](https://leetcode.cn/problems/shortest-common-supersequence/)

设 $dp_{i,j}$ 表示 $s[i..n]$ 和 $t[j..m]$ (定义 $n,m$ 为越界下标)作为子序列的最短超字符串长度。

1. 若 $s_i=t_j$，则一定包含该字符，即：$dp_{i,j}=dp_{i+1,j+1}+1$

2. 否则，哪个短要哪个 $dp_{i,j}=\min(dp_{i+1,j},dp_{i,j+1})+1$

   哪边下标 +1 就是用了谁的字符来 +1，因为不等于另一边，所以不能延长另一边

对边界，有 $dp_{n,j}=m-j$，$dp_{i,m}=n-i$，$dp_{n,m}=0$。

```c++
class Solution {
    public String shortestCommonSupersequence(String str1, String str2) {
        int n = str1.length(), m = str2.length();
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 0; i < n; ++i) {
            dp[i][m] = n - i; 
            //如dp[0][m]=n,即s[0..n]自身长度为n
        }
        for (int i = 0; i < m; ++i) {
            dp[n][i] = m - i;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (str1.charAt(i) == str2.charAt(j)) {
                    dp[i][j] = dp[i + 1][j + 1] + 1;
                } else {
                    dp[i][j] = Math.min(dp[i + 1][j], dp[i][j + 1]) + 1;
                }
            }
        }
        StringBuilder res = new StringBuilder();
        int t1 = 0, t2 = 0;
        while (t1 < n && t2 < m) {
            if (str1.charAt(t1) == str2.charAt(t2)) {
                res.append(str1.charAt(t1));
                ++t1;
                ++t2;
            } else if (dp[t1 + 1][t2] == dp[t1][t2] - 1) { //如果当初推导转移时走的是i+1,j
                res.append(str1.charAt(t1));
                ++t1;
            } else if (dp[t1][t2 + 1] == dp[t1][t2] - 1) {
                res.append(str2.charAt(t2));
                ++t2;
            }
        }
        if (t1 < n) {
            res.append(str1.substring(t1));
        } else if (t2 < m) {
            res.append(str2.substring(t2));
        }
        return res.toString();
    }
}
```



##### 1641\.统计字典序元音字符串的数目

[题目](https://leetcode.cn/problems/count-sorted-vowel-strings/)

设 $dp_{i,j}$ 表示长为 $i$ 的以第 $j$ 个元音结尾的答案。则所求为 $\sum_{j=1}^5dp_{n,j}$。

初始状态为 $dp_{1,j}=1$。对 $dp_{i,j}$，所有满足上一个字符不大于 $j$ 的都可以接上 $j$，即 $dp_{i,j}=\sum_{k=1}^jdp_{i-1,k}$。得解，$O(5n)$。

故所求为 $\sum_{j=1}^5dp_{n,j}=dp_{n+1,5}$。

还可以继续优化(看下文)。

朴素 DP：

```rust
impl Solution {
    pub fn count_vowel_strings(n: i32) -> i32 {
        let _n = (n + 1) as usize;
        let mut dp = Vec::with_capacity(_n);
        for _ in 0.._n {
            dp.push(vec![0; 5]);
        }
        for i in 0..5 {
            dp[0][i] = 1;
        }
        for i in 1.._n {
            for j in 0..5 {
                for k in 0..=j {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        dp[_n - 1][4]
    }
}
```

不难发现，$dp_{i,j}$ 的本质是常数数组 $(1,1,\cdots)$ 的 $n$ **阶**前缀和的第 $5$ 个元素。下面拓展并证明如何求该数组的任意阶前缀和的任意元素。转载自我原创的 [我的博客](https://lr580.github.io/2022/11/06/%E6%80%9D%E7%BB%B4-%E6%95%B0%E5%AD%A6%E9%A2%98%E5%8D%95%E9%A2%98%E8%A7%A3/#%E9%AB%98%E9%98%B6%E5%89%8D%E7%BC%80%E5%92%8C)。

设 $a=(1,1,\cdots)$，观察可得，有 $s_{j,i}$ 矩阵(这里设下标行 $j$ 从 $0$ 开始，列 $i$ 从 $0$ 开始)：
$$
s=\begin{pmatrix}
1&1&1&1&\cdots\\
1&2&3&4&\cdots\\
1&3&6&10&\cdots\\
1&4&10&20&\cdots\\
1&5&15&35&\cdots\\
\vdots&\vdots&\vdots&\vdots&\ddots
\end{pmatrix}
$$
抽象为 $s_{j,i}$ 表示从最左上角点 $(0,1)$ 出发，只能往左和往下走，共有多少种方案能走到 $(j,i)$。显然初始值是 $s_{0,1}=1$，且根据加法原理，有：$s_{j,i}=s_{j-1,i}+s_{j,i-1}$，可以发现该组合数学意义与前缀和数组算术等价。即问题暂时转化为问方案数。

显然，从 $(0,1)$ 走到 $(j,i)$ 共需要往下移动 $j$ 次，往左移动 $i-1$ 次，在这所有 $i+j-1$ 次移动里，分 $j$ 次往下，共有 $C_{i+j-1}^j$ 种方案。即：$a=(1,1,\cdots)$ 时，有：$s_{j,i}=C_{i+j-1}^j=C_{i+j-1}^{i-1}$。对于本题，即 $j=n,i=4$，即求 $C_{n+4}^4$。

扩展：下面简要推导如何求任意数组的任意阶前缀和任意元素。

推广到 $a=(a_1,a_2,\cdots, a_n)$，有：
$$
s=\begin{pmatrix}
a_1&a_2&a_3&a_4&\cdots\\
a_1&a_1+a_2&a_1+a_2+a_3&a_1+a_2+a_3+a_4&\cdots\\
a_1&2a_1+a_2&3a_1+2a_2+a_3&4a_1+3a_2+2a_3+a_4&\cdots\\
a_1&3a_1+a_2&6a_1+3a_2+a_3&10a_1+6a_2+3a_3+a_4&\cdots\\
\vdots&\vdots&\vdots&\vdots&\ddots
\end{pmatrix}
$$
换言之，现在抽象成了，可以从任一点 $(0,i)(i\le x)$ 出发，第一步只能往下走且方案数为 $a_i$，在这之后 只能往左和往下走，共有多少种方案能走到 $(j,i)(j\ge 1)$。显然，可以将其拆分为 $x$ 个子问题，即分别从 $(0,1),(0,2),\cdots,(0,x)$ 出发，走到  $(j-1,i)$ 的方案数，将这些方案数用加法原理加起来即可，有：
$$
s_{j+1,i}=\sum_{x=1}^iC_{j+i-x}^{j}a_x(j\ge 1)
$$
作偏移，有：(你扣不支持 `\begin{align}`，所以排版难看)
$$
s_{j+1,i}=\sum_{x=1}^{i}C_{i+j-x}^ja_x\\
=C_{j+i-1}^ja_1+C_{j+i-2}^ja_2+\cdots+C_{j+i-x+1}^ja_{x-1}+C_{j+i-x}^ja_x①\\

s_{j+1,i-1}=\sum_{x=1}^{i-1}C_{i-1+j-x}^ja_x\\
=C_{j+i-2}^ja_1+C_{j+i-3}^ja_2+\cdots+C_{j+i-x}^ja_{ix-1}②\\

s_{j,i}=\sum_{x=1}^{i}C_{i+j-1-x}^ja_x\\
=C_{j+i-2}^{j-1}a_1+C_{j+i-3}^{j-1}a_2+\cdots+C_{j+i-2}^{j-x}a_{x-1}+C_{j+i-x-1}^{j-1}a_x③
$$
根据组合数学杨辉三角公式：$C_{n-1}^{r-1}+C_{n-1}^r=C_n^r$ 可知，$②+③=①$。由此，证明了该组合数学意义式子与题给前缀和式子等价。因此，可以用组合数学方法推导高阶前缀和。即所求为：
$$
s_{y,x}=\sum_{k=1}^xC_{y+x-k-1}^{y-1}a_k
$$
注意到 $y-1$ 很大，我们可以转化为求较小的 $C_{y+x-k-1}^{x-k}$，并且使用线性递推，即所求的从 $k=1$ 开始递增的组合数值分别是：
$$
\dfrac{1}{0!},\dfrac{n}{1!},\dfrac{n(n+1)}{2!},\dfrac{n(n+1)(n+2)}{3!},\cdots
$$
即每次让分子乘以多一个数，分母也改为下一个阶乘即可，可以降复杂度 $O(y)$ 为 $O(n)$。

> 参考题目：[这里](https://oj.socoding.cn/p/1892)，题解见上文我的博客。



##### 1039\.多边形三角剖分的最低得分

[题目](https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/)

可知，三角剖分的数目为卡特兰数。具体而言固定一条边，该边所属第三点有 $n-2$ 个选择，并且把剩余部分拆分成了两个子问题，即方案数为 $p_n=\sum_{i=2}^{n-1}p_ip_{n-i}$，且初始值为 $p_2=p_3=1$。可知是指数增长，故不可以暴力枚举所有方案。(可以 $O(n)$ 计算卡特兰数，但没必要)

考虑固定一条边，为了区间连续性期间，不妨固定最后一条边 $(0,n-1)$，给这条边找第三点。设当前边是 $(i,j)$，枚举第三点，则答案为 $dp_{i,j}=v_iv_jv_k+dp_{i,k}+dp_{k,j}$。特判一下边界，并且做记忆化处理，最后输出 $dp_{0,n-1}$ 即可。

```rust
impl Solution {
    pub fn min_score_triangulation(v: Vec<i32>) -> i32 {
        let n = v.len();
        let mut dp = vec![vec![0; n]; n];
        fn calc(v: &[i32], dp: &mut Vec<Vec<i32>>, l: usize, r: usize) -> i32 {
            if dp[l][r] != 0 {
                return dp[l][r];
            }
            if l + 2 > r {
                return 0;
            }
            if l + 2 == r {
                return v[l] * v[l + 1] * v[r];
            }
            let mut ans = i32::MAX;
            for k in l + 1..r {
                ans = ans.min(v[l] * v[k] * v[r] + calc(v, dp, l, k) + calc(v, dp, k, r));
            }
            dp[l][r] = ans;
            ans
        };
        calc(&v, &mut dp, 0, n - 1)
    }
}
```

> 一种顺序枚举的做法：
>
> ```rust
> pub fn min_score_triangulation(values: Vec<i32>) -> i32 {
>     let n = values.len();
>     let mut dp = vec![vec![i32::MAX;n+1];n];
>     for i in 0..n {
>         dp[i][2] = 0;
>     }
> 
>     for c in 3..=n {
>         for i in 0..n {
>             for j in (i+1)..(i+c-1) {
>                 let jn = j % n;
>                 dp[i][c] = dp[i][c].min(
>                     values[i]*values[jn]*values[(i+c-1)%n] + dp[i][j+1-i] + dp[jn][i+c-j]
>                 );
>             }
>         }
>     }
>     dp[0][n]
> }
> ```



##### 1053\.交换一次的先前排列

[题目](https://leetcode.cn/problems/previous-permutation-with-one-swap/)

逆序遍历原数组，对每个 $v$，如果能找到在它之后出现过比它小的值，就用最大比它小的与它交换。注意如果有多个应该取最早出现的一个，考虑 `3,1,1`，显然 `1,3,1` 比 `1,1,3` 更大。

维护 tree map，可以达到时间 $O(n\log n)$ 和空间 $O(n)$。(对 C++ 而言，直接取 v 的 prev 指针即可)

```rust
use std::collections::BTreeMap;
impl Solution {
    pub fn prev_perm_opt1(arr: Vec<i32>) -> Vec<i32> {
        let n = arr.len();
        let mut h: BTreeMap<i32, usize> = BTreeMap::new();
        let mut ans: Vec<i32> = Vec::new();
        ans.extend(arr);
        for i in (0..n).rev() {
            if i + 1 != n {
                let v = ans[i];
                if let Some(j) = h.range(..v).next_back().map(|(&_k, &v)| (v)) {
                    let k = ans[i];
                    ans[i] = ans[j];
                    ans[j] = k;
                    break;
                }
            }
            h.insert(ans[i], i);
        }
        ans
    }
}
```

更优解：当找到第一个逆序时，原数组往后的部分一定是单调的，所以直接遍历后半部分可以直接搞到最大小于的目标。

```java
class Solution {
    public int[] prevPermOpt1(int[] arr) {
        int n = arr.length;
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                int j = n - 1;
                while (arr[j] >= arr[i] || arr[j] == arr[j - 1]) {
                    j--;
                }
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                break;
            }
        }
        return arr;
    }
}
```



##### 1000\.合并石头的最低成本

[题目](https://leetcode.cn/problems/minimum-cost-to-merge-stones/)

当 $k=2$ 时是典中典的区间 DP 模板题(相邻合并)。

设 $dp_{l,r,t}$ 为将 $[l,r]$ 内石子合为 $t$ 堆的答案。初始 $dp_{i,i,1}=0$，其他为 $\infty$。所求是 $dp_{1,n,1}$。若 $t=1$，则答案为 $dp_{l,r,t}=dp_{l,r,k}+s_{l,r}$。注意 $k$ 是常量，不是 $i,j,k$ 的变量。若 $t>1$，则 $dp_{l,r,t}=\min (dp_{l,p,1}+dp_{p+1,r,t-1})$。之所以不用 $+s_{l,r}$，是因为只是离散地把两个堆放在一起并没有进行合并操作，所以没有代价。只是笼统代表两次子合并的和。

显然，最多能开到 $k$ 的维度，故空间 $O(n^2k)$，时间 $O(n^3k)$。其中多一个 $n$ 来自转移。

递归写法：

```java
class Solution {
    static final int INF = 0x3f3f3f3f;
    int[][][] d;
    int[] sum;
    int k;

    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }
        this.k = k;
        d = new int[n][n][k + 1];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(d[i][j], -1);
            }
        }
        sum = new int[n];

        // 初始化
        for (int i = 0, s = 0; i < n; i++) {
            d[i][i][1] = 0;
            s += stones[i];
            sum[i] = s;
        }
        int res = get(0, n - 1, 1);
        return res;
    }

    public int get(int l, int r, int t) {
        // 若 d[l][r][t] 不为 -1，表示已经在之前的递归被求解过，直接返回答案
        if (d[l][r][t] != -1) {
            return d[l][r][t];
        }
        // 当石头堆数小于 t 时，一定无解
        if (t > r - l + 1) {
            return INF;
        }
        if (t == 1) {
            int res = get(l, r, k);
            if (res == INF) {
                return d[l][r][t] = INF;
            }
            return d[l][r][t] = res + (sum[r] - (l == 0 ? 0 : sum[l - 1]));
        }
        int val = INF;
        for (int p = l; p < r; p += (k - 1)) {
            val = Math.min(val, get(l, p, 1) + get(p + 1, r, t - 1));
        }
        return d[l][r][t] = val;
    }
}
```

非递归写法：

```java
class Solution {
    static final int INF = 0x3f3f3f3f;

    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }

        int[][][] d = new int[n][n][k + 1];
        int[] sum = new int[n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Arrays.fill(d[i][j], INF);
            }
        }

        for (int i = 0, s = 0; i < n; i++) {
            d[i][i][1] = 0;
            s += stones[i];
            sum[i] = s;
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                for (int t = 2; t <= k; t++) {
                    for (int p = l; p < r; p += k - 1) {
                        d[l][r][t] = Math.min(d[l][r][t], d[l][p][1] + d[p + 1][r][t - 1]);
                    }
                }
                d[l][r][1] = Math.min(d[l][r][1], d[l][r][k] + sum[r] - (l == 0 ? 0 : sum[l - 1]));
            }
        }
        return d[0][n - 1][1];
    }
}
```

优化：对 $[l,r]$，一开始有 $r-l+1$ 堆，不难看出每次减少 $k-1$ 堆，即堆数固定减少。具体而言设 $dp_{l,r}$ 是答案，则：
$$
dp_{l,r}=\min dp_{l,p}+dp_{p+1,r}+[(r-l)\bmod (k-1)=0]s_{l,r}
$$
也就是默认叠加，满了自动合并。

```java
class Solution {
    static final int INF = 0x3f3f3f3f;

    public int mergeStones(int[] stones, int k) {
        int n = stones.length;
        if ((n - 1) % (k - 1) != 0) {
            return -1;
        }

        int[][] d = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(d[i], INF);
        }
        int[] sum = new int[n];

        for (int i = 0, s = 0; i < n; i++) {
            d[i][i] = 0;
            s += stones[i];
            sum[i] = s;
        }

        for (int len = 2; len <= n; len++) {
            for (int l = 0; l < n && l + len - 1 < n; l++) {
                int r = l + len - 1;
                for (int p = l; p < r; p += k - 1) {
                    d[l][r] = Math.min(d[l][r], d[l][p] + d[p + 1][r]);
                }
                if ((r - l) % (k - 1) == 0) {
                    d[l][r] += sum[r] - (l == 0 ? 0 : sum[l - 1]);
                }
            }
        }
        return d[0][n - 1];
    }
}
```



##### 2417\.公因子的数目

[题目](https://leetcode.cn/problems/number-of-common-factors/)

暴力略自己想到的一个是先根号复杂度求 a 的所有因数存 set，然后对 b 求一遍，看看每个在不在 set 里。

更优：直接求 $\gcd(a,b)$ 的因子数。

```rust
impl Solution {
    pub fn common_factors(a: i32, b: i32) -> i32 {
        let mut ans = 0;
        for i in 1..=a.max(b) {
            if a % i == 0 && b % i == 0 {
                ans += 1;
            }
        }
        ans
    }
}
```



##### 1017\.负二进制转换

[题目](https://leetcode.cn/problems/convert-to-base-2/)

不妨先打个表，打表 C++ 程序如下：

> ```c++
> #include <bits/stdc++.h>
> using namespace std;
> using ll = long long;
> const ll mn = 7;
> map<ll, string> m;
> signed main()
> {
>     freopen("1017tab.txt", "w", stdout);
>     for (ll h = 0; h < 1 << mn; ++h)
>     {
>         ll cnt = 0;
>         string s = "";
>         for (ll i = 0, v = 1; i < mn; ++i, v *= -2)
>         {
>             if ((h >> i) & 1)
>             {
>                 cnt += v;
>             }
>             s = (((h >> i) & 1) ? '1' : '0') + s;
>         }
>         m[cnt] = s;
>     }
>     for (auto [v, s] : m)
>     {
>         printf("%3lld %s\n", v, s.c_str());
>     }
>     return 0;
> }
> ```

截取打表打出来的内容，发现抛开 $(-2)^0$ 不谈，对每两负正位如 $(-2)^1,(-2)^2$ 或 $(-2)^2,(-2)^3$，变化规律总是从 $01\to00\to11\to10$ 增大(显然，即把二进制增长的末位反一下)，且总是隔 $2,8,32,\cdots$ 变化一次。例如对 $(-2)^1,(-2)^2$ 是隔 $2$ 个，即：

> ```c
>  -2 0000010
>  -1 0000011
>   0 0000000
>   1 0000001
>   2 0000110
>   3 0000111
>   4 0000100
>   5 0000101
> ```

考虑做一个偏移，即把 $-2$ 看成 $0$，然后开始递增，可以发现，两位两位的映射，把 $(00)_2,(01)_2,(10)_2,(11)_2$ 映射成 $(01)_{-2},(00)_{-2},(11)_{-2}，(10)_{-2}$。

考虑到最大值是 $10^{9}$，可以不断做偏移，即对 $n$ 加上 $-2,(-2)^3,(-2)^5,\cdots,(-2)^{29}$，直到被 $30$ 位负二进制表示的最小的负数变成 $0$，然后从倒数第二低位开始，两位两位地进行映射即可。

```rust
impl Solution {
    pub fn base_neg2(n: i32) -> String {
        if n == 0 {
            return "0".to_string();
        }
        let mut v = n as i64;
        let mut i = 1 as i64;
        let mut ip = 2 as i64;
        const TOP: i64 = 30;
        while i < TOP {
            v += ip;
            i += 2;
            ip *= 4;
        }
        i -= 2;
        ip /= 4;
        assert!(i == TOP - 1);
        let mut ans = String::new();
        let c = ["01", "00", "11", "10"];
        while i > 0 {
            let r = v / ip;
            v %= ip;
            ans += c[r as usize];
            i -= 2;
            ip /= 4;
        }
        if v == 0 {
            ans += "0";
        } else {
            ans += "1";
        }
        ans.trim_start_matches('0').to_string()
    }
}
```

题解：

解法一：将 $n$ 拆分为若干 $2^i$，若 $i$ 偶数，直接对应负二进制；否则 $2^i=(-2)^{i+1}+(-2)^i$。这样搞了之后，会得到若干 $C(-2)^i$，当 $C > 1$ 时，需要进位。若 $C$ 是基数，则设 $C(-2)^i=a(-2)^{i+1}+(-2)^i$，否则进位完本位没有，为 $C(-1)^i=a(-2)^{i+1}$。 $C=v=ax+r$，则 $a=\dfrac{v-r}{x}$。$v$ 的最低位就是余数 $r$，负数是二进制补码，所以最低位不变余数直接取 $v\&1$。故 $a=\dfrac{C-(C\&1)}{-2}$。也可以等式两边同除易知。

```java
class Solution {
    public String baseNeg2(int n) {
        if (n == 0) {
            return "0";
        }
        int[] bits = new int[32];
        for (int i = 0; i < 32 && n != 0; i++) {
            if ((n & 1) != 0) {
                bits[i]++;
                if ((i & 1) != 0) {
                    bits[i + 1]++;
                }
            }
            n >>= 1;
        }
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            int val = carry + bits[i];
            bits[i] = val & 1;
            carry = (val - bits[i]) / (-2);
        }
        int pos = 31;
        StringBuilder res = new StringBuilder();
        while (pos >= 0 && bits[pos] == 0) {
            pos--;
        }
        while (pos >= 0) {
            res.append(bits[pos]);
            pos--;
        }
        return res.toString();
    }
}
```

解法二：可以模仿普通进制转换，如：

![image.png](img/1680742541-xMapiC-image.png)

```python
def baseNeg2(self, n: int) -> str:
    return str(n) if n in (0, 1) else self.baseNeg2((n - (n & 1)) // -2) + str(n & 1) 
```

解法三：显然，奇数位全 0，偶数位全 1 的负二进制最大，转化为二进制为 0x55555555。最小的是奇数位全 1，偶数位全 0，转化为二进制为 0xAAAAAAAA(最高A占了符号位负数)。设最大值与 $n$ 差值为 $d$，若把最大值在负二进制下表示，减去差值，那么得到 $n$ 的负二进制。减法操作可以这么做：

- 对 diff 偶数 1，1-1 变 0；偶数 0，1-0 不变还是 0
- 对 diff 奇数 0，0-0 不变还是 0；奇数 1，因为 $(2)^i=(-2)^{i+1}+(-2)^i$，故不借位，0-1=1

可以发现符合异或的定义。即对 $m=0x55555555$，差值是 $m-n$，这两个二进制表达，直接用异或，就得到了负二进制的 $n$，即 $n_{-2}=m_2\oplus (m_2-n_2)$。

这种办法最高效，不考虑答案去前导零，则是 $O(1)$ 的。

```java
class Solution {
    public String baseNeg2(int n) {
        int val = 0x55555555 ^ (0x55555555 - n);
        if (val == 0) {
            return "0";
        }
        StringBuilder res = new StringBuilder();
        while (val != 0) {
            res.append(val & 1);
            val >>= 1;
        }
        return res.reverse().toString();
    }
}
```



##### 1040\.移动石子直到连续II

[题目](https://leetcode.cn/problems/moving-stones-until-consecutive-ii/)

讲人话的题意翻译：数轴上有 $n$ 个整点，每次只能移动首/尾的点，将该点移动到任意一个满足：移动后不再是首/尾且该位置本来没有点的整数的位置。求最小和最大移动次数。

先对点排序，得 $a$ 有序坐标序列。由于不能移动使其成为新首，故移动后的位置必然大于 $a_0$。枚举每个 $[a_i,a_i+n)$ 作为终态，本来在这个范围的点不用动，其他点每次拿当前末尾放到这个区间最小空位上去，或拿首放到最大空位。但是有一种特殊条件不可行：唯一空位是最大的空位。其他情况都可以放，例如对 `3,4,5,6,10`，第一个区间是 $[3,7]$，不能放；第二个区间是 $[4,8]$，先把首 $3$ 放到最大空位 $8$，再把尾 $10$ 放到最小空位 $7$ 即可。又如 `1,3,10`，枚举的第一个区间是 $[1,3]$，直接把尾 $10$ 放到最小空位 $2$ 即可。

具体到实现上，当然可以开动态开点的线段树，但是有更优做法。对排序后的 $a$ 叠 $cnt$，存 $map$，即 $m_v$ 表示 $\le v$ 的数有多少个。对每个 $l=a_i$ 和 $r=a_i+n-1$，二分找到 $\le r$ 的最大 $map$ 元素 $m_{r'}$，则这个区间非空位置数为 $m_l-m_{r'}+1$，总位置数为 $r-l+1=n$。单次查询 $O(\log n)$。共 $O(n\log n)$。

对最大值，考虑两种方案：每次把首跳最大空位，或者把尾跳最小空位。首跳最大空位会损失 $a_1-a_0$ 个空位，尾跳最小空位会损失 $a_{n-1}-a_{n-2}$ 个空位。在这之后，必然首与第二小连续，或者尾与第二大连续，对连续的一方，跳走，每次损失一个长度。除去首尾外，还有 $n-2$ 个非空不可跳，故第一步首跳最多跳 $a_{n-1}-a_0-(a_1-a_0+n-2)=a_{n-1}-a_1-(n-2)$ 个空位，第一步尾跳最多跳 $a_{n-1}-a_0-(a_{n-1}-a_{n-2}+n-2)=a_{n-2}-a_0-(n-2)$ 个空位。取最值就是最大值。复杂度 $O(1)$。

考虑上排序复杂度，总时间复杂度为 $O(n\log n)$，开 map 空间复杂度为 $O(n)$。

```rust
use std::collections::BTreeMap;
impl Solution {
    pub fn num_moves_stones_ii(stones: Vec<i32>) -> Vec<i32> {
        let mut a = stones.clone();
        a.sort();
        let n = a.len();
        let mut cnt = 0;
        let mut h = BTreeMap::new();
        for i in 0..n {
            cnt += 1;
            h.insert(a[i], cnt);
        }
        let mut mi = n as i32;
        for (l, lcnt) in &h {
            // if lcnt == &1 {
            //     continue; //not==1
            // }
            //不能h,不然不可以搞h.range
            let r = l + n as i32 - 1;
            let pr = h.range(..=r).last();//<=r的最大
            if let Some((re, rcnt)) = pr {
                let num = rcnt - lcnt + 1;
                let rng = r - l + 1;
                // println!("{} {} {} {}", l, r, lcnt, rcnt);
                if re < &r && rng - num == 1 {
                    continue;
                }
                mi = mi.min(rng - num);
            }
        }
        if a[n - 1] - a[0] + 1 == n as i32 {
            mi = 0;
        }
        let mut mx = a[n - 1] - a[1] - (n as i32 - 2);
        mx = mx.max(a[n - 2] - a[0] - (n as i32 - 2));
        mx = mx.max(0);
        vec![mi, mx]
    }
}
```

求最小可以用双指针滑窗优化，从而 $O(n)$ 找最小，且空间 $O(1)$：

```java
class Solution {
    public int[] numMovesStonesII(int[] stones) {
        int n = stones.length;
        Arrays.sort(stones);
        if (stones[n - 1] - stones[0] + 1 == n) {
            return new int[]{0, 0};
        }
        int ma = Math.max(stones[n - 2] - stones[0] + 1, stones[n - 1] - stones[1] + 1) - (n - 1);
        int mi = n;
        for (int i = 0, j = 0; i < n && j + 1 < n; ++i) {
            while (j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) {
                ++j;//新区间跨度<=n
            }
            if (j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) {//如果不在区间内的仅是最大值a[n-1],区间只有一个空位,动两次
                mi = Math.min(mi, 2);
            } else {
                mi = Math.min(mi, n - (j - i + 1));
            }
        }
        return new int[]{mi, ma};
    }
}
```



##### 3\.无重复字符的最长子串

[题目](https://leetcode.cn/problems/longest-substring-without-repeating-characters/)

当然可以 cnt 双指针，一眼：

```rust
pub struct Solution {}
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut cnt = [0; 128];
        let mut ans = 0;
        let mut l = 0 as usize;
        let mut rs = s.chars();
        let mut ls = s.chars();
        for r in 0..s.len() {
            let i = rs.next().unwrap() as usize;
            cnt[i] += 1;
            while cnt[i] > 1 {
                let j = ls.next().unwrap() as usize;
                cnt[j] -= 1;
                l += 1;
            }
            ans = ans.max(r - l + 1);
        }
        ans as i32
    }
}
```

更优雅：对每个字符，记录上次出现的位置，每次把左指针取近一次重复的。

```rust
impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        use std::cmp::max;
        let mut last: [i32; 128] = [-1; 128];
        let mut left = -1;
        let mut ans = 0;
        for (i, v) in s.chars().enumerate() {
            left = max(left, last[v as usize]);
            last[v as usize] = i as i32;
            ans = max(ans, (i as i32) - left);
        }
        return ans;
    }
}
```



##### 1125\.最小的必要团队

[题目](https://leetcode.cn/problems/smallest-sufficient-team/)

设每个技能(哈希转下标)当前团队有与没有为二进制状态，每个团队可以对应一个 $n$ 位的二进制状态。BFS 搜索，初始设状态为 $0$，目标状态为 $2^n-1$。每次搜索，遍历所有人的二进制状态，将它或到当前状态上，如果有更新，就继续 BFS，队列存储状态。注意如果某个状态遍历过了剪一下。

因为每次遍历 $m$ 人，最坏状态都要更新，每次更新复制方案需要 $O(m)$，故单次遍历为 $O(m^2)$。最坏每个状态都遍历一次，故时间复杂度为 $O(m^22^n)$，空间为 $O(m2^n)$。

可以通过前向星办法链表压缩存储，每个方案指向上一个人，能达到时空均降一个 $m$ 的效果，具体参见题解。这里略。 

```rust
use std::collections::HashMap;
use std::collections::VecDeque;
impl Solution {
    pub fn smallest_sufficient_team(req_skills: Vec<String>, people: Vec<Vec<String>>) -> Vec<i32> {
        let mut h = HashMap::new();
        let n = req_skills.len();
        for i in 0..n {
            h.insert(&req_skills[i], i);
        }
        let tg = (1 << n) - 1;
        let mut q = VecDeque::new();
        let mut vis = vec![false; 1 << n];
        struct Node {
            state: i32,
            scheme: Vec<i32>,
        } //不用分号
        q.push_back(Node {
            state: 0,
            scheme: vec![],
        });
        let m = people.len();
        while !q.is_empty() {
            let nd = q.pop_front().unwrap();
            let u = nd.state;
            // println!("{} {:?}", u, nd.scheme);#不能nd
            if u == tg {
                return nd.scheme;
            }
            if vis[u as usize] {
                continue;
            }
            vis[u as usize] = true;
            for i in 0..m {
                let mut v = u;
                for j in 0..people[i].len() {
                    let k = h.get(&people[i][j]).unwrap();
                    let kv = 1 << k;
                    v |= kv;
                }
                if !vis[v as usize] && v != u {
                    let mut nx = nd.scheme.clone();
                    nx.push(i as i32);
                    q.push_back(Node {
                        state: v,
                        scheme: nx,
                    });
                }
            }
        }
        panic!("No sol");
    }
}
```

题解顺序遍历：

```java
class Solution {
    public int[] smallestSufficientTeam(String[] req_skills, List<List<String>> people) {
        int n = req_skills.length, m = people.size();
        HashMap<String, Integer> skill_index = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            skill_index.put(req_skills[i], i);
        }
        int[] dp = new int[1 << n];
        Arrays.fill(dp, m);
        dp[0] = 0;
        int[] prev_skill = new int[1 << n];
        int[] prev_people = new int[1 << n];
        for (int i = 0; i < m; i++) {
            List<String> p = people.get(i);
            int cur_skill = 0;
            for (String s : p) {
                cur_skill |= 1 << skill_index.get(s);
            }
            for (int prev = 0; prev < (1 << n); prev++) {
                int comb = prev | cur_skill;
                if (dp[comb] > dp[prev] + 1) {
                    dp[comb] = dp[prev] + 1;
                    prev_skill[comb] = prev;
                    prev_people[comb] = i;
                }
            }
        }
        List<Integer> res = new ArrayList<>();
        int i = (1 << n) - 1;
        while (i > 0) {
            res.add(prev_people[i]);
            i = prev_skill[i];
        }
        return res.stream().mapToInt(j -> j).toArray();
    }
}
```



##### 1041\.困于环中的机器人

[题目](https://leetcode.cn/problems/robot-bounded-in-circle/)

可以连续走四次，如果回到原点就行。更优雅的解法：

1. 走一轮回到原点，困于环中。
2. 没回到原点：
   1. 面朝北，则不会困于环中。
   2. 面朝南，再走一次就会于上一次逆向，使得下一轮必然回到原点，困于环中。
   3. 面朝东，那么再走一次面朝南，于是再走两次面朝北(第一第三次相反，第二第四次相反)，困于环中。
   4. 面朝西，同理。

```rust
impl Solution {
    pub fn is_robot_bounded(instructions: String) -> bool {
        let mut x = 0;
        let mut y = 0;
        const DX: [i32; 4] = [0, -1, 0, 1];
        const DY: [i32; 4] = [1, 0, -1, 0];
        let mut d = 0;
        for _i in 0..4 {
            for c in instructions.chars() {
                match c {
                    'G' => {
                        x += DX[d];
                        y += DY[d];
                    }
                    'L' => d = (1 + d) % 4,
                    'R' => d = (3 + d) % 4,
                    _ => (),
                }
            }
        }
        x == 0 && y == 0
    }
}
```

```java
class Solution {
    public boolean isRobotBounded(String instructions) {
        int[][] direc = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int direcIndex = 0;
        int x = 0, y = 0;
        int n = instructions.length();
        for (int idx = 0; idx < n; idx++) {
            char instruction = instructions.charAt(idx);
            if (instruction == 'G') {
                x += direc[direcIndex][0];
                y += direc[direcIndex][1];
            } else if (instruction == 'L') {
                direcIndex += 3;
                direcIndex %= 4;
            } else {
                direcIndex++;
                direcIndex %= 4;
            }
        }
        return direcIndex != 0 || (x == 0 && y == 0);
    }
}
```



##### 1147\.段式回文

[题目](https://leetcode.cn/problems/longest-chunked-palindrome-decomposition/)

rust 双百。看到没人用 rust 写字符串哈希的题解，那我补一个。

解题思路很一眼，不断贪心找当前前缀和后缀，用字符串哈希判断是否相等相等就删掉。

```rust
impl Solution {
    pub fn longest_decomposition(text: String) -> i32 {
        let n = text.len();
        const P: usize = 41;
        let mut h = vec![0 as usize; n + 1];
        let mut p = vec![1 as usize; n + 1];
        let mut c = text.chars();
        for i in 1..=n {
            p[i] = p[i - 1].wrapping_mul(P);
            h[i] = h[i - 1].wrapping_mul(P);
            h[i] = h[i].wrapping_add(c.next().unwrap() as usize - 'a' as usize + 1);
        }
        let hash = |l: usize, r: usize| h[r].wrapping_sub(h[l - 1].wrapping_mul(p[r + 1 - l])); //必须显式usize声明
        let mut ans = 0;
        let (mut l, mut r) = (1 as usize, n);
        while l <= r {
            let mut k = 0;
            loop {
                let hl = hash(l, l + k);
                let hr = hash(r - k, r);
                if hl == hr {
                    ans += 2;
                    if l + k == r {
                        ans -= 1;
                        l = 1;
                        r = 0;
                    } else {
                        l += k + 1;
                        r -= k + 1;
                    }
                    break;
                }
                k += 1;
            }
        }
        ans
    }
}
```



##### 1023\.驼峰式匹配

[题目](https://leetcode.cn/problems/camelcase-matching/)

```rust
impl Solution {
    pub fn camel_match(queries: Vec<String>, pattern: String) -> Vec<bool> {
        let n = queries.len();
        let mut ans = vec![false; n];
        let cs: Vec<char> = pattern.chars().collect();
        for i in 0..n {
            let mut ci = 0;
            let mut ok = true;
            for q in queries[i].chars() {
                if ci == pattern.len() {
                    if q.is_uppercase() {
                        ok = false;
                        break;
                    }
                    continue;
                }
                if q == cs[ci] {
                    ci += 1;
                } else if q.is_uppercase() {
                    ok = false;
                    break;
                }
            }
            ans[i] = ok && ci == pattern.len();
        }
        ans
    }
}
```

更优实现：

```rust
impl Solution {
    pub fn camel_match(queries: Vec<String>, pattern: String) -> Vec<bool> {
        let mut ans = vec![false; queries.len()];
        let pattern: Vec<char> = pattern.chars().collect();
        for (i, query) in queries.iter().enumerate() {
            let mut j = 0;
            for ch in query.chars() {
                if j < pattern.len() && ch == pattern[j] {
                    j += 1;
                }else {
                    if 'A' <= ch  && ch <= 'Z' {
                        j = 0;
                        break;
                    }
                }
            }
            if j == pattern.len() {
                ans[i] = true;
            }
        }

        ans
    }
}
```



正则：

```java
class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        String newPattern = "[a-z]*" + String.join("[a-z]*", pattern.split("")) + "[a-z]*";
        return Arrays.stream(queries).map(query -> query.matches(newPattern)).collect(Collectors.toList());
    }
}
```



##### 1157\.子数组中占绝大多数的元素

[题目](https://leetcode.cn/problems/online-majority-element-in-subarray/)

解法一：随机化+二分查找。

显然，题目所求的是绝对众数(即不会出现并列众数的众数)，不仅如此还要在众数的基础上满足一个频次需求。

设众数存在，为 $x$，若随机选择一个区间内的数，有最低 $\dfrac12$ 概率选到众数，如果连续选 $k=20$ 次都选不到众数的概率最坏为 $(\dfrac12)^k\approx10^{-6}$。

对每个值，升序存每个出现的下标。二分查询 $[l,r]$ 内有多少个该值出现，跟频次比较。特别地如果该值已经是众数(即频次乘二大于等于长度)，但不满足频次，可以直接停止随机化。

```c++
class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr): arr(arr) {
        for (int i = 0; i < arr.size(); ++i) {
            loc[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int threshold) {
        int length = right - left + 1;
        uniform_int_distribution<int> dis(left, right);

        for (int i = 0; i < k; ++i) {
            int x = arr[dis(gen)];
            vector<int>& pos = loc[x];
            int occ = upper_bound(pos.begin(), pos.end(), right) - lower_bound(pos.begin(), pos.end(), left);
            if (occ >= threshold) {
                return x;
            }
            else if (occ * 2 >= length) {
                return -1;
            }
        }

        return -1;
    }

private:
    static constexpr int k = 20;

    const vector<int>& arr;
    unordered_map<int, vector<int>> loc;
    mt19937 gen{random_device{}()};
};
```

解法二：摩尔投票+线段树。

Boyer-Moore 投票算法。如果众数 +1，其他数 -1，求和后必然和 \>0。时间复杂度是 $O(n)$，空间复杂度是 $O(1)$，具体而言：

1. 设候选总数 `candidate` 和出现次数 `count`。初始随机选一个候选，如首元素。
2. 往下遍历，如果 `count` 变成 0，那么下一个出现的数重新选为候选数

最后选定的一定是众数。即：[参考](https://leetcode.cn/problems/majority-element/solution/duo-shu-yuan-su-by-leetcode-solution/)

```java
class Solution {
    public int majorityElement(int[] nums) {
        int count = 0;
        Integer candidate = null;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }
        return candidate;
    }
}
```

只能在已知必然有众数的前提下使用，不然是错的，如 `1 2 3 4 5` 会找出 `5`。

原理：每次更换候选数时，能保持 count 确实仍为 0，因为 -1 的变 +1，而 +1 的变 -1，整体不变。

根据投票算法的本质，可知，对给定数组，拆成两部分(无论连续与否)，分别投票得到 $(x_0,cnt_0),(x_1,cnt_1)$，要进行合并时：

- $x_0=x_1$，结果相加 $(x_0,cnt_0+cnt_1)$。
- 否则，取较大那个，然后大减小，即 $(\max(x_0,x_1),|cnt_0-cnt_1|)$

如果本来这个区间就没有众数，那么查出来显然假。否则，总数肯定是 $x_0,x_1$ 其一，若 $x_0=x_1$，直接相加是容易理解的。否则，相减后的结果，不等于直接整段投票的结果，如 `4,1,1,1,4` 和 `5,4,4,4,4`，直接计算合并后的投票值是 4，但是算出来是 2。

根据这个原理套上线段树，可以区间查询任意区间摩尔投票的值然后再用上述二分检查。注意这个合并可能会查假，例如 `0 1 1 1 0` 合并 `5 4 4 4 4`，实际上是无解，但是合出来 cnt 是对的。

```c++
struct Node {
    Node(int x = 0, int cnt = 0): x(x), cnt(cnt) {}
    Node& operator+=(const Node& that) {
        if (x == that.x) {
            cnt += that.cnt;
        }
        else if (cnt >= that.cnt) {
            cnt -= that.cnt;
        }
        else {
            x = that.x;
            cnt = that.cnt - cnt;
        }
        return *this;
    }

    int x, cnt;
};

class MajorityChecker {
public:
    MajorityChecker(vector<int>& arr): arr(arr) {
        n = arr.size();
        for (int i = 0; i < n; ++i) {
            loc[arr[i]].push_back(i);
        }

        tree.resize(n * 4);
        seg_build(0, 0, n - 1);
    }
    
    int query(int left, int right, int threshold) {
        Node ans;
        seg_query(0, 0, n - 1, left, right, ans);
        vector<int>& pos = loc[ans.x];
        int occ = upper_bound(pos.begin(), pos.end(), right) - lower_bound(pos.begin(), pos.end(), left);
        return (occ >= threshold ? ans.x : -1);
    }

private:
    int n;
    const vector<int>& arr;
    unordered_map<int, vector<int>> loc;
    vector<Node> tree;

    void seg_build(int id, int l, int r) {
        if (l == r) {
            tree[id] = {arr[l], 1};
            return;
        }

        int mid = (l + r) / 2;
        seg_build(id * 2 + 1, l, mid);
        seg_build(id * 2 + 2, mid + 1, r);
        tree[id] += tree[id * 2 + 1];
        tree[id] += tree[id * 2 + 2];
    }

    void seg_query(int id, int l, int r, int ql, int qr, Node& ans) {
        if (l > qr || r < ql) {
            return;
        }
        if (ql <= l && r <= qr) {
            ans += tree[id];
            return;
        }

        int mid = (l + r) / 2;
        seg_query(id * 2 + 1, l, mid, ql, qr, ans);
        seg_query(id * 2 + 2, mid + 1, r, ql, qr, ans);
    }
};
```



##### 2409\.统计共同度过的日子数

[题目](https://leetcode.cn/problems/count-days-spent-together/)

暴力逐日模拟+时间戳思想，判断每天是否都在两个时间戳区间内：

```rust
const DAYS: [i32; 13] = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
pub fn tomd(s: String) -> (i32, i32) {
    let m = s[0..2].parse::<i32>().unwrap();
    let d = s[s.len() - 2..].parse::<i32>().unwrap();
    return (m, d);
}
pub fn val(m: i32, d: i32) -> i32 {
    m * 100 + d
}
impl Solution {
    pub fn count_days_together(
        arrive_alice: String,
        leave_alice: String,
        arrive_bob: String,
        leave_bob: String,
    ) -> i32 {
        let (m11, d11) = tomd(arrive_alice);
        let (m12, d12) = tomd(leave_alice);
        let (m21, d21) = tomd(arrive_bob);
        let (m22, d22) = tomd(leave_bob);
        let (v11, v12) = (val(m11, d11), val(m12, d12));
        let (v21, v22) = (val(m21, d21), val(m22, d22));
        let mut ans = 0;
        for m in m11..=m12 {
            for d in 1..=DAYS[m as usize] {
                let v = val(m, d);
                if v >= v11 && v <= v12 && v >= v21 && v <= v22 {
                    ans += 1;
                }
            }
        }
        ans
    }
}
```

更优解：将月日转一年的第几天，然后可以直接求区间长度，两区间并即可。

```rust
const MONTHS: [i32; 12] = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

impl Solution {
    pub fn count_days_together(arrive_alice: String, leave_alice: String, arrive_bob: String, leave_bob: String) -> i32 {
        let parse = |s: String| -> i32 {
            let mut it = s.split('-').map(|v| v.parse::<i32>().unwrap());
            let (month, day) = (it.next().unwrap(), it.next().unwrap());
            MONTHS[..(month - 1) as usize].iter().sum::<i32>() + day
        };

        let a1 = parse(arrive_alice);
        let a2 = parse(leave_alice);
        let b1 = parse(arrive_bob);
        let b2 = parse(leave_bob);
        let min_day = a1.max(b1);
        let max_day = a2.min(b2);

        0.max(max_day - min_day + 1)
    }
}
```



##### 1026\.节点与其祖先之间的最大差值

[题目](https://leetcode.cn/problems/maximum-difference-between-node-and-ancestor/)

所以直接搞最大最小即可，丢到参数里即可。

```java
class Solution {
    private int ans = Integer.MIN_VALUE;

    private void dfs(TreeNode u, Integer mi, Integer mx) {
        if (u == null) {
            return;
        }
        if (mi != null) {
            ans = Math.max(ans, Math.abs(u.val - mi));
            ans = Math.max(ans, Math.abs(u.val - mx));
            mi = Math.min(mi, u.val);
            mx = Math.max(mx, u.val);
        } else {
            mi = u.val;
            mx = u.val;
        }
        dfs(u.left, mi, mx);
        dfs(u.right, mi, mx);
    }

    public int maxAncestorDiff(TreeNode root) {
        dfs(root, null, null);
        return ans;
    }
}
```

解法二：维护路径最值，然后相减。不管值域是不是非负数都可以这么搞。

```java


    public int maxAncestorDiff(TreeNode root) {
        if (root == null) {
            return 0;
        }
        // 默认情况下，已知的最小最大边界既是root.val
        return dfs(root, root.val, root.val);
    }


    /**
     * DFS
     * @param root 树节点
     * @param min 已知的最小边界值
     * @param max 已知的最大边界值
     * @return 最大差值
     */
    private int dfs(TreeNode root, int min, int max) {
        // maxAncestorDiff已经对root判空了，这里就不需要判空了
        // 每经过一个节点，则根据当前节点值，重新计算最小边界和最大边界值（不断扩张已知的范围）
        min = Math.min(min, root.val);
        max = Math.max(max, root.val);

        if (root.left == null && root.right == null) {
            // 到叶子节点的时候，此时该DFS路径的上下边界值已经是已知的最大范围，则计算差值
            return max - min;
        }
        // 递归处理左子树（路径往左走）
        int leftMaxAncestorDiff = dfs(root.left, min, max);
        // 递归处理右子树（路径往右走）
        int rightMaxAncestorDiff = dfs(root.right, min, max);
        // 返回最大差值的最大值
        return Math.max(leftMaxAncestorDiff, rightMaxAncestorDiff);
    }
```



##### 1043\.分隔数组以得到最大和

[题目](https://leetcode.cn/problems/partition-array-for-maximum-sum/)

设 $dp_i$ 前 $i$ 个数的答案，倒序枚举 $j\in[i-k,i-1]$，有：
$$
dp_i=\max dp_j+(i-j)\max_{k=j+1}^ia_k
$$
也就是枚举将 $a_i$ 不断往前扩展直到 $k$ 长，期间维护后缀 max。复杂度 $O(nk)$。

```java
class Solution {
    public int maxSumAfterPartitioning(int[] arr, int k) {
        int n = arr.length;
        int[] d = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int maxValue = arr[i - 1];
            for (int j = i - 1; j >= 0 && j >= i - k; j--) {
                d[i] = Math.max(d[i], d[j] + maxValue * (i - j));
                if (j > 0) {
                    maxValue = Math.max(maxValue, arr[j - 1]);
                }
            }
        }
        return d[n];
    }
}
```



##### 1187\.使数组严格递增

[题目](https://leetcode.cn/problems/make-array-strictly-increasing/)

设 $dp_i$ 表示只考虑前 $i$ 个数，且第 $i$ 个数不变时的答案。因为最后一个数可能变，所以增设 $arr1_{n+1}=\infty$，求 $dp_{n+1}$，以让最后一个数可以变化。初始设 $dp_i=\infty$，空区间 $dp_{0}=0$。如果最后法发现为 $\infty$ 就无解。

如果有 $arr1_{i} > arr1_{i-1}$，那么可以仍然递增不需要额外操作即 $dp_{i}=dp_{i-1}$。之后，进行一轮遍历，枚举 $j < i-1$，将 $[1,i-1]$ 区间分割成 $[1,j],[j+1,i-1]$，前者保留，后者全部替换。显然 $arr2$ 的重复值没有意义，可以直接排序去重。然后统计一下 $arr2$ 值域在 $[arr1_{j}+1,arr1_{i}-1]$ 的不相同元素有几个，如果不少于区间长度 $i-j-1$，那么可以全部替换，转移方程为 $dp_{i}=dp_j+i-j-1$。

每次查询，在有序数组二分或使用 map，对数复杂度，故总复杂度为 $O(n^2\log m)$

```java
import java.util.Arrays;
import java.util.TreeMap;

class Solution {
    private TreeMap<Integer, Integer> s;
    private final static int INF = (int) (1e9 + 7);

    private int rangeCnt(int l, int r) {
        int rv = s.higherEntry(r).getValue() - 1;
        int lv = s.ceilingEntry(l).getValue();
        return rv - lv + 1;
    }

    public int makeArrayIncreasing(int[] arr1, int[] arr2) {
        int n = arr1.length;
        int a[] = new int[n + 2];
        int dp[] = new int[n + 2];
        a[0] = -1;
        for (int i = 1; i <= n; ++i) {
            a[i] = arr1[i - 1];
        }
        a[n + 1] = INF;
        Arrays.fill(dp, INF);
        dp[0] = 0;
        s = new TreeMap<>();
        Arrays.sort(arr2);
        for (Integer val : arr2) {
            s.put(val, s.size());
            s.put(val, s.size());
        }
        s.put(INF, s.size() + 1);
        for (int i = 1; i <= n + 1; ++i) {
            if (a[i] > a[i - 1]) {
                dp[i] = dp[i - 1];
            }
            for (int j = 0; j < i - 1; ++j) {
                int cnt = rangeCnt(a[j] + 1, a[i] - 1);
                if (cnt >= i - j - 1) {
                    dp[i] = Math.min(dp[i], dp[j] + i - j - 1);
                }
            }
        }
        return dp[n + 1] == INF ? -1 : dp[n + 1];
    }
}
```

> 附：提供一些测试用例
>
> ```
> [3,2,1]
> [1,2,3]
> 
> [1,5,3,6,7]
> [3,4]
> 
> [6,8,7,10,20]
> [5,6,7]
> 
> [1,3,2]
> [4]
> 
> [1,5,4,10,9,20]
> [4,6,9,10,14]
> 
> [10,1,12,2,5]
> [1,2,3,4,11,13,14]
> 
> [1,2,3,4,6]
> [5]
> ```

其他解法：

设 $dp_{i,j}$ 表示前 $i$ 个元素替换了 $j$ 次后末尾元素的最小值。

- 若 $a_i$ 保留，则必须严格大于前 $i-1$ 个元素，即 $a_i > dp_{i-1,j}$
- 若 $a_i$ 替换，换了一定要大于前 $i-1$ 个元素，即 $v > dp_{i-1,j-1}$，找到 $b$ 里大于其的最小元素进行替换即可

方便起见，初始设 $dp=\infty,dp_{0,0}=-\infty$。

```c++
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        int n = arr1.size();
        int m = arr2.size();
        vector<vector<int>> dp(n + 1, vector<int>(min(m, n) + 1, INF));
        dp[0][0] = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= min(i, m); j++) {
                /* 如果当前元素大于序列的最后一个元素 */
                if (arr1[i - 1] > dp[i - 1][j]) {
                    dp[i][j] = arr1[i - 1];
                }
                if (j > 0 && dp[i - 1][j - 1] != INF) {
                    /* 查找严格大于 dp[i - 1][j - 1] 的最小元素 */
                    auto it = upper_bound(arr2.begin(), arr2.end(), dp[i - 1][j - 1]);//也可以begin+j-1,因为前j-1次一定消耗掉了不能反复用
                    if (it != arr2.end()) {
                        dp[i][j] = min(dp[i][j], *it);
                    }
                }
                if (i == n && dp[i][j] != INF) {
                    return j;
                }
            }
        }
        return -1;
    }
};
```

而对自己想出的那个状态，还可以继续优化，每个 i 只一次二分：

```c++
constexpr int INF = 0x3f3f3f3f;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        /* 右侧哨兵 inf */
        arr1.push_back(INF); 
        /* 左侧哨兵 -1 */
        arr1.insert(arr1.begin(), -1); 
        int n = arr1.size();
        int m = arr2.size();

        vector<int> dp(n, INF);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            /* arr1[i] 左侧的元素不进行替换 */
            if (arr1[i - 1] < arr1[i]) {
                dp[i] = min(dp[i], dp[i - 1]);
            }
            /* 固定替换元素的右侧终点 */
            int k = lower_bound(arr2.begin(), arr2.end(), arr1[i]) - arr2.begin();
            /* 枚举从 i 左侧连续替换元素的个数 */
            for (int j = 1; j <= min(i - 1, k); ++j) {
                /* 替换的连续 j 个元素的左侧起点需满足大于 arr1[i - j - 1] */ 
                if (arr1[i - j - 1] < arr2[k - j]) {
                    dp[i] = min(dp[i], dp[i - j - 1] + j);
                }
            }
        }
        return dp[n - 1] == INF ? -1 : dp[n - 1];
    }
};
```



##### 1027\.最长等差数列

[题目](https://leetcode.cn/problems/longest-arithmetic-subsequence/)

枚举每个公差，然后用桶优化，存下每个结尾的最长等差子序列。

```java
class Solution {
    public int longestArithSeqLength(int[] nums) {
        int n = nums.length, cnt[] = new int[501], ans = 2;
        for (int d = -500; d <= 500; ++d) {
            for (int i = 0; i < n; ++i) {
                cnt[nums[i]] = 0;
            }
            for (int i = 0; i < n; ++i) {
                if (nums[i] - d >= 0 && nums[i] - d <= 500) {
                    cnt[nums[i]] = Math.max(cnt[nums[i]], cnt[nums[i] - d] + 1);
                } else {
                    cnt[nums[i]] = Math.max(cnt[nums[i]], 1);
                }
            }
            for (int i = 0; i < n; ++i) {
                ans = Math.max(ans, cnt[nums[i]]);
            }
        }
        return ans;
    }
}
```

优雅写法：

```java
class Solution {
    public int longestArithSeqLength(int[] nums) {
        int minv = Arrays.stream(nums).min().getAsInt();
        int maxv = Arrays.stream(nums).max().getAsInt();
        int diff = maxv - minv;
        int ans = 1;
        for (int d = -diff; d <= diff; ++d) {
            int[] f = new int[maxv + 1];
            Arrays.fill(f, -1);
            for (int num : nums) {
                int prev = num - d;
                if (prev >= minv && prev <= maxv && f[prev] != -1) {
                    f[num] = Math.max(f[num], f[prev] + 1);
                    ans = Math.max(ans, f[num]);
                }
                f[num] = Math.max(f[num], 1);
            }
        }
        return ans;
    }
}
```



##### 1105\.填充书架

[题目](https://leetcode.cn/problems/filling-bookcase-shelves/)

比较显然的 DP。

```java
class Solution {
    public int minHeightShelves(int[][] a, int w) {
        int n = a.length, dp[] = new int[n + 1];
        for (int i = 1; i <= n; ++i) {
            int cnt = a[i - 1][0], h = a[i - 1][1];
            dp[i] = dp[i - 1] + h;
            for (int j = i - 1; j >= 1; --j) {
                cnt += a[j - 1][0];
                if (cnt > w) {
                    break;
                }
                h = Math.max(h, a[j - 1][1]);
                dp[i] = Math.min(dp[i], dp[j - 1] + h);
            }
        }
        return dp[n];
    }
}
```



##### 1163\.按字典序排在最后的子串

[题目](https://leetcode.cn/problems/last-substring-in-lexicographical-order/)

字典序最大的子串一定是一个后缀。因为如果找到了一个非后缀的子串，一定可以不断向后扩展该子串，使得该子串更大，最终成为后缀。因此只需要求出最大的后缀即可。

使用后缀数组/后缀自动机可以完成该目标。以后缀数组为例，只需要求出 `sa[n]` 的序号，然后输出该序号的后缀即可。倍增法后缀数组复杂度为 $O(n\log n)$，可以用 SA-IS 或 3DC 法优化为 $O(n)$(这里懒，不优化了)，后缀自动机的话复杂度直接就是 $O(n)$。

```java
import java.util.Arrays;

class SuffixArray {
    public int m = 300, p, n;
    public int[] cnt, rk, sa, id, px, oldrk;

    boolean cmp(int x, int y, int w) {
        return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
    }

    public SuffixArray(String s) {
        n = s.length();
        cnt = new int[m + 1];
        rk = new int[n + 1];
        sa = new int[n + 1];
        id = new int[n + 1];
        px = new int[n + 1];
        oldrk = new int[2 * (n + 1)];
        for (int i = 1; i <= n; ++i) {
            ++cnt[rk[i] = s.charAt(i - 1)];
        }
        for (int i = 1; i <= m; ++i) {
            cnt[i] += cnt[i - 1];
        }
        for (int i = n; i >= 1; --i) {
            sa[cnt[rk[i]]--] = i;
        }
        for (int w = 1, i;; w <<= 1, m = p) {
            for (p = 0, i = n; i > n - w; --i) {
                id[++p] = i;
            }
            for (int j = 1; j <= n; ++j) {
                if (sa[j] > w) {
                    id[++p] = sa[j] - w;
                }
            }
            Arrays.fill(cnt, 0);
            for (int j = 1; j <= n; ++j) {
                ++cnt[px[j] = rk[id[j]]];
            }
            for (int j = 1; j <= m; ++j) {
                cnt[j] += cnt[j - 1];
            }
            for (int j = n; j >= 1; --j) {
                sa[cnt[px[j]]--] = id[j];
            }
            for (int j = 0; j <= n; ++j) {
                oldrk[j] = rk[j];
            }
            for (p = 0, i = 1; i <= n; ++i) {
                rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
            }
            if (p == n) {
                for (int j = 1; j <= n; ++j) {
                    sa[rk[j]] = j;
                }
                break;
            }
            cnt = new int[p + 1];
        }
    }
}

class Solution {
    public String lastSubstring(String s) {
        SuffixArray sa = new SuffixArray(s);
        int biggest = sa.sa[s.length()];
        return s.substring(biggest - 1);
    }
}
```

更优解：双指针。

```java
class Solution {
    public String lastSubstring(String s) {
        int n = s.length();
        int i = 0;//当前最长子串起点,j是候选起点
        for (int j = 1, k = 0; j + k < n;) {
            int d = s.charAt(i + k) - s.charAt(j + k);
            if (d == 0) {//[i,i+k]==[j,j+k]都是同一个字母
                ++k;
            } else if (d < 0) {//既然都是同一个字母,那么这些字母对应的后缀都丢了
                i += k + 1;
                k = 0;
                //yedcbazaaa i=y,j=z,k=0 -> i=e while to i=z,j=a
                if (i >= j) {
                    j = i + 1;
                }
            } else {
                //zbzazc -> j=b -> j=a then above i=z1 i=z2 i=z3,j=c
                j += k + 1;
                k = 0;
            }
        }
        return s.substring(i);
    }
}
```



##### 1031\.两个非重叠子数组的最大和

[题目](https://leetcode.cn/problems/maximum-sum-of-two-non-overlapping-subarrays/)

前缀和直接枚举全体方案即可。

```java
class Solution {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        int n = nums.length, s[] = new int[n + 1], ans = 0;
        for (int i = 1; i <= n; ++i) {
            s[i] += s[i - 1] + nums[i - 1];
        }
        for (int i = 1; i + firstLen - 1 <= n; ++i) {
            for (int j = 1; j + secondLen - 1 <= n; ++j) {
                if (j > i + firstLen - 1 || j + secondLen - 1 < i) {
                    int res = s[i + firstLen - 1] - s[i - 1];
                    res += s[j + secondLen - 1] - s[j - 1];
                    ans = Math.max(ans, res);
                }
            }
        }
        return ans;
    }
}
```

假设第一段总是在第二段前边(否则，可以交换两个 Len 再跑一次)，维护 suml 为当前第一段的和，sumr 是当前第二段的和，维护有史以来最大的 suml，然后让其加上 sumr。

```java
class Solution {
    public int maxSumTwoNoOverlap(int[] nums, int firstLen, int secondLen) {
        return Math.max(help(nums, firstLen, secondLen), help(nums, secondLen, firstLen));
    }

    public int help(int[] nums, int firstLen, int secondLen) {
        int suml = 0;
        for (int i = 0; i < firstLen; ++i) {
            suml += nums[i];
        }
        int maxSumL = suml;
        int sumr = 0;
        for (int i = firstLen; i < firstLen + secondLen; ++i) {
            sumr += nums[i];
        }
        int res = maxSumL + sumr;
        for (int i = firstLen + secondLen, j = firstLen; i < nums.length; ++i, ++j) {
            suml += nums[j] - nums[j - firstLen];
            maxSumL = Math.max(maxSumL, suml);
            sumr += nums[i] - nums[i - secondLen];
            res = Math.max(res, maxSumL + sumr);
        }
        return res;
    }
}d
```



##### 1048\.最长字符串链

[题目](https://leetcode.cn/problems/longest-string-chain/)

比题解更优复杂度的拓扑排序DP。

前身关系可以建一张 DAG，枚举每个字符串，遍历删掉每个字符得到的子串，然后查询该子串是否在 words 出现过(如果重复出现任取一个)，若出现过。连一条有向边，设字符串有 $n$ 个，每个长度为 $m$，则建图的复杂度是 $O(nm^2)$，空间复杂度也是 $O(nm)$(考虑 hashmap 预处理优化查询)。

在这之后，对建好的图，初始化每个点的最长单词链为 $dp_i=1$，拓扑序转移，对每个节点 $u$，设子节点为 $v$，则转移方程为 $dp_u=\max dp_v+1$。跑拓扑序的时空复杂度均为 $O(n)$(用下标表示节点，而不是用字符串表示)。

因此总时空复杂度取建图复杂度，为 $O(nm^2)$。

```java
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.HashMap;

class Solution {
    public int longestStrChain(String[] words) {
        int n = words.length;
        int[] ru = new int[n], dp = new int[n];
        @SuppressWarnings("unchecked")
        ArrayList<Integer> g[] = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            g[i] = new ArrayList<>();
            dp[i] = 1;
        }
        HashMap<String, Integer> m = new HashMap<>();
        for (int i = 0; i < n; ++i) {
            m.put(words[i], i);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0, je = words[i].length(); j < je; ++j) {
                String s = words[i].substring(0, j) + words[i].substring(j + 1);
                Integer k = m.get(s);
                if (k != null) {
                    g[k].add(i);
                    ++ru[i];
                }
            }
        }
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < n; ++i) {
            if (ru[i] == 0) {
                q.addLast(i);
            }
        }
        int ans = 1;
        while (!q.isEmpty()) {
            int u = q.pollFirst();
            for (int v : g[u]) {
                dp[v] = Math.max(dp[v], dp[u] + 1);
                ans = Math.max(ans, dp[v]);
                if (--ru[v] == 0) {
                    q.addLast(v);
                }
            }
        }
        return ans;
    }
}
```

题解的不建图排序 DP，按长度排序 $O(n\log n)$，排序后不断存 map，空间 $O(nm)$，枚举每个串的子串为 $O(nm^2)$。

```java
class Solution {
    public int longestStrChain(String[] words) {
        Map<String, Integer> cnt = new HashMap<String, Integer>();
        Arrays.sort(words, (a, b) -> a.length() - b.length());
        int res = 0;
        for (String word : words) {
            cnt.put(word, 1);
            for (int i = 0; i < word.length(); i++) {
                String prev = word.substring(0, i) + word.substring(i + 1);
                if (cnt.containsKey(prev)) {
                    cnt.put(word, Math.max(cnt.get(word), cnt.get(prev) + 1));
                }
            }
            res = Math.max(res, cnt.get(word));
        }
        return res;
    }
}
```

后缀自动机，复杂度为 $O(\sum|s|)$。

字符串 t 是 s 的前身，相当于字符串 t 可以被分割为两部分，且两部分分别是 s 的前缀和后缀。令 $rep(s)=s+\#+s$，若是 $t$ 是 $s$ 的前身，则 $rep(t)$ 和 $rep(s)$ 有长为 $|s|$  的公共子串(即 原串后缀+`#`+原串前缀 组成的子串)。

按长度顺序处理 DP，每次处理所有同长字符串，将 DP 值存入 SAM。之后看不懂了。[参考](https://leetcode.cn/problems/longest-string-chain/solution/zi-fu-chuan-geng-chang-shi-de-onmjie-fa-bjk1b/)



##### 1172\.餐盘栈

[题目](https://leetcode.cn/problems/dinner-plate-stacks/)

维护栈套栈，具体而言，将每个栈用列表连接起来，然后开 tree set 有序维护列表里不满的栈的下标。则对每个操作：

1. `push`。取不满的第一个栈插入，并更新 tree set
2. `popAtStack`。做完边界/有效性特判后，删掉指定栈顶，更新 tree set
3. `pop`。不断取列表尾(栈套栈的外层栈顶)，如果空就弹掉，这样就避免了再维护多一个 tree set 区分空和不满。

不需要维护满的栈下标，因为上述操作用不到。只需要维护未满即可。

均摊每次操作时间复杂度取 tree set 复杂度 $O(\log n)$，总空间复杂度 $O(n)$。

```java
import java.util.ArrayList;
import java.util.TreeSet;

class DinnerPlates {
    int c;
    TreeSet<Integer> full, avail;
    ArrayList<ArrayList<Integer>> s;

    public DinnerPlates(int capacity) {
        c = capacity;
        full = new TreeSet<>();
        avail = new TreeSet<>();
        s = new ArrayList<>();
    }

    public void push(int val) {
        if (avail.isEmpty()) {
            avail.add(s.size());
            s.add(new ArrayList<>());
        }
        int i = avail.first();
        s.get(i).add(val);
        if (s.get(i).size() == c) {
            avail.remove(i);
            full.add(i);
        } else {
            avail.add(i);
        }
    }

    public int pop() {
        while (!s.isEmpty() && s.get(s.size() - 1).size() == 0) {
            avail.remove(s.size() - 1);
            s.remove(s.size() - 1);
        }
        return popAtStack(s.size() - 1);
    }

    public int popAtStack(int index) {
        if (s.isEmpty() || index >= s.size()) {
            return -1;
        }
        ArrayList<Integer> lt = s.get(index);
        if (lt.isEmpty()) {
            return -1;
        }
        int val = lt.get(lt.size() - 1);
        lt.remove(lt.size() - 1);
        full.remove(index);
        avail.add(index);
        return val;
    }
}
```

题解写的是什么乱七八糟不想看。



##### 2423\.删除字符使频率相同

[题目]()

自己的n方暴力和假贪心：

```java
class Solution {
    public boolean equalFrequency(String word) {
        int n = word.length();
        for (int i = 0; i < n; ++i) {
            String s = word.substring(0, i) + word.substring(i + 1);
            int cnt[] = new int[26];
            for (int c : s.getBytes()) {
                cnt[c - 'a']++;
            }
            boolean avail = true;
            for (int j = 0, bf = 0; j < 26; ++j) {
                if (cnt[j] > 0) {
                    if (bf != 0 && bf != cnt[j]) {
                        avail = false;
                    }
                    bf = cnt[j];
                }
            }
            if (avail) {
                return true;
            }
        }
        return false;
    }
}
/*
"bac"
"bb"
"ba"
"aazz"
"abcc"
"aab"
"azaz"
"aabbccb"
"abbcc"
"abcdee"
"cbccca"
 */
```

归纳结论：

```java
class Solution {
   public boolean equalFrequency(String word) {
       int cnt[] = new int[26], n = word.length();
       for (int i = 0; i < n; ++i) {
           cnt[word.charAt(i) - 'a']++;
       }
       TreeMap<Integer, Integer> m = new TreeMap<>();
       for (int i = 0; i < 26; ++i) {
           if (cnt[i] > 0) {
               m.put(cnt[i], m.getOrDefault(cnt[i], 0) + 1);
           }
       }
       if (m.size() == 1) {// bb | abc
           return m.firstEntry().getValue() == 1 || m.firstKey() == 1;
       }
       if (m.size() != 2) {
           return false;
       }
       // abbbccc | aabbcczzz
       return (m.firstKey() == 1 && m.firstEntry().getValue() == 1) ||
            (m.lastEntry().getValue() == 1 && m.lastKey() - m.firstKey() == 1);
   }
}
```

一种枚举优化：将原串转cnt数组，枚举删掉每个字符，然后统计字符集

```java
class Solution {
    public boolean equalFrequency(String word) {
        int[] charCount = new int[26];
        int n = word.length();
        for (int i = 0; i < n; i++) {
            charCount[word.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (charCount[i] == 0) {
                continue;
            }
            charCount[i]--;
            HashSet<Integer> frequency = new HashSet<Integer>();
            for (int f : charCount) {
                if (f > 0) {
                    frequency.add(f);
                }
            }
            if (frequency.size() == 1) {
                return true;
            }
            charCount[i]++;
        }
        return false;
    }
}
```

来点继续优化：

```java
class Solution {
    public boolean equalFrequency(String word) {
        int[] charCount = new int[26];
        for (char c : word.toCharArray()) {
            charCount[c - 'a']++;
        }
        Map<Integer, Integer> freqCount = new HashMap<>();
        for (int c : charCount) {
            if (c > 0) {
                freqCount.put(c, freqCount.getOrDefault(c, 0) + 1);
            }
        }
        for (int c : charCount) {
            if (c == 0) {
                continue;
            }
            freqCount.put(c, freqCount.get(c) - 1);
            if (freqCount.get(c) == 0) {
                freqCount.remove(c);
            }
            if (c - 1 > 0) {
                freqCount.put(c - 1, freqCount.getOrDefault(c - 1, 0) + 1);
            }
            if (freqCount.size() == 1) {
                return true;
            }
            if (c - 1 > 0) {
                freqCount.put(c - 1, freqCount.get(c - 1) - 1);
                if (freqCount.get(c - 1) == 0) {
                    freqCount.remove(c - 1);
                }
            }
            freqCount.put(c, freqCount.getOrDefault(c, 0) + 1);
        }
        return false;
    }
}
```



##### 1003\.检查替换后的词是否有效

[题目](https://leetcode.cn/problems/check-if-word-is-valid-after-substitutions/)

贪心，不断删 abc，一定不会更差。

列表比较快：

```java
import java.util.ArrayList;

class Solution {
    public boolean isValid(String s) {
        ArrayList<Character> a = new ArrayList<>();
        for (byte c : s.getBytes()) {
            a.add((char) c);
            while (a.size() >= 3 && a.get(a.size() - 1) == 'c') {
                if (a.get(a.size() - 2) == 'b' && a.get(a.size() - 3) == 'a') {
                    for (int i = 0; i < 3; ++i) {
                        a.remove(a.size() - 1);
                    }
                } else {
                    break;
                }
            }
        }
        return a.size() == 0;
    }
}
```

sb 比较慢：

```java
class Solution {
    public boolean isValid(String s) {
        StringBuilder stk = new StringBuilder();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            stk.append(c);
            if (stk.length() >= 3 && stk.substring(stk.length() - 3).equals("abc")) {
                stk.delete(stk.length() - 3, stk.length());
            }
        }
        return stk.isEmpty();
    }
}
```



##### 2106\.摘水果

[题目](https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps/)

前缀和枚举所有走 k 步的方案：①只往左/往右；②先左后右；③先右后左。其他方案一定不会比上述方案更优。

```java
class Solution {
    private int s[], m, n;

    private int sum(int l, int r) {
        l = Math.max(0, Math.min(m, l));
        r = Math.max(0, Math.min(m, r));
        return s[r + 1] - s[l];
    }

    public int maxTotalFruits(int[][] fruits, int a, int k) {
        n = fruits.length;
        m = Math.max(a, fruits[n - 1][0]);
        s = new int[m + 2];
        for (int i = 0; i < n; ++i) {
            s[fruits[i][0] + 1] += fruits[i][1];
        }
        for (int i = 1; i <= m + 1; ++i) {
            s[i] += s[i - 1];
        }
        int ans = sum(a, a + k);
        ans = Math.max(ans, sum(a - k, a));
        for (int l = 1; a - l >= 0 && 2 * l <= k; ++l) {
            int r = k - 2 * l;
            ans = Math.max(ans, sum(a - l, a + r));
        }
        for (int r = 1; a + r <= m && 2 * r <= k; ++r) {
            int l = k - 2 * r;
            ans = Math.max(ans, sum(a - l, a + r));
        }
        return ans;
    }
}
```

也可以离散化前缀和，那么查询要用二分。就是省空间不剩时间了。

```java
class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int n = fruits.length;
        int[] sum = new int[n + 1];
        int[] indices = new int[n];
        sum[0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + fruits[i][1];
            indices[i] = fruits[i][0];
        }
        int ans = 0;
        for (int x = 0; x <= k / 2; x++) {
            /* 向左走 x 步，再向右走 k - x 步 */
            int y = k - 2 * x;
            int left = startPos - x;
            int right = startPos + y;
            int start = lowerBound(indices, 0, n - 1, left);
            int end = upperBound(indices, 0, n - 1, right);
            ans = Math.max(ans, sum[end] - sum[start]);
            /* 向右走 x 步，再向左走 k - x 步 */
            y = k - 2 * x;
            left = startPos - y;
            right = startPos + x;
            start = lowerBound(indices, 0, n - 1, left);
            end = upperBound(indices, 0, n - 1, right);
            ans = Math.max(ans, sum[end] - sum[start]);
        }
        return ans;
    }

    public int lowerBound(int[] arr, int left, int right, int val) {
        int res = right + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= val) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }

    public int upperBound(int[] arr, int left, int right, int val) {
        int res = right + 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > val) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
}
```

优化成 $O(2n)$ 时间和 $O(1)$ 的滑窗：

对一个固定的区间 $[l,r]$，求出走完该区间所需的步数，有：

1. 如果起点 $p$ 在区间右，要走 $p-l$ 步

2. 如果起点 $p$ 在区间左，要走 $r-p$ 步

3. 否则，先左后右，要走 $p-l+r-l$ 步

4. 否则，先右后左，要走 $r-p+r-l$ 步

   第三第四种情况合并为 $r-l+\min(r-p,p-l)$

   加上绝对值时，即 $r-l+\min(|r-p|,|p-l|)$，第三第四不变，

   对第一，有 $\min$ 取 $p-r$，得 $r-l+p-r=p-l$

   对第二，有 $\min$ 取 $l-p$，得 $r-l+l-p=r-p$

综上，$r-l+\min(|r-p|,|p-l|)$ 能覆盖全部情况，简写为 $f(l,r)$

若 $r$ 不变，$l$ 减少，作差得：
$$
f(l,r)-f(l-1,r)=-1+\min(|r-p|,|p-l|)-\min(|r-p|,|p-l+1|)
$$
如果 $p\le l$，最值肯定都不取 $|r-p|$，通常有 $-1+l-p-(l-1-p)=0$，当且仅当 $p=l$ 取 $-1+0-1=-2$。

若 $l < p$，如果都取 $|r-p|$，得 $-1$。否则，如果能取 $|p-l|$ 也能取 $|p-l+1|$，由上述得 $0$，否则取 $|r-p|-|p-l|$，必然满足 $|p-l+1|=|r-p|$ 也得 $-1$。

综上，有 $f(l,r)\ge f(l-1,r)$。即论证了滑窗的可行性。也就是严格论证了越长的区间步数越大这一显然结论。

区间越长肯定越好。故初始化 $l=r=0$，不断移动 $r$，当超出步数时，缩减 $l$。

```java
class Solution {
    public int maxTotalFruits(int[][] fruits, int startPos, int k) {
        int left = 0;
        int right = 0;
        int n = fruits.length;
        int sum = 0;
        int ans = 0;
        // 每次固定住窗口右边界
        while (right < n) {
            sum += fruits[right][1];
            // 移动左边界
            while (left <= right && step(fruits, startPos, left, right) > k) {
                sum -= fruits[left][1];
                left++;
            }
            ans = Math.max(ans, sum);
            right++;
        }
        return ans;
    }

    public int step(int[][] fruits, int startPos, int left, int right) {
        return Math.min(Math.abs(startPos - fruits[right][0]), Math.abs(startPos - fruits[left][0])) + fruits[right][0] - fruits[left][0];
    }
}
```

 

##### 1419\.数青蛙

[题目](https://leetcode.cn/problems/minimum-number-of-frogs-croaking/)

模拟多线程，用较优复杂度给每个线程分配任务。不能一遍遍扫，只能扫一遍，考虑 `c...r...o...a...k...` 会卡到 $n^2$。个人实现：

```java
class Solution {
    public int minNumberOfFrogs(String s) {
        int cnt[] = new int[5], ans = 0;
        byte[] t = new byte[] { 'c', 'r', 'o', 'a', 'k' };
        int[] p = new int[128];
        for (int i = 0; i < 5; ++i) {
            p[t[i]] = i;
        }
        for (byte c : s.getBytes()) {
            int i = p[c], sum = 0;
            if (i == 0) {
                ++cnt[i];
            } else if (cnt[i - 1] > 0) {
                --cnt[i - 1];
                ++cnt[i];
            } else {
                return -1;
            }
            for (int j = 0; j < 5; ++j) {
                sum += cnt[j];
            }
            ans = Math.max(ans, sum);
            if (i == 4) {
                --cnt[i];
            }
        }
        for (int i = 0; i < 4; ++i) {
            if (cnt[i] != 0) {
                return -1;
            }
        }
        return ans;
    }
}
```

更优实现(少一个 for，理论上快五倍但实践上不如我的快)

```java
class Solution {
    public int minNumberOfFrogs(String croakOfFrogs) {
        if (croakOfFrogs.length() % 5 != 0) {
            return -1;
        }
        int res = 0, frogNum = 0;
        int[] cnt = new int[4];
        Map<Character, Integer> map = new HashMap<Character, Integer>() {{
            put('c', 0);
            put('r', 1);
            put('o', 2);
            put('a', 3);
            put('k', 4);
        }};
        for (int i = 0; i < croakOfFrogs.length(); i++) {
            char c = croakOfFrogs.charAt(i);
            int t = map.get(c);
            if (t == 0) {
                cnt[t]++;
                frogNum++;
                if (frogNum > res) {
                    res = frogNum;
                }
            } else {
                if (cnt[t - 1] == 0) {
                    return -1;
                }
                cnt[t - 1]--;
                if (t == 4) {
                    frogNum--;
                } else {
                    cnt[t]++;
                }
            }
        }
        if (frogNum > 0) {
            return -1;
        }
        return res;
    }
}
```



##### 1010\.总持续时间可被60整除的歌曲

[题目](https://leetcode.cn/problems/pairs-of-songs-with-total-durations-divisible-by-60/)

直接枚举：

```java
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int cnt[] = new int[60], n = time.length, ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += cnt[(60 - time[i] % 60) % 60];
            ++cnt[time[i] % 60];
        }
        return ans;
    }
}
```

遍历完计数再枚举：

```java
class Solution {
    public int numPairsDivisibleBy60(int[] time) {
        int[] cnt = new int[60];
        for (int t : time) {
            cnt[t % 60]++;
        }
        long res = 0;
        for (int i = 1; i < 30; i++) {
            res += cnt[i] * cnt[60 - i];
        }
        res += (long) cnt[0] * (cnt[0] - 1) / 2 + (long) cnt[30] * (cnt[30] - 1) / 2;
        return (int) res;
    }
}
```



##### 1263\.推箱子

[题目](https://leetcode.cn/problems/minimum-moves-to-move-a-box-to-their-target-location/)

空间更优的解法。BFS 套 BFS。所有状态为：当前箱子位置+玩家相对箱子的四方向位置，共 $4nm$ 个状态。所以外层 BFS 的存储状态为：箱子位置+玩家位置+已经推动的次数。每次遍历时，对当前玩家位置，再进行一次内层 BFS，以求出箱子的四个相对位置玩家是否可达，如果可达，就尝试推一次。时间复杂度为 $O(4n^2m^2)$，空间复杂度为 $O(4nm)$。

```java
import java.util.ArrayDeque;

class Solution {
    int n, m, ex, ey, bx, by, px, py;
    int[] dx = { -1, 0, 1, 0 }, dy = { 0, -1, 0, 1 };
    boolean reach[][], vis[][][];
    char g[][];

    private boolean in(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    private void updateReachable() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                reach[i][j] = false;
            }
        }
        ArrayDeque<Integer[]> q = new ArrayDeque<>();
        q.addLast(new Integer[] { px, py });
        while (!q.isEmpty()) {
            Integer[] tm = q.pollFirst();
            int ax = tm[0], ay = tm[1];
            if (reach[ax][ay]) {
                continue;
            }
            reach[ax][ay] = true;
            for (int i = 0; i < 4; ++i) {
                int nx = ax + dx[i], ny = ay + dy[i];
                if (in(nx, ny) && g[nx][ny] != '#' && !(nx == bx && ny == by)) {
                    q.addLast(new Integer[] { nx, ny });
                }
            }
        }
    }

    public int minPushBox(char[][] grid) {
        n = grid.length;
        m = grid[0].length;
        g = grid;
        reach = new boolean[n][m];
        vis = new boolean[n][m][4];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 'T') {
                    ex = i;
                    ey = j;
                } else if (grid[i][j] == 'B') {
                    bx = i;
                    by = j;
                } else if (grid[i][j] == 'S') {
                    px = i;
                    py = j;
                }
            }
        }
        ArrayDeque<Integer[]> q = new ArrayDeque<>();
        q.addLast(new Integer[] { bx, by, px, py, 0 });
        while (!q.isEmpty()) {
            Integer[] tm = q.pollFirst();
            bx = tm[0];
            by = tm[1];
            if (bx == ex && by == ey) {
                return tm[4];
            }
            px = tm[2];
            py = tm[3];
            updateReachable();
            for (int i = 0; i < 4; ++i) {
                int qx = bx + dx[i], qy = by + dy[i];
                if (in(qx, qy) && reach[qx][qy] && !vis[bx][by][i]) {
                    int cx = bx - dx[i], cy = by - dy[i];
                    if (in(cx, cy) && g[cx][cy] != '#') {
                        vis[bx][by][i] = true;
                        q.addLast(new Integer[] { cx, cy, bx, by, tm[4] + 1 });
                    }
                }
            }
        }
        return -1;
    }
}
```

一种时间更优但空间更劣的办法：

```java
class Solution {
    public int minPushBox(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        int sx = -1, sy = -1, bx = -1, by = -1; // 玩家、箱子的初始位置
        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (grid[x][y] == 'S') {
                    sx = x;
                    sy = y;
                } else if (grid[x][y] == 'B') {
                    bx = x;
                    by = y;
                }
            }
        }

        int[] d = {0, -1, 0, 1, 0};

        int[][] dp = new int[m * n][m * n];
        for (int i = 0; i < m * n; i++) {
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        Queue<int[]> queue = new ArrayDeque<int[]>();
        dp[sx * n + sy][bx * n + by] = 0; // 初始状态的推动次数为 0
        queue.offer(new int[]{sx * n + sy, bx * n + by});
        while (!queue.isEmpty()) {
            Queue<int[]> queue1 = new ArrayDeque<int[]>();
            while (!queue.isEmpty()) {
                int[] arr = queue.poll();
                int s1 = arr[0], b1 = arr[1];
                int sx1 = s1 / n, sy1 = s1 % n, bx1 = b1 / n, by1 = b1 % n;
                if (grid[bx1][by1] == 'T') { // 箱子已被推到目标处
                    return dp[s1][b1];
                }
                for (int i = 0; i < 4; i++) { // 玩家向四个方向移动到另一个状态
                    int sx2 = sx1 + d[i], sy2 = sy1 + d[i + 1], s2 = sx2*n+sy2;
                    if (!ok(grid, m, n, sx2, sy2)) { // 玩家位置不合法
                        continue;
                    }
                    if (bx1 == sx2 && by1 == sy2) { // 推动箱子
                        int bx2 = bx1 + d[i], by2 = by1 + d[i + 1], b2 = bx2*n+by2;
                        if (!ok(grid, m, n, bx2, by2) || dp[s2][b2] <= dp[s1][b1] + 1) { // 箱子位置不合法 或 状态已访问
                            continue;
                        }
                        dp[s2][b2] = dp[s1][b1] + 1;
                        queue1.offer(new int[]{s2, b2});
                    } else {
                        if (dp[s2][b1] <= dp[s1][b1]) { // 状态已访问
                            continue;
                        }
                        dp[s2][b1] = dp[s1][b1];
                        queue.offer(new int[]{s2, b1});
                    }
                }
            }
            queue = queue1;
        }
        return -1;
    }

    public boolean ok(char[][] grid, int m, int n, int x, int y) { // 不越界且不在墙上
        return x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != '#';
    }
}
```



##### 1015\.可被k整除的最小整数

[题目](https://leetcode.cn/problems/smallest-integer-divisible-by-k/)

我的暴力，思路模仿天梯赛一道20分题-整除光棍。

```java
class Solution {
    public int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) {
            return -1;
        }
        int cnt = 0, s = 0, p = 1;
        do {
            s = (s + p % k) % k;
            ++cnt;
            p = p * 10 % k;
        } while (s != 0);
        return cnt;
    }
}
```

前置知识：四则运算取模定理、费马小定理、欧拉定理等。

即求最小长度 $n$ 满足 $\sum_{i=0}^{n-1}10^i\equiv0\pmod k$。

根据乘法取模公式容易得知，只要 $10^i\equiv 10^j\pmod k$，其中 $i < j$，那么一定可以用 $10^i$ 替换 $10^j$，从而使得任意 $10^{i+k}$ 与 $10^{j+k}$ 等价，即一个循环节长度为 $j-i$(不一定是最短循环节，如 $x$ 是循环长度的话任意整数 $cx$ 都是循环长度)。根据费马小定理，对任意整数 $a$ 有 $a^k\equiv a\pmod k$，代入 $10$，可知一个循环节的长度是 $k-1$。

> 到这里其实已经可以暴力套取模公式了，即只需要运算 $k-1$ 次，如果还没到 $0$ 必然无解，否则一旦到 $0$ 就输出。

更优雅解法：$\overline{111\cdots1}=\dfrac{10^n-1}9$，因为是整数，所以必然有 $9|(10^n-1)$，也可以用等比数列证，当 $n|k$ 时，等价于 $10^n\equiv 1\pmod{9k}$，根据欧拉定理，求出 $\varphi(9k)$ 是一个循环节，然后枚举 $\varphi(9k)$  的所有因子 $d$，快速幂求出是否 $10^d\equiv 1\pmod{9k}$ 即可。求欧拉函数和枚举所有因子(不是质因子)的复杂度都是  $O(\sqrt k)$，枚举后要上快速幂，故总复杂度为 $O(\log k\sqrt k)$。当然，如果枚举后一个都不为 $1$，就证明无解了。

下面证明若 $2|k$ 或 $5|k$(即 $k$ 含因数 $2$ 或 $5$，也可以表示成 $\gcd(10,k)\neq 1$)必然无解，其他情况$(\gcd(10,k)= 1)$必然有解。

因为成循环节，所以必然有同余的 $a=\dfrac{10^x-1}{9},b=\dfrac{10^y-1}{9},a > b$，其中同余意味着 $k|(a-b)$，作差得 $a-b=\dfrac{10^x-10^y}9=10^y\dfrac{10^{x-y}-1}9$ 。如果 $k$ 没有因子 $2$ 或 $5$，要满足 $k|(a-b)$，只能让 $k|\dfrac{10^{x-y}-1}9$，即 $\dfrac{10^{x-y}-1}9\equiv 0\pmod k$，这意味着 $n=x-y$ 是可行解。

否则，可以整除 $10^y$， 

```java
class Solution {
    public int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0)
            return -1;
        int m = phi(k * 9);
        // 从小到大枚举不超过 sqrt(m) 的因子
        int i = 1;
        for (; i * i <= m; i++)
            if (m % i == 0 && pow(10, i, k * 9) == 1)
                return i;
        // 从小到大枚举不低于 sqrt(m) 的因子
        for (i--; ; i--)
            if (m % i == 0 && pow(10, m / i, k * 9) == 1)
                return m / i;
    }

    // 计算欧拉函数（n 以内的与 n 互质的数的个数）
    private int phi(int n) {
        int res = n;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                res = res / i * (i - 1);
                while (n % i == 0) n /= i;
            }
        }
        if (n > 1)
            res = res / n * (n - 1);
        return res;
    }

    // 快速幂，返回 pow(x, n) % mod
    private long pow(long x, int n, long mod) {
        long res = 1;
        for (; n > 0; n /= 2) {
            if (n % 2 > 0) res = res * x % mod;
            x = x * x % mod;
        }
        return res;
    }
}
```



##### 1016\.子串能表示从 1 到 N 数字的二进制串

[链接]((https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/))

手玩发现如果要包含全体连续正整数，字符串长度会很长，根据构造直觉，可知 n 很快无法完全覆盖，故想过直接枚举每个数字转二进制然后开字符串哈希/KMP判是否在字符串内。

然后想到既然判是否在字符串内了，字符串又这么短，何不直接预处理每个字符串子串，然后存 hash 表，然后枚举 hash 表看看是否前 n 个数都在表内即可，因此，时空复杂度为 $O(|s|^2)$。

```java
class Solution {
    public boolean queryString(String s, int n) {
        HashSet<Integer> h = new HashSet<>();
        byte[] b = s.getBytes();
        for (int i = 0, ie = s.length(); i < ie; ++i) {
            int v = 0;
            for (int j = i; j < ie; ++j) {
                v = v * 2 + b[j] - '0'; //注意没处理溢出,可能会被hack
                h.add(v);
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!h.contains(i)) {
                return false;
            }
        }
        return true;
    }
}
```

枚举优化：$O(|s|\log n)$，内层只需要枚举到不超过 $n$ 即可。

```java
class Solution {
    public boolean queryString(String S, int n) {
        var seen = new HashSet<Integer>();
        var s = S.toCharArray();
        for (int i = 0, m = s.length; i < m; ++i) {
            int x = s[i] - '0';
            if (x == 0) continue; // 二进制数从 1 开始
            for (int j = i + 1; x <= n; j++) {
                seen.add(x);
                if (j == m) break;
                x = (x << 1) | (s[j] - '0'); // 子串 [i,j] 的二进制数
            }
        }
        return seen.size() == n;
    }
}
```

如一个字符串要包含所有连续整数，例如长为 $3$ 的互不相同字符共有 $4$ 个($100,101,110,111$)，既然互不相同，理想情况下就算重叠的再好，每个字符也会多一个不一样的即最优总长度为 $3+(4-1)=6$。推广一下，设 $n$ 的二进制长度是 $k+1$，则 $[2^k,n]$ 内长度为 $k+1$ 的数，共 $n-2^k+1$ 个，总长度为 $k+1+n-2^k$。同理，$[2^{k-1},2^k-1]$ 有 $2^{k-1}$ 个，满足 $k+2^{k-1}-1$，因为不同长度间可以叠，所以不是加，具体而言应当至少满足 $|s|\ge \max(k+1+n-2^k,k+2^{k-1}-1)$，才可能(不是必然)有解。$k$ 是 $O(\log n)$，所以 $\max$ 式子求出来大约是 $0.5n$ 的数据量，准确而言，$|s| \le 10^3$ 可以推出 $n < 2014$，因此，只需要遍历 $n$ 的每个数，看看是否在子串也行：

```java
class Solution {
    public boolean queryString(String s, int n) {
        for (int i = 1; i <= n; i++)
            if (!s.contains(Integer.toBinaryString(i)))
                return false;
        return true;
    }
}
```

大约是 $O(|s|^2\log n)$ 的复杂度，但空间优。

注意到在上文分析里，区间 $[2^{k-1},2^k-1]$ 如果能全部覆盖，那么更低的位数区间必然也能被覆盖，这是因为把 $k$ 长最低位砍掉，刚好就是低一位的。因此，只需要考虑能否被长为 $k,k+1$ 这两组的全体二进制。同理，对 $[2^k,n]$ 的全体数，可以被 $k$ 的一部分覆盖，所以只需要从 $\lfloor\dfrac n2\rfloor+1$ 开始考虑。

更优解法：滑动窗口。不断维护长为 $k$ 的窗口，$O(|s|)$ 求出所有长为 $k$ 的 01 串的十进制值然后丢 set 里，最后看看 set 是否包含给定范围。

```java
class Solution {
    public boolean queryString(String s, int n) {
        if (n == 1)
            return s.contains("1");

        int k = 31 - Integer.numberOfLeadingZeros(n); // n 的二进制长度减一
        if (s.length() < Math.max(n - (1 << k) + k + 1, (1 << (k - 1)) + k - 1))
            return false;

        return check(s, k, n / 2 + 1, (1 << k) - 1) && check(s, k + 1, 1 << k, n);
    }

    // 对于长为 k 的在 [lower, upper] 内的二进制数，判断这些数 s 是否都有
    private boolean check(String s, int k, int lower, int upper) {
        if (lower > upper) return true;
        var seen = new HashSet<Integer>();
        int mask = (1 << (k - 1)) - 1;
        int x = Integer.parseInt(s.substring(0, k - 1), 2);
        for (int i = k - 1, m = s.length(); i < m; i++) {
            // & mask 可以去掉最高比特位，从而实现滑窗的「出」
            // << 1 | (s.charAt(i) - '0') 即为滑窗的「入」
            x = ((x & mask) << 1) | (s.charAt(i) - '0');
            if (lower <= x && x <= upper)
                seen.add(x);
        }
        return seen.size() == upper - lower + 1;
    }
}
```



##### 1330\.翻转子数组得到最大的数组值

[题目](https://leetcode.cn/problems/reverse-subarray-to-maximize-array-value/)

先特判掉翻转左端点为起始点和右端点为终点的情况，对剩下的情况，设翻转的区间是 $[i,j],i > 0, j < n-1$，

解法一：

根据 $|x|=\max(x,-x)$，且 $\max(a,b)+c=\max(a+c,b+c)$ 得
$$
\max(a,b)+\max(c,d)=\max(a+c,a+d,b+c,b+d)
$$
有：

原式核心问题即求 $\max _{0 < i <j < n-1}|a_j-a_{i-1}|+|a_{j+1}-a_i|-|a_{j+1}-a_j|-|a_i-a_{i-1}|$。
$$
\begin{align}
&|a_j-a_{i-1}|+|a_{j+1}-a_i|-|a_{j+1}-a_j|-|a_i-a_{i-1}|\\
=&\max\pmatrix{a_j-a_{i-1},\\a_{i-1}-a_j}+\max\pmatrix{a_{j+1}-a_i,\\a_i-a_{j+1}}+(-|a_{j+1}-a_j|-|a_i-a_{i-1}|)\\
=&\max\pmatrix{a_j-a_{i-1}+a_{j+1}-a_i,\\a_j-a_{i-1}+a_i-a_{j+1},\\a_{i-1}-a_j+a_{j+1}-a_i,\\a_{i-1}-a_j+a_i-a_{j+1}}+(-|a_{j+1}-a_j|-|a_i-a_{i-1}|)\\
=&\max\pmatrix{
a_j-a_{i-1}+a_{j+1}-a_i-|a_{j+1}-a_j|-|a_i-a_{i-1}|,\\
a_j-a_{i-1}+a_i-a_{j+1}-|a_{j+1}-a_j|-|a_i-a_{i-1}|,\\
a_{i-1}-a_j+a_{j+1}-a_i-|a_{j+1}-a_j|-|a_i-a_{i-1}|,\\
a_{i-1}-a_j+a_i-a_{j+1}-|a_{j+1}-a_j|-|a_i-a_{i-1}|}\\
=&\max\pmatrix{
a_j+a_{j+1}-|a_{j+1}-a_j|-a_{i-1}-a_i-|a_i-a_{i-1}|,\\
-a_{j+1}+a_j-|a_{j+1}-a_j|+a_i-a_{i-1}-|a_i-a_{i-1}|,\\
a_{j+1}-a_j-|a_{j+1}-a_j|-a_i+a_{i-1}-|a_i-a_{i-1}|,\\
-a_{j+1}-a_j-|a_{j+1}-a_j|+a_i+a_{i-1}-|a_i-a_{i-1}|}
\end{align}
$$
因为 $i <j$，所以维护四个前缀最大值 $\pm a_i\pm a_{i-1}-|a_i-a_{i-1}|$，每次对不同的 $j$，分别求出最大值即可。

```java
class Solution {
public:
    static constexpr int INF = 0x3f3f3f3f;

    int maxValueAfterReverse(const vector<int>& nums) {
        const int n = nums.size(), a = nums[0], b = nums[n - 1];
        // 记录前缀最大值，数组下标表示正负号，0 为正，1 为负
        int premax[2][2] = {-INF, -INF, -INF, -INF};
        int sum = 0, ans = 0;
        for (int i = 1;i < n;++i) {
            const int x = nums[i - 1], y = nums[i], d = abs(x - y);
            sum += d;
            // 更新结果，将公共的 -d 部分提取出来减少计算量
            ans = max(ans, max({
                abs(x - b),
                abs(y - a),
                premax[0][0] - x - y,
                premax[0][1] - x + y,
                premax[1][0] + x - y,
                premax[1][1] + x + y
            }) - d);
            // 更新最大值信息
            premax[0][0] = max(premax[0][0], x + y - d);
            premax[0][1] = max(premax[0][1], x - y - d);
            premax[1][0] = max(premax[1][0], -x + y - d);
            premax[1][1] = max(premax[1][1], -x - y - d);
        }
        return sum + ans;
    }
};
```

解法二：

令 $a=nums_{i-1},b=nums_{i},x=nums_{j},y=nums_{j+1}$，先算出原数组值，然后求最大增量即：
$$
\max_{i <j}\Delta=|a-x|+|b-y|-|a-b|-|x-y|
$$
显然有 $|a-b|=\max(a,b)-\min(a,b)$，且显然 $a+b=\max(a,b)+\min(a,b)$，相加、相减得：
$$
a+b+|a-b|=2\max(a,b),\quad a+b-|a-b|=2\min(a,b)
$$
若 $\max(a,b)\le\min(x,y)$，可知
$$
\begin{align}
\Delta&=x-a+y-b-|a-b|-|x-y|\\
&=(x+y-|x-y|)-(a+b+|a-b|)\\
&=2\min(x,y)-2\max(a,b)
\end{align}
$$
根据假设，可知 $\max(a,b)\le \min(x,y)$，故上式 $\ge 0$。

同理，若 $\max(x,y)\le \min(a,b)$，得 $\Delta=2\min(a,b)-2\max(x,y)\ge 0$。

在全体 $a,b,x,y$ 的 $4!$ 种大小关系里，$\max(a,b)\le\min(x,y)$ 有 $abxy,abyx,baxy,bayx$ 四种情况，同理，$\max(x,y)\le\min(a,b)$ 也有四种情况。

如果 $\max(a,x)\le\min(b,y)$，同理 $\Delta=2\max(a,x)-2\min(b,y)\le 0$，而不等号反即 $\max(b,y)\le\min(a,x)$ 时 $\Delta=2\max(b,y)-2\min(a,x)\le 0$。共八种情况。

剩下的情况为 $\max(a,y)\le \min(b,x)$，或 $\max(b,x)\le\min(a,y)$，均得 $\Delta=0$。

也就是说，当且仅当 $\max(x,y)\le\min(a,b)$ 或 $\max(x,y)\le \min(x,y)$ 时翻转更优，分别为：

1. $\max(x,y)\le\min(a,b),\Delta=2\min(x,y)-2\max(a,b)$
2. $\max(a,b)\le\min(x,y),\Delta=2\min(a,b)-2\max(x,y)$

维护 $mx=\max\min(|nums_i-nums_{i-1}|)$ 和 $mn=\min\max(|nums_i-nums_{i-1}|)$。

如果 $mx > mn$，也就是拿最大的 $\min(x,y)=mx$，最小的 $\max(a,b)=mn$，代入上式，求得最大的差值 $\Delta$。

```java
class Solution {
    public int maxValueAfterReverse(int[] nums) {
        int base = 0, d = 0, n = nums.length;
        int mx = Integer.MIN_VALUE, mn = Integer.MAX_VALUE;
        for (int i = 1; i < n; i++) {
            int a = nums[i - 1], b = nums[i];
            int dab = Math.abs(a - b);
            base += dab;
            mx = Math.max(mx, Math.min(a, b));
            mn = Math.min(mn, Math.max(a, b));
            d = Math.max(d, Math.max(Math.abs(nums[0] - b) - dab, // i=0
                                     Math.abs(nums[n - 1] - a) - dab)); // j=n-1
        }
        return base + Math.max(d, 2 * (mx - mn));
    }
}
```



##### 1054\.距离相等的条形码

[题目](https://leetcode.cn/problems/distant-barcodes/)

个人解法：对每个出现频次，记录所有数字，按频次从高到低隔一个地填数。

```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.TreeMap;

class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        int n = barcodes.length;
        HashMap<Integer, Integer> h = new HashMap<>();
        for (int v : barcodes) {
            h.put(v, h.getOrDefault(v, 0) + 1);
        }
        TreeMap<Integer, ArrayList<Integer>> h2 = new TreeMap<>();
        for (Entry<Integer, Integer> pr : h.entrySet()) {
            int k = pr.getKey(), v = -pr.getValue();
            if (h2.containsKey(v)) {
                h2.get(v).add(k);
            } else {
                ArrayList<Integer> lt = new ArrayList<>();
                lt.add(k);
                h2.put(v, lt);
            }
        }
        int i = 0, ans[] = new int[n];
        for (Entry<Integer, ArrayList<Integer>> pr : h2.entrySet()) {
            int k = -pr.getKey();
            ArrayList<Integer> lt = pr.getValue();
            for (int v : lt) {
                for (int j = 0; j < k; ++j) {
                    ans[i] = v;
                    if (i + 2 >= n) {
                        i = 1;
                    } else {
                        i += 2;
                    }
                }
            }
        }
        return ans;
    }
}
```

官解一：贪心填最高频的，维护大根堆，顺序遍历，如果当前跟上一个重复，就填次大的

```java
class Solution {
    public int[] rearrangeBarcodes(int[] barcodes) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int b : barcodes) {
            if (!count.containsKey(b)) {
                count.put(b, 0);
            }
            count.put(b, count.get(b) + 1);
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            pq.offer(new int[]{entry.getValue(), entry.getKey()});
        }
        int n = barcodes.length;
        int[] res = new int[n];
        for (int i = 0; i < n; ++i) {
            int[] p = pq.poll();
            int cx = p[0], x = p[1];
            if (i == 0 || res[i - 1] != x) {
                res[i] = x;
                if (cx > 1) {
                    pq.offer(new int[]{cx - 1, x});
                }
            } else {
                int[] p2 = pq.poll();
                int cy = p2[0], y = p2[1];
                res[i] = y;
                if (cy > 1) {
                    pq.offer(new int[]{cy - 1, y});
                }
                pq.offer(new int[]{cx, x});
            }
        }
        return res;
    }
}
```

官解二：分两个道，可以证明贪心直接摆不会冲突。

```java
class Solution {
    public static int[] rearrangeBarcodes(int[] barcodes) {
        int length = barcodes.length;
        if (length < 2) {
            return barcodes;
        }

        Map<Integer, Integer> counts = new HashMap<>();
        int maxCount = 0;
        for (int b : barcodes) {
            counts.put(b, counts.getOrDefault(b, 0) + 1);
            maxCount = Math.max(maxCount, counts.get(b));
        }

        int evenIndex = 0;
        int oddIndex = 1;
        int halfLength = length / 2;
        int[] res = new int[length];
        for (Map.Entry<Integer, Integer> entry : counts.entrySet()) {
            int x = entry.getKey();
            int count = entry.getValue();
            while (count > 0 && count <= halfLength && oddIndex < length) {
                res[oddIndex] = x;
                count--;
                oddIndex += 2;
            }
            while (count > 0) {
                res[evenIndex] = x;
                count--;
                evenIndex += 2;
            }
        }
        return res;
    }
}
```



##### 1072\.按列翻转得到最大值等行数

[题目](https://leetcode.cn/problems/flip-columns-for-maximum-number-of-equal-rows/)

求出把每行变成 0 或变成 1 需要的操作序列，然后反求出现次数最大的操作序列。

```java

import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int maxEqualRowsAfterFlips(int[][] a) {
        HashMap<ArrayList<Boolean>, Integer> h = new HashMap<>();
        int n = a.length, m = a[0].length, ans = 0;
        for (int i = 0; i < n; ++i) {
            ArrayList<Boolean> f0 = new ArrayList<>(m), f1 = new ArrayList<>(m);
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 0) {
                    f1.add(true);
                    f0.add(false);
                } else {
                    f1.add(false);
                    f0.add(true);
                }
            }
            h.put(f0, h.getOrDefault(f0, 0) + 1);
            h.put(f1, h.getOrDefault(f1, 0) + 1);
            ans = Math.max(ans, h.get(f0));
            ans = Math.max(ans, h.get(f1));
        }
        return ans;
    }
}
```

优化：一个操作序列与其取反(该操作不操作，不该操作操作)是等价的，换言之对一个行整行按位取反后是等价的

```java
class Solution {
    public int maxEqualRowsAfterFlips(int[][] matrix) {
        int m = matrix.length, n = matrix[0].length;
        Map<String, Integer> map = new HashMap<String, Integer>();
        for (int i = 0; i < m; i++) {
            char[] arr = new char[n];
            Arrays.fill(arr, '0');
            for (int j = 0; j < n; j++) {
                // 如果 matrix[i][0] 为 1，则对该行元素进行翻转
                arr[j] = (char) ('0' + (matrix[i][j] ^ matrix[i][0]));
            }
            String s = new String(arr);
            map.put(s, map.getOrDefault(s, 0) + 1);
        }
        int res = 0;
        for (Map.Entry<String, Integer> entry : map.entrySet()) {
            res = Math.max(res, entry.getValue());
        }
        return res;
    }
}
```



##### 1335. 工作计划的最低难度

[题目](https://leetcode.cn/problems/minimum-difficulty-of-a-job-schedule/)

设 $dp_{i,k}$ 表示只考虑前 $i$ 个工作前 $k$ 天，则自然能想到转移为：
$$
dp_{i,k}=\min_{j=1}^{i-1}(dp_{j,k-1}+\max_{v=j+1}^ia_v),k-1\le j\le i
$$
其中 max 直接原地叠后缀即可，故复杂度为 $O(n^2d)$，且空间可以压第二维，可以优化成 $O(n)$

```java
class Solution {
    public int minDifficulty(int[] a, int d) {
        int n = a.length;
        if (d > n) {
            return -1;
        }
        int dp[][] = new int[n + 1][d + 1];
        for (int i = 1, mx = 0; i <= n; ++i) {
            mx = Math.max(mx, a[i - 1]);
            dp[i][1] = mx;
        }
        for (int k = 2; k <= d; ++k) {
            for (int i = k; i <= n; ++i) {
                int mx = 0;
                dp[i][k] = Integer.MAX_VALUE;
                for (int j = i; j > k - 1; --j) {
                    mx = Math.max(mx, a[j - 1]);
                    dp[i][k] = Math.min(dp[i][k], dp[j - 1][k - 1] + mx);
                }
            }
        }
        return dp[n][d];
    }
}
```

> 滚动数组：
>
> ```java
> class Solution {
>     public int minDifficulty(int[] jobDifficulty, int d) {
>         int n = jobDifficulty.length;
>         if (n < d) {
>             return -1;
>         }
>         int[] dp = new int[n];
>         for (int i = 0, j = 0; i < n; ++i) {
>             j = Math.max(j, jobDifficulty[i]);
>             dp[i] = j;
>         }
>         for (int i = 1; i < d; ++i) {
>             int[] ndp = new int[n];
>             Arrays.fill(ndp, 0x3f3f3f3f);
>             for (int j = i; j < n; ++j) {
>                 int ma = 0;
>                 for (int k = j; k >= i; --k) {
>                     ma = Math.max(ma, jobDifficulty[k]);
>                     ndp[j] = Math.min(ndp[j], ma + dp[k - 1]);
>                 }
>             }
>             dp = ndp;
>         }
>         return dp[n - 1];
>     }
> }
> ```

优化：

令 $left_i$ 是 $a_i$ 左边最近比它严格大的元素的下标。

设 $left_i=p$，则任选 $k$，有：

- $j\ge p$ 时，$\max _{v=j+1}^i=a_i$，即 $dp_{i,k}=a_j+\min_{j=p}^{j-1}dp_{j,k-1}$

  可以用严格单调递减栈求出 $left_i$，用线段树/ST表维护上一层的 $dp$ 最小值，即可 $O(\log n)$ 求出这个值。

   还有一种更好的办法，每个栈节点存下标 $i$ 加上 $\min_{v=p}^{i}dp_{v,k-1}$，如果 $p$ 不存在就一直拉到首部。初始设为 $a_i$，每次 while 弹栈时，维护弹走的 $\min$ 加上去，可以 $O(n)$ 维护一层的所有该情况。

- 否则，$\max_{v=j+1}^i=\max_{v=j+1}^pa_v$，即：
  $$
  dp_{i,k}=\min_{j=1}^{p-1}(dp_{j,k-1}+\max_{v=j+1}^pa_v)=dp_{i,p}
  $$
  这种情况可以直接 $O(1)$ 推，本质上是 $p$ 点往右推。在上文单调栈的情况下，可以直接取出 $p$。

维护一个关于 $dp_{i,k-1}$ 的一层严格单调递减栈，可以求出 $p$。

故复杂度为 $O(nd)$，空间 $O(n)$。

```java
class Solution {
    public int minDifficulty(int[] a, int d) {
        int n = a.length;
        if (n < d) return -1;

        var f = new int[d][n];
        f[0][0] = a[0];
        for (int i = 1; i < n; i++)
            f[0][i] = Math.max(f[0][i - 1], a[i]);
        for (int i = 1; i < d; i++) {
            var st = new ArrayDeque<int[]>(); // (下标 j，从 f[i-1][left[j]] 到 f[i-1][j-1] 的最小值)
            for (int j = i; j < n; j++) {
                int mn = f[i - 1][j - 1]; // 只有 a[j] 一项工作
                while (!st.isEmpty() && a[st.peek()[0]] <= a[j]) // 向左一直计算到 left[j]
                    mn = Math.min(mn, st.pop()[1]);
                f[i][j] = mn + a[j]; // 从 a[left[j]+1] 到 a[j] 的最大值是 a[j]
                if (!st.isEmpty()) // 如果这一段包含 <=left[j] 的工作，那么这一段的最大值必然不是 a[j]
                    f[i][j] = Math.min(f[i][j], f[i][st.peek()[0]]); // 答案和 f[i][left[j]] 是一样的
                st.push(new int[]{j, mn}); // 注意这里保存的不是 f[i][j]
            }
        }
        return f[d - 1][n - 1];
    }
}
```



##### 2446. 判断两个事件是否存在冲突

[题目](https://leetcode.cn/problems/determine-if-two-events-have-conflict/)

两个区间 $[a,b],[c,d]$ 重合的充要条件是 $c\ge b$ 且 $d\ge a$

```java
class Solution {
    private int toMinute(String s) {
        int h = Integer.parseInt(s.substring(0, 2));
        int m = Integer.parseInt(s.substring(3));
        return h * 60 + m;
    }

    public boolean haveConflict(String[] event1, String[] event2) {
        int a = toMinute(event1[0]), b = toMinute(event1[1]);
        int c = toMinute(event2[0]), d = toMinute(event2[1]);
        return b >= c && d >= a;
    }
}
```

更优做法是直接比较字典序：

```java
class Solution {
    public boolean haveConflict(String[] event1, String[] event2) {
        return !(event1[1].compareTo(event2[0]) < 0 || event2[1].compareTo(event1[0]) < 0);
    }
}
```



##### 1073\.负二进制数相加

[题目](https://leetcode.cn/problems/adding-two-negabinary-numbers/)

考虑在负二进制下原地进位模拟，由于：
$$
\begin{align}
2\cdot (-2)^0&=(-2)^1+(-2)^2\\
\end{align}
$$
两边同乘 $(-2)^k$，可以得知对任意的位进位规则有：
$$
\begin{align}
2\cdot (-2)^k&=(-2)^{k+1}+(-2)^{k+2}\\
\end{align}
$$
经过进位，会使得某个位叠上 $3$(原本 $1+1$，加上进位 $1$)，同理可得：
$$
3\cdot(-2)^k=(-2)^k+(-2)^{k+1}+(-2)^{k+2}
$$
考虑某个位 $k$ 的前两个位都是 $1+1$，那么对 $k$ 能叠两次进位，即叠到 $4$，而有：
$$
4\cdot (-2)^k=(-2)^{k+2}
$$
不可能叠到更高的，如 $5$ 或以上。根据上述规则，只有前两位能叠，每个位最多叠多一个数，所以显然得证。

但是如果只用这三条规则，会产生循环进位，考虑 $(11)_{-2}+(01)_{-2}$，会无限进位。因此需要特别多考虑：
$$
2\cdot(-2)^k+(-2)^{k+1}=0
$$
如此，则完备地讨论了全部可能的情况，上述规则只涉及 $3$ 个位(当前，上一个，上上一个)的两个本位和一个进位，枚举可知每种情况都有对应的解法，故已经完备。

代码：

```java
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int a[] = new int[Math.max(arr1.length, arr2.length) + 5];
        for (int i = 0, j = arr1.length - 1; j >= 0; --j, ++i) {
            a[i] += arr1[j];
        }
        for (int i = 0, j = arr2.length - 1; j >= 0; --j, ++i) {
            a[i] += arr2[j];
        }
        for (int i = 0; i < a.length - 2; ++i) {
            if (a[i] == 2) {
                if (a[i + 1] == 0) {
                    ++a[i + 1];
                    ++a[i + 2];
                } else {
                    --a[i + 1];
                }
                a[i] = 0;
            }
            if (a[i] == 3) {
                a[i] -= 2;
                ++a[i + 1];
                ++a[i + 2];
            }
            if (a[i] == 4) {
                a[i] = 0;
                ++a[i + 2];
            }
        }
        int n = 0;
        for (int i = a.length - 1; i >= 0; --i) {
            if (a[i] > 0) {
                n = i;
                break;
            }
        }
        int r[] = new int[n + 1];
        for (int i = 0, j = n; j >= 0; --j, ++i) {
            r[i] = a[j];
        }
        return r;
    }
}
```

解法二：进位不算1，算-1，则原本的数的范围从2进制加法的0123变成了-1012，分类讨论：若为2，本位0，进位-1；若为-1，则本位下一位都设为1。这种进位算法只需要牵扯一个位。

```java
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int i = arr1.length - 1, j = arr2.length - 1;
        int carry = 0;
        List<Integer> ans = new ArrayList<Integer>();
        while (i >= 0 || j >= 0 || carry != 0) {
            int x = carry;
            if (i >= 0) {
                x += arr1[i];
            }
            if (j >= 0) {
                x += arr2[j];
            }
            if (x >= 2) {
                ans.add(x - 2);
                carry = -1;
            } else if (x >= 0) {
                ans.add(x);
                carry = 0;
            } else {
                ans.add(1);
                carry = 1;
            }
            --i;
            --j;
        }
        while (ans.size() > 1 && ans.get(ans.size() - 1) == 0) {
            ans.remove(ans.size() - 1);
        }
        int[] arr = new int[ans.size()];
        for (i = 0, j = ans.size() - 1; j >= 0; i++, j--) {
            arr[i] = ans.get(j);
        }
        return arr;
    }
}
```

也可以转十进制然后转回去：

```python
class Solution:
    def addNegabinary(self, arr1: List[int], arr2: List[int]) -> List[int]:
        def atn(arr:List[int]):
            l=len(arr)
            return sum((-2)**(l-1-i)*arr[i] for i in range(l))
        def nta(num:int):
            arr=[]
            while num!=0:
                tmp=num%(-2)
                arr.insert(0,-tmp)
                num+=tmp#key
                num//=(-2)
            if arr==[]: return [0]
            return arr
        num1,num2=atn(arr1),atn(arr2)
        num_plus=num1+num2
        return nta(num_plus)
```



##### 1079\.活字印刷

[题目]()

个人爆搜，复杂度 $O(n\cdot n!)$

```java
class Solution {
    private HashSet<String> h = new HashSet<>();
    private boolean vis[];
    private int n;
    private StringBuilder cur = new StringBuilder();
    private String t;

    private void dfs() {
        String s = cur.toString();
        if (h.contains(s)) {
            return;
        }
        h.add(s);
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                cur.append(t.charAt(i));
                dfs();
                vis[i] = false;
                cur.deleteCharAt(cur.length() - 1);
            }
        }
    }

    public int numTilePossibilities(String tiles) {
        h.clear();
        t = tiles;
        n = tiles.length();
        vis = new boolean[n];
        dfs();
        return h.size() - 1;
    }
}
```

> 题解写法：
>
> ```java
> class Solution {
>     public int numTilePossibilities(String tiles) {
>         Map<Character, Integer> count = new HashMap<>();
>         for (char t : tiles.toCharArray()) {
>             count.put(t, count.getOrDefault(t, 0) + 1);
>         }
>         Set<Character> tile = new HashSet<>(count.keySet());
>         return dfs(tiles.length(), count, tile) - 1;
>     }
> 
>     private int dfs(int i, Map<Character, Integer> count, Set<Character> tile) {
>         if (i == 0) {
>             return 1;
>         }
>         int res = 1;
>         for (char t : tile) {
>             if (count.get(t) > 0) {
>                 count.put(t, count.get(t) - 1);
>                 res += dfs(i - 1, count, tile);
>                 count.put(t, count.get(t) + 1);
>             }
>         }
>         return res;
>     }
> }
> ```

设 $dp_{i,j}$ 表示只用前 $i$ 种字符构造长为 $j$ 的序列的方案数，设第 $i$ 种字符有 $cnt$ 个，则：

- 一个也不选，$dp_{i,j}=dp_{i-1,j}$
- 选 $k$ 个，则 $C_{j}^k$ 种选法，其余位置顶上，即 $dp_{i,j}=dp_{i-1,j-k}\cdot C_j^k$

即：
$$
dp_{i,j}=\sum_{k=0}^{\min(j,cnt_i)}dp_{i-1,j-k}C_k^j
$$
初始值为 $dp_{0,0}=0$。所求为 $\sum_{j=1}^ndp_{m,j}$，其中 $m$ 是字符种类数。

由于 $\sum cnt=n$，故三重循环的总复杂度为 $O(n^2)$，还可以滚动压 DP。

```java
class Solution {
    private static final int MX = 8;
    private static final int[][] c = new int[MX][MX];

    static {
        for (int i = 0; i < MX; i++) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; j++)
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j]; // 预处理组合数
        }
    }

    public int numTilePossibilities(String tiles) {
        // 注：改成 int[26] 统计可能会快一点点，感兴趣可以试试（下面 DP 跳过 cnt=0 的情况）
        var counts = new HashMap<Character, Integer>(); // 统计每个字母的出现次数
        for (var c : tiles.toCharArray())
            counts.merge(c, 1, Integer::sum); // counts[c]++
        var f = new int[tiles.length() + 1];
        f[0] = 1; // 构造空序列的方案数
        int n = 0;
        for (var cnt : counts.values()) { // 枚举第 i 种字母
            n += cnt; // 常数优化：相比从 tiles.length() 开始要更快
            for (int j = n; j > 0; j--) // 枚举序列长度 j
                // 枚举第 i 种字母选了 k 个，注意 k=0 时的方案数已经在 f[j] 中了
                for (int k = 1; k <= j && k <= cnt; k++)
                    f[j] += f[j - k] * c[j][k];
        }
        int ans = 0;
        for (int j = 1; j <= n; j++)
            ans += f[j];
        return ans;
    }
}
```

多项式：

> 在做这道题之前，让我们回忆一下 OJ 的一道题目：[还是还是字符串计数](https://oj.socoding.cn/p/1451)
>
> 这道题目的解法是指数生成函数，该知识可以参考离散数学(递推方程-指数生成函数及其应用)。
>
> 对于 OJ `还是还是字符串计数` 这题，组合形式的指数生成函数为：
> $$
> (1+\frac{x}{1!}+\frac{x^2}{2!}+\dots)^2(1+\frac{x^2}{2!}+\frac{x^4}{4!}+\dots)^2
> $$
> 利用泰勒展开 $e^x=\sum_{n=0}^\infty\frac{x^n}{n!},x\in\mathbf{R}$ 和二项式奇偶求和 $e^{2x}(\frac{e^x+e^{-x}}2)^2=\frac14(e^{4x}+1+2e^{2x})$ 并再次展开生成函数原式：
> $$
> \frac14+\frac14(1+\frac{4x}{1!}+\dots+\frac{(4x)^n}{n!}+\dots)+\frac12(1+\frac{2x}{1!}+\dots+\frac{(2x)^n}{n!}+\dots)
> $$
> 提取 $x^n$ 项系数 $\dfrac14\cdot\dfrac{4^n}{n!}+\dfrac12\cdot\dfrac{2^n}{n!}$，将组合转排列，乘以 $n!$，得 $4^{n-1}+2^{n-1}$

现在回到这道题，题意转化为：设第 $i$ 个字母有 $cnt_i$ 个，其中 $\sum cnt=n$，使用任意多个字母，求能组成本质不同字符串有几个。

类比引入题，可以得出，只考虑排列时，指数生成函数为：
$$
\prod_{i}(1+\dfrac{x}{1!}+\dfrac{x^2}{2!}+\cdots+\dfrac{x^{cnt_i}}{cnt_i!})
$$
现在加上组合，所求为该生成函数的每一项乘以 $i!$，设 $x_i$ 的系数为 $a_i$，则所求为：$\sum_{i=1}^na_ii!$

> 以样例 `aab` 为例，有指数生成函数 $(1+x+\dfrac{x^2}2)(1+x)=1+2x+\dfrac32x^2+\dfrac12x^3$。
>
> 则所求为 $2\cdot1!+\dfrac32\cdot2!+\dfrac12\cdot3!=2+3+3=8$。

为了适应模意义，使用 NTT 求解多项式乘法，最多进行 $26$ 次乘法，每次复杂度为 $O(n\log n)$(考虑最坏情况，第一个多项式长度 $\approx n$，其他多项式长度极小)，故总复杂度为 $O(26n\log n)$。

> 常数优化：可以控制多项式乘法的顺序，如使用哈夫曼编码的思想，将至多 $26$ 个多项式不断每次让最短的两个相乘， 乘至多 $25$ 次。如果有很多个同 $cnt$ 的多项式，还可以用多项式乘方。略。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 998244353;
ll qui(ll a, ll x)
{
    ll ret = 1;
    while (x)
    {
        if (x & 1)
            ret = ret * a % mod;
        a = a * a % mod;
        x >>= 1;
    }
    return ret;
}

using Poly = vector<ll>;
const int BIT = 20;
int p[1 << BIT];

Poly operator*(const Poly &a, const Poly &b)
{
    int n = a.size() - 1, m = b.size() - 1;
    int L, l = 0;
    for (L = 1; L <= n + m; l++, L = L << 1)
        ;

    vector<int> p(L);

    for (int i = 1; i < L; i++)
        p[i] = ((p[i >> 1] >> 1) | ((i & 1) << (l - 1)));
    auto u = a, v = b;
    u.resize(L, 0), v.resize(L, 0);
    auto ntt = [&L, &l, &p](Poly &g, int type)
    {
        for (int i = 0; i < L; i++)
            if (i < p[i])
                swap(g[i], g[p[i]]);
        for (int i = 1; i < L; (i <<= 1))
        {
            ll wn = qui(3, (mod - 1) / (i << 1));
            for (int j = 0; j < L; j += (i << 1))
            {
                ll w = 1;
                for (int k = j; k < j + i; w = w * wn % mod, k++)
                {
                    assert(k + i < L);
                    assert(k < L);
                    ll t = g[k + i] * w % mod;
                    g[k + i] = (g[k] - t + mod) % mod;
                    g[k] = (g[k] + t) % mod;
                }
            }
        }
        if (type == 1)
            return;
        reverse(g.begin() + 1, g.begin() + L);
        ll ni = qui(L, mod - 2);
        for (int i = 0; i < L; i++)
            g[i] = g[i] * ni % mod;
    };
    ntt(u, 1), ntt(v, 1);

    Poly g(L, 0);
    for (int i = 0; i < L; i++)
        g[i] = u[i] * v[i] % mod;
    ntt(g, -1);

    return g;
}

const ll maxn = 1e5 + 10;
ll fact[maxn], inv[maxn], n, cnt[256], ans;
string s;

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> s;
    n = s.length();
    for (auto c : s)
    {
        ++cnt[c];
    }
    fact[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[n] = qui(fact[n], mod - 2);
    for (int i = n - 1; i >= 0; --i) // 线性阶乘逆元
    {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }

    Poly a = {1};
    for (int i = 'a'; i <= 'z'; ++i)
    {
        if (cnt[i])
        {
            Poly b = vector<ll>(cnt[i] + 1, 0);
            for (ll j = 0; j <= cnt[i]; ++j)
            {
                b[j] = inv[j];
            }
            a = a * b;
            while (a.back() == 0) // 避免长度指数增长
            {
                a.pop_back();
            }
        }
    }
    for (ll i = 1; i < a.size(); ++i)
    {
        ans = (ans + (a[i] * fact[i])) % mod;
    }
    cout << ans;
    return 0;
}
```

哈夫曼树：

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

inline constexpr unsigned rev(unsigned x) {
	x = ((x >> 1) & 0x55555555) | ((x & 0x55555555) << 1);
	x = ((x >> 2) & 0x33333333) | ((x & 0x33333333) << 2);
	x = ((x >> 4) & 0x0F0F0F0F) | ((x & 0x0F0F0F0F) << 4);
	x = ((x >> 8) & 0x00FF00FF) | ((x & 0x00FF00FF) << 8);
	return x >> 16 | x << 16;
}

template<bool Inv = true, typename T>
inline void fft(std::complex<T>* seq, unsigned n, unsigned m) {
	static constexpr std::complex<T> C(0, Inv ? -M_PI : M_PI);
	const unsigned d = 32 - m;
	for (unsigned i = 1;i < n;++i) {
		const unsigned ri = rev(i) >> d;
		if (i < ri) swap(seq[i], seq[ri]);
	}
	for (unsigned p = 1;p < n;p *= 2) {
		const std::complex<T> step = exp(C / T(p));
		for (unsigned i = 0;i < n;i += p) {
			std::complex<T> cur = 1;
			for (unsigned j = i + p;i < j;++i) {
				const std::complex<T> l = seq[i];
				const std::complex<T> r = seq[i + p] * cur;
				cur *= step;
				seq[i] = l + r;
				seq[i + p] = l - r;
			}
		}
	}
	if constexpr (Inv)
		for (unsigned i = 0;i < n;++i)
			seq[i] /= n;
}

class Poly : public std::vector<double> {
public:
    using std::vector<double>::vector;

	Poly operator*(const Poly& other) const {
		const unsigned ln = size(), rn = other.size();
		const unsigned n = ln + rn - 1;
		unsigned m = 0;
		while ((1 << m) < n) ++m;
		const unsigned pn = 1 << m;
		std::vector<std::complex<double>> lf(pn), rf(pn);
		for (unsigned i = 0;i < ln;++i)
			lf[i] = (*this)[i];
		for (unsigned i = 0;i < rn;++i)
			rf[i] = other[i];
		fft<0>(lf.data(), pn, m);
		fft<0>(rf.data(), pn, m);
		for (unsigned i = 0;i < pn;++i)
			lf[i] *= rf[i];
		fft<1>(lf.data(), pn, m);
		Poly ans(n);
		for (unsigned i = 0;i < n;++i)
			ans[i] = lf[i].real();
		return ans;
	}

	Poly pow(unsigned e) const {
		const unsigned n0 = size();
		const unsigned n = e * (n0 - 1) + 1;
		unsigned m = 0;
		while ((1 << m) < n) ++m;
		const unsigned pn = 1 << m;
		std::vector<std::complex<double>> f(pn);
		for (unsigned i = 0;i < n0;++i)
			f[i] = (*this)[i];
		fft<0>(f.data(), pn, m);
		for (unsigned i = 0;i < pn;++i) {
			std::complex<double> p2 = f[i], pe = 1;
			for (unsigned j = e;j > 0;j /= 2) {
				if (j % 2 == 1) pe *= p2;
				p2 *= p2;
			}
			f[i] = pe;
		}
		fft<1>(f.data(), pn, m);
		Poly ans(n);
		for (unsigned i = 0;i < n;++i)
			ans[i] = f[i].real();
		return ans;
	}
};

class Solution {
public:
    struct Comparator {
        bool operator()(const Poly& lhs, const Poly& rhs) const {
            return lhs.size() > rhs.size();
        }
    };

    int numTilePossibilities(string tiles) {
        unordered_map<char, int> char_cnt;
        unordered_map<int, int> cnt_cnt;
        for (char c : tiles)
            ++char_cnt[c];
        for (auto [k, v] : char_cnt)
            ++cnt_cnt[v];
        vector<Poly> q;
        for (auto [k, v] : cnt_cnt) {
            Poly poly(k + 1);
            poly[0] = 1;
            double fac = 1;
            for (int i = 1;i <= k;++i)
                poly[i] = fac /= i;
            q.push_back(poly.pow(v));
        }
        make_heap(q.begin(), q.end(), Comparator{});
        while (q.size() > 1) {
            const Poly lv = move(q.front());
            pop_heap(q.begin(), q.end(), Comparator{});
            q.pop_back();
            const Poly rv = move(q.front());
            pop_heap(q.begin(), q.end(), Comparator{});
            q.pop_back();
            q.push_back(lv * rv);
            push_heap(q.begin(), q.end());
        }
        const Poly poly = q.front();
        const int n = poly.size();
        int ans = 0;
        double fac = 1;
        for (int i = 1;i < n;++i)
            ans += round(poly[i] * (fac *= i));
        return ans;
    }
};

signed main()
{
    return 0;
}
```



##### 2514\.统计同位异构字符串数目

[题目]()

个人实现：

```java
import java.util.HashMap;
import java.util.Map.Entry;

class Solution {
    private long p = 1000000007, f[], iv[];

    private long inv(long a) {
        long r = 1;
        for (long b = p - 2; b > 0; b >>= 1) {
            if ((b & 1) == 1) {
                r = r * a % p;
            }
            a = a * a % p;
        }
        return r;
    }

//    private long c(int u, int d) {// d选u的组合数
//        return f[d] * iv[u] % p * iv[d - u] % p;
//    }

    public int countAnagrams(String s) {
        String t[] = s.split(" ");
        int n = 0, m = t.length;
        for (int i = 0; i < m; ++i) {
            n = Math.max(n, t[i].length());
        }

        f = new long[n + 1];
        iv = new long[n + 1];
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] * i % p;
        }
        iv[n] = inv(f[n]);
        for (int i = n - 1; i >= 0; --i) {
            iv[i] = iv[i + 1] * (i + 1) % p;
        }

        long ans = 1;
        for (int i = 0; i < m; ++i) {
            long v = f[t[i].length()];
            HashMap<Character, Integer> cnt = new HashMap<>();
            for (int j = 0; j < t[i].length(); ++j) {
                char c = t[i].charAt(j);
                cnt.put(c, cnt.getOrDefault(c, 0) + 1);
            }
            for (Entry<Character, Integer> pr : cnt.entrySet()) {
                v = v * iv[pr.getValue()] % p;
            }
            ans = ans * v % p;
        }
        return (int) ans;
    }
}
```

更优实现：都是乘法，分母可以只算一次逆元，也不需要预处理什么东西

```java
class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int countAnagrams(String S) {
        var s = S.toCharArray();
        long ans = 1L, mul = 1L;
        var cnt = new int[26];
        for (int i = 0, j = 0; i < s.length; ++i) {
            if (s[i] == ' ') {
                Arrays.fill(cnt, 0);
                j = 0;
            } else {
                mul = mul * ++cnt[s[i] - 'a'] % MOD;
                ans = ans * ++j % MOD;
            }
        }
        return (int) (ans * pow(mul, MOD - 2) % MOD);
    }

    private long pow(long x, int n) {
        var res = 1L;
        for (; n > 0; n /= 2) {
            if (n % 2 > 0) res = res * x % MOD;
            x = x * x % MOD;
        }
        return res;
    }
}
```



##### LCP33\.蓄水

[题目](https://leetcode.cn/problems/o8SXZn/)

个人解法，复杂度也不太懂的瞎贪，觉得对每个数操作次数有限，很快收敛，所以每次找到代价最大的将它尝试缩减一下，直到无论怎么缩都不会降低次数为止：

```java
class Solution {
    private int max(int[] a) {
        int ans = 0;
        for (int i = 0; i < a.length; ++i) {
            ans = Math.max(ans, a[i]);
        }
        return ans;
    }

    public int storeWater(int[] bucket, int[] vat) {
        int n = bucket.length, c[] = new int[n], mx = 0, op = 0, ans = 0;
        for (int i = 0; i < n; ++i) {
            if (vat[i] == 0) {// SPJ
                c[i] = 0;
                continue;
            }
            if (bucket[i] == 0) {// SPJ
                ++bucket[i];
                ++op;
            }
            c[i] = (vat[i] - 1) / bucket[i] + 1;
        }
        mx = max(c);
        ans = mx + op;
        int cc = 0;
        while (true) {
            ++cc;
            boolean move = false;
            for (int i = 0; i < n; ++i) {
                if (c[i] == mx) {
                    int od = c[i];
                    int nw = (vat[i] - 1) / (bucket[i] + 1) + 1;
                    if (nw >= od) {
                        continue;
                    }
                    move = true;
                    ++op;
                    ++bucket[i];
                    c[i] = (vat[i] - 1) / bucket[i] + 1;
                }
//                System.out.print(bucket[i] + " ");
            }
//            System.out.println();
            mx = max(c);
//            System.out.println(op + " " + mx + " " + (op + mx) + " " + ans);
            if (!move) {
                break;
            }
            ans = Math.min(ans, op + mx);
        }
//        System.out.println(cc);
        return ans;
    }
}
```

设最终装水次数是 $k$，显然一次至少需要装 $\lceil\dfrac{vat_i}k\rceil$，也就是说，升级的次数是 $\max(0,\lceil\dfrac{vat_i}k\rceil-bucket_i)$，故总次数是 $k+\sum \lceil\dfrac{vat_i}k\rceil$。

枚举 $k$，复杂度为 $O(n\max vat_i)$。

```java
class Solution {
    public int storeWater(int[] bucket, int[] vat) {
        int n = bucket.length;
        int maxk = Arrays.stream(vat).max().getAsInt();
        if (maxk == 0) {
            return 0;
        }
        int res = Integer.MAX_VALUE;
        for (int k = 1; k <= maxk && k < res; ++k) {
            int t = 0;
            for (int i = 0; i < bucket.length; ++i) {
                t += Math.max(0, (vat[i] + k - 1) / k - bucket[i]);
            }
            res = Math.min(res, t + k);
        }
        return res;
    }
}
```

显然，对升级后的 $b'$，与初始容量 $b$，总操作次数是：
$$
\sum(b'_i-b_i)+\max\lceil\dfrac{v_i}{b'_i}\rceil
$$
每次选择需要操作最大的一个 $i$ 进行升级。使用最大堆 $(cnt_i,i)$ 维护每个有容量的 $i$ 需要装水多少次。不断升级，直到无法降低操作次数。

```java
class Solution {
    public int storeWater(int[] bucket, int[] vat) {
        int n = bucket.length;
        PriorityQueue<int[]> pq = new PriorityQueue<int[]>((a, b) -> b[0] - a[0]);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (bucket[i] == 0 && vat[i] != 0) {
                ++cnt;
                ++bucket[i];
            }
            if (vat[i] > 0) {
                pq.offer(new int[]{(vat[i] + bucket[i] - 1) / bucket[i], i});
            }
        }
        if (pq.isEmpty()) {
            return 0;
        }
        int res = Integer.MAX_VALUE;
        while (cnt < res) {
            int[] arr = pq.poll();
            int v = arr[0], i = arr[1];
            res = Math.min(res, cnt + v);
            if (v == 1) {
                break;
            }
            int t = (vat[i] + v - 2) / (v - 1);
            cnt += t - bucket[i];
            bucket[i] = t;
            pq.offer(new int[]{(vat[i] + bucket[i] - 1) / bucket[i], i});
        }
        return res;
    }
}
```



##### 1373\.二叉搜索子树的最大键值和

[题目](https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/)

个人版本：

```java
class Solution {
    private int ans;

    private int[] dfs(TreeNode now) {
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE, s = 0;
        if (now == null) {
            return new int[] { min, max, s, 1 };
        }
        int l[] = dfs(now.left), r[] = dfs(now.right), state = 0;
        if (l[1] < now.val && r[0] > now.val && l[3] > 0 && r[3] > 0) {
            state = 1;
            min = Math.min(now.val, Math.min(l[0], r[0]));
            max = Math.max(now.val, Math.max(l[1], r[1]));
            s = s + l[2] + r[2] + now.val;
            ans = Math.max(ans, s);
        }
        return new int[] { min, max, s, state };
    }

    public int maxSumBST(TreeNode root) {
        ans = 0;
        dfs(root);
        return ans;
    }
}
```

减少一个参数返回的版本：

```java
class Solution {
    private int ans; // 二叉搜索树可以为空

    public int maxSumBST(TreeNode root) {
        dfs(root);
        return ans;
    }

    private int[] dfs(TreeNode node) {
        if (node == null)
            return new int[]{Integer.MAX_VALUE, Integer.MIN_VALUE, 0};

        int[] left = dfs(node.left); // 递归左子树
        int[] right = dfs(node.right); // 递归右子树
        int x = node.val;
        if (x <= left[1] || x >= right[0]) // 不是二叉搜索树
            return new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE, 0};

        int s = left[2] + right[2] + x; // 这棵子树的所有节点值之和
        ans = Math.max(ans, s);

        return new int[]{Math.min(left[0], x), Math.max(right[1], x), s};
    }
}
```



##### 1080\.根到叶路径上的不足节点

[题目](https://leetcode.cn/problems/insufficient-nodes-in-root-to-leaf-paths/)

按题意遍历即可，可以优化为 return le | re

```java
class Solution {
    private int lim;

    private boolean dfs(TreeNode u, int sum) {
        if (u == null) {
            return false;
        }
        sum += u.val;
        if (u.left == null && u.right == null) {
            return sum >= lim;
        }
        boolean exist = false;
        boolean le = dfs(u.left, sum), re = dfs(u.right, sum);
        exist |= le | re;
        if (!le) {
            u.left = null;
        }
        if (!re) {
            u.right = null;
        }
        return exist;
    }

    public TreeNode sufficientSubset(TreeNode root, int limit) {
        lim = limit;
        if (!dfs(root, 0)) {
            root = null;
        }
        return root;
    }
}
```



##### 1090\.受标签影响的最大值

[题目](https://leetcode.cn/problems/largest-values-from-labels/)

不断取能取的最大的，结果不会更差。即使考虑标签不同值相同有多项，这些项不管取哪个标签都不影响更小值，即，如果有一种策略对同一个标签，不取更大取了次大，则不如取更大更优，如 `[9,9,9,8,7,6]` 和 `[1,2,3,1,2,3]` 且 `3,1`，则取二到四项不如一到三更优。

```java
class Solution {
    public int largestValsFromLabels(int[] values, int[] labels, int numWanted, int useLimit) {
        int n = values.length, a[][] = new int[n][2];
        for (int i = 0; i < n; ++i) {
            a[i][0] = values[i];
            a[i][1] = labels[i];
        }
        Arrays.sort(a, (u, v) -> v[0] - u[0]);
        int s = 0;
        HashMap<Integer, Integer> h = new HashMap<>();
        for (int i = 0, j = 0; i < n && j < numWanted; ++i) {
            if (h.getOrDefault(a[i][1], 0) < useLimit) {
                h.put(a[i][1], h.getOrDefault(a[i][1], 0) + 1);
                s += a[i][0];
                ++j;
            }
        }
        return s;
    }
}
```



##### 1377\.T秒后青蛙的位置

[题目](https://leetcode.cn/problems/frog-position-after-t-seconds/)

```java
class Solution {
    private ArrayList<Integer> e[];
    private double ans;
    private int t, target;

    private void dfs(int u, int fa, double p, int d) {
        int sons = e[u].size() - 1;
        if (u == target) {
            if (sons == 0 || (sons > 0 && d == t)) {
                ans = p;
            }
            return;
        }
        if (d >= t) {
            return;
        }
        for (int v : e[u]) {
            if (v != fa) {
                dfs(v, u, p / sons, d + 1);
            }
        }
    }

    @SuppressWarnings("unchecked")
    public double frogPosition(int n, int[][] edges, int t, int target) {
        this.t = t;
        this.target = target;
        e = new ArrayList[n + 1];
        for (int i = 0; i <= n; ++i) {
            e[i] = new ArrayList<>();
        }
        for (int i = 0; i < edges.length; ++i) {
            int u = edges[i][0], v = edges[i][1];
            e[u].add(v);
            e[v].add(u);
        }
        e[1].add(0);
        dfs(1, 0, 1, 0);
        return ans;
    }
}
```



##### 2451\.差值数组不同的字符串

[题目](https://leetcode.cn/problems/odd-string-difference/)

个人写法：

```java
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map.Entry;
class Solution {
    public String oddString(String[] words) {
        HashMap<String, ArrayList<Integer>> h = new HashMap<>();
        for (int i = 0; i < words.length; ++i) {
            byte[] b = words[i].getBytes();
            StringBuilder sb = new StringBuilder();
            for (int j = 1; j < b.length; ++j) {
                int v = b[j] - b[j - 1];
                sb.append(v);
                sb.append(',');
            }
            String s = sb.toString();
            if (!h.containsKey(s)) {
                h.put(s, new ArrayList<>());
            }
            h.get(s).add(i);
        }
        for (Entry<String, ArrayList<Integer>> it : h.entrySet()) {
            if (it.getValue().size() == 1) {
                return words[it.getValue().get(0)];
            }
        }
        return null;
    }
}
```

更优实现：

```java
class Solution {
    public String oddString(String[] words) {
        int[] diff0 = get(words[0]);
        int[] diff1 = get(words[1]);
        if (Arrays.equals(diff0, diff1)) {
            for (int i = 2; i < words.length; i++) {
                if (!Arrays.equals(diff0, get(words[i]))) {
                    return words[i];
                }
            }
        }
        return Arrays.equals(diff0, get(words[2])) ? words[1] : words[0];
    }

    public int[] get(String word) {
        int[] diff = new int[word.length() - 1];
        for (int i = 0; i + 1 < word.length(); i++) {
            diff[i] = word.charAt(i + 1) - word.charAt(i);
        }
        return diff;
    }
}
```



##### 1093\.大样本统计

[题目](https://leetcode.cn/problems/statistics-from-a-large-sample/)

个人：

```java
class Solution {
    public double[] sampleStats(int[] count) {
        double mx = -1, mi = 257, s = 0, mode = 0, mid = 0;
        int mxcnt = 0, num = 0, now = 0;
        for (int i = 0; i < count.length; ++i) {
            if (count[i] > 0) {
                mx = Math.max(mx, i);
                mi = Math.min(mi, i);
                s += (long)count[i] * i;
                num += count[i];
            }
            if (count[i] > mxcnt) {
                mxcnt = count[i];
                mode = i;
            }
        }
        for (int i = 0, pr = 0; i < count.length; ++i) {
            if (count[i] > 0) {
                int l = now + 1, r = now + count[i];
                if (num % 2 == 1) {
                    if (l <= num / 2 + 1 && num / 2 + 1 <= r) {
                        mid = i;
                    }
                } else {
                    if (l <= num / 2 && num / 2 + 1 <= r) {
                        mid = i;
                    } else if (r == num / 2) {
                        pr = i;
                    } else if (l == num / 2 + 1) {
                        mid = (pr + i) / 2.0;
                    }
                }
                now += count[i];
            }
        }
        return new double[] { mi, mx, s / num, mid, mode };
    }
}
```

题解：

```java
class Solution {
    public double[] sampleStats(int[] count) {
        int n = count.length;
        int total = Arrays.stream(count).sum();
        double mean = 0.0;
        double median = 0.0;
        int minnum = 256;
        int maxnum = 0;
        int mode = 0;

        int left = (total + 1) / 2;
        int right = (total + 2) / 2;
        int cnt = 0;
        int maxfreq = 0;
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long) count[i] * i;
            if (count[i] > maxfreq) {
                maxfreq = count[i];
                mode = i;
            }
            if (count[i] > 0) {
                if (minnum == 256) {
                    minnum = i;
                }
                maxnum = i;
            }
            if (cnt < right && cnt + count[i] >= right) {
                median += i;
            }
            if (cnt < left && cnt + count[i] >= left) {
                median += i;
            }
            cnt += count[i];
        }
        mean = (double) sum / total;
        median = median / 2.0;
        return new double[]{minnum, maxnum, mean, median, mode};
    }
}
```



##### 1439\.有序矩阵中的第k个最小数组和

[题目](https://leetcode.cn/problems/find-the-kth-smallest-sum-of-a-matrix-with-sorted-rows/)

个人：优先级队列，共最多 $k=200$ 种状态，每种状态推一次是 $O(n^2)$ 复杂度，加上堆，故 $O(200n^2\log n)$ 时间和 $O(200n)$ 空间。

```java
class Solution {
    public int kthSmallest(int[][] mat, int k) {
        int cnt = 0, n = mat.length, m = mat[0].length;
        PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> a[n] - b[n]);
        HashSet<String> h = new HashSet<>();
        int p[] = new int[n + 1];
        for (int i = 0; i < n; ++i) {
            p[i] = 0;
            p[n] += mat[i][0];
        }
        q.add(p);
        while (!q.isEmpty()) {
            int a[] = q.poll();
            String as = Arrays.toString(a);
            if (h.contains(as)) {
                continue;
            }
            h.add(as);
            if (++cnt == k) {
                return a[n];
            }
            for (int i = 0; i < n; ++i) {
                if (a[i] + 1 >= m) {
                    continue;
                }
                int b[] = Arrays.copyOf(a, n + 1);
                b[n] += mat[i][b[i] + 1] - mat[i][b[i]];
                ++b[i];
                q.add(b);
            }
        }
        return -1;
    }
}
```

一种暴力：设只考虑前 $i$ 行(初始为 $[0]$)下的前 $k$ 小结果是 $a$，将这个结果乘法原理搞一下下一行，然后排序只取前 $k$ 小，不难发现复杂度为 $O(nmk\log nk)$ 和空间 $O(nk)$。

```java
class Solution {
    public int kthSmallest(int[][] mat, int k) {
        var a = new int[]{0};
        for (var row : mat) {
            var b = new int[a.length * row.length];
            int i = 0;
            for (int x : a)
                for (int y : row)
                    b[i++] = x + y;
            Arrays.sort(b);
            if (b.length > k) // 保留最小的 k 个
                b = Arrays.copyOfRange(b, 0, k);
            a = b;
        }
        return a[k - 1];
    }
}
```

上述 for-for 还可以用归并排序合并思想来进一步优化。



参考暴力，最小堆优化实现：

- 每个状态的递推顺序优化，即第一行只能由本行左边推出，其他行只能由上一行同一列推出，避免用哈希表去重。
- 每次只考虑两行，把前 i 行状态压缩成一行。

每次实现的空间是 $O(k)$，时间是 $O(k\log k)$，故总空间不变，时间为 $O(nk\log k)$。

```java
class Solution {
    public int kthSmallest(int[][] mat, int k) {
        var a = new int[]{0};
        for (var row : mat)
            a = kSmallestPairs(row, a, k);
        return a[k - 1];
    }

    // 373. 查找和最小的 K 对数字
    private int[] kSmallestPairs(int[] nums1, int[] nums2, int k) {
        int n = nums1.length, m = nums2.length, sz = 0;
        var ans = new int[Math.min(k, n * m)];
        var pq = new PriorityQueue<int[]>((a, b) -> a[0] - b[0]);
        pq.add(new int[]{nums1[0] + nums2[0], 0, 0});
        while (!pq.isEmpty() && sz < k) {
            var p = pq.poll();
            int i = p[1], j = p[2];
            ans[sz++] = nums1[i] + nums2[j]; // 数对和
            if (j == 0 && i + 1 < n)
                pq.add(new int[]{nums1[i + 1] + nums2[0], i + 1, 0});
            if (j + 1 < m)
                pq.add(new int[]{nums1[i] + nums2[j + 1], i, j + 1});
        }
        return ans;
    }
}
```





二分：设有 $f(s)$ 个不超过 $s$ 的数组和，则随着 $s$ 的增大，显然 $f(s)$ 非严格递增。则二分 $s$，若 $f(s)\ge k$，则答案至多为 $s$，若 $f(s) < k$，则答案至少为 $s+1$。

```java
class Solution {
    private int leftK;

    public int kthSmallest(int[][] mat, int k) {
        int sl = 0, sr = 0;
        for (var row : mat) {
            sl += row[0];
            sr += row[row.length - 1];
        }
        // 二分模板 https://www.bilibili.com/video/BV1AP41137w7/
        int left = sl - 1, right = sr; // 开区间 (sl-1,sr)
        while (left + 1 < right) { // 开区间不为空
            // 循环不变量：
            // f(left) < k
            // f(right) >= k
            int mid = (left + right) >>> 1;
            leftK = k;
            if (dfs(mat, mat.length - 1, mid - sl)) // 先把第一列的所有数都选上
                right = mid; // 二分范围缩小至开区间 (left, mid)
            else // f(mid) < k
                left = mid; // 二分范围缩小至开区间 (mid, right)
        }
        return right;
    }

    // 返回是否找到 k 个子数组和
    private boolean dfs(int[][] mat, int i, int s) {
        if (i < 0) // 能递归到这里，说明数组和不超过二分的 mid
            return --leftK == 0; // 是否找到 k 个
        for (int x : mat[i]) { // 「枚举选哪个」，注意 mat[i] 是有序的
            if (x - mat[i][0] > s) // 选 x 不选 mat[i][0]
                break; // 剪枝：后面的元素更大，无需枚举
            if (dfs(mat, i - 1, s - (x - mat[i][0]))) // 选 x 不选 mat[i][0]
                return true; // 找到 k 个就一直返回 true，不再递归
        }
        return false;
    }
}
```

对检验函数 dfs，从最后一行开始，暴力搜索，看能不能找到至少 k 条路径，使得路径和不小于 s。显然每条路径长 n，故每次搜索复杂度为 $O(nk)$。

如果确实有不少于 k 个，就找更小的 s，并保留答案。

二分次数是值域，故总复杂度为 $O(nk\log\sum_j mat_{n,j})$，空间是递归栈 $O(n)$。



##### 1110\.删点成林

[题目](https://leetcode.cn/problems/delete-nodes-and-return-forest/)

个人写法：

```java
class Solution {
    private HashSet<Integer> h;
    private List<TreeNode> res;

    private void dfs(TreeNode u, TreeNode fa) {
        if (u == null) {
            return;
        }
        boolean die = h.contains(u.val);
        TreeNode pv = die ? null : u;
        dfs(u.left, pv);
        dfs(u.right, pv);
        if (u.left != null && h.contains(u.left.val)) {
            u.left = null;
        }
        if (u.right != null && h.contains(u.right.val)) {
            u.right = null;
        }
        if (fa == null && !die) {
            res.add(u);
        }
    }

    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        Integer[] del = Arrays.stream(to_delete).boxed().toArray(Integer[]::new);
        h = new HashSet<>(Arrays.asList(del));
        res = new ArrayList<>();
        dfs(root, null);
        return res;
    }
}
```

优雅写法：

```java
class Solution {
    public List<TreeNode> delNodes(TreeNode root, int[] toDelete) {
        var ans = new ArrayList<TreeNode>();
        var s = new HashSet<Integer>();
        for (int x : toDelete) s.add(x);
        if (dfs(ans, s, root) != null) ans.add(root);
        return ans;
    }

    private TreeNode dfs(List<TreeNode> ans, Set<Integer> s, TreeNode node) {
        if (node == null) return null;
        node.left = dfs(ans, s, node.left);
        node.right = dfs(ans, s, node.right);
        if (!s.contains(node.val)) return node;
        if (node.left != null) ans.add(node.left);
        if (node.right != null) ans.add(node.right);
        return null;
    }
}
```

##### 1130\.叶值的最小代价生成树

[题目](https://leetcode.cn/problems/minimum-cost-tree-from-leaf-values/)

容易想到区间 DP 然后轻而易举弄出来：

```java
class Solution {
    public int mctFromLeafValues(int[] a) {
        int n = a.length, mx[][] = new int[n][n];// orST表
        for (int i = 0; i < n; ++i) {
            mx[i][i] = a[i];
            for (int j = i + 1; j < n; ++j) {
                mx[i][j] = Math.max(mx[i][j - 1], a[j]);
            }
        }
        int dp[][] = new int[n][n];
        for (int len = 2; len <= n; ++len) {
            for (int l = 0, r = len - 1; r < n; ++l, ++r) {
                dp[l][r] = Integer.MAX_VALUE;
                for (int k = l; k < r; ++k) {
                    int v = dp[l][k] + dp[k + 1][r] + mx[l][k] * mx[k + 1][r];
                    dp[l][r] = Math.min(dp[l][r], v);
                }
            }
        }
        return dp[0][n - 1];
    }
}
```

操作步骤：不断合并 $a$ 的相邻数，代价为两数乘积，**合并后的数为两数最大值** ，直到 $a$ 只剩一个数。

若 $a_{i-1}\ge a_i$ 且 $a_i\le a_{i+1}$，若 $a_{i-1}\le a_{i+1}$，那么：

- 先合并左边再合并右边的代价为 $a_{i-1}a_i+a_{i-1}a_{i+1}$
- 先合并右边再合并左边的代价为 $a_{i+1}a_i+a_{i-1}a_{i+1}$

显然先合并左边的代价更小，所以先合并左边更优。如果 $a_{i-1} > a_{i+1}$ 则先合并右边更优。

维护严格递减单调栈，遍历 $a$，设当前值是 $x$，若栈顶 $y\le x$，那么将栈顶 $y$ 出栈，然后新栈顶为 $z$。

- 若 $z$ 不存在或 $z > x$，根据上述规则，后者显然合右更好，直接合掉。对 $z$ 不存在，在当前子问题下，$y$ 选择合掉不会更差，否则新的 $x$ 不会更小。
- 若 $z\le x$，根据上述规则，合左即 $yz$。

合并后，新的 $y$ 继续判断，直到 $y > x$ 或栈空。到最后时，剩下的栈内元素递减，故不断合并栈顶即可。

```java
class Solution {
    public int mctFromLeafValues(int[] arr) {
        int res = 0;
        Deque<Integer> stk = new ArrayDeque<Integer>();
        for (int x : arr) {
            while (!stk.isEmpty() && stk.peek() <= x) {
                int y = stk.pop();
                if (stk.isEmpty() || stk.peek() > x) {
                    res += y * x;
                } else {
                    res += stk.peek() * y;
                }
            }
            stk.push(x);
        }
        while (stk.size() >= 2) {
            int x = stk.pop();
            res += stk.peek() * x;
        }
        return res;
    }
}
```



##### 2517\.礼盒的最大甜蜜度

[题目](https://leetcode.cn/problems/maximum-tastiness-of-candy-basket/)

二分最大甜蜜度，然后每次贪心搜索有序集合里最小的下一个可选元素，复杂度 $O(n\log^2n)$。

```java
class Solution {
    public int maximumTastiness(int[] price, int k) {
        Integer[] a = Arrays.stream(price).boxed().toArray(Integer[]::new);
        TreeSet<Integer> h = new TreeSet<>(Arrays.asList(a));
        int lf = 1, rf = h.last(), ans = 0;
        while (lf <= rf) {
            int cf = (lf + rf) >> 1;
            boolean ok = true;
            for (int pr = h.first(), i = 1; i < k && ok; ++i) {
                Integer v = h.ceiling(pr + cf);
                if (null == v) {
                    ok = false;
                } else {
                    pr = v;
                }
            }
            if (ok) {
                lf = cf + 1;
                ans = cf;
            } else {
                rf = cf - 1;
            }
        }
        return ans;
    }
}
```

更优解：不用再二分套二分，直接遍历排序后原数组，当当前元素差大于甜蜜度时，更新 pr 和 cnt。

```java
class Solution {
    public int maximumTastiness(int[] price, int k) {
        Arrays.sort(price);
        int left = 0, right = price[price.length - 1] - price[0];
        while (left < right) {
            int mid = (left + right + 1) / 2;
            if (check(price, k, mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }

    public boolean check(int[] price, int k, int tastiness) {
        int prev = Integer.MIN_VALUE / 2;
        int cnt = 0;
        for (int p : price) {
            if (p - prev >= tastiness) {
                cnt++;
                prev = p;
            }
        }
        return cnt >= k;
    }
}
```



##### 2559\.统计范围内的元音字符串数目

[题目](https://leetcode.cn/problems/count-vowel-strings-in-ranges/)

前缀和模板题。

```java
class Solution {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int m = queries.length, n = words.length;
        int s[] = new int[n + 1], q[] = new int[m];
        Character v[] = new Character[] { 'a', 'e', 'i', 'o', 'u' };
        HashSet<Character> vowel = new HashSet<>(Arrays.asList(v));
        for (int i = 0; i < n; ++i) {
            boolean ok = vowel.contains(words[i].charAt(0));
            ok &= vowel.contains(words[i].charAt(words[i].length() - 1));
            s[i + 1] += s[i] + (ok ? 1 : 0);
        }
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1];
            q[i] = s[r + 1] - s[l];
        }
        return q;
    }
}
```



##### 1156\.单字符重复子串的最大长度

[题目](https://leetcode.cn/problems/swap-for-longest-repeated-character-substring/)

小模拟：分类讨论。

对每个字符，设其连续长度为 $cnt$，间隔长度为 $blo$。有几种情况：

1. 不交换，取 $\max cnt$
2. 交换一个拼接到最长 $cnt$ 去，当 $|cnt| \ge 2$ 时，取 $\max cnt+1$
3. 如果 $blo$ 恰为 $1$，相邻两段合在一起，当 $blo_i=1$ 时取 $\max cnt_{i}+cnt_{i-1}$
4. 如果除了这两段还有第三段，抽一个替换掉 $blo$ 取 $\max cnt_{i}+cnt_{i-1}+1$

时间复杂度 $O(26n)$，空间复杂度 $O(n)$。

```java
class Solution {
    @SuppressWarnings("unchecked")
    public int maxRepOpt1(String text) {
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            ArrayList<Integer> cnt = new ArrayList<>();
            ArrayList<Integer> blo = new ArrayList<>();
            char t = (char) ('a' + i);
            int cn = 0, bl = 0;
            for (int j = 0; j < text.length(); ++j) {
                char s = text.charAt(j);
                if (s == t) {
                    if (cn++ == 0) {
                        blo.add(bl);
                        bl = 0;
                    }
                } else {
                    if (cn > 0) {
                        cnt.add(cn);
                        cn = 0;
                    }
                    ++bl;
                }
            }
            if (cn > 0) {
                cnt.add(cn);
            }
            blo.add(bl);

            int mx = 0;
            for (int j = 0; j < cnt.size(); ++j) {
                mx = Math.max(mx, cnt.get(j));
            }
            mx += cnt.size() > 1 ? 1 : 0;
            for (int j = 1; j < cnt.size(); ++j) {
                if (blo.get(j) == 1) {
                    int x = cnt.get(j), y = cnt.get(j - 1);
                    int s = x + y;
                    s += cnt.size() > 2 ? 1 : 0;
                    mx = Math.max(mx, s);
                }
            }
            ans = Math.max(ans, mx);
        }
        return ans;
    }
}
```

优化：只遍历一次，滑动窗口。

```java
class Solution {
    public int maxRepOpt1(String text) {
        Map<Character, Integer> count = new HashMap<Character, Integer>();
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            count.put(c, count.getOrDefault(c, 0) + 1);
        }

        int res = 0;
        for (int i = 0; i < text.length(); ) {
            // step1: 找出当前连续的一段 [i, j)
            int j = i;
            while (j < text.length() && text.charAt(j) == text.charAt(i)) {
                j++;
            }
            int curCnt = j - i;

            // step2: 如果这一段长度小于该字符出现的总数，并且前面或后面有空位，则使用 curCnt + 1 更新答案
            if (curCnt < count.getOrDefault(text.charAt(i), 0) && (j < text.length() || i > 0)) {
                res = Math.max(res, curCnt + 1);
            }

            // step3: 找到这一段后面与之相隔一个不同字符的另一段 [j + 1, k)，如果不存在则 k = j + 1 
            int k = j + 1;
            while (k < text.length() && text.charAt(k) == text.charAt(i)) {
                k++;
            }
            res = Math.max(res, Math.min(k - i, count.getOrDefault(text.charAt(i), 0)));
            i = j;
        }
        return res;
    }
}
```

##### 2611\.老鼠和奶酪

[题目](https://leetcode.cn/problems/mice-and-cheese/)

个人做法：自定义排序后贪心。

```java
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int n = reward1.length, s = 0;
        Integer a[] = new Integer[n];
        for (int i = 0; i < n; ++i) {
            a[i] = i;
        }
        Arrays.sort(a, (x, y) -> (reward1[y] - reward2[y]) - (reward1[x] - reward2[x]));
        for (int i = 0; i < k; ++i) {
            s += reward1[a[i]];
        }
        for (int i = k; i < n; ++i) {
            s += reward2[a[i]];
        }
        return s;
    }
}
```

同样的思路，不同的实现：先让鸭脖2全部吃了，然后排序把前k优让它吐出来给鸭脖1吃。

```java
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int ans = 0;
        int n = reward1.length;
        int[] diffs = new int[n];
        for (int i = 0; i < n; i++) {
            ans += reward2[i];
            diffs[i] = reward1[i] - reward2[i];
        }
        Arrays.sort(diffs);
        for (int i = 1; i <= k; i++) {
            ans += diffs[n - i];
        }
        return ans;
    }
}
```

思路是一样的，但是只动态维护前 k 个，多的直接踢了，使得时间 $O(n\log n)$ 优化成 $O(n\log k)$ 且空间 $O(n)$ 优化成 $O(k)$ 

```java
class Solution {
    public int miceAndCheese(int[] reward1, int[] reward2, int k) {
        int ans = 0;
        int n = reward1.length;
        PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
        for (int i = 0; i < n; i++) {
            ans += reward2[i];
            pq.offer(reward1[i] - reward2[i]);
            if (pq.size() > k) {
                pq.poll();
            }
        }
        while (!pq.isEmpty()) {
            ans += pq.poll();
        }
        return ans;
    }
}
```

##### 1240\.铺瓷砖

[题目](https://leetcode.cn/problems/tiling-a-rectangle-with-the-fewest-squares/)

设 $h(n,m)$ 是铺满矩形所需的正方形最少数目，有：$h(n,m)\le \max(n,m)$

证明：

1. 若 $n=m$ 显然 $h(n,m)=1$
2. 若$n > m$，填一个 $m\times m$ 使得 $h(n,m)\le 1+h(n-m,m)$，每次最少让 $\max(n,m)$ 减少一，故证毕。

爆搜：从 $(0,0)$ 开始从大到小地覆盖正方形，然后搜索右边的下一个位置

```java
class Solution {
    int ans;

    public int tilingRectangle(int n, int m) {
        ans = Math.max(n, m);
        boolean[][] rect = new boolean[n][m];
        dfs(0, 0, rect, 0);
        return ans;
    }

    public void dfs(int x, int y, boolean[][] rect, int cnt) {
        int n = rect.length, m = rect[0].length;
        if (cnt >= ans) {
            return;
        }        
        if (x >= n) {
            ans = cnt; 
            return;
        }
        /* 检测下一行 */        
        if (y >= m) {
            dfs(x + 1, 0, rect, cnt); 
            return;
        }        
        /* 如当前已经被覆盖，则直接尝试下一个位置 */
        if (rect[x][y]) {
            dfs(x, y + 1, rect, cnt);
            return;
        }
    
        for (int k = Math.min(n - x, m - y); k >= 1 && isAvailable(rect, x, y, k); k--) {
            /* 将长度为 k 的正方形区域标记覆盖 */
            fillUp(rect, x, y, k, true);
            /* 跳过 k 个位置开始检测 */
            dfs(x, y + k, rect, cnt + 1);
            fillUp(rect, x, y, k, false);
        }
    }

    public boolean isAvailable(boolean[][] rect, int x, int y, int k) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (rect[x + i][y + j]) {
                    return false;
                }
            }
        }
        return true;
    }

    public void fillUp(boolean[][] rect, int x, int y, int k, boolean val) {
        for (int i = 0; i < k; i++){
            for (int j = 0; j < k; j++) {
                rect[x + i][y + j] = val;
            }
        }
    }
}
```



##### 2699\.修改图中的边权

[题目](https://leetcode.cn/problems/modify-graph-edge-weights/)

无解的充要条件：

1. 所有边赋为 $1$，如果仍然大于 $target$，因为增加边权不会让答案更小，故无解。
2. 所有边赋为 $\infty$，若仍然小于 $target$，因为减少边权不会让答案更大，故无解。

设在上述第一种情况跑出来的 $source$ 单源最短路是 $d_{i,0}$，当有解时，根据 dijkstra 的特性，只要按照 dijkstra 遍历顺序去修改边，就不会在修改后对已确定的最短路产生影响。

所以在第一种情况下，再跑一遍 dijkstra，此时跑出的结果为 $d_{i,1}$，对可修改的边 $(u,v)$，设边权改为 $w$，则所求路径 $s\to \cdots\to x\to y\to\cdots\to t$ 由三部分组成：

1. $d_{x,1}$ 即 $s\to\cdots\to x$

2. $x\to y = w$

3. $y\to\cdots\to t$，如果 $y$ 确实在最短路上，对所有边赋 $1$ 的最短路是 $d_{t,0}$，其在后半段的最短路长度可以直接路径相减，即 $d_{t,0}-d_{y,0}$。

   如果 $y$ 不在最短路上，那么这次修改无效，可以直接忽略修改。

要满足题意，即构造 $d_{x,1}+w+d_{t,0}-d_{y,0}=target$，即 $w=target-d_{t,0}+d_{y,0}-d_{x,1}$。

因为是稠密图，所以暴力 dijkstra 比堆优化的更优，所以直接用暴力 dijkstra 即可。

如何理解使用 $d_{?,0}$：

- 实际上是一个贪心的过程，因为最初的图是能达到的最小图，所以接下来需要增大一些 $w$，并且尽可能地往大的去凑，肯定比凑小的不会更差。

- 如果最短路必经只有 $w$，每个 $w$ 增长到某个特定值，就能在理想情况下只增它达到目标值，那么这个理想值就是后面的都不动(维持 $d_{t,0}-d_{y,0}$)，且前面动过的也不再动了，的情况下凑方程达到的值。

- 如果 $w$ 是有一个上限的(即大到一定程度最短路就更改，而不再走 $w$)，考虑唯一的一条可变边是 $x\to y$，且唯一岔路是 $x\to p\to y$(总长度为 $10$)，那么显然只有 $1\le w\le 9$ 可选，即如果 $w$ 最大只能变成 $9$，否则最短路不生效。

  这时候不妨设 $d_{x,1}=d_{x,0}$(因为前面没有可变的边) $=100$ 且 $d_{t,0}-d_{y,0}=100$，且后面也没有可变的边，若 $target=205$，显然算出 $w=5$，刚好凑够。

  若 $target=222$，则任意 $w\ge 10$ 的结果都等价于这条边只贡献 $10$，那么我即使把 $w$ 拉到无穷，它也只对 $target$ 贡献 $10$(因为根本不走它了)，所以直接赋值即可，不需要考虑后效性之类的。

  那么，因为 $w$ 的变动，会使得最短路改走，使得后续的 $d_{x,1}$ 增大。

因此上述策略是正确的。

```java
class Solution {
    public int[][] modifiedGraphEdges(int n, int[][] edges, int source, int destination, int target) {
        List<int[]> g[] = new ArrayList[n];
        Arrays.setAll(g, e -> new ArrayList<>());
        for (int i = 0; i < edges.length; i++) {
            int x = edges[i][0], y = edges[i][1];
            g[x].add(new int[]{y, i});
            g[y].add(new int[]{x, i}); // 建图，额外记录边的编号
        }

        var dis = new int[n][2];
        for (int i = 0; i < n; i++)
            if (i != source)
                dis[i][0] = dis[i][1] = Integer.MAX_VALUE;

        dijkstra(g, edges, destination, dis, 0, 0);
        int delta = target - dis[destination][0];
        if (delta < 0) // -1 全改为 1 时，最短路比 target 还大
            return new int[][]{};

        dijkstra(g, edges, destination, dis, delta, 1);
        if (dis[destination][1] < target) // 最短路无法再变大，无法达到 target
            return new int[][]{};

        for (var e : edges)
            if (e[2] == -1) // 剩余没修改的边全部改成 1
                e[2] = 1;
        return edges;
    }

    // 朴素 Dijkstra 算法
    // 这里 k 表示第一次/第二次
    private void dijkstra(List<int[]> g[], int[][] edges, int destination, int[][] dis, int delta, int k) {
        int n = g.length;
        var vis = new boolean[n];
        for (; ; ) {
            // 找到当前最短路，去更新它的邻居的最短路
            // 根据数学归纳法，dis[x][k] 一定是最短路长度
            int x = -1;
            for (int i = 0; i < n; ++i)
                if (!vis[i] && (x < 0 || dis[i][k] < dis[x][k]))
                    x = i;
            if (x == destination) // 起点 source 到终点 destination 的最短路已确定
                return;
            vis[x] = true; // 标记，在后续的循环中无需反复更新 x 到其余点的最短路长度
            for (var e : g[x]) {
                int y = e[0], eid = e[1];
                int wt = edges[eid][2];
                if (wt == -1)
                    wt = 1; // -1 改成 1
                if (k == 1 && edges[eid][2] == -1) {
                    // 第二次 Dijkstra，改成 w
                    int w = delta + dis[y][0] - dis[x][1];
                    if (w > wt)
                        edges[eid][2] = wt = w; // 直接在 edges 上修改
                }
                // 更新最短路
                dis[y][k] = Math.min(dis[y][k], dis[x][k] + wt);
            }
        }
    }
}
```



二分+最短路：

设可修改的边的权列表是 $w$，为书写方便令 $D=target$，则 $w$ 的所有可能性不超过 $O(D^2)$ 种，分别为：$[1,1,\cdots,1],[2,1,\cdots,1],\cdots,[D,1,\cdots,1],[D,2,\cdots,1],\cdots[D,D,\cdots,D]$ 种。

注意到 $[1,D,\cdots,1]$ 这样的可能性不计，这是因为只用上述顺序在有解的情况下一定可以构造出，且每次增加总 $\sum w$ 为 $1$ 下，最多只增加 $1$ 的答案最短路长度。也就是说不需要指数级的所有可能性都枚举出来，只需要枚举所有可能性的一个特定 $D^2$ 子集就一定能覆盖到有解的情况。

复杂度为 $O(2\log Dn^2)$。

```java
class Solution {
    public int[][] modifiedGraphEdges(int n, int[][] edges, int source, int destination, int target) {
        int k = 0;
        for (int[] e : edges) {
            if (e[2] == -1) {
                ++k;
            }
        }

        if (dijkstra(source, destination, construct(n, edges, 0, target)) > target) {
            return new int[0][];
        }
        if (dijkstra(source, destination, construct(n, edges, (long) k * (target - 1), target)) < target) {
            return new int[0][];
        }

        long left = 0, right = (long) k * (target - 1), ans = 0;
        while (left <= right) {
            long mid = (left + right) / 2;
            if (dijkstra(source, destination, construct(n, edges, mid, target)) >= target) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for (int[] e : edges) {
            if (e[2] == -1) {
                if (ans >= target - 1) {
                    e[2] = target;
                    ans -= target - 1;
                } else {
                    e[2] = (int) (1 + ans);
                    ans = 0;
                }
            }
        }

        return edges;
    }

    public long dijkstra(int source, int destination, int[][] adjMatrix) {
        // 朴素的 dijkstra 算法
        // adjMatrix 是一个邻接矩阵
        int n = adjMatrix.length;
        long[] dist = new long[n];
        Arrays.fill(dist, Integer.MAX_VALUE / 2);
        boolean[] used = new boolean[n];
        dist[source] = 0;

        for (int round = 0; round < n - 1; ++round) {
            int u = -1;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }
            used[u] = true;
            for (int v = 0; v < n; ++v) {
                if (!used[v] && adjMatrix[u][v] != -1) {
                    dist[v] = Math.min(dist[v], dist[u] + adjMatrix[u][v]);
                }
            }
        }

        return dist[destination];
    }

    public int[][] construct(int n, int[][] edges, long idx, int target) {
        // 需要构造出第 idx 种不同的边权情况，返回一个邻接矩阵
        int[][] adjMatrix = new int[n][n];
        for (int i = 0; i < n; ++i) {
            Arrays.fill(adjMatrix[i], -1);
        }
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if (w != -1) {
                adjMatrix[u][v] = adjMatrix[v][u] = w;
            } else {
                if (idx >= target - 1) {
                    adjMatrix[u][v] = adjMatrix[v][u] = target;
                    idx -= (target - 1);
                } else {
                    adjMatrix[u][v] = adjMatrix[v][u] = (int) (1 + idx);
                    idx = 0;
                }
            }
        }
        return adjMatrix;
    }
}
```



##### 1170\.比较字符串最小字母出现频次

[题目](https://leetcode.cn/problems/compare-strings-by-frequency-of-the-smallest-character/)

个人写法：前缀和、两次扫描求 f

```java
class Solution {
    private int f(String s) {
        byte t = 'z';
        for (byte c : s.getBytes()) {
            t = (byte) Math.min(c, t);
        }
        int cnt = 0;
        for (byte c : s.getBytes()) {
            cnt += c == t ? 1 : 0;
        }
        return cnt;
    }

    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int cnt[] = new int[12], n = words.length, m = queries.length;
        for (int i = 0; i < n; ++i) {
            ++cnt[f(words[i])];
        }
        for (int i = 1; i < cnt.length; ++i) {
            cnt[i] += cnt[i - 1];
        }
        int ans[] = new int[m];
        for (int i = 0, t = cnt.length - 1; i < m; ++i) {
            ans[i] = cnt[t] - cnt[f(queries[i])];
        }
        return ans;
    }
}
```

更优写法：后缀和、一次扫描

```java
class Solution {
    public int[] numSmallerByFrequency(String[] queries, String[] words) {
        int[] count = new int[12];
        for (String s : words) {
            count[f(s)]++;
        }
        for (int i = 9; i >= 1; i--) {
            count[i] += count[i + 1];
        }
        int[] res = new int[queries.length];
        for (int i = 0; i < queries.length; i++) {
            String s = queries[i];
            res[i] = count[f(s) + 1];
        }
        return res;
    }

    public int f(String s) {
        int cnt = 0;
        char ch = 'z';
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c < ch) {
                ch = c;
                cnt = 1;
            } else if (c == ch) {
                cnt++;
            }
        }
        return cnt;
    }
}
```

##### 1171\.从链表中删去总和值为零的连续节点

[题目](https://leetcode.cn/problems/remove-zero-sum-consecutive-nodes-from-linked-list/)

究极暴力：先把链表转数组，有子段为零的条件为前缀和满足 $s_r-s_{l-1}=0$，所以维护前缀和哈希表，如果当前前缀和 $s_r$ 与之前某个 $s_{l-1}$ 相等，删掉 $[l,r]$。(因为遇到重复就删掉了，所以不需要考虑 map 重复键值问题)。这个过程是 $O(n)$ 的。每次执行这个过程会让长度减小，最多执行 $O(0.5n)$ 次这个过程，故总复杂度为 $O(n^2)$。做完后再转回链表。

```java
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        ArrayList<Integer> a = new ArrayList<>();
        for (ListNode it = head; it != null; it = it.next) {
            a.add(it.val);
        }
        for (;;) {
            boolean del = false;
            HashMap<Integer, Integer> h = new HashMap<>();
            h.put(0, -1);
            for (int i = 0, s = 0; i < a.size(); ++i) {
                s += a.get(i);
                if (h.containsKey(s)) {
                    ArrayList<Integer> b = new ArrayList<>();
                    int l = h.get(s);
                    for (int j = 0; j < a.size(); ++j) {
                        if (j <= l || j > i) {
                            b.add(a.get(j));
                        }
                    }
                    a = b;
                    del = true;
                    break;
                }
                h.put(s, i);
            }
            if (!del) {
                break;
            }
        }
        ListNode hd = new ListNode(), it = hd;
        for (int v : a) {
            it.next = new ListNode(v);
            it = it.next;
        }
        return hd.next;
    }
}
```

题解：维护每个前缀和最右的位置，如果超过两个前缀和相等，最左的和最右的一删肯定可以解。如果没有相等的，就原地 TP。复杂度 $O(n)$。

```java
class Solution {
    public ListNode removeZeroSumSublists(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        Map<Integer, ListNode> seen = new HashMap<>();
        int prefix = 0;
        for (ListNode node = dummy; node != null; node = node.next) {
            prefix += node.val;
            seen.put(prefix, node);
        }
        prefix = 0;
        for (ListNode node = dummy; node != null; node = node.next) {
            prefix += node.val;
            node.next = seen.get(prefix).next;
        }
        return dummy.next;
    }
}
```

##### 1483\.树节点的第k个祖先

[题目](https://leetcode.cn/problems/kth-ancestor-of-a-tree-node/)

个人实现：

```java

class TreeAncestor {
    private int m, fa[][], lg[], d[];
    private ArrayList<Integer> e[];

    private void dfs(int u, int f) {
        fa[u][0] = f;
        d[u] = d[f] + 1;
        for (int i = 1, ie = lg[d[u]]; i <= ie; ++i) {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
//            System.out.println("fa[" + u + "][" + i + "]=" + fa[u][i]);
        }
        for (int v : e[u]) {
            if (v != f) {
                dfs(v, u);
            }
        }
    }

    @SuppressWarnings("unchecked")
    public TreeAncestor(int n, int[] parent) {
        e = new ArrayList[n];
        for (int i = 0; i < n; ++i) {
            e[i] = new ArrayList<>();
        }
        for (int u = 1, v; u < n; ++u) {
            v = parent[u];
            e[u].add(v);
            e[v].add(u);
        }
        m = (int) Math.ceil(Math.log(n)) + 1;
        fa = new int[n][m];
        lg = new int[n + 1];
        d = new int[n];
        for (int i = 1; i <= n; ++i) {
            lg[i] = lg[i / 2] + 1;
        }
        dfs(0, 0);
    }

    public int getKthAncestor(int u, int k) {
        if (d[u] <= k) {
            return -1;
        }
//        System.out.println(u + " " + lg[k] + " " + k);
        for (int i = lg[k], t = k; i >= 0; --i) {
            if ((1 << i) <= t) {
//                System.out.println("Jump " + (1 << i));
                u = fa[u][i];
                t -= 1 << i;
            }
        }
        return u;
    }
}
```

官方实现：

```java
class TreeAncestor {
    static final int LOG = 16;
    int[][] ancestors;

    public TreeAncestor(int n, int[] parent) {
        ancestors = new int[n][LOG];
        for (int i = 0; i < n; i++) {
            Arrays.fill(ancestors[i], -1);
        }
        for (int i = 0; i < n; i++) {
            ancestors[i][0] = parent[i];
        }
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (ancestors[i][j - 1] != -1) {
                    ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
                }
            }
        }            
    }

    public int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if (((k >> j) & 1) != 0) {
                node = ancestors[node][j];
                if (node == -1) {
                    return -1;
                }
            }
        }
        return node;
    }
}
```

##### 2475\.数组中不等三元组的数目

[题目](https://leetcode.cn/problems/number-of-unequal-triplets-in-array/)

暴力 $O(n^3)$

```java
class Solution {
    public int unequalTriplets(int[] nums) {
        int cnt = 0, n = nums.length;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    cnt += nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k] ? 1 : 0;
                }
            }
        }
        return cnt;
    }
}
```

排序，维护相等区间 $[i,j)$，长度为 $j-i$，它左边的长度是 $i$，右边的长度是 $n-j$，故总个数为 $i(j-i)(n-j)$，复杂度 $O(n\log n)$

```java
class Solution {
    public int unequalTriplets(int[] nums) {
        Arrays.sort(nums);
        int res = 0, n = nums.length;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && nums[j] == nums[i]) {
                j++;
            }
            res += i * (j - i) * (n - j);
        }
        return res;
    }
}
```

哈希表：设当前元素有 $v$ 个，之前遍历过的总元素有 $t$ 个，则未遍历过的元素有 $n-t-v$ 个，即 $tv(n-t-v)$。复杂度 $O(n)$

```java
class Solution {
    public int unequalTriplets(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        for (int x : nums) {
            count.merge(x, 1, Integer::sum);
        }
        int res = 0, n = nums.length, t = 0;
        for (Map.Entry<Integer, Integer> entry : count.entrySet()) {
            res += t * entry.getValue() * (n - t - entry.getValue());
            t += entry.getValue();
        }
        return res;
    }
}
```

##### 1375. 二进制字符串前缀一致的次数

[题目](https://leetcode.cn/problems/number-of-times-binary-string-is-prefix-aligned/)

树状数组：

```java
class Fenwick {
    private int a[], n;

    public Fenwick(int n) {
        this.n = n;
        a = new int[n + 1];
    }

    public void add(int i, int v) {
        for (; i <= n; i += i & -i) {
            a[i] += v;
        }
    }

    public int query(int r) {
        int res = 0;
        for (; r > 0; r -= r & -r) {
            res += a[r];
        }
        return res;
    }

    public int query(int l, int r) {
        return query(r) - query(l - 1);
    }
}

class Solution {
    public int numTimesAllBlue(int[] flips) {
        int n = flips.length, cnt = 0;
        Fenwick t = new Fenwick(n);
        for (int i = 0; i < n; ++i) {
            t.add(flips[i], 1);
            cnt += t.query(1, i + 1) == i + 1 ? 1 : 0;
        }
        return cnt;
    }
}
```

更优解：注意到当满足条件时，必然是 $[1,i]$ 全 $1$，换句话说其他位全 $0$，即 max 恰好为 $i$，所以维护 max 即可。

```java
class Solution {
    public int numTimesAllBlue(int[] flips) {
        int ans = 0, mx = 0, n = flips.length;
        for (int i = 0; i < n; i++) {
            mx = Math.max(mx, flips[i]);
            if (mx == i + 1) ans++;
        }
        return ans;
    }
}
```

##### 1177\.构建回文串检测

[题目](https://leetcode.cn/problems/can-make-palindrome-from-substring/)

一个子串重排后最少需要多少次修改能成为回文串？

首先成对一定能消，所以每个字符出现次数 $\&1$。如果串长是奇数还能再减掉 $1$(回文中心)，最后每修改一次能消掉两个不相等的，故总最小修改次数为：
$$
\lceil\dfrac{(\sum_icnt_i\&1)-[len\&1]}{2}\rceil=\lfloor\dfrac{\sum_icnt_i\&1}2\rfloor
$$
使用前缀和维护 $26$ 个 $cnt$，总复杂度为 $O((n+m)|s|)$，代码为：

```java
class Solution {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        int n = s.length(), cnt[][] = new int[26][n + 1];
        for (int i = 0; i < n; ++i) {
            int c = s.charAt(i) - 'a';
            for (int j = 0; j < 26; ++j) {
                cnt[j][i + 1] += cnt[j][i] + (c == j ? 1 : 0);
            }
        }
        int m = queries.length;
        Boolean ans[] = new Boolean[m];
        for (int i = 0; i < m; ++i) {
            int l = queries[i][0], r = queries[i][1], k = queries[i][2], t = 0;
            for (int j = 0; j < 26; ++j) {
                t += ((cnt[j][r + 1] - cnt[j][l]) % 2 == 1 ? 1 : 0);
            }
            t -= (r - l + 1) % 2 == 1 ? 1 : 0;
            ans[i] = (t + 1) / 2 <= k;
        }
        return Arrays.asList(ans);
    }
}
```

优化：由于只关心每种字符出现次数的奇偶性，所以可以把前缀和压成一个 bit 位，低 $i$ 位表示第 $i$ 个字母出现次数的奇偶性。那么前缀异或 $s_r\oplus s_{l-1}$ 可以表明子段 $[l,r]$ 的奇偶性，优化成 $O((n+m)\lceil\dfrac{C}{64}\rceil)$，其中 $C=26$。

```java
class Solution {
    public List<Boolean> canMakePaliQueries(String s, int[][] queries) {
        int n = s.length();
        var sum = new int[n + 1];
        for (int i = 0; i < n; i++) {
            int bit = 1 << (s.charAt(i) - 'a');
            sum[i + 1] = sum[i] ^ bit;
        }

        var ans = new ArrayList<Boolean>(queries.length); // 预分配空间
        for (var q : queries) {
            int left = q[0], right = q[1], k = q[2];
            int m = Integer.bitCount(sum[right + 1] ^ sum[left]);
            ans.add(m / 2 <= k);
        }
        return ans;
    }
}
```

##### 1494\.并行课程II

[题目](https://leetcode.cn/problems/parallel-courses-ii/)

个人代码：完全暴力，复杂度为大约 $O(2^n C_n^k)$，虽然实际表现没这么差，BFS 尾部剪枝能卡过去

```java
class Solution {
    public int minNumberOfSemesters(int n, int[][] relations, int k) {
        int dp[] = new int[1 << n], t = (1 << n) - 1;
        Arrays.fill(dp, Integer.MAX_VALUE);
        @SuppressWarnings("unchecked")
        ArrayList<Integer> e[] = new ArrayList[n + 1];
        for (int i = 1; i <= n; ++i) {
            e[i] = new ArrayList<>();
        }
        for (int i = 0; i < relations.length; ++i) {
            int u = relations[i][0], v = relations[i][1];
            e[v].add(u);
        }
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        dp[0] = 0;
        while (!q.isEmpty()) {
            int s = q.poll(), cnt = 0;
//            System.out.println(s + " " + dp[s]);
            if (s == t) {
                break;
            }
            boolean vis[] = new boolean[n + 1];
            for (int i = 0; i < n; ++i) {
                vis[i + 1] = (s & (1 << i)) > 0;
            }
            boolean avail[] = new boolean[n + 1];
            for (int u = 1; u <= n; ++u) {
                boolean ok = true;
                for (int v : e[u]) {
                    if (!vis[v]) {
                        ok = false;
                        break;
                    }
                }
                avail[u] = ok;
//                System.out.print(avail[u] + ", ");
                cnt += ok ? 1 : 0;
            }
//            System.out.println();
            if (cnt <= k) {
                int m = s;
                for (int u = 1; u <= n; ++u) {
                    if (avail[u]) {
                        m |= 1 << (u - 1);
                    }
                }
                if (dp[m] == Integer.MAX_VALUE) {
                    dp[m] = dp[s] + 1;
                    q.add(m);
                }
            } else {
                ArrayList<Integer> a = new ArrayList<>();
                for (int u = 1; u <= n; ++u) {
                    if (avail[u]) {
                        a.add(u);
                    }
                }
                dfs(a, q, dp, k, -1, new int[k], s);
            }
            if (dp[t] != Integer.MAX_VALUE) {
                break;
            }
        }
        return dp[t];
    }

    private void dfs(ArrayList<Integer> a, Queue<Integer> q, int[] dp, int k, int pr, int[] c,
            int s) {
        if (k == 0) {
            int m = s;
            for (int i = 0; i < c.length; ++i) {
                m |= 1 << (c[i] - 1);
            }
            if (dp[m] == Integer.MAX_VALUE) {
                dp[m] = dp[s] + 1;
                q.add(m);
            }
            return;
        }
        for (int i = pr + 1; i < a.size(); ++i) {
            c[k - 1] = a.get(i);
            dfs(a, q, dp, k - 1, i, c, s);
        }
    }
}
```



题解：枚举子集。

前置知识：[子集遍历](https://oi-wiki.org/math/binary-set/)

对二进制状态(有 $k$ 个 $1$) $m$，按二进制大小降序遍历 $m$ 的所有 $2^k$ 个非空子集的方法是：

```c++
for (int s = m; s; s = (s - 1) & m)
```

对于共 $n$ 位的全体 $2^n$ 个二进制状态，遍历全体状态及其子集的代码为：

```c++
for (int m = 0; m < (1 << n); ++m)// 降序遍历 m 的非空子集
  for (int s = m; s; s = (s - 1) & m)// s 是 m 的一个非空子集
```

总复杂度为 $O(3^n)$，若 $m$ 有 $k$ 个 $1$，则有 $2^k$ 个子集，共有 $C_n^k$ 个 $m$ 有 $k$ 个 $1$，根据二项式定理，有 $\sum_{k=0}^nC_n^k2^n=(1+2)^n=3^n$



边集递推：对状态 $i$，设 $dp_i$ 是最少学期数，$need_i$ 是最小前置集合状态。对每条边 $u\to v$，初始设 $need_{2^v}=2^u$。且显然 $dp_0=0,need_0=0$。

对 $need$ 的实际运算，考虑对 $i$ 找到任意一个子集 $sub$，那么集合减法有 $i\oplus sub$ 是不包含 $sub$ 的另一子集，显然有 $need_i=need_{i\oplus sub}|need_{sub}$。

根据枚举子集，可以知道 $i\&(i-1)$ 一定是上一个子集，而上一个子集少掉的是最低位，即 lowbit $i\&(-i)$，故顺序枚举时，可以通过 $need_i=need_{i\&i-1}|need_{i\&-i}$ 正确处理掉所有的依赖关系。

当前状态 $i$ 的 $need_i$ 一定是它的子集，故 $i\oplus need_i$ 就是当前没学可学的全体课程状态。然后所有 $need_i$ 的子集，对不超过 $k$ 的全体子集 $sub$，可以从没学 $sub$ 但其他都学了的这个子集推到 $i$，即 $dp_i=\min(dp_i,dp_{i\oplus sub})$。

因为顺序枚举 $i$，所以子集一定都已经处理完了，根据上文分析复杂度为 $O(3^n)$。

做一个剪枝优化，如果 $need_i|i\neq i$，即 $need_i$ 不是 $i$ 的子集，那么 $i$ 状态无效。注意显然不会影响正确性，即如不会出现一个 $3\to2\to1$ 的学习图无效的情况，因为这个图枚举 $4,6,7$ 的顺序是可以做到的。

```java
class Solution {
    public int minNumberOfSemesters(int n, int[][] relations, int k) {
        int[] dp = new int[1 << n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        int[] need = new int[1 << n];
        for (int[] edge : relations) {
            need[(1 << (edge[1] - 1))] |= 1 << (edge[0] - 1);
        }
        dp[0] = 0;
        for (int i = 1; i < (1 << n); ++i) {
            need[i] = need[i & (i - 1)] | need[i & (-i)];
            if ((need[i] | i) != i) { // i 中有任意一门课程的前置课程没有完成学习
                continue;
            }
            int valid = i ^ need[i]; // 当前学期可以进行学习的课程集合
            if (Integer.bitCount(valid) <= k) { // 如果个数小于 k，则可以全部学习，不再枚举子集
                dp[i] = Math.min(dp[i], dp[i ^ valid] + 1);
            } else { // 否则枚举当前学期需要进行学习的课程集合
                for (int sub = valid; sub > 0; sub = (sub - 1) & valid) {
                    if (Integer.bitCount(sub) <= k) {
                        dp[i] = Math.min(dp[i], dp[i ^ sub] + 1);
                    }
                }
            }
        }
        return dp[(1 << n) - 1];
    }
}
```

##### 2481\.分割圆的最少切割次数

[题目](https://leetcode.cn/problems/minimum-cuts-to-divide-a-circle/)

```c++
return n == 1 ? 0 : (n % 2 == 0 ? n / 2 : n);
```



##### 1254\.统计封闭岛屿的数目

[题目](https://leetcode.cn/problems/number-of-closed-islands/)

个人解法：填多一个外圈全0，然后统计连通0的数目并-1(外圈)即为答案。

```c++
class Solution
{
public:
    int closedIsland(vector<vector<int>> &grid)
    {
        int n = grid.size() + 1, m = grid[0].size() + 1;
        vector<vector<bool>> a(n + 1, vector<bool>(m + 1, false));
        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                a[i][j] = grid[i - 1][j - 1];
            }
        }
        int cnt = 0;
        static int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                if (!a[i][j])
                {
                    
                    ++cnt;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        auto pr = q.front();
                        q.pop();
                        a[pr.first][pr.second] = true;
                        for (int k = 0; k < 4; ++k)
                        {
                            int nx = pr.first + dx[k];
                            int ny = pr.second + dy[k];
                            if (nx < 0 || ny < 0 || nx > n || ny > m || a[nx][ny])
                            {
                                continue;
                            }
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
        return cnt - 1;
    }
};
```

答案的 BFS：如果 BFS 途中碰到了临界边框那么这次不算答案。

```c++
class Solution {
public:
    static constexpr int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
                
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    queue<pair<int,int>> qu;
                    grid[i][j] = 1;
                    bool closed = true;

                    qu.push(make_pair(i, j));
                    while (!qu.empty()) {
                        auto [cx, cy] = qu.front();
                        qu.pop();
                        if (cx == 0 || cy == 0 || cx == m - 1 || cy == n - 1) {
                            closed = false;
                        }
                        for (int i = 0; i < 4; i++) {
                            int nx = cx + dir[i][0];
                            int ny = cy + dir[i][1];
                            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 0) {
                                grid[nx][ny] = 1;
                                qu.emplace(nx, ny);
                            }
                        }
                    }
                    if (closed) {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
```

> GPT4: `const`关键字声明的变量可以在运行时计算其值，而`constexpr`关键字声明的变量必须在编译时计算其值。这意味着`constexpr`的值必须是编译器可以在编译时知道的常量，而`const`的值可以在运行时确定。

DFS 同理：

```c++
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();

        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if (x < 0 || y < 0 || x >= m || y >= n) {
                return false;
            }
            if (grid[x][y] != 0) {
                return true;
            }
            grid[x][y] = -1;
            bool ret1 = dfs(x - 1, y);
            bool ret2 = dfs(x + 1, y);
            bool ret3 = dfs(x, y - 1);
            bool ret4 = dfs(x, y + 1);
            return ret1 && ret2 && ret3 && ret4;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0 && dfs(i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

> 注意这个局部函数的语法写法

显然也可以用并查集：

> 注意内部类的语法(以及他的用 rank 的并查集写法不优、统计也不优)

```c++
class UnionFind {
public:
    UnionFind(int n) {
        this->parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
        this->rank = vector<int>(n);
    }

    void uni(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) {
            if (rank[rootx] > rank[rooty]) {
                parent[rooty] = rootx;
            } else if (rank[rootx] < rank[rooty]) {
                parent[rootx] = rooty;
            } else {
                parent[rooty] = rootx;
                rank[rootx]++;
            }
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
private:
    vector<int> parent;
    vector<int> rank;
};

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        UnionFind uf(m * n);

        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0) {
                uf.uni(i * n, 0);
            }
            if (grid[i][n - 1] == 0) {
                uf.uni(i * n + n - 1, 0);
            }
        }
        for (int j = 1; j < n - 1; j++) {
            if (grid[0][j] == 0) {
                uf.uni(j, 0);
            }
            if (grid[m - 1][j] == 0) {
                uf.uni((m - 1) * n + j, 0);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (i > 0 && grid[i - 1][j] == 0) {
                        uf.uni(i * n + j, (i - 1) * n + j);
                    }
                    if (j > 0 && grid[i][j - 1] == 0) {
                        uf.uni(i * n + j, i * n + j - 1);
                    }
                }
            }
        }

        unordered_set<int> cnt;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cnt.emplace(uf.find(i * n + j));
                }
            }
        }
        int total = cnt.size();
        if (cnt.count(uf.find(0))) {
            total--;
        }
        return total;
    }
};
```

##### 1262\.可被三整除的最大和

[题目](https://leetcode.cn/problems/greatest-sum-divisible-by-three/)

> 错误解法：$O(n^2)$ DP，对每个 $n_1,n_2$(等价类长度)摁推；或者无脑贪心

贪心缩数据+DP。正确性未经证明，仅供参考。可能是错误解法，但是能过题。

首先将原数组划分为模 $3$ 的三个等价类：$a_0,a_1,a_2$，然后分别排序。

$a_0$ 里都是 $3$ 的倍数直接全部都要，对 $a_1,a_2$，首先采用下述的玄学贪心：

当数组长度 $|a_1|,|a_2|$ 都大于某个范围(这里设为 $12$)时，贪心地让最大的三个 $a_1$ 元素和三个 $a_2$ 元素拿走，显然仍然保持总和是 $3$ 的倍数。

当 $|a_1|,|a_2|$ 有一方小于 $12$ 时，使用暴力 DP，对每个状态 $n_1,n_2$，走三个转移：$n_1-3,n_2;n_1,n_2-3;n_1-1,n_2-1$，即选三个最大 $a_1$ 或选三个最大 $a_2$ 或选一个最大 $a_1$ 和一个最大 $a_2$，复杂度为 $O(|a_1|\cdot |a_2|)\le 12(n-12)=O(12n)$。

参考代码：

```c++
class Solution
{
public:
    int maxSumDivThree(vector<int> &nums)
    {
        vector<int> a[3];
        for (int v : nums)
        {
            a[v % 3].push_back(v);
        }
        for (int i = 0; i < 3; ++i)
        {
            sort(a[i].begin(), a[i].end());
        }
        int ans = 0;
        for (int v : a[0])
        {
            ans += v;
        }
        int n2 = a[2].size(), n1 = a[1].size();
        while (n1 >= 3 && n2 >= 3)
        {
            ans += a[1][n1 - 1] + a[1][n1 - 2] + a[1][n1 - 3];
            ans += a[2][n2 - 1] + a[2][n2 - 2] + a[2][n2 - 3];
            n1 -= 3, n2 -= 3;
        }
        map<pair<int, int>, int> h;
        function<int(int, int)> dfs = [&](int n1, int n2)
        {
            if (h.find({n1, n2}) != h.end())
            {
                return h[{n1, n2}];
            }
            int res = 0;
            if (n1 && n2)
            {
                res = max(res, dfs(n1 - 1, n2 - 1) + a[1][n1 - 1] + a[2][n2 - 1]);
            }
            if (n1 >= 3)
            {
                res = max(res, dfs(n1 - 3, n2) + a[1][n1 - 1] + a[1][n1 - 2] + a[1][n1 - 3]);
            }
            if (n2 >= 3)
            {
                res = max(res, dfs(n1, n2 - 3) + a[2][n2 - 1] + a[2][n2 - 2] + a[2][n2 - 3]);
            }
            h[{n1, n2}] = res;
            return res;
        };
        ans += dfs(n1, n2);
        return ans;
    }
};
```

正经算法：

贪心+正向。设等价类余 $1,2$ 是 $b,c$。如果在 $b$ 选了 $cnt_b$ 个，$c$ 选了 $cnt_c$ 个，则总和为 $(cnt_b+2cnt_c)\bmod 3\equiv(cnt_b-cnt_c)\bmod 3$。

等效于 $cnt_b\equiv cnt_c\mod 3$ 就行。

$cnt_b$ 至少是 $|b|-2$。反证法：如果是 $|b|-3$ 或更小，可以三个三个地选完。故 $cnt_b\in \{|b|,|b|-1,|b|-2\},cnt_c\in \{|c|,|c|-1,|c|-2\}$，暴力枚举这九种情况即可。

```c++
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // 使用 v[0], v[1], v[2] 分别表示 a, b, c
        vector<int> v[3];
        for (int num: nums) {
            v[num % 3].push_back(num);
        }
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());

        int ans = 0;
        int lb = v[1].size(), lc = v[2].size();
        for (int cntb = lb - 2; cntb <= lb; ++cntb) {
            if (cntb >= 0) {
                for (int cntc = lc - 2; cntc <= lc; ++cntc) {
                    if (cntc >= 0 && (cntb - cntc) % 3 == 0) {
                        ans = max(ans, accumulate(v[1].begin(), v[1].begin() + cntb, 0) + accumulate(v[2].begin(), v[2].begin() + cntc, 0));
                    }
                }
            }
        }
        return ans + accumulate(v[0].begin(), v[0].end(), 0); //0+sum(v区间)
    }
};
```

解法二：逆向贪心(丢弃法)

如果全选后余 $1$，要么丢 $b$ 最小一个，要么丢 $c$ 最小两个。

如果全选后余 $2$，要么丢 $b$ 最小两个，要么丢 $c$ 最小一个。

```c++
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // 使用 v[0], v[1], v[2] 分别表示 a, b, c
        vector<int> v[3];
        for (int num: nums) {
            v[num % 3].push_back(num);
        }
        sort(v[1].begin(), v[1].end(), greater<int>());
        sort(v[2].begin(), v[2].end(), greater<int>());
        int tot = accumulate(nums.begin(), nums.end(), 0);
        int remove = INT_MAX;

        if (tot % 3 == 0) {
            remove = 0;
        }
        else if (tot % 3 == 1) {
            if (v[1].size() >= 1) {
                remove = min(remove, v[1].end()[-1]);
                //逆向范围元素的办法
            }
            if (v[2].size() >= 2) {
                remove = min(remove, v[2].end()[-2] + v[2].end()[-1]);
            }
        }
        else {
            if (v[1].size() >= 2) {
                remove = min(remove, v[1].end()[-2] + v[1].end()[-1]);
            }
            if (v[2].size() >= 1) {
                remove = min(remove, v[2].end()[-1]);
            }
        }

        return tot - remove;
    }
};
```

DP：设 $f(i,j)$ 表示前 $i(i\ge 1)$ 个数选的数的和余 $j$ 下和的最大值为 $f(i,j)$。

对当前数，要么选要么不选：

- 选，则 $f(i,j)=a_i+f(i-1,(j-a_j)\bmod 3)$
- 不选，则 $f(i-1,j)$

取最大值即可。初始值 $f(0,0)=0,f(0,j)=-\infty(j > 0)$。压掉 $i$，时间 $O(3n)$，空间 $O(3)$。

```c++
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> f = {0, INT_MIN, INT_MIN};
        for (int num: nums) {
            vector<int> g = f;
            for (int i = 0; i < 3; ++i) {
                g[(i + num % 3) % 3] = max(g[(i + num % 3) % 3], f[i] + num);
            }
            f = move(g);
        }
        return f[0];
    }
};
```

##### 1595\.连通两组点的最小成本

[题目](https://leetcode.cn/problems/minimum-cost-to-connect-two-groups-of-points/)

题目所求**不是最小权二分图最大匹配**，匹配是边端点两两不重的边集。题目所求为最小权边覆盖，即用边集覆盖所有的点。

最小权边覆盖可以转化为最小权匹配。边覆盖=匹配+额外边。

额外边是加了之后只多覆盖一个点的边，对不在匹配的每个点，选择最小的边，不会影响其他不在匹配的点。对邻接矩阵，二分图左边第 $i$ 个点的最优额外边是 $\min e_{i,:}$，右边第 $j$ 个点的最优额外边是 $\min e_{:,j}$。即分别为行列最小值。

显然一种较差的解是每个店都直接选择最小的额外边，称为基本解。在基本解的前提下，引入匹配，每加入一条匹配边 $(u,v)$，首先去掉了两边的额外边，再加上这条边的边权，即 $e_{i,j}-\min e_{i,:}-\min e_{:,j}$。在费用网络流建立一个流量为 $1$，费用为上述值的边。然后源点跟左边、右边跟汇点都连流量为 $1$ 费用为 $0$ 的边，即求朴素的最小权匹配。

使用 MCFN，复杂度为 $O(\min(n,m)^2\max(n,m))=O(n^3)$。

> 一个包装的很好的网络流板子：
>
> 前置依赖：
>
> ```c++
> namespace details {
> 	inline unsigned int bsf32(uint32_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_ctz(n);
> #elif defined _MSC_VER
> 		unsigned long ans;
> 		_BitScanForward(&ans, n);
> 		return ans;
> #elif
> 		static constexpr unsigned char table[32] = {
> 			0, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8,
> 			31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9,
> 		};
> 		return table[((n & -n) * 0x077CB531) >> 57];
> #endif
> 	}
> 
> 	inline unsigned int bsf64(uint64_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_ctzll(n);
> #elif defined _MSC_VER
> 		unsigned long ans;
> 		_BitScanForward64(&ans, n);
> 		return ans;
> #elif
> 		static constexpr unsigned char table[64] = {
> 			0, 1, 56, 2, 57, 49, 28, 3, 61, 58, 42, 50, 38, 29, 17, 4,
> 			62, 47, 59, 36, 45, 43, 51, 22, 53, 39, 33, 30, 24, 18, 12, 5,
> 			63, 55, 48, 27, 60, 41, 37, 16, 46, 35, 44, 21, 52, 32, 23, 11,
> 			54, 26, 40, 15, 34, 20, 31, 10, 25, 14, 19, 9, 13, 8, 7, 6,
> 		};
> 		return table[((n & -n) * 0x03f79d71b4ca8b09) >> 58];
> #endif
> 	}
> 
> 	inline unsigned int bsr32(uint32_t n) noexcept {
> #if defined __GNUC__
> 		return 31 - __builtin_clz(n);
> #elif defined _MSC_VER
> 		unsigned long ans;
> 		_BitScanReverse(&ans, n);
> 		return ans;
> #elif
> 		float t = n;
> 		uint32_t ans;
> 		memcpy(&ans, &t, sizeof(float));
> 		return (ans >> 23 & 255) - 127;
> #endif
> 	}
> 
> 	inline unsigned int bsr64(uint64_t n) noexcept {
> #if defined __GNUC__
> 		return 63 - __builtin_clzll(n);
> #elif defined _MSC_VER
> 		unsigned long ans;
> 		_BitScanReverse64(&ans, n);
> 		return ans;
> #elif
> 		float t = n;
> 		uint32_t ans;
> 		memcpy(&ans, &t, sizeof(float));
> 		return (ans >> 23 & 255) - 127;
> #endif
> 	}
> 
> 	inline unsigned int popcnt32(uint32_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_popcount(n);
> #elif defined _MSC_VER
> 		return __popcnt(n);
> #elif
> 		n -= ((n >> 1) & 0x55555555);
> 		n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
> 		return ((((n >> 4) + n) & 0x0f0f0f0f) * 0x01010101) >> 24;
> #endif
> 	}
> 
> 	inline unsigned int popcnt64(uint64_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_popcountll(n);
> #elif defined _MSC_VER
> 		return __popcnt64(n);
> #elif
> 		n -= ((n >> 1) & 0x5555555555555555);
> 		n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
> 		return ((((n >> 4) + n) & 0x0f0f0f0f0f0f0f0f) * 0x0101010101010101) >> 56;
> #endif
> 	}
> 
> 	inline unsigned int parity32(uint32_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_parity(n);
> #elif defined _MSC_VER
> 		return __popcnt(n) & 1;
> #elif
> 		n ^= n >> 1;
> 		n ^= n >> 2;
> 		n = (n & 0x11111111) * 0x11111111;
> 		return (n >> 28) & 1;
> #endif
> 	}
> 
> 	inline unsigned int parity64(uint64_t n) noexcept {
> #if defined __GNUC__
> 		return __builtin_parityll(n);
> #elif defined _MSC_VER
> 		return __popcnt64(n) & 1;
> #elif
> 		n ^= n >> 1;
> 		n ^= n >> 2;
> 		n = (n & 0x1111111111111111) * 0x1111111111111111;
> 		return (n >> 60) & 1;
> #endif
> 	}
> 
> 
> 	template<typename I, bool B = 32 < std::numeric_limits<I>::digits>
> 	struct _BitFuncImpl {
> 		inline static unsigned int bsf(I n) noexcept { return bsf64(n); }
> 		inline static unsigned int bsr(I n) noexcept { return bsr64(n); }
> 		inline static unsigned int popcnt(I n) noexcept { return popcnt64(n); }
> 		inline static unsigned int parity(I n) noexcept { return parity64(n); }
> 	};
> 
> 	template<typename I>
> 	struct _BitFuncImpl<I, false> {
> 		inline static unsigned int bsf(I n) noexcept { return bsf32(n); }
> 		inline static unsigned int bsr(I n) noexcept { return bsr32(n); }
> 		inline static unsigned int popcnt(I n) noexcept { return popcnt32(n); }
> 		inline static unsigned int parity(I n) noexcept { return parity32(n); }
> 	};
> 
> 	template<typename I>
> 	inline unsigned int bsf(I n) noexcept { return _BitFuncImpl<I>::bsf(n); }
> 	template<typename I>
> 	inline unsigned int bsr(I n) noexcept { return _BitFuncImpl<I>::bsr(n); }
> 	template<typename I>
> 	inline unsigned int popcnt(I n) noexcept { return _BitFuncImpl<I>::popcnt(n); }
> 	template<typename I>
> 	inline unsigned int parity(I n) noexcept { return _BitFuncImpl<I>::parity(n); }
> }
> 
> template<typename E>
> class Network {
> public:
>     using edge_type = E;
>     using size_type = unsigned;
> 
> private:
>     size_type n, m;
>     size_type* pos;
>     std::unique_ptr<edge_type[]> edges;
> 
> public:
>     Network(std::unique_ptr<edge_type[]> edges, std::unique_ptr<size_type[]> spos, size_type n, size_type m)
>         : n(n), m(m), pos(spos.release() + 1), edges(std::move(edges))
>     {
>         pos[-1] = 1;
>     }
> 
>     Network(const Network& other) : n(other.n), m(other.m), pos(other.pos), edges(new edge_type[m]) {
>         std::copy_n(other.edges.get(), m, edges.get());
>         ++pos[-1];
>     }
> 
>     ~Network() { if (--pos[-1] == 0) delete[] (pos - 1); }
> 
>     inline size_type order() const noexcept { return n; }
>     inline size_type size() const noexcept { return m; }
>     inline const size_type* raw_pos() const noexcept { return pos; }
>     inline const edge_type* raw_edges() const noexcept { return edges.get(); }
>     inline edge_type* raw_edges() noexcept { return edges.get(); }
> };
> 
> template<typename F = int, typename C = int>
> class MCFN {
> public:
>     using size_type = unsigned;
> 
> private:
>     struct RawEdge {
>         size_type from, to;
>         F cap;
>         C cost;
>     };
> 
>     struct Edge {
>     private:
>         friend class MCFN;
>         size_type _rev, _to;
>         F _cap;
>         C _cost;
>         Edge(size_type rev, size_type to, F cap, C cost) : _rev(rev), _to(to), _cap(cap), _cost(cost) {}
>     public:
>         using flow_type = F;
>         using cost_type = C;
>         Edge() = default;
>         inline size_type rev() const noexcept { return _rev; }
>         inline size_type to() const noexcept { return _to; }
>         inline flow_type residual() const noexcept { return _cap; }
>         inline bool full() const noexcept { return _cap == 0; }
>         inline void push(flow_type d) noexcept { _cap -= d; }
>         inline cost_type cost() const noexcept { return _cost; }
>     };
> 
>     std::vector<RawEdge> edges;
>     std::vector<size_type> deg;
> 
> public:
>     MCFN() noexcept = default;
> 
>     MCFN(size_type n) : deg(n, 0) {}
> 
>     void reserve(size_type n, size_type m) {
>         edges.reserve(m);
>         deg.reserve(n);
>     }
> 
>     inline size_type add_vertex() {
>         const size_type ans = deg.size();
>         deg.push_back(0);
>         return ans;
>     }
> 
>     inline void add_edge(size_type from, size_type to, F cap, C cost) {
>         if (cap <= 0) return;
>         edges.emplace_back(RawEdge{from, to, cap, cost});
>         ++deg[from];
>         ++deg[to];
>     }
> 
>     Network<Edge> prepare() const {
>         using size_type = typename Network<Edge>::size_type;
>         const size_type n = deg.size(), m = edges.size();
>         std::unique_ptr<Edge[]> sorted_edges(new Edge[2 * m]);
>         std::unique_ptr<size_type[]> spos(new size_type[n + 2]);
>         const auto pos = spos.get() + 1;
>         *std::partial_sum(deg.begin(), deg.end(), pos) = 2 * m;
>         for (size_type i = m;i-- > 0;) {
>             const RawEdge e = edges[i];
>             const size_type u = e.from, v = e.to;
>             const size_type rp = --pos[v], p = --pos[u];
>             sorted_edges[p] = Edge(rp, v, e.cap, e.cost);
>             sorted_edges[rp] = Edge(p, u, 0, -e.cost);
>         }
>         return Network<Edge>(std::move(sorted_edges), std::move(spos), n, 2 * m);
>     }
> };
> ```
>
> 网络流算法：
>
> ```c++
> template<typename F = int, typename C = int, typename G>
> auto ssp(G&& g, std::size_t s, std::size_t t, bool nneg = false)
> -> std::pair<
>     typename std::common_type<F, typename std::remove_reference<G>::type::edge_type::flow_type>::type,
>     typename std::common_type<C, typename std::remove_reference<G>::type::edge_type::cost_type>::type>
> {
>     using graph_type = typename std::remove_reference<G>::type;
>     using size_type = typename graph_type::size_type;
>     using edge_type = typename graph_type::edge_type;
>     using flow_type = typename std::common_type<F, typename edge_type::flow_type>::type;
>     using cost_type = typename std::common_type<C, typename edge_type::cost_type>::type;
>     static constexpr size_type BIN_LEN = std::numeric_limits<cost_type>::digits;
>     static constexpr cost_type INF = std::numeric_limits<cost_type>::max();
>     struct ShortestPath {
>         size_type pre;
>         cost_type pot, dis;
>     };
>     struct ListNode {
>         size_type prev, next;
>     };
>     const size_type n = g.order(), m = g.size();
>     const bool use_heap = m / n <= n / std::min<size_type>(3 * details::bsr(n + 7) + 15, 64);
>     const auto edges = g.raw_edges();
>     const auto pos = g.raw_pos();
>     std::vector<ShortestPath> sp(n);
>     std::vector<bool> vis;
>     const auto init = [&] {
>         vis.assign(n, false);
>         std::vector<size_type> q(n);
>         size_type l = 0, r = 1;
>         for (auto& e : sp)
>             e.pot = INF;
>         sp[s] = {0, 0};
>         vis[s] = true;
>         q[0] = s;
>         while (l != r) {
>             const size_type u = q[l];
>             l = l + 1 != n ? l + 1 : 0;
>             vis[u] = false;
>             const size_type pu = sp[u].pre;
>             const cost_type du = sp[u].pot;
>             const auto start_edge = edges + pos[u];
>             const auto end_edge = edges + pos[u + 1];
>             for (auto i = start_edge;i != end_edge;++i) {
>                 const edge_type e = *i;
>                 if (e.full()) continue;
>                 const size_type v = e.to();
>                 const cost_type dv = sp[v].pot;
>                 const cost_type ndv = du + e.cost();
>                 if (ndv < dv) {
>                     sp[v].pre = pu + 1;
>                     sp[v].pot = ndv;
>                     if (sp[v].pre >= n) throw std::invalid_argument("graph contains negative cycles.");
>                     if (!vis[v]) {
>                         q[r] = v;
>                         vis[v] = true;
>                         r = r + 1 != n ? r + 1 : 0;
>                     }
>                 }
>             }
>         }
>     };
>     if (!nneg) init();
>     const cost_type pt = sp[t].pot;
>     flow_type flow = 0;
>     cost_type cost = 0;
>     const auto augment = [&] {
>         flow_type f = std::numeric_limits<flow_type>::max();
>         for (size_type i = t;i != s;) {
>             const edge_type e = edges[sp[i].pre];
>             const flow_type r = edges[e.rev()].residual();
>             if (r < f) f = r;
>             i = e.to();
>         }
>         for (size_type i = t;i != s;) {
>             auto& e = edges[sp[i].pre];
>             edges[e.rev()].push(f);
>             e.push(-f);
>             i = e.to();
>         }
>         flow += f;
>         const cost_type dt = sp[t].dis;
>         for (auto& e : sp)
>             if (e.dis < dt)
>                 e.pot -= dt - e.dis;
>         cost += cost_type(f) * (pt - sp[s].pot);
>     };
>     const auto flow_with_heap = [&] {
>         std::vector<ListNode> list(n + BIN_LEN + 1);
>         const auto dijkstra_with_heap = [&] {
>             const auto radix_distance = [] (cost_type lhs, cost_type rhs) {
>                 return lhs != rhs ? details::bsr(lhs ^ rhs) + 1 : 0;
>             };
>             const auto buk = list.data() + n;
>             const auto insert_list = [&] (size_type idx, size_type v) {
>                 const size_type rear = buk[idx].prev;
>                 list[rear].next = v;
>                 list[v].prev = rear;
>                 buk[idx].prev = v;
>                 list[v].next = idx + n;
>             };
>             cost_type top = 0;
>             for (size_type i = 0;i <= n + BIN_LEN;++i)
>                 list[i] = {i, i};
>             list[s] = {n, n};
>             buk[0] = {size_type(s), size_type(s)};
>             for (auto& e : sp)
>                 e.dis = INF;
>             sp[s].dis = 0;
>             while (true) {
>                 size_type u = buk[0].next;
>                 if (u == n) {
>                     size_type idx = 1;
>                     for (;idx <= BIN_LEN;++idx)
>                         if (buk[idx].next < n)
>                             break;
>                     if (idx > BIN_LEN) break;
>                     const size_type head = buk[idx].next;
>                     top = sp[head].dis;
>                     for (size_type i = head;(i = list[i].next) < n;)
>                         if (sp[i].dis < top)
>                             top = sp[i].dis;
>                     for (size_type i = head;i < n;) {
>                         const size_type j = list[i].next;
>                         insert_list(radix_distance(top, sp[i].dis), i);
>                         i = j;
>                     }
>                     buk[idx] = {idx + n, idx + n};
>                     u = buk[0].next;
>                 }
>                 if (u == size_type(t)) return true;
>                 const size_type next = list[u].next;
>                 list[next].prev = n;
>                 buk[0].next = next;
>                 const cost_type pu = sp[u].pot;
>                 const cost_type du = sp[u].dis;
>                 const auto start_edge = edges + pos[u];
>                 const auto end_edge = edges + pos[u + 1];
>                 for (auto i = start_edge;i != end_edge;++i) {
>                     const edge_type e = *i;
>                     if (e.full()) continue;
>                     const size_type v = e.to();
>                     const cost_type pv = sp[v].pot;
>                     const cost_type dv = sp[v].dis;
>                     const cost_type ndv = e.cost() + pu - pv + du;
>                     if (ndv < dv) {
>                         const size_type new_idx = radix_distance(top, ndv);
>                         if (new_idx != radix_distance(top, dv)) {
>                             const size_type prev = list[v].prev;
>                             const size_type next = list[v].next;
>                             list[prev].next = next;
>                             list[next].prev = prev;
>                             insert_list(new_idx, v);
>                         }
>                         sp[v].dis = ndv;
>                         sp[v].pre = e.rev();
>                     }
>                 }
>             }
>             return false;
>         };
>         while (dijkstra_with_heap())
>             augment();
>     };
>     const auto flow_without_heap = [&] {
>         std::vector<size_type> min_buk;
>         const auto dijkstra_without_heap = [&] {
>             vis.assign(n, false);
>             min_buk = {size_type(s)};
>             for (auto& e : sp)
>                 e.dis = INF;
>             sp[s].dis = 0;
>             while (true) {
>                 size_type u;
>                 cost_type du;
>                 if (!min_buk.empty()) {
>                     u = min_buk.back();
>                     min_buk.pop_back();
>                     if (vis[u]) continue;
>                     du = sp[u].dis;
>                 } else {
>                     du = INF;
>                     for (size_type i = 0;i < n;++i)
>                         if (!vis[i] && sp[i].dis < du)
>                             du = sp[u = i].dis;
>                     if (du == INF) break;
>                 }
>                 if (u == size_type(t)) return true;
>                 vis[u] = true;
>                 const cost_type pu = sp[u].pot;
>                 const auto start_edge = edges + pos[u];
>                 const auto end_edge = edges + pos[u + 1];
>                 for (auto i = start_edge;i != end_edge;++i) {
>                     const edge_type e = *i;
>                     if (e.full()) continue;
>                     const size_type v = e.to();
>                     const cost_type pv = sp[v].pot;
>                     const cost_type dv = sp[v].dis;
>                     const cost_type ndv = e.cost() + pu - pv + du;
>                     if (ndv < dv) {
>                         sp[v].dis = ndv;
>                         sp[v].pre = e.rev();
>                         if (ndv == du) min_buk.push_back(v);
>                     }
>                 }
>             }
>             return false;
>         };
>         while (dijkstra_without_heap())
>             augment();
>     };
>     if (use_heap)
>         flow_with_heap();
>     else
>         flow_without_heap();
>     return std::make_pair(flow, cost);
> }
> ```

本题代码：

```c++
class Solution {
public:
    int connectTwoGroups(const vector<vector<int>>& cost) {
        const int m = cost.size(), n = cost[0].size();
        vector<int> row_min(m, INT_MAX);
        vector<int> col_min(n, INT_MAX);
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                row_min[i] = min(row_min[i], cost[i][j]);
                col_min[j] = min(col_min[j], cost[i][j]);
            }
        }
        MCFN<int, int> mcfn(m + n + 2);
        const int s = m + n, t = s + 1;
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j)
                mcfn.add_edge(i, m + j, 1, min(cost[i][j] - row_min[i] - col_min[j], 0));
            mcfn.add_edge(s, i, 1, 0);
        }
        for (int i = 0;i < n;++i)
            mcfn.add_edge(m + i, t, 1, 0);
        return reduce(row_min.begin(), row_min.end(), 0) + reduce(col_min.begin(), col_min.end(), 0) + ssp(mcfn.prepare(), s, t).second;
    }
};
```

> GPT4: C++17 reduce 求前缀和
>
> `reduce` 是并行化算法，因此它可以在多核处理器上更有效地运行，这对于处理大数据集非常有用。
>
> 需要注意的是，`reduce` 的执行顺序是未指定的，因此，使用 `reduce` 的时候必须保证二元操作符是结合的，即 `binary_op(binary_op(a1, a2), a3) == binary_op(a1, binary_op(a2, a3))`。这样，不论 `reduce` 如何安排计算顺序，最终的结果都是一样的。

劣解法：状压 DP

设二进制数 $s$ 表示长为 $|n_2|$ 位状态，$dp_{i,s}$ 表示左边前 $i$ 个点与右边 $s$ 点集连接的最小成本。初始值 $dp{0,0}=0$，且无法连通的全体为 $dp_{0,s}=dp_{i,0}=\infty$。

否则，转移方程为，设第 $i-1$ 个点与当前 $s$ 的第 $k$ 个点相连，$s_{-k}$ 是去掉第 $k$ 个点后的剩余点集二进制状态，则对成本，有其中一种情况：

- 那么 $k$ 不需要再跟其他点相连，即 $dp_{i,s_{-k}}$ 能够满足其他点，$k$ 单独设 $e_{i-1,k}$
- $i-1$ 不需要再跟其他点相连，即 $dp_{i-1,s}$ 和单独 $e_{i-1,k}$
- 这两个点都不需要再与其他点相连 $dp_{i-1,s_{-k}}$ 和单独 $e_{i-1,k}$

即 $dp_{i,s}=\min(\min(dp_{i,s_{-k}},dp_{i-1,s},dp_{i,s_{-k}})+e_{i-1,k})$

可以压掉第一维度：

```c++
class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int size1 = cost.size(), size2 = cost[0].size(), m = 1 << size2;
        vector<int> dp1(m, INT_MAX / 2), dp2(m);
        dp1[0] = 0;
        for (int i = 1; i <= size1; i++) {
            for (int s = 0; s < m; s++) {
                dp2[s] = INT_MAX / 2;
                for (int k = 0; k < size2; k++) {
                    if ((s & (1 << k)) == 0) {
                        continue;
                    }
                    dp2[s] = min(dp2[s], dp2[s ^ (1 << k)] + cost[i - 1][k]);
                    dp2[s] = min(dp2[s], dp1[s] + cost[i - 1][k]);
                    dp2[s] = min(dp2[s], dp1[s ^ (1 << k)] + cost[i - 1][k]);
                }
            }
            dp1.swap(dp2);
        }
        return dp1[m - 1];
    }
};
```

时间 $O(nm2^m)$，空间 $O(2^m)$。

##### LCP41.黑白翻转棋

[题目](https://leetcode.cn/problems/fHi6rV/)

一种笨策略：枚举每个 `.` 尝试将其转化为 `X`，然后对转化后的棋盘，求出有多少个白色转黑色，取最大值返回，即：

```c++
int flipChess(mmap &chessboard)
{
    int ans = 0;
    for (int i = 0; i < (int)chessboard.size(); ++i)
    {
        for (int j = 0; j < (int)chessboard[i].size(); ++j)
        {
            if (chessboard[i][j] == '.' )
            {
                chessboard[i][j] = 'X';
                int v = check(chessboard); //求出有多少个白色转黑色
                ans = max(ans, v);
                chessboard[i][j] = '.';
            }
        }
    }
    return ans;
}
```

下面我们来具体实现求白色转黑色数量的函数 `check`。使用如下思路：

每一轮枚举横竖撇捺四个方向，对每个方向的每一次枚举(即每一横/每一竖/每一撇/每一捺)，先求出每个小黑子的位置，然后两两枚举相邻黑子，先检查相邻黑子间是否全都是白子，如果是，那么把这些白子全部变成黑子。

如果在这一轮枚举中，全体横竖撇捺都没有任何白子变黑子，那么退出循环。否则，对变化后的新棋盘，重新进行上述枚举。

在最坏情况下，设 $n=m$ 均为最大值，有 $O(nm)$ 次枚举，每次枚举横竖撇捺，都要对每个格子遍历 $O(1)$ 次，横竖撇捺共 $4$ 下，故每次枚举横竖撇捺有 $O(4mn)$ 次枚举。故总复杂度为 $O(4n^2m^2)=O(n^2m^2)$。

因为共需要调用 $O(nm)$ 次 `check` 函数，故算法总复杂度为 $O(n^3m^3)$。

以每一横为例，具体的一轮枚举为：

```c++
for (int i = 0; i < n; ++i)
{
	vector<int> x;
	for (int j = 0; j < m; ++j)
	{
		if (a[i][j] == 'X')
		{
			x.push_back(j);
		}
	}
    //这个两层循环是O(m)的,而不是O(m^2)
	for (int j = 1; j < x.size(); ++j)
	{
		bool allo = true;
		for (int k = x[j - 1] + 1; k < x[j] && allo; ++k)
		{
			allo &= a[i][j] == 'O';
		}
        for (int k = x[j - 1] + 1; k < x[j] && allo; ++k)
        {
            a[i][j] = 'X';
            ++cnt;
        }
	}
}
```

如果每一竖、撇、捺都复制粘贴一遍上述思路然后改改，代码很长，可维护性很差。考虑一种优雅的写法，统一地实现横竖撇捺的枚举。

可以求出一种统一枚举横竖撇捺的实现为：

```c++
int n = a.size(), m = a[0].size();
auto in = [&](int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < m;
};
constexpr int d[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
function<void(int &, int &)> nx[] = {
	[](int &x, int &y)
	{ x += 1, y = 0; },
	[](int &x, int &y)
	{ x = 0, y += 1; },
	[&](int &x, int &y)
	{ (x == 0 && y + 1 < m) ? (x = 0, y += 1) : (x += 1, y = 0); },
	[&](int &x, int &y)
	{ (x == 0 && y + 1 < m) ? (x = 0, y += 1) : (x += 1, y = m - 1); }};
for (int h = 0; h < 4; ++h)
{
	for (int x0 = 0, y0 = 0; in(x0, y0); nx[h](x0, y0))
	{
		for (int x1 = x0, y1 = y0; in(x1, y1); x1 += d[h][0], y1 += d[h][1])
		{
			//具体每一格
		}
	}
}
```

扼要地解释一下逻辑实现：

- 最外层循环是控制当前是哪一种枚举，$h=1,2,3,4$ 分别是横、竖、主对角线(捺)、副对角线(撇)枚举

- 中间层循环控制如何切换到下一横、下一竖、下一主对角线、下一副对角线；且最开始总是从 $(0,0)$ 为第一个横竖/对角线。

  横竖很好理解，下一横就让竖坐标增一，横坐标清零；竖相反即可。下面重点讨论对角线。

  因为对角线切换存在逻辑更改，例如，对 $3\times 5$ 矩阵，不妨这么定义每一条主对角线、副对角线(元素表示第几条对角线)：
  $$
  \pmatrix{
  1&2&3&4&5\\
  6&1&2&3&4\\
  7&6&1&2&3
  }
  \quad
  \pmatrix{
  1&2&3&4&5\\
  2&3&4&5&6\\
  3&4&5&6&7
  }
  $$
  那么每一个对角线的第一个元素不妨设为最上边的元素。可以发现主对角线的首元素移动规律为先往右、然后回到最左并往下；副对角线的首元素移动规律为先往右、然后直接往下。而切换移动规则的关键是当前元素位于第一行最右边，即 $x=0,y=m-1$。

  综上，不难写出切换到下一横、下一竖、下一主对角线、下一副对角线的代码，可以定义四个匿名函数，按下标编成函数数组 `nx`(即 next)。

  易得，上述逻辑下遍历完全部横竖/对角线的充要条件是第一次产生越界。使用函数 `in` 检查是否越界。

- 最内层循环控制每一横、每一竖、每一主对角线、每一副对角线，可以使用类似 BFS 的增量数组控制每一次移动。遍历完当前横竖/对角线的充要条件是第一次产生越界。

现在我们将 `check` 函数从横扩展到横竖撇捺，完整代码如下所示：

```c++
class Solution
{
    using mmap = vector<string>;
    int check(mmap a)
    {
        int cnt = 0, n = a.size(), m = a[0].size();
        auto in = [&](int x, int y)
        {
            return x >= 0 && y >= 0 && x < n && y < m;
        };
        constexpr int d[4][2] = {{0, 1}, {1, 0}, {1, 1}, {1, -1}};
        function<void(int &, int &)> nx[] = {
            [](int &x, int &y)
            { x += 1, y = 0; },
            [](int &x, int &y)
            { x = 0, y += 1; },
            [&](int &x, int &y)
            { (x == 0 && y + 1 < m) ? (x = 0, y += 1) : (x += 1, y = 0); },
            [&](int &x, int &y)
            { (x == 0 && y + 1 < m) ? (x = 0, y += 1) : (x += 1, y = m - 1); }};

        for (int bf = 0;;)
        {
            for (int h = 0; h < 4; ++h)
            {
                for (int x0 = 0, y0 = 0; in(x0, y0); nx[h](x0, y0))
                {
                    string s = "";
                    vector<pair<int, int>> f;
                    for (int x1 = x0, y1 = y0; in(x1, y1); x1 += d[h][0], y1 += d[h][1])
                    {
                        s += a[x1][y1];
                        f.push_back({x1, y1});
                    }
                    vector<int> x;
                    for (int i = 0; i < s.size(); ++i)
                    {
                        if (s[i] == 'X')
                        {
                            x.push_back(i);
                        }
                    }
                    for (int i = 1; i < x.size(); ++i)
                    {
                        bool ok = true;
                        for (int j = x[i - 1] + 1; j < x[i] && ok; ++j)
                        {
                            ok &= s[j] == 'O';
                        }
                        for (int j = x[i - 1] + 1; j < x[i] && ok; ++j)
                        {
                            auto [x1, y1] = f[j];
                            a[x1][y1] = 'X';
                            ++cnt;
                        }
                    }
                }
            }
            if (bf == cnt)
            {
                break;
            }
            bf = cnt;
        }
        return cnt;
    }

public:
    int flipChess(mmap &chessboard)
    {
        int ans = 0;
        for (int i = 0; i < (int)chessboard.size(); ++i)
        {
            for (int j = 0; j < (int)chessboard[i].size(); ++j)
            {
                if (chessboard[i][j] == '.' )
                {
                    chessboard[i][j] = 'X';
                    int v = check(chessboard);
                    // cout << i << ' ' << j << ' ' << v << '\n';
                    ans = max(ans, v);
                    chessboard[i][j] = '.';
                }
            }
        }
        return ans;
    }
};
```



更优解法：

BFS，对当前修改位置，八方向射线(横竖撇捺刚好)找到能去的下一个黑子，一路上的每个白子都入队。

枚举每个修改位置，对每个位置都 BFS，且 BFS 内层射线复杂度是 $O(8\max(n,m))$，故总复杂度为 $O(n^2m^2\max(n,m))$。

```c++
class Solution {
public:
    const int dirs[8][2] = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    bool judge(const vector<string>& chessboard, int x, int y, int dx, int dy) {
        x += dx;
        y += dy;
        while (0 <= x && x < chessboard.size() && 0 <= y && y < chessboard[0].size()) {
            if (chessboard[x][y] == 'X') {
                return true;
            } else if (chessboard[x][y] == '.') {
                return false;
            }
            x += dx;
            y += dy;
        }
        return false;
    }

    int bfs(vector<string> chessboard, int px, int py) {
        int cnt = 0;
        queue<pair<int, int>> q;
        q.emplace(px, py);
        chessboard[px][py] = 'X';
        while (!q.empty()) {
            pair<int, int> t = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i) {
                if (judge(chessboard, t.first, t.second, dirs[i][0], dirs[i][1])) {
                    int x = t.first + dirs[i][0], y = t.second + dirs[i][1];
                    while (chessboard[x][y] != 'X') {
                        q.emplace(x, y);
                        chessboard[x][y] = 'X';
                        x += dirs[i][0];
                        y += dirs[i][1];
                        ++cnt;
                    }
                }
            }
        }
        return cnt;
    }

    int flipChess(vector<string>& chessboard) {
        int res = 0;
        for (int i = 0; i < chessboard.size(); ++i) {
            for (int j = 0; j < chessboard[0].size(); ++j) {
                if (chessboard[i][j] == '.') {
                    res = max(res, bfs(chessboard, i, j));
                }
            }
        }
        return res;
    }
};
```

##### 16\.19\.水域大小

[题目](https://leetcode.cn/problems/pond-sizes-lcci/)

我的 BFS 写法：

```c++
class Solution
{
public:
    vector<int> pondSizes(vector<vector<int>> &land)
    {
        vector<int> ans;
        int n = land.size(), m = land[0].size();
        constexpr int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        constexpr int dy[] = {0, -1, -1, -1, 0, 1, 1, 1};
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (land[i][j])
                {
                    continue;
                }
                int cnt = 0;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();
                    if (land[x][y])
                    {
                        continue;
                    }
                    land[x][y] = 1;
                    ++cnt;
                    for (int i = 0; i < 8; ++i)
                    {
                        int ax = x + dx[i], ay = y + dy[i];
                        if (ax < 0 || ay < 0 || ax >= n || ay >= m || land[ax][ay])
                        {
                            continue;
                        }
                        q.push({ax, ay});
                    }
                }
                ans.push_back(cnt);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
```

题解的：

```c++
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        auto bfs = [&](int x, int y) -> int {
            int res = 0;
            queue<pair<int, int>> q;
            q.push({x, y});
            land[x][y] = -1;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                res++;
                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (dx == 0 && dy == 0) {
                            continue;
                        }
                        if (x + dx < 0 || x + dx >= m || y + dy < 0 || y + dy >= n || land[x + dx][y + dy] != 0) {
                            continue;
                        }
                        land[x + dx][y + dy] = -1;
                        q.push({x + dx, y + dy});
                    }
                }
            }
            return res;
        };

        vector<int> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) {
                    res.push_back(bfs(i, j));
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```

DFS：

```c++
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            if (x < 0 || x >= m || y < 0 || y >= n || land[x][y] != 0) {
                return 0;
            }
            land[x][y] = -1;
            int res = 1;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) {
                        continue;
                    }
                    res += dfs(x + dx, y + dy);
                }
            }
            return res;
        };

        vector<int> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) {
                    res.push_back(dfs(i, j));
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};
```

##### 1659\.最大化网格幸福感

[题目](https://leetcode.cn/problems/maximize-grid-happiness/)

状压压缩代码详解+扩展到多次询问/求最优方案数

状压压缩经典题，思路为：

1. 设三进制状态 $s$ 表示一行，每一位为 $1$ 设为外向者，$2$ 为内向者，$0$ 为无人
2. 设 $g_{i,j}$ 表示上一行状态为 $i$，当前行状态为 $j$ 下的最优解，预处理
3. 设 $dp_{i,u,v,s}$ 表示前 $i$ 行共有 $u$ 个内向者和 $v$ 个外向者，第 $i$ 行状态为 $s$ 的最优解
4. 答案即求 $\max_{i=0}^u\max_{j=0}^v\max_{s}dp_{m,i,j,s}$

其中预处理 $g$ 的复杂度为 $O(3^m\cdot 3^m)=O(3^{2m})\approx6\times10^4$

处理 $dp$ 的复杂度为 $O(nuv3^{2m})\approx 10^7$，空间复杂度为 $O(nuv3^m)\approx4\times 10^4$。

具体思路见代码，有详细注释：

```c++
class Solution
{
public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount);
};
using ll = int;
// 8=min(n*m,6)+2,245=3^5+2
const ll maxn = 8, maxp = 245;
ll g[maxp][maxp], dp[maxn][maxn][maxn][maxp];
//, c[maxn][maxn][maxn][maxp]; (取得最优解的方案数)
// uu:introvertsCount, vv:extrovertsCount
int Solution::getMaxGridHappiness(int n, int m, int uu, int vv)
{
    // 3的幂的常数数组
    constexpr ll n3[] = {1, 3, 9, 27, 81, 243, 729};
    // 三进制状态的每一位,0表示无人,1是外向,2是内向
    constexpr ll no = 0, in = 1, ou = 2;
    // 单位为10,内向外向的基础得分
    constexpr ll basein = 12, baseou = 4;
    // 对单行的三进制状态i,有ins[i]个内向者和outs[i]个外向者
    ll ins[maxp] = {}, ous[maxp] = {};
    /* 设单位为10
    ofs[0] 表示两个外向挨在一块对两人的总加成 2+2=4
    ofs[1] 表示一内一外挨在一块 -3+2=-1
    ofs[2] 表示两内向挨在一块对两人的总加成 -3-3=-6
    */
    constexpr ll ofs[5] = {4, -1, -6};

    // g[i][j]:上一行状态为i,这一行为j是，j这一行的得分
    memset(g, 0, sizeof g);
    // 预处理在上一行影响下每一行所有状态的得分
    for (ll i = 0; i < n3[m]; ++i)
    {
        // 先预处理不考虑上一行的本行得分
        //  state=i当前状态;s是这一行得分,pre是上一格
        ll st = i, s = 0, pre = no;
        do // 逐位枚举这一行每个格子
        {
            ll now = st % 3; // 当前格子
            if (now == in)
            {
                ++ins[i], s += basein;
            }
            else if (now == ou)
            {
                ++ous[i], s += baseou;
            }
            if (pre != no && now != no)
            { // 左右两格挨在一起
                s += ofs[(pre == in) + (now == in)];
            }
            pre = now, st /= 3;
        } while (st);

        // 预处理在上一行影响下的得分g[j][i]
        for (ll j = 0; j < n3[m]; ++j)
        {
            g[j][i] += s; // 不考虑上一行的基础分
            for (ll st1 = i, st2 = j, k = 0; k < m; ++k, st1 /= 3, st2 /= 3)
            {
                ll now = st1 % 3, pre = st2 % 3;
                if (pre != no && now != no)
                { // 上下两格挨在一起
                    g[j][i] += ofs[(pre == in) + (now == in)];
                }
            }
        }
    }

    // dp[i][u][v][now] 前i行共有u个内向者,v个外向者,第i行三进制状态为now下，前i行的总得分
    memset(dp, 0xbf, sizeof dp); // 不是-infty的大负数
    dp[0][0][0][0] = 0;          // 初态
    for (ll i = 1; i <= n; ++i)
    { // 当前第i行
        for (ll u = 0; u <= uu; ++u)
        { // 前i行有u个内向者
            for (ll v = 0; v <= vv; ++v)
            { // 前i行有v个外向者
                for (ll now = 0; now < n3[m]; ++now)
                { // 当前行状态
                    if (ins[now] > u || ous[now] > v)
                    {
                        continue;
                    }
                    // 前i-1行有x个内向者和y个外向者
                    ll x = u - ins[now], y = v - ous[now];
                    for (ll pre = 0; pre < n3[m]; ++pre)
                    { // 上一行状态
                        if (dp[i - 1][x][y][pre] < 0)
                        { // 不可能状态
                            continue;
                        }
                        dp[i][u][v][now] = max(dp[i][u][v][now], dp[i - 1][x][y][pre] + g[pre][now]);
                    }
                }
            }
        }
    }

    // 有i个内向者j个外向者时的最优解
    // 即a[i][j]=max(dp[n][i][j][now])
    ll a[maxn][maxn] = {};
    for (ll i = 0; i <= uu; ++i)
    { // 内向者数目
        for (ll j = 0; j <= vv; ++j)
        { // 外向者数目
            for (ll k = 0; k < n3[m]; ++k)
            { // 第n行状态
                a[i][j] = max(a[i][j], dp[n][i][j][k]);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= uu; ++i)
    { // 内向者数目
        for (ll j = 0; j <= vv; ++j)
        { // 外向者数目
            ans = max(ans, a[i][j]);
        }
    }
    return ans * 10; // 基本单位10
}
```

**扩展：**

[多次询问题目](https://oj.socoding.cn/p/1397) (SCNUCPC2020A题)

该题与本题的区别为：

- 对同一个 $n,m$，有 $Q(Q\le 49)$ 次不同的 $u,v$ 询问
- 每个询问不仅要求出最优解，还要求出取得最优解的方案数

思路很接近，修改上述代码，即可得到：

```c++
#include <bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ln;
typedef int ll;
#define il inline
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repe(i,a,b) for(ll i=a;i<=b;++i)
#define red(i,a,b) for(ll i=a;i>b;--i)
#define rede(i,a,b) for(ll i=a;i>=b;--i)
#define orep(i,a,b) for(i=a;i<b;++i)
#define orepe(i,a,b) for(i=a;i<=b;++i)
#define ored(i,a,b) for(i=a;i>b;--i)
#define orede(i,a,b) for(i=a;i>=b;--i)
inline ll read()
{
	char p = 0; ll r = 0, o = 0;
	for (; p < '0' || p>'9'; o |= p == '-', p = getchar());
	for (; p >= '0' && p <= '9'; r = (r << 1) + (r << 3) + (p ^ 48), p = getchar());
	return o ? (~r) + 1 : r;
}
#define mn 245 //3^5
#define mm 6
#define big 0x7ffffffa
ll g[mn][mn], in[mn], out[mn], n3[] = { 1,3,9,27,81,243,729 };
//in[i] how many chino in state(i), out[i] likewise
//g[i][j] 是上一行为i，下一行为j时下一行的分数
ll ofs[5] = { 4,-1,-6 }, dp[8][8][8][mn], c[8][8][8][mn];
//ofs[0] neighbor both cocas; [1]cocas x chino; [2] both chino
ll a[8][8], b[8][8], n, m, q, u, v;
signed main()
{
	n = read(), m = read(), q = read();
	rep(i, 0, n3[m])
	{
		ll x = 0, y = 0, s = 0, st = i;
		do 
		{
			y = st % 3;
			if (y == 1) ++in[i], s += 12; //chino
			else if (y == 2) ++out[i], s += 4; //cocoa
			if (x && y) //neighbor in row
				s += ofs[(x == 1) + (y == 1)];
			x = y; //last y
			st /= 3;
		} while (st);
		rep(pre, 0, n3[m])//upper line, likewise
		{
			g[pre][i] += s;
			for (ll st1 = i, st2 = pre, j = 0; j < m; ++j, st1 /= 3, st2 /= 3)
			{
				x = st1 % 3, y = st2 % 3;
				if (x && y) g[pre][i] += ofs[(x == 1) + (y == 1)];
			}
            cout << pre << ' ' << i << ' ' << g[pre][i] << '\n';
		}
	}
	//rep(i, 0, 8) rep(j, 0, 8) rep(k, 0, 8) rep(h, 0, mn)
	//	dp[i][j][k][h] = -1; //+1类问题；且这个负值必须大于max(g[i][j])
	memset(dp, 0xbf, sizeof dp);//事实表明该函数比循环赋值快
	dp[0][0][0][0] = 0, c[0][0][0][0] = 1;
	repe(i, 1, n)
		repe(u, 0, mm)//注意到mm不是到m；开到mm的原因是u,v不一定小于n,m
			repe(v, 0, mm)
				rep(now, 0, n3[m])
				{
					if (in[now] > u || out[now] > v) continue;
					ll x = u - in[now], y = v - out[now];
					//在这一行之前，chino和cocoa放了x和y棋子
					rep(pre, 0, n3[m])
					{
						if (dp[i - 1][x][y][pre] < 0) continue;
						if (dp[i][u][v][now] < dp[i - 1][x][y][pre] + g[pre][now])//有更优解
							dp[i][u][v][now] = dp[i - 1][x][y][pre] + g[pre][now],
							c[i][u][v][now] = c[i - 1][x][y][pre];
						else if (dp[i][u][v][now] == dp[i - 1][x][y][pre] + g[pre][now])//最优解积累
							c[i][u][v][now] += c[i - 1][x][y][pre];
					}
				}
	repe(i, 0, mm)
		repe(j, 0, mm)
			rep(k, 0, n3[m])//求放棋为i,j时的最优解及其解法数
				if (dp[n][i][j][k] > a[i][j])
					a[i][j] = dp[n][i][j][k],
					b[i][j] = c[n][i][j][k];
				else if (dp[n][i][j][k] == a[i][j])
					b[i][j] += c[n][i][j][k];
	while (q--)
	{
		u = read(), v = read();
		ll mx = 0, s = 0;
		repe(i, 0, u)
			repe(j, 0, v)//求在放棋数范围为[0,u],[0,v]下最优解及其个数
				if (a[i][j] > mx) mx = a[i][j], s = b[i][j];
				else if (a[i][j] == mx) s += b[i][j];
		printf("%d %d\n", mx, s);
	}
	return 0;
}
```



题解朴素状压，基本思路是一样的：

```c++
class Solution {
private:
    static constexpr int T = 243, N = 5, M = 6;
    int n, m, tot;
    int mask_bits[T][N];
    int iv_count[T], ev_count[T];
    int inner_score[T], inter_score[T][T];
    int d[N][T][M + 1][M + 1];

    // 邻居间的分数
    static constexpr int score[3][3] = {
        {0, 0, 0},
        {0, -60, -10},
        {0, -10, 40}
    };

public:
    void init_data() {
        // 计算行内分数
        for (int mask = 0; mask < tot; mask++) {
            int mask_tmp = mask;
            for (int i = 0; i < n; i++) {
                int x = mask_tmp % 3;
                mask_bits[mask][i] = x;
                mask_tmp /= 3;
                if (x == 1) {
                    iv_count[mask]++;
                    inner_score[mask] += 120;
                } else if (x == 2) {
                    ev_count[mask]++;
                    inner_score[mask] += 40;
                }
                if (i > 0) {
                    inner_score[mask] += score[x][mask_bits[mask][i - 1]];
                }
            }
        }
        // 计算行间分数
        for (int i = 0; i < tot; i++) {
            for (int j = 0; j < tot; j++) {
                inter_score[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    inter_score[i][j] += score[mask_bits[i][k]][mask_bits[j][k]];
                }
            }
        }
    }

    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->n = n;
        this->m = m;
        // 状态总数为 3^n
        this->tot = pow(3, n);

        init_data();
        // 记忆化搜索数组，初始化为 -1，表示未赋值
        memset(d, -1, sizeof d);
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }

    int dfs(int row, int premask, int iv, int ev) {
        if (row == m || (iv == 0 && ev == 0)) {
            return 0;
        }
        // 如果该状态已经计算过答案，则直接返回
        if (d[row][premask][iv][ev] != -1) {
            return d[row][premask][iv][ev];
        }
        // 使用引用，简化代码
        int& res = d[row][premask][iv][ev];
        // 合法状态，初始值为 0
        res = 0;
        for (int mask = 0; mask < tot; mask++) {
            // mask 包含的内向人数不能超过 iv ，外向人数不能超过 ev
            if (iv_count[mask] > iv || ev_count[mask] > ev) {
                continue;
            }
            res = max(res, dfs(row + 1, mask, iv - iv_count[mask], ev - ev_count[mask]) 
                            + inner_score[mask] 
                            + inter_score[premask][mask]);
        }
        return res;
    }
};
```



轮廓线优化：

按行枚举每次需要枚举 $3^n$ 种状态。如果可以按位置行枚举，只需要 $3$ 种状态。

设一维坐标 $pos=xm+y$，则当前元素 $h_{pos}$ 只需要根据左边状态和上边状态 $h_{pos-1}$ 和 $h_{pos-m}$ 更新相邻分数。即连续共 $[pos-m,pos-1]$ 有 $m$ 个位置保留记忆。设掩码为前 $m$ 个格子。状态更新为：
$$
mask=mask\bmod 3^{m-1}\times 3+h_{pos}
$$
定义 $dp_{pos,mask,u,v}$ 表示枚举到第 $pos$ 个格子，轮廓线为 $mask$，尚有 $u,v$ 个内外向者未放置。则时间复杂度压一个 $3^m$，多一个 $m$，即 $O(nmuv3^m)$。

```c++
class Solution {
private:
    static constexpr int T = 243, N = 5, M = 6;
    int n, m, tot;
    int p[N];
    int d[N * N][T][M + 1][M + 1];

    // 邻居间的分数
    static constexpr int score[3][3] = {
        {0, 0, 0},
        {0, -60, -10},
        {0, -10, 40}
    };

public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        this->n = n;
        this->m = m;
        // 状态总数为 3^n
        this->tot = pow(3, n);
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            p[i] = p[i - 1] * 3;
        }
        
        // 记忆化搜索数组，初始化为 -1，表示未赋值
        memset(d, -1, sizeof d);
        return dfs(0, 0, introvertsCount, extrovertsCount);
    }

    int dfs(int pos, int mask, int iv, int ev) {
        if (pos == n * m || (iv == 0 && ev == 0)) {
            return 0;
        }
        int& res = d[pos][mask][iv][ev];
        if (res != -1) {
            return res;
        }
        res = 0;
        int up = mask / p[n - 1], left = mask % 3;
        // 若处于第一列，则左侧没有元素，将 left 置为 0
        if (pos % n == 0) {
            left = 0;
        }
        for (int i = 0; i < 3; i++) {
            if ((i == 1 && iv == 0) || (i == 2 && ev == 0)) {
                continue;
            }
            int next_mask = mask % p[n - 1] * 3 + i;
            int score_sum = dfs(pos + 1, next_mask, iv - (i == 1), ev - (i == 2))
                            + score[up][i]
                            + score[left][i];
            if (i == 1) {
                score_sum += 120;
            } else if (i == 2) {
                score_sum += 40;
            }
            res = max(res, score_sum);
        }
        return res;
    }
};
```

计算几何基础问题通用板子

对本题，若有重叠，分为两种情况：

1. 圆心在矩形内部，直接判断即可。
2. 圆心在举行外部，将圆心 $P$ 与四条矩形线段 $AB,BC,CD,DA$ 分别求点到线段的距离，如果存在一个距离大于等于半径，则重叠。

其中，点 $P$ 到线段 $AB$ 距离的公式为：
$$
d=\begin{cases}
\dfrac{|\vec{AB}\times \vec{AP}|}{|AB|},& P投影在线段AB内\\
|PA|,& P投影在射线AB后边\\
|PB|,& P投影在射线AB前边，不在线段AB内
\end{cases}
$$
直接套模板(完整模板和所有能解决的问题及其证明见下文)，得：

```c++
using db = double;
#define cp const point &
class point
{
public:
    db x, y;
    point(db x = 0, db y = 0) : x(x), y(y) {}
    point operator+(cp p) const { return point(x + p.x, y + p.y); }
    point operator-(cp p) const { return point(x - p.x, y - p.y); }
    point operator*(const db &p) const { return point(x * p, y * p); }
    point operator/(const db &p) const { return point(x * p, y * p); }
    db norm() const { return x * x + y * y; }
    db abs() const { return sqrt(norm()); }
    friend db dot(cp a, cp b)
    {
        return a.x * b.x + a.y * b.y;
    }
    friend db cross(cp a, cp b)
    {
        return a.x * b.y - a.y * b.x;
    }
};
db dis(cp a, cp b, cp p) // p到线段ab的距离
{
    if (dot(b - a, p - a) < 0.0)
    {
        return (p - a).abs();
    }
    if (dot(a - b, p - b) < 0.0)
    {
        return (p - b).abs();
    }
    return abs(cross(b - a, p - a)) / (b - a).abs();
}
class Solution
{
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2)
    {
        if (x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2)
        { // 内含
            return true;
        }
        point p = point(xCenter, yCenter);
        point a = point(x1, y1), b = point(x2, y1), c = point(x2, y2), d = point(x1, y2);
        if (dis(a, b, p) <= radius || dis(b, c, p) <= radius || dis(c, d, p) <= radius || dis(d, a, p) <= radius)
        {
            return true;
        }
        return false;
    }
};
```

完整基础计算几何模板(个人整理版)：

- [计算几何课件](https://github.com/lr580/shannon_sources/blob/master/%E8%AF%BE%E4%BB%B6_%E8%AE%A1%E7%AE%97%E5%87%A0%E4%BD%95/%E8%AE%A1%E7%AE%97%E5%87%A0%E4%BD%95.md) (含证明)
- [其他算法模板](https://github.com/lr580/algorithm_template)

这份计算几何模板能解决：

1. 点/向量

   点积 差积 点旋转 向量平行/垂直 极坐标互换

2. 线段/直线

   1. 点到直线距离 点到线段距离
   2. 线段是否相交 线段与直线是否相交 线段与线段距离 直线与线段距离
   3. 直线交点 线段交点
   4. 点到直线的投影 点关于直线的对称点 圆与直线交点 圆与圆的交点

3. 多边形

   面积 点是否在多边形内部(PIP)

4. 极角排序(两种实现及其应用)

5. 凸包(可求凸多边形直径)

6. 面积估算

   微分 蒙特卡洛 积分 二分/三分优化

如有需要欢迎下载阅读。



本题特化题解：

思路一：

沿着矩形一圈放圆心移动，可以得到一个圆角矩形，圆心只要在这个圆角矩形的范围内就重叠。则分为圆心在：中心、四个外边矩形、四个圆角(可抽象为点在圆内)，共九种情况，分类讨论即可：

```c++
class Solution {
public:
    long long distance(int ux, int uy, int vx, int vy) {
        return (long long)pow(ux - vx, 2) + (long long)pow(uy - vy, 2);
    }

    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        /* 圆心在矩形内部 */
        if (x1 <= xCenter && xCenter <= x2 && y1 <= yCenter && yCenter <= y2) {
            return true;
        }
        /* 圆心在矩形上部*/
        if (x1 <= xCenter && xCenter <= x2 && y2 <= yCenter && yCenter <= y2 + radius) {
            return true;
        }
        /* 圆心在矩形下部*/
        if (x1 <= xCenter && xCenter <= x2 && y1 - radius <= yCenter && yCenter <= y1) {
            return true;
        }
        /* 圆心在矩形左部*/
        if (x1 - radius <= xCenter && xCenter <= x1 && y1 <= yCenter && yCenter <= y2) {
            return true;
        }
        /* 圆心在矩形右部*/
        if (x2 <= xCenter && xCenter <= x2 + radius && y1 <= yCenter && yCenter <= y2) {
            return true;
        }
        /* 矩形左上角 */
        if (distance(xCenter, yCenter, x1, y2) <= radius * radius)  {
            return true;
        }
        /* 矩形左下角 */
        if (distance(xCenter, yCenter, x1, y1) <= radius * radius) {
            return true;
        }
        /* 矩形右上角 */
        if (distance(xCenter, yCenter, x2, y2) <= radius * radius) {
            return true;
        }
        /* 矩形右下角 */
        if (distance(xCenter, yCenter, x1, y2) <= radius * radius) {
            return true;
        }
        /* 无交点 */
        return false;
    }
};
```

解法二：先求出只看x坐标圆心到矩形的最小距离 $x$，在求出只看y坐标的最小距离 $y$，那么圆心到矩形的最小距离就是 $\sqrt{x^2+y^2}$。两边平方消精度误差。

```c++
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        long long dist = 0;
        if (xCenter < x1 || xCenter > x2) {
            dist += min(pow(x1 - xCenter, 2), pow(x2 - xCenter, 2));
        }
        if (yCenter < y1 || yCenter > y2) {
            dist += min(pow(y1 - yCenter, 2), pow(y2 - yCenter, 2));
        }
        return dist <= radius * radius;
    }
};
```

##### 2485\.找出中枢整数

[题目](https://leetcode.cn/problems/find-the-pivot-integer/)

等差数列公式 $\dfrac{n(a_1+a_n)}{2}$，解得 $x=\pm\sqrt{\dfrac{n^2+n}2}$。

判断 $x$ 是否是整数，只需要判断求出来的 $x^2$ 是否等于开方前的数即可。

```c++
class Solution {
public:
    int pivotInteger(int n) {
        int t = (n * n + n) / 2;
        int x = sqrt(t);
        if (x * x == t) {
            return x;
        }
        return -1;
    }
};
```

个人实现：不判断整数，直接代回去看看是否有解。

```c++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int pivotInteger(int n)
    {
        int x = round(sqrt((n * n + n) / 2));
        if (x * (1 + x) == (n - x + 1) * (n + x))
        {
            return x;
        }
        return -1;
    }
};
```



##### 1186\.删除一次得到子数组最大和

[题目](https://leetcode.cn/problems/maximum-subarray-sum-with-one-deletion/)

设下标 $1$ 开始，前缀和为 $s$，即求：
$$
\max_{r=1}^n( s_r-\min_{l=1}^{r-1}(s_{l-1}+\min(0,\min_{i=l}^ra_i)))
$$
不能滑窗(+RMQ/multiset)。

使用 DP：设 $dp_{i,k}$ 表示以 $i$ 结尾，删了 $k$ 次的非空子树组最大和。初始 $dp_{0,?}=0$，转移：
$$
dp_{i,0}=\max(dp_{i-1,0},0)+a_0,\quad dp_{i,1}=\max(dp_{i-1,1}+a_{i},dp_{i-1,0})
$$
答案：$\max dp$。

在不删的情况下，即取最大 $s_r-\min s_{l-1}$，$dp_{i,0}$ 与之等价。

在删的情况下，已经删了就不能删了；还没删就把当前 $a_i$ 给删了。

```c++
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int dp0 = arr[0], dp1 = 0, res = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            dp1 = max(dp0, dp1 + arr[i]);
            dp0 = max(dp0, 0) + arr[i];
            res = max(res, max(dp0, dp1));
        }
        return res;
    }
};
```

##### 1681\.最小不兼容性

[题目](https://leetcode.cn/problems/minimum-incompatibility/)

设 $dp_i$ 是二进制状态 $i$ 的答案，即求 $dp_{2^n-1}$ 的值。初始 $dp_0=0$，其余 $dp=\infty$。

首先预处理所有子集，求出全体长为 $\dfrac nk$ 的且不含相等值的状态，计算它的值存为 $v_i$。

枚举所有状态 $mask$，求出该状态尚未被分配元素的集合 $sub$，相等元素只保留最后出现的一个，遍历 $sub$ 的全体子集 $nxt$，有：
$$
dp_{mask|cnt}=\min_{nxt\ is\ valid}(dp_{mask}+v_{nxt})
$$
枚举子集，故复杂度为 $O(3^n)\approx1.4\times 10^7$，空间为 $O(2^n)$。

```c++
class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(1 << n, INT_MAX);
        dp[0] = 0;
        int group = n / k;
        unordered_map<int, int> values;

        for (int mask = 1; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) != group) {
                continue;
            }
            int mn = 20, mx = 0;
            unordered_set<int> cur;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    if (cur.count(nums[i]) > 0) {
                        break;
                    }
                    cur.insert(nums[i]);
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);
                }
            }
            if (cur.size() == group) {
                values[mask] = mx - mn;
            }
        }

        for (int mask = 0; mask < (1 << n); mask++) {
            if (dp[mask] == INT_MAX) {
                continue;
            }
            unordered_map<int, int> seen;
            for (int i = 0; i < n; i++) {
                if ((mask & (1 << i)) == 0) { //mask没有的全体不重元素
                    seen[nums[i]] = i;
                }
            }
            if (seen.size() < group) { //不同元素的个数
                continue;
            }
            int sub = 0;
            for (auto& pair : seen) {
                sub |= (1 << pair.second);
            }
            int nxt = sub;
            while (nxt > 0) {
                if (values.count(nxt) > 0) { //在某个n/k子集里
                    dp[mask | nxt] = min(dp[mask | nxt], dp[mask] + values[nxt]);
                }
                nxt = (nxt - 1) & sub;
            }
        }

        return (dp[(1 << n) - 1] < INT_MAX) ? dp[(1 << n) - 1] : -1;
    }
};
```



##### 1253\.重构2行二进制矩阵

[题目](https://leetcode.cn/problems/reconstruct-a-2-row-binary-matrix/)

个人：

```c++
class Solution
{
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int> &colsum)
    {
        int s = 0, n = colsum.size();
        for (auto x : colsum)
        {
            s += x;
        }
        vector<vector<int>> emp;
        if (s != upper + lower)
        {
            return emp;
        }
        vector<vector<int>> r = vector(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            if (colsum[i] == 2)
            {
                r[0][i] = r[1][i] = 1;
                --upper, --lower;
            }
            // cout << upper << ' ' << lower << '\n';
        }
        for (int i = 0; i < n; ++i)
        {
            if (colsum[i] == 1)
            {
                if (upper > 0)
                {
                    r[0][i] = 1;
                    --upper;
                }
                else
                {
                    r[1][i] = 1;
                    --lower;
                }
            }
        }
        if (upper != 0 || lower != 0)
        {
            return emp;
        }
        return r;
    }
};
```

题解，只需要一次 for：

```c++
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        int sum = 0, two = 0;
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                ++two;
            }
            sum += colsum[i];
        }
        if (sum != upper + lower || min(upper, lower) < two) {
            return {};
        }
        upper -= two;
        lower -= two;
        vector<vector<int>> res(2, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            if (colsum[i] == 2) {
                res[0][i] = res[1][i] = 1;
            } else if (colsum[i] == 1) {
                if (upper > 0) {
                    res[0][i] = 1;
                    --upper;
                } else {
                    res[1][i] = 1;
                }
            }
        }
        return res;
    }
};
```

##### 2490\.回环句

[题目](https://leetcode.cn/problems/circular-sentence/)

个人实现：

```c++
class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        stringstream ss(sentence);
        vector<string> a;
        string t;
        while (ss >> t)
        {
            a.push_back(t);
        }
        int n = a.size(), ok = true;
        for (int i = 0, j = (i + 1) % n; i < n; ++i, j = (j + 1) % n)
        {
            ok &= a[i].back() == *a[j].begin();
        }
        return ok;
    }
};
```

更优雅：

```c++
class Solution {
public:
    bool isCircularSentence(string sentence) {
        if (sentence.back() != sentence.front()) {
            return false;
        }
        for (int i = 0; i < sentence.size(); i++) {
            if (sentence[i] == ' ' && sentence[i + 1] != sentence[i - 1]) {
                return false;
            } 
        }
        return true;
    }
};
```

##### 445\.两数相加II

[题目](https://leetcode.cn/problems/add-two-numbers-ii/solution/)

个人暴力：转array手撕高精度转回去

```c++
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto toArray = [](ListNode *it)
        {
            vector<int> v;
            for (; it; it = it->next)
            {
                v.push_back(it->val);
            }
            reverse(v.begin(), v.end());
            return v;
        };
        vector<int> a = toArray(l1), b = toArray(l2);
        int n = max(a.size(), b.size());
        vector<int> r = vector<int>(n + 1, 0);
        for (int i = 0, c = 0; i <= n; ++i)//<n的话进位不了
        {
            int sum = c;//不能够c+a[i]+b[i]小心越界飞
            sum += i < a.size() ? a[i] : 0;
            sum += i < b.size() ? b[i] : 0;
            r[i] = sum % 10;
            c = sum / 10;
            // cout << r[i] << ' ' << c << '\n';
        }
        ListNode *head = new ListNode(), *ans = head;
        while (r.size() > 1 && r.back() == 0)//size()>1否则0+0=empty
        {
            r.pop_back();
        }
        // for (int i = 0; i < r.size(); ++i)
        for (int i = r.size() - 1; i >= 0; --i)
        {
            ListNode *it = new ListNode(r[i]);
            head->next = it;
            head = it;
        }
        return ans->next;
    }
};
```

答案：栈+反向建链

```c++
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() or !s2.empty() or carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
    }
};
```

##### 2178\.拆分成最多数目的正偶数之和

[题目](https://leetcode.cn/problems/maximum-split-of-positive-even-integers/)

对于 $finalSum = \sum_{i=1}^n2i$ 的所有 $finalSum$ 该构造显然最优，然后对其他的，先找到唯一 $n$ 满足 $\sum_{i=1}^n2i\le finalSum < \sum_{i=1}^{n+1}2i$，然后把这个前 $n$ 项和的最后一项调大使得刚好凑够 $finalSum$ 即可。

个人实现：

 ```c++
using ll = long long;
class Solution
{
public:
    vector<ll> maximumEvenSplit(ll s)
    {
        if (s % 2)
        {
            return {};
        }
        ll r = 0;
        vector<ll> a;
        for (ll i = 2; r + i <= s; i += 2)
        {
            r += i;
            a.push_back(i);
        }
        ll last = a.back();
        a.pop_back();
        a.push_back(s - (r - last));
        return a;
    }
};
 ```

优雅实现：

```c++
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum % 2 > 0) {
            return res;
        }
        for (int i = 2; i <= finalSum; i += 2) {
            res.push_back(i);
            finalSum -= i;
        }
        res.back() += finalSum;
        return res;
    }
};
```

##### 167. 两数之和 II - 输入有序数组

[题目](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)

二分：

```c++
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0; i < n; ++i)
        {
            auto j = lower_bound(numbers.begin() + i + 1, numbers.end(), target - numbers[i]);
            if (j != numbers.end() && *j + numbers[i] == target)
            {
                return {1 + i, 1 + (int)distance(numbers.begin(), j)};
            }
        }
        return {};
    }
};
```

题解写法二分：

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = (high - low) / 2 + low;
                if (numbers[mid] == target - numbers[i]) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] > target - numbers[i]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return {-1, -1};
    }
};
```

双指针：

初设 $i,j$ 是两端端点，若 $a_i+a_j < s$，则 $\forall j' < j,a_i+a_{j'} < s$，故剩余解空间里当前 $i$ 的所有 $(i,j)$ 都不必再搜索，故先不断右移 $i$，约等于删除一个元素后考虑子问题，直到 $a_i+a_j \ge s$，如果 $>s$，则同理 $\forall i' > i,a_{i'}+a_j > s,$，即当前 $j$ 的所有 $(i,j)$ 不必再搜索，考虑左移 $j$，直到再次 $\le s$。

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }
};
```

##### 15\.三数之和

[题目](https://leetcode.cn/problems/3sum/)

二分优化最后一层枚举，$O(n^2\log n)$。

```c++
class Solution
{
public:
    using node = tuple<int, int, int>;
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        set<node> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int w = -nums[i] - nums[j];
                auto it = lower_bound(nums.begin() + j + 1, nums.end(), w);
                if (it != nums.end() && *it == w)
                {
                    ans.insert({nums[i], nums[j], w});
                }
            }
        }
        vector<vector<int>> r;
        for (node nd : ans)
        {
            auto [u, v, w] = nd;
            r.push_back({u, v, w});
        }
        return r;
    }
};

/* 反正TLE了
class Solution
{
public:
    using node = tuple<int, int, int>;
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        map<int, vector<int>> m;
        set<node> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            m[nums[i]].push_back(i);
            if (m[nums[i]].size() > 3)
            {
                m[nums[i]].erase(m[nums[i]].begin());
            }
        }
        // for (auto it = m.begin(); it != m.end(); ++it)
        // {
        //     vector<int> &v = it->second;
        //     sort(v.begin(), v.end());
        //     reverse(v.begin(), v.end());
        // }
        vector<vector<int>> r;
        // FFT可以优化这个for-for为O(nlogn)
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int w = -(nums[i] + nums[j]);
                for (auto k : m[w])
                {
                    if (k > j)
                    {
                        ans.insert({nums[i], nums[j], w});
                        break;
                    }
                }
            }
        }
        for (node nd : ans)
        {
            auto [u, v, w] = nd;
            r.push_back({u, v, w});
        }
        return r;
    }
};
*/
```

std 是排序后双指针：

考虑子问题：对元素互异有序数组，找出所有 $x+y=z$  的 $(x,y)$ 对。设双指针在两边 $i=0,j=n-1$，对当前 $j$，若 $a_i+a_j > z$，则根据上一题可知，所有 $(i,j)$ 都不可能，故 $j$ 缩小，如果恰好 $a_i+a_j=z$ 就凑上去。左指针按枚举顺序增加即可。

考虑剔除重复元素：①全部搞完去重；②与上一个答案对比去重；③对每次枚举 $i$，仅枚举比上一个 $a_i$ 大的最小 $i$。(考虑 $1+1=2$，不会去掉正确答案)。共 $O(n)$。

同理，对 $x+y+z=0$，枚举 $z$(同 ③ 去重)，再重复上述过程即可。$O(n^2)$

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};
```

##### 16\.最接近的三数之和

[题目](https://leetcode.cn/problems/3sum-closest/)

二分优化枚举，找相等的相近数 $O(n^2\log n)$

```c++
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = -1e9, n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int v = target - nums[i] - nums[j];
                int k = lower_bound(nums.begin() + j + 1, nums.end(), v) - nums.begin();
                if (k - 1 > j)
                {
                    int w1 = nums[i] + nums[j] + nums[k - 1];
                    if (abs(target - ans) > abs(target - w1))
                    {
                        ans = w1;
                    }
                }
                if (k > j && k != n)
                {
                    int w2 = nums[i] + nums[j] + nums[k];
                    if (abs(target - ans) > abs(target - w2))
                    {
                        ans = w2;
                    }
                }
            }
        }
        return ans;
    }
};
```

答案：双指针 $O(n^2)$

考虑子问题对 $x+y=z$ 凑最接近的，对 $i,j$，若 $a_i+a_j > z$，则所有 $j$ 的其他数对只会更差，故 $j$ 左移；同理，若 $a_i+a_j < z$，则所有 $i$ 的其他数对只会更差。故仿照上一题即可。

```c++
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int best = 1e7;

        // 根据差值的绝对值来更新答案
        auto update = [&](int cur) {
            if (abs(cur - target) < abs(best - target)) {
                best = cur;
            }
        };

        // 枚举 a
        for (int i = 0; i < n; ++i) {
            // 保证和上一次枚举的元素不相等
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 使用双指针枚举 b 和 c
            int j = i + 1, k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                // 如果和为 target 直接返回答案
                if (sum == target) {
                    return target;
                }
                update(sum);
                if (sum > target) { // 不 while 也行等下一轮
                    // 如果和大于 target，移动 c 对应的指针
                    int k0 = k - 1;
                    // 移动到下一个不相等的元素
                    while (j < k0 && nums[k0] == nums[k]) {
                        --k0;
                    }
                    k = k0;
                } else {
                    // 如果和小于 target，移动 b 对应的指针
                    int j0 = j + 1;
                    // 移动到下一个不相等的元素
                    while (j0 < k && nums[j0] == nums[j]) {
                        ++j0;
                    }
                    j = j0;
                }
            }
        }
        return best;
    }
};
```

##### 1911\. 最大子序列交替和

[题目](https://leetcode.cn/problems/maximum-alternating-subsequence-sum/)

思路：先找单调不减的最高值作第一个数，然后不断找接下来单调不增的最低值作减数、再接着找单调不减的最高值作被减数，找到时这两个数加入子序列中。

```c++
class Solution
{
public:
    using ll = long long;
    ll maxAlternatingSum(const vector<int> &nums)
    {
        constexpr int findlow = 0, findhigh = 1;
        int status = findhigh, n = nums.size();
        ll low = 0, high, ans = 0, prv = -1e9;
        auto add = [&]()
        { ans += high - low; };
        for (int i = 0; i < n; ++i)
        {
            if (status == findhigh)
            {
                if (nums[i] >= prv)
                {
                    high = nums[i];
                }
                else
                {
                    status = findlow;
                    add();
                    low = nums[i];
                }
            }
            else
            {
                if (nums[i] <= prv)
                {
                    low = nums[i];
                }
                else
                {
                    high = nums[i];
                    status = findhigh;
                }
            }
            prv = nums[i];
        }
        if (status == findhigh)
        {
            add();
        }
        return ans;
    }
};
```

设 $dp_{i,j}$ 是在前 $i$ 个数选子序列，且最后一个元素下标奇偶性为 $j$ 的答案。

初始值为 $dp_{0,0}=nums_0,dp_{0,1}=0$

则 $dp_{i,0}=\max(dp_{i-1,0},dp_{i-1,1}+nums_i)$

且 $dp_{i,1}=\max(dp_{i-1,1},dp_{i-1,0}-nums_i)$

答案为 $dp_{n,0/1}$ 的最大值。滚动一下。

```c++
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long even = nums[0], odd = 0;
        for (int i = 1; i < nums.size(); i++) {
            even = max(even, odd + nums[i]);
            odd = max(odd, even - nums[i]);
        }
        return even;
    }
};
```

##### 979\.在二叉树中分配硬币

[题目](https://leetcode.cn/problems/distribute-coins-in-binary-tree/)

最近公共祖先+网络流

大炮打蚊子的究极暴力解法：LCA+最小费用最大流。

思路：

1. 首先建树，将题给二叉链表转为邻接表/链式前向星等存图方便后续处理

2. 预处理出每两点间的距离，可以使用任意全源最短路算法，考虑到是树，这里使用了倍增法求树上公共祖先($O(n\log n)$ 预处理和 $O(\log n)$ 查询)，然后以此为基础求树上两点距离。也可以使用更优的欧拉序RMQ求树上公共祖先($O(n\log n)$ 预处理和 $O(1)$ 查询)

3. 设 $a_i$ 是点 $i$ 的硬币数，则所有 $a_u > 1$ 的点 $u$ 需要转移 $a_u-1$ 个硬币给 $a_v=0$ 的点 $v$。不妨进行网络流建模：

   设源点到上述 $u$ 点连流量为 $a_u-1$ 费用为 $0$ 的边，$u$ 点到 $v$ 点连流量为 $1$ 单位费用为 $dis(u,v)$(两点距离)的边，且 $v$ 点向汇点连流量为 $1$ 费用为 $0$ 的边，然后求最小费用最大流并输出最小费用即可。

   整体复杂度取求网络流复杂度，使用 MCFN 求网络流，复杂度约为 $O(n^3)$

核心代码：

```c++
vector<int> g[maxn];
int n, a[maxn];
int distributeCoins(TreeNode *root)
{
    build(root, 0); //上述第一步
    init(); //求树上k级祖先
    MCFN<int, int> mcfn(n + 2);
    const int s = n, t = n + 1;
    for (int u = 1; u <= n; ++u) //网络流建模
    {
        if (a[u] > 1)
        {
            mcfn.add_edge(s, u - 1, a[u] - 1, 0);
            for (int v = 1; v <= n; ++v)
            {
                if (a[v] == 0)
                {
                    mcfn.add_edge(u - 1, v - 1, 1, dis(u, v));
                }
            }
        }
        else if (a[u] == 0)
        {
            mcfn.add_edge(u - 1, t, 1, 0);
        }
    }
    return ssp(mcfn.prepare(), s, t).second;
}
```

完整代码：含网络流和 LCA 代码

```c++
namespace details
{
    inline unsigned int bsf32(uint32_t n) noexcept
    {
#if defined __GNUC__
        return __builtin_ctz(n);
#elif defined _MSC_VER
        unsigned long ans;
        _BitScanForward(&ans, n);
        return ans;
#elif
        static constexpr unsigned char table[32] = {
            0,
            1,
            28,
            2,
            29,
            14,
            24,
            3,
            30,
            22,
            20,
            15,
            25,
            17,
            4,
            8,
            31,
            27,
            13,
            23,
            21,
            19,
            16,
            7,
            26,
            12,
            18,
            6,
            11,
            5,
            10,
            9,
        };
        return table[((n & -n) * 0x077CB531) >> 57];
#endif
    }

    inline unsigned int bsf64(uint64_t n) noexcept
    {
#if defined __GNUC__
        return __builtin_ctzll(n);
#elif defined _MSC_VER
        unsigned long ans;
        _BitScanForward64(&ans, n);
        return ans;
#elif
        static constexpr unsigned char table[64] = {
            0,
            1,
            56,
            2,
            57,
            49,
            28,
            3,
            61,
            58,
            42,
            50,
            38,
            29,
            17,
            4,
            62,
            47,
            59,
            36,
            45,
            43,
            51,
            22,
            53,
            39,
            33,
            30,
            24,
            18,
            12,
            5,
            63,
            55,
            48,
            27,
            60,
            41,
            37,
            16,
            46,
            35,
            44,
            21,
            52,
            32,
            23,
            11,
            54,
            26,
            40,
            15,
            34,
            20,
            31,
            10,
            25,
            14,
            19,
            9,
            13,
            8,
            7,
            6,
        };
        return table[((n & -n) * 0x03f79d71b4ca8b09) >> 58];
#endif
    }

    inline unsigned int bsr32(uint32_t n) noexcept
    {
#if defined __GNUC__
        return 31 - __builtin_clz(n);
#elif defined _MSC_VER
        unsigned long ans;
        _BitScanReverse(&ans, n);
        return ans;
#elif
        float t = n;
        uint32_t ans;
        memcpy(&ans, &t, sizeof(float));
        return (ans >> 23 & 255) - 127;
#endif
    }

    inline unsigned int bsr64(uint64_t n) noexcept
    {
#if defined __GNUC__
        return 63 - __builtin_clzll(n);
#elif defined _MSC_VER
        unsigned long ans;
        _BitScanReverse64(&ans, n);
        return ans;
#elif
        float t = n;
        uint32_t ans;
        memcpy(&ans, &t, sizeof(float));
        return (ans >> 23 & 255) - 127;
#endif
    }

    inline unsigned int popcnt32(uint32_t n) noexcept
    {
#if defined __GNUC__
        return __builtin_popcount(n);
#elif defined _MSC_VER
        return __popcnt(n);
#elif
        n -= ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        return ((((n >> 4) + n) & 0x0f0f0f0f) * 0x01010101) >> 24;
#endif
    }

    inline unsigned int popcnt64(uint64_t n) noexcept
    {
#if defined __GNUC__
        return __builtin_popcountll(n);
#elif defined _MSC_VER
        return __popcnt64(n);
#elif
        n -= ((n >> 1) & 0x5555555555555555);
        n = (n & 0x3333333333333333) + ((n >> 2) & 0x3333333333333333);
        return ((((n >> 4) + n) & 0x0f0f0f0f0f0f0f0f) * 0x0101010101010101) >> 56;
#endif
    }

    inline unsigned int parity32(uint32_t n) noexcept
    {
#if defined __GNUC__
        return __builtin_parity(n);
#elif defined _MSC_VER
        return __popcnt(n) & 1;
#elif
        n ^= n >> 1;
        n ^= n >> 2;
        n = (n & 0x11111111) * 0x11111111;
        return (n >> 28) & 1;
#endif
    }

    inline unsigned int parity64(uint64_t n) noexcept
    {
#if defined __GNUC__
        return __builtin_parityll(n);
#elif defined _MSC_VER
        return __popcnt64(n) & 1;
#elif
        n ^= n >> 1;
        n ^= n >> 2;
        n = (n & 0x1111111111111111) * 0x1111111111111111;
        return (n >> 60) & 1;
#endif
    }

    template <typename I, bool B = 32 < std::numeric_limits<I>::digits>
    struct _BitFuncImpl
    {
        inline static unsigned int bsf(I n) noexcept { return bsf64(n); }
        inline static unsigned int bsr(I n) noexcept { return bsr64(n); }
        inline static unsigned int popcnt(I n) noexcept { return popcnt64(n); }
        inline static unsigned int parity(I n) noexcept { return parity64(n); }
    };

    template <typename I>
    struct _BitFuncImpl<I, false>
    {
        inline static unsigned int bsf(I n) noexcept { return bsf32(n); }
        inline static unsigned int bsr(I n) noexcept { return bsr32(n); }
        inline static unsigned int popcnt(I n) noexcept { return popcnt32(n); }
        inline static unsigned int parity(I n) noexcept { return parity32(n); }
    };

    template <typename I>
    inline unsigned int bsf(I n) noexcept { return _BitFuncImpl<I>::bsf(n); }
    template <typename I>
    inline unsigned int bsr(I n) noexcept { return _BitFuncImpl<I>::bsr(n); }
    template <typename I>
    inline unsigned int popcnt(I n) noexcept { return _BitFuncImpl<I>::popcnt(n); }
    template <typename I>
    inline unsigned int parity(I n) noexcept { return _BitFuncImpl<I>::parity(n); }
}

template <typename E>
class Network
{
public:
    using edge_type = E;
    using size_type = unsigned;

private:
    size_type n, m;
    size_type *pos;
    std::unique_ptr<edge_type[]> edges;

public:
    Network(std::unique_ptr<edge_type[]> edges, std::unique_ptr<size_type[]> spos, size_type n, size_type m)
        : n(n), m(m), pos(spos.release() + 1), edges(std::move(edges))
    {
        pos[-1] = 1;
    }

    Network(const Network &other) : n(other.n), m(other.m), pos(other.pos), edges(new edge_type[m])
    {
        std::copy_n(other.edges.get(), m, edges.get());
        ++pos[-1];
    }

    ~Network()
    {
        if (--pos[-1] == 0)
            delete[] (pos - 1);
    }

    inline size_type order() const noexcept { return n; }
    inline size_type size() const noexcept { return m; }
    inline const size_type *raw_pos() const noexcept { return pos; }
    inline const edge_type *raw_edges() const noexcept { return edges.get(); }
    inline edge_type *raw_edges() noexcept { return edges.get(); }
};

template <typename F = int, typename C = int>
class MCFN
{
public:
    using size_type = unsigned;

private:
    struct RawEdge
    {
        size_type from, to;
        F cap;
        C cost;
    };

    struct Edge
    {
    private:
        friend class MCFN;
        size_type _rev, _to;
        F _cap;
        C _cost;
        Edge(size_type rev, size_type to, F cap, C cost) : _rev(rev), _to(to), _cap(cap), _cost(cost) {}

    public:
        using flow_type = F;
        using cost_type = C;
        Edge() = default;
        inline size_type rev() const noexcept { return _rev; }
        inline size_type to() const noexcept { return _to; }
        inline flow_type residual() const noexcept { return _cap; }
        inline bool full() const noexcept { return _cap == 0; }
        inline void push(flow_type d) noexcept { _cap -= d; }
        inline cost_type cost() const noexcept { return _cost; }
    };

    std::vector<RawEdge> edges;
    std::vector<size_type> deg;

public:
    MCFN() noexcept = default;

    MCFN(size_type n) : deg(n, 0) {}

    void reserve(size_type n, size_type m)
    {
        edges.reserve(m);
        deg.reserve(n);
    }

    inline size_type add_vertex()
    {
        const size_type ans = deg.size();
        deg.push_back(0);
        return ans;
    }

    inline void add_edge(size_type from, size_type to, F cap, C cost)
    {
        if (cap <= 0)
            return;
        edges.emplace_back(RawEdge{from, to, cap, cost});
        ++deg[from];
        ++deg[to];
    }

    Network<Edge> prepare() const
    {
        using size_type = typename Network<Edge>::size_type;
        const size_type n = deg.size(), m = edges.size();
        std::unique_ptr<Edge[]> sorted_edges(new Edge[2 * m]);
        std::unique_ptr<size_type[]> spos(new size_type[n + 2]);
        const auto pos = spos.get() + 1;
        *std::partial_sum(deg.begin(), deg.end(), pos) = 2 * m;
        for (size_type i = m; i-- > 0;)
        {
            const RawEdge e = edges[i];
            const size_type u = e.from, v = e.to;
            const size_type rp = --pos[v], p = --pos[u];
            sorted_edges[p] = Edge(rp, v, e.cap, e.cost);
            sorted_edges[rp] = Edge(p, u, 0, -e.cost);
        }
        return Network<Edge>(std::move(sorted_edges), std::move(spos), n, 2 * m);
    }
};
template <typename F = int, typename C = int, typename G>
auto ssp(G &&g, std::size_t s, std::size_t t, bool nneg = false)
    -> std::pair<
        typename std::common_type<F, typename std::remove_reference<G>::type::edge_type::flow_type>::type,
        typename std::common_type<C, typename std::remove_reference<G>::type::edge_type::cost_type>::type>
{
    using graph_type = typename std::remove_reference<G>::type;
    using size_type = typename graph_type::size_type;
    using edge_type = typename graph_type::edge_type;
    using flow_type = typename std::common_type<F, typename edge_type::flow_type>::type;
    using cost_type = typename std::common_type<C, typename edge_type::cost_type>::type;
    static constexpr size_type BIN_LEN = std::numeric_limits<cost_type>::digits;
    static constexpr cost_type INF = std::numeric_limits<cost_type>::max();
    struct ShortestPath
    {
        size_type pre;
        cost_type pot, dis;
    };
    struct ListNode
    {
        size_type prev, next;
    };
    const size_type n = g.order(), m = g.size();
    const bool use_heap = m / n <= n / std::min<size_type>(3 * details::bsr(n + 7) + 15, 64);
    const auto edges = g.raw_edges();
    const auto pos = g.raw_pos();
    std::vector<ShortestPath> sp(n);
    std::vector<bool> vis;
    const auto init = [&]
    {
        vis.assign(n, false);
        std::vector<size_type> q(n);
        size_type l = 0, r = 1;
        for (auto &e : sp)
            e.pot = INF;
        sp[s] = {0, 0};
        vis[s] = true;
        q[0] = s;
        while (l != r)
        {
            const size_type u = q[l];
            l = l + 1 != n ? l + 1 : 0;
            vis[u] = false;
            const size_type pu = sp[u].pre;
            const cost_type du = sp[u].pot;
            const auto start_edge = edges + pos[u];
            const auto end_edge = edges + pos[u + 1];
            for (auto i = start_edge; i != end_edge; ++i)
            {
                const edge_type e = *i;
                if (e.full())
                    continue;
                const size_type v = e.to();
                const cost_type dv = sp[v].pot;
                const cost_type ndv = du + e.cost();
                if (ndv < dv)
                {
                    sp[v].pre = pu + 1;
                    sp[v].pot = ndv;
                    if (sp[v].pre >= n)
                        throw std::invalid_argument("graph contains negative cycles.");
                    if (!vis[v])
                    {
                        q[r] = v;
                        vis[v] = true;
                        r = r + 1 != n ? r + 1 : 0;
                    }
                }
            }
        }
    };
    if (!nneg)
        init();
    const cost_type pt = sp[t].pot;
    flow_type flow = 0;
    cost_type cost = 0;
    const auto augment = [&]
    {
        flow_type f = std::numeric_limits<flow_type>::max();
        for (size_type i = t; i != s;)
        {
            const edge_type e = edges[sp[i].pre];
            const flow_type r = edges[e.rev()].residual();
            if (r < f)
                f = r;
            i = e.to();
        }
        for (size_type i = t; i != s;)
        {
            auto &e = edges[sp[i].pre];
            edges[e.rev()].push(f);
            e.push(-f);
            i = e.to();
        }
        flow += f;
        const cost_type dt = sp[t].dis;
        for (auto &e : sp)
            if (e.dis < dt)
                e.pot -= dt - e.dis;
        cost += cost_type(f) * (pt - sp[s].pot);
    };
    const auto flow_with_heap = [&]
    {
        std::vector<ListNode> list(n + BIN_LEN + 1);
        const auto dijkstra_with_heap = [&]
        {
            const auto radix_distance = [](cost_type lhs, cost_type rhs)
            {
                return lhs != rhs ? details::bsr(lhs ^ rhs) + 1 : 0;
            };
            const auto buk = list.data() + n;
            const auto insert_list = [&](size_type idx, size_type v)
            {
                const size_type rear = buk[idx].prev;
                list[rear].next = v;
                list[v].prev = rear;
                buk[idx].prev = v;
                list[v].next = idx + n;
            };
            cost_type top = 0;
            for (size_type i = 0; i <= n + BIN_LEN; ++i)
                list[i] = {i, i};
            list[s] = {n, n};
            buk[0] = {size_type(s), size_type(s)};
            for (auto &e : sp)
                e.dis = INF;
            sp[s].dis = 0;
            while (true)
            {
                size_type u = buk[0].next;
                if (u == n)
                {
                    size_type idx = 1;
                    for (; idx <= BIN_LEN; ++idx)
                        if (buk[idx].next < n)
                            break;
                    if (idx > BIN_LEN)
                        break;
                    const size_type head = buk[idx].next;
                    top = sp[head].dis;
                    for (size_type i = head; (i = list[i].next) < n;)
                        if (sp[i].dis < top)
                            top = sp[i].dis;
                    for (size_type i = head; i < n;)
                    {
                        const size_type j = list[i].next;
                        insert_list(radix_distance(top, sp[i].dis), i);
                        i = j;
                    }
                    buk[idx] = {idx + n, idx + n};
                    u = buk[0].next;
                }
                if (u == size_type(t))
                    return true;
                const size_type next = list[u].next;
                list[next].prev = n;
                buk[0].next = next;
                const cost_type pu = sp[u].pot;
                const cost_type du = sp[u].dis;
                const auto start_edge = edges + pos[u];
                const auto end_edge = edges + pos[u + 1];
                for (auto i = start_edge; i != end_edge; ++i)
                {
                    const edge_type e = *i;
                    if (e.full())
                        continue;
                    const size_type v = e.to();
                    const cost_type pv = sp[v].pot;
                    const cost_type dv = sp[v].dis;
                    const cost_type ndv = e.cost() + pu - pv + du;
                    if (ndv < dv)
                    {
                        const size_type new_idx = radix_distance(top, ndv);
                        if (new_idx != radix_distance(top, dv))
                        {
                            const size_type prev = list[v].prev;
                            const size_type next = list[v].next;
                            list[prev].next = next;
                            list[next].prev = prev;
                            insert_list(new_idx, v);
                        }
                        sp[v].dis = ndv;
                        sp[v].pre = e.rev();
                    }
                }
            }
            return false;
        };
        while (dijkstra_with_heap())
            augment();
    };
    const auto flow_without_heap = [&]
    {
        std::vector<size_type> min_buk;
        const auto dijkstra_without_heap = [&]
        {
            vis.assign(n, false);
            min_buk = {size_type(s)};
            for (auto &e : sp)
                e.dis = INF;
            sp[s].dis = 0;
            while (true)
            {
                size_type u;
                cost_type du;
                if (!min_buk.empty())
                {
                    u = min_buk.back();
                    min_buk.pop_back();
                    if (vis[u])
                        continue;
                    du = sp[u].dis;
                }
                else
                {
                    du = INF;
                    for (size_type i = 0; i < n; ++i)
                        if (!vis[i] && sp[i].dis < du)
                            du = sp[u = i].dis;
                    if (du == INF)
                        break;
                }
                if (u == size_type(t))
                    return true;
                vis[u] = true;
                const cost_type pu = sp[u].pot;
                const auto start_edge = edges + pos[u];
                const auto end_edge = edges + pos[u + 1];
                for (auto i = start_edge; i != end_edge; ++i)
                {
                    const edge_type e = *i;
                    if (e.full())
                        continue;
                    const size_type v = e.to();
                    const cost_type pv = sp[v].pot;
                    const cost_type dv = sp[v].dis;
                    const cost_type ndv = e.cost() + pu - pv + du;
                    if (ndv < dv)
                    {
                        sp[v].dis = ndv;
                        sp[v].pre = e.rev();
                        if (ndv == du)
                            min_buk.push_back(v);
                    }
                }
            }
            return false;
        };
        while (dijkstra_without_heap())
            augment();
    };
    if (use_heap)
        flow_with_heap();
    else
        flow_without_heap();
    return std::make_pair(flow, cost);
}

const int maxn = 102, maxm = 9;
class Solution
{
    vector<int> g[maxn];
    int n, a[maxn];
    void build(TreeNode *r, int fa)
    {
        ++n;
        a[n] = r->val;
        if (fa)
        {
            g[n].push_back(fa);
            g[fa].push_back(n);
        }
        int _n = n;
        if (r->left)
        {
            build(r->left, _n);
        }
        if (r->right)
        {
            build(r->right, _n);
        }
    }
    int lg[maxn], d[maxn], fa[maxn][maxm];
    void dfs(int u, int f)
    {
        fa[u][0] = f;
        d[u] = d[f] + 1;
        for (int i = 1; i <= lg[d[u]]; ++i)
        {
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        }
        for (auto v : g[u])
        {
            if (v != f)
            {
                dfs(v, u);
            }
        }
    }
    int lca(int u, int v)
    {
        if (d[u] < d[v])
        {
            swap(u, v);
        }
        while (d[u] > d[v])
        {
            u = fa[u][lg[d[u] - d[v]] - 1];
        }
        assert(d[u] == d[v]);
        if (u == v)
        {
            return u;
        }
        for (int k = lg[d[u]] - 1; k >= 0; --k)
        {
            if (fa[u][k] != fa[v][k])
            {
                u = fa[u][k], v = fa[v][k];
            }
        }
        return fa[u][0];
    }
    void init()
    {
        for (int i = 1; i <= n; ++i)
        { // lg[i]=1+floor(log2(i))
            lg[i] = lg[i / 2] + 1;
        }
        dfs(1, 0);
    }
    int dis(int u, int v)
    {
        return d[u] + d[v] - 2 * d[lca(u, v)];
    }

public:
    int distributeCoins(TreeNode *root)
    {
        build(root, 0);
        init();
        MCFN<int, int> mcfn(n + 2);
        const int s = n, t = n + 1;
        for (int u = 1; u <= n; ++u)
        {
            if (a[u] > 1)
            {
                mcfn.add_edge(s, u - 1, a[u] - 1, 0);
                for (int v = 1; v <= n; ++v)
                {
                    if (a[v] == 0)
                    {
                        mcfn.add_edge(u - 1, v - 1, 1, dis(u, v));
                    }
                }
            }
            else if (a[u] == 0)
            {
                mcfn.add_edge(u - 1, t, 1, 0);
            }
        }
        return ssp(mcfn.prepare(), s, t).second;
    }
};
```

题解：

设 $dfs(a)$ 表示以 $a$ 为根节点的子树如果满足每个节点都只有一个金币，需要从父节点拿走多少个金币。若 $dfs(a) > 0$，则需要拿走，否则，自己多出的需要给父节点。无论是何种情况，都需要移动 $|dfs(a)|$ 次。

每个节点从左右子节点转移的金币(正拿走负给予)数额为 $dfs(l)+dfs(r)$，加上自己的 $val_a-1$(自己留一个)，得到的结果是正负就转移给父节点，不断如此往复。

```c++
class Solution {
public:    
    int distributeCoins(TreeNode* root) {
        int move = 0;

        function<int(const TreeNode *)> dfs = [&](const TreeNode *root) -> int {
            int moveleft = 0;
            int moveright = 0;
            if (root == nullptr) {
                return 0;
            }
            if (root->left) {
                moveleft = dfs(root->left);
            }        
            if (root->right) {
                moveright = dfs(root->right);
            }
            move += abs(moveleft) + abs(moveright);
            return moveleft + moveright + root->val - 1;
        };

        dfs(root);
        return move;
    }
};
```

##### lc18\.四数之和

[题目](https://leetcode.cn/problems/4sum/)

可以二分优化一层；注意炸 int。

```c++
class Solution
{
public:
    using ll = long long;
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    ll t = 1LL * target - nums[i] - nums[j] - nums[k];
                    int l = lower_bound(nums.begin() + k + 1, nums.end(), t) - nums.begin();
                    if (l >= n || nums[l] != t)
                    {
                        continue;
                    }
                    ans.insert({nums[i], nums[j], nums[k], nums[l]});
                }
            }
        }
        vector<vector<int>> r;
        for (auto pr : ans)
        {
            r.push_back(pr);
        }
        return r;
    }
};
```

双指针：

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if (nums.size() < 4) {
            return quadruplets;
        }
        sort(nums.begin(), nums.end());
        int length = nums.size();
        for (int i = 0; i < length - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
                break;
            }
            if ((long) nums[i] + nums[length - 3] + nums[length - 2] + nums[length - 1] < target) {
                continue;
            }
            for (int j = i + 1; j < length - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                    break;
                }
                if ((long) nums[i] + nums[j] + nums[length - 2] + nums[length - 1] < target) {
                    continue;
                }
                int left = j + 1, right = length - 1;
                while (left < right) {
                    long sum = (long) nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        left++;
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return quadruplets;
    }
};
```

##### 834\.树中距离之和

[题目](https://leetcode.cn/problems/sum-of-distances-in-tree/)

首先统计每个节点的子树的点数 $c_u$ 和所有儿子到它的距离和 $s_u$。

对根节点，有 $dp_u=s_u$；对其他节点，设父节点为 $f$，则：

- 它的子树的点距离和为 $s_u$ 不变
- 除了子树的其他全体点共有 $n-c_u$ 个，这些点先到 $f$ 点的距离和为 $dp_f-s_u-c_u$，其中 $-s_u-c_u$ 是子树所有点往上走一格的距离和，即从 $dp_f$ 里减去 $u$ 子树的贡献。
- 到 $f$ 点的除了子树的全体点再走一步到达 $u$，共 $n-c_u$ 个，贡献为 $1\times (n-c_u)$。

故转移方程为：
$$
dp_u=s_u+dp_f+n-c_u-s_u-c_u=dp_f+n-2c_u
$$

 ```c++
class Solution
{
    vector<vector<int>> g;
    int n;
    vector<int> s, c, dp;

    int dfs(int u, int f)
    {
        int sum = 0, cnt = 1;
        for (auto v : g[u])
        {
            if (v != f)
            {
                sum += dfs(v, u);
                cnt += c[v];
            }
        }
        c[u] = cnt, s[u] = sum;
        return s[u] + c[u];
    }

    void dfs2(int u, int f)
    {
        dp[u] = s[u];
        if (f != -1)
        {
            dp[u] += dp[f] + n - c[u] - s[u] - c[u];
        }
        for (auto v : g[u])
        {
            if (v != f)
            {
                dfs2(v, u);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        this->n = n;
        s.resize(n), c.resize(n), dp.resize(n), g.resize(n);
        for (auto pr : edges)
        {
            int u = pr[0], v = pr[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        dfs2(0, -1);
        return dp;
    }
};
 ```

##### 415\.字符串相加

[题目](https://leetcode.cn/problems/add-strings/)

python 调库：

```python
import sys
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        sys.set_int_max_str_digits(10010)
        return str(int(num1)+int(num2))
```

C++ 

```c++
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1, j = num2.length() - 1, add = 0;
        string ans = "";
        while (i >= 0 || j >= 0 || add != 0) {
            int x = i >= 0 ? num1[i] - '0' : 0;
            int y = j >= 0 ? num2[j] - '0' : 0;
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i -= 1;
            j -= 1;
        }
        // 计算完以后的答案需要翻转过来
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

##### 1851\.包含每个查询的最小区间

[题目](https://leetcode.cn/problems/minimum-interval-to-include-each-query/)

> 错误解：预处理每个询问，考虑过静态双链表然后不断删，必须开 vector 开静态数组炸空间，但是无法查找首个有效位置，set 维护首个位置会炸常数，vector 维护会 TLE。

预处理，考虑对查询排序，变成增删两种命令，即 l 位置增，r+1 位置删，然后指针扫，维护当前所有区间长度的集合，每次取最小的。

设值域 $m$，区间数 $n$，询问数 $q$，时间复杂度为 $O(m+n\log n+q)$，空间复杂度 $O(m)$。

可以进行空间优化，当且仅当当前值域在询问里才保存，则时间复杂度不变，空间优化为 $O(q)$，优化意义不大故从略。

```c++
class Solution
{
    const int ADD = -1, DEL = 1;
    using pr = pair<int, int>;

public:
    vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
    {
        int vr = -1, m = queries.size();
        auto len = [](const vector<int> &v) -> int
        { return v[1] - v[0] + 1; };
        vector<pr> cmd;
        for (auto p : intervals)
        {
            vr = max(vr, p[1] + 1);
            cmd.push_back({p[0], ADD * len(p)});
            cmd.push_back({p[1] + 1, DEL * len(p)});
        }
        sort(cmd.begin(), cmd.end());
        vector<int> ans(vr), res(m);
        multiset<int> lens;
        lens.insert(1e9);
        for (int i = 0, j = 0, je = cmd.size(); i < vr; ++i)
        {
            ans[i] = 1e9;
            while (j < je && cmd[j].first <= i)
            {
                int le = abs(cmd[j].second);
                if (cmd[j].second < 0)
                {
                    lens.insert(le);
                }
                else
                {
                    lens.erase(lens.find(le));
                }
                ++j;
            }
            ans[i] = min(ans[i], *lens.begin());
            ans[i] = ans[i] == 1e9 ? -1 : ans[i];
        }
        for (int i = 0; i < m; ++i)
        {
            res[i] = ans[queries[i]];
        }
        return res;
    }
};
```

题解：离线，查询按值排序，区间按左端点排序；对每个值，类似地维护区间的优先级队列，按区间长维护合法的每个区间。优化到 $O(n\log n)$

```c++
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> qindex(queries.size());
        iota(qindex.begin(), qindex.end(), 0);
        sort(qindex.begin(), qindex.end(), [&](int i, int j) -> bool {
            return queries[i] < queries[j];
        });
        sort(intervals.begin(), intervals.end(), [](const vector<int> &it1, const vector<int> &it2) -> bool {
            return it1[0] < it2[0];
        });
        priority_queue<vector<int>> pq;
        vector<int> res(queries.size(), -1);
        int i = 0;
        for (auto qi : qindex) {
            while (i < intervals.size() && intervals[i][0] <= queries[qi]) {
                int l = intervals[i][1] - intervals[i][0] + 1;
                pq.push({-l, intervals[i][0], intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top()[2] < queries[qi]) {
                pq.pop();
            }
            if (!pq.empty()) {
                res[qi] = -pq.top()[0];
            }
        }
        return res;
    }
};
```

##### 918\.环形子数组的最大和

[题目](https://leetcode.cn/problems/maximum-sum-circular-subarray/)

前缀和+可删堆。

将环转化成二倍长的链，对前缀和 $s$，即求 $\max_{r=1}^{2n}(s_r-\min_{l=r-n}^{r-1}s_{l-1})$。

扫描 $r$，使用可删堆维护长为 $n$ 的堆，每次当堆元素大于 $n$ 时就删掉一个，注意不一定是删堆顶，所以要用可删堆实现，用 multiset 等也行。

复杂度取堆复杂度，即 $O(n\log n)$。

```c++
struct heap
{
    priority_queue<int, vector<int>, greater<int>> a, b;
    void insert(int x) { a.push(x); }
    void erase(int x) { b.push(x); }
    int top()
    {
        while (!b.empty() && a.top() == b.top())
        {
            a.pop(), b.pop();
        }
        return a.top();
    }
    int pop()
    {
        int t = top();
        a.pop();
        return t;
    }
    int size() { return a.size() - b.size(); }
};
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size(), ans = -1e9;
        vector<int> s(2 * n + 1);
        for (int i = 0; i < 2 * n; ++i)
        {
            s[i + 1] = s[i] + (nums[i % n]);
        }
        heap q = heap();
        q.insert(s[0]);
        for (int r = 1, l = r - n; r <= 2 * n; ++r, ++l)
        {
            if (l > 0)
            {
                q.erase(s[l - 1]);
            }
            int sum = s[r] - q.top();
            ans = max(ans, sum);
            q.insert(s[r]);
        }
        return ans;
    }
};
```

官方优化：使用环转链，对自己的堆，改成单调队列(单调不减)

```c++
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        deque<pair<int, int>> q;
        int pre = nums[0], res = nums[0];
        q.push_back({0, pre});
        for (int i = 1; i < 2 * n; i++) {
            while (!q.empty() && q.front().first < i - n) {
                q.pop_front();
            }
            pre += nums[i % n];
            res = max(res, pre - q.front().second);
            while (!q.empty() && q.back().second >= pre) {
                q.pop_back();
            }
            q.push_back({i, pre});
        }
        return res;
    }
};
```

官方解法：DP

```c++
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftMax(n);
        // 对坐标为 0 处的元素单独处理，避免考虑子数组为空的情况
        leftMax[0] = nums[0];
        int leftSum = nums[0];
        int pre = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i++) { // 不考虑环的朴素最大
            pre = max(pre + nums[i], nums[i]);
            res = max(res, pre);
            leftSum += nums[i];
            leftMax[i] = max(leftMax[i - 1], leftSum);
        }

        // 从右到左枚举后缀，固定后缀，选择最大前缀
        int rightSum = 0;
        for (int i = n - 1; i > 0; i--) {
            rightSum += nums[i];
            res = max(res, rightSum + leftMax[i - 1]);
        }
        return res;
    }
};
```

优化：对第二种情况，即跨过环的，即求全长减去最小和。

```c++
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int preMax = nums[0], maxRes = nums[0];
        int preMin = nums[0], minRes = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            preMax = max(preMax + nums[i], nums[i]);
            maxRes = max(maxRes, preMax);
            preMin = min(preMin + nums[i], nums[i]);
            minRes = min(minRes, preMin);
            sum += nums[i];
        }
        if (maxRes < 0) {
            return maxRes;
        } else {
            return max(maxRes, sum - minRes);
        }
    }
};
```

##### 1499\.满足不等式的最大值

[题目](https://leetcode.cn/problems/max-value-of-equation/)

按需枚举，对每个 $j$，即求 $y_i+y_j+x_j-x_i$，即对范围内的点，求 $y_i-x_i$ 的最大值，无脑维护单调不增队列即可。

```c++
class Solution
{
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k)
    {
        int n = points.size(), ans = -1e9;
        deque<int> q;
        auto val = [&](int i)
        {
            auto pr = points[i];
            return pr[1] - pr[0];
        };
        for (int j = 0; j < n; ++j)
        {
            auto pr = points[j];
            int xj = pr[0], yj = pr[1];
            while (q.size() && points[q.front()][0] < xj - k)
            {
                q.pop_front();
            }
            if (q.size())
            {
                auto pr2 = points[q.front()];
                int xi = pr2[0], yi = pr2[1];
                ans = max(ans, yi + yj + xj - xi);
            }
            while (q.size() && val(j) > val(q.back()))
            {
                q.pop_back();
            }
            q.push_back(j);
        }
        return ans;
    }
};
```

常数比我低的实现：

```c++
class Solution {
public:
    using pii = pair<int, int>;
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = INT_MIN;
        deque<pii> qu;
        for (auto &point : points) {
            int x = point[0], y = point[1];
            while (!qu.empty() && x - qu.front().second > k) {
                qu.pop_front();
            }
            if (!qu.empty()) {
                res = max(res, x + y + qu.front().first);
            }
            while (!qu.empty() && y - x >= qu.back().first) {
                qu.pop_back();
            }
            qu.emplace_back(y - x, x);
        }
        return res;
    }
};
```

也可以用堆。可以不写对顶/可删堆：

```c++
class Solution {
public:
    using pii = pair<int, int>;
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int res = INT_MIN;
        priority_queue<pii, vector<pii>, greater<pii>> heap;
        for (auto &point : points) {
            int x = point[0], y = point[1];
            while (!heap.empty() && x - heap.top().second > k) {
                heap.pop();
            }
            if (!heap.empty()) {
                res = max(res, x + y - heap.top().first);
            }
            heap.emplace(x - y, x);
        }
        return res;
    }
};
```

##### 2050\.并行课程III

[题目](https://leetcode.cn/problems/parallel-courses-iii/)

个人：拓扑排序 DP

```c++
class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<vector<int>> g(n + 1);
        vector<int> dp(n + 1), ru(n + 1);
        for (auto pr : relations)
        {
            int u = pr[0], v = pr[1];
            ++ru[v];
            g[u].push_back(v);
        }
        int ans = 0;
        queue<int> q;
        for (int i = 1; i <= n; ++i)
        {
            if (ru[i] == 0)
            {
                q.push(i);
                dp[i] = time[i - 1];
                ans = max(ans, dp[i]);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (auto v : g[u])
            {
                dp[v] = max(dp[v], time[v - 1] + dp[u]);
                ans = max(ans, dp[v]);
                if (--ru[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        return ans;
    }
};
```

题解：记忆化搜索 DP

```c++
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        int mx = 0;
        vector<vector<int>> prev(n + 1);
        for (auto &relation : relations) {
            int x = relation[0], y = relation[1];
            prev[y].emplace_back(x);
        }
        unordered_map<int, int> memo;
        function<int(int)> dp = [&](int i) -> int {
            if (!memo.count(i)) {
                int cur = 0;
                for (int p : prev[i]) {
                    cur = max(cur, dp(p));
                }
                cur += time[i - 1];
                memo[i] = cur;
            }
            return memo[i];
        };

        for (int i = 1; i <= n; i++) {
            mx = max(mx, dp(i));
        }
        return mx;
    }
};
```

##### 141\.环形链表

[题目](https://leetcode.cn/problems/linked-list-cycle/)

可以哈希表做，略。

个人快慢指针：

```c++
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if(head==nullptr){return false;}//SPJ
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr)
        {
            if (fast == slow)
            {
                return true;
            }
            if (fast->next != nullptr && fast->next->next != nullptr)
            {
                fast = fast->next->next;
                slow = slow->next;
            }
            else
            {
                break;
            }
        }
        return false;
    }
};
```

题解快慢指针：

```c++
class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (slow != fast) {
            if (fast == nullptr || fast->next == nullptr) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};
```

##### 142\.环形链表II

[题目](https://leetcode.cn/problems/linked-list-cycle-ii/)

当然可以哈希表：

```c++
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        set<ListNode *> s;
        for (ListNode *now = head; now != nullptr; now = now->next)
        {
            if (s.find(now) != s.end())
            {
                return now;
            }
            s.insert(now);
        }
        return nullptr;
    }
};
```

快慢指针：

设链表头部到环前的区间有 $a$ 个点(即从头结点走 $a$ 步恰好入环)，环长为 $b+c$ 个点，其中 $b$ 是进入环后继续走了多远到达相遇点。则快指针走过的距离为 $a+n(b+c)+b$，且慢指针走过的距离为 $a+b$，慢指针在相遇前不可能完整走完一圈，由追及问题易知。联立得：
$$
a+n(b+c)+b=2(a+b)
$$
解得 $a=c+(n-1)(b+c)$，也就是说，当慢指针走完残圈距离 $c$ 后再走若干圈，刚好能与从头开始走的等速度指针相遇。

```c++
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
```

##### 143\.重排链表

[题目](https://leetcode.cn/problems/reorder-list/)

暴力：先转线性表，然后暴力改指针(题目要求必须用原地址，所以不能新建一个链表去代替它)

```c++
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};
```

压空间复杂度的做法：

1. 快慢指针法空间 $O(1)$ 找中间结点(奇数时哪边长无所谓)
2. 转置后半部分，具体而言顺序遍历，将每个指向反向并返回最后一个点
3. 归并合并前后部分，类似道理

```c++
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        ListNode* mid = middleNode(head);
        ListNode* l1 = head;
        ListNode* l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    void mergeList(ListNode* l1, ListNode* l2) {
        ListNode* l1_tmp;
        ListNode* l2_tmp;
        while (l1 != nullptr && l2 != nullptr) {
            l1_tmp = l1->next;
            l2_tmp = l2->next;

            l1->next = l2;
            l1 = l1_tmp;

            l2->next = l1;
            l2 = l2_tmp;
        }
    }
};
```

##### 2681\.英雄的力量

[题目](https://leetcode.cn/problems/power-of-heroes/)

排序后为数组 $a$，即求：
$$
\begin{align}
\sum_{i=1}^na_i^3&+\\
a_2^2a_12^{2-1-1}&+\\
a_3^2a_12^{3-1-1}&+a_3^2a_22^{3-2-1}&+\\
\cdots&+\\
a_n^2a_12^{n-1-1}&+a_n^2a_22^{n-2-1}&+\cdots&+a_n^2a_{n-1}2^{n-(n-1)-1}\\
\end{align}
$$
上述计算复杂度为 $O(n^2)$，但是可以递推优化。

考虑 $s_k=a_12^k+a_22^{k-1}+\cdots+a_{k-1}2^0$，

则：$s_{k+1}=a_12^{k+1}+a_22^{k}+\cdots+a_{k-1}2^1+a_k=2s_k+a_k$。

所以优化为 $O(n)$。

```c++
const int mod = 1e9 + 7;
class Solution
{
public:
    int sumOfPower(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size(), s = 0;
        for (auto v : nums)
        {
            ans = (ans + (1LL * v * v % mod * v % mod)) % mod;
        }
        for (int i = 1; i < n; ++i)
        {
            int pw = 1LL * nums[i] * nums[i] % mod;
            s = (s * 2 % mod + nums[i - 1]) % mod;
            ans = (ans + (1LL * s * pw) % mod) % mod;
        }
        return ans;
    }
};
```

题解：排序后设 $dp_i$ 表示以 $a_i$ 结尾全体子序列(而不是子串)的最小值之和，则有：
$$
dp_i=a_i+\sum_{j=0}^{i-1}dp_j
$$
使用前缀和优化枚举、并滚动数组优化，可以 $O(n)$ 时间、$O(1)$ 空间算 $dp$。

则所求为 $\sum_{i=0}^{n-1}a_i^2dp_i$。

```c++
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int dp = 0, preSum = 0; 
        int res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            dp = (nums[i] + preSum) % mod;
            preSum = (preSum + dp) % mod;
            res = (int) ((res + (long long) nums[i] * nums[i] % mod * dp) % mod);
            if (res < 0) {
                res += mod;
            }
        }
        return res;
    }
};
```

##### 822\.翻转卡片游戏

[题目](https://leetcode.cn/problems/card-flipping-game)

值无解当且仅当正反面都是它。

个人：set

```c++
class Solution
{
public:
    int flipgame(vector<int> &fronts, vector<int> &backs)
    {
        set<int> a, db;
        for (auto v : fronts)
        {
            a.insert(v);
        }
        for (auto v : backs)
        {
            a.insert(v);
        }
        for (int i = 0, n = fronts.size(); i < n; ++i)
        {
            if (fronts[i] == backs[i])
            {
                db.insert(fronts[i]);
            }
        }
        for (auto b : a)
        {
            if (db.find(b) == db.end())
            {
                return b;
            }
        }
        return 0;
    }
};
```

std：unset

```c++
class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        int res = 3000, n = fronts.size();
        unordered_set<int> same;
        for (int i = 0; i < n; ++i) {
            if (fronts[i] == backs[i]) {
                same.insert(fronts[i]);
            }
        }
        for (int &x : fronts) { // find min
            if (x < res && same.count(x) == 0) {
                res = x;
            }
        }
        for (int &x : backs) {
            if (x < res && same.count(x) == 0) {
                res = x;
            }
        }
        return res % 3000; //3000%3000=no sol
    }
};
```

##### 21\.合并两个有序链表

[题目]()

签略。递归和迭代：

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        } else if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
```

```c++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};
```



##### 980\.不同路径III

[题目](https://leetcode.cn/problems/unique-paths-iii/)

个人思路：对路径记忆，做 BFS

更优：路径可以状压(地图很小，自己还看错数据范围了) 时空 $O(rc2^{rc})$

```c++
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int si = 0, sj = 0, st = 0;
        unordered_map<int, int> memo;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0 || grid[i][j] == 2) {
                    st |= (1 << (i * c + j));
                } else if (grid[i][j] == 1) {
                    si = i, sj = j;
                }
            }
        }

        function<int(int ,int, int)> dp = [&](int i, int j, int st) -> int {
            if (grid[i][j] == 2) {
                if (st == 0) {
                    return 1;
                }
                return 0;
            }
            int key = ((i * c + j) << (r * c)) + st;
            if (!memo.count(key)) {
                int res = 0;
                vector<array<int, 2>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
                for (auto &[di, dj] : dir) {
                    int ni = i + di, nj = j + dj;
                    if (ni >= 0 && ni < r && nj >= 0 && nj < c && (st & (1 << (ni * c + nj))) > 0) {
                        res += dp(ni, nj, st ^ (1 << (ni * c + nj)));
                    }
                }
                memo[key] = res;
            }
            return memo[key];
        };
        return dp(si, sj, st);
    }
};

```

DFS：时间 $O(4^{rc})$，空间取递归栈

```c++
class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        int si = 0, sj = 0, n = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 0) {
                    n++;
                 } else if (grid[i][j] == 1) {
                    n++;
                    si = i;
                    sj = j;
                 }
            }
        }

        function<int(int, int, int)> dfs = [&](int i, int j, int n) -> int {
            if (grid[i][j] == 2) {
                if (n == 0) {
                    return 1;
                }
                return 0;
            }

            int t = grid[i][j], res = 0;
            grid[i][j] = -1;
            vector<array<int, 2>> dir({{-1, 0}, {1, 0}, {0, -1}, {0, 1}});
            for (auto &[di, dj] : dir) {
                int ni = i + di;
                int nj = j + dj;
                if (ni >= 0 && ni < r && nj >= 0 && nj < c && \
                   (grid[ni][nj] == 0 || grid[ni][nj] == 2)) {
                    res += dfs(ni, nj, n - 1);
                }
            }
            grid[i][j] = t;
            return res;
        };
        return dfs(si, sj, n);
    }
};
```

##### 1749\.任意子数组的绝对值的最大值

[题目](https://leetcode.cn/problems/maximum-absolute-sum-of-any-subarray)

维护历史前缀和里最大最小值，以维护当前最小最大值。

```c++
class Solution
{
public:
    int maxAbsoluteSum(vector<int> &nums)
    {
        int minl = 0, maxl = 0, minans = 2e9, maxans = -2e9, s = 0;
        for (auto v : nums)
        {
            s += v;
            minans = min(minans, s - maxl);
            maxans = max(maxans, s - minl);
            minl = min(minl, s);
            maxl = max(maxl, s);
        }
        return max(-minans, maxans);
    }
};
```

##### 1289\.下降路径最小和II

[题目](https://leetcode.cn/problems/minimum-falling-path-sum-ii/)

无脑DP+前缀和优化，平方复杂度

```c++
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(2, vector<int>(m, 1e9));
        for (int i = 0; i < m; ++i)
        {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; ++i)
        {
            vector<int> minl(m, 1e9), minr(m, 1e9);
            minl[0] = dp[(i - 1) & 1][0];
            for (int j = 1; j < m; ++j)
            {
                minl[j] = min(minl[j - 1], dp[(i - 1) & 1][j]);
            }
            minr[m - 1] = dp[(i - 1) & 1][m - 1];
            for (int j = m - 2; j >= 0; --j)
            {
                minr[j] = min(minr[j + 1], dp[(i - 1) & 1][j]);
            }
            for (int j = 0; j < m; ++j)
            {
                int now = 1e9;
                if (j - 1 >= 0)
                {
                    now = min(now, minl[j - 1]);
                }
                if (j + 1 < m)
                {
                    now = min(now, minr[j + 1]);
                }
                dp[i & 1][j] = now + grid[i][j];
            }
        }
        int ans = 1e9;
        for (int i = 0; i < m; ++i)
        {
            ans = min(ans, dp[(n - 1) & 1][i]);
        }
        return ans;
    }
};
```

常数优化：思路2，找出最小值和次小值，当前是最小用次小，否则最小

```c++
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int first_min_sum = 0;
        int second_min_sum = 0;
        int first_min_index = -1;
        
        for (int i = 0; i < n; i++) {
            int cur_first_min_sum = INT_MAX;
            int cur_second_min_sum = INT_MAX;
            int cur_first_min_index = -1;
            
            for (int j = 0; j < n; j++) {
                int cur_sum = (j != first_min_index ? first_min_sum : second_min_sum) + grid[i][j];
                if (cur_sum < cur_first_min_sum) {
                    cur_second_min_sum = cur_first_min_sum;
                    cur_first_min_sum = cur_sum;
                    cur_first_min_index = j;
                } else if (cur_sum < cur_second_min_sum) {
                    cur_second_min_sum = cur_sum;
                }
            }
            first_min_sum = cur_first_min_sum;
            second_min_sum = cur_second_min_sum;
            first_min_index = cur_first_min_index;
        }
        return first_min_sum;
    }
};
```

##### 88\.合并两个有序数组

[题目](https://leetcode.cn/problems/merge-sorted-array)

普通双指针，需要额外空间：

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            } else if (p2 == n) {
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};
```

逆向双指针，从大到小，设初始指针 $p_1=m-1,p_2=n-1$，移动到左数组 $t=m+n-1$，显然，对 $p_1,p_2$，可以算出左右输出已经处理完的元素数目分别为 $m-p_1-1$ 和 $n-p_2-1$，即 tail 移动了 $m+n-p_1-p_2-2$ 次，当前左数组共有 $n+m$ 长度，其中 $n+m-p_1-1$ 个位置可用，可用位置与移动位置作差，可知 $t$ 永远不可能超过 $p_1$。

```c++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if (p1 == -1) {
                cur = nums2[p2--];
            } else if (p2 == -1) {
                cur = nums1[p1--];
            } else if (nums1[p1] > nums2[p2]) {
                cur = nums1[p1--];
            } else {
                cur = nums2[p2--];
            }
            nums1[tail--] = cur;
        }
    }
};
```

##### 833\.字符串中的查找与替换

[题目](https://leetcode.cn/problems/find-and-replace-in-string)

模拟：

- 按 indices 重排序操作，复杂度 $O(m\log m)$
- 双指针(原串, 操作数组)，如果匹配成功(最坏共匹配 $O(ml)$ 字符)，答案增加替换后的串，原串跳一个串长；否则，答案增加一个字符，原串跳一个字符，整体 $O(n+ml)$，考虑全换最坏空间 $O(ml)$

```c++
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size(), m = indices.size();

        vector<int> ops(m);
        iota(ops.begin(), ops.end(), 0);
        sort(ops.begin(), ops.end(), [&](int i, int j) { return indices[i] < indices[j]; });

        string ans;
        int pt = 0;
        for (int i = 0; i < n;) {
            while (pt < m && indices[ops[pt]] < i) {
                ++pt;
            }
            bool succeed = false;
            while (pt < m && indices[ops[pt]] == i) {
                if (s.substr(i, sources[ops[pt]].size()) == sources[ops[pt]]) {
                    succeed = true;
                    break;
                }
                ++pt;
            }
            if (succeed) {
                ans += targets[ops[pt]];
                i += sources[ops[pt]].size();
            }
            else {
                ans += s[i];
                ++i;
            }
        }
        return ans;
    }
};

```

方案二：哈希表代替排序，看看每个 indices 是否有操作，有就做，复杂度优掉排序的

```c++
class Solution {
public:
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
        int n = s.size(), m = indices.size();

        unordered_map<int, vector<int>> ops;
        for (int i = 0; i < m; ++i) {
            ops[indices[i]].push_back(i);
        }

        string ans;
        for (int i = 0; i < n;) {
            bool succeed = false;
            if (ops.count(i)) {
                for (int pt: ops[i]) {
                    if (s.substr(i, sources[pt].size()) == sources[pt]) {
                        succeed = true;
                        ans += targets[pt];
                        i += sources[pt].size();
                        break;
                    }
                }
            }
            if (!succeed) {
                ans += s[i];
                ++i;
            }
        }
        return ans;
    }
};
```

##### 1444\.切披萨的方案数

[题目](https://leetcode.cn/problems/number-of-ways-of-cutting-a-pizza)

设 $dp_{k,r,c}$ 表示已经切了 $k$ 刀，最后一个披萨左上角为 $(r,c)$ 的方案数，答案为 $\sum_{r=1}^n\sum_{c=1}^mdp_{k-1,r,c}$。

记二维前缀和 $s_{i,j}$ 表示苹果的数量，则可以在 $O(nm)$ 预处理后 $O(1)$ 计算一个矩形区域是否有苹果，记 $has(x_1,x_2,y_1,y_2)$ 表示矩形第 $[x_1,x_2]$ 行和第 $[y_1,y_2]$ 列子阵是否存在至少一个苹果。

转移方程为：
$$
dp_{k,x_2,y_2}=\sum_{x_1=x_2\ or\ y_1=y_2} dp_{k-1,x_1,y_1}\\s.t.\ has(x_2,n,y_2,m)\ and\ has(x_1,x_3,y_1,y_3)
$$
其中将 $(x_1,y_1)$ 为左上角的子阵一刀切开为新旧两个子阵，使得新子阵的左上角为 $(x_2,y_2)$，原子阵的右下角为 $(x_3,y_3)$(可以分类讨论求得)。

即对每个 $(x_2,y_2)$，枚举所有上一刀能切成它的状态。因此时间复杂度为 $O(knm(n+m))=O(kn^3)$。空间复杂度为 $O(knm)$，可以压成 $O(nm)$，这里懒得压。

参考代码：

```c++
class Solution
{
public:
    int ways(vector<string> &pizza, int k)
    {
        int n = pizza.size(), m = pizza[0].size();
        vector<vector<int>> s(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (pizza[i - 1][j - 1] == 'A');
            }
        }
        auto has = [&](int x1, int x2, int y1, int y2)
        {
            return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1] > 0;
        };

        const int inpos = 0, mod = 1e9 + 7;
        // dp[k][r][c] 切了k刀,最后一块左上角为(r,c)方案数
        vector<vector<vector<int>>> dp(k, vector<vector<int>>(n + 1, vector<int>(m + 1, inpos)));
        dp[0][1][1] = has(1, n, 1, m);
        auto f = [&](int h, int x1, int x2, int y1, int y2)
        {
            if (!has(x2, n, y2, m))
            {
                return;
            }
            if (dp[h - 1][x1][y1] == inpos)
            {
                return;
            }
            int x3, y3;
            if (x1 == x2)
            {
                x3 = n, y3 = y2 - 1;
            }
            else
            {
                x3 = x2 - 1, y3 = m;
            }
            if (!has(x1, x3, y1, y3))
            {
                return;
            }
            dp[h][x2][y2] += dp[h - 1][x1][y1];
            dp[h][x2][y2] %= mod;
        };
        for (int h = 1; h <= k - 1; ++h)
        {
            for (int x2 = 1; x2 <= n; ++x2)
            {
                for (int y2 = 1; y2 <= m; ++y2)
                {
                    for (int x1 = x2, y1 = 1; y1 < y2; ++y1)
                    {
                        f(h, x1, x2, y1, y2);
                    }
                    for (int x1 = 1, y1 = y2; x1 < x2; ++x1)
                    {
                        f(h, x1, x2, y1, y2);
                    }
                }
            }
        }

        int ans = 0;
        for (int x = 1; x <= n; ++x)
        {
            for (int y = 1; y <= m; ++y)
            {
                ans += dp[k - 1][x][y];
                ans %= mod;
            }
        }
        return ans;
    }
};
```



题解常数优化+实现简化：

1. 优化前缀和判定，如果 $(x_1,x_3,y_1,y_3)$ 有苹果，意味着 $s_{x_2,y_2} > s_{x_1,y_1}$。
2. 优化答案累积，在最后再切一刀，切成 $dp_{k,r,c}$，最后不用求和

```c++
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int m = pizza.size(), n = pizza[0].size(), mod = 1e9 + 7;
        vector<vector<int>> apples(m + 1, vector<int>(n + 1));
        vector<vector<vector<int>>> dp(k + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));

        // 预处理
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                apples[i][j] = apples[i][j + 1] + apples[i + 1][j] - apples[i + 1][j + 1] + (pizza[i][j] == 'A');
                dp[1][i][j] = apples[i][j] > 0;
            }
        }

        for (int ki = 2; ki <= k; ki++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    // 水平方向切
                    for (int i2 = i + 1; i2 < m; i2++) {
                        if (apples[i][j] > apples[i2][j]) {
                            dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i2][j]) % mod;
                        }
                    }
                    // 垂直方向切
                    for (int j2 = j + 1; j2 < n; j2++) {
                        if (apples[i][j] > apples[i][j2]) {
                            dp[ki][i][j] = (dp[ki][i][j] + dp[ki - 1][i][j2]) % mod;
                        }
                    }
                }
            }
        }
        return dp[k][0][0];
    }
};
```

##### 1388\.3n块披萨

[题目](https://leetcode.cn/problems/pizza-with-3n-slices/)

不能区间 DP，无法从一个小区间递推出一个大区间。

考虑是链时，设 $dp_{i,j}$ 表示从前 $i$ 个披萨选择了 $j$ 块，答案为 $dp_{n,\frac n3}$。初始状态：

- $dp_{?,0}=0$
- $dp_{0,1}=a_0$ (下标从 $0$ 算)
- $dp_{1,1}=\max(a_0,a_1)$ 

转移：$dp_{i,j}=\max(dp_{i-1,j},dp_{i-2,j-1}+a_i)$，即当前位置要么选要么不选。注意到最后答案是 $n,\frac n3$ 状态，所以隔一个选即可。一定要隔至少一个。

上述转移是 $O(n^2)$ 的，无需优化，直接搞即可。

考虑不是链，即有约束条件：不能同时选第一个、最后一个，所以对原问题求两次：删掉第一个数求 DP，删掉最后一个数求 DP。

```c++
class Solution {
public:
    int calculate(const vector<int>& slices) {
        int N = slices.size(), n = (N + 1) / 3;
        vector<vector<int>> dp(N, vector<int>(n + 1, INT_MIN));
        dp[0][0] = 0;
        dp[0][1] = slices[0];
        dp[1][0] = 0;
        dp[1][1] = max(slices[0], slices[1]);
        for (int i = 2; i < N; i++) {
            dp[i][0] = 0;
            for (int j = 1; j <= n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i]);
            }
        }
        return dp[N - 1][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        vector<int> v1(slices.begin() + 1, slices.end());
        vector<int> v2(slices.begin(), slices.end() - 1);
        int ans1 = calculate(v1);
        int ans2 = calculate(v2);
        return max(ans1, ans2);
    }
};
```



洛谷 P1792 种树 [题目](https://www.luogu.com.cn/problem/P1792)

可以推知，如果选取的序号不相邻，总能找到一种操作方式。具体而言：对每个披萨，先选择它右边的披萨，然后每次总能找到一个有左边空闲的披萨，三个三个地删掉，直到删完。这也是上面解法合理性的证明。

所以原题转化为选取 $\frac n3$ 个不相邻元素的最大值。

贪心：每次选最大的，但显然样例就不行了，所以需要反悔。所以每次选完标记一下反悔的余地。具体而言，选择 $a_i$ 后，删掉 $a_{i-1},a_i,a_{i+1}$，然后再原本位置添加 $-a_{i}+a_{i-1}+a_{i+1}$，再次选择新节点相当于反悔 $a_i$ 然后同时选择 $a_{i-1},a_{i+1}$。

即相当于删掉左右两点，自己点权修改，或者删三次插一次。使用静态双向链表+堆即可。

```c++
#include <bits/stdc++.h>
using namespace std;
vector<int> a; // used in struct, must global
class Solution
{
public:
    int solve(const vector<int> &slices, int k)
    {
        int n = slices.size();
        vector<int> l(n, 0), r(n, 0);
        a = slices;
        for (int i = 0; i < n; ++i)
        {
            l[i] = (i - 1 + n) % n;
            r[i] = (i + 1) % n;
        }
        auto remove = [&](int i)
        {
            r[l[i]] = r[i], l[r[i]] = l[i];
        };
        vector<bool> alive(n, true);
        struct cmp
        {
            bool operator()(int l, int r)
            {
                return a[l] < a[r];
            }
        };
        priority_queue<int, vector<int>, cmp> q;
        for (int i = 0; i < n; ++i)
        {
            q.push(i);
        }
        int ans = 0;
        for (int i = 0; i < k;)
        {
            int x = q.top();
            q.pop();
            if (!alive[x])
            {
                continue;
            }
            ++i;
            ans += a[x];
            alive[l[x]] = alive[r[x]] = false;
            a[x] = a[l[x]] + a[r[x]] - a[x];
            q.push(x);
            remove(l[x]), remove(r[x]);
        }
        return ans;
    }
    int maxSizeSlices(const vector<int> &slices)
    {
        return solve(slices, slices.size() / 3);
    }
};
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n < m * 2)
    {
        cout << "Error!";
        return 0;
    }
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    Solution s;
    cout << s.solve(a, m);
    return 0;
}
```

##### 2337\.移动片段得到字符串

[题目](https://leetcode.cn/problems/move-pieces-to-obtain-a-string/)

有解必须同时满足的充要条件：

1. 去除所有 `_` 后两字符串 $s',t'$ 相等。显然。
2. 若，$s_i=L$，这个 $L$ 在 $t$ 必须不能更右；同理若为 $R$，不能更左

```c++
class Solution
{
    // vector<int> a, b;
public:
    bool sameRelative(string s, string t)
    {
        int n = s.size(), i = 0, j = 0;
        for (;;)
        {
            for (; i < n && s[i] == '_'; ++i)
                ;
            if (i == n)
                break;
            for (; j < n && t[j] == '_'; ++j)
                ;
            if (j == n || s[i] != t[j])
                return false;
            if (s[i] == 'L' && i < j)
                return false;
            if (s[i] == 'R' && i > j)
                return false;
            ++i, ++j;
        }
        for (; j < n && t[j] == '_'; ++j)
            ;
        return j == n;
    }
    bool canChange(string s, string t) {return sameRelative(s, t);}
};
```

##### 849\.到最近的人的最大距离

[题目]()

我的做法时空 On，找 1：

```c++
class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int n = seats.size();
        vector<int> r(n, 1e9);
        for (int i = n - 1, last = 1e9; i >= 0; --i)
        {
            r[i] = last;
            if (seats[i])
            {
                last = i;
            }
        }
        int ans = 0;
        for (int i = 0, l, last = -1e9; i < n; ++i)
        {
            l = last;
            if (seats[i])
            {
                last = i;
            }
            else
            {
                ans = max(ans, min(i - l, r[i] - i));
            }
        }
        return ans;
    }
};
```

更优解空间 O1，找 0，特判首尾段段长，中间段=除2上取整。略。

##### 1782\.统计点对的数目

[题目](https://leetcode.cn/problems/count-pairs-of-nodes/)

设度数为 $d$，有 $c_{i,j}$ 条连接 $(i,j)$ 的边，即求满足下面不等式的 $(i,j)$ 数目：
$$
d_i+d_j-s_{i,j} > q
$$
对每个 $q$，枚举 $d_i$，忽略 $s_{i,j}$，放缩，查看有多少个 $d_i + d_j > q+s_{i,j}\ge q$，即二分看看有多少个  $j$ 满足 $> q-d_i$。

之后，枚举每个 $s_{i,j}$，如果它在 $d_i+d_j > q$ 满足，但是在 $d_i+d_j-s_{i,j} > q$ 不满足，从答案删去。

复杂度 $O(qn\log n+qm)$

```c++
class Solution
{
public:
    vector<int> countPairs(int n, vector<vector<int>> &edges, vector<int> &queries)
    {
        vector<int> d(n + 1, 0);
        map<pair<int, int>, int> c;
        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            ++d[u], ++d[v];
            ++c[make_pair(min(u, v), max(u, v))];
        }
        vector<int> ds = d;
        sort(ds.begin(), ds.end());
        // for(int i=0;i<=n;++i){
        //     cout << ds[i] << " ";
        // }
        // cout << '\n';
        vector<int> res;
        for (auto q : queries)
        {
            int ans = n * (n - 1) / 2;
            vector<int> val(n + 1);
            int dels = 0;
            for (int i = 1; i <= n; ++i)
            {
                int v = q - d[i];
                auto j = upper_bound(ds.begin(), ds.end(), v) - ds.begin();
                if(j>0) --j;
                // ans -= j; // invalid (0,j]
                dels += j;
                auto ip = lower_bound(ds.begin(), ds.end(), d[i]) - ds.begin();
                // cout << dels << '\n';
                // ans += ip <= j; // i!=i
                dels -= ip <= j;
                // cout << i << " " << j << " " << ip << " " << v << " " << dels << '\n';
                val[i] = j + 1; // valid [j+1,n]
            }
            ans -= dels / 2; // i > j, i < j
            for (auto pr : c)
            {
                int u = pr.first.first, v = pr.first.second, s = pr.second;
                // not included above
                ans -= (d[u] + d[v] - s) <= q && d[u] + d[v] > q;
                // cout << "Del " << u << " " << v << "\n";
            }
            res.push_back(ans);
            // cout << "\n";
        }
        return res;
    }
};
```

更优实现：

1. 按照排序后的 $d$ 的顺序枚举 $d$，二分时能去重，不用手动除二判和 $i=j$
2. unmap 优化，不用自定义结构体做二维合一即可

```c++
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n);
        unordered_map<int, int> cnt;
        for (auto edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            if (x > y) {
                swap(x, y);
            }
            degree[x]++;
            degree[y]++;
            cnt[x * n + y]++;
        }

        vector<int> arr = degree;
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for (int bound : queries) {
            int total = 0;
            for (int i = 0; i < n; i++) {
                int j = upper_bound(arr.begin() + i + 1, arr.end(), bound - arr[i]) - arr.begin();
                total += n - j;
            }
            for (auto &[val, freq] : cnt) {
                int x = val / n;
                int y = val % n;
                if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
                    total--;
                }
            }
            ans.emplace_back(total);
        }

        return ans;
    }
};
```

优化：双指针

- 因为 $d_i$ 递增枚举，所以满足的区间也是单调变化的，可以不用二分搜索，直接指针维护即可

```c++
class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n);
        unordered_map<int, int> cnt;
        for (auto edge : edges) {
            int x = edge[0] - 1, y = edge[1] - 1;
            if (x > y) {
                swap(x, y);
            }
            degree[x]++;
            degree[y]++;
            cnt[x * n + y]++;
        }

        vector<int> arr = degree;
        vector<int> ans;
        sort(arr.begin(), arr.end());
        for (int bound : queries) {
            int total = 0;
            for (int i = 0, j = n - 1; i < n; i++) {
                while (j > i && arr[i] + arr[j] > bound) {
                    j--;
                }
                total += n - 1 - max(i, j);
            }
            for (auto &[val, freq] : cnt) {
                int x = val / n;
                int y = val % n;
                if (degree[x] + degree[y] > bound && degree[x] + degree[y] - freq <= bound) {
                    total--;
                }
            }
            ans.emplace_back(total);
        }

        return ans;
    }
};
```

##### 225\.汇总区间

[题目](https://leetcode.cn/problems/summary-ranges/description/)

我的代码：

```c++
class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        if (nums.size() == 0)
            return {};
        sort(nums.begin(), nums.end());
        vector<string> ans;
        int n = nums.size();
        for (int i = 0, l = nums[0], r; i < n; ++i)
        {
            r = nums[i];
            if (i + 1 == n || nums[i + 1] != r + 1)
            {
                if (l == r)
                {
                    ans.push_back(to_string(l));
                }
                else
                {
                    ans.push_back("" + to_string(l) + "->" + to_string(r));
                }
                if (i + 1 != n)
                {
                    l = nums[i + 1];
                }
            }
        }
        return ans;
    }
};
```

更优雅实现：

- `move(x)` 将 `x` 剪切返回，执行后 `x` 为空，返回值为 `x` 的值。

```c++
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int i = 0;
        int n = nums.size();
        while (i < n) {
            int low = i;
            i++;
            while (i < n && nums[i] == nums[i - 1] + 1) {
                i++;
            }
            int high = i - 1;
            string temp = to_string(nums[low]);
            if (low < high) {
                temp.append("->");
                temp.append(to_string(nums[high]));
            }
            ret.push_back(move(temp));
        }
        return ret;
    }
};
```

##### 56\.合并区间

[题目](https://leetcode.cn/problems/merge-intervals/)

我的实现：

```c++
class Solution
{
public:
    using pr = vector<int>;
    vector<vector<int>> merge(vector<vector<int>> &a)
    {
        sort(a.begin(), a.end(), [](pr l, pr r)
             { return l[0] == r[0] ? l[1] < r[1] : l[0] < r[0]; });
        vector<pr> ans;
        int n = a.size();
        for (int l = 0, r; l < n;)
        {
            pr no = a[l];
            for (r = l + 1; r < n; ++r)
            {
                pr nw = a[r];
                if (nw[0] > no[1])
                {
                    break;
                }
                no = {no[0], max(no[1], nw[1])};
            }
            ans.push_back(no);
            l = r;
        }
        return ans;
    }
};
```

更优雅实现：

- 不需要自定义比较依据，默认的依据就很对
- 每次用上一个答案区间与当前区间对比即可

```c++
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};
```

##### 57\.插入区间

[题目](https://leetcode.cn/problems/insert-interval)

暴力：直接插入、排序、按上一道题处理。

我的小模拟，写的很烂，wa 了不少：

```c++
class Solution
{
    using pr = vector<int>;

public:
    vector<vector<int>> insert(vector<vector<int>> &a, vector<int> &b)
    {
        vector<pr> ans;
        //ans.push_back({-10,-10});
        int n = a.size(), merged = false;
        if(n&&b[1]<=a[0][0]){
            ans.push_back(b);
            merged = true;
        }
        for (int i = 0; i < n; ++i)
        {
            ans.push_back(a[i]);
            pr &c = ans.back();
            if (c[1] >= b[0] && b[1] >= c[0])
            {
                //cout << b[0] << " " << b[1] << " "  << c[0] << " " << c[1] << '\n';
                c[0] = min(c[0], b[0]);
                c[1] = max(c[1], b[1]);
                merged = true;
            }
            if (ans.size() >= 2)
            {
                pr &d = ans[ans.size() - 2];
                //cout << "? " << d[0] << " " << d[1] << " "  << c[0] << " " << c[1] << '\n';
                if (d[1] >= c[0])
                {
                    //cout << "drop " << c[0] << " " << c[1] << '\n';
                    d[0] = min(d[0], c[0]);
                    d[1] = max(d[1], c[1]);
                    ans.pop_back();
                }
                else if(!merged && d[1] < b[0] && b[1] < c[0]) {
                    pr cc = c;
                    ans.pop_back();
                    ans.push_back(b);
                    ans.push_back(cc);
                    merged = true;
                }
            }
        }
        //ans.erase(ans.begin());
        if (!merged) {
            ans.push_back(b);
        }
        return ans;
    }
};
```

优雅实现：

```c++
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        vector<vector<int>> ans;
        for (const auto& interval: intervals) {
            if (interval[0] > right) {
                // 在插入区间的右侧且无交集
                if (!placed) {
                    ans.push_back({left, right});
                    placed = true;                    
                }
                ans.push_back(interval);
            }
            else if (interval[1] < left) {
                // 在插入区间的左侧且无交集
                ans.push_back(interval);
            }
            else {
                // 与插入区间有交集，计算它们的并集
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }
        if (!placed) {
            ans.push_back({left, right});
        }
        return ans;
    }
};
```

##### 440\.字典序的第k小数字

[题目](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order)

暴力就遍历字典树，理论 $O(k)$。

已知 $i$ 的子节点为 $10i+j(0\le j\le 9)$。当遍历到 $i$ 时，先序往后走 $k-i$ 步即可。设当前字典序第 $i$ 小节点是 $n_i$，如果它有右兄弟，则为 $n_{i+1}$。设 $i$ 为根的子树的节点数为 $f(i)$，则：

- $f(n_i)\le k-i$，直接走右兄弟(或无兄弟回走，但实际不需要)，下一步还需要跳 $k-i-f(n_i)$ 个点
- $f(n_i) >k-i$，走子树，顺序遍历每个直接子节点

求 $f$，可以设子树是满10叉树，每一层最左最右为 $first,last$，然后每下一层都用原本的 $first,last$ 求新的，一直下到 $n$ 所在的层，该层节点数为 $\min(n, last)-first+1$。复杂度为 $O(\log n)$。

在如此遍历时，不需要回走。走 $n_i$ 实际上最坏走 $O(10\log n)$ 次(每层乘以扇出)，故总复杂度为 $O(10\log^2 n)$。

```c++
class Solution {
public:
    int getSteps(int curr, long n) {
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = getSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr = curr*10;
                k--;
            }
        }
        return curr;
    }
};
```

##### 823\.带因子的二叉树

[题目](https://leetcode.cn/problems/binary-trees-with-factors/)

设 $s_i$ 是以第 $i$ 个数为根的子树的方案数，则答案为 $\sum s$。

对每个数 $a_i$，枚举所有能组成它的因子对 $a_j,a_k$ 满足 $a_j\le a_k,a_ja_k=a_i$，则方案数为 $s_i=1+\sum s_js_k(1+[j\neq k])$，即两子不同排列乘二，相同只有一种。

对 $a$ 排序，然后因为 $n$ 小 $a$ 大，直接枚举 $a$ 而不是枚举全体因子，故总复杂度为 $O(n^2)$。用 map 对 j 找 k。

```c++
const int mod = 1e9 + 7;
using ll = long long;
class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &a)
    {
        int n = a.size();
        sort(a.begin(), a.end());
        map<int, int> ai;
        for (int i = 0; i < n; ++i)
        {
            ai[a[i]] = i;
        }
        ll ans = 0;
        vector<ll> s(n, 1); // 以a[i]为根的子树的方案数
        for (int i = 0; i < n; ++i)
        {
            int v = a[i];
            // for (int x = 2; x * x <= v; ++x)
            for (int xi = 0; xi < i; ++xi)
            {
                int x = a[xi];
                if (v % x == 0 && ai.find(v / x) != ai.end() && x <= v / x)
                {
                    int y = v / x;
                    int yi = ai[y];
                    s[i] = (s[i] + (s[xi] * s[yi] % mod * (x == y ? 1 : 2) % mod)) % mod;
                }
            }
            ans = (ans + s[i]) % mod;
        }
        return ans;
    }
};
```

题解：优化使用双指针对 j 找 k：

```c++
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<long long> dp(n);
        long long res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int left = 0, right = i - 1; left <= right; left++) {
                while (right >= left && (long long)arr[left] * arr[right] > arr[i]) {
                    right--;
                }
                if (right >= left && (long long)arr[left] * arr[right] == arr[i]) {
                    if (right != left) {
                        dp[i] = (dp[i] + dp[left] * dp[right] * 2) % mod;
                    } else {
                        dp[i] = (dp[i] + dp[left] * dp[right]) % mod;
                    }
                }
            }
            res = (res + dp[i]) % mod;
        }
        return res;
    }
};
```

##### 446\.等差数列划分 II

[题目](https://leetcode.cn/problems/arithmetic-slices-ii-subsequence)

设 $f_{i,d}$ 表示尾项为 $i$ 公差为 $d$ 的等差数列(项数 $\ge 2$)，枚举倒数第二项 $j$，同公差可以推过去，所以 $f_{j,d}$ 这一系列数列都满足条件，且还有额外的 $n=2$ 的数列 $(j,i)$ 也满足，故 $f_{i,d}\leftarrow f_{j,d}+1$。

一个 $i$ 最多跟 $i-1$ 个前项形成公差，所以 $d$ 离散化后不超过 $n$ 项，故复杂度为 $O(n^2)$。

```c++
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int ans = 0;
        int n = nums.size();
        vector<unordered_map<long long, int>> f(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long long d = 1LL * nums[i] - nums[j];
                auto it = f[j].find(d);
                int cnt = it == f[j].end() ? 0 : it->second;
                ans += cnt;
                f[i][d] += cnt + 1;
            }
        }
        return ans;
    }
};
```

##### 1654\.到家的最少跳跃次数

[题目](https://leetcode.cn/problems/minimum-jumps-to-reach-home)

记录两个状态：当前位置、上一步到这一步是往前还是往后。

必须记录两个状态，不能忽略上一个状态，不然会错。感觉也很合理，不证。

假设跳到比 $x+b$ 还远的位置，若 $a\ge b$，不能连续后跳两次，则无论如何都回不到 $x$，故边界为 $x+b$。若 $a <b$，设 $f$ 是最大禁止下标，当要求次数最小时，考虑如下两条等长路径：

![image.png](img/1644679382-RhIkpL-image.png)

这意味着，可以通过修改操作顺序，在不连续两次往回的前提下，构造当前位置恒不超过 $\max(f+a+b,x)$ 的方案，即每次往前走要越界时马上往回走，可行范围是 $a+b$，之后就不受禁止影响了。

证明：设 $f$ 开始是原点，对 $p=a+b$ 模意义下，从原点开始，只能选择 $+a$ 或 $-b$，对某个数 $x$，有 $x+a$ 不超 $a+b$ 时不变，超了就变成 $x-b$。对 $x-b$ 不超时就 $x-b$，超了就 $x+a$，所以从模意义证明了路径等效性。

所以 BFS 即可：

```c++
class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        // 最远距离 bound = max(F + a + b, x + b)
        int F = *max_element(forbidden.begin(), forbidden.end()), bound = max(F + a + b, x + b);

        int ban[bound + 1];
        memset(ban, 0, sizeof(ban));
        for(int f : forbidden) {
            ban[f] = 1;
        }

        int dist[bound + 1][2]; // dist[i][0] - 上一次前跳, dist[i][1] - 上一次后跳
        memset(dist, 0x3f, sizeof(dist));
        dist[0][0] = 0;
        queue<pair<int,int>> q({{0, 0}});
        while(q.size()) {
            auto [i, pre] = q.front(); q.pop();
            if(i == x) {
                return dist[i][pre];
            }
            if(pre == 0 && i-b >= 0 && !ban[i-b] && dist[i][pre] + 1 < dist[i-b][1]) {
                dist[i-b][1] = dist[i][pre] + 1;
                q.emplace(i-b, 1);
            }
            if(i+a <= bound && !ban[i+a] && dist[i][pre] + 1 < dist[i+a][0]) {
                dist[i+a][0] = dist[i][pre] + 1;
                q.emplace(i+a, 0);
            }
        }

        return -1;
    }
};

```

##### 458\.可怜的小猪

[题目](https://leetcode.cn/problems/poor-pigs/)

> 样例2解释：猪1喝23,猪2喝24,刚好对应二进制状态。
>
> 样例3解释：给 60min 可以一头猪，只要只有1猪喝两桶，那么喝死了无法确定具体哪桶有毒所以还要多一头。

设 $n$ 猪弄清 $m$ 桶需要的次数为 $t$，定义为 $f(n,m)$，则时间为 $die\times t$。

1. $n=1$，$t=m-1$。一桶桶喝，喝到第 $i$ 桶死了就有毒。如果喝了前 $m-1$ 桶都没死，最后一桶肯定有毒。即 $f(1,m)=m-1$。

2. $n=2$。

   枚举所有不重合方案：第一轮猪a 喝前 $i$ 桶，猪b 喝后 $m-i$ 桶。

   设一猪同时喝 $x$ 桶喝死了，另一猪一定不死，第二头猪分辨这 $x$ 桶，只能一桶桶喝。发现的最坏时间为第一头猪喝死喝一次，第二头猪喝倒数第二桶桶喝死喝 $x-1$ 次，共 $x-1+1$ 次。

   - 第一次喝猪a喝死了，花费 $i$ 次。
   - 第一次喝猪b喝死了，花费 $m-i$ 次。

   故最坏喝 $\max(i,m-i)$ 次，显然取 $i=m\div 2$ 取整(上下取整均可)。即喝的次数为 $\lceil\dfrac m2\rceil$。

   > 如果猪a 喝前 i 桶，猪b 喝后 $m-j(j <i)$ 桶，显然一定不更优。
   >
   > 如果猪a 喝任意 i 桶，可以等价于重排序为前 i 桶。

   改进：跳过第一桶，猪a喝第二桶开始的 $i$ 桶，猪b喝后面全部，可以优化为 $\lceil\dfrac {m-1}2\rceil=\lfloor\dfrac m2\rfloor$。

   但是这样的方案解释不了样例二，因为可以只喝一次。考虑两猪喝的桶有重叠。重叠桶数能且仅能是 1，因为如果重叠 2 桶，刚好有毒在这里，都死了分不出哪一桶。

   归纳法：

   - $m=1$ 显然零次，猪都不用了

   - $m=2$ 显然一次

   - $m=3$，不需要重叠，猪a喝2，猪b喝3，都没死就1，a死2，b死3，喝一次。即上文改进方案的例子。

   - $m=4$，重叠，猪a喝23，猪b喝24，都死了2，都没死1，仅死a3，仅死b4，喝一次

   - $m=5$，猪a 234，猪b 25，如果a死b活，第二轮b喝34，喝两次

     可以认为子问题为 $2,n-1$。

   - $m=6$，猪a 234，猪b 256，增讨b死a活a喝56，两次

     子问题为两个 $2,n-1$ 的最大值。

   - $m=7$，猪a 123,，猪b 145，都没死的话a6，两次。

     子问题加一个 $2,n$。

   - $m=8$，不变，都没死的话a6,b7，两次。

     一子问题改为 $3,n$。

   - $m=9$，如果不变， 6789 子问题要 1 次，所以还是两次。

   也就是说，每次分配方案时，

   > 设猪a 喝 $[1,x]$，猪b 喝 $\{1\}\cup [x+1,x+y-1]$，长度分别为 $x+y$，且剩下 $[x+y,m]$ (长为 $m-x-y$)没猪喝。设 $dp_{i}$ 表示 $n=2,m=i$ 最少喝几次。根据归纳，得出转移方程：
   > $$
   > dp_m=\min_{x,y,x+y\le m}(\max(x-2,y-2,dp_{m-x-y})+1)
   > $$
   > 第一次能判断出来当且仅当两猪死，否则，死猪a 判断 $[2,x]$，长为 $x-1$，化为 $n=1$ 子问题结论为 $f(1,x-1)=x-2$。死猪b 判断长为 $y-1$ 的 $[x+2,x+y-1]$，同理为 $f(1,y-1)=y-2$。否则，都活着，判断长为 $f(2,m-x-y+1)$。

   重新整理，设猪a 喝 $[1,1+x]$，非重叠长 $x$，猪b 喝 $\{1\}\cup [1+x+1,1+x+y]$，非重叠长为 $y$，没猪喝 $[2+x+y,n]$，长 $z=n-x-y-1$。则：
   $$
   dp_m=\min(1+\max(x-1,y-1,dp_z))
   $$
   初始值 $dp_0=0$，可以写暴力 DP 验证：

   ```python
   m=100
   dp = [0 for i in range(m+1)]
   dp[2] = dp[3] = 1
   for i in range(4, m+1):
       dp[i] = m
       for x in range(1, i+1):
           for y in range(1, i+1):
               if 1+x+y >= i:
                   continue
               z = i - (x+y+1)
               dp[i] = min(dp[i], max(x-1,y-1,dp[z])+1)
   for i in range(1,m+1):
       print(i,dp[i])
   ```

   因此，可以暴力 $O(m^3)$ 求出 $f(2,m)$ 的值。观察值，可以得出规律：

   $dp$ 递增，且有 $1$ 个值为 $0$，$3$ 个值为 $1$，$5$ 个值为 $2$，$\cdots$，$2i+1$ 个值为 $i$。等差数列求和，可知规律前 $n$ 项和是 $(i+1)^2$，故为 $dp_i=\lfloor\sqrt{i-1}\rfloor$。

   即 $f(2,m)=\lfloor\sqrt{m-1}\rfloor$

3. 根据数学直觉，不妨推测 $f(n,m)=\lfloor(m-1)^{\frac 1n}\rfloor$。

   > 则对样例，求一下 $f(i,1000)$，得：
   >
   > ```python
   > for i in range(1,7):
   >     print(i, int(999**(1/i)))
   > ```
   >
   > 符合样例一。

因此，设最大容忍次数为 $t=\lfloor\dfrac{minutesToTest}{minutesToDie}\rfloor$，从小到大枚举 $n$，找到最小的满足 $f(n,m)\le t$ 的 $n$ 输出即可。

```python
class Solution:
    def poorPigs(self, m: int, minutesToDie: int, minutesToTest: int) -> int:
        if m == 1:
            return 0
        t = minutesToTest // minutesToDie
        n = 1
        while int((m-1)**(1 / n)) > t:
            n += 1
        return n
```

证明暂略，有空再补。

> ### 力扣比赛
>

#### 周赛327

**vp成绩**：

![image-20230112173246572](img/image-20230112173246572.png)

##### 2529\. 正整数和负整数的最大计数

签到题。进阶就二分 xx bound 即可。

```c++
int maximumCount(vector<int> &nums)
{
    int neg = 0, pos = 0;
    for (int i = 0, n = nums.size(); i < n; ++i)
    {
        neg += nums[i] < 0;
        pos += nums[i] > 0;
    }
    return max(neg, pos);
}
```



##### 2530\. 执行 K 次操作后的最大分数

小根堆的板子题。

```c++
long long maxKelements(vector<int> &nums, int k)
{
    using ll = long long;
    priority_queue<ll> q;
    for (int i = 0, n = nums.size(); i < n; ++i)
    {
        q.push(nums[i]);
    }
    ll ans = 0;
    while (k--)
    {
        ll x = q.top();
        q.pop();
        ans += x;
        q.push((x - 1) / 3 + 1);
    }
    return ans;
}
```



##### 2531\. 使字符串总不同字符的数目相等

暴力优化。容易发现每个字母只有前两次出现(/首次出现)是有用的，之后再出现全删了。因此可以在一遍扫描后用 $O(26^2)$ 的复杂度暴力尝试所有字母组合的交换。(写得烂，实际上写出来 $O(52^2)$，但无伤大雅)

```c++
bool isItPossible(string word1, string word2)
{
    int bin1[130] = {}, bin2[130] = {};
    int n1 = 0, n2 = 0, m1 = 0, m2 = 0;
    string s1, s2;
    auto add = [&](char c, int *bin, int &m)
    {
        if (bin[c]++ == 0)
        {
            m++;
        }
    };
    auto del = [&](char c, int *bin, int &m)
    {
        if (--bin[c] == 0)
        {
            m--;
        }
    };
    for (auto c : word1)
    {
        add(c, bin1, m1);
        if (bin1[c] <= 2)
        {
            n1++;
            s1 += c;
        }
    }
    for (auto c : word2)
    {
        add(c, bin2, m2);
        if (bin2[c] <= 2)
        {
            n2++;
            s2 += c;
        }
    }
    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j)
        {
            del(s1[i], bin1, m1);
            del(s2[j], bin2, m2);
            add(s1[i], bin2, m2);
            add(s2[j], bin1, m1);
            if (m1 == m2)
            {
                return true;
            }
            del(s1[i], bin2, m2);
            del(s2[j], bin1, m1);
            add(s1[i], bin1, m1);
            add(s2[j], bin2, m2);
        }
    }
    return false;
}
```



##### 2532\. 过桥的时间

大模拟题。按题意做即可，一眼大约 $O(t\log n)$ 的复杂度。

```c++
static long long t;
static int suc;
static int hsuc;
struct worker
{
    int i, ltr, po, rtl, pn;
    bool operator<(const worker &rhs) const
    {
        if (ltr + rtl != rhs.ltr + rhs.rtl)
        {
            return ltr + rtl < rhs.ltr + rhs.rtl;
        }
        return i < rhs.i;
    }
};
static priority_queue<worker> lq, rq;

struct event;
static bool busy;
static priority_queue<event> ev;
const static int e_finish_cross_bridge_fright = 1;
const static int e_finish_putnew = 2;
const static int e_finish_cross_bridge_fleft = 3;
const static int e_finish_putold = 4;
struct event
{
    long long t;
    int ty;
    worker w;
    void next() const
    { // 回调事件
        if (ty == e_finish_cross_bridge_fright)
        { // putnew
            busy = false;
            ++suc;
            ev.push({t + w.pn, e_finish_putnew, w});
        }
        else if (ty == e_finish_putnew)
        { // left to right
            lq.push(w);
        }
        else if (ty == e_finish_cross_bridge_fleft)
        { // putold
            busy = false;
            ++hsuc;
            ev.push({t + w.po, e_finish_putold, w});
        }
        else if (ty == e_finish_putold)
        { // right to left
            rq.push(w);
        }
    }
    bool operator<(const event &rhs) const
    {
        return t > rhs.t;
    }
};

class Solution
{
public:
    int findCrossingTime(int n, int k, vector<vector<int>> &time)
    {
        t = 0;
        suc = 0;  // 走回左岸的
        hsuc = 0; // 从旧仓库拿起的
        busy = false;
        while (!ev.empty())
        {
            ev.pop();
        }
        while (!lq.empty()) // left side waiting
        {
            lq.pop();
        }
        while (!rq.empty())
        {
            rq.pop();
        }

        for (int i = 0; i < k; ++i)
        {
            lq.push({i, time[i][0], time[i][1], time[i][2], time[i][3]});
        }

        while (suc < n)
        {
            while (!ev.empty() && ev.top().t == t)
            {
                ev.top().next();
                ev.pop();
            }
            if (!busy)
            {
                if (!rq.empty())
                {
                    worker w = rq.top();
                    rq.pop();
                    ev.push({t + w.rtl, e_finish_cross_bridge_fright, w});
                    busy = true;
                }
                else if (!lq.empty() && hsuc < n)
                {
                    worker w = lq.top();
                    lq.pop();
                    ev.push({t + w.ltr, e_finish_cross_bridge_fleft, w});
                    busy = true;
                }
            }
            if (suc < n && !ev.empty())
            {
                t = ev.top().t;
            }
        }
        return t;
    }
};
```

> 挂了一次，因为 operator 重载写炸了，太久没练手写成了：
>
> ```c++
> bool operator<(const worker &rhs) const
> {
>     if (ltr + rtl < rhs.ltr + rhs.rtl)
>     {
>         return true;
>     }
>     return i < rhs.i;
> }
> ```





#### Shell

##### 193\. 有效电话号码

[题目](https://leetcode.cn/problems/valid-phone-numbers/),任意一种：

```shell
grep -P '^(\d{3}-|\(\d{3}\) )\d{3}-\d{4}$' file.txt
sed -n -r '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-[0-9]{4}$/p' file.txt
awk '/^([0-9]{3}-|\([0-9]{3}\) )[0-9]{3}-([0-9]{4})$/' file.txt
```

chatGPT:

grep 是一种在文本文件中查找文本的命令行工具。它的基本语法如下：

```sh
grep 'pattern' file
```

其中，'pattern' 是要查找的文本字符串，file 是要搜索的文件。

如果要在多个文件中搜索，可以将文件名列在命令行中：

```sh
grep 'pattern' file1 file2 file3
```

可以在目录中搜索文件，可以使用通配符。

```sh
grep 'pattern' /path/to/dir/*
```

还可以使用递归模式搜索整个目录：

```sh
grep -r 'pattern' /path/to/dir
```

grep 命令还有很多选项可用, 例如：

- -n : 显示匹配行的行号。输出如 `\d:` 格式不带空格拼接后面内容
- -i : 忽略大小写。
- -v : 显示不包含匹配字符串的行。
- -w 用于在文本文件中搜索仅完全匹配单词的文本(类似于正则的单词边界检测，即若有 `sh` 能匹配 `sh st` 不能匹配 `shst`)

可以使用 man grep 查看详细信息。

`grep -P` 是一个选项，它允许使用 Perl 正则表达式 (PCRE) 来搜索文本。

Perl 正则表达式是一种功能强大的正则表达式语言，支持许多特殊字符和模式匹配操作。例如，可以使用 PCRE 中的捕获组来匹配多个子字符串，或者使用命名组来方便地管理匹配的子字符串。

如果要使用 PCRE 来搜索文本，可以在 grep 命令中使用 -P 选项，例如：

```sh
grep -P '\d{3}-\d{2}-\d{4}' file
```

这个命令将在文件中查找所有符合美国社会安全号码格式的字符串（xxx-xx-xxxx）。

请注意，使用 -P 选项需要 PCRE 库的支持。如果系统上没有安装该库，则会提示错误信息。

另外, -P 是GNU grep独有的参数，在其他版本的 grep 中可能不支持。

假设你有一个名为 "log.txt" 的文件，其中包含多行日志信息，你想查找所有包含 "error" 的行。

可以使用以下命令来实现：

```sh
grep 'error' log.txt
```

这个命令将在 "log.txt" 中查找所有含有 "error" 的行，并将这些行的文本打印到屏幕上。



##### 195\. 第十行

[题目](https://leetcode.cn/problems/tenth-line/)。

`cut` 是一个命令行工具，用于从文本文件中删除或提取特定字段。它通常用于处理以某种字符（通常是制表符或空格）分隔的文本文件。

`cut` 的基本语法如下：

```sh
cut -f field_number -d delimiter file
```

其中，-f 指定要提取的字段，-d 指定字段之间的分隔符，file 是要处理的文件。

例如，假设你有一个文件 "data.txt"，其中包含以逗号分隔的数据，如下所示：

```
Copy codeName,Age,Gender
John,30,Male
Sara,25,Female
```

你可以使用以下命令提取第一列（Name）：

```sh
cut -f 1 -d ',' data.txt
```

输出

```
Name
John
Sara
```

也可以提取多列，例如提取第一列和第二列

```sh
cut -f 1,2 -d ',' data.txt
```

输出

```
Name,Age
John,30
Sara,25
```

第二种格式：

`cut -d: -f2` 是一个 `cut` 命令的例子。

`-d:` 指定字段之间的分隔符为冒号 (:)。

`-f2` 指定要提取的字段是第二个字段。

例如，假设你有一个文件 "data.txt"，其中包含以冒号分隔的数据，如下所示：

```
Name:Age:Gender
John:30:Male
Sara:25:Female
```

你可以使用 `cut -d: -f2` 来提取第二列（Age）:

```sh
cut -d: -f2 data.txt
```

输出

```
30
25
```

这个命令将会在文件中查找所有冒号分隔的字段，并输出第二个字段。

由此，引出第一种解法：

```sh
grep -n "" file.txt | grep -w '10' | cut -d : -f 2
```



`sed` 是一个流编辑器，用于在文本文件中执行替换、删除、插入和其他编辑操作。它在命令行中运行，可以对文本文件进行非常强大的编辑。

`sed` 的基本语法如下：

```sh
sed 's/old/new/g' file
```

其中 `s/old/new/g` 是一个替换命令，它会替换文件中所有的 "old" 为 "new"。

```sh
sed -n '10p' file.txt
```

`-n` 选项表示禁止默认输出，只有在符合特定条件时才会输出

`10p` 指令是打印第10行。



```sh
awk '{if(NR==10){print $0}}' file.txt
```

`awk` 是一种用于文本处理的命令行工具，可以轻松地对文本文件进行模式匹配、替换、计算和其他操作。

在这个命令中，`NR==10` 是一个条件，它指明 awk 只对第10行执行操作。

`{print $0}` 指令是打印整行。



加小于十行判定：

```sh
row_num=$(cat file.txt | wc -l)
echo $row_num
if [ $row_num -lt 10 ];then
    echo "The number of row is less than 10"
else
    awk '{if(NR==10){print $0}}' file.txt
fi
```

输出总行数的办法：

```sh
awk '{print NR}' file.txt | tail -n1
awk 'END{print NR}' file.txt 
grep -nc "" file.txt 
grep -c "" file.txt 
grep -vc "^$" file.txt 
grep -n "" file.txt|awk -F: '{print '}|tail -n1 | cut -d: -f1
grep -nc "" file.txt
sed -n "$=" file.txt 
wc -l file.txt 
cat file.txt | wc -l
wc -l file.txt | cut -d' ' -f1
```



##### 194\. 转置字符

[题目](https://leetcode.cn/problems/transpose-file/)

```sh
columns=$(cat file.txt | head -n 1 | wc -w)
for i in $(seq 1 $columns)
do
awk '{print $'''$i'''}' file.txt | xargs
done
```

1. 使用 `cat` 命令读取文件 file.txt 的第一行
2. 使用 `head -n 1` 命令取出第一行
3. 使用 `wc -w` 命令统计第一行的单词数，并将结果存储在变量 `columns` 中
4. 使用 `seq 1 $columns` 命令生成从 1 到 $columns 的数字序列
5. 对于序列中的每一个数字，使用 `awk '{print $i}' file.txt` 命令取出文件中第i列的值
6. 将第i列的值使用 `xargs` 命令打印到屏幕上. xargs 可将多个参数用空格隔开，如 `cat` 管道到 `xargs` 会以空格代替换行

`xargs` 是一个命令行工具，它可以将输入转换为命令行参数并执行命令。通常与其他命令结合使用，如 find, grep 等等。

`xargs` 的基本语法如下：

```sh
command | xargs [options] [command [options]]
```

其中，`command` 是输入的命令，`xargs` 将其输出作为参数传递给后面的命令。

例如，假设你有一个文件夹 /tmp 中有很多文件，你想删除所有以 .txt 结尾的文件。

```sh
\find /tmp -name '*.txt' | xargs rm
```

这个命令将使用 find 命令在 /tmp 目录中查找所有以 .txt 结尾的文件，并将这些文件名传递给 xargs 命令。xargs 命令将这些文件名作为参数传递给后面的 rm 命令，从而删除这些文件

上文莫名其妙的一堆单引号，可以改为双引号解析内部变量：

```sh
awk '{print $'"$i"'}' file.txt | xargs
```

或：(因为多余的可以认为是空串`''`，做的字符串拼接)

```sh
awk '{print $'$i'}' file.txt | xargs
```



`$()` 是 shell 中的一种特殊格式，称为命令替换。它允许将命令的输出作为参数传递给其他命令。

它的语法如下：

```sh
$(command)
```

其中，command 是要执行的命令，$() 将命令的输出作为参数传递给其他命令



##### 192\. 统计词频

[题目](https://leetcode.cn/problems/word-frequency/)

```sh
cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -nr | awk '{ print $2, $1 }'
```

`cat` 读文件并返回每行内容

`tr` 命令用于转换或删除文件中的字符 -s：缩减连续重复的字符成指定的单个字符。在这里将任意多空格转为单个换行

`sort` 按字典序排序每一行

`uniq` 命令用于检查及删除文本文件中重复出现的行列，一般与 sort 命令结合使用。-c：在每列开头显示该行重复出现的次数，格式是 `\d` 加一个空格与原内容隔开。

再次排序，使其倒序。注意，当单词的出现次数大于10时，sort 需要考虑按数字排序，而非默认的按 ascii 码排序

然后逐行按指定格式输出，[awk参考](https://mp.weixin.qq.com/s/rIvOa5yvXFCAWiidxFz_ug)



#### 数据库

##### 175\. 组合两个表

[题目](https://leetcode.cn/problems/combine-two-tables/)

```mysql
select a.firstName, a.lastName, b.city, b.state
from Person as a left join Address as b
on a.personId = b.personId;
```

> 更优雅：
>
> ```mysql
> select FirstName, LastName, City, State
> from Person left join Address
> on Person.PersonId = Address.PersonId;
> ```



##### 176\. 第二高的薪水

[题目](https://leetcode.cn/problems/second-highest-salary/)，注意去重后的第二高

对只有一行一列的数据，可以用再次 select 的方法输出，如果查不到数据，这样输出会返回 NULL，并且可以用 as 方法重命名列名

```mysql
select 1 as colname;
```

将查询结果套到这个 select 里，即可查空输出 NULL，个人解法：先嵌套子查询找最值，然后取小于最值的最大值

```mysql
select (
    select salary from Employee
    where salary < (select max(salary) from Employee)
    order by salary desc
    limit 1
) as SecondHighestSalary
```

更优解：直接排序时加 offset

```mysql
SELECT
    (SELECT DISTINCT
            Salary
        FROM
            Employee
        ORDER BY Salary DESC
        LIMIT 1 OFFSET 1) AS SecondHighestSalary;
```

也可以套 ifnull 函数：

```mysql
SELECT
    IFNULL(
      (SELECT DISTINCT Salary
       FROM Employee
       ORDER BY Salary DESC
        LIMIT 1 OFFSET 1),
    NULL) AS SecondHighestSalary
```



##### 177\. 第N高的薪水

[题目](https://leetcode.cn/problems/nth-highest-salary/)

offset 不能是表达式只能是变量/常量不然会炸，所以先设变量

```mysql
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  declare x int;
  set x = n-1;
  RETURN (
      # Write your MySQL query statement below.
      select (
          select distinct salary from Employee
          order by salary desc limit 1 offset x
      ) 
  );
END
```

可以把赋值塞到初始化，两行合一行：

```mysql
declare x int default N-1;
```

也可以不设变量，直接修改传入的参数：

```mysql
set N = N-1; # 或 :=
```

> chatGPT:
>
> `set n = 1` 是在 MySQL 的 SQL 查询中设置变量的语法，在这种情况下， n 将会被视为一个普通的变量。
>
> 而 `set n := 1` 是在 MySQL 的存储过程中设置变量的语法，在这种情况下，n 将会被视为一个局部变量。

[更多其他解法](https://leetcode.cn/problems/nth-highest-salary/solution/mysql-zi-ding-yi-bian-liang-by-luanz/)



##### 178\. 分数排名

[题目](https://leetcode.cn/problems/rank-scores/)

```mysql
select score,
dense_rank() over (order by score desc) as `rank` 
from Scores
```



##### 180\. 连续出现的数字

[题目](https://leetcode.cn/problems/consecutive-numbers/)

```mysql
select distinct a.Num as ConsecutiveNums
from Logs as a, Logs as b, Logs as c
where a.Id = b.Id - 1 and b.Id = c.Id - 1 and a.Num = b.Num and b.Num = c.Num
```



##### 181\. 超过经理收入的员工

[题目](https://leetcode.cn/problems/employees-earning-more-than-their-managers/) 注意读题，题意应当是每个人只有零个或一个上级经理，找到收入大于他直接上级的人

个人版用时很高的的代码(800ms+)：

```mysql
select a.name as `Employee`
from Employee as a
where a.salary > (
    select b.salary from Employee as b
    where b.id=a.managerId and a.salary>b.salary)
```

快很多(360ms)的两个相似代码：

```mysql
SELECT
    a.Name AS 'Employee'
FROM
    Employee AS a,
    Employee AS b
WHERE
    a.ManagerId = b.Id
    AND a.Salary > b.Salary
```

```mysql
SELECT
     a.NAME AS Employee
FROM Employee AS a JOIN Employee AS b
     ON a.ManagerId = b.Id
     AND a.Salary > b.Salary
```



##### 184\. 部门工资最高的员工

[题目](https://leetcode.cn/problems/department-highest-salary/)

个人效率很低的代码：(1080ms)

```mysql
select b.name as `Department`, a.name as `Employee`, a.salary as `Salary`
from Employee as a, Department as b
where a.departmentId = b.id and a.salary >= (
    select max(salary) from Employee as c
    where c.departmentId = b.id 
)
```

优化代码：(664ms)

```mysql
SELECT
    Department.name AS 'Department',
    Employee.name AS 'Employee',
    Salary
FROM
    Employee
        JOIN
    Department ON Employee.DepartmentId = Department.Id
WHERE
    (Employee.DepartmentId , Salary) IN
    (   SELECT
            DepartmentId, MAX(Salary)
        FROM
            Employee
        GROUP BY DepartmentId
	)
```



##### 185\. 部门工资前三高的所有员工

[题目](https://leetcode.cn/problems/department-top-three-salaries/)

> 注意到子查询不能带 limit(`This version of MySQL doesn't yet support 'LIMIT & IN/ALL/ANY/SOME subquery'`) 所以下面语句不能用：
>
> ```mysql
> select b.name as `Department`, a.name as `Employee`, Salary
> from Employee as a, Department as b
> where a.departmentId = b.id and
> Salary > any(
>     select c.salary from Employee as c
>     where a.departmentId = c.departmentId
>     order by salary desc limit 3
> )
> ```

修改上一题的思路，考虑：前三大，即在去重后的子查询里，最多只有两个(即 `<3`)人工资比他大，count 一下即可

```mysql
select b.name as `Department`, a.name as `Employee`, Salary
from Employee as a join Department as b
on a.departmentId = b.id
where 3 > (
    select count(distinct c.salary) from Employee as c
    where c.salary > a.salary
    and a.departmentId = c.departmentId
)
```



##### 182\. 查找重复的电子邮箱

[题目](https://leetcode.cn/problems/duplicate-emails/)

自己的弱智代码：(多余地增加了外层 select)

```mysql
select distinct a.Email from Person as a
where a.Email in (
    select b.Email from Person as b 
    group by b.Email having count(*)>1)
```

官解：

```mysql
select Email from Person group by Email having count(Email) > 1
```



##### 262\. 行程和用户

[题目](https://leetcode.cn/problems/trips-and-users/)

注意：

- 枚举类型的操作跟字符串差不多
- 联表要点(不能or合并连一次，必须连两次)
- round, sum, if 来实现计算

```mysql
select a.request_at as Day,
    round(sum(if(a.status='completed',0,1))/count(a.status),2) as `Cancellation Rate`
from Trips as a
join Users as b on a.client_id=b.users_id and b.banned='no'
join Users as c on a.driver_id=c.users_id and c.banned='no'
where a.request_at between '2013-10-01' and '2013-10-03'
group by a.request_at
```

效率高一点：

```mysql
SELECT T.request_at AS `Day`, 
	ROUND(
			SUM(
				IF(T.STATUS = 'completed',0,1)
			)
			/ 
			COUNT(T.STATUS),
			2
	) AS `Cancellation Rate`
FROM trips AS T
WHERE 
T.Client_Id NOT IN (
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
)
AND
T.Driver_Id NOT IN (
	SELECT users_id
	FROM users
	WHERE banned = 'Yes'
)
AND T.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY T.request_at
```



##### 196\.删除重复的电子邮箱

[题目](https://leetcode.cn/problems/delete-duplicate-emails/)

> 不能用下面语句，会报错为 `You can't specify target table 'Person' for update in FROM clause`
>
> ```mysql
> delete from Person
> where id not in (
>     select b.id from Person as b 
>     where b.id <= all (
>         select c.id from Person as c
>         where c.email = b.email
>     )
> )
> ```

```mysql
delete a from Person a, Person b
where a.email=b.email and a.id>b.id
```

其他方法：

```mysql
DELETE 
FROM
	Person 
WHERE
	id NOT IN 
	(SELECT t.id from (SELECT MIN(id) /*每个email分组中最小id*/as id FROM Person GROUP BY Email/*依据Email进行分组*/) t)
```



##### 601\.体育馆的流量

[题目](https://leetcode.cn/problems/human-traffic-of-stadium/)

个人不看题解的AC代码(340ms)：

```mysql
select distinct a.* from Stadium as a, Stadium as b, Stadium as c
where a.people>=100 and b.people>=100  and c.people>=100 and(
    (a.id=b.id-1 and b.id=c.id-1) or
    (a.id=b.id+1 and a.id=c.id-1) or
    (a.id=b.id+1 and b.id=c.id+1)
)
order by visit_date asc
```

372ms 的窗口函数解法，好处是适用于任意连续(上述连续几个要join几下)：

```mysql
with t1 as(
    select *,id - row_number() over(order by id) as rk
    from stadium
    where people >= 100
)

select id,visit_date,people
from t1
where rk in(
    select rk
    from t1
    group by rk
    having count(rk) >= 3
)
```

原理：如果要筛去 `<100` 的，则每次删除时会造成一个不连续，致使前后的 `id-row_number` (即未删时row number减既删时row number)的差值加至少1。所以每个连续段的差值是一致的，只要这个连续段长够3即可纳入



##### 197\.上升的温度

[题目](https://leetcode.cn/problems/rising-temperature/)

日期比较，使用 `datediff`，(472ms)

```mysql
select a.id from Weather as a, Weather as b
where datediff(a.recordDate,b.recordDate)=1 and a.Temperature>b.Temperature
```

窗口函数更快(348ms)

```mysql
select id
from
    (select 
        id,
        temperature,
        recordDate,
        lag(recordDate,1) over(order by recordDate) as last_date,
        lag(temperature,1) over(order by recordDate) as last_temperature
    from Weather) a
where temperature > last_temperature and datediff(recordDate, last_date) = 1
```

其他函数：

```mysql
select w1.Id
from Weather as w1, Weather as w2
where TIMESTAMPDIFF(DAY, w2.RecordDate, w1.RecordDate) = 1 
AND w1.Temperature > w2.Temperature
```

```mysql
select a.id 
    from weather a join weather b 
    on (a.recorddate = adddate(b.recorddate,INTERVAL 1 day))
where a.temperature > b.temperature
```

```mysql
select 
    w.Id
from Weather w
join (
    select 
        RecordDate,Temperature
    from 
        Weather
) t1
on w.RecordDate = DATE_ADD(t1.RecordDate,INTERVAL 1 day)
where w.Temperature > t1.Temperature;
```



##### 608\.树节点

[题目](https://leetcode.cn/problems/tree-node/)

个人代码：



```mysql
select id,
    case when (id in (select id from tree where isnull(p_id))) then 'Root'
    when (id in (select distinct p_id from tree)) then 'Inner'
    else 'Leaf' end as `Type`
from tree -- 或 is null 关键字而不是用函数
```

可以等价于：

```mysql
SELECT
    atree.id,
    IF(ISNULL(atree.p_id),
        'Root',
        IF(atree.id IN (SELECT p_id FROM tree), 'Inner','Leaf')) Type
FROM tree atree
```



##### 511\.游戏玩法分析I

[题目](https://leetcode.cn/problems/game-play-analysis-i/)

group by 裸题：

```mysql
select player_id, min(event_date) as first_login
from Activity group by player_id
```



##### 626\.换座位

[题目](https://leetcode.cn/problems/exchange-seats/)

if-else 题：

```mysql
select id,
    case when id%2=1 and isnull(lead(student,1) over (order by id asc))=0
        then lead(student,1) over (order by id asc)
    when id%2=0 then lag(Seat.student,1) over (order by id asc)
    else student end as `student`
from Seat
```

注意不能直接搞 min, max, count 等聚类函数，否则只会查一列。

要搞可以这么搞：

```mysql
SELECT
    (CASE
        WHEN MOD(id, 2) != 0 AND counts != id THEN id + 1
        WHEN MOD(id, 2) != 0 AND counts = id THEN id
        ELSE id - 1
    END) AS id,
    student
FROM
    seat,
    (SELECT
        COUNT(*) AS counts
    FROM
        seat) AS seat_counts
ORDER BY id ASC;
```



##### 584\.寻找用户推荐人

[题目](https://leetcode.cn/problems/find-customer-referee/)

注意 mysql 是三值比较，即有 true, false, unknown，所以要特判 null

```mysql
select name from customer where referee_id!=2 or isnull(referee_id)
```

安全等于：当两个操作数均为 NULL 时，其返回值为 1 而不为 NULL； 而当一个操作数为 NULL 时，其返回值为 0 而不为 NULL。 [ref](https://leetcode.cn/link/?target=http://c.biancheng.net/view/7191.html)

```mysql
SELECT name FROM customer WHERE NOT referee_id <=> 2;
```



##### 1393\.股票的资本损益

[题目](https://leetcode.cn/problems/capital-gainloss/)

```mysql
select stock_name,
    sum(case when operation='Buy' then -price else price end) as `capital_gain_loss`
from Stocks
group by stock_name
```

题解其他写法解法：

```mysql
select 
    stock_name, 
    sum(if(operation='Buy',-price, price)) capital_gain_loss 
from Stocks
group by stock_name
```



##### 586\.订单最多的客户

[题目](https://leetcode.cn/problems/customer-placing-the-largest-number-of-orders/)

我的实现：(一定要有 as c 不然报错，临时表必须命名)

```mysql
select c.customer_number from (
    select customer_number, count(*)
    from Orders
    group by customer_number 
    order by count(*) desc
    limit 1
) as c
```

更优雅的做法是：

```mysql
SELECT
    customer_number
FROM
    orders
GROUP BY customer_number
ORDER BY COUNT(*) DESC
LIMIT 1
```



##### 158\.市场分析I

[题目](https://leetcode.cn/problems/market-analysis-i/)

究极低效个人代码：

```mysql
select user_id as `buyer_id`, join_date, if(isnull(tmp),0,tmp) as `orders_in_2019`
from Users left join (
    select buyer_id, count(*) as tmp from Orders
    where extract(year from order_date)='2019'
    group by buyer_id
) as c on user_id=buyer_id
```

快 300ms：

```mysql
select Users.user_id as buyer_id, join_date, ifnull(UserBuy.cnt, 0) as orders_in_2019
from Users
left join (
    select buyer_id, count(order_id) cnt 
    from Orders
    where order_date between '2019-01-01' and '2019-12-31'
    group by buyer_id
) UserBuy
on Users.user_id = UserBuy.buyer_id
```



##### 595\.大的国家

[题目](https://leetcode.cn/problems/big-countries/)

慢：

```mysql
select name,population,`area` from World
where `area`>=3000000 or population>=25000000
```

快：(快一点)

```mysql
SELECT
    name, population, area
FROM
    world
WHERE
    area >= 3000000

UNION

SELECT
    name, population, area
FROM
    world
WHERE
    population >= 25000000
```



##### 596\.超过5名学生的课

[题目](https://leetcode.cn/problems/classes-more-than-5-students/)

签。

```mysql
select class from Courses
group by class
having count(*)>=5
```



##### 607\.销售员

[题目](https://leetcode.cn/problems/sales-person/)

较高效率的个人写法：

```mysql
select a.name from SalesPerson as a
where a.sales_id not in (
    select b.sales_id from Orders as b
    where b.com_id in (
        select c.com_id from Company as c
        where c.name like 'RED'
    )
)
```



##### 620\.有趣的电影

[题目](https://leetcode.cn/problems/not-boring-movies/)

签。

```mysql
select * from cinema
where id%2=1 and description not like 'boring'
order by rating desc
```



##### 627\.变更性别

[题目](https://leetcode.cn/problems/swap-salary/)

不快：

```mysql
update Salary set sex=(
    case when sex='f' then 'm' else 'f' end
)
```

比较快：

```mysql
update salary set sex = if(sex='m','f','m');
```

跟上面速度一样：

```mysql
update salary set sex = char(ascii('m') + ascii('f') - ascii(sex));
```



##### 1084\.销售分析III

[题目](https://leetcode.cn/problems/sales-analysis-iii/)

低效率：

```mysql
select product_id, product_name from Product
where product_id not in (
    select product_id from Sales
    where sale_date not between '2019-01-01' and '2019-03-31'
) and product_id in (
    select distinct product_id from Sales
)
```

一样低效率：

```mysql
select
    product_id,
    product_name
from product
where product_id in (
    select
        product_id
    from sales
    group by product_id
    having max(sale_date) <= '2019-03-31'
    and min(sale_date) >= '2019-01-01'
)
```

快 200ms:

```mysql
select
    s.product_id,
    p.product_name
from
    Sales s left join Product p
        on s.product_id = p.product_id
group by
    s.product_id
having
    min(s.sale_date) >= '2019-01-01'
        and max(s.sale_date) <= '2019-03-31'
```



##### 1141\.查询近30天活跃用户数

[题目](https://leetcode.cn/problems/user-activity-for-the-past-30-days-i/)

我的写法一：

```mysql
select activity_date as `day`,
    count(distinct user_id) as `active_users`
from Activity
where activity_date between '2019-06-28' and '2019-07-27'
group by activity_date
```

写法二：(没我的写法快)

```mysql
SELECT activity_date AS day, count(distinct user_id) AS active_users
FROM activity
WHERE DATEDIFF('2019-07-27', activity_date) >=0
AND DATEDIFF('2019-07-27', activity_date) < 30
GROUP BY activity_date;
```



##### 1148\.文章浏览I

[题目](https://leetcode.cn/problems/article-views-i/submissions/)

```mysql
select distinct author_id as id
from Views
where author_id=viewer_id
order by author_id asc
```



##### 1179\.重新格式化部门表

[题目](https://leetcode.cn/problems/reformat-department-table/)

```mysql
SELECT id, 
SUM(CASE WHEN month='Jan' THEN revenue END) AS Jan_Revenue,
SUM(CASE WHEN month='Feb' THEN revenue END) AS Feb_Revenue,
SUM(CASE WHEN month='Mar' THEN revenue END) AS Mar_Revenue,
SUM(CASE WHEN month='Apr' THEN revenue END) AS Apr_Revenue,
SUM(CASE WHEN month='May' THEN revenue END) AS May_Revenue,
SUM(CASE WHEN month='Jun' THEN revenue END) AS Jun_Revenue,
SUM(CASE WHEN month='Jul' THEN revenue END) AS Jul_Revenue,
SUM(CASE WHEN month='Aug' THEN revenue END) AS Aug_Revenue,
SUM(CASE WHEN month='Sep' THEN revenue END) AS Sep_Revenue,
SUM(CASE WHEN month='Oct' THEN revenue END) AS Oct_Revenue,
SUM(CASE WHEN month='Nov' THEN revenue END) AS Nov_Revenue,
SUM(CASE WHEN month='Dec' THEN revenue END) AS Dec_Revenue
FROM department
GROUP BY id
ORDER BY id;
```



##### 1484\.按日期分组销售产品

[题目](https://leetcode.cn/problems/group-sold-products-by-the-date/)

```mysql
select sell_date, count(distinct product) as `num_sold`,
    group_concat(distinct product order by product separator ',') as `products`
from Activities as a
group by sell_date
order by sell_date
```

或：

```mysql
SELECT sell_date,
       COUNT(DISTINCT product) num_sold,
       GROUP_CONCAT(DISTINCT product) products
FROM Activities
GROUP BY sell_date
```



##### 1407\.排名靠前的旅行者

[题目](https://leetcode.cn/problems/top-travellers/)

```mysql
select name, if(isnull(sum(distance)),0,sum(distance)) as `travelled_distance`
from Users left join Rides on Rides.user_id=Users.id
group by user_id
order by travelled_distance desc, name asc
```

效率差一点的写法：

```mysql
select
name,ifnull(travelled_distance,0) as travelled_distance
from Users
left join(
select
user_id,sum(distance) as travelled_distance 
from 
Rides 
group by user_id
)t1
on t1.user_id= Users.id
order by travelled_distance desc, name asc
```



##### 1795\.每个产品在不同商店的价格

[题目](https://leetcode.cn/problems/rearrange-products-table/)

is not null

```mysql
SELECT product_id, 'store1' store, store1 price FROM products WHERE store1 IS NOT NULL
UNION
SELECT product_id, 'store2' store, store2 price FROM products WHERE store2 IS NOT NULL
UNION
SELECT product_id, 'store3' store, store3 price FROM products WHERE store3 IS NOT NULL
```



##### 1873\.计算特殊奖金

[题目](https://leetcode.cn/problems/calculate-special-bonus/)

770ms:

```mysql
SELECT employee_id,
IF(MOD(employee_id,2)!=0 AND LEFT(name,1)!='M',salary,0) bonus
FROM Employees
ORDER BY employee_id
```

600ms:

```mysql
select employee_id, 
    case when name not like 'M%' and employee_id&1=1 then salary
    else 0 end as `bonus`
from Employees
order by employee_id asc
```

481ms:

```mysql
SELECT employee_id ,salary AS bonus
FROM Employees
WHERE employee_id%2!=0 AND name NOT LIKE ('M%')
UNION 
SELECT employee_id ,salary*0 AS bonus
FROM Employees
WHERE employee_id%2=0 OR name LIKE ('M%')
ORDER BY employee_id;
```



##### 1890\.2020年最后一次登录

[题目](https://leetcode.cn/problems/the-latest-login-in-2020/)

慢：

```mysql
select user_id, max(time_stamp) as `last_stamp`
from Logins
where extract(year from time_stamp) = '2020'
group by user_id
```

```mysql
SELECT user_id, max(time_stamp) last_stamp
FROM Logins
WHERE year(time_stamp) = 2020
GROUP BY user_id
```

```mysql
select user_id, max(time_stamp) last_stamp
from Logins
where time_stamp >= '2020-01-01 00:00:00' and time_stamp <= '2020-12-31 23:59:59'
group by user_id
```

```mysql
select user_id, max(time_stamp) as last_stamp
from logins
where datediff(time_stamp, '2020-01-01') >= 0 and datediff(time_stamp, '2021-01-01') < 0
group by user_id
```

快：

```mysql
select user_id,max(time_stamp)last_stamp from logins
where time_stamp like "2020%"
group by user_id
```



##### 1581\.进店缺未进行过交易的顾客

[题目](https://leetcode.cn/problems/customer-who-visited-but-did-not-make-any-transactions/)

1546ms:

```mysql
select customer_id, count(*) as `count_no_trans`
from Visits
where visit_id not in (select distinct visit_id from Transactions)
group by customer_id
```

1330ms:

```mysql
select v.customer_id,count(*) count_no_trans 
from Visits v 
left join Transactions t 
on (v.visit_id = t.visit_id) 
where amount is null 
group by customer_id 
```



##### 1527\.患某种疾病的患者

[题目](https://leetcode.cn/problems/patients-with-a-condition/)

```mysql
select * from Patients
where conditions like 'DIAB1%' or conditions like '% DIAB1%'
```

不能 `%DIAB1%`，考虑反例 `NOTDIAB11`

效率相近：

```mysql
SELECT * FROM PATIENTS
WHERE CONDITIONS REGEXP '^DIAB1|\\sDIAB1'
```



##### 1587\.银行账户概要II

[题目](https://leetcode.cn/problems/bank-account-summary-ii/)

910ms:

```mysql
select name, sum(amount) as `balance`
from Users, Transactions
where Users.account = Transactions.account
group by Users.account 
having sum(amount)>10000
```

750-800ms:

```mysql
select name, sum(amount) as balance
from users left join transactions on users.account = transactions.account
group by users.account
having balance > 10000
```



##### 1741\.查询每个员工花费的总时间

[题目](https://leetcode.cn/problems/find-total-time-spent-by-each-employee/)

```mysql
select event_day as `day`, emp_id, sum(out_time-in_time) as `total_time`
from Employees
group by day, emp_id
```



##### 1693\.每天的领导和合伙人

[题目](https://leetcode.cn/problems/reconstruct-itinerary/)

```mysql
select date_id, make_name, count(distinct lead_id) as `unique_leads`, 
count(distinct partner_id) as `unique_partners`
from DailySales
group by date_id, make_name
```

#### 多线程

##### 1114\.按序打印

[题目](https://leetcode.cn/problems/print-in-order/)

> 错误的：
>
> ```java
> class Foo {
> 
>  private static boolean firstDone = false;
>  private static boolean secondDone = false;
> 
>  public Foo() {
> 
>  }
> 
>  public void first(Runnable printFirst) throws InterruptedException {
> 
>      // printFirst.run() outputs "first". Do not change or remove this line.
>      printFirst.run();
>      firstDone = true;
>  }
> 
>  public void second(Runnable printSecond) throws InterruptedException {
> 
>      // printSecond.run() outputs "second". Do not change or remove this line.
>      while (!firstDone)
>          ;
>      printSecond.run();
>      secondDone = true;
>  }
> 
>  public void third(Runnable printThird) throws InterruptedException {
> 
>      // printThird.run() outputs "third". Do not change or remove this line.
>      while (!secondDone)
>          ;
>      printThird.run();
>  }
> }
> ```
>
>
> 换成非静态更错，会导致 TLE 的发生。
>
> 对非静态，分析如下：
>
> 每个线程有自己的工作内存(线程栈)，将用到的变量备份一份。所以最初每个线程都把 `firstDone, secondDone` 拷贝了一份。当 `firstDone` 更新时，这个更新没有通知其他线程的工作内存。
>
> 修改：被`volatile`关键字修饰的变量保证修改的值立刻更新到主存，使得其他线程需要读取时要到主存读取。所以上述变量加个 `volatile` 即可。

先看一份**错误的**代码：

```java
class Foo {

    private boolean firstDone = false;
    private boolean secondDone = false;

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        firstDone = true;  
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (!firstDone)
            ;
        printSecond.run();
        secondDone = true;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (!secondDone)
            ;
        printThird.run();
    }
}
```

错误原因分析：

每个线程有自己的工作内存(线程栈)，将用到的变量备份一份。所以最初每个线程都把 `firstDone, secondDone` 拷贝了一份。当 `f1` 执行完毕时，`firstDone` 更新时，这个更新没有通知其他线程的工作内存，所以导致 `firstDone` 对其他线程一直认为是 `false` 的。

> 具体而言，JVM定义了内存模型JMM(java memory model)屏蔽硬件平台和操作系统的内存访问差异，规定所有变量存在主存，线程有自己的工作内存，所有操作在工作内存进行(不能直接对主存操作)，线程不能访问其他线程的工作内存。

被 `volatile` 关键字修饰的变量保证修改的值立刻更新到主存，使得其他线程需要读取时要到主存读取。

> 具体而言，类的成员或静态成员变量被 `volatile` 修饰后：
>
> - 保证可见性，一个线程修改值后新值对其他线程立刻可见
>
>   当写一个volatile变量时，JMM会把该线程本地内存中的变量强制刷新到主内存中去，这个写会操作会导致其他线程中的volatile变量缓存无效
>
> - 禁止进行指令重排序
>
>   即执行到volatile变量时，其前面的所有语句都执行完，后面所有语句都未执行。且前面语句的结果对volatile变量及其后面语句可见
>
> 但 volatile 不保证原子性，因为运算操作符并非原子操作，需要保证原子性可以使用下面三种方法之一：
>
> 1. synchronized
> 2. Lock 
> 3. `AtomicInteger`
>
> 由于单纯的 `firstDone = true` 操作是原子操作，所以直接使用 volatile 即可。具体而言，Java 只保证基本数据类型变量的读取和赋值是原子性操作，如：
>
> ```java
> x = 10; //原子性
> y = x; //非原子性
> x++; //非原子性
> x = x + 1; //非原子性
> ```

因此，正确代码如下：

```java
class Foo {

    private volatile boolean firstDone = false;
    private volatile boolean secondDone = false;

    public Foo() {
    }

    public void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        firstDone = true;  
    }

    public void second(Runnable printSecond) throws InterruptedException {
        while (!firstDone)
            ;
        printSecond.run();
        secondDone = true;
    }

    public void third(Runnable printThird) throws InterruptedException {
        while (!secondDone)
            ;
        printThird.run();
    }
}
```

正确的其他：

①原子变量

```java
class Foo {

  private AtomicInteger firstJobDone = new AtomicInteger(0);
  private AtomicInteger secondJobDone = new AtomicInteger(0);

  public Foo() {}

  public void first(Runnable printFirst) throws InterruptedException {
    // printFirst.run() outputs "first".
    printFirst.run();
    // mark the first job as done, by increasing its count.
    firstJobDone.incrementAndGet();
  }

  public void second(Runnable printSecond) throws InterruptedException {
    while (firstJobDone.get() != 1) {
      // waiting for the first job to be done.
    }
    // printSecond.run() outputs "second".
    printSecond.run();
    // mark the second as done, by increasing its count.
    secondJobDone.incrementAndGet();
  }

  public void third(Runnable printThird) throws InterruptedException {
    while (secondJobDone.get() != 1) {
      // waiting for the second job to be done.
    }
    // printThird.run() outputs "third".
    printThird.run();
  }
}
```

同步锁：

```java
class Foo {
    
    private boolean firstFinished;
    private boolean secondFinished;
    private Object lock = new Object();

    public Foo() {
        
    }

    public void first(Runnable printFirst) throws InterruptedException {
        
        synchronized (lock) {
            // printFirst.run() outputs "first". Do not change or remove this line.
            printFirst.run();
            firstFinished = true;
            lock.notifyAll(); 
        }
    }

    public void second(Runnable printSecond) throws InterruptedException {
        
        synchronized (lock) {
            while (!firstFinished) {
                lock.wait();
            }
        
            // printSecond.run() outputs "second". Do not change or remove this line.
            printSecond.run();
            secondFinished = true;
            lock.notifyAll();
        }
    }

    public void third(Runnable printThird) throws InterruptedException {
        
        synchronized (lock) {
           while (!secondFinished) {
                lock.wait();
            }

            // printThird.run() outputs "third". Do not change or remove this line.
            printThird.run();
        } 
    }
}
```

##### 1115\.交替打印FooBar

[题目](https://leetcode.cn/problems/print-foobar-alternately/)

一种**错误的**超时代码如下：(n=5就超时了)

```java
class FooBar {
    private int n;
    private volatile boolean beforeBar = true;

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while (!beforeBar)
                ;
            printFoo.run();
            beforeBar = false;
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while (beforeBar)
                ;
            printBar.run();
            beforeBar = true;
        }
    }
}
```

错误理由：忙等太浪费 CPU，使得拉满时间片，占用了 2n 次时间片。

语法前置知识：

- synchronized了同一个对象的，同一时间只能有一个线程执行这个同步块中的代码。但不保证同步块内是原子性的。
- 将一个 Object 对象视为资源，当该对象使用 wait 方法时，阻塞掉对象所在线程。直到其他线程里被同一对象使用 notify(唤醒第一个wait的线程)或 notifyAll(唤醒所有wait的线程)
- 注意，wait 和 notify(All) 方法必须放在对该 object 自身的同步块内执行。

修改后的代码：

```java
class FooBar {
    private int n;
    private volatile boolean beforeBar = true;// 上一次打印了Bar
    private Object lock = new Object();

    public FooBar(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized (lock) {
                while (!beforeBar) {
                    lock.wait(); // 因lock而阻塞当前线程
                }
                printFoo.run();
                beforeBar = false;
                lock.notifyAll(); // 唤醒所有被lock阻塞的线程
                //在本题,都用notify也行
            }
        }

    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized (lock) {
                while (beforeBar) {
                    lock.wait();
                }
                printBar.run();
                beforeBar = true;
                lock.notifyAll();
            }
        }
    }
}
```

为什么上述代码是可行的，考虑一种情况，线程 A 执行 foo，线程 B 执行 bar， A,B 单处理机并发，一种可能的顺序如下：(不考虑 print 等的 IO 阻塞)

1. A while 判假，直接 print foo
2. A 赋值 `beforeBar=false` 然后时间片到了让出了处理机
3. B 刚开始执行，看到 false 了所以 while 判假，print bar
4. B 继续跑，不仅弄了 `beforeBar = true` 还 `notifyAll` 了
5. B 这一轮 for 完了，下一次 while 里把自己阻塞了
6. A 顺着之前，`notifyAll` 然后时间片又到了(或者被B唤醒抢占)
7. B 被唤醒，while 走下一轮，又把自己阻塞了
8. A 继续 print foo……

> 这样写也行：(foo bar 都类似改)
>
> ```java
> for (int i = 0; i < n; i++) {
>     while (!beforeBar) {
>         synchronized (lock) { //如果改成 lock2 或别的不行
>             lock.wait(); // 因lock而阻塞当前线程
>         }
>     }
>     printFoo.run();
>     beforeBar = false;
>     synchronized (lock) {
>         lock.notify(); // 唤醒所有被lock阻塞的线程
>     }
> }
> ```



附：六种方法：

```java
//手太阴肺经 BLOCKING Queue
public class FooBar {
    private int n;
    private BlockingQueue<Integer> bar = new LinkedBlockingQueue<>(1);
    private BlockingQueue<Integer> foo = new LinkedBlockingQueue<>(1);
    public FooBar(int n) {
        this.n = n;
    }
    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            foo.put(i);
            printFoo.run();
            bar.put(i);
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            bar.take();
            printBar.run();
            foo.take();
        }
    }
}

//手阳明大肠经CyclicBarrier 控制先后
class FooBar6 {
    private int n;

    public FooBar6(int n) {
        this.n = n;
    }

    CyclicBarrier cb = new CyclicBarrier(2);
    volatile boolean fin = true;

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            while(!fin);
            printFoo.run();
            fin = false;
            try {
                cb.await();
            } catch (BrokenBarrierException e) {}
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            try {
                cb.await();
            } catch (BrokenBarrierException e) {}
            printBar.run();
            fin = true;
        }
    }
}

//手少阴心经 自旋 + 让出CPU
class FooBar5 {
    private int n;

    public FooBar5(int n) {
        this.n = n;
    }

    volatile boolean permitFoo = true;

    public void foo(Runnable printFoo) throws InterruptedException {     
        for (int i = 0; i < n; ) {
            if(permitFoo) {
        	    printFoo.run();
            	i++;
            	permitFoo = false;
            }else{
                Thread.yield();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {       
        for (int i = 0; i < n; ) {
            if(!permitFoo) {
        	printBar.run();
        	i++;
        	permitFoo = true;
            }else{
                Thread.yield();
            }
        }
    }
}



//手少阳三焦经 可重入锁 + Condition
class FooBar4 {
    private int n;

    public FooBar4(int n) {
        this.n = n;
    }
    Lock lock = new ReentrantLock(true);
    private final Condition foo = lock.newCondition();
    volatile boolean flag = true;
    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            lock.lock();
            try {
            	while(!flag) {
                    foo.await();
                }
                printFoo.run();
                flag = false;
                foo.signal();
            }finally {
            	lock.unlock();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n;i++) {
            lock.lock();
            try {
            	while(flag) {
                    foo.await();
            	}
                printBar.run();
                flag = true;
                foo.signal();
            }finally {
            	lock.unlock();
            }
        }
    }
}

//手厥阴心包经 synchronized + 标志位 + 唤醒
class FooBar3 {
    private int n;
    // 标志位，控制执行顺序，true执行printFoo，false执行printBar
    private volatile boolean type = true;
    private final Object foo=  new Object(); // 锁标志

    public FooBar3(int n) {
        this.n = n;
    }
    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized (foo) {
                while(!type){
                    foo.wait();
                }
                printFoo.run();
                type = false;
                foo.notifyAll();
            }
        }
    }

    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            synchronized (foo) {
                while(type){
                    foo.wait();
                }
                printBar.run();
                type = true;
                foo.notifyAll();
            }
        }
    }
}


//手太阳小肠经 信号量 适合控制顺序
class FooBar2 {
    private int n;
    private Semaphore foo = new Semaphore(1);
    private Semaphore bar = new Semaphore(0);
    public FooBar2(int n) {
        this.n = n;
    }

    public void foo(Runnable printFoo) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            foo.acquire();
        	printFoo.run();
            bar.release();
        }
    }
    public void bar(Runnable printBar) throws InterruptedException {
        for (int i = 0; i < n; i++) {
            bar.acquire();
        	printBar.run();
            foo.release();
        }
    }
}
```

##### 1116\.打印零与奇偶数

[题目](https://leetcode.cn/problems/print-zero-even-odd/)

个人：

```java
class ZeroEvenOdd {
    private int n;
    private volatile boolean beforeZero = false;
    private volatile boolean beforeEven = true;
    private Object lockZero = new Object();
    private Object lockOdd = new Object();
    private Object lockEven = new Object();

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int i = 0; i < n; ++i) {
            while (beforeZero) {
                synchronized (lockZero) {
                    lockZero.wait();
                }
            }
            printNumber.accept(0);
            beforeZero = true;
            synchronized (lockOdd) {
                lockOdd.notifyAll();
            }
            synchronized (lockEven) {
                lockEven.notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            while (!(beforeZero && !beforeEven)) {
                synchronized (lockEven) {
                    lockEven.wait();
                }
            }
            printNumber.accept(i);
            beforeEven = true;
            beforeZero = false;
            synchronized (lockZero) {
                lockZero.notifyAll();
            }
            synchronized (lockOdd) {
                lockOdd.notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            while (!(beforeZero && beforeEven)) {
                lockOdd.wait();
            }
            printNumber.accept(i);
            beforeEven = false;
            beforeZero = false;
            synchronized (lockZero) {
                lockZero.notifyAll();
            }
            synchronized (lockEven) {
                lockEven.notifyAll();
            }
        }
    }
}
```

[其他一堆解法](https://leetcode.cn/problems/print-zero-even-odd/solution/by-be_a_better_coder-axp4/)

[一些解法](https://leetcode.cn/problems/print-zero-even-odd/solution/java-san-chong-xing-neng-you-yue-de-jie-h4pxx/)

信号量：

```java
class ZeroEvenOdd {
    private int n;

    // 默认 zero 有一个信号量可用
    private Semaphore zero = new Semaphore(1);

    // 默认 even 和 odd 没有可用信号量
    private Semaphore even = new Semaphore(0);
    private Semaphore odd = new Semaphore(0);

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {

        for (int i = 1;i <= n; i++){

            // 首次执行时， zero 有一个可用的信号量
            zero.acquire();
            printNumber.accept(0);
            if(i % 2 == 1){
                // 可以理解为 odd 增加一个信号量，这样 odd 可以继续走流程
                odd.release();
            }else{
                // 可以理解为 even 增加一个信号量， 这样 even 可以继续走流程
                even.release();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {

        for (int i = 2; i <= n;i += 2){

            // 等待信号量，获取到了信号后，往下走
            even.acquire();

            printNumber.accept(i);

            // 发送信号量给 zero
            zero.release();
        }

    }

    public void odd(IntConsumer printNumber) throws InterruptedException {

        for (int i = 1; i <= n; i += 2){

            // 等待信号量，获取到了信号后，往下走
            odd.acquire();
            printNumber.accept(i);

            // 发送信号量给 zero
            zero.release();
        }
    }

}
```

```java
class ZeroEvenOdd {
    private int n;

    // 方法二： 不用锁，直接用 volatile
    private volatile int curValue = 0;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {

        for (int i = 1; i <= n; i++) {
            while (curValue != 0) {
                Thread.yield();
            }

            printNumber.accept(0);

            if (i % 2 == 1) {
                curValue = 1;
            } else {
                curValue = 2;
            }

        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            while (curValue != 2) {
                Thread.yield();
            }

            printNumber.accept(i);
            curValue = 0;
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            while (curValue != 1) {
                Thread.yield();
            }

            printNumber.accept(i);
            curValue = 0;
        }
    }
}
```

##### 1117\.H2O生成

[题目](https://leetcode.cn/problems/building-h2o/)

个人：

```java
package lc;

import java.util.concurrent.Semaphore;
import java.util.concurrent.atomic.AtomicInteger;

class H2O {
    private Semaphore h1 = new Semaphore(0), h2 = new Semaphore(0);
    private Semaphore o1 = new Semaphore(0), o2 = new Semaphore(0);
    private Semaphore ho1 = new Semaphore(0), ho2 = new Semaphore(0);
    private Semaphore o = new Semaphore(1), h = new Semaphore(2);
    private AtomicInteger cnt = new AtomicInteger(0);

    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
//        System.out.println("1");
        boolean isFirst;
        synchronized (cnt) {
            isFirst = cnt.get() % 2 == 1 ? true : false;
            cnt.incrementAndGet();
        }
        h.acquire();
        if (isFirst) {
            h1.release();
            ho1.release();
            h2.acquire();
            o1.acquire();
        } else {
            h2.release();
            ho2.release();
            h1.acquire();
            o2.acquire();
        }
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
        h.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
//        System.out.println(2);
        o.acquire();
        o1.release();
        o2.release();
        ho1.acquire();
        ho2.acquire();
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
        releaseOxygen.run();
        o.release();
    }
}

public class lc1117 {
    public static void main(String[] args) throws InterruptedException {
        Runnable h = new Runnable() {
            @Override
            public void run() {
                System.out.print("H");
            }
        };
        Runnable o = new Runnable() {
            @Override
            public void run() {
                System.out.print("O");
            }
        };
        H2O h2o = new H2O();
        for (int i = 0; i < 2; ++i) {
            new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        h2o.hydrogen(h);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
        for (int i = 0; i < 1; ++i) {
            new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        h2o.oxygen(o);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }
    }
}
```

题解：

```java
class H2O {


    private Semaphore hSema = new Semaphore(2);
    private Semaphore oSema = new Semaphore(0);


    public H2O() {

    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        hSema.acquire();
        releaseHydrogen.run();
        oSema.release();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        oSema.acquire(2);
        releaseOxygen.run();
        hSema.release(2);
    }
}
```

[更多办法](https://leetcode.cn/problems/building-h2o/solution/chang-you-duo-xian-cheng-zhi-h2osheng-ch-8f7g/)

##### 1195\.交替打印字符串

[题目](https://leetcode.cn/problems/fizz-buzz-multithreaded/)

按序输出导致实际上每次只能同时运行一个线程。所以用一个变量表示当前应该输出哪个值，如果某个线程负责这个值就输出，否则就把自己的时间片让出去给别的线程。

因为变量值要通知给多个线程，所以可以考虑使用原子变量，或者使用 volatile 都可以。因为只能同时运行一个线程，所以不原子性也没啥问题。

原子变量：

```java
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.IntConsumer;

class FizzBuzz {
    private int n;
    private AtomicInteger cnt = new AtomicInteger(1);

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 3; i <= n; i += 3) {
            if (i % 5 != 0) {
                while (cnt.get() != i) {
                    Thread.yield();
                }
                printFizz.run();
                cnt.incrementAndGet();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 5; i <= n; i += 5) {
            if (i % 3 != 0) {
                while (cnt.get() != i) {
                    Thread.yield();
                }
                printBuzz.run();
                cnt.incrementAndGet();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 15; i <= n; i += 15) {
            while (cnt.get() != i) {
                Thread.yield();
            }
            printFizzBuzz.run();
            cnt.incrementAndGet();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; ++i) {
            if (i % 5 != 0 && i % 3 != 0) {
                while (cnt.get() != i) {
                    Thread.yield();
                }
                printNumber.accept(i);
                cnt.incrementAndGet();
            }
        }
    }
}
```

volatile:

```java
class FizzBuzz {
    private int n;
    private volatile int cnt = 1;

    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 3; i <= n; i += 3) {
            if (i % 5 != 0) {
                while (cnt != i) {
                    Thread.yield();
                }
                printFizz.run();
                ++cnt;
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 5; i <= n; i += 5) {
            if (i % 3 != 0) {
                while (cnt != i) {
                    Thread.yield();
                }
                printBuzz.run();
                ++cnt;
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 15; i <= n; i += 15) {
            while (cnt != i) {
                Thread.yield();
            }
            printFizzBuzz.run();
            ++cnt;
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; ++i) {
            if (i % 5 != 0 && i % 3 != 0) {
                while (cnt != i) {
                    Thread.yield();
                }
                printNumber.accept(i);
                ++cnt;
            }
        }
    }
}
```

[更多解法](https://leetcode.cn/problems/fizz-buzz-multithreaded/solution/chang-you-duo-xian-cheng-zhi-jiao-ti-da-eeurc/)

更好的本地调试：

```java
public static void main(String[] args) {
    Runnable printFizz = () -> {
        System.out.printf("%s", "fizz");
    };
    Runnable printBuzz = () -> {
        System.out.printf("%s", "buzz");
    };
    Runnable printFizzBuzz = () -> {
        System.out.printf("%s", "fizzbuzz");
    };
    IntConsumer intConsumer = new IntConsumer();
    FizzBuzz fb = new FizzBuzz(15);
    new Thread(() -> {
        try {
            fb.fizz(printFizz);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }).start();
    new Thread(() -> {
        try {
            fb.buzz(printBuzz);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }).start();
    new Thread(() -> {
        try {
            fb.fizzbuzz(printFizzBuzz);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }).start();
    new Thread(() -> {
        try {
            fb.number(intConsumer);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }).start();

}


public class IntConsumer {
    public void accept(int i) {
        System.out.printf("%d", i);
    }
}
```

同步量：

```java
class FizzBuzz {
    private int n;

    private Semaphore number = new Semaphore(1);
    private Semaphore fizz = new Semaphore(0);
    private Semaphore buzz = new Semaphore(0);
    private Semaphore fizzbuzz = new Semaphore(0);


    public FizzBuzz(int n) {
        this.n = n;
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 != 0) {
                fizz.acquire();
                printFizz.run();
                number.release();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 3 != 0 && i % 5 == 0) {
                buzz.acquire();
                printBuzz.run();
                number.release();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0 && i % 5 == 0) {
                fizzbuzz.acquire();
                printFizzBuzz.run();
                number.release();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i++) {
            number.acquire();
            if (i % 3 != 0 && i % 5 != 0) {//开始打印
                printNumber.accept(i);
                number.release();
            } else if (i % 3 == 0 && i % 5 != 0) {//fizz开始打印
                fizz.release();
            } else if (i % 3 != 0 && i % 5 == 0) {//buzz开始打印
                buzz.release();
            } else {
                fizzbuzz.release();//fizzbuzz开始打印
            }
        }
    }
}
```

##### 1226\.哲学家进餐

[题目](https://leetcode.cn/problems/the-dining-philosophers/)

设 5 个信号量 $c$，$c_i$ 表示第 $i$ 根筷子是否空闲，初始有 $c_i=1$。如果写成下面的**错误**形式：

```java
c[i].acquire();
c[(i + 1) % 5].acquire();

pickLeftFork.run();
pickRightFork.run();
eat.run();
putLeftFork.run();
putRightFork.run();

c[i].release();
c[(i + 1) % 5].release();
```

会出现死锁问题，考虑：

5 个哲学家都只执行完第一行代码(`c[i].acquire();`)就时间片到，进而导致每个哲学家都只拿了一根筷子，且等待别人拿了的另一根，满足死锁的四个条件：互斥、不可剥夺、请求和保持、循环等待。

为了打破死锁，规定每个哲学家要么同时拿起两根筷子，要么一根也不拿(即拿起一双筷子原子化)，为了实现这样的目的，可以增设一个 mutex 信号量，即：五个哲学家里，每次只允许一个哲学家拿筷子，当有哲学家将要拿筷子时，任何其他哲学家不能拿筷子。

因为拿到筷子的哲学家一定能吃，所以他拿的筷子一定会被释放，所以如果有另一位哲学家拿到一只筷子，他的等待时间是有限的，进而打破了死锁。完整代码：

```java
class DiningPhilosophers {
    Semaphore c[] = new Semaphore[5], mutex = new Semaphore(1);

    public DiningPhilosophers() {
        for (int i = 0; i < 5; ++i) {
            c[i] = new Semaphore(1);
        }
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int i, Runnable pickLeftFork, Runnable pickRightFork, Runnable eat,
            Runnable putLeftFork, Runnable putRightFork) throws InterruptedException {
        mutex.acquire();
        c[i].acquire();
        c[(i + 1) % 5].acquire();
        pickLeftFork.run();
        pickRightFork.run();
        mutex.release();
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        c[i].release();
        c[(i + 1) % 5].release();
    }
}
```

> 思路参考：2023 王道计算机操作系统考研复习指导 P102-P103。



### CF杂题

#### 训练赛2

SCNU 软院集训队个人赛第二场。

1. E [CF710A](https://vjudge.csgrandeur.cn/problem/CodeForces-710A/origin)

   签到 模拟

2. A [CF707B](https://vjudge.csgrandeur.cn/problem/CodeForces-707B/origin)

   图论 STL

3. F [CF709C](https://vjudge.csgrandeur.cn/problem/CodeForces-709C/origin)

   贪心

4. B [CF707C](https://vjudge.csgrandeur.cn/problem/CodeForces-707C/origin)

   数学 构造

5. C [CF707D](https://vjudge.csgrandeur.cn/problem/CodeForces-707D/origin)

   并查集 DFS 离线 bitset

6. G [CF709D](https://vjudge.csgrandeur.cn/problem/CodeForces-709D/origin)

   贪心 构造

7. D [CF707E](https://vjudge.csgrandeur.cn/problem/CodeForces-707E/origin)

   二维树状数组 离线 预处理

8. H [CF709E](https://vjudge.csgrandeur.cn/problem/CodeForces-709E/origin)

   重心 树上DP

##### E CF710A

喵一眼题面 href 可知，王后八方向。直接模拟或数学即可。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    char c;
    ll d;
    cin >> c >> d;
    ll r = c - 'a' + 1;
    ll ans = 0;
    for (ll i = r - 1; i <= r + 1; ++i)
    {
        for (ll j = d - 1; j <= d + 1; ++j)
        {
            if (!(i == r && j == d))
            {
                if (i >= 1 && i <= 8 && j >= 1 && j <= 8)
                {
                    ++ans;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
```

##### A CF707B

对只有非负权的边，显然任意最短路的最小值是只有一条边的最短路。set 存所有原料店，枚举每条边，如果边的一端在原料店内，一端不在，就更新边权。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 1e5 + 10, inf = 1e9 + 10;
ll n, m, k, ans = inf;
vector<pair<ll, ll>> g[mn];
set<ll> a;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> k;
    for (ll i = 1, u, v, w; i <= m; ++i)
    {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (ll i = 1, u; i <= k; ++i)
    {
        cin >> u;
        a.insert(u);
    }
    for (ll u = 1; u <= n; ++u)
    {
        if (a.find(u) == a.end())
        {
            continue;
        }
        for (auto [v, w] : g[u])
        {
            if (a.find(v) != a.end())
            {
                continue;
            }
            ans = min(ans, w);
        }
    }
    if (ans == inf)
    {
        cout << -1;
    }
    else
    {
        cout << ans << '\n';
    }
    return 0;
}
```

##### F CF709C

找到第一个不是 a 的地方开始，然后对每个字符都不为 a 的连续子段操作。如果无法找到，字符串必然全 a，改最后一个。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 1e5 + 10;
ll n;
char s[mn];
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> s;
    n = strlen(s);
    for (ll i = 0; i < n; ++i)
    {
        if (s[i] != 'a')
        {
            for (; i < n && s[i] != 'a'; ++i)
            {
                s[i]--;
            }
            cout << s;
            return 0;
        }
    }
    // all a
    for (ll i = 0; i < n; ++i)
    {
        assert(s[i] == 'a');
    }
    s[n - 1] = 'z';
    cout << s;
    return 0;
}
/*
codeforces
abacaba
z
zbb
za
*/
```

##### B CF707C

考虑 $m^2-(m-1)^2=2m-1(m\ge2)$，可覆盖所有 $> 1$ 的奇数的 $n^2$。

接下来对 $m^2-(m-2)^2=4m-4(m\ge 3)$，可以覆盖从 $8$ 开始的所有的 $4$ 的倍数的 $n^2$。

对任意 $m^2-(m-i)^2=2mi-i^2(i > 2, m - i \ge 1)$，若 $i$ 是奇数，则结果是奇数，不如 $i=1$。

否则，若 $i$ 是偶数，则 $2mi$ 是 $4$ 的倍数，由于 $i=2j$，故 $i^2=4j^2$ 也是 $4$ 的倍数。最小的是 $i=4$，为 $5^2-(5-4)^2=24$，所以覆盖不了 $8$ 以下。其覆盖结果也都不如 $i=2$。

对于任意的 $n^2$，若 $n$ 是奇数，$n^2$ 也是奇数，必然能被 $i=1$ 覆盖。若 $n > 2$ 且 $n$ 是偶数，则 $n=2x,n^2=4x^2$，即 $n$ 必然是 $4$ 的倍数，能被 $i=2$ 覆盖。所以仅有 $n=1,n=2$ 无解。也就是说得以严格证明不需要使用 $m^2+k^2$，只需要使用 $m^2-(m-1)^2,m^2-(m-2)^2$ 就可以覆盖全体正整数。

因此只需要考虑 $i=1,2$ 就可以覆盖全部情况。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    n *= n;
    if (n > 1 && n % 2 == 1)
    {
        cout << n / 2 + 1 << ' ' << n / 2;
        return 0;
    }
    if (n > 4 && n % 4 == 0)
    {
        cout << n / 4 + 1 << ' ' << n / 4 - 1;
        return 0;
    }
    cout << -1;
    return 0;
}
/*
1
3
2
4
8
16
3200080001 40000 40001
200080010 10001 10003
*/
```

##### C CF707D

注意到每次修改只能基于当前版本，且每次操作 $4$ 只能回退当前版本。即本题对版本的变化灵活性较差，这是关键。

当没有操作 4 时，操作可以看成一条链，边就是操作。从初始版本 $0$ 出发走一遍就得到了链上每个结果。当有操作 4 时，设从 $v$ 回退到 $u$，则将 $u,v$ 两点合并(考虑并查集)，然后下一次非 $4$ 的操作从 $v$ 出发继续延伸链，可知，能将询问离线得到一棵树。 

那么只需要从根节点 $0$ 出发，遍历这棵树，遍历时执行操作，然后回溯时撤销掉所执行的操作，就能处理出全部的询问。使用 bitset 优化操作 $3$，则复杂度为 $O(\dfrac m C)$，其他操作都是 $O(1)$。故总复杂度为 $O(\dfrac{qm}C)$。

注意一个细节，对无效的操作 $1$ 或 $2$，不需要撤销。操作 $1$、操作 $2$ 互为逆操作，操作 $3$ 的逆操作是自身。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mb = 1024, mn = 1e5 + 10;
bitset<mb> a[mb], rv;
ll k[mn], n, m, q, fa[mn], s;
struct cmd
{
    ll op, i, j;
};
vector<pair<ll, cmd>> g[mn];
ll findf(ll x)
{
    while (x != fa[x])
    {
        x = fa[x];
    }
    return x;
}
void perform(cmd &c)
{
    if (c.op == 1)
    {
        if (!a[c.i][c.j])
        {
            ++s;
        }
        else
        {
            c.op = 5;
        }
        a[c.i][c.j] = 1;
    }
    else if (c.op == 2)
    {
        if (a[c.i][c.j])
        {
            --s;
        }
        else
        {
            c.op = 5;
        }
        a[c.i][c.j] = 0;
    }
    else if (c.op == 3)
    {
        s -= a[c.i].count();
        a[c.i] ^= rv;
        s += a[c.i].count();
    }
}
void revoke(cmd c)
{
    if (c.op <= 2)
    {
        c.op = 3 - c.op;
    }
    perform(c);
}
void dfs(ll u)
{
    k[u] = s;
    // cout << "k:" << u << ' ' << k[u] << '\n';
    for (auto [v, cm] : g[u])
    {
        perform(cm);
        dfs(v);
        revoke(cm);
        // cout << "revoke: " << s << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m >> q;
    for (ll i = 1; i <= m; ++i)
    {
        rv[i] = 1;
    }
    for (ll i = 1; i <= q; ++i)
    {
        fa[i] = i;
    }
    for (ll u = 0, v = 1; v <= q; ++v)
    {
        cmd cm;
        cin >> cm.op >> cm.i;
        if (cm.op <= 2)
        {
            cin >> cm.j;
        }
        if (cm.op == 4)
        {
            u = cm.i;
            fa[findf(v)] = findf(u);
            continue;
        }
        g[findf(u)].push_back({v, cm});
        u = v;
    }
    dfs(0);
    for (ll i = 1; i <= q; ++i)
    {
        cout << k[findf(i)] << '\n';
    }
    return 0;
}
```

##### G CF709D

打表找规律，一个参考打表程序如下：

> ```c++
> #include <bits/stdc++.h>
> using namespace std;
> using ll = long long;
> const ll mn = 1e6 + 10;
> ll a[mn], top;
> map<pair<ll, ll>, set<pair<ll, ll>>> m;
> signed main()
> {
>  ios::sync_with_stdio(false), cin.tie(0);
>  cin >> top;
>  for (ll i = 0; i < 1 << top; ++i)
>  {
>      for (ll j = 0; j < top; ++j)
>      {
>          a[j] = (i >> j) & 1;
>      }
>      ll a00 = 0, a01 = 0, a10 = 0, a11 = 0;
>      for (ll j = 0; j < top; ++j)
>      {
>          for (ll k = j + 1; k < top; ++k)
>          {
>              a00 += a[j] == 0 && a[k] == 0;
>              a01 += a[j] == 0 && a[k] == 1;
>              a10 += a[j] == 1 && a[k] == 0;
>              a11 += a[j] == 1 && a[k] == 1;
>          }
>      }
>      for (ll j = top - 1; j >= 0; --j)
>      {
>          cout << a[j];
>      }
>      cout << ' ' << a00 << ' ' << a01 << ' ' << a10 << ' ' << a11 << '\n';
>      m[{a00, a11}].insert({a01, a10});
>  }
>  for (auto [pr, s] : m)
>  {
>      cout << pr.first << ' ' << pr.second << " - " << s.size() << " : ";
>      for (auto [a01, a10] : s)
>      {
>          cout << '(' << a01 << ',' << a10 << ") ";
>      }
>      cout << '\n';
>  }
>  return 0;
> }
> ```

根据打表规律，发现有解必然满足：

1. $a_{00},a_{11}$ 的出现次数是 $C_{x}^2$。其中 $x$ 是 $0$ 或 $1$ 的数目。

   证明：共有 $x$ 个 $0$ 时，$00$ 的数目一定是 $C_x^2$，直接高中组合数学即可。对 $1$ 同理。

2. 设有 $n_0$ 个 $0$，$n_1$ 个 $1$，若 $n_0 > 0,n_1 > 0$，恒满足 $n_0n_1=a_{01}+a_{10}$。

   证明：一共有 $n_1$ 个 $1$，对每个 $1$，与每个 $0$，要么组成 $10$，要么组成 $01$，故每个 $1$ 贡献 $n_0$ 个 $a_{01}+a_{10}$，故共贡献 $n_0n_1$ 次。

根据第二个规律的证明过程，可以通过在 $n_0$ 个 $0$ 上不断插入 $1$ 构造得字符串，对每次构造，设要插入的 $1$ 的前面有 $u(0\le u\le n_0)$ 个 $0$，后面有 $v=n_0-u$ 个 $0$，则当前 $1$ 对 $a_{01}$ 贡献 $u$，对 $a_{10}$ 贡献 $v$。可以直接贪心，即设 $1$ 先最大地去凑 $a_{10}$，然后再最大地去凑 $a_{01}$。反过来地，若已知某个 $1$ 贡献分别为 $(u,n_0-u)$，也能确定它必然插入在第 $u$ 个 $0$ 后面。注意每个 $0$ 后面可以插入零到任意多个 $1$。设当前还差 $c_{01}$ 个 $a_{01}$ 贡献要凑，$c_{10}$ 个 $a_{10}$ 贡献要凑，有：

- 若 $c_{10}\ge n_{0}$，把 $1$ 插入到最前面(第 $1$ 个 $0$ 前边)，导致 $c_{01}$ 不变，$c_{10}$ 减少 $n_0$。
- 否则，$0\le c_{10} < n_0$，把 $1$ 插入到第 $c_{10}$ 个 $0$ 前边，导致 $c_{10}$ 清零，$c_{01}$ 减少 $n_0-c_{10}$。

不断如此构造，即可得到有解的目标字符串。

特判一些边界，如全 $0$ 全 $1$ 等，即可得解。 

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
map<ll, ll> m;
const ll mn = 1e6 + 10;
ll n, n0, n1, a00, a01, a10, a11;
ll cnt[mn];
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    for (ll x = 1; x * (x - 1) / 2 <= 2e9; ++x)
    {
        m[x * (x - 1) / 2] = x;
    }
    cin >> a00 >> a01 >> a10 >> a11;
    if (a00 == 0 && a11 == 0 && a01 == 0 && a10 == 0)
    {
        cout << 0;
        return 0;
    }
    if (m.find(a00) == m.end() || m.find(a11) == m.end())
    {
        cout << "Impossible";
        return 0;
    }
    n0 = m[a00], n1 = m[a11], n = n0 + n1;
    if (a11 == 0 && a01 == 0 && a10 == 0)
    {
        for (ll i = 0; i < n0; ++i)
        {
            cout << 0;
        }
        return 0;
    }
    if (a00 == 0 && a01 == 0 && a10 == 0)
    {
        for (ll i = 0; i < n1; ++i)
        {
            cout << 1;
        }
        return 0;
    }
    if (n0 * n1 != a01 + a10)
    {
        cout << "Impossible";
        return 0;
    }
    ll c01 = a01, c10 = a10;
    for (ll i = 0; i < n1; ++i)
    {
        ll p01, p10;
        if (c10 >= n0)
        {
            p10 = n0;
        }
        else
        {
            p10 = c10;
        }
        p01 = n0 - p10;
        cnt[p01]++;
        c10 -= p10, c01 -= p01;
    }
    for (ll i = 0; i < n0; ++i)
    {
        for (ll j = 0; j < cnt[i]; ++j)
        {
            cout << 1;
        }
        cout << 0;
    }
    for (ll j = 0; j < cnt[n0]; ++j)
    {
        cout << 1;
    }
    return 0;
}
```

##### D CF707E

> 一开始审题失误没看到关键点 $len < 2000$，且没剩多少时间了，所以没开。

[能过的代码参考](https://blog.csdn.net/dieyi9889/article/details/101867233)

一眼二维树状数组维护矩阵和。对条链，先将其点亮，对应到二维树状数组上有 $O(len\log n\log m)\approx n\log^2 n$ 的代价。然后遍历共 $O(n)$ 次 ask，每次查询该点亮的链对该**子矩阵**(注意不是对该询问)的贡献是多少，查询的复杂度是四次树状数组询问，$O(n)$ 次 ask 故也共 $O(n\log^2 n)$。然后再将该链删掉，即还原树状数组，反向操作，耗费 $O(n\log^2 n)$。共 $k$ 条链，每条都做一次，共 $O(n^2\log^2n)$ 的复杂度。<u>经过这样的预处理，使得每条链对每个子矩阵的贡献都存了下来。</u>(解题核心思路)

接下来顺序遍历询问，维护 bool 数组表示当前点亮的链来维护 switch。对每个 ask，再遍历一遍每条链的点亮状态，如果亮着，加上该子矩阵该链的值。这个过程是 $O(q+nk)=O(n^2)$ 的。

故总复杂度为 $O(n^2\log^2n)$。

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template <class T>
inline void read(T &x)
{
    Finish_read = 0;
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch))
    {
        if (ch == '-')
            f = -1;
        if (ch == EOF)
            return;
        ch = getchar();
    }
    while (isdigit(ch))
        x = x * 10 + ch - '0', ch = getchar();
    x *= f;
    Finish_read = 1;
}
template <class T>
inline void print(T x)
{
    if (x / 10 != 0)
        print(x / 10);
    putchar(x % 10 + '0');
}
template <class T>
inline void writeln(T x)
{
    if (x < 0)
        putchar('-');
    x = abs(x);
    print(x);
    putchar('\n');
}
template <class T>
inline void write(T x)
{
    if (x < 0)
        putchar('-');
    x = abs(x);
    print(x);
}
/*================Header Template==============*/
const int maxn = 2005;
int n, m, k, qcnt, q;
ll T[maxn + 50][maxn + 50];
int len[maxn];
int x[maxn][maxn], y[maxn][maxn], w[maxn][maxn];
int c[1000005], qx1[maxn], qy1[maxn], qx2[maxn], qy2[maxn];
bool change[maxn];
ll ans[maxn][maxn];
#define lowbit(x) x & (-x)
/*==================Define Area================*/
void Add(int x, int y, int w)
{
    for (int i = x; i <= maxn; i += lowbit(i))
    {
        for (int j = y; j <= maxn; j += lowbit(j))
        {
            T[i][j] += w;
        }
    }
}

ll Sum(int x, int y)
{
    ll res = 0;
    for (int i = x; i; i -= lowbit(i))
    {
        for (int j = y; j; j -= lowbit(j))
        {
            res += T[i][j];
        }
    }
    return res;
}

int main()
{
    read(n);
    read(m);
    read(k);
    for (int i = 1; i <= k; i++)
    {
        read(len[i]);
        for (int j = 1; j <= len[i]; j++)
        {
            read(x[i][j]);
            read(y[i][j]);
            read(w[i][j]);
        }
    }
    read(q);
    for (int i = 1; i <= q; i++)
    {
        char opt[2];
        scanf("%s", opt);
        if (opt[0] == 'A')
        {
            ++qcnt;
            read(qx1[qcnt]);
            read(qy1[qcnt]);
            read(qx2[qcnt]);
            read(qy2[qcnt]);
        }
        else
        {
            read(c[i]);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= len[i]; j++)
        {
            Add(x[i][j], y[i][j], w[i][j]);
        }
        for (int j = 1; j <= qcnt; j++)
        {
            ans[i][j] = Sum(qx2[j], qy2[j]) + Sum(qx1[j] - 1, qy1[j] - 1) - Sum(qx1[j] - 1, qy2[j]) - Sum(qx2[j], qy1[j] - 1);
        }
        for (int j = 1; j <= len[i]; j++)
        {
            Add(x[i][j], y[i][j], -w[i][j]);
        }
    }
    for (int i = 1, cnt = 1; i <= q; i++)
    {
        if (c[i])
        {
            change[c[i]] ^= 1;
        }
        else
        {
            ll res = 0;
            for (int j = 1; j <= k; j++)
            {
                if (!change[j])
                    res += ans[j][cnt];
            }
            printf("%lld\n", res);
            cnt++;
        }
    }
    return 0;
}
```

##### H CF709E

> 开始一眼以为统计方案数，所以跳了。

[参考](https://blog.csdn.net/xgc_woker/article/details/82957280)

以重心为根进行 DFS。维护子树大小，该点为根子树的最大和非严格次大子树大小。设 DFS 时选择移边的子树的大小是 $s$，将这条边移动到当前遍历的子树上。

对重心外的点，如果它不是最大子树，那么往下遍历该点时，若当前点的最大子树更大，更新 $s$。否则，它自己是最大子树，不能我挪我自己，所以若当前点的非严格次大子树更大，更新 $s$。

如果有 $s$，当前子树大小是 $t$，因为从重心开始遍历，所以 $t$ 肯定不超，然后子树外部分大小是 $n-t$，如果把那个可删的最大子树 $s$ 给锯掉，连到自己上去，发现能成为重心，就可行。否则不可行。

如果一开始 DFS 根下来第一次就选定了 $s$，容易得知不会再更新 $s$。否则，一开始选的严格次大的话，有可能更新当前的新子树为 $s$，但绝无可能再把原重心那边的更新过来，因为如果包含重心的子树，必然是大于一半个节点树的。所以接下来的更新只需要在 $s$ 子树内考虑即可，且只需要考虑最大子树，看看有没有大于最开始给的非严格次大即可。

参考：

```c++
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
int _min(int x, int y) { return x < y ? x : y; }
int _max(int x, int y) { return x > y ? x : y; }
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * f;
}

struct edge
{
    int x, y, next;
} e[810000];
int len, last[410000];
int n, mx1[410000], mx2[410000], bs[410000];
int tot[410000], ans[410000];

void ins(int x, int y)
{
    e[++len].x = x, e[len].y = y;
    e[len].next = last[x], last[x] = len;
}

void dfs(int x, int fa)
{
    tot[x] = 1;
    mx1[x] = mx2[x] = bs[x] = 0;
    for (int k = last[x]; k; k = e[k].next)
    {
        int y = e[k].y;
        if (y != fa)
        {
            dfs(y, x);
            tot[x] += tot[y];
            if (tot[y] > n / 2)
                bs[x] = tot[y]; // 不满足重心的一个子树
            else if (tot[y] > mx1[x])
                mx2[x] = mx1[x], mx1[x] = tot[y];
            else if (tot[y] > mx2[x])
                mx2[x] = tot[y];
        }
    }
    if (n - tot[x] > n / 2)
        bs[x] = n - tot[x];
    else if (n - tot[x] > mx1[x])
        mx2[x] = mx1[x], mx1[x] = n - tot[x];
    else if (n - tot[x] > mx2[x])
        mx2[x] = n - tot[x];
}

void dfs2(int x, int fa, int s)
{
    if (!bs[x])
        ans[x] = 1;
    else if (n - tot[x] - s <= n / 2)
        ans[x] = 1;
    for (int k = last[x]; k; k = e[k].next)
    {
        int y = e[k].y;
        if (y != fa)
        {
            if (mx1[x] != tot[y])
                dfs2(y, x, _max(s, mx1[x]));
            else
                dfs2(y, x, _max(s, mx2[x]));
        }
    }
}

int main()
{
    n = read();
    for (int i = 1; i < n; i++)
    {
        int x = read(), y = read();
        ins(x, y), ins(y, x);
    }
    dfs(1, 0); // 找重心
    int rt;
    for (int i = 1; i <= n; i++)
    {
        if (!bs[i])
        {
            rt = i;
            break;
        }
    }
    dfs(rt, 0); // 重心为根,重新维护最大和次大子树
    dfs2(rt, 0, 0);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}
```

#### CCPC2023网络赛热身赛

原题：[2021CCPC女生赛](https://codeforces.com/gym/103389)，分别是K,B,H,J

- A 签到
- B 倍增
- C 半平面交
- D 树上DP

##### 音乐游戏

签。略。赛时忘了 getline 语法懒得去翻，所以写了 C 风格，然后 < 写成 <= debug 了五分钟左右：

```c++
#include <bits/stdc++.h>
using namespace std;
signed main()
{
    int n;
    char nth;
    scanf("%d%c",&n,&nth);
    int cnt = 0;
    for(int h=0;h<n;++h){
        char c;
        for(int i=0;i<6;++i){
            scanf("%c",&c);
            if(c=='-'){
                ++cnt;
            }
            //printf("[%c]",c);
        }
        //printf("Done %d %d\n", h,n);
        if(h+1<n){
            scanf("%c",&nth);
        }
    }
    cout << cnt << '\n';
    return 0;
}
```

##### 攻防演练

> 我的思路：通过暴力程序，找出未证明的规律，若一个串能找到 $t$ 个长为 $m$ 的 $A-M$ 的序列排列为子序列的串，那么答案为 $t+1$。例如对 $m=3$，`abcacb` 是 $k=3$，同理 `abbcaaaacacb` 也是 $k=3$，而 `abbcca` 只能是 $k=2$。然后发现对 $q$ 次询问做不到，我的复杂度无论如何只能 $O(nq)$。莫队不会回滚，ST/线段树/前缀和/DP 不会实现。

预处理出在下标 $i$ 处<u>的下个位置</u>到后面出现的首个第 $j$ 个字母的下标 $nxt_{i,j}$，可以 $O(nm)$ 处理。

定义 $f_{i,0}=\max_{j=0}^mnxt_{i,j}$，即包含 $A\sim M$ 的全体字符的子序列的最后一个字符所在。做倍增，定义 $f_{i,j}$ 表示包含 $2^j$ 个这样的子序列的最后一个字符所在，显然 $f_{i,j}=f_{f_{i,j-1},j-1}$。

长为 $k+1$ 的任意串都不是 $s_{l,r}$ 的子序列时，那么长为 $k$ 的是子序列，这表明从 $l-1$ 开始跳 $k$ 次能跳到。所以在跳完不超过 $r$ 的情况下跑倍增不断跳，输出 $k+1$ 即可。

暴力找出来的规律的具体原理：$k$ 长都匹配，即有长为 $k$ 的通配符。每个通配符具体到上面即一个 $f_{i,0}$ 的跨度

[参考](https://blog.csdn.net/kaka03200/article/details/121098182)

```c++
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
const ll inf = 1e18;
const int N = 2e5 + 10;
const int M = 1e6 + 10;
const double eps = 1e-8;
const int mod = 998244353;

#define fi first
#define se second
#define re register
#define lowbit (-x&x)
#define endl '\n'
int n, m;
char s[N];
int nxt[N][26];
int f[N][20];
int pos[26];
void solve() {
    cin >> m >> n;
    cin >> (s + 1);
    for (int i = 0; i < 26; i++) nxt[n][i] = n + 1;
    for (int i = n; i >= 1; i--) {
        if (!pos[s[i]-'a']) nxt[i][s[i]-'a'] = n + 1;
        else nxt[i][s[i]-'a'] = pos[s[i]-'a'];
        pos[s[i]-'a'] = i;
        for (int j = 0; j < m; j++) {
            if (pos[j]) nxt[i-1][j] = pos[j];
            else nxt[i-1][j] = n + 1;
        }
    }
    for (int i = 0; i <= n; i++) {
        int ma = 0;
        for (int j = 0; j < m; j++) ma = max(ma, nxt[i][j]);
        f[i][0] = ma;
        for (int j = 0; j < 20; j++) f[n+1][j] = f[n][j] = n + 1;
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i <= n; i++) {
            f[i][j] = f[f[i][j-1]][j-1];
//            if (!i) cout << f[i][j] << ' ' << f[i][j-1] << ' ' << j-1 << endl;
        }
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r;
        int ans = 0;
        int now = l - 1;
        for (int i = 19; ~i; i--) {
            if (f[now][i] <= r) {
                ans += (1 << i);
                now = f[now][i];
            }
        }
        printf("%d\n", ans+1);
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifdef ACM_LOCAL
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif

#ifdef ACM_LOCAL
    auto start = clock();
#endif
    int t = 1;
//    cin >> t;
    while (t--)
        solve();
#ifdef ACM_LOCAL
    auto end = clock();
    cerr << "Run Time: " << double(end - start) / CLOCKS_PER_SEC << "s" << endl;
#endif
    return 0;
}
```

##### 4G网络

[参考](https://codeforces.com/gym/103389/attachments/download/16594/2021CCPC%E5%A5%B3%E7%94%9F%E8%B5%9B%E9%A2%98%E8%A7%A3.pdf) 直接看官方题解，很清晰。超出能力不补。

##### 最大权边独立集

> 枚举位于答案边集的加入的边的数量 $t$，显然 $0\le t\le k$，因为独立集的定义故 $2t\le n$。加入 $t$ 条边等价于删掉 $2t$ 个点，则这 $t$ 条边贡献 $tp$，剩下的图再求一个最大权边独立集。
>
> 设 $f_{i,j,0}$ 表示 $i$ 为根的子树，子树删了 $j$ 个点，不能往上匹配时的答案，$1$ 是能网上匹配。枚举 $j$ 从 $0$ 到 $\min(size_x,k)$。
>
> 没有代码，看不懂 DP。



#### 未分类

目录：

1. CF367C-Hard problem

   DP/最短路

2. CF861B-Playing in a Casino

   枚举优化 排序

3. -Division

   质因数分解

4. codeton4-D Climbing the Tree

   思维 数学 讨论

##### CF367C-Hard problem

[题目](https://codeforces.com/contest/706/problem/C)

每个位置至于前后位置的选择有关。不妨建图，每个字符串有转与不转两种选择，分别连向前后转与不转，然后标上旋转代价，注意不要重复贡献(wa了一发)，然后图上拓扑DP/最短路即可。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 2e5 + 10, big = 1e16;
vector<pair<ll, ll>> g[mn];
ll n, c[mn], t;
string s[mn];
ll d[mn];
bool vis[mn];
struct node
{
    ll i, d;
    bool operator<(const node &o) const { return d > o.d; }
};
priority_queue<node> q;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> c[i];
    }
    for (ll i = 1; i <= n; ++i)
    {
        cin >> s[i];
    }
    t = 2 * n + 1;
    g[0].push_back({1, 0});
    g[0].push_back({2, c[1]});
    for (ll i = 1; i < n; ++i)
    {
        string &sa = s[i], &sb = s[i + 1];
        string ta = sa, tb = sb;
        reverse(ta.begin(), ta.end());
        reverse(tb.begin(), tb.end());
        ll ua = 2 * i - 1, va = 2 * i, ub = 2 * i + 1, vb = 2 * i + 2;
        if (sa <= sb)
        {
            g[ua].push_back({ub, 0});
        }
        if (sa <= tb)
        {
            g[ua].push_back({vb, c[i + 1]});
        }
        if (ta <= sb)
        {
            g[va].push_back({ub, 0});
        }
        if (ta <= tb)
        {
            g[va].push_back({vb, c[i + 1]});
        }
    }
    g[2 * n - 1].push_back({t, 0});
    g[2 * n].push_back({t, 0});
    for (ll i = 1; i <= t; ++i)
    {
        d[i] = big;
    }
    q.push({0, 0});
    while (!q.empty())
    {
        node p = q.top();
        q.pop();
        ll u = p.i;
        if (vis[u])
        {
            continue;
        }
        vis[u] = true;
        for (auto [v, w] : g[u])
        {
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({v, d[v]});
            }
        }
    }
    if (d[t] >= big)
    {
        cout << -1;
    }
    else
    {
        cout << d[t];
    }
    return 0;
}
/*
2
1 2
ba
ac

3
1 3 1
aa
ba
ac

2
5 5
bbb
aaa

2
3 3
aaa
aa

4
0 0 8 6
bi
qp
bt
ya
*/
```

##### CF861B-Playing in a Casino

[题目](https://codeforces.com/contest/1808/problem/B)

按列排序后，可以去掉绝对值，那么对同一个被减数，减数是前缀和。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mn = 3e5;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> a(m + 1, vector<ll>(n + 1));
        vector<vector<ll>> s(m + 1, vector<ll>(n + 1));
        for (ll i = 1; i <= n; ++i)
        {
            for (ll j = 1; j <= m; ++j)
            {
                cin >> a[j][i];
            }
        }
        for (ll i = 1; i <= m; ++i)
        {
            sort(a[i].begin(), a[i].end());
            for (ll j = 1; j <= n; ++j)
            {
                s[i][j] = a[i][j] + s[i][j - 1];
            }
        }
        ll ans = 0;
        for (ll i = 1; i <= m; ++i)
        {
            for (ll j = 1; j < n; ++j)
            {
                ans += (s[i][n] - s[i][j]) - a[i][j] * (n - j);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
```



##### Division

[题目]()

> 显然不可以对 $p$ 朴素质因数分解(pollard rho 也许可以？但我没成功，对一些数据卡到 TLE 了)。

对 $q$ 质因数分解，则要满足条件必然对所有 $q$ 的组成质数 $mq^{t_i}_i$，如果 $p$ 也有该质数 $mq_{i}^{t'_i}$，若对想要构造的 $x$，其必然 $t'$都是 $p$ 的子集，且满足 $t'_i < t'_i$。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll p, q;
        cin >> p >> q;
        map<ll, ll> mq;
        {
            ll x = q;
            for (ll i = 2; i * i <= x; ++i)
            {
                while (x % i == 0)
                {
                    ++mq[i];
                    x /= i;
                }
            }
            if (x > 1)
            {
                mq[x] = 1;
            }
        }
        ll r = 1;
        if (p % q)
        {
            r = p;
        }
        for (auto [p_, t_q] : mq)
        {
            ll x = p, t_p = 0;
            while (x % p_ == 0)
            {
                t_p++;
                x /= p_;
            }
            if (t_p >= t_q)
            {
                ll new_r = p;
                for (ll i = 0; i < t_p - t_q + 1; ++i)
                {
                    new_r /= p_;
                }
                r = max(r, new_r);
            }
        }
        cout << r << '\n';
    }
    return 0;
}
/*
2
1 998244353
6 580
*/
```



##### codeton4-D Climbing the Tree

[题目](https://codeforces.com/contest/1810/problem/D)

对 $(a,b,n)$ 可以确定唯一的可能高度区间 $[a(n-1)-b(n-2)+1,an-b(n-1)]$ (特判 $n=1$ 为 $[1,a]$)。对每个新的 $(a,b,n)$，如果与原有的区间不相交，不合法，否则，取重复区间。

对询问 $(a,b)$，设已知高度为 $h$，则最少需要 $an-b(n-1)\ge h$ 天，解得 $n=\lceil\dfrac{h-b}{a-b}\rceil$，特判 $h\le a$ 为 $1$ 天。对区间两个端点分别计算出 $n$，如果 $n$ 一致，输出，否则说不知道。

单次操作复杂度 $O(1)$。

```c++
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pr = pair<ll, ll>;
const ll inf = 5e18;
bool intersect(pr x, pr y)
{
    return !(x.second < y.first || y.second < x.first);
}
/*
cout << intersect({1, 3}, {4, 6}) << '\n';
cout << intersect({4, 6}, {1, 3}) << '\n';
cout << intersect({2, 3}, {1, 4}) << '\n';
cout << intersect({1, 4}, {2, 3}) << '\n';
cout << intersect({1, 10}, {10, 11}) << '\n';
cout << intersect({10, 11}, {1, 10}) << '\n';
cout << intersect({4, 7}, {5, 7}) << '\n';
cout << intersect({5, 7}, {4, 7}) << '\n';
cout << intersect({4, 7}, {5, 8}) << '\n';
cout << intersect({5, 8}, {4, 7}) << '\n';
*/
pr combine(pr x, pr y)
{
    return {max(x.first, y.first), min(x.second, y.second)};
}
ll cei(ll a, ll b)
{
    return (a + b - 1) / b;
}
pr rng(ll a, ll b, ll n)
{
    if (n == 1)
    {
        return {1, a};
    }
    return {a * (n - 1) - b * (n - 2) + 1, a * n - b * (n - 1)};
}
ll minday(ll a, ll b, ll h)
{
    if (h <= a)
    {
        return 1;
    }
    return cei(h - b, a - b);
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        pr eff = {0, inf};
        ll q;
        cin >> q;
        while (q--)
        {
            ll cmd, a, b, n;
            cin >> cmd >> a >> b;
            if (cmd == 1)
            {
                cin >> n;
                pr nw = rng(a, b, n);
                if (intersect(eff, nw))
                {
                    cout << "1 ";
                    eff = combine(eff, nw);
                }
                else
                {
                    cout << "0 ";
                }
            }
            else
            {
                ll l = minday(a, b, eff.first);
                ll r = minday(a, b, eff.second);
                if (l == r)
                {
                    cout << l << ' ';
                }
                else
                {
                    cout << "-1 ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}
```

### 其他杂题

#### ATC

##### DP-V-Subtree

[题目](https://atcoder.jp/contests/dp/tasks/dp_v?lang=en) [题解](https://blog.csdn.net/Emm_Titan/article/details/123875298)

$f$ 维护自己往下的子树数，$g$ 维护自己往上的子树数，答案是 $fg$。

转移时要用除法，但模数不是质数，所以将其转化为前后缀积乘法。

```c++
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define maxn 100005
vector < int > pre[maxn], suf[maxn];
vector < int > G[maxn];
int f[maxn], g[maxn];
int n, mod;
void dfs1( int u, int fa ) {
	f[u] = 1;
	for( int v : G[u] )
		if( v == fa ) continue;
		else dfs1( v, u ), f[u] = f[u] * (f[v] + 1) % mod;
	pre[u].resize( G[u].size() + 1, 1 );
	suf[u].resize( G[u].size() + 1, 1 );
	for( int i = 1;i < G[u].size();i ++ ) {
		pre[u][i] = pre[u][i - 1];
		if( G[u][i - 1] ^ fa ) 
			pre[u][i] = pre[u][i] * (f[G[u][i - 1]] + 1) % mod;
	}
	for( int i = G[u].size() - 2;i >= 0;i -- ) {
		suf[u][i] = suf[u][i + 1];
		if( G[u][i + 1] ^ fa )
			suf[u][i] = suf[u][i] * (f[G[u][i + 1]] + 1) % mod;
	}
}
void dfs2( int u, int fa ) {
	for( int i = 0;i < G[u].size();i ++ ) {
		int v = G[u][i];
		if( v == fa ) continue;
		g[v] = pre[u][i] * suf[u][i] % mod * g[u] % mod + 1;//加1是父亲代表的子树全为白 
		dfs2( v, u );
	}
}
signed main() {
	scanf( "%lld %lld", &n, &mod );
	for( int i = 1, u, v;i < n;i ++ ) {
		scanf( "%lld %lld", &u, &v );
		G[u].push_back( v );
		G[v].push_back( u );
	}
	dfs1( 1, 0 );
	g[1] = 1;
	dfs2( 1, 0 );
	for( int i = 1;i <= n;i ++ ) printf( "%lld\n", g[i] * f[i] % mod );
	return 0;
}
```

