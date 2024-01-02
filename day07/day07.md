## 哈希表part02
### 454.四数相加II  383. 赎金信  15. 三数之和  18. 四数之和


#### 454
https://leetcode.cn/problems/4sum-ii/description/

给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n

nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

=====

下面这个操作，在c++中，如果a+b不存在，那么它会自动insert,并且初始化为0

```c++
map[a + b]++;
```
具体的话，在day07_test里面可以运行

```c++
int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4) {
    unordered_map<int, int> map;
    int count = 0;
    //这里就不要用(;;)的循环了，有方便的实现
    for (int a: nums1) {
        for (int b: nums2) {
            map[a + b]++;   //如果a+b存在就加加，如果不存在，insert并初始化为0，再加加
        }
    }
    for (int c: nums3) {
        for (int d: nums4) {
            if (map.find(0 - c - d) != map.end()) {
                count += map[0 - c - d];
            }
        }
    }
    return count;
}
```

----
#### 383
https://leetcode.cn/problems/ransom-note/description/

给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。

如果可以，返回 true ；否则返回 false 。

magazine 中的每个字符只能在 ransomNote 中使用一次。
```c++
bool canConstruct(string ransomNote, string magazine) {
    int record[26] = {0};
    //先行判断，如果长度不对直接结束，减少时间
    if (ransomNote.size() > magazine.size()) {
        return false;
    }
    for (int i = 0; i < magazine.length(); i++) {
        record[magazine[i] - 'a']++;
    }
    for (int j = 0; j < ransomNote.length(); j++) {
        record[ransomNote[j] - 'a']--;
        
        if (record[ransomNote[j] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}
```

-----
#### 15
https://leetcode.cn/problems/3sum/description/
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
你返回所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。

这个题目出现在哈希表章节让人很容易想到要用哈希方法去解决，但是实际上哈希解法不仅时间复杂度高，而且去重复杂。

应该用双指针去解这道题，但是依旧要考虑去重问题
```c++
vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        //首先i在最左边，left从i右边一个位置开始，right从最右边开始
        for(int i = 0; i < nums.size(); i++){
            //当最左边都大于零，有序序列之和肯定不为0
            if(nums[i] > 0){
                return result;
            }
            //去重，i>0是为了从第二个才开始比，i和i-1而不是用i、i+1是因为left会在i+1位置上，要避免
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum > 0){
                    right--;
                }
                else if(sum < 0){
                    left++;
                }
                else{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    //去重
                    while(right > left && nums[right] == nums[right - 1]){
                        right--;
                    }
                    while(right > left && nums[left] == nums[left + 1]){
                        left++;
                    }
                    right--;
                    left++;
                }
            }

        }
        return result;
    }
```

-----
#### 18
https://leetcode.cn/problems/4sum/description/

给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n

a、b、c 和 d 互不相同

nums[a] + nums[b] + nums[c] + nums[d] == target

你可以按 任意顺序 返回答案 。

上一题的基础上，剪枝要改变，去重也要改变。

剪枝的话，target可能小于0，所以如果有[-4, -1, 0, 0] target = -5， 那么上题的剪枝会有错误的结果
```c++
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for(int k = 0; k < nums.size(); k++){
            //剪枝,就是这种情况之后，后面都不会有符合条件的结果了，跳出
            if(nums[k] > target && nums[k] >= 0){
                break;
            }
            //去重
            if(k > 0 && nums[k] == nums[k-1]){
                continue;
            }
            for(int i = k + 1; i < nums.size(); i++){
                //剪枝
                if(nums[i] + nums[k] > target && nums[i] + nums[k] >=0){
                    break;
                }
                if(i > k+1 && nums[i] == nums[i-1]){
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while(left < right){
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出，我没有考虑过
                    if((long)nums[k] + nums[i] + nums[left] + nums[right] > target){
                        right--;
                    }
                    else if((long)nums[k] + nums[i] + nums[left] + nums[right] < target){
                        left++;
                    }
                    else{
                        result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                        while(left < right && nums[right] == nums[right - 1]){
                            right--;
                        }
                        while(left < right && nums[left] == nums[left + 1]){
                            left++;
                        }
                        right--;
                        left++;
                    }
                }

            }
        }
        return result;
    }
```