## 字符串part02
### 232.用栈实现队列   225. 用队列实现栈

#### 232
https://leetcode.cn/problems/implement-queue-using-stacks/description/

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
```c++
class MyQueue {
private:
    stack<int> sin;
    stack<int> sout;
public:
    MyQueue() {

    }
    
    void push(int x) {
        sin.push(x);
    }
    
    int pop() {
        //全部转移进去sout
        if(sout.empty()){
            while(!sin.empty()){
                sout.push(sin.top());
                sin.pop();
            }
        }
        //sout输出
        int result = sout.top();
        sout.pop();
        return result;
    }
    
    int peek() {
        int result = this->pop();
        sout.push(result);
        return result;
    }
    
    bool empty() {
        if(sin.empty() && sout.empty()){
            return true;
        }
        return false;
    }
};
```

----
#### 225
https://leetcode.cn/problems/implement-stack-using-queues/description/

请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。

```c++
class MyStack {
private:
    queue<int> que;
public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int n = que.size();
        n--;
        while(n--){
            que.push(que.back());
            que.pop();
        }
        int result = que.front();
        que.pop();
        return result;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};
```






