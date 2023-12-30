# day02
## 链表part02
### 24. 两两交换链表中的节点 19.删除链表的倒数第N个节点 面试题 02.07. 链表相交 142.环形链表II
#### 24
https://leetcode.cn/problems/swap-nodes-in-pairs/description/
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

不要搞错了，cur->next要指向cur->next->next的，如果最开始没有指向，链表会断开，这个操作是有注释那一行
```c++
ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr){
            ListNode* tmpLeft = cur->next;
            ListNode* tmpRight = cur->next->next->next;
            
            cur->next = cur->next->next;    //举例就是，当前初始dummy应该指向下一个的下一个位置上

            cur->next->next = tmpLeft;
            tmpLeft->next = tmpRight;
            cur = cur->next->next;
        }
        return dummyHead->next;
    }
```
------
#### 19
https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/

给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
```c++
ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode * fast = dummyHead;
        ListNode * slow = dummyHead;
        
        //先走n步
        while(n-- && fast != NULL){
            fast = fast->next;
        }
        fast = fast->next;  //这里要多一次，因为去掉倒数第n个的话，倒数n+1个就要停下来了
        
        //一起走
        while(fast != NULL){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return dummyHead->next;
    }
```

-----
#### 面试题 02.07. 链表相交
https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/

给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

swap函数是在algorithm里的

```c++
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0;
        int lenB = 0;
        while(curA != NULL){
            lenA++;
            curA = curA->next;
        }
        while(curB != NULL){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;

        if(lenB > lenA){
            swap(lenA, lenB);
            swap(curA, curB);
        }
        //上面操作完之后，永远是A比B长，统一一下操作
        int sub = lenA - lenB;
        while(sub--){
            curA = curA->next;  //A长A先走，之后会汇合
        }
        //上面走完之后，两个剩下的长度就一样了
        while(curA != NULL){
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
```

-----
#### 142
https://leetcode.cn/problems/linked-list-cycle-ii/description/

给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

不允许修改 链表。

这里和数学问题相关，首先快指针走两步，慢的走一步，如果有环一定会相遇；

另外，在相遇的地方以及起始点分别开始走，一定会在入口相遇。

```c++
ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        //因为快指针2步跳，所以要判断当前和next，不然可能跳出去了
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            if(slow == fast){
                ListNode* index1 = head;
                ListNode* index2 = fast;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            }
        }
        return NULL;
    }
```