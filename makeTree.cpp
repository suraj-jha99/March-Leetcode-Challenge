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
    TreeNode* makeTree(vector<int>& in,int is,int ie,vector<int>& po,int ps,int pe,
    unordered_map<int,int> &mp){
        if(is>ie || ps>pe){
            return NULL;
        }

        //cur root is at the end of postorder
        TreeNode* root = new TreeNode(po[pe]);
        //find idx of root in inorder arr
        int ridx = mp[po[pe]];
        //find cnt of num lying on left of root[use inorder array]
        int cntLeft = ridx - is;

        root->left = makeTree(in,is,ridx-1,po,ps,ps + cntLeft - 1,mp);
        root->right = makeTree(in,ridx+1,ie,po,ps + cntLeft, pe - 1,mp);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& in, vector<int>& po) {
        int m=in.size(),n=po.size();

        if(m != n) return NULL;
        
        //map to find node in O(1)
        unordered_map<int,int> mp; //{node,idx}
        for(int i=0; i<m; i++) mp[in[i]]=i;

        return makeTree(in,0,m-1,po,0,n-1,mp);
    }
};
