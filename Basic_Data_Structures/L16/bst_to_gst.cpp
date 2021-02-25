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
    void bstToGst_aux(TreeNode* cur, int &sum)
    {
        if(!cur)
            return;
        
        bstToGst_aux(cur->right, sum);
        
        sum += cur->val;
        cur->val = sum;
        
        bstToGst_aux(cur->left, sum);
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        bstToGst_aux(root,sum);
        return root;
    }
};
