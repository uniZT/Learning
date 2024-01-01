## Part01数组
### 704二分查找 27移除元素 35 34


#### 704
https://leetcode.cn/problems/binary-search/

给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。


对于vector,要获取长度不要用sizeof()，而要用.size()

对于取mid，left + (right - left) / 2 才是防溢出正常方式

----
第一种写法是target在[left, right]的区间里，

所以left==right的情况是确实存在的，这也是我自己平常用的方法
```C++
int search1(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;    //用.size()，别用sizeof()
    while(left <= right){
        //int mid = (left + right) / 2;
        //这样不好，要注意防溢出
        int mid = left + (right - left) / 2;
        if(nums[mid] == target){
            return mid;
        }
        else if(nums[mid] > target){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return -1;
}
```
第二种写法是在一个[left, right)的左闭右开区间里，

那么只有left < right才是合法的
```c++
int search2(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();    //和上面-1区别
    while(left < right){        //在这里要left < right才是合法的范围
        int mid = left + (right - left) / 2;
        if(nums[mid] > target){
            right = mid;
        }
        else if(nums[mid] < target){
            left = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
}
```
----
#### 35
https://leetcode.cn/problems/search-insert-position/

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。

看到顺序应该考虑二分法

下面是最简单的复杂度为n的方法，遍历一次。二分法可以更快
```c++
int searchInsert(vector<int>& nums, int target) {
    for(int i = 0; i < nums.size(); i++){
        if(nums[i] >= target){
            return i;
        }        
    }
    return nums.size();
}
```
二分法
```c++
int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){     // 搞清楚边界条件，不能加等号的，
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return left;
}
//while那一段也可以变成这样，这样更好理解，也能通过测试
while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                return mid;
            }
}
```
-----

#### 34
https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/description/
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值 target，返回 [-1, -1]。
你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

就用二分法解决问题，但是要多一个左右边界，其实还是二分。

复杂一点的用官方解写一个函数。简单思路用下面的想法。
```c++
vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int first = -1;     //找不到会返回-1，初始先给个-1的值
        int last = -1;
        //分别两次二分
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                first = mid;        //这两行是为了让找到最左边的target
                right = mid - 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        left = 0;
        right = nums.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                last = mid;         //这两行是为了让找到最右边的target
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid -1;
            }
            else{
                left = mid + 1;
            }
        }
        return vector<int> {first, last};
    }
```

-----
#### 27
https://leetcode.cn/problems/remove-element/
https://programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html#%E6%80%9D%E8%B7%AF

给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

快慢指针法

左右指针，每次右指针必定向右移动。如果不碰到val，左右指针一起向右移动，并且把右的值给到左边。
如果碰到val的话，就只有右指针移动，跨过去。

实际上的原理就是右指针除了碰到val，都会把现在的值给左指针，相当于碰到的元素都往前挪，除了val以外。

```c++
int removeElement(vector<int> &nums, int val) {
    int slow = 0;
    for(int fast = 0; fast < nums.size(); fast++){
        if(val != nums[fast]){
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}
```
左右双指针法

左右往中间靠，右边碰到val才往左走，不然等左边去换
```c++
int removeElement2(vector<int> &nums, int val) {
    int left = 0;
    int right = nums.size() - 1;    //别忘了减1
    while(left <= right){
        // 找左边等于val的元素
        while(left <= right && nums[left] != val){
            left++;
        }
        // 找右边不等于val的元素
        while(left <= right && nums[right] == val){
            right--;
        }
        // 将右边不等于val的元素覆盖左边等于val的元素
        if(left < right){       //如果这里用了等号，left会多交换一次，导致长度出现问题
            nums[left++] = nums[right--];
        }
    }
    return left;
}
```