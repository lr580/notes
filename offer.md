面试准备笔记。

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

可以滚动一下优化空间常数。则时间复杂度 $O(|s|\cdot |p|)$，空间复杂度 $O(|p|)$。d

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





> ### 力扣比赛
>

#### 周赛327

vp成绩：

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

