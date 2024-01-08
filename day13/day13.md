## 栈与队列part03
### 239. 滑动窗口最大值  347.前 K 个高频元素


#### 239
https://leetcode.cn/problems/sliding-window-maximum/description/

给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。

返回 滑动窗口中的最大值 。

=====

要注意的点，首先设计一个队列，这个队列是单调队列。左边大右边小。

当push一个元素，比较队尾元素，如果插入的比队尾大，队尾出队，一直到队尾>=插入元素，然后插入。

队列以外，整个的操作是，首先插入前k个元素。 由于设计好队列的性质，插入完的，一定符合单调队列的性质。

插入完记录当前最大的在result里。

滑动窗口右移，出队最左边的，但是这里要确认一下窗口最左边的在push的时候有没有被处理掉了，如果没有被处理掉，那么pop，如果被处理掉就不用pop。

然后push，然后再记录最大元素（最左边的）放进result。

```c++
class MyQueue{
    public:
        void pop(int value){
            if(!que.empty() && value == que.front()){       //这里需要确认一下，窗口最左边的元素value在push的时候有没有被排除掉，如果还在就pop，后面可以看到详细操作
                que.pop_front();
            }
        }
        void push(int value){
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }
        int front(){
            return que.front();
        }
    private:
        deque<int> que;
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        MyQueue que;
        for(int i = 0; i < k; i++){
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for(int i = k; i < nums.size(); i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
```

----
#### 347
https://leetcode.cn/problems/top-k-frequent-elements/description/

给你一个整数数组 nums 和一个整数 k ，请你返回其中出现频率前 k 高的元素。你可以按 任意顺序 返回答案。

=====

关于大小根堆，用priority_queue，然后加一个对比大小的函数来构建。priority_queue本身就是一个堆。

```c++
//小根堆
class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
            return lhs.second > rhs.second;
        }
    };
```


```c++
//小根堆
    class mycomparison{
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs){
            return lhs.second > rhs.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
        //难点是这个小根堆的理解
        priority_queue<pair<int,int>, vector<pair<int, int>>, mycomparison> pri_que;
        
        //堆里保证只有k个元素，auto是取巧，实际上是这个unordered_map<int, int>::iterator
        for(auto it = map.begin(); it != map.end(); it++){
            pri_que.push(*it);
            if (pri_que.size() > k) {
                pri_que.pop();
            }
        }
        vector<int> result(k);
        //题目没要求顺序，但是这里小根堆，从后向前输出是从大到小的顺序
        for (int i = k - 1; i >= 0; i--) {
             result[i] = pri_que.top().first;
             pri_que.pop();
        }
        
        return result;
    }
```




