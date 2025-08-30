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
    int prev = -1;
    void f(TreeNode* root , int& ans){

        if(root ==NULL){
            return ;
        }

        f(root->left , ans);

        if(prev!= -1){
            ans = min(ans , root->val - prev);
        }
        prev = root->val;

        f(root->right , ans);

       



    

    }
public:
    int getMinimumDifference(TreeNode* root) {
        int ans = INT_MAX;
        f(root ,ans);
        return ans;

    }
};