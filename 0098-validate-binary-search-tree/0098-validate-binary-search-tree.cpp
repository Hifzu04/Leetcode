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
    bool f(TreeNode* root , TreeNode* min , TreeNode* max ){
        if(root==nullptr) return true;

      if(min!= nullptr && root->val<= min->val  || (max!= nullptr && root->val >= max->val)){
        return false ;
      }
     

     return  f(root->left , min , root) && f(root->right , root , max);
    // return true;


       
    }
    bool isValidBST(TreeNode* root) {
        return f( root  , nullptr , nullptr);
    }
};