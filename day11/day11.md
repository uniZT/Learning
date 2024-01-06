## 栈与队列part02
### 20. 有效的括号  1047. 删除字符串中的所有相邻重复项  150. 逆波兰表达式求值



#### 20
https://leetcode.cn/problems/valid-parentheses/description/

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

=====

这个有两个思路，

第一个，遇到左括号就塞进去，有括号就把栈里的取出来对比是不是一对。

第二个，遇到左括号，塞进去右括号，遇到右括号直接对比是不是一样的就好了。

后者的代码格式简单一点。另外，开头先判断一下长度是否为偶数可以更快。

```c++
bool isValid(string s) {
        if (s.size() % 2 != 0) return false; // 如果s的长度为奇数，一定不符合要求
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') st.push(')');
            else if (s[i] == '{') st.push('}');
            else if (s[i] == '[') st.push(']');
            // 第三种情况：遍历字符串匹配的过程中，栈已经为空了，没有匹配的字符了，说明右括号没有找到对应的左括号 return false
            // 第二种情况：遍历字符串匹配的过程中，发现栈里没有我们要匹配的字符。所以return false
            else if (st.empty() || st.top() != s[i]) return false;
            else st.pop(); // st.top() 与 s[i]相等，栈弹出元素
        }
        // 第一种情况：此时我们已经遍历完了字符串，但是栈不为空，说明有相应的左括号没有右括号来匹配，所以return false，否则就return true
        return st.empty();
    }
```
----
#### 1047
https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/description/

给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

=====

可以用字符串作为栈，字符串是有比如back()  push_back()   pop_back()之类的操作的

```c++
string removeDuplicates(string s) {
        string result;
        for(char c : s){
            if(result.empty() || c != result.back()){
                result.push_back(c);
            }
            else{
                result.pop_back();
            }
        }
        return result;
    }
```



-----
#### 150
https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/

给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。

请你计算该表达式。返回一个表示表达式值的整数。

=====

要注意num1和num2的顺序

```c++
int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(int i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+" ||tokens[i] == "-" ||tokens[i] == "*" ||tokens[i] == "/"){
                long long num1 = st.top();
                st.pop();
                long long num2 = st.top();
                st.pop();
                if(tokens[i] == "+")    st.push(num2 + num1);
                if(tokens[i] == "-")    st.push(num2 - num1);
                if(tokens[i] == "*")    st.push(num2 * num1);
                if(tokens[i] == "/")    st.push(num2 / num1);
            }
            else{
                st.push(stoll(tokens[i]));
            }
        }
        long long result = st.top();
        st.pop();
        return result;
    }
```

