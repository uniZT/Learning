# 回溯算法part05
## * 491.递增子序列
## * 46.全排列
## * 47.全排列 II



### 要注意的点


### 491.递增子序列
https://leetcode.cn/problems/non-decreasing-subsequences/

给你一个整数数组 nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按 任意顺序 返回答案。

数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。



=====
```c++
private:
//同层元素重复的元素不会重复使用6,7,6,7,8中，同层7只使用一次
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        //要求最小2个
        if(path.size() > 1){
            result.push_back(path);
            //这里不要return，树还可以往下走
        }
        
        unordered_set<int> uset;
        for(int i = startIndex; i < nums.size(); i++){
            if(!path.empty() && nums[i] < path.back()|| uset.find(nums[i]) != uset.end()){
                continue;   //不符合条件就下一个
            }
            uset.insert(nums[i]);
            path.push_back(nums[i]);
            backtracking(nums, i+1);    //往深处走
            path.pop_back();
        }
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
```

----
### 46.全排列
https://leetcode.cn/problems/permutations/description/

给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

=====
```c++
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
```

-----
### 
https://leetcode.cn/problems/permutations-ii/

给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

=====
```c++
private:
    vector<vector<int>> result;
    vector<int> path;
    //used是排序号的
    void backtracking(vector<int>& nums, vector<bool>& used){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            //最后一项不管是true还是false都可以，但是false是层，true是树枝
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;
            }
            //当这个没有被用过的时候，才会继续，否则跳过
            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        result.clear();
        path.clear();
        sort(nums.begin(), nums.end()); // 排序
        vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
```
-----
### 


=====

