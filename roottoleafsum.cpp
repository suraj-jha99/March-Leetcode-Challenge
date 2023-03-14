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
    // preorder dfs traversal
    int dfs(TreeNode *root,int curSum){
        //base case
        if(root==NULL) return 0;
        
        //add curr node in the path sum
        // append current node's digit
        curSum = curSum*10 + root->val;
        
        // leaf node - return current number to be added to total sum
        if(root->left==NULL && root->right==NULL)
            return curSum;
        
        //recurse for child if current node is not leaf
        return dfs(root->left,curSum)+dfs(root->right,curSum);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};
