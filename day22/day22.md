# 二叉树part08
## ● 235. 二叉搜索树的最近公共祖先
## ● 701.二叉搜索树中的插入操作
## ● 450.删除二叉搜索树中的节点


### 要注意的点


### 235. 二叉搜索树的最近公共祖先
https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-search-tree/

给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

=====
```c++
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return root;

        //左
        if(root->val > p->val && root->val > q->val){
            TreeNode* left = lowestCommonAncestor(root->left , p, q);
            if(left != NULL){
                return left;
            }
        }
        //右
        if(root->val < p->val && root->val < q->val){
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if(right != NULL){
                return right;
            }
        }
        return root;
    }
```



----
### 701.二叉搜索树中的插入操作
https://leetcode.cn/problems/insert-into-a-binary-search-tree/description/

给定二叉搜索树（BST）的根节点 root 和要插入树中的值 value ，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据 保证 ，新值和原始二叉搜索树中的任意节点值都不同。

=====
```c++
TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(root->val > val){
            root->left = insertIntoBST(root->left, val);
        }
        if(root->val < val){
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
```


-----
### ● 450.删除二叉搜索树中的节点
https://leetcode.cn/problems/delete-node-in-a-bst/

给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

=====

```c++
TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        if(root->val == key){
            //左右孩子都为空（叶子节点），直接删除节点， 返回NULL为根节点
            if(root->left == nullptr && root->right == nullptr){
                delete root;
                return nullptr;
            }
            //左孩子为空，右孩子不为空，删除节点，右孩子补位 ，返回右孩子为根节点
            else if (root->left == nullptr) {
                TreeNode* retNode = root->right;
                delete root;
                return retNode;
            }
            // 右孩子为空，左孩子不为空，删除节点，左孩子补位，返回左孩子为根节点
            else if (root->right == nullptr) {
                TreeNode* retNode = root->left;
                delete root;
                return retNode;
            }
            else {
                TreeNode* cur = root->right; // 找右子树最左面的节点
                while(cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root;
                root = root->right;
                delete tmp;
                return root;
            }
            
        }
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);
        return root;
    }
```

