# 动态规划part15
## ● 392.判断子序列
## ● 115.不同的子序列


### 要注意的点


### 392.判断子序列
https://leetcode.cn/problems/is-subsequence/



=====
```c++
bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 1; j <= t.size(); j++) {
                if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];
            }
        }
        if (dp[s.size()][t.size()] == s.size()) return true;
        return false;
    }
```



----
### 115.不同的子序列
https://leetcode.cn/problems/distinct-subsequences/

=====


