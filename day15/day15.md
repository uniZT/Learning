# 二叉树part02
## ● 102.层序遍历  10题  ● 226.翻转二叉树  ● 101.对称二叉树 2
### 要注意的点
层序遍历的题目里，在一个for循环里，终止的判断是一个随时会变化的queue.
这个时候，终止条件i < size就应该在循环之前提前size = que.size()。
如果用i < que.size()，会因为que在for里不断变化而出现问题。

翻转二叉树里，不同的递归顺序需要有不同的写法。

### 102
https://leetcode.cn/problems/binary-tree-level-order-traversal/description/

给你二叉树的根节点 root ，返回其节点值的 层序遍历 。

=====

非递归，初始节点入栈，
```c++
vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> que;
        vector<vector<int>> result;
        if(root != NULL){
            que.push(root);
        }
        while(!que.empty()){
            int size = que.size();
            vector<int> levelresult;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                levelresult.push_back(node->val);
                if(node->left)  que.push(node->left);
                if(node->right) que.push(node->right);
            }
            result.push_back(levelresult);
        }
        return result;
}
```

----
### 226
https://leetcode.cn/problems/invert-binary-tree/description/

给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。

=====

递归翻转
```c++
TreeNode* invertTree(TreeNode* root) {
        if(root == NULL) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
}
```


-----
### 101
https://leetcode.cn/problems/symmetric-tree/

给你一个二叉树的根节点 root ， 检查它是否轴对称。

=====

用递归的思路，首先设置终止条件。

然后left的左边和right的右边，这两个外侧的进行比较；
然后left的右边和right的左边，这两个内侧的进行比较；
```c++
bool compare(TreeNode* left, TreeNode* right){
        if((left == NULL && right != NULL) || (left != NULL && right == NULL))  return false;
        else if(left == NULL && right == NULL)  return true;
        else if(left->val != right->val)    return false;
        //上面是终止条件，那么如果left的val等于right的val，则进行下面操作
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        return outside&&inside;
}
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return compare(root->left, root->right);
}
```
