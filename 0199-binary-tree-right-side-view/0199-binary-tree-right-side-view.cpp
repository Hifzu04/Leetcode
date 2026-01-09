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

    //using level order traversal (BFS)
    void bfs(TreeNode* root , vector<int>&ans){
          if(!root) return  ;
       
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int n= q.size();
             TreeNode* curr = NULL;
            while(n--){
                curr = q.front();
                q.pop();
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL)  q.push(curr->right);

            }
            //last element of any level
            ans.push_back(curr->val);

        }
    }


    //using dfs - inorder
    void dfs(TreeNode* root , vector<int>&ans ,int  level ){
              if(!root) return ;
              if(ans.size() < level){
                 ans.push_back(root->val);
              } 
              if(root->right) dfs(root->right , ans , level+1);
            if(root->left)    dfs(root->left , ans , level+1 );

    }
   
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans; 
       // bfs(root , ans);

        dfs(root , ans ,1 );
        return ans ;

    }
};