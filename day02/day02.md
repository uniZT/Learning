# day02
## 数组part02
### 977.有序数组的平方 209.长度最小的子数组 59.螺旋矩阵II
#### 977
https://leetcode.cn/problems/squares-of-a-sorted-array/description/

给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

暴力算法
```c++
vector<int> sortedSquares(vector<int>& nums) {
    for(int i = 0; i < nums.size(); i++){
        nums[i] *= nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
}
```
用空间换时间O(n)，用一个新的数组，原数组两边往中间遍历，大的先放在新数组右边，一直往左走
```c++
vector<int> sortedSquares2(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    for(int left = 0, right = n - 1, pivot = n - 1; left <= right;){    //这里要等于号不能只小于
        if(nums[left] * nums[left] > nums[right] * nums[right]){
            result[pivot--] = nums[left] * nums[left];
            left++;
        }
        else{
            result[pivot--] = nums[right] * nums[right];
            right--;
        }
    }
    return result;
}
```
------
#### 209
https://leetcode.cn/problems/minimum-size-subarray-sum/description/

给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

用滑动窗口解决问题
```
#include <cstdint>里面包含了INT32_MAX
```
```c++
int minSubArrayLen(int target, vector<int>& nums) {
    int result = INT32_MAX;     //最终结果用result保存
    int sum = 0;                //窗口内元素和
    int length = 0;             //窗口长度
    int begin = 0;              //窗口起始位置
    //end为窗口终止位置
    for(int end = 0; end < nums.size(); end++){
        sum += nums[end];                   //每次终止位置+1之后都要把它加上
        while(sum >= target){               //当窗口内元素之和大于等于目标值
            length = end - begin + 1;       //更新窗口长度
            result = min(result, length);   //最终结果，这个是为了当最后所有数加起来不满足条件设置的
            sum -= nums[begin++];           //窗口左边右移缩小
        }
    }
    return result == INT32_MAX ? 0:result;
}
```

#### 59
https://leetcode.cn/problems/spiral-matrix-ii/description/

给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
定义vector的二维数组：
```c++
vector<vector<int>> res(n, vector<int>(n, 0));
```
```c++
vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n,0));
        //循环次数是n/2，如果n为奇数，最后在中心位置添加最后一个数即可
        int loop = n / 2;
        int stratx = 0, starty = 0; //x是纵坐标，y是横坐标
        int mid = n / 2;            //最后的中间点的位置
        int count = 1;              //从1开始
        int offset = 1;             //偏移量，为了纠正最后在什么地方停下来
        int i,j;                    //i是行号，j是列号
        while(loop--){
            i = stratx;
            j = starty;
            //第i行，每一列遍历，第一个分号前的其实可以不要，因为在上面已经初始化了，但是这样看的更清楚
            //循环内的没什么好说的，就是简单的加1
            //关键是循环条件
            for(j = starty ;j < n - offset; j++){
                result[i][j] = count++;
            }
            //第一个分号的i赋值语句其实可以不要，上面已经赋值过了
            for(i = startx ;i < n - offset; i++){
                result[i][j] = count++;
            }
            for(;j > starty; j--){
                result[i][j] = count++;
            }
            for(;i>stratx;i--){
                result[i][j] = count++;
            }
            starty++;
            stratx++;
            offset++;
        }
        //其实下面不需要==1也可以的
        if(n%2==1){
            result[mid][mid] = count;
        }
        return result;
}
```