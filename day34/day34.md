# 贪心算法 part03
## ● 1005.K次取反后最大化的数组和
## ● 134. 加油站
## ● 135. 分发糖果

### 要注意的点
sort函数重构排序函数

for(int i : nums)   //vector<int> nums

这个时候i是nums[i],不要搞错了


### 1005.K次取反后最大化的数组和
https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/

给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。

=====
```c++
int largestSumAfterKNegations(vector<int>& nums, int k) {
        int result = 0;
        sort(nums.begin(), nums.end(), cmp);
        //让abs大的尽量为正
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 && k > 0){
                nums[i] = -nums[i];
                k--;
            }
        }
        //处理完之后，如果k还大于0，不停翻转abs最小的元素，如果k为偶数，其实没有变化
        if(k % 2 == 1){
            //翻转可以这样写
            nums[nums.size() - 1] *= -1;
        }
        for(int i : nums){
            result += i;
        }
        return result;
    }
```



----
### 134. 加油站
https://leetcode.cn/problems/gas-station/

在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。

你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。

给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。

=====
```c++
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0;
        int curSum = 0;
        int totalSum = 0;
        for(int i = 0; i < gas.size(); i++){
            curSum = curSum + gas[i] - cost[i];
            totalSum = totalSum + gas[i] - cost[i];
            if(curSum < 0){
                start = i + 1;
                curSum = 0;
            }
        }
        if(totalSum < 0) return -1;
        return start;
    }
```

-----
### 


=====
```c++
int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(), 1);
        //从左到右
        for(int i = 1; i < ratings.size(); i++){
            if(ratings[i] > ratings[i - 1]){
                candy[i] = candy[i - 1] + 1;                //这里就是比前一个大
            }
        }
        //从右到左
        for(int i = ratings.size() - 2; i >=0; i--){
            if(ratings[i] > ratings[i + 1]){
                candy[i] = max(candy[i + 1] + 1, candy[i]); //这里要选两个里更大的一个
            }
        }
        int result = 0;
        for(int i : candy){
            result += i;
        }
        return result;
    }
```
