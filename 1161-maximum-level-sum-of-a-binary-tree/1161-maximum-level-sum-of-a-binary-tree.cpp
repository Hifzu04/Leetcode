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
    int maxLevelSum(TreeNode* root) {
    //my approach use dfs => sum at each level .=> ret level for max sum
     if (!root) return 0;

     queue<TreeNode*>q;
     q.push(root);
     int currlevel = 1 ; 
     int maxlevel = 1 ; 
     int currsum  = 0 ; 
     int maxsum =INT_MIN ;
     while(!q.empty()){
        int n = q.size();
        
        //traverse each level 
        for(int i = 0 ; i<n  ; i++){
            TreeNode* curr = q.front();
            q.pop();
            currsum+=curr->val;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        if(maxsum<currsum){
            maxsum  = currsum;
            maxlevel = currlevel;
        
        }
        currsum = 0 ; 
        currlevel++;
       

     }
     return maxlevel;


    }
};