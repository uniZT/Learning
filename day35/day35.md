# 贪心算法 part04
## ● 860.柠檬水找零
## ● 406.根据身高重建队列
## ● 452. 用最少数量的箭引爆气球

### 要注意的点


### 860.柠檬水找零
https://leetcode.cn/problems/lemonade-change/

在柠檬水摊上，每一杯柠檬水的售价为 5 美元。顾客排队购买你的产品，（按账单 bills 支付的顺序）一次购买一杯。

每位顾客只买一杯柠檬水，然后向你付 5 美元、10 美元或 20 美元。你必须给每个顾客正确找零，也就是说净交易是每位顾客向你支付 5 美元。

注意，一开始你手头没有任何零钱。

给你一个整数数组 bills ，其中 bills[i] 是第 i 位顾客付的账。如果你能给每位顾客正确找零，返回 true ，否则返回 false 。

=====

注意这里是5、10、20元三种面额，不是按总金额算的
```c++
bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for(int money : bills){
            //收5元
            if(money == 5){
                five++;
            }
            //收10元，找5元
            if(money == 10){
                if(five > 0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            //收20，找10 + 5，或者找3张5元
            if(money == 20){
                if(five > 0 && ten > 0){
                    ten--;
                    five--;
                    twenty++;
                }
                else if(five >= 3 && ten <= 0){
                    five -= 3;
                    twenty++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
```



----
### 406.根据身高重建队列
https://leetcode.cn/problems/queue-reconstruction-by-height/

假设有打乱顺序的一群人站成一个队列，数组 people 表示队列中一些人的属性（不一定按顺序）。每个 people[i] = [hi, ki] 表示第 i 个人的身高为 hi ，前面 正好 有 ki 个身高大于或等于 hi 的人。

请你重新构造并返回输入数组 people 所表示的队列。返回的队列应该格式化为数组 queue ，其中 queue[j] = [hj, kj] 是队列中第 j 个人的属性（queue[0] 是排在队列前面的人）。

=====
```c++
//题目的vector数组是一个vector里面有复数个长度为2的vector[a,b]
    static bool cmp(const vector<int>& a, const vector<int>& b){
        //先按第2个元素从小到大排。再按第1个元素，从大到小排
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> result;
        for(int i = 0; i < people.size(); i++){
            int position = people[i][1];
            result.insert(result.begin() + position, people[i]);
        }
        return result;
    }
```

-----
### 452. 用最少数量的箭引爆气球
https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/

有一些球形气球贴在一堵用 XY 平面表示的墙面上。墙面上的气球记录在整数数组 points ，其中points[i] = [xstart, xend] 表示水平直径在 xstart 和 xend之间的气球。你不知道气球的确切 y 坐标。

一支弓箭可以沿着 x 轴从不同点 完全垂直 地射出。在坐标 x 处射出一支箭，若有一个气球的直径的开始和结束坐标为 xstart，xend， 且满足  xstart ≤ x ≤ xend，则该气球会被 引爆 。可以射出的弓箭的数量 没有限制 。 弓箭一旦被射出之后，可以无限地前进。

给你一个数组 points ，返回引爆所有气球所必须射出的 最小 弓箭数 。

=====
```c++
static bool cmp(vector<int>& a, vector<int>& b){
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int result = 1;
        if(points.size() == 0) return 0;
        //按左边的数字来排序
        sort(points.begin(), points.end(), cmp);
        for(int i = 1; i < points.size(); i++){
            //当后一个左边大于前一个右边，气球不重叠，+1
            if(points[i][0] > points[i -1][1]){
                result++;
            }
            //如果后一个与前一个重叠，那么设置当前最右的位置为min(当前最右,前一个最右)
            else{
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }
        return result;
    }
```