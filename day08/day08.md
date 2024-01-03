## 字符串part01
### 344.反转字符串  541. 反转字符串II  卡码网：54.替换数字  151.翻转字符串里的单词  卡码网：55.右旋转字符串


#### 344
https://leetcode.cn/problems/reverse-string/description/

编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。

不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。

=====

这里通过位运算进行数值交换我之前一直都不清楚，但是其实并没有什么用
```c++
s[i] ^= s[j];
s[j] ^= s[i];
s[i] ^= s[j];
```
```c++
void reverseString(vector<char>& s) {
        for(int i = 0, j = s.size() - 1; i < j; i++, j--){
            swap(s[i], s[j]);
        }
    }
```

----
#### 541
https://leetcode.cn/problems/reverse-string-ii/description/

给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。
如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

=====

在遍历字符串的过程中，让 i += (2 * k)，i 每次移动 2 * k，然后判断是否需要有反转的区间。
```c++
string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += (k * 2)){
            if(i + k <= s.size()){
                reverse(s.begin() + i, s.begin() + i + k);
            }
            else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
```

-----
#### 卡码网：54

最简单的写法，但是并不能做到O(1)的空间复杂度
```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
    string sinput;
    string soutput;
    cin >> sinput;
    for(int i = 0; i < sinput.size(); i++){
        if(sinput[i] >= '0' && sinput[i] <= '9'){
            soutput.append("number");
        }
        else{
            soutput.push_back(sinput[i]);
        }
    }
    cout << soutput;
    return 0;
}
```

-----
#### 151
https://leetcode.cn/problems/reverse-words-in-a-string/description/

给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

=====

这里要注意的是，函数对string的修改需要用(string & s)，它不像数组那样可以直接用

处理分两步，第一步，首先要去掉多余的空格；第二步整个串翻转；第三步，单独翻转单词

感觉很难，需要二刷
```c++
void removeSpace(string& s){
        int slow = 0, fast = 0;
        while(s.size() > 0 && fast < s.size() && s[fast] == ' '){
            fast++;
        }
        for(;fast < s.size(); fast++){
            //去掉开头的空格
            if(fast - 1 > 0 && s[fast - 1] == s[fast] && s[fast] == ' '){
                continue;
            }
            else{
                s[slow++] = s[fast];
            }
        }
        //去掉尾部的空格
        if(slow - 1 > 0 && s[slow - 1] == ' '){
            s.resize(slow - 1);
        }
        else{
            s.resize(slow);
        }
    }
    string reverseWords(string s) {
        removeSpace(s);
        reverse(s.begin(), s.end());
        int start = 0;
        for(int i = 0; i <= s.size(); i++){
            if(i == s.size() || s[i] == ' '){
                reverse(s.begin()+start, s.begin() + i);
                start = i + 1;
            }
        }
        return s;
    }
```

-----
#### 卡码网：55
https://kamacoder.com/problempage.php?pid=1065

字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个字符串 s 和一个正整数 k，请编写一个函数，将字符串中的后面 k 个字符移到字符串的前面，实现字符串的右旋转操作。

例如，对于输入字符串 "abcdefg" 和整数 2，函数应该将其转换为 "fgabcde"。

这个算比较简单，多次翻转就好了

```c++
#include<bits/stdc++.h>
using namespace std;
 int main(){
     int n;
     string s;
     cin >> n;
     cin >> s;
     reverse(s.begin(), s.end());
     reverse(s.begin(), s.begin() + n);
     reverse(s.begin() + n, s.end());
     cout << s;
     return 0;
 }
```