# 动态规划 part05
## ● 1049. 最后一块石头的重量 II
## ● 494. 目标和 这个不会
## ● 474.一和零


### 要注意的点
dp[j] = max( dp[j]（不放物品i） , dp[j - weight[i]] + value[i]（放物品i） )

### 1049. 最后一块石头的重量 II
https://leetcode.cn/problems/last-stone-weight-ii/

有一堆石头，用整数数组 stones 表示。其中 stones[i] 表示第 i 块石头的重量。

每一回合，从中选出任意两块石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：

如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块 石头。返回此石头 最小的可能重量 。如果没有石头剩下，就返回 0。

=====
```c++
int lastStoneWeightII(vector<int>& stones) {
        //100 * 30 = 3000, 3000 / 2 = 1500这是最大的情况,100 30都是题中给的
        vector<int> dp(1501, 0);
        int sum = 0;
        for(int i = 0; i < stones.size(); i++){
            sum += stones[i];
        }
        int target = sum / 2;
        for(int i = 0; i < stones.size(); i++){
            for(int j = target; j >= stones[i]; j--){
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[target] - dp[target];
    }
```



----
### 494. 目标和 这个不会
https://leetcode.cn/problems/target-sum/

=====
```c++
int findTargetSumWays(vector<int>& nums, int target) {
        //假设加法的总和为x，那么减法对应的总和就是sum - x
        //x - (sum - x) = target
        //x = (target + sum) / 2
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(abs(target) > sum) return 0;
        if((target + sum) % 2 == 1)return 0;

        int bagSize = (target + sum) / 2;
        vector<int> dp(bagSize + 1, 0);
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = bagSize; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[bagSize];
    }
```

-----
### 474.一和零
https://leetcode.cn/problems/ones-and-zeroes/

=====
```c++
int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for(string str : strs){
            int oneNum = 0, zeroNum = 0;
            for(char c : str){
                if(c == '0') zeroNum++;
                else oneNum++;
            }
            for(int i = m; i >= zeroNum; i--){
                for(int j = n; j >= oneNum; j--){
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
```

