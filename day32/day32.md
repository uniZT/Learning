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
### 55. 跳跃游戏
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
### 45.跳跃游戏II
https://leetcode.cn/problems/jump-game-ii/

给定一个长度为 n 的 0 索引整数数组 nums。初始位置为 nums[0]。

每个元素 nums[i] 表示从索引 i 向前跳转的最大长度。换句话说，如果你在 nums[i] 处，你可以跳转到任意 nums[i + j] 处:

0 <= j <= nums[i]

i + j < n

返回到达 nums[n - 1] 的最小跳跃次数。生成的测试用例可以到达 nums[n - 1]。

=====
```c++
int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;

        //当前覆盖的最远距离,第一步的时候当前只有0这个位置，第二步才会去到0+num[0]
        int cur = 0;

        //下一步覆盖的最远距离，初始值会被覆盖掉无所谓
        int next = 0;

        int result = 0;
        for(int i = 0; i < nums.size(); i++){
            //更新下一步的最远位置
            next = max(nums[i] + i, next);
            //如果当前已经到当前一步可以走的最远距离
            if(i == cur){
                //那么进入下一步
                result++;
                //更新当前最远距离
                cur = next;
                //如果当前最远距离可以到最后一个了，那就跳出去返回结果
                if(next >= nums.size() - 1) break;
            }
        }
        return result;
    }
```

