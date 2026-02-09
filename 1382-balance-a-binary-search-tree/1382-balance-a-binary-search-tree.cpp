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
   TreeNode* Balance(vector<int>& vec ,int  l ,int r){
         if(l>r){
               return NULL;
         }
         int mid = l + (r-l)/2;
         TreeNode* root = new TreeNode(vec[mid]);
         root->left = Balance(vec , l , mid-1);
         root->right = Balance(vec, mid+1 , r);
         return root;
   }
   void inOrder(TreeNode* root , vector<int>& vec){
         if(!root){
            return ;
         }
         inOrder(root->left , vec);
         vec.push_back(root->val);
         inOrder(root-> right , vec);

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vec;
        inOrder(root , vec);
        
        return Balance(vec , 0 , vec.size()-1);
    }
};