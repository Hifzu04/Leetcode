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
    int ans ;
public:
    //vector -> min , max , sum
    vector<int> dfs(TreeNode* root){
        if(root == NULL){
            return  {INT_MAX , INT_MIN , 0};
        }
        vector<int>left = dfs(root->left);
        vector<int>right = dfs(root->right);
        if(root->val > left[1] && root->val < right[0]){
            int currsum = left[2] + right[2] + root->val;
            ans = max(ans , currsum);
            int minval = min(root->val , left[0]);
            int maxval = max(root-> val , right[1]);
            return  {minval ,maxval , currsum};
        }
        int maxsum =  max(left[2] , right[2]);
        return {INT_MIN , INT_MAX , maxsum };
    }
    int maxSumBST(TreeNode* root) {
        ans = 0 ;
        dfs(root);
        return ans ;
    }
};