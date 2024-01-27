# 回溯算法part02
## ● 216.组合总和III
## ● 17.电话号码的字母组合



### 要注意的点


### 216.组合总和III
https://leetcode.cn/problems/combination-sum-iii/

找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：

只使用数字1到9
每个数字 最多使用一次
返回 所有可能的有效组合的列表 。该列表不能包含相同的组合两次，组合可以以任何顺序返回。

=====
```c++
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(int k, int n, int sum, int startIndex){
        //剪枝
        if(sum > n) return;

        if(path.size() == k){
            if(sum == n) result.push_back(path);
            return;
        }
        for(int i = startIndex; i <= 9 - (k - path.size()) + 1; i++){
            sum += i;
            path.push_back(i);
            backtracking(k, n, sum, i + 1);
            sum -= i;   //回溯
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        path.clear();
        backtracking(k, n, 0, 1);
        return result;
    }
```



----
### 17.电话号码的字母组合
https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

=====
```c++
private:
    const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
    };
public:
    vector<string> result;
    string s;
    void backtracking(const string& digits, int index){
        //当index指向最后一个之后的位置上时，说明已经满了，送入结果
        if(index == digits.size()){
            result.push_back(s);
            return;
        }
        int digit = digits[index] - '0';    //index指向的string数字转换成int数字
        string letters = letterMap[digit];  //获取对应字符集
        for(int i = 0; i< letters.size(); i++){
            s.push_back(letters[i]);
            backtracking(digits, index + 1);
            s.pop_back();   //回溯
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();
        result.clear();
        if(digits.size() == 0){
            return result;
        }
        backtracking(digits, 0);
        return result;
    }
```

-----
### 


=====

-----
### 


=====

