# 回溯算法part03
## ● 39. 组合总和
## ● 40.组合总和II
## ● 131.分割回文串



### 要注意的点


### 39. 组合总和
https://leetcode.cn/problems/combination-sum/description/

给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。

=====
```c++
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
        if(sum > target){
            return;
        }
        if(sum == target){
            result.push_back(path);
            return;
        }
        //这里要startIndex的原因是，会有2,2,3，但是不能有3,2,2
        for(int i = startIndex; i < candidates.size(); i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, target, sum, i);   //这里i不需要+1，因为可以重复取
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        backtracking(candidates, target, 0, 0);
        return result;
    }
```



----
### 40.组合总和II
https://leetcode.cn/problems/combination-sum-ii/

给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。

=====
```c++
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used){
        //@这个可以没有，但是下面for循环条件需要改变
        if(sum > target){
            return;
        }
        
        
        if(sum == target){
            result.push_back(path);
            return;
        }
        //@下面变成这个，上面就可以没有
        // for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++)
        for(int i = startIndex; i < candidates.size(); i++){
            if(i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false){
                continue;
            }
            path.push_back(candidates[i]);
            //used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            //used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            sum += candidates[i];
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used); //往深处去
            used[i] = false;    //往同层去，同层使用过
            sum -= candidates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        path.clear();
        result.clear();
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
```

-----
### 131.分割回文串
https://leetcode.cn/problems/palindrome-partitioning/

给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

=====
```c++
private:
    vector<vector<string>> result;
    vector<string> path;
    bool isPalindrome(const string& s,int start, int end){
        for(int i = start, j = end; i < j; i++, j--){
            if(s[i] != s[j]) return false;
        }
        return true;
    }

    void backtracking(const string& s, int startIndex){
        //终止条件，如果index已经大于size，说明找到了
        if(startIndex >= s.size()){
            result.push_back(path);
            return;
        }

        for(int i = startIndex; i < s.size(); i++){
            if(isPalindrome(s, startIndex, i)){
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
            }
            else{
                continue;
            }
            backtracking(s, i+1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s) {
        backtracking(s,0);
        return result;
    }
```


