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

