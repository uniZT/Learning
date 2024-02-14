# 动态规划part04
## ● 01背包问题，你该了解这些！
## ● 416. 分割等和子集


### 要注意的点


### 01背包问题
dp[i][j]为最大价值

[0, i]的物品任意取，放进容量为j的背包里

之后可以优化成一维dp数组，一维滚动数组

1.一维数组dp[j]，容量为j的背包所能装的最大价值

2.递推公式：
```
    dp[j] = max( dp[j]（不放物品i） , dp[j - weight[i]] + value[i]（放物品i） )
    dp[j - weight[i]]的意思是：放物品i，把i的重量减下去，即背包被消耗掉了；+ value[i] 再加上i的价值
```
3.初始化：
```
    dp[0] = 0   背包容量为0所能装的也是0
    其他也都是0   
```

4.遍历顺序
```
第一重for循环遍历物品
第二重for循环倒序遍历背包，保证每个物品只被添加过一次
for(i = 0; i < 物品数量; i++){
    for(j = 背包初始容量; j >= weight[i]; j--){
        递推公式
    }
}
```

=====




----
### 416. 分割等和子集


=====
```c++
bool canPartition(vector<int>& nums) {
        //本题里面，value和weight都当做相同的数
        vector<int> dp(10001, 0);
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2 == 1) return false;
        sum /= 2;

        for(int i = 0; i < nums.size(); i++){
            for(int j = sum; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[sum] == sum)   return true;
        return false;
    }
```




