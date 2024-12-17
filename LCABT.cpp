/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode *result;
private:
    bool helper(TreeNode *root, TreeNode *p,TreeNode *q)
    {
        //base case
        if(root==NULL)
            return false;
        
        
        //post order 
        bool left = helper(root->left,p,q);
        bool right =helper(root->right,p,q);
        
        // now if the current node is p or q
        bool mid = (root ==p || root ==q);

        if((left && right) || (mid && left) || (mid && right))
            result = root;
        
        return left||mid||right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q);
        return result;

    }       
};
//Time complexity O(N)
// space complexity O(h)