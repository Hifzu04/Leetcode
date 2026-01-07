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
 long mod = 1e9+7;
class Solution {
public:
    long totSum = 0 ; 
    long maxSum  = 0 ; 
    int Total(TreeNode* root){
        if(!root) return 0;
        int left = Total(root->left);
        int right = Total(root->right);
        int tot = left+ right+ root->val;
        return tot;
    }
    int maxSumfunc(TreeNode* root){
        if(!root) return 0 ;

         int left = maxSumfunc(root->left);
        int right = maxSumfunc(root->right);
        long sub = left+ right+ root->val;
        long other = totSum - sub;
        long prod = sub*other;
        maxSum = max(maxSum , prod);

        

        return sub;
    }

    int maxProduct(TreeNode* root) {
        totSum = Total(root);

         maxSumfunc(root);
         return maxSum%(mod);




    }
};