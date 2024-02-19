# 动态规划part01
## ● 509. 斐波那契数
## ● 70. 爬楼梯
## ● 746. 使用最小花费爬楼梯



### 要注意的点


### 509. 斐波那契数
https://leetcode.cn/problems/fibonacci-number/

=====
```c++
int fib(int n) {
        if(n < 2) return n;
        int dp[2] = {0, 1};
        //0,1,1,2,3,5
        //n=2时，<=才能进入循环进行处理
        for(int i = 2; i <= n; i++){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
```



----
### 70. 爬楼梯
https://leetcode.cn/problems/climbing-stairs/

假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

=====

实际上就是斐波那契数列

每一阶只能从，前一阶和再前一阶来
```c++
//1阶 1种
    //2阶 2种
    //3阶 1阶走两步，2阶走一步，1阶+2阶 3种
    //4阶只能有2或者3阶迈上来，2 + 3 = 5种
    int climbStairs(int n) {
        //从1阶才开始
        if(n - 1 < 2) return n;
        int dp[2] = {1, 2};
        for(int i = 3; i <= n; i++){
            int sum = dp[0] + dp[1];
            dp[0] = dp[1];
            dp[1] = sum;
        }
        return dp[1];
    }
```

-----
### 746. 使用最小花费爬楼梯
https://leetcode.cn/problems/min-cost-climbing-stairs/description/

给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。

=====

就是求上一步和上上步的最短距离加上他们跨上来的较短的距离
```c++
int minCostClimbingStairs(vector<int>& cost) {
        //dp[i]是到达i的最小距离，dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2])
        //即之前的 dp + 它跨上来的花费，更新为新的dp
        vector<int> dp(cost.size() + 1);
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i <= cost.size(); i++){
            dp[i] = min(cost[i - 1] + dp[i - 1], cost[i - 2] + dp[i - 2]);
        }
        return dp[cost.size()];
    }
```

