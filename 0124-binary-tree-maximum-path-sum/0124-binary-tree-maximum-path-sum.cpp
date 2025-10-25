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
     int max_sum ;
    int f(TreeNode* root){
        if(root==NULL) return 0;
        int l = f(root->left);
        int r = f(root->right);
        int neeche_hi = l+ r+ root->val;
        int anyone = max(l ,r) + root->val;
        int only_root = root->val;
        max_sum = max({max_sum, neeche_hi ,anyone,only_root });
        return max(anyone, only_root);

    }
    int maxPathSum(TreeNode* root) {
        max_sum = INT_MIN;
         f(root);
        return max_sum;
    }
};