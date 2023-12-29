# day03
## 链表part01
### 203.移除链表元素 707.设计链表 206.反转链表
#### 203
https://leetcode.cn/problems/remove-linked-list-elements/description/
给你一个链表的头节点 head 和一个整数 val ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。

几个要注意的点

1. 使用虚拟头结点dummyhead逻辑会更加简单清晰，否则就要分头结点和中间结点来处理整个链表
2. 要记得delete删除掉那些不要的元素，否则会一直占用内存
3. 设置一个虚拟头结点如下
```c++
ListNode* dummyHead = new ListNode(0); 
//定义
struct ListNode {
    int val;
    ListNode *next;
    //构造函数
    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```
```c++
ListNode *removeElements(ListNode *head, int val) {
    ListNode * dummyHead = new ListNode(0);
    dummyHead->next = head;
    ListNode* cur = dummyHead;
    while(cur->next != NULL){
        if(cur->next->val != val){
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }
        else{
            cur = cur->next;
        }
    }
    head = dummyHead->next;
    delete dummyHead;
    return head;
}
```

------
#### 209
https://leetcode.cn/problems/design-linked-list/description/

你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

一个是平时写得不多忘得差不多，一个是这种造轮子的平时基本都是用现成的，感觉很难。

```c++
class MyLinkedList {
public:
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int val):val(val),next(nullptr){}
    };  //不要忘了分号
    //_dummyHead和_size都是定义在下面private里面的
    MyLinkedList() {
        _dummyHead = new ListNode(0);
        _size = 0;
    }
    
    int get(int index) {
        if(index > (_size - 1) || index < 0){
            return -1;
        }
        ListNode* cur = _dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(cur->next != nullptr){
            cur=cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size){
            return;
        }
        else if(index < 0){
            index = 0;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* cur = _dummyHead;
        while(index--){
            cur=cur->next;
        }
        newNode->next = cur->next;
        cur->next=newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index<0){
            return;
        }
        ListNode * cur = _dummyHead;
        while(index--){
            cur = cur->next;
        }
        ListNode* temp = cur->next;
        cur->next=cur->next->next;
        delete temp;
        //下面是为了避免野指针
        temp=nullptr;
        _size--;
    }
private:
    int _size;
    ListNode* _dummyHead;
};
```
#### 59
https://leetcode.cn/problems/reverse-linked-list/description/

给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

有双指针法和递归解法，递归比较难比较抽象
```c++
ListNode* reverseList(ListNode* head) {
        ListNode* left = NULL;
        ListNode* right = head;
        ListNode* temp;
        while(right){
            temp = right->next;
            right->next = left;
            left = right;
            right = temp;
        }
        return left;
    }
```
```c++
    ListNode* reverse(ListNode* left,ListNode* right){
        if(right == NULL) return left;
        ListNode* temp = right->next;
        right->next = left;
        // 可以和双指针法的代码进行对比，如下递归的写法，其实就是做了这两步
        // left = right;
        // right = temp;
        return reverse(right,temp);
    }
    ListNode* reverseList(ListNode* head) {
        // 和双指针法初始化是一样的逻辑
        // ListNode* right = head;
        // ListNode* left = NULL;
        return reverse(NULL, head);
    }
```