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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*>parent;
        unordered_set<int>child;

        for(vector<int>& v : descriptions){
            int p = v[0];
            int c = v[1];
            int l = v[2];
            if(parent.find(p) == parent.end()){
                parent[p] = new TreeNode(p);
            }
            if(parent.find(c) == parent.end()){
                parent[c] = new TreeNode(c);
            }

            if(l== 1){
                parent[p]-> left = parent[c];
            }else {
                parent[p] -> right = parent[c];
            }

            child.insert(c);



        }

        for(vector<int>& v : descriptions){
            int p = v[0];
            if(child.find(p) == child.end()){
                return parent[p];
            }
        }

        return 0;
    }
};