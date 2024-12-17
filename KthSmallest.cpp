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
    void helper(TreeNode *root, priority_queue<int>&minHeap,int k)
    {
        if(root==NULL)
            return;


        helper(root->left,minHeap,k);

        minHeap.push(root->val);
        if(minHeap.size() > k)
        {
            minHeap.pop();
        }
        helper(root->right,minHeap,k);
        
        return;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        //minheap
        priority_queue<int>minHeap;

        helper(root,minHeap, k);

        return minHeap.top();

    }
};
//Time complexity O(N)
//space complexity O(N)

//but we can optimize using the inorder traversal sorting property for BST
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
    int res;
private:
    void helper(TreeNode *root, int &k)
    {
        //base case
        if(root ==NULL || k<=0)
            return;

        helper(root->left,k);
        k--;
        if(k==0)
        {
            res = root->val;
            return;
        }
        helper(root->right,k);

        return;

    }
public:
    int kthSmallest(TreeNode* root, int k) {
        helper(root,k);
        return res;
    }
};

//Time complxity O(K)
//space complexity O(1)
