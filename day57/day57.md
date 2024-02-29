# 动态规划part14
## 1143.最长公共子序列
##  1035.不相交的线   
## ● 53. 最大子序和  动态规划


### 要注意的点


### 1143.最长公共子序列
https://leetcode.cn/problems/longest-common-subsequence/

=====
```c++
int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
```



----
### 1035.不相交的线
https://leetcode.cn/problems/uncrossed-lines/

=====
```c++
int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size() + 1, vector<int>(B.size() + 1, 0));
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[A.size()][B.size()];
    }
```

-----
### 53. 最大子序和  动态规划
https://leetcode.cn/problems/maximum-subarray/

=====
不是很想用动态规划做
```c++

```