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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        
        //make a flag var to know if a null ptr exists bw nodes
        bool isPrevNodeNull=false;
        
        while(!q.empty()){
            TreeNode *frontNode=q.front();
            q.pop();
            
            //if curr node is NULL
            if(frontNode == NULL)
                isPrevNodeNull=true;
            
            else{//not null node
                
                if(isPrevNodeNull==true)
                    return false;
                
                //add left and right child
                q.push(frontNode->left);
                q.push(frontNode->right);
            }
        }
        return true;
    }
};
