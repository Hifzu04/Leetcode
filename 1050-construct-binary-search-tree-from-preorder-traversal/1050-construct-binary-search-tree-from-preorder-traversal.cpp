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
    TreeNode* insert(int curr , TreeNode* root){
        if(root==NULL){
            return new TreeNode(curr); 
        }
        if(curr< root->val){
            root->left = insert(curr ,root->left);
        } else {
            root->right = insert(curr , root->right);
        }

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int curr : preorder){
            root = insert(curr , root);
        }
        return root;
    }
};