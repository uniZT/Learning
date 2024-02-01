# 贪心算法 part01
## ● 455.分发饼干
## ● 376. 摆动序列
## ● 53. 最大子序和



### 要注意的点


### 455.分发饼干
https://leetcode.cn/problems/assign-cookies/description/

假设你是一位很棒的家长，想要给你的孩子们一些小饼干。但是，每个孩子最多只能给一块饼干。

对每个孩子 i，都有一个胃口值 g[i]，这是能让孩子们满足胃口的饼干的最小尺寸；并且每块饼干 j，都有一个尺寸 s[j] 。如果 s[j] >= g[i]，我们可以将这个饼干 j 分配给孩子 i ，这个孩子会得到满足。你的目标是尽可能满足越多数量的孩子，并输出这个最大数值。

 
=====

就是小饼干给吃的少的，不行就下一个饼干，可以就下一个小朋友下一个饼干
```c++
int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int result = 0;
        for(int childIndex = 0, cakeIndex = 0; childIndex < g.size() && cakeIndex < s.size();){
            if(g[childIndex] <= s[cakeIndex]){
                result++;
                childIndex++;
                cakeIndex++;
            }
            else{
                cakeIndex++;
            }
        }
        return result;
    }
```



----
### 376. 摆动序列
https://leetcode.cn/problems/wiggle-subsequence/

给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。

=====

```c++
int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int curDiff = 0;
        int preDiff = 0;
        int result = 1;
        for(int i = 0; i < nums.size() - 1; i++){
            curDiff = nums[i + 1] - nums[i];
            if((curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0)){
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
```

-----
### 
https://leetcode.cn/problems/maximum-subarray/description/

给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

=====
```c++
int maxSubArray(vector<int>& nums) {
        int result = INT32_MIN;
        int count = 0;
        for(int i = 0; i < nums.size(); i++){
            count += nums[i];
            if(count > result){
                result = count;
            }
            if(count < 0){
                count = 0;
            }
        }
        return result;
    }
```


