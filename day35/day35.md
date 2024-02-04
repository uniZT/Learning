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


=====


-----
### 452. 用最少数量的箭引爆气球


=====