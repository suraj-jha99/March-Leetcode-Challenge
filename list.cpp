/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* middle(ListNode* head){
        ListNode *slow=head,*fast=head,*prev=head;

        while(fast && fast->next){
            prev = slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //break link of lower half ll from upper half ll
        if(prev != NULL){
            prev->next =  NULL;
        }

        return slow;
    }

    TreeNode* makeTree(ListNode* head){
        if(head == NULL){
            return NULL;
        }

        //find mid and make root node
        ListNode* mid = middle(head);
        TreeNode* root = new TreeNode(mid->val);

        if(mid == head){
            return root;
        }

        root->left = makeTree(head);
        root->right = makeTree(mid->next);

        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;

        return makeTree(head);
    }
};
