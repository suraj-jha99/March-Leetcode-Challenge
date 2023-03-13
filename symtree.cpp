/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool issymm(TreeNode* p,TreeNode* q){
        if(!p && q || p && !q){
            return false;
        }

        if(!p && !q) return true;

        return p->val == q->val && issymm(p->left,q->right) 
               && issymm(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return issymm(root->left,root->right);
    }
};
