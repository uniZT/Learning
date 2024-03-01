# 动态规划part17
## ● 647. 回文子串
## ● 516.最长回文子序列
## ● 动态规划总结篇



### 要注意的点


### 647. 回文子串
https://leetcode.cn/problems/palindromic-substrings/

=====
```c++
int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--) {  // 注意遍历顺序
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) { // 情况一 和 情况二
                        result++;
                        dp[i][j] = true;
                    } else if (dp[i + 1][j - 1]) { // 情况三
                        result++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return result;
    }
```



----
### 516.最长回文子序列
https://leetcode.cn/problems/longest-palindromic-subsequence/


=====
```c++
int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
```

-----
### 动态规划总结篇

动规五部曲分别为：

1.确定dp数组（dp table）以及下标的含义

2.确定递推公式

3.dp数组如何初始化

4.确定遍历顺序

5.举例推导dp数组

=====
