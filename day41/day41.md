# 动态规划part03
## ● 343. 整数拆分
## ● 96.不同的二叉搜索树


### 要注意的点


### 343. 整数拆分
https://leetcode.cn/problems/integer-break/

=====

dp的定义是，dp[i]为数字i的最大乘积，也就是说应该从小到大计算

第一个有效的起点应该是dp[2],前面两个其实任何数都没关系

dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));

j * (i - j) 是单纯的把整数拆分为两个数相乘，而j * dp[i - j]是拆分成两个以及两个以上的个数相乘。
```c++
int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;  //2 = 1 + 1, 1*1=1
        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i/2; j++){
                dp[i] = max(dp[i], max(j * (i - j), dp[i - j] * j));
            }
        }
        return dp[n];
    }
```

----
### 96.不同的二叉搜索树
https://leetcode.cn/problems/unique-binary-search-trees/

给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

=====

假设有3个节点，

头为1 = 左子树（0节点） x 右子树（2节点）

头为2 = 左子树（1节点） x 右子树（1节点）

头为3 = 左子树（2节点） x 右子树（0节点）
```c++
dp[3] = dp[0] * dp[2] + dp[1] * dp[2] + dp[2] * dp[0]
```
整理出的递推公式是：

j为循环，j是头结点，左边有 j-1 个节点，头结点右边有 i-j 个节点
```c++
dp[i] = dp[j - 1] * dp[i - j]
```
```c++
//要先找出递推公式
//dp[i]如果为有i个节点种数
//上面有递推公式推导        
int numTrees(int n) {
    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            //j的意思是头结点是哪个节点
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}
```
