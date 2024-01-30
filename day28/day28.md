# 回溯算法part04
## ● 93.复原IP地址
## ● 78.子集
## ● 90.子集II


### 要注意的点


### 93.复原IP地址


=====
```c++
private:
    vector<string> result;
    bool isValid(const string& s, int start, int end){
        if(start > end){
            return false;
        }
        if(s[start] == '0' && start != end){
            return false;
        }
        int num = 0;
        for(int i = start; i <= end; i++){
            if(s[i] > '9' || s[i] < '0') return false;
            num = num * 10 + (s[i] - '0');
            if(num > 255) return false;
        }
        return true;
    }
    void backtracking(string& s, int startIndex, int pointNum){
        if(pointNum == 3){
            if(isValid(s, startIndex, s.size() - 1)){
                result.push_back(s);
            }
            return;
        }
        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');
                pointNum++;
                backtracking(s, i + 2, pointNum);   //插入了逗号+2
                pointNum--;                 //回溯
                s.erase(s.begin() +i + 1);  //删掉逗号
            }
            else break;
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        result.clear();
        if (s.size() < 4 || s.size() > 12) return result; // 剪枝
        backtracking(s, 0, 0);
        return result;
    }
```



----
### 78.子集
https://leetcode.cn/problems/subsets/description/

给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

=====
```c++
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        if(startIndex > nums.size()) return;
        result.push_back(path);
        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums, 0);
        return result;
    }
```

-----
### 90.子集II
https://leetcode.cn/problems/subsets-ii/

给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

=====
```c++
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used){
        result.push_back(path);
        for(int i = startIndex; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end()); // 去重需要排序
        backtracking(nums, 0, used);
        return result;
    }
```

