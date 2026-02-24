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
    
    int dfs(TreeNode* root , int value){
        if(!root){
            return 0;
        }

        value = (value * 2) + root->val ;
        if(root->left == NULL && root->right ==NULL){
            return value;
        }
        return dfs(root->left , value) + dfs(root->right , value);
    }
    int sumRootToLeaf(TreeNode* root) {
       return  dfs(root , 0);
    }
};