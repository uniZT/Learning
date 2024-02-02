# 贪心算法 part02
## ● 122.买卖股票的最佳时机II
## ● 55. 跳跃游戏
## ● 45.跳跃游戏II


### 要注意的点


### 122.买卖股票的最佳时机II
https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/

给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

=====

就是求向上走的所有段加起来
```c++
int maxProfit(vector<int>& prices) {
        int result = 0;
        for(int i = 1; i < prices.size(); i++){
            result += max(prices[i] - prices[i - 1], 0);
        }
        return result;
    }
```



----
### 
https://leetcode.cn/problems/jump-game/description/

给你一个非负整数数组 nums ，你最初位于数组的 第一个下标 。数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标，如果可以，返回 true ；否则，返回 false 。

=====
```c++
bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size() == 1) return true;
        for(int i = 0; i <= cover; i++){
//            if(i + nums[i] > cover){
//                cover = i + nums[i];
//            }
            //优化为
            cover = max(i + nums[i], cover);
            
            if(cover >= nums.size() - 1){
                return true;
            }
        }
        return false;
    }
```

-----
### 


=====

-----
### 


=====

