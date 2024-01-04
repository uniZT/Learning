## 字符串part02
### 28. 实现 strStr()  459.重复的子字符串  字符串总结  双指针回顾



#### 28
https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

kmp的手算方法和机器算的方法有一些不一样

下面是时间复杂度高的算法，这里需要引入一个flag，确保在正确匹配到之后可以返回正确结果。
```c++
int strStr(string haystack, string needle) {
        for(int i = 0; i + needle.size() <= haystack.size(); i++){
            bool flag = 1;
            for(int j = 0; j < needle.size(); j++){
                if(haystack[i + j] != needle[j]){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                    return i;
            }
        }
        return -1;
    }
```



----
#### 459
https://leetcode.cn/problems/repeated-substring-pattern/description/

给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。

=====
移动匹配的方法假设字符串是s，两个拼起来是s+s，把s+s头尾去掉，只要在中间找到s，那么这个串就符合题目条件

string的find函数，找不到会返回一个string的npos
```c++
bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        ss.erase(ss.begin());
        ss.erase(ss.end() - 1);
        if(ss.find(s) != ss.npos){
            return true;
        }
        return false;
}
```





