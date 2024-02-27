# 动态规划part07
## ● 70. 爬楼梯 （进阶）
## ● 322. 零钱兑换
## ● 279.完全平方数


### 要注意的点


### 70. 爬楼梯 （进阶）


=====




----
### 322. 零钱兑换
https://leetcode.cn/problems/coin-change/description/

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

=====
```c++
int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++){
            for (int j = coins[i]; j <= amount; j++){
                if (dp[j - coins[i]] != INT_MAX){ // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
                }
            }
        }
        if (dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
```

-----
### 279.完全平方数
https://leetcode.cn/problems/perfect-squares/

给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

=====
```c++
int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i <= n; i++){
            for (int j = 1; j * j <= i; j++){
                dp[i] = min(dp[i - j * j] + 1, dp[i]);
            }
        }
        return dp[n];
    }
```

