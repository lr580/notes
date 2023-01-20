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
